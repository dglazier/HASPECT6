#include "RooMcmc.h"
#include "HSMetropolisHastings.h"
#include <TIterator.h>
#include <TLeaf.h>
#include <RooStats/UniformProposal.h>
#include <RooStats/SequentialProposal.h>
#include <RooStats/ProposalHelper.h>

namespace HS{
  namespace FIT{

    using namespace RooFit;
    using namespace RooStats;

    
    RooMcmc::~RooMcmc(){
      //if(fTreeMCMC)delete fTreeMCMC;
      //  delete fChainData;
      // delete fModelConfig;
    }
    
    void RooMcmc::Run(Setup &setup,RooAbsData &fitdata){
      //initialise MCMCCalculator
      fSetup=&setup;
      fData=&fitdata;
      
      SetModel(fSetup->GetModelConfig());
      SetupBasicUsage();

      MakeChain();
      
    }
  
    ///////////////////////////////////////////
    void RooMcmc::MakeChain()
    {
      cout<<"HSMCMC::MakeChain()"<<endl;
      if (!fData || !fPdf   ) return;
      if (fPOI.getSize() == 0) return;

   
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
      RooAbsReal* nll = prodPdf->createNLL(*fData, Constrain(*constrainedParams),ConditionalObservables(fConditionalObs));
      //RooAbsReal* nll = prodPdf->createNLL(*fData); 
      delete constrainedParams;
 
      // add in sumw/sumw2 term
      if(fData->isNonPoissonWeighted()&&fCorrectForWeights){
      	Double_t SumW=SumWeights();
      	Double_t SumW2=SumWeights2();
	TString NllName=nll->GetName();
	NllName.ReplaceAll("-","m");
	NllName.ReplaceAll("+","p");
	nll->SetName(NllName);
      	RooFormulaVar *alphanll=new RooFormulaVar("alphanll",Form("%lf*%s",SumW/SumW2,nll->GetName()),RooArgSet(*nll));
      	nll=alphanll;
      }
    
      fParams = nll->getParameters(*fData);
      RemoveConstantParameters(fParams);
    
      HSMetropolisHastings mh;
      if(fKeepStart) mh.SetKeepStart();
      mh.SetFunction(*nll);
      mh.SetType(MetropolisHastings::kLog);
      mh.SetSign(MetropolisHastings::kNegative);
      mh.SetParameters(*fParams);
      if (fChainParams.getSize() > 0) mh.SetChainParameters(fChainParams);
      mh.SetProposalFunction(*fPropFunc);
      mh.SetNumIters(fNumIters);

      fChain= mh.ConstructChain(); //mh is still owner and will delete
      
      fChainData=fChain->GetAsDataSet(EventRange(0, fChain->Size()));
      cout<<"make tree"<<endl;
      if(fChainData){
 	fTreeMCMC=RooStats::GetAsTTree("MCMCTree","MCMCTree",*fChainData);
	delete fChainData;
      }  
      cout<<"make burned in data"<<endl;
      if(fChain->Size()>fNumBurnInSteps)
	fChainData=fChain->GetAsDataSet(EventRange(fNumBurnInSteps, fChain->Size()));

 
      if (useDefaultPropFunc) delete fPropFunc;
      if (usePriorPdf) delete prodPdf;
      delete nll;
      
      return;
    }
    ////////////////////////////////////////////////////////
    
