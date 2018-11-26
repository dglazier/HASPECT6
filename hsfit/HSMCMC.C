//////////////////////////////////////////////////////
///
/// HSMCMC MCMC minimiser for RooFit
/// Currently only works with positive PDFs only.

#include "HSMCMC.h"
#include "Rtypes.h"
#include "RooGlobalFunc.h"
#include "RooAbsReal.h"
#include "RooArgSet.h"
#include "RooArgList.h"
#include "RooStats/ModelConfig.h"
#include "RooStats/RooStatsUtils.h"
#include "RooStats/MCMCCalculator.h"
#include "RooStats/MetropolisHastings.h"
#include "RooStats/MarkovChain.h"
#include "RooStats/MCMCInterval.h"
#include "TIterator.h"
#include "RooStats/UniformProposal.h"
#include "RooStats/PdfProposal.h"
#include "RooFitResult.h"
#include "RooProdPdf.h"
#include "RooProduct.h"
#include "RooStats/Heaviside.h"
#include "RooNDKeysPdf.h"

using namespace RooStats;
using namespace HS::FIT;

////////////////////////////////////////////////////////////////////////////////
/// default constructor

HSMCMC::HSMCMC()  
  //MCMCCalculator::fPropFunc(0),
  // fPdf(0),
  //fPriorPdf(0),
  // fData(0),
  //fAxes(0)
{
   // fNumIters = 0;
   // fNumBurnInSteps = 0;
   // fNumBins = 0;
   // fUseKeys = kFALSE;
   // fUseSparseHist = kFALSE;
   // fSize = -1;
   // fIntervalType = MCMCInterval::kShortest;
   // fLeftSideTF = -1;
   // fEpsilon = -1;
   // fDelta = -1;
}

////////////////////////////////////////////////////////////////////////////////
/// constructor from a Model Config with a basic settings package configured
/// by SetupBasicUsage()

HSMCMC::HSMCMC(RooAbsData& data, const ModelConfig & model) 
  // fPropFunc(0),
  // fData(&data),
  // fAxes(0)
{
  fData=&data;
   SetModel(model);
   SetupBasicUsage();
}
HSMCMC::~HSMCMC(){
  delete fChain;
  delete fTreeMCMC;
  delete fChainData;
}
////////////////////////////////////////////////////////////////////////////////
/// Main interface to get a RooStats::ConfInterval.

