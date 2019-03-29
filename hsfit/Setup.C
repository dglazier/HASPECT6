#include "Setup.h"
#include <RooGenericPdf.h>
#include <RooAbsData.h>
#include <RooDataSet.h>
#include <TRandom.h>


namespace HS{
  namespace FIT{


    Setup::Setup():TNamed(){
      //RooAbsData::setDefaultStorageType(RooAbsData::Tree);
      DefaultFitOptions();
    }
    Setup::Setup(TString name):TNamed(name,name){
      //RooAbsData::setDefaultStorageType(RooAbsData::Tree);
      DefaultFitOptions();
    }
    
    Setup::Setup(const Setup& other):TNamed(other.fName,other.fName){
      cout<<"%%%%%%%%%%%%%%%%%%%%%copy setup "<<endl;
      fWS={"HSWS"};
      for(auto &varStr: other.fVarString)
    	LoadVariable(varStr);
      for(auto &catStr: other.fCatString)
    	LoadCategory(catStr);
      for(auto &varStr: other.fAuxVarString)
    	LoadAuxVar(varStr);
      for(auto &pdfStr: other.fPDFString)
    	FactoryPDF(pdfStr);
      for(auto &specStr: other.fSpecString)
    	LoadSpeciesPDF(specStr.first,specStr.second);
      
      fFitOptions=other.fFitOptions;
      fConstraints=other.fConstraints;
      
      fCut=other.fCut;
      fIDBranchName=other.fIDBranchName;
      fOutDir=other.fOutDir;

    }

    Setup& Setup::operator=(const Setup& other){
      cout<<"@@@@@@@@@@@@@@@@@@@copy setup "<<endl;
      fWS={"HSWS"};
      for(auto &varStr: other.fVarString){
    	LoadVariable(varStr);
      }
      for(auto &catStr: other.fCatString)
    	LoadCategory(catStr);
     for(auto &varStr: other.fAuxVarString)
    	LoadAuxVar(varStr);
       for(auto &pdfStr: other.fPDFString)
    	FactoryPDF(pdfStr);
      for(auto &specStr: other.fSpecString)
    	LoadSpeciesPDF(specStr.first,specStr.second);
      
  
      fFitOptions=other.fFitOptions;
      fConstraints=other.fConstraints;

      fCut=other.fCut;
      fIDBranchName=other.fIDBranchName;
      fOutDir=other.fOutDir;

      return *this;
    }
 
    ////////////////////////////////////////////////////////////
    /// Load a fit variable e.g s.LoadVariable("X[-1,1]");
    /// Fit a variable in your tree called X between -1 and 1
    void Setup::LoadVariable(TString opt){

      auto var=dynamic_cast<RooRealVar*>(fWS.factory(opt));
      if(!var) {
	cout<<"Setup::LoadVariable "<<opt<<" failed"<<endl;
	return;
      }
      fVarString.push_back(opt);
      fFitVars.push_back(var);      
    }
    ////////////////////////////////////////////////////////////
    /// Load a category e.g. s.LoadCategory("Pol[m=-1,p=1]");
    /// PDF can depend on a data category called Pol which may
    /// have values -1 or 1 (other valued events are discarded 
    void Setup::LoadCategory(TString opt){
      auto cat=dynamic_cast<RooCategory*>(fWS.factory(opt));
      if(!cat) {
	cout<<"Setup::LoadCategory "<<opt<<" failed"<<endl;
	return;
      }
      fCatString.push_back(opt);
      fFitCats.push_back(cat);
   
    }
    /////////////////////////////////////////////////////////
    ///LoadAuxVars can bes used to cut input trees and keeping
    ///variable branches in binned or reduced trees
    ///the limits of the variable are added to Cut and applied to data import
    void Setup::LoadAuxVar(TString opt){
      auto var=dynamic_cast<RooRealVar*>(fWS.factory(opt));
      fAuxVars.push_back(var);
     
      RooRealVar* varreal=nullptr;
 
      if((varreal=dynamic_cast<RooRealVar*>(var))){
	if(fCut.Sizeof()>1)fCut+="&&";
	fCut+=Form("%s>=%lf&&%s<=%lf",varreal->GetName(),varreal->getMin(),varreal->GetName(),varreal->getMax());   
      }
     fAuxVarString.push_back(opt);
     }
    ///////////////////////////////////////////////////////////
    ///Set this PDF to be included in extended ML fit
    ///This function will create the associated yield paramter
    void Setup::LoadSpeciesPDF(TString opt,Float_t Scale0){
      //take a copy of the pdf from the workspace, so no ownership issues
      auto* pdf=reinterpret_cast<RooGenericPdf*>(fWS.pdf(opt)->clone());
      fPDFs.add(*pdf);//RooGeneric is just a dummy, add does not take RooAbsPdf
      fParameters.add(*(fPDFs.find(opt)->getParameters(DataVars())));// get parameters not in fit variables 
      //     fParameters.add(*(fPDFs.find(opt)->getParameters(MakeArgSet(fFitVars,fFitCats))));// get parameters not in fit variables 
      //Add a yield parameter for this species
      fYields.add(*(fWS.factory(fYld+opt+Form("[%f,0,1E12]",Scale0))));//default yields limits
      fSpecString.push_back(std::make_pair<TString,Float_t>(std::move(opt),std::move(Scale0)));
    }
    