    void RooMcmc::Result(){

      cout<<"RooMcmc::Result()"<<endl;
      RooArgList saveFloatFinalList(*fChainData->get()) ;
       
      for(Int_t i=0;i<fParams->getSize();i++){
  
	RooRealVar* var=dynamic_cast<RooRealVar*>(saveFloatFinalList.at(i));
	cout<<var->GetName()<<" "<<fChainData->mean(*var)<<" +- "<<fChainData->sigma(*var)<<endl;
	((RooRealVar*)fParams->find(var->GetName()))->setVal(fChainData->mean(*var));
	((RooRealVar*)fParams->find(var->GetName()))->setError(fChainData->sigma(*var));
      }
      fChainData->covarianceMatrix()->Print();

      //Add entry branch to mcmc tree for easy cutting on BurnIn
      //fMCMCtree contains all events
      Long64_t entry=0;
      auto entryBranch=fTreeMCMC->Branch("entry",&entry,"entry/L");
      for(entry=0;entry<fTreeMCMC->GetEntries();entry++)
	entryBranch->Fill();

      AddFormulaToMCMCTree();
    }
    void RooMcmc::AddFormulaToMCMCTree(){

      auto formulas=fSetup->Formulas();
      if(!formulas.getSize()) return;
      vector<Double_t> formVals(formulas.getSize());
      vector<TBranch*> formBranches(formulas.getSize());
      TIter iter=formulas.createIterator();
      Int_t iform=0;
      while(RooFormulaVar* formu=dynamic_cast<RooFormulaVar*>(iter())){
	TString formuName=formu->GetName();
	
	formBranches[iform]=fTreeMCMC->Branch(formuName,&formVals[iform],formuName+"/D");
	iform++;
      }

      Long64_t Nmcmc=fTreeMCMC->GetEntries();
      Int_t Nleaf=fTreeMCMC->GetListOfLeaves()->GetEntries();
      for(Int_t entry=0;entry<Nmcmc;entry++){
	
	fTreeMCMC->GetEntry(entry);
	
	for(Int_t ibr=0;ibr<Nleaf;ibr++){
	  TLeaf *leaf=dynamic_cast<TLeaf*>(fTreeMCMC->GetListOfLeaves()->At(ibr));
	  RooRealVar* brVar=dynamic_cast<RooRealVar*>(fParams->find(leaf->GetName()));
	  if(brVar) brVar->setVal(leaf->GetValue());
	    
	}
	  
	
	iter.Reset();
	iform=0;
	while(RooFormulaVar* formu=dynamic_cast<RooFormulaVar*>(iter())){
	  
	  formVals[iform]=formu->getValV();
	  formBranches[iform]->Fill();
	  iform++;

	}
      }  
 
    }
    ///////////////////////////////////////////////
    Double_t  RooMcmc::SumWeights(){
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
    ///////////////////////////////////////////////////////
    Double_t  RooMcmc::SumWeights2(){
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
    //FRom MCMCCalculator
    void RooMcmc::SetModel( ModelConfig*  model) {
      // set the model
      fModelConfig=std::move(model);
      //fPdf = fModelConfig->GetPdf();
      fPdf = fSetup->Model();
      fPriorPdf = fModelConfig->GetPriorPdf();
      fPOI.removeAll();
      fNuisParams.removeAll();
      fConditionalObs.removeAll();
      fGlobalObs.removeAll();
      if (fModelConfig->GetParametersOfInterest())
	fPOI.add(*fModelConfig->GetParametersOfInterest());
      if (fModelConfig->GetNuisanceParameters())
	fNuisParams.add(*fModelConfig->GetNuisanceParameters());
      if (fModelConfig->GetConditionalObservables())
	fConditionalObs.add( *(fModelConfig->GetConditionalObservables() ) );
      if (fModelConfig->GetGlobalObservables())
	fGlobalObs.add( *(fModelConfig->GetGlobalObservables() ) );
      
    }
    /////////////////////////////////////////////////////
    void RooMcmc::SetupBasicUsage()
    {
      fPropFunc = 0;
      // fNumIters = 100;
      //fNumBurnInSteps = 10;
      //fWarmup=fNumBurnInSteps;
      
     }
    ///////////////////////////////////////////////////////////////
    file_uptr RooMcmc::SaveInfo(){
      
      TString fileName=fSetup->GetOutDir()+fSetup->GetName()+"/Results"+fSetup->GetTitle()+GetName()+".root";
      file_uptr file(TFile::Open(fileName,"recreate"));
      Result();
      
      fTreeMCMC->Write();
      //save paramters and chi2s in  dataset (for easy merging)
      RooArgSet saveArgs(fSetup->Parameters());
      saveArgs.add(fSetup->Yields());
      
      RooRealVar Nllval("NLL","NLL",NLL());
      saveArgs.add(Nllval);
     
      RooDataSet saveDS(FinalParName(),TString(GetName())+"Results",saveArgs);
      saveDS.add(saveArgs);
      saveDS.Write();
      TTree* treeDS=RooStats::GetAsTTree(ResultTreeName(),ResultTreeName(),saveDS);
      treeDS->Write();

      return std::move(file);
    }
     //////////////////////////////////////////////////////////////

    
   void RooMcmcSeq::Run(Setup &setup,RooAbsData &fitdata){
     fSetup=&setup;
     fData=&fitdata;
   //initialise MCMCCalculator
     SetData(fitdata);
     SetModel(setup.GetModelConfig());
     SetupBasicUsage();
     cout<<"Paramters of interest "<<endl;
     fPOI.Print("v");
     
     RooStats::SequentialProposal sp(fNorm);
     SetProposalFunction(sp);
     //fKeepStart=kTRUE; //start values from previous
     MakeChain();
     
      
   }
    void RooMcmcUniform2Seq::Run(Setup &setup,RooAbsData &fitdata){
     fSetup=&setup;
     fData=&fitdata;
     //initialise MCMCCalculator
     SetData(fitdata);
     SetModel(fSetup->GetModelConfig());
     SetupBasicUsage();
      
     auto NumIters0=fNumIters;
     fNumIters=2*fPOI.getSize();

     MakeChain();//default uniform for burn-in

     fNumIters=NumIters0;
     fWarmup=5;

     RooStats::SequentialProposal sp(fNorm);
     SetProposalFunction(sp);
     fKeepStart=kTRUE; //start values from previous
     MakeChain();
     
 
   }

    void RooMcmcGaus::Run(Setup &setup,RooAbsData &fitdata){
     fSetup=&setup;
     fData=&fitdata;

     //initialise MCMCCalculator
     SetData(fitdata);
     SetModel(setup.GetModelConfig());
     SetupBasicUsage();
     
     ProposalHelper ph;
     ph.SetVariables(fPOI);

     auto npars=fPOI.getSize();
    
     ph.SetWidthRangeDivisor(fNorm);
    
     ph.SetUpdateProposalParameters(true);
     ph.SetCacheSize(1000);
     fPropFunc = (ph.GetProposalFunction());
     
     
     MakeChain();
     
      
   }

 
    
  }
}


    