void HSMCMC::MakeChain()
{
  cout<<"HSMCMC::MakeChain()"<<endl;
   if (!fData || !fPdf   ) return;
   if (fPOI.getSize() == 0) return;

   if (fSize < 0) {
      coutE(InputArguments) << "MCMCCalculator::GetInterval: "
         << "Test size/Confidence level not set.  Returning NULL." << endl;
      return;
   }

   // if a proposal function has not been specified create a default one
   bool useDefaultPropFunc = (fPropFunc == 0);
   bool usePriorPdf = (fPriorPdf != 0);
   if (useDefaultPropFunc) fPropFunc = new UniformProposal();

   // if prior is given create product
   RooAbsPdf * prodPdf = fPdf;
   if (usePriorPdf) {
      TString prodName = TString("product_") + TString(fPdf->GetName()) + TString("_") + TString(fPriorPdf->GetName() );
      prodPdf = new RooProdPdf(prodName,prodName,RooArgList(*fPdf,*fPriorPdf) );
   }
 
   RooArgSet* constrainedParams = prodPdf->getParameters(*fData);
   RooAbsReal* nll = prodPdf->createNLL(*fData, RooFit::Constrain(*constrainedParams), RooFit::ConditionalObservables(fConditionalObs));
   //RooAbsReal* nll = prodPdf->createNLL(*fData); 
   delete constrainedParams;
 
   //add in sumw/sumw2 term
   if(fData->isNonPoissonWeighted()&&fCorrectForWeights){
     Double_t SumW=SumWeights();
     Double_t SumW2=SumWeights2();
     RooFormulaVar *alphanll=new RooFormulaVar("alphanll",Form("%lf*%s",SumW/SumW2,nll->GetName()),RooArgSet(*nll));
     nll=alphanll;
   }
    
   fParams = nll->getParameters(*fData);
   RemoveConstantParameters(fParams);
   // if (fNumBins > 0) {
   //    SetBins(*fParams, fNumBins);
   //    SetBins(fPOI, fNumBins);
   //    if (dynamic_cast<PdfProposal*>(fPropFunc)) {
   //       RooArgSet* proposalVars = ((PdfProposal*)fPropFunc)->GetPdf()->
   //                                             getParameters((RooAbsData*)NULL);
   //       SetBins(*proposalVars, fNumBins);
   //    }
   // }
   
   MetropolisHastings mh;
   mh.SetFunction(*nll);
   mh.SetType(MetropolisHastings::kLog);
   mh.SetSign(MetropolisHastings::kNegative);
   mh.SetParameters(*fParams);
   if (fChainParams.getSize() > 0) mh.SetChainParameters(fChainParams);
   mh.SetProposalFunction(*fPropFunc);
   mh.SetNumIters(fNumIters);

   cout<<"Construct"<<endl;
  fChain = mh.ConstructChain();
  cout<<"DONE "<<endl;
  //fParams = nll->getParameters(*fData);
 //  fParams->Print();
  //fChainData=fChain->GetAsDataSet(EventRange(fNumBurnInSteps, fChain->Size()));
  if(fChain->Size()>fNumBurnInSteps)
    fChainData=fChain->GetAsDataSet( RooFit::EventRange(fNumBurnInSteps, fChain->Size()));
  //    fChainData=fChain->GetAsDataSet(SelectVars(*fParams),EventRange(fNumBurnInSteps, fChain->Size()));
  else{
    Error("HSMCMC::MakeChain()"," not enough samples to pass burn in, you eed to increase NMCMC");
    fChainData=fChain->GetAsDataSet( RooFit::SelectVars(*fParams));
  }
  //fChainData=fChain->GetAsDataSet();
  cout<<"Tree"<<endl;
   
   fTreeMCMC=RooStats::GetAsTTree("MCMCTree","MCMCTree",*fChainData);
 
   if (useDefaultPropFunc) delete fPropFunc;
   if (usePriorPdf) delete prodPdf;
   delete nll;
   //delete params;

   return;
}
Double_t  HSMCMC::SumWeights(){
  // Otherwise sum the weights in the event
  Double_t sumw(0), carry(0);
  Int_t i ;
  for (i=0 ; i<fData->numEntries() ; i++) {
    fData->get(i) ;
 
    Double_t y = fData->weight() - carry;
    Double_t t = sumw + y;
    carry = (t - sumw) - y;
    sumw = t;
  }
  return sumw;
}
Double_t  HSMCMC::SumWeights2(){
  // Otherwise sum the weights in the event
  Double_t sumw(0), carry(0);
  Int_t i ;
  for (i=0 ; i<fData->numEntries() ; i++) {
    fData->get(i) ;
 
    Double_t y = fData->weight()*fData->weight() - carry;
    Double_t t = sumw + y;
    carry = (t - sumw) - y;
    sumw = t;
  }
  return sumw;
}
void HSMCMC::CreateKeysPdf()
{
   // kbelasco: check here for memory leak.  does RooNDKeysPdf use
   // the RooArgList passed to it or does it make a clone?
   // also check for memory leak from chain, does RooNDKeysPdf clone that?
  cout<<"SIZE "<<fParams->getSize()<<endl;
    if (fParams->getSize() == 0) {
      coutE(InputArguments) << "Error in HSMCMC::CreateKeysPdf: "
         << "parameters have not been set." << endl;
      return;
   }

   if (fNumBurnInSteps >= fChain->Size()) {
      coutE(InputArguments) <<
         "MCMCInterval::CreateKeysPdf: creation of Keys PDF failed: " <<
         "Number of burn-in steps (num steps to ignore) >= number of steps " <<
         "in Markov chain." << endl;
      delete fKeysPdf;
      delete fCutoffVar;
      delete fHeaviside;
      delete fProduct;
      fKeysPdf = NULL;
      fCutoffVar = NULL;
      fHeaviside = NULL;
      fProduct = NULL;
      return;
   }

   // RooArgList* paramsList = new RooArgList();
   // for (Int_t i = 0; i < fDimension; i++)
   //    paramsList->add(*fAxes[i]);

   // kbelasco: check for memory leaks with chain.  who owns it? does
   // RooNDKeysPdf take ownership?
   fParams->Print();
   //  fChainData->Print();
   RooDataSet *dataset1 = new RooDataSet( "chainset","chainset",GetTree(), *fParams);
   GetTree()->Print("");
   dataset1->Print();
   fKeysPdf = new RooNDKeysPdf("keysPDF", "Keys PDF", *fParams, *dataset1, "a");
   fCutoffVar = new RooRealVar("cutoff", "cutoff", 0);
   //I think taking product with heaviside forces evaluate>0
   fHeaviside = new RooStats::Heaviside("heaviside", "Heaviside", *fKeysPdf, *fCutoffVar);
   fProduct = new RooProduct("product", "Keys PDF & Heaviside Product",
                                        RooArgSet(*fKeysPdf, *fHeaviside));
}
RooFitResult* HSMCMC::Save(){

  cout<<"RooFitResult* HSMCMC::Save()"<<endl;
  RooFitResult* fitRes = new RooFitResult("mcmc","HSMCMC result") ;

  // Move eventual fixed parameters in floatList to constList
  RooArgList saveFloatFinalList(*fChainData->get()) ;
  //fitRes->setFinalParList(saveFloatFinalList) ;

  Double_t edm, errdef, minVal;
  Int_t nvpar, nparx;
  // Int_t icode = _theFitter->GetStats(minVal, edm, errdef, nvpar, nparx);
  // fitRes->setStatus(_status) ;
  //fitRes->setCovQual(icode) ;
  //fitRes->setMinNLL(fChain->NLL());//get the last NLL in chain
  //fitRes->setEDM(edm) ;
  //fitRes->setFinalParList(saveFloatFinalList) ;
  //fitRes->setCovarianceMatrix(fChainData->corrcovMatrix(fChainData->get()));
  //  fitRes->setStatusHistory(_statusHistory) ;
  cout<<"HSMCMC::Save() "<<endl;
  //saveFloatFinalList.Print("v");
  for(Int_t i=0;i<fParams->getSize();i++){
  
    RooRealVar* var=dynamic_cast<RooRealVar*>(saveFloatFinalList.at(i));
    cout<<var->GetName()<<" "<<fChainData->mean(*var)<<" +- "<<fChainData->sigma(*var)<<endl;
    ((RooRealVar*)fParams->find(var->GetName()))->setVal(fChainData->mean(*var));
    ((RooRealVar*)fParams->find(var->GetName()))->setError(fChainData->sigma(*var));
  }
  fChainData->covarianceMatrix()->Print();
  
  // fitRes->Print();
  return fitRes ;
}
