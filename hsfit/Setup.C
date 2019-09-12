#include "Setup.h"
#include "Weights.h"
#include "RooHSComplex.h"
#include "RooHSEventsPDF.h"
#include "RooComponentsPDF.h"
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
      //   cout<<"****************************COPY "<<fIDBranchName<<" "<<fVars.getSize()<< " "<< other.fFormString.size()<<endl;
      //       fWS={"HSWS"};
       fFitOptions=other.fFitOptions;
       fConstraints=other.fConstraints;   
       fCut=other.fCut;
       fDataOnlyCut=other.fDataOnlyCut;

       fIDBranchName=other.fIDBranchName;
       fOutDir=other.fOutDir;
       for(auto &parStr: other.fParString)
	 LoadParameter(parStr);
       for(auto &varStr: other.fVarString)
	 LoadVariable(varStr);
       for(auto &catStr: other.fCatString)
	 LoadCategory(catStr);
       for(auto &varStr: other.fAuxVarString)
	 LoadAuxVar(varStr);
       for(auto &formStr: other.fFormString)
	 LoadFormula(formStr);
       for(auto &funcStr: other.fFuncVarString)
	 LoadFunctionVar(funcStr);
       for(auto &pdfStr: other.fPDFString)
	 FactoryPDF(pdfStr);

       for(auto &specStr: other.fSpecString)
    	LoadSpeciesPDF(specStr.first,specStr.second);

      //const parameters
       for(const auto& pdf:other.fConstPDFPars)
	 SetConstPDFPars(pdf.first,pdf.second);
       for(const auto& par:other.fConstPars)
	 SetConstPar(par.first,par.second);
      
    }

    Setup& Setup::operator=(const Setup& other){
      fFitOptions=other.fFitOptions;
      fConstraints=other.fConstraints;
      fCut=other.fCut;
      fIDBranchName=other.fIDBranchName;
      fOutDir=other.fOutDir;
      //fWS={"HSWS"};
      
      for(auto &parStr: other.fParString)
	 LoadParameter(parStr);
       for(auto &varStr: other.fVarString){
    	LoadVariable(varStr);
      }
      for(auto &catStr: other.fCatString)
    	LoadCategory(catStr);
      for(auto &varStr: other.fAuxVarString)
    	LoadAuxVar(varStr);
      for(auto &formStr: other.fFormString)
    	LoadFormula(formStr);
      for(auto &funcStr: other.fFuncVarString)
	 LoadFunctionVar(funcStr);
      for(auto &pdfStr: other.fPDFString)
    	FactoryPDF(pdfStr);
      for(auto &specStr: other.fSpecString)
    	LoadSpeciesPDF(specStr.first,specStr.second);
      
      //const parameters
      for(const auto& pdf:other.fConstPDFPars)
	SetConstPDFPars(pdf.first,pdf.second);
      for(const auto& par:other.fConstPars)
	SetConstPar(par.first,par.second);
  
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
    /// Load a fit variable e.g s.LoadParameter("X[-1,1]");
    /// Add a fit parameter X between -1 and 1
    /// and store it for when copied
    void Setup::LoadParameter(TString opt){
      LoadParameterOnTheFly(opt);
      fParString.push_back(opt);
    }
     ////////////////////////////////////////////////////////////
    /// Load a fit variable e.g s.LoadParameter("X[-1,1]");
    /// Add a fit parameter X between -1 and 1
    void Setup::LoadParameterOnTheFly(TString opt){
      auto var=dynamic_cast<RooRealVar*>(fWS.factory(opt));
      if(!var) {
	cout<<"Setup::LoadParameter "<<opt<<" failed"<<endl;
	return;
      }
      if(!fParameters.contains(*var))
	fParameters.add(*var);      
    }
     ////////////////////////////////////////////////////////////
    /// Load a fit RooAbsReal class e.g s.LoadFunctionVar("RooRealSphHarmonic::leg2(CTh[0,-1,1],Phi[0,-3.141,3.141],2,1)"));
    /// Add a fit parameter X between -1 and 1
    void Setup::LoadFunctionVar(TString opt){
      if(std::find(fFuncVarString.begin(),fFuncVarString.end(),opt)!=fFuncVarString.end()) return;
      cout<<" Setup::LoadFunctionVar "<<opt<<endl;
      auto var=dynamic_cast<RooAbsReal*>(fWS.factory(opt));
      if(!var) {
	cout<<"Setup::LoadFunctionVar "<<opt<<" failed"<<endl;
	return;
      }
      fFuncVars.add(*var);      
      fFuncVarString.push_back(opt);

      if(auto cvar=dynamic_cast<RooHSComplex*>(var) ){
	//Complex Var need to load real and imaginery parts
	LoadFunctionVar(cvar->FactoryReal());
	LoadFunctionVar(cvar->FactoryImag());
	LoadFunctionVar(cvar->FactoryImagConj());
      }
     }
    ////////////////////////////////////////////////////////////
    /// Load a formulaVar e.g s.LoadFormula("name=@v1[1,0,2]+@v2[]");
    /// Fit a variable in your tree called X between -1 and 1
    void Setup::LoadFormula(TString formu){
      fFormString.push_back(formu);
      //get formula name
      TString name=formu(0,formu.First("="));
      strings_t pars;
      strings_t ranges;
      ReadFormula(formu,pars,ranges);
      for(UInt_t i=0;i<pars.size();i++){
	if(ranges[i]!=TString("[]")) LoadParameterOnTheFly(pars[i]+ranges[i]);
      }
      //get rid of [range]
      for(auto& range:ranges)
	formu.ReplaceAll(range, "");
      //get rid of name=
      formu=formu(formu.First("=")+1,formu.Sizeof());
      //get rid of @
      formu.ReplaceAll("@", "");
      RooArgList rooPars;
      for(auto& par:pars)
	if(fWS.var(par))rooPars.add(*fWS.var(par));
	else if(fWS.function(par))rooPars.add(*fWS.function(par));
	else if(fWS.cat(par))rooPars.add(*fWS.cat(par));
	else Error("Setup::LoadFormula"," unknown parameter");
      
      //      rooPars.Print();
      RooFormulaVar fovar(name,formu,rooPars) ;

      //fovar.Print();
      fWS.import(fovar);
      if(fWS.function(name))
	fFormulas.add(*fWS.function(name));
      else Fatal("Setup::LoadFormula","Formula didn't compile");
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
 
      auto typeIter=cat->typeIterator();
      if(fCut.Sizeof()>1)fCut+="&&";
      fCut+="(";
      Bool_t first=kTRUE;
      while(auto type=dynamic_cast<RooCatType*>(typeIter->Next())){
	if(first){
	  fCut+=Form("%s==%d",cat->GetName(),type->getVal());
	  first=kFALSE;
	}
	else
	  fCut+=Form("||%s==%d",cat->GetName(),type->getVal());
	  
      }
      fCut+=")";
     
      
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
    ////////////////////////////////////////////////////////////
    /// Use RooFit Workspace factory to define PDFs
    /// In addition handle special "new" PDF types
    void Setup::FactoryPDF(TString opt){
      fPDFString.push_back(opt);
      if(opt.Contains("WEIGHTS@")){
	opt.ReplaceAll("WEIGHTS@","$"); //$ should be a safe character!!!!

	TString wopt=opt(opt.First("$")+1,opt.Sizeof()-opt.First("$"));
	opt=opt(0,opt.First("$"));


	RooAbsArg* pdf=nullptr;
	//Checck for special non-RooFit PDFs
	if(opt.Contains("RooComponentsPDF")){
	  pdf=ComponentsPDF(opt);
	}
	else	//create PDF as normal
	  pdf=fWS.factory(opt);
	

	///////////////////////////////////
	//check if EventsPDF
	auto *evPdf=dynamic_cast<RooHSEventsPDF*>(pdf);
	if(evPdf){
	  // evPdf->SetInWeights(wgtcon);
	  fPDFInWeights[evPdf->GetName()]=wopt;
	}	
	else{	
	  cout<<	"WARNING Setup::FactoryPDF trying to give weights to non RooHSEventsPDF "<< opt<<" "<<wopt<<endl;
	}	
      }
      else{
	RooAbsArg* pdf=nullptr;
	//Check for special non-RooFit PDFs
	if(opt.Contains("RooComponentsPDF")){
	  pdf=ComponentsPDF(opt);
	}
	else	//create PDF as normal
	  pdf=fWS.factory(opt);
      }

    }
    ///////////////////////////////////////////////////////////
    /// Create PDF, parameters formulas and functions from PdfParser
    void Setup::ParserPDF(TString str, PARSER::PdfParser& parse){
      //Get the FactoryPDF string and create functions etc
      auto pdfString=parse.ConstructPDF(str.Data());

      //Load Parameters
      auto pars = parse.GetParameters();
      for(auto& par:pars)
	LoadParameter(par);
    //LoadFormulas
      auto forms = parse.GetFormulas();
      for(auto& form:forms)
	LoadFormula(form);
       //LoadFunctionVars
      auto funs = parse.GetFunctions();
      for(auto& fun:funs){
	cout<<"Load Function var "<<fun<<endl;
	LoadFunctionVar(fun);
	
      }
       
      FactoryPDF(pdfString);
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
    ///Special ComponentsPDF factory
    RooAbsPdf* Setup::ComponentsPDF(TString opt){
      opt.ReplaceAll("RooComponentsPDF::","");
      TString pdfName=opt(0,opt.First("("));
      //  fWS.Print();
      //cout<<"ComponentsPDF "<<pdfName<<endl;
      //Get baseline
      TString	sbaseLine=opt(opt.First("(")+1,opt.First(",")-opt.First("(")-1);
      Double_t baseLine=sbaseLine.Atof();
      //make observable list
      TString sobs=opt(opt.First("{")+1,opt.First("}")-opt.First("{")-1);
      auto obsStrings=sobs.Tokenize(",");
      RooArgList obsList("RooComponentsPDF::ComponentObservables");
      auto varsAndCats=FitVarsAndCats();
      //cout<<"Observable String "<<sobs<<endl;
      for(Int_t i=0;i<obsStrings->GetEntries();i++ ){
	//cout<<"      "<<obsStrings->At(i)->GetName()<<endl;
	obsList.add(*varsAndCats.find(obsStrings->At(i)->GetName()));
      }
      delete obsStrings;
      
      //obsList.Print("v");
      
      //make component list
      //TString scomps=opt(opt.First("<")+1,opt.First(">")-opt.First("<")-1);
      TString scomps=opt(opt.First("=")+1,opt.Last(')')-opt.First("=")-1);
      //cout<<opt<<" "<<opt.First("=")<<" "<<opt.Sizeof()<<" "<<opt.Sizeof()-opt.First("=")<<" "<<scomps.Sizeof()<<endl;
      
      scomps.ReplaceAll("{","");
      scomps.ReplaceAll("}","");
      auto compStrings=scomps.Tokenize(":");
      vector<RooArgList> compsLists;
      Int_t ic=0;
      //cout<<"Components String "<<scomps<<endl;
      for(Int_t i=0;i<compStrings->GetEntries();i++ ){
	//	cout<<"      "<<compStrings->At(i)->GetName()<<endl;
	RooArgList termList(Form("RooComponentsPDF::Term%d",ic++));
	TString term = compStrings->At(i)->GetName();
	auto termStrings=term.Tokenize(";");
	for( Int_t j=0;j<termStrings->GetEntries();j++ ){
	  //	  cout<<"                 "<<termStrings->At(j)->GetName()<<endl;
	  
	  TString sarg = termStrings->At(j)->GetName();
	  TString vname =sarg;
	  if(sarg.Contains("=")){//look for formula
	    LoadFormula(sarg);//Load formula
	    vname=sarg(0,sarg.First("=")); //get the var name
	  }
	  else  if(sarg.Contains("[")){//look for new parameter
	    LoadParameterOnTheFly(sarg);
	    vname=sarg(0,sarg.First("[")); //get the par name
	  }
	  // else cout<<"Will look for "<<vname<<endl;
	  if( dynamic_cast<RooRealVar*>(fWS.var(vname))){
	    //cout<<"GOT PAR "<<endl;
	    termList.add(*fWS.var(vname));
	  }
	  else if( dynamic_cast<RooCategory*>(fWS.cat(vname))) termList.add(*fWS.cat(vname));
	  else if ( dynamic_cast<RooFormulaVar*>(fWS.function(vname))) termList.add(*fWS.function(vname));
	  else if ( dynamic_cast<RooAbsReal*>(fWS.function(vname))) termList.add(*fWS.function(vname)); //for function vars
	  else Fatal("RooAbsPdf* Setup::ComponentsPDF(TString opt)","variable not found");
	}
	//termList.Print("v");
	compsLists.push_back(termList);//add this term to the components list
	delete termStrings;
      }
      delete compStrings;
      //create pdf and import to workspace
      auto pdf=new RooComponentsPDF(pdfName,pdfName,baseLine,obsList,compsLists);
      fWS.import(*pdf);
      return pdf;
    }
    //////////////////////////////////////////////////////////
    ///Create the PDF sum for Extended ML fit
    void Setup::TotalPDF(){
  
      //if(fModel)fModel->Print();

      //Construct a total PDF whcih is the sum of the species PDFs
      fModel=new RooAddPdf(fName+"TotalPDF","total model",
			   fPDFs, 
			   fYields);
      //fModel->Print();
      AddFitOption(RooFit::Extended());
    }
    //////////////////////////////////////////////////////////
    Double_t Setup::SumOfYields(){
      //fYields.Print("v");
      //fParsAndYields.Print("v");
      Double_t sum=0;
      TIter iter=fYields.createIterator();
      while(RooRealVar* arg=(RooRealVar*)iter())
	sum+=arg->getValV();

      return sum;
 
    }
    RooArgSet& Setup::Cats(){
      if(fCats.getSize())
	return fCats;
      fCats.add(MakeArgSet(fFitCats));
      return fCats;
    }
    RooArgSet& Setup::DataVars(){
      fVars.removeAll();
      fVars.add(MakeArgSet(fFitVars));
      fVars.add(MakeArgSet(fFitCats));
      fVars.add(MakeArgSet(fAuxVars));
      if(!fWS.var(fIDBranchName)){
	fWS.factory(fIDBranchName+"[0,9.99999999999999e14]");
      }
      fVars.add(*fWS.var(fIDBranchName));
      return fVars;
    }
   RooArgSet& Setup::FitVarsAndCats(){
      if(fVarsAndCats.getSize())
	return fVarsAndCats;
      fVarsAndCats.add(MakeArgSet(fFitVars));
      fVarsAndCats.add(MakeArgSet(fFitCats));
      return fVarsAndCats;
    }
   RooArgSet& Setup::ParsAndYields(){
      if(fParsAndYields.getSize())
	return fParsAndYields;
      fParsAndYields.add(fParameters);
      fParsAndYields.add(fYields);
      return fParsAndYields;
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

    void ReadFormula(TString forma, strings_t& svars,strings_t& sranges){
      
      svars.clear();
      sranges.clear();
      Bool_t addIt=kTRUE;

      for(Int_t i=0;i<forma.Sizeof();i++){
	if(TString(forma[i])=="@"){
	  Int_t j=i;
	  for(;j<forma.Sizeof();j++){
	    if(TString(forma[j])=="["){
	      TString varname=forma(i+1,j-i-1);
	      if(std::find(svars.begin(),svars.end(),varname)==svars.end()){
		svars.push_back(varname);
		addIt=kTRUE;
	      }
	      else addIt=kFALSE;
	      i=j;
	      continue;
	    }
	    if(TString(forma[j])=="]"){
	      if(addIt)sranges.push_back(forma(i,j-i+1));
	      i=j;
	      break;
	    }
	    
	  }
	}
      }
    

    }

    
  }//namespace FIT
}//namesapce HS