    //////////////////////////////////////////////////////////
    ///Create the PDF sum for Extended ML fit
    void Setup::TotalPDF(){
  
      if(fModel)fModel->Print();

      //Construct a total PDF whcih is the sum of the species PDFs
      fModel=new RooAddPdf(fName+"TotalPDF","total model",
			   fPDFs, 
			   fYields);
      fModel->Print();
      AddFitOption(RooFit::Extended());
    }
    RooArgSet& Setup::DataVars(){
      if(fVars.getSize())
	return fVars;
      fVars.add(MakeArgSet(fFitVars));
      fVars.add(MakeArgSet(fFitCats));
      fVars.add(MakeArgSet(fAuxVars));
      fWS.factory(fIDBranchName+"[0,9.99999999999999e14]");
      fVars.add(*fWS.var(fIDBranchName));
      return fVars;
    }

    void Setup::RandomisePars(){
      //randomise fit parameters
      for(Int_t ip=0;ip<fParameters.getSize();ip++){
	RooRealVar *par=((RooRealVar*)&fParameters[ip]);
	//check if par this is fxed constant.
	if(par->isConstant()) continue;
	//Look through constraints to see if one is defined for this parameter
	Bool_t hadCon=kFALSE;
	for(Int_t ic=0;ic<fConstraints.getSize();ic++){
	  RooAbsPdf *pdfCon=((RooAbsPdf*)&fConstraints[0]);//get RooPdf constraint
	  if(pdfCon->getObservables(fParameters)->contains(*par)){ //does it contain par?
	    //Yes, must generate random number from constraint
	    RooArgSet setPar(*par); //make an argset from this 1 par as needed for..
	    RooDataSet *oneEv=pdfCon->generate(setPar,1); //gen 1 event
	    const RooArgSet* theEv = oneEv->get(); //get the event
	    theEv->getRealValue(par->GetName()); //get par value of event
	    hadCon=kTRUE;
	    delete oneEv;
	    break;//can only have 1!	
	  }
	}
	//If there was no constraint to select from just take random in range 
	if(!hadCon)par->setVal(gRandom->Uniform(par->getMin(""),par->getMax("")));
      }//end Paramter loop
    }

    ////////////////////////////////////////////////////////////
    RooStats::ModelConfig*  Setup::GetModelConfig(){
      auto modelConfig =new RooStats::ModelConfig(&fWS);
      modelConfig->SetParametersOfInterest(fParameters);
      modelConfig->SetPdf(*fModel);
      return std::move(modelConfig);
    }

    ////////////////////////////////////////////////////////////
    ///Utiltiy functions
    RooArgSet MakeArgSet(realvars_t vars){
      RooArgSet aset;
      for(auto rv: vars)
	aset.add(*rv);
      return aset;
    }
    RooArgSet MakeArgSet(catvars_t cats){
      RooArgSet aset;
      for(auto rv: cats)
	aset.add(*rv);
      return aset;
    }
    void SetAllValLimits(RooArgList& items,Double_t val,Double_t low,Double_t high){
      for(Int_t idr=0;idr<items.getSize();idr++){
	auto item=dynamic_cast<RooRealVar*>( &items[idr]);
	if(item){
	  item->setVal(val);//get variable
	  if(low!=high)
	    item->setRange(low,high);
	}
      }
    }
  }//namespace FIT
}//namesapce HS
