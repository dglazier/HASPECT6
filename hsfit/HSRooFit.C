#include "HSRooFit.h"
#include <TSystem.h>
#include <TRandom.h>
#include <TH1.h>
#include <TH2.h>
#include <TMath.h>
#include <TDirectory.h>
#include <TLegend.h>
#include <TVectorD.h>
#include <RooGenericPdf.h>
#include <RooDataHist.h>
#include <RooAbsData.h>
#include <RooChi2Var.h>
#include <RooHist.h>
#include <RooConstVar.h>
#include "RooMinimizer.h"
#include "RooMinuit.h"
#include "RooHSEventsHistPDF.h"
#include "RooRandom.h"
#include <RooStats/SequentialProposal.h>
#include "RooStats/RooStatsUtils.h"
#include <algorithm>      // std::sort
#include <list>     

namespace HS{
  namespace FIT{
    TList* gRooFits=new TList();//when moving between different root scripts
    HSRooFit* gRF= nullptr;//when moving between different root scripts
  }
}


using namespace HS;
using namespace HS::FIT;
using namespace RooFit;

HSRooFit::HSRooFit() : TNamed(){};

HSRooFit::HSRooFit(TString name,RooWorkspace* ws) : TNamed(name,name){
  fOwnWorkSpace=kFALSE;
  //Use an already existing workspace
  fWS=ws;
  fCanvases=new TList();fCanvases->SetOwner();
  fHists=new TList();fHists->SetOwner();
  fRooFits=new TList();fRooFits->SetOwner();
  RooFit::Minimizer("Minuit2");
  RooFit::PrintLevel(1) ;
  RooAbsData::setDefaultStorageType(RooAbsData::Tree);//seems to use less memory
}

HSRooFit::HSRooFit(TString name) : TNamed(name,name){
  fOwnWorkSpace=kTRUE;
  fWS = new RooWorkspace("wHS");
  fGotID=kFALSE;
  fCanvases=new TList();fCanvases->SetOwner();
  fHists=new TList();fHists->SetOwner();
  fRooFits=new TList();fRooFits->SetOwner();
  RooFit::Minimizer("Minuit2");
  RooFit::PrintLevel(1) ;
  RooAbsData::setDefaultStorageType(RooAbsData::Tree);//seems to use less memory
 
}
HSRooFit::HSRooFit(HSRooFit* rf){
  //  HSRooFit();
   //copy constructor, but do not copy the data tree, load that explicitly
  fOwnWorkSpace=kTRUE;
  LoadWorkSpace(rf->GetWorkSpace(),rf->GetName());
 
  if(rf->GetBins())fDataBins=(Bins*)rf->GetBins()->Clone();
  //if(rf->fID) fID=rf->fID;
  fIsPlot=rf->fIsPlot;
  fBinnedFit=rf->fBinnedFit;
  fSingleSp=rf->fSingleSp;
  fOutDir=rf->fOutDir;
  fBinDir=rf->fBinDir;
  //  fStudyPDF=rf->fStudyPDF;
  //fStudyPlot=rf->fStudyPlot;
  // fNStudyTrials=rf->fNStudyTrials;
  fInWeights=rf->fInWeights;
  fWeightName=rf->fWeightName;
  fFitMethod=rf->fFitMethod;
}

HSRooFit::~HSRooFit(){
  if(fWS&&fOwnWorkSpace) {delete fWS;fWS=nullptr;}
  //if(fCanvases)delete fCanvases;
  if(fHists){delete fHists;fHists=nullptr;}
  if(fResult) {delete fResult;fResult=nullptr;}
  //if(fRooFits) delete fRooFits;=nullptr;}
  if(fDataBins) {delete fDataBins;fDataBins=nullptr;}
  if(fMCIntTree) {delete fMCIntTree;fMCIntTree=nullptr;}
  if(fMCGenTree) {delete fMCGenTree;fMCGenTree=nullptr;}
  if(fModelConfig) {delete fModelConfig;fModelConfig=nullptr;}
  if(fInWeights&&fOwnWorkSpace) {delete fInWeights;fInWeights=nullptr;}
 }

void HSRooFit::LoadDataSet(TTree* tree,Bool_t toWS){
  ftoWS=toWS;
  //Take a tree and convert to RooDataSet
  if(!tree) {cout<<"Tree does not exist "<<endl;exit(0);}
  fTree=tree;//->CopyTree(fCut);
  RooArgSet dataVars(fVariables,fAuxVars);
  if(fID) dataVars.add(*fID);
  TTree* tempTree=tree->CopyTree(fCut);

  tree->SetBranchStatus("*",0);
  for(Int_t i=0;i<fVariables.getSize();i++){//only copy variable branches for speed
    tree->SetBranchStatus(fVariables[i].GetName(),1);
  }
  for(Int_t i=0;i<fAuxVars.getSize();i++){//only copy variable branches for speed
    // tree->SetBranchStatus(fAuxVars[i].GetName(),1);
  }
  //but always need ID branch
  if(tree->GetBranch(fIDBranchName)){
    tree->SetBranchStatus(fIDBranchName,1);
  }
  
  // fData=new RooDataSet(tree->GetName(),tree->GetTitle(),dataVars,RooFit::Import(*tree)); //make roodatset if not splitting onto bins
  //  fData=new RooDataSet(tree->GetName(),tree->GetTitle(),dataVars,RooFit::Import(*tree),RooFit::Cut(fCut)); //make roodatset if not splitting onto bins
  fData=new RooDataSet(tree->GetName(),tree->GetTitle(),dataVars,RooFit::Import(*tempTree)); //make roodatset if not splitting onto bins
  delete tempTree;
  if(toWS) fWS->import(*fData); //import if told to
  // else if(!(fDataBins))if(!fInWeights)fWS->import(*fData); //if not told to import if not bins
  //else if not told to import and there are bins don't import
  cout<<"HSRooFit::LoadDataSet(TTree*) Print dataset for "<<tree->GetName()<<endl;
  fData->Print();
}
void HSRooFit::RemoveDataSet(){
  if(fData) {fData->SetName("Empty");fData->reset();}
  if(!fTree)return;//no tree dataset
  delete fTree;
  //if(fData) delete fData;//crashes workspace...
}
void HSRooFit::CleanWSDataSets(){
  list<RooAbsData*> datalist=fWS->allData();
  for (std::list<RooAbsData*>::iterator it = datalist.begin(); it != datalist.end(); it++){
    ((RooDataSet*)*it)->SetName("Cleared");
    ((RooDataSet*)*it)->reset();
  }
}
void HSRooFit::LoadDataSet(RooAbsData* data,Bool_t toWS){
  ftoWS=toWS;
  if(!data) {cout<<"LoadDataSet(RooAbsData*) No valid data set "<<endl;return;}
  //Take a tree and convert to RooDataSet
  //if(fWS->pdf("TotalPDF"))fWS->pdf("TotalPDF")->SetNameTitle("OldPDF","OldPDF");
  //Make sure events in data match variable and cut definitions
  RooArgSet dataVars(fVariables,fAuxVars);
  if(fID) dataVars.add(*fID);
  RooAbsData* dataCut=data->reduce(dataVars,fCut);
  // delete data;data=nullptr;
  if(toWS) fWS->import(*dataCut);
  else if(!(fDataBins))if(!fInWeights)fWS->import(*dataCut); //if not told to import if not bins
  //else if not told to import and there are bins don't import
  fData=dataCut;
  cout<<"HSRooFit::LoadDataSet Print dataset for "<<fData->GetName()<<endl;
  fData->Print();
}
void HSRooFit::LoadWorkSpaceData(RooWorkspace* ws,TString rfname){
  LoadWorkSpace(ws,rfname);
  LoadDataSet(ws->allData().front());//assumes only 1 data set!!
}
void HSRooFit::LoadWorkSpace(RooWorkspace* ws,TString rfname){
  fOwnWorkSpace=kFALSE;
  if(rfname==TString("")){
    //if no name given take name of this RF
    //i.e. for reloading a workspace into a previous defined RF
    //e.g. for ToyStudies
    rfname=GetName();
  }
  cout<<"HSRooFit::LoadWorkSpace WS "<<rfname<<" "<<fWS<<" "<<ws<<endl;
  //else the given name is used
  //this is useful for creating subfits when binning etc
  //and the new RF has a different name to the RF which created the workspace
  //load model from workspace, does not load data
  //This allows to create a new HSRooFit object for different trees

  if(!ws) {cout<<"Warning void HSRooFit::LoadWorkSpace NULL workspace supplied returning"<<endl; return;}
  if(fWS){ delete fWS;fWS=nullptr;} //replace the one made in constructor
  fWS=ws;
  fWS->Print();
  //  fVariables.Print();
  // if(fWS->set(rfname+"Variables")){fVariables.removeAll();fVariables.add(*(fWS->set(rfname+"Variables")));fWS->import(fVariables,RooFit::RecycleConflictNodes());}
  fWS->set(rfname+"Variables")->Print();
  // if(fWS->set(rfname+"Variables")){fVariables.removeAll();fVariables.add(*(fWS->set(rfname+"Variables")));fWS->import(fVariables);}
  if(fWS->set(rfname+"Variables")){fVariables.removeAll();fVariables.add(*(fWS->set(rfname+"Variables")));}
  if(fWS->set(rfname+"AuxVars")){fAuxVars.removeAll();fAuxVars.add(*(fWS->set(rfname+"AuxVars")));}
  if(fWS->set(rfname+"BinVars")){fBinVars.removeAll();fBinVars.add(*(fWS->set(rfname+"BinVars")));}
  if(fWS->set(rfname+"Parameters")){fParameters.removeAll();fParameters.add(*(fWS->set(rfname+"Parameters")));}
  if(fWS->set(rfname+"Yields")){fYields.removeAll();fYields.add(*(fWS->set(rfname+"Yields")));}
  if(fWS->set(rfname+"PDFs")){fPDFs.removeAll();fPDFs.add(*(fWS->set(rfname+"PDFs")));}
  if(fWS->set(rfname+"Constraints")){fConstraints.removeAll();fConstraints.add(*(fWS->set(rfname+"Constraints")));}
  // if(fWS->set("FitOptions"))fFitOptions.add(*(fWS->set("FitOptions")));
  if(fWS->set("ID")) {
    fIDBranchName=(fWS->set("ID"))->first()->GetName();
    fID=fWS->var(fIDBranchName);
    fGotID=kTRUE;
  }
  else fGotID=kFALSE;
    if(!fWS->set(TString(GetName())+"PDFs"))DefineSets();//Will be tagged with new rf name
  // fWS->Print();
}
TTree* HSRooFit::GetFileTree(TString filename,TString treename){
  TDirectory* saveDir=gDirectory;
  TFile* file=new TFile(filename);
  TTree* tree=(TTree*)file->Get(treename);
  saveDir->cd();
  return tree; 
}
void HSRooFit::LoadPartSet(TString setname, RooArgList *list){
  cout<<setname<<endl;
  if(fWS->set(setname)){
    RooArgSet newset;
    RooArgSet wsset=*(fWS->set(setname));
    wsset.Print();
    list->removeAll();
     list->add(wsset);
  }
  list->Print();
}
void HSRooFit::MergeWorkSpace(HSRooFit* rf){
  RooWorkspace* ws=rf->GetWorkSpace();
  TString rfname=rf->GetName();
  fWS->defineSet(rfname+"Variables",*ws->set(rfname+"Variables"),kTRUE);
  fWS->defineSet(rfname+"AuxVars",*ws->set(rfname+"AuxVars"),kTRUE);
  fWS->defineSet(rfname+"BinVars",*ws->set(rfname+"BinVars"),kTRUE);
  fWS->defineSet(rfname+"Parameters",*ws->set(rfname+"Parameters"),kTRUE);
  fWS->defineSet(rfname+"Yields",*ws->set(rfname+"Yields"),kTRUE);
  fWS->defineSet(rfname+"PDFs",*ws->set(rfname+"PDFs"),kTRUE);
  fWS->defineSet(rfname+"Constraints",*ws->set(rfname+"Constraints"),kTRUE);
  
}
void HSRooFit::LoadOverlapWorkSpace(RooWorkspace* ws,TString rfname){
  fOwnWorkSpace=kFALSE;
  rfname=GetName();
  cout<<"WS "<<rfname<<" "<<fWS<<" "<<ws<<" "<<GetName()<<endl;
  //else the given name is used
  //this is useful for creating subfits when binning etc
  //and the new RF has a different name to the RF which created the workspace
  //load model from workspace, does not load data
  //This allows to create a new HSRooFit object for different trees

  if(!ws) {cout<<"Warning void HSRooFit::LoadWorkSpace NULL workspace supplied returning"<<endl; return;}
  RooWorkspace *oldWS=nullptr;
  if(fWS) oldWS=fWS;
  //  if(fWS){ delete fWS;fWS=nullptr;} //replace the one made in constructor
  fWS=ws;
  fWS->Print();
  //fVariables.Print();
  // if(fWS->set(rfname+"Variables")){fVariables.removeAll();fVariables.add(*(fWS->set(rfname+"Variables")));fWS->import(fVariables,RooFit::RecycleConflictNodes());}
  fWS->set(rfname+"Variables")->Print();
  // if(fWS->set(rfname+"Variables")){fVariables.removeAll();fVariables.add(*(fWS->set(rfname+"Variables")));fWS->import(fVariables);}
  LoadPartSet(rfname+"Variables",&fVariables);
  LoadPartSet(rfname+"AuxVars",&fAuxVars);
  LoadPartSet(rfname+"BinVars",&fBinVars);
  LoadPartSet(rfname+"Parameters",&fParameters);
  LoadPartSet(rfname+"Yields",&fYields);
  LoadPartSet(rfname+"PDFs",&fPDFs);
  LoadPartSet(rfname+"Constraints",&fConstraints);
  // if(fWS->set("FitOptions"))fFitOptions.add(*(fWS->set("FitOptions")));
  if(fWS->set("ID")) {
    fIDBranchName=(fWS->set("ID"))->first()->GetName();
    fID=fWS->var(fIDBranchName);
    fGotID=kTRUE;
  }
  else fGotID=kFALSE;
  
  if(!fWS->set(TString(GetName())+"PDFs"))DefineSets();//Will be tagged with new rf name
  // if(oldWS){ delete oldWS;oldWS=nullptr;}
  // fWS->Print();
}
void HSRooFit::DefineSets(){
  TString rfname=GetName(); //convert name to TString
  //define var types in workspace, for easy reloading
  fWS->defineSet(rfname+"Variables",fVariables);
  fWS->defineSet(rfname+"AuxVars",fAuxVars);
  fWS->defineSet(rfname+"BinVars",fBinVars);
  fWS->defineSet(rfname+"Parameters",fParameters);
  fWS->defineSet(rfname+"Yields",fYields);
  fWS->defineSet(rfname+"PDFs",fPDFs);
  fWS->defineSet(rfname+"Constraints",fConstraints);
  // fWS->defineSet("FitOptions",fFitOptions);
}
void HSRooFit::SetParVals(RooFitResult *res){
  SetParVals(res->floatParsFinal());
}
void HSRooFit::SetParVals(RooArgList pars){
  for(Int_t ip=0;ip<pars.getSize();ip++){
    cout<<ip<<" "<<pars.at(ip)->GetName()<<endl;
    Int_t ind=fParameters.index(pars.at(ip)->GetName());
    if(ind==-1) continue;
    RooRealVar* realpar=nullptr;
    if((realpar=dynamic_cast<RooRealVar*>(pars.at(ip))))
      ((RooRealVar*)fParameters.at(ind))->setVal(realpar->getVal());
  }
}
void HSRooFit::LoadWeights(TString wfile,TString wname){
  //GetWeights object 
  cout<<"void HSRooFit::LoadWeights "<<wfile<<" "<<wname<<endl;
  if(fInWeights) delete fInWeights;
  fInWeights=0;
  fInWeights=new HS::Weights();
  fInWeights->LoadSaved(wfile,wname);
  fIDBranchName=fInWeights->GetIDName();
  fInWeights->PrintWeight();
}
void HSRooFit::SetDataWeight(){
  if(!fInWeights) return;
  if(fInWeights->GetSpeciesID(fWeightName)<0) return;
  RooArgList setWeights;
  RooRealVar wvar(fWeightName,fWeightName,0);
  setWeights.add(wvar);
  setWeights.Print();
  RooDataSet wData("weights","weights",setWeights) ;
  cout<<"HSRooFit::SetDataWeight() Print data "<<endl;
  fData->Print();
  //Loop over the weights find the entry for the event ID
  if(fInWeights->GetIDName().Sizeof()>1)fIDBranchName=fInWeights->GetIDName();
  for(Int_t ev=0;ev<fData->numEntries();ev++){
    const RooArgSet* vars=fData->get(ev);
    fInWeights->GetEntryBinarySearch((Long64_t)vars->getRealValue(fIDBranchName));
    // cout<<fInWeights->GetWeight(fWeightName)<<endl;
    // wvar.setVal(fInWeights->GetWeight(fWeightName));
    wvar.setVal(fInWeights->GetWeight(fWeightName));
    wData.add(setWeights);
  }
  wData.Print();
  ((RooDataSet*)fData)->merge(&wData);
  fData->Print();
  RooDataSet* nonZeroWeights=(RooDataSet*)fData->reduce(fWeightName+"!=0"); 
  wData.reset();
  fData->reset();
  RooDataSet* tmpData=0;
  tmpData=new RooDataSet(TString("Weight_")+fWeightName+fData->GetName(),fData->GetTitle(),nonZeroWeights,*nonZeroWeights->get(),0,fWeightName);
  delete nonZeroWeights;nonZeroWeights=nullptr;
  
  //  tmpData=new RooDataSet(TString("Weight_")+fWeightName+fData->GetName(),fData->GetTitle(),(RooDataSet*)fData,*fData->get(),0,fWeightName);
  fData->SetName("Empty");fData->reset();fData=0;
  fData=tmpData;
  fData->Print();
  //if(ftoWS) fWS->import(*fData); //import if told to
  // else if(!(fDataBins))fWS->import(*fData); //or no databins to confuse it
  // delete fInWeights;fInWeights=nullptr;
}
void HSRooFit::SetDataWeightFast(){
  //Ignore ID just merge with dataset which should have same entries
  if(!fInWeights) return;
  if(fInWeights->GetSpeciesID(fWeightName)<0) return;
  if(fInWeights->GetTree()->GetEntries()!=fData->numEntries()) {
    Error("HSRooFit::SetDataWeightFast()"," dataset and weights do not match entries");
    return;
  }
  RooArgList setWeights;
  RooRealVar wvar(fWeightName,fWeightName,0);
  setWeights.add(wvar);
  setWeights.Print();

  RooDataSet wData("Weights","Weights",setWeights,RooFit::Import(*fInWeights->GetTree())); //make roodatset if not splitting onto bins
  wData.Print();
  ((RooDataSet*)fData)->merge(&wData);
  
  fData->Print();
  RooDataSet* tmpData=0;
  tmpData=new RooDataSet(TString("Weight_")+fWeightName+fData->GetName(),fData->GetTitle(),(RooDataSet*)fData,*fData->get(),0,fWeightName);
  fData->SetName("Empty");fData->reset();fData=0;
  fData=tmpData;
  fData->Print();
  if(ftoWS) fWS->import(*fData); //import if told to
  else if(!(fDataBins))fWS->import(*fData); //or no databins to confuse it 
}
void HSRooFit::SetWeightName(TString WName){
  if(!fInWeights) {Warning("HSRooFit::SetWeightName","Need to SetInweights first");return;}
  if(fInWeights->GetSpeciesID(WName)<0) {Warning("HSRooFit::SetWeightName","Weight %s does not exist in InWeights",WName.Data());return;}
  fWeightName=WName;
}
void HSRooFit::LoadVariable(TString opt){
 RooAbsArg* var=(RooAbsArg*) fWS->factory(opt);
 fVariables.add(*var);
 RooRealVar* varreal=nullptr;
 RooCategory* varcat=nullptr;
  if((varreal=dynamic_cast<RooRealVar*>(var))){
   if(fCut.Sizeof()>1)fCut+="&&";
   fCut+=Form("%s>=%lf&&%s<=%lf",varreal->GetName(),varreal->getMin(),varreal->GetName(),varreal->getMax());
 }
 // else if((varcat=dynamic_cast<RooCategory*>(var))){
 //   if(fCut.Sizeof()>1)fCut+="&&";
 //   fCut+=Form("%s>=%lf&&%s<=%lf",varcat->GetName(),varcat->getMin(),varcat->GetName(),varcat->getMax());
 // }
 return;
}
// void HSRooFit::LoadCategory(TString opt){
//   fVariables.add(*(fWS->factory(opt)));
// }

/////////////////////////////////////////////////////////
///HSRooFit::LoadAuxVars can bes used to cut input trees and keeping
///variable bracnhes in binned or reduced trees
///the limits of the varibale are added to Cut and applied to data import
void HSRooFit::LoadAuxVars(TString opt){
  RooAbsArg* var=(RooAbsArg*) fWS->factory(opt);
  fAuxVars.add(*(var));
  //  fAuxVars.add(*(fWS->factory(opt)));
  RooRealVar* varreal=nullptr;
  RooCategory* varcat=nullptr;
  if((varreal=dynamic_cast<RooRealVar*>(var))){
    if(fCut.Sizeof()>1)fCut+="&&";
    fCut+=Form("%s>=%lf&&%s<=%lf",varreal->GetName(),varreal->getMin(),varreal->GetName(),varreal->getMax());   
  }
  // else if((varcat=dynamic_cast<RooCategory*>(var))){
  //   if(fCut.Sizeof()>1)fCut+="&&";
  //   fCut+=Form("%s>=%lf&&%s<=%lf",varcat->GetName(),varcat->getMin(),varcat->GetName(),varcat->getMax());
  // }
  return;
}
void HSRooFit::LoadBinVars(TString opt,Int_t nbins,Double_t min,Double_t max){
  if(!fDataBins) fDataBins=new Bins("HSDataBins");
  //Load a variable that is to be used to define the kinmatic bins
  //opt must be the name of a variable in the tree
  // LoadAuxVars(opt+Form("[%lf,%lf]",min,max));//dummy range, needed for factory to create var
  fBinVars.add(*(fWS->factory(opt+Form("[%lf,%lf]",min,max))));
  fDataBins->AddAxis(opt,nbins,min,max);

}
void HSRooFit::LoadBinVars(TString opt,Int_t nbins,Double_t* xbins){
  if(!fDataBins) fDataBins=new Bins("HSDataBins");
  //Load a variable that is to be used to define the kinmatic bins
  //opt must be the name of a variable in the tree
  fBinVars.add(*(fWS->factory(opt+Form("[%lf,%lf]",xbins[0],xbins[nbins]))));
  fDataBins->AddAxis(opt,nbins,xbins);

}
void HSRooFit::CheckRange(){
  //check over fit variables to find max and min values in datastore
  //change range accordingly. Seems to help weighted fits
  for(Int_t iy=0;iy<fVariables.getSize();iy++){
    Double_t high,low;
    RooRealVar *var=((RooRealVar*)&fVariables[iy]);
    fData->getRange(*var,low,high);
    if(low>var->getMin()){
      Info("HSRooFit::CheckRange()","changing min for %s from %f to %f",var->GetName(),var->getMin(),low);
      var->setMin(low);
    }
    if(high<var->getMax()){
      Info("HSRooFit::CheckRange()","changing min for %s from %f to %f",var->GetName(),var->getMax(),high);
      var->setMax(high);
    }
    
  }
}
RooRealVar* HSRooFit::GetVar(TString name){
  RooRealVar* var=0;
  if(var==GetVariable(name)) return var;
  else if(var==GetAuxVar(name)) return var;
  else cout<<"HSRooFit::GetVar no variable with name "<<name<<endl;
  return nullptr;
}
void HSRooFit::LoadSpeciesPDF(TString opt,Int_t Scale0){
  //Scale gives relative starting value to other species
  //Get PDF from workspace and add to PDF list
  fPDFs.add(*((RooGenericPdf*)fWS->pdf(opt)));//RooGeneric is just a dummy, add does not take RooAbsPdf
  //fPDFs.find(opt);
  fParameters.add(*(fPDFs.find(opt)->getParameters(RooArgSet(fVariables,fAuxVars))));// get parameters not in fVariables 
  //Add a yield parameter for this species
  fYields.add(*(fWS->factory(fYld+opt+Form("[%d,0,1E12]",Scale0))));//default yields limits
}
void HSRooFit::TotalPDF(){
  cout<<"HSRooFit::TotalPDF() "<<fWS<<" "<<fModel<<endl;
  if(fModel)fModel->Print();
  //Construct a total PDF whcih is the sum of the species PDFs
  RooAddPdf model(fName+"TotalPDF","total model",
		  fPDFs, 
		  fYields);
  model.Print();
  Int_t Nm=0;
  //can't delete from workspace!
  while(fWS->pdf(TString(fName)+Form("TotalPDF%d",Nm++)));
  model.SetName(TString(fName)+Form("TotalPDF%d",Nm-1));
  cout<<"HSRooFit::TotalPDF() "<<model.GetName()<<endl;
  // fWS->Print();
  // fWS->import(model); //and replace any existing model, memory leak?
  fWS->import(model,RooFit::RecycleConflictNodes()); //and replace any existing model, memory leak?
  fModel=fWS->pdf(model.GetName());
  fModel->Print();
  AddFitOption(RooFit::Extended());
  fWS->Print();
}
void HSRooFit::Fit(Bool_t randPar){   
  Info("HSRooFit::Fit()"," Starting");
  if(!fData){
    Error("HSRooFit::Fit"," no dataset loaded");
    return;
  }
  if(fModel)fModel->Print();
  if(randPar) RandomisePars();
  if (fResult) {delete fResult;fResult=0;}
  //Initialise yield fit parameters
  for(Int_t iy=0;iy<fYields.getSize();iy++){//set yields below entries in dataset
    if(fData->sumEntries()<=1){
      cout<<"void HSRooFit::Fit SUMENTRIES "<<fData->sumEntries()<<endl;;
      fWS->var(fYields[iy].GetName())->setRange(0,fData->numEntries()); 
      // fWS->var(fYields[iy].GetName())->setVal(1E3/2/fWS->var(fYields[iy].GetName())->getVal());//scale by value give in LoadSpecies 
      fWS->var(fYields[iy].GetName())->setVal(fData->numEntries()/2);//scale by value give in LoadSpecies 

    }
    //if(fFiti==0){
      fWS->var(fYields[iy].GetName())->setRange(0,fData->sumEntries()*2); 
      //fWS->var(fYields[iy].GetName())->setVal(fData->sumEntries()/2/fWS->var(fYields[iy].GetName())->getVal());//scale by value give in LoadSpecies
      fWS->var(fYields[iy].GetName())->setVal(fData->sumEntries()/2);//scale by value give in LoadSpecies
      //}
  }
  if(fFiti==0){
    DefaultFitOptions();
    //Add any constraints to the likelihood
    fConstraints.Print();
    if(fConstraints.getSize()) AddFitOption(RooFit::ExternalConstraints(fConstraints));
  }
    fFitOptions.Print("");
  if(fBinnedFit){
    if(fConstraints.getSize())cout<<"Warning : HSRooFit::Fit Constraints defined for binned fit, this is will not work in RooFit has to be ML fit"<<endl;  
    RooRealVar *var=((RooRealVar*)&fVariables[0]);//assume fitting first variable
    Double_t hmin;
    Double_t hmax;
    fData->getRange(*var,hmin,hmax);
    // var->setRange("R1",hmin,hmax);
    //TH1D* hist=(TH1D*)fData->fillHistogram(new TH1D("binned","binned",var->getBins(),var->getMin(""),var->getMax("")),RooArgList(*var));
    TH1D* hist=(TH1D*)fData->fillHistogram(new TH1D("binned","binned",var->getBins(),hmin,hmax),RooArgList(*var));
    if(hist->GetMinimum()<10) hist->Rebin();
    Bool_t ForceMLL=kFALSE;
    if(hist->GetMinimum()<5){cout<<"HSRooFit::Fit binned fit requested but some bins have few entries, switching to likelihood "<<endl;ForceMLL=kTRUE;}
    hist->Sumw2();
    RooDataHist rdh(Form("chi2hist%d",fFiti),Form("chi2hist%d",fFiti),RooArgList(*var),RooFit::Import(*hist));
    cout<<"MAX MIN VALUES "<<hmin<<" "<<hmax<<endl;
    RooCmdArg dataerr=RooFit::DataError(RooAbsData::SumW2);
    fFitOptions.Print("");
    if(!fFitOptions.FindObject(&dataerr)) fFitOptions.Add(&dataerr);

    if(!ForceMLL)fResult=fModel->chi2FitTo(rdh,fFitOptions);
    else fResult=fModel->fitTo(rdh,fFitOptions);
    
    fFitOptions.Remove(&dataerr);
    delete hist;
    
  }
  else{
    if(fFitMethod==0)
      fResult=FitMinuit1();
    else if(fFitMethod==1)
      fResult=FitMinuit2();
    else if(fFitMethod==2)
      fResult=FitMCMC();


    else Warning("HSRooFit::Fit","Fit method not defined");
  }
  //    fResult=fModel->fitTo(*fData,fFitOptions);
  fNllval.setVal(fResult->minNll());
  fFiti++;
 //plot result
  if(fIsPlot)PlotDataModel();

}
///////////////////////////////////////////////////////////////
///Fit with standard HSMCMC class
RooFitResult *HSRooFit::FitMCMC(){
  if(!fModel) TotalPDF();
  RooStats:: SequentialProposal sp(0.5);
  if(fMCMC) delete fMCMC;
  fMCMC=new HSMCMC(*GetData(), *GetModelConfig());
  fMCMC->SetNumBurnInSteps(fBurnMCMC);
  fMCMC->SetNumIters(fNMCMC);
  fMCMC->SetProposalFunction(sp);
  //make the markov chain
  fMCMC->MakeChain();
  fNllval.setVal(fMCMC->NLL());
  return fMCMC->Save();
}
///////////////////////////////////////////////////////////////
///Fit with standard RooFit
RooFitResult *HSRooFit::FitMinuit1(){
  return fModel->fitTo(*fData,fFitOptions);
}
///////////////////////////////////////////////////////////////
///Fit with weights by multiplying by alpha=SumW/SumW^2
///More or less a copy of RooFitResult* RooAbsPdf::fitTo(RooAbsData& data, const RooLinkedList& cmdList) 

RooFitResult *HSRooFit::FitMinuit2(){
    // Select the pdf-specific commands 
  RooCmdConfig pc(Form("RooAbsPdf::fitTo(%s)",GetName())) ;

  RooLinkedList fitCmdList(fFitOptions) ;
  RooLinkedList nllCmdList = pc.filterCmdList(fitCmdList,"ProjectedObservables,Extended,Range,RangeWithName,SumCoefRange,NumCPU,SplitRange,Constrained,Constrain,ExternalConstraints,CloneData,GlobalObservables,GlobalObservablesTag,OffsetLikelihood") ;

  pc.defineString("fitOpt","FitOptions",0,"") ;
  pc.defineInt("optConst","Optimize",0,2) ;
  pc.defineInt("verbose","Verbose",0,0) ;
  pc.defineInt("doSave","Save",0,0) ;
  pc.defineInt("doTimer","Timer",0,0) ;
  pc.defineInt("plevel","PrintLevel",0,1) ;
  pc.defineInt("strat","Strategy",0,1) ;
  pc.defineInt("initHesse","InitialHesse",0,0) ;
  pc.defineInt("hesse","Hesse",0,1) ;
  pc.defineInt("minos","Minos",0,0) ;
  pc.defineInt("ext","Extended",0,2) ;
  pc.defineInt("numcpu","NumCPU",0,1) ;
  pc.defineInt("numee","PrintEvalErrors",0,10) ;
  pc.defineInt("doEEWall","EvalErrorWall",0,1) ;
  pc.defineInt("doWarn","Warnings",0,1) ;
  pc.defineInt("doSumW2","SumW2Error",0,-1) ;
  pc.defineInt("doOffset","OffsetLikelihood",0,0) ;
  pc.defineString("mintype","Minimizer",0,"Minuit") ;
  pc.defineString("minalg","Minimizer",1,"minuit") ;
  pc.defineObject("minosSet","Minos",0,0) ;
  pc.defineSet("cPars","Constrain",0,0) ;
  pc.defineSet("extCons","ExternalConstraints",0,0) ;
  pc.defineMutex("FitOptions","Verbose") ;
  pc.defineMutex("FitOptions","Save") ;
  pc.defineMutex("FitOptions","Timer") ;
  pc.defineMutex("FitOptions","Strategy") ;
  pc.defineMutex("FitOptions","InitialHesse") ;
  pc.defineMutex("FitOptions","Hesse") ;
  pc.defineMutex("FitOptions","Minos") ;
  pc.defineMutex("Range","RangeWithName") ;
  pc.defineMutex("InitialHesse","Minimizer") ;
  
  // Process and check varargs 
  pc.process(fitCmdList) ;
  if (!pc.ok(kTRUE)) {
    return 0 ;
  }

  // Decode command line arguments
  const char* fitOpt = pc.getString("fitOpt",0,kTRUE) ;
  Int_t optConst = pc.getInt("optConst") ;
  Int_t verbose  = pc.getInt("verbose") ;
  Int_t doSave   = pc.getInt("doSave") ;
  Int_t doTimer  = pc.getInt("doTimer") ;
  Int_t plevel    = pc.getInt("plevel") ;
  Int_t strat    = pc.getInt("strat") ;
  Int_t initHesse= pc.getInt("initHesse") ;
  Int_t hesse    = pc.getInt("hesse") ;
  Int_t minos    = pc.getInt("minos") ;
  Int_t numee    = pc.getInt("numee") ;
  Int_t doEEWall = pc.getInt("doEEWall") ;
  Int_t doWarn   = pc.getInt("doWarn") ;
  Int_t doSumW2  = pc.getInt("doSumW2") ;
  const RooArgSet* minosSet = static_cast<RooArgSet*>(pc.getObject("minosSet")) ;
#ifdef __ROOFIT_NOROOMINIMIZER
  const char* minType =0 ;
#else
  const char* minType = pc.getString("mintype","Minuit") ;
  const char* minAlg = pc.getString("minalg","minuit") ;
#endif

  // Determine if the dataset has weights  
  Bool_t weightedData = fData->isNonPoissonWeighted() ;
  if(fNll) {delete fNll;fNll=nullptr;}
  //if(fResult) {delete fResult;fResult=nullptr;}
  fNll=fModel->createNLL(*fData,nllCmdList) ;
  RooFitResult *ret = 0 ;    

  //add in sumw/sumw2 term
  if(fData->isNonPoissonWeighted()){
    Double_t SumW=SumWeights();
    Double_t SumW2=SumWeights2();
    RooFormulaVar *alphanll=new RooFormulaVar("alphanll",Form("%lf*%s",SumW/SumW2,fNll->GetName()),RooArgSet(*fNll));
    fNll=alphanll;
  }
  
  //Use Minuit minimiser
  RooMinuit m(*fNll) ;
  
  m.setEvalErrorWall(doEEWall) ;
  if (doWarn==0) {
    m.setNoWarn() ;
  }
  
  m.setPrintEvalErrors(numee) ;
  if (plevel!=1) {
    m.setPrintLevel(plevel) ;
  }
  
  if (optConst) {
    // Activate constant term optimization
    m.optimizeConst(optConst) ;
  }
  
  if (fitOpt) {
    
    // Play fit options as historically defined
    ret = m.fit(fitOpt) ;
    
  } else {
    
    if (verbose) {
      // Activate verbose options
	m.setVerbose(1) ;
    }
    if (doTimer) {
      // Activate timer options
      m.setProfile(1) ;
    }
    
    if (strat!=1) {
      // Modify fit strategy
      m.setStrategy(strat) ;
    }
    
    ////////////////////////////////////////////////////
    //Now standard minimisation algorithm
    if (initHesse) {	
      // Initialize errors with hesse
      m.hesse() ;
      }
    
    // Minimize using migrad
    m.migrad() ;
    
    if (hesse) {
      // Evaluate errors with Hesse
      m.hesse() ;
    }
    
    if (minos) {
      // Evaluate errs with Minos
      if (minosSet) {
	  m.minos(*minosSet) ;
      } else {
	m.minos() ;
      }
      
    
    
    }	

    // Optionally return fit result
    if (doSave) {
      string name = Form("fitresult_%s_%s",fModel->GetName(),fData->GetName()) ;
      string title = Form("Result of fit of p.d.f. %s to dataset %s",fModel->GetName(),fData->GetName()) ;
      ret = m.save(name.c_str(),title.c_str()) ;
    } 
    
  }
  
  if (optConst) {
    m.optimizeConst(0) ;
  }
  return ret ;

}

void HSRooFit::RandomisePars(){
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
  }
}

void HSRooFit::PlotModel(TString varName,TString pdfName){
  if(!fWS->pdf(pdfName)){
    cout<<"HSRooFit::PlotModel given pdf does not exist in workspace"<<pdfName<<endl;
    fWS->Print();
  }
  TCanvas *canvas=0;
  if(!fCanvases){fCanvases=new TList();fCanvases->SetOwner();}
  RooRealVar* var=fWS->var(varName);//get variable
  fCanvases->Add(canvas=new TCanvas(TString(GetTitle())+varName+pdfName,TString(GetTitle())+varName+pdfName));//create new canvas for drawing on
  RooPlot* frame = var->frame(); // RooFit frame
  fWS->pdf(pdfName)->plotOn(frame,LineStyle(kSolid), LineColor(kRed));
  frame->SetTitle(pdfName+TString(" versus ")+varName);
  frame->Draw();
  canvas->Modified();
  canvas->Update();

}
void HSRooFit::PlotDataModel(){
  //Function to plot the data and fitted model for each variable
  
  TCanvas *canvas0=0;
  TCanvas *canvas1=0;
  if(!fCanvases){fCanvases=new TList();fCanvases->SetOwner();fCanvases->SetName(TString("RFPlots")+GetTitle());}
  //make sure chi2 created
  if(fChi2s.getSize()==0){
    for(Int_t idr=0;idr<fVariables.getSize();idr++){
      RooRealVar* var=dynamic_cast<RooRealVar*>(fWS->var(fVariables[idr].GetName()));//get variable
      if(!var) continue;
      RooRealVar* chi2var=new RooRealVar(TString("Chi2")+var->GetName(),TString("Chi2")+var->GetName(),0);
      fChi2s.add(*chi2var);
    }
  }
  //Loop over variables
  for(Int_t idr=0;idr<fVariables.getSize();idr++){
    RooRealVar* var=dynamic_cast<RooRealVar*>(fWS->var(fVariables[idr].GetName()));//get variable
    if(!var) continue;
    cout<< fChi2s.getSize()<<" "<<fChi2s.at(idr)<<" "<<var<<endl;
    fChi2s.at(idr)->GetName();
    RooRealVar* chi2=dynamic_cast<RooRealVar*>(fChi2s.at(idr));//get variable
    
    cout<<"Plotting "<<fVariables[idr].GetName()<<endl;
    fCanvases->Add(canvas0=new TCanvas(TString(GetTitle())+fVariables[idr].GetName()+Form("%d",fFiti),TString(GetTitle())+fVariables[idr].GetName()));//create new canvas for drawing on
    RooPlot* frame = var->frame(); // RooFit frame 
    fData->plotOn(frame, DataError(RooAbsData::SumW2) ) ; //plot the data
    fModel->plotOn(frame,LineColor(kRed),Precision(4E-2)) ; //model = signal + back fit result 
    //    fModel->plotOn(frame,LineColor(kRed),Precision(1E-2)) ; //model = signal + back fit result 
    //Get the chi2
    fChi2=frame->chiSquare();
    if(TMath::IsNaN(fChi2)) fChi2=-1;
    chi2->setVal(fChi2);
    cout<<fFiti<<" HSRooFit::PlotDataModel() chi2 = "<<fChi2<<endl;
    fModel->paramOn(frame,
		    Layout(0.1, 0.4, 0.9),
		    Format("NEU",AutoPrecision(2)),
		    ShowConstants()); //show fit parameters
    frame->SetTitle(TString("Fit components for ")+fVariables[idr].GetName());


    //Pull distributions
    // fCanvases->Add(canvas1=new TCanvas(TString("Pull_")+TString(GetTitle())+fVariables[idr].GetName()+Form("%d",fFiti),TString(GetTitle())+fVariables[idr].GetName()));
    // RooHist* hpull=frame->pullHist();
    // hpull->Draw();
    // canvas1->Modified();
    // canvas1->Update();

    // //Residual distributions
    // fCanvases->Add(canvas1=new TCanvas(TString("Residual_")+TString(GetTitle())+fVariables[idr].GetName()+Form("%d",fFiti),TString(GetTitle())+fVariables[idr].GetName()));
    // RooHist* hres=frame->residHist();
    // hres->Draw();
    // canvas1->Modified();
    // canvas1->Update();

    canvas0->cd();
    //Now Loop over components (do after pulls so they are calculated with total)
    for(Int_t ic=0;ic<fPDFs.getSize();ic++)
      fModel->plotOn(frame,Components(fPDFs[ic]),LineStyle(kDashed),LineColor(ic%8+1),Precision(1E-2)) ; //just the back fit result  
    frame->Draw() ;
    canvas0->Modified();
    canvas0->Update();


  }
}

HSRooFit*  HSRooFit::CreateSubFitBins(TTree* ctree,TString rfname,Bool_t CopyTree){//events already selected
  //create a fit object for a subset of data either by setting cut
  //or by fTree->SetEntryList prior to calling this function 
  //It will be deleted by this object
  // cout<<"HSRooFit::CreateSubFitBins with tree "<<ctree->GetName()<<endl;
  HSRooFit* RFa=new HSRooFit(rfname);
  if(fBinnedFit)RFa->SetBinnedFit();
  RFa->SetSingleSpecies(fSingleSp);
  RFa->SetBinDir(fBinDir);
  RFa->SetOutDir(fOutDir);
  RFa->SetInWeights(fInWeights);
  RFa->SetWeightName(fWeightName);
  //  RFa->SetNStudyTrials(fNStudyTrials);
  //RFa->SetStudyPDF(fStudyPDF);
  //RFa->SetStudyPlot(fStudyPlot);
  RFa->SetCut(fCut);
  RFa->SetFitMethod(fFitMethod);
  RFa->SetNMCMC(fNMCMC);
  //Done configuring RF
  fRooFits->Add(RFa);
  RFa->LoadWorkSpace(fWS,GetName());
  // RFa->SetIDBranchName(fIDBranchName);
  for(Int_t ill=0;ill<fFitOptions.GetSize();ill++)
    RFa->AddFitOption(*((RooCmdArg*)fFitOptions.At(ill)));
  if(!ctree) return RFa; 
  //Load the data tree if given
  TDirectory *saveDir=gDirectory;
  if(CopyTree)RFa->LoadDataSet(ctree->CopyTree(fCut));//will use any EntryList
  else if(fCut.Sizeof()>1)RFa->LoadDataSet(ctree->CopyTree(fCut));
  else RFa->LoadDataSet(ctree);//use whole tree
   saveDir->cd();
  RFa->SetDataWeight();//if defined weights use them for this dataset
  return RFa;
}
void HSRooFit::SavePlots(TString filename){
  TFile* file=0;
  cout<<"HSRooFit::SavePlots "<<TString(fOutDir+TString("Results")+GetTitle()+".root")<<" "<<fCanvases<<" "<<fResult<<endl;
			  
  file=new TFile(fOutDir+TString("Results")+GetTitle()+".root","recreate");
  if(fCanvases) fCanvases->Write();
  if(fResult) fResult->Write("HSFitResult");
  if(fMCMC) fMCMC->GetTree()->Write();

  //save paramters and chi2s in  dataset (for easy merging)
  RooArgSet saveArgs(fParameters,fChi2s);
  saveArgs.add(fNllval);
  RooDataSet saveDS("HSResults","HSResults",saveArgs);
  saveDS.add(saveArgs);
  saveDS.Write();
  TTree* treeDS=RooStats::GetAsTTree("ResultsTree","ResultsTree",saveDS);
   treeDS->Write();
  file->Close();
  delete file;
  
}

void HSRooFit::MakeBinnedTrees(TTree* tree,TString name){
  //turn off all branches we do not require to save space and memory
  tree->SetBranchStatus("*",0);
  for(Int_t i=0;i<fVariables.getSize();i++){//only copy variable branches for speed
    tree->SetBranchStatus(fVariables[i].GetName(),1);
  }
  for(Int_t i=0;i<fAuxVars.getSize();i++){//only copy variable branches for speed
    tree->SetBranchStatus(fAuxVars[i].GetName(),1);
  }
  //but always need ID branch
  if(tree->GetBranch(fIDBranchName)){
    tree->SetBranchStatus(fIDBranchName,1);
  }
  //now split the tree into bins and save in subdirs of fOutDir
  fDataBins->SetOutDir(fOutDir);
  fDataBins->SetDataName(name);
  fDataBins->RunBinTree(tree);
  fDataBins->Save(fOutDir+name+"Entries.root");
 
}

void HSRooFit::ConfigureSavedBins(TString dirname,TString pdfname){
  //Note pdfname is Data by default, only set if just studying simulated data
  fBinDir=dirname;
  fDataBins=new Bins("HSDataBins",fBinDir+pdfname+"Entries.root");
  if(!fDataBins->GetN()) {Error("HSRooFit::ConfigureSavedBins()","No bins found in directory = %s",fBinDir.Data());return;}
  return;
}

void HSRooFit::FitSavedBins(Int_t Nfits,Bool_t cleanup){
  if(!fDataBins->GetN()) return;
  Info("HSRooFit::FitSaved","Goint to run %d fits from %s",Nfits,fBinDir.Data());
  if(!fWS->set(TString(GetName())+"PDFs"))DefineSets();
  TDirectory *saveDir=gDirectory;
  //Loop over bins
  for(Int_t ib=0;ib<GetBins()->GetN();ib++){
    TChain *chainData=new TChain("BinnedTree");
    chainData->Add(GetBinDir()+GetBins()->GetBinName(ib)+TString("/Tree")+"Data"+".root");
    cout<<"Data chain "<<GetBinDir()+GetBins()->GetBinName(ib)+TString("/Tree")+"Data"+".root"<<" "<<chainData->GetEntries()<<" "<<chainData->GetName()<<endl;
     
    HSRooFit* rf=CreateSubFitBins(chainData,GetBins()->GetBinName(ib),kFALSE);
     //look for RooHSEventsPDFs to get MC events trees
    for(Int_t ip=0;ip<fPDFs.getSize();ip++){
      RooAbsPdf* pdf=rf->GetWorkSpace()->pdf(fPDFs[ip].GetName());
      RooHSEventsPDF* hspdf=0;
      if((hspdf=dynamic_cast<RooHSEventsPDF*>(pdf))){    
	Info("HSRooFit::FitSaved","Found RooHsAbsEventsPDF %s",hspdf->GetName());
	cout<<"MC CHAIN "<<fPDFs[ip].GetName()<<endl;
	TChain *chainMC=new TChain("BinnedTree");
	//pdf has ownership of chain when set
	chainMC->Add(GetBinDir()+GetBins()->GetBinName(ib)+TString("/Tree")+hspdf->GetName()+".root");
	if(!chainMC->GetEntries()||!hspdf->IsValid()){
	  RemovePDF(ip);
	  ip--;
	}
	else{
	  hspdf->SetEvTree(chainMC,fCut);
	  hspdf->AddProtoData(rf->GetDataSet());
	  RooHSEventsHistPDF* histspdf=0;
	  if((histspdf=dynamic_cast<RooHSEventsHistPDF*>(pdf)))
	    histspdf->CreateHistPdf();
	}
	delete chainMC;
      }
    } 
    //Configured the fir for this bin now do it
    if(fModel)rf->TotalPDF();//total PDF defined in parent so also for child
    rf->RunAFit(Nfits);
    rf->GetWorkSpace()->saveSnapshot(TString("FinalResults")+rf->GetName(),RooArgSet(fYields,fParameters),kTRUE);//make a copy of final results, this allows you to load the results if you want to loop over fFits later
    if(cleanup){
      delete rf;rf=nullptr;
      delete chainData;chainData=nullptr;
    }
    //delete binDFile;
  }
}
// void HSRooFit::StudySavedBins(Int_t Nfits,Bool_t cleanup){
//   if(!fDataBins->GetN()) return;
//   Info("HSRooFit::StudySavedBins","Going to run %d fits from %s",Nfits,fBinDir.Data());
//   if(!fWS->set(TString(GetName())+"PDFs"))DefineSets();
//   TDirectory *saveDir=gDirectory;
//   //Loop over bins
//   for(Int_t ib=0;ib<GetBins()->GetN();ib++){
//     HSRooFit* rf=CreateSubFitBins(nullptr,GetBins()->GetBinName(ib),kFALSE);
//      //look for RooHSEventsPDFs to get MC events trees
//     for(Int_t ip=0;ip<fPDFs.getSize();ip++){
//       RooAbsPdf* pdf=rf->GetWorkSpace()->pdf(fPDFs[ip].GetName());
//       RooHSEventsPDF* hspdf=0;
//       if((hspdf=dynamic_cast<RooHSEventsPDF*>(pdf))){    
// 	Info("HSRooFit::FitSaved","Found RooHsAbsEventsPDF %s",hspdf->GetName());
// 	hspdf->ResetTree();
// 	cout<<"MC CHAIN "<<fPDFs[ip].GetName()<<endl;
// 	TChain *chainMC=new TChain("BinnedTree");
// 	//pdf has ownership of chain when set
// 	chainMC->Add(GetBinDir()+GetBins()->GetBinName(ib)+TString("/Tree")+hspdf->GetName()+".root");
// 	//	if(!hspdf->SetEvTree(chainMC)) {Error("HSRooFit::FitSavedBins","problem with chain for %s",hspdf->GetName());exit(0);}

// 	hspdf->SetEvTree(chainMC,fCut);
// 	//	hspdf->AddProtoData(rf->GetDataSet());
// 	delete chainMC;
//       }
//     } 
//     //Configured the fir for this bin now do it
//     if(fModel)rf->TotalPDF();//total PDF defined in parent so also for child
//     //rf->StudyFit();
//     if(cleanup){
//       delete rf;rf=nullptr;
//     }
//   }
  
// }
void HSRooFit::FitBatchBin(Int_t Nfits, TString DataFileName){
  
  Info("HSRooFit::FitBatchBin","Goint to run fit from %s",fBinDir.Data());
  if(!fWS->set(TString(GetName())+"PDFs"))DefineSets();
  TDirectory *saveDir=gDirectory;

  TChain *chainData=new TChain("BinnedTree");
  chainData->Add(GetBinDir()+TString("/Tree")+DataFileName+".root");
  cout<<"Data chain "<<GetBinDir()+TString("/Tree")+DataFileName+".root"<<" "<<chainData->GetEntries()<<" "<<chainData->GetName()<<endl;

  if(!chainData->GetEntries()){
	delete chainData;
	return;
  }
  LoadDataSet(chainData);
  //look for RooHSEventsPDFs to get MC events trees
  for(Int_t ip=0;ip<fPDFs.getSize();ip++){
    RooAbsPdf* pdf=fWS->pdf(fPDFs[ip].GetName());
    RooHSEventsPDF* hspdf=0;
    if((hspdf=dynamic_cast<RooHSEventsPDF*>(pdf))){    
      Info("HSRooFit::FitSaved","Found RooHsAbsEventsPDF %s",hspdf->GetName());
      cout<<"MC CHAIN "<<fPDFs[ip].GetName()<<endl;
      TChain *chainMC=new TChain("BinnedTree");
      //pdf has ownership of chain when set
      chainMC->Add(GetBinDir()+TString("/Tree")+hspdf->GetName()+".root");
      if(!chainMC->GetEntries()||!hspdf->IsValid()){
	RemovePDF(ip);
	ip--;
      }
      else{
	hspdf->SetEvTree(chainMC,fCut);
	hspdf->AddProtoData(GetDataSet());
	RooHSEventsHistPDF* histspdf=0;
	if((histspdf=dynamic_cast<RooHSEventsHistPDF*>(pdf)))
	  histspdf->CreateHistPdf();
     }
      delete chainMC;    
    }
  }
  SetDataWeight();//if defined weights use them for this dataset
  //CheckRange();
  RunAFit(Nfits);
  delete chainData;
  
}
void HSRooFit::RemovePDF(Int_t iPDF){
    RooRealVar* yield0=(RooRealVar*)&fYields[iPDF];
    GetPDFsp()->remove(GetPDFs()[iPDF]);
    GetYieldsp()->remove(*(GetWorkSpace()->var(yield0->GetName())));
    GetWorkSpace()->removeSet("Yields");
    GetWorkSpace()->removeSet("PDFs");
    GetWorkSpace()->defineSet("Yields",GetYields());
    GetWorkSpace()->defineSet("PDFs",GetPDFs());	
}
void HSRooFit::RunAFit(Int_t Nfits){
   //Create new fit and load the new bin data tree
  if(!fWS->set(TString(GetName())+"PDFs"))DefineSets();
  if(fFitMethod==2) Fit();
  else FitMany(Nfits);

  if(fData&&Nfits)
    if(fData->isNonPoissonWeighted()){
      //Need to calculate correction to covariance matrix
      //Only do it at the end so FitMany can check real covariance
      //matrix to make sure its status is OK
      //if SumW2Error(kTRUE) is set the the covQual is not useful
      //just says set extrnally
      if(!(GetFitOptions().find("SumW2Error")))
	AddFitOption(RooFit::SumW2Error(kTRUE));
      Fit();
    }
  Info("HSRooFit::RunAFit","Save to %s",(fOutDir+TString("Results")+GetTitle()).Data());
  SavePlots(fOutDir+TString("Results")+GetTitle()+".root");
  
}
void HSRooFit::FitSplitIntegral(Int_t Nfits){
  //Create new fit and load the new bin data tree
  if(!fWS->set(TString(GetName())+"PDFs"))DefineSets();
  fWS->saveSnapshot(Form("StartRangeFit"),RooArgSet(fYields,fParameters),kTRUE);
  TString title=GetTitle();
  //Loop over integration event ranges in RooHSEventsPDF   
  for(Int_t isplits=0;isplits<fNIntRanges;isplits++){
    fWS->loadSnapshot(Form("StartRangeFit"));

    for(UInt_t ip=0;ip<fHSPDF_Ranges.size();ip++){
      fHSPDF_Ranges[ip]->SetNRanges(fNIntRanges);
      fHSPDF_Ranges[ip]->SetNextRange(isplits);
    }

    if(fFitMethod==2) Fit();
    else FitMany(Nfits);

    if(fData&&Nfits&&fFitMethod==0)
      if(fData->isNonPoissonWeighted()){
	//Need to calculate correction to covariance matrix
	//Only do it at the end so FitMany can check real covariance
	//matrix to make sure its status is OK
	//if SumW2Error(kTRUE) is set the the covQual is not useful
	//just says set extrnally
	if(!(GetFitOptions().find("SumW2Error")))
	  AddFitOption(RooFit::SumW2Error(kTRUE));
	Fit();
      }

    SetTitle(title+Form("_Range_%d",isplits));
    Info("HSRooFit::FitSplitIntegral;","Save to %s",(fOutDir+TString("Results")+GetTitle()).Data());
    SavePlots("");	
  } 
}
// void HSRooFit::StudyFit(){
//   if(!fNStudyTrials) return;
//   if(!fWS->set(TString(GetName())+"PDFs"))DefineSets();

//   Info("HSRooFit::StudyFit()","will attempt %d trials on %s",fNStudyTrials,fStudyPDF.Data());
//   RooHS1StepStudy this_study(GetName(),"testing the fit systematics");
//   this_study.attach(*fWS);
//   this_study.SetOutDir(GetOutDir());
//   this_study.SetPDFName(fStudyPDF);
//   this_study.SetPlot(fStudyPlot);
//   if(fNStudyTrials<0) this_study.UseAll(); //Use all events in tree rather than yield parameter
//   if(fBinnedFit)this_study.GetRooFit()->SetBinnedFit();
//   for(Int_t ill=0;ill<fFitOptions.GetSize();ill++)
//     this_study.GetRooFit()->AddFitOption(*((RooCmdArg*)fFitOptions.At(ill)));
//   RooStudyManager mgr(*fWS,this_study);
//   mgr.run(TMath::Abs(fNStudyTrials)) ;
// }
///////////////////////////////////////////////////////////////
///Attempt many fit swith randomly selected parameters
///Take the fit result with the best likelihood
///If using weighted data Sumw2Errors should not be included as an option
///for these fits or the covariance matrix cannot be used to assess the fit
//instead you must do another fit after this, with the option set
void HSRooFit::FitMany(Int_t Nfits){
  if(Nfits==0) return;
  //Do the fit many times with different initial paramters
  //Maybe new fit so construct PDF if not laready loaded
  if(!fWS->set(TString(GetName())+"PDFs"))DefineSets();
    // if(!fModel)TotalPDF();
 
  //Store the likelihood value
  TVectorD loglh(Nfits);
  //Fit the model to data with all paramters free
  //first fit use initial paramter values
  if(!fModel) fModel=(RooAbsPdf*)&(fPDFs[0]);//Not ideal, will just take the fist PDF loaded by LoadSpecies unless TotalPDF has already been called.
  Fit();
  Bool_t nan=TMath::IsNaN(fResult->minNll());
  Bool_t edm=(fResult->covQual()>1)||(fResult->covQual()==-1);
  Bool_t fail=(fResult->minNll()!=-1e+30);

  if(fBinnedFit&&!TMath::IsNaN(fChi2)) loglh[0]=fChi2; //actually did chi2 fit
  else if((!nan)&&edm&&fail) loglh[0]=fResult->minNll();
  else loglh[0]=1E300;
  //((TCanvas*)fCanvases->Last())->SetTitle(Form("Fit %d LogL = %lf",0,fChi2));
  fWS->saveSnapshot(Form("ssFit%d",0),RooArgSet(fYields,fParameters),kTRUE);

  //<Ae and aray of fit results
  TObjArray* fitResults=new TObjArray(Nfits);
  fitResults->SetOwner(kTRUE);
  fitResults->AddLast((RooFitResult*)fResult->clone());

  //loop over number of fits
  for(Int_t ifit=1;ifit<Nfits;ifit++){
    Fit(kTRUE);
    fWS->saveSnapshot(Form("ssFit%d",ifit),RooArgSet(fYields,fParameters),kTRUE);
   
    fitResults->AddLast((RooFitResult*)fResult->clone());
    
    nan=TMath::IsNaN(fResult->minNll());
    //check covariance OK or externally provide (SumW2Error) =-1
    edm=(fResult->covQual()>1)||(fResult->covQual()==-1);
    fail=(fResult->minNll()!=-1e+30);
    if(fBinnedFit&&!TMath::IsNaN(fChi2)) loglh[ifit]=fChi2; //actually did chi2 fit
    else if((!nan)&&edm&&fail)loglh[ifit]=fResult->minNll();  //loglh[ifit]=fResult->minNll();
    else loglh[ifit]=1E300;
 
  }
  cout<<"HSRooFit::FitMany  Likelihoods "<<endl;
  for(Int_t i=0;i<Nfits;i++){
    cout<<loglh[i]<<endl;
  }	
  //take best result for splot parameters
  Int_t best=TMath::LocMin(Nfits,loglh.GetMatrixArray());
  cout<<"HSRooFit::FitMany() Best likelihood was "<<loglh[best]<<" "<<best<<" so use those parameters"<<endl;
  fWS->loadSnapshot(Form("ssFit%d",best));
 
  fResult=dynamic_cast<RooFitResult*>(fitResults->RemoveAt(best));//keep for writing to file
  fResult->SetName(Form("Result"));
  fResult->Print();

  for(Int_t iy=0;iy<fYields.getSize();iy++){
    cout<<((RooRealVar*)&fYields[iy])->GetName()<<" "<<((RooRealVar*)&fYields[iy])->getVal()<<endl;
    //  ((RooRealVar*)&fYields[iy])->setError(sqrt(((RooRealVar*)&fYields[iy])->getVal()));
  }

}


void HSRooFit::WriteToFile(TString fname){
  //this currently crashes and could be fixed
  //need to change the version to 1 in ClassDef
  TFile rfFile(fname,"recreate");
  Write();
  rfFile.Close();
}
Bool_t HSRooFit::InitialiseFit(){
  cout<<" HSRooFit::InitialiseFit()"<<endl;
  if(GetDataSet()->numEntries()<2) {return kFALSE;}
  if(GetPDFs().getSize()==0){
    cout<<" HSRooFit::InitialiseFit() no model found for "<<GetName()<<" probably no events kinmatically allowed in this bin" <<endl;
    return kFALSE;
  }
  return kTRUE;
    
}
void HSRooFit::DefaultFitOptions(){
  // if(fData)
  //   if(fData->isNonPoissonWeighted())AddFitOption(RooFit::SumW2Error(kTRUE));
  AddFitOption(RooFit::NumCPU(1));
  AddFitOption(RooFit::Save(kTRUE));
  AddFitOption(RooFit::Warnings(kFALSE));


}
Double_t  HSRooFit::SumWeights(){
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
Double_t  HSRooFit::SumWeights2(){
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
///////////////////////////////////////////////////
///Make a ModelConfig from HSRooFit for RooStats purposes
RooStats::ModelConfig*  HSRooFit::GetModelConfig(){
  cout<<"ModelConfig*  HSRooFit::GetModelConfig()"<<endl;
  if(fModelConfig)return fModelConfig;
  fModelConfig =new RooStats::ModelConfig(fWS);
  if(!fModel) fModel=(RooAbsPdf*)&(fPDFs[0]);//Not ideal, will just take the fist PDF loaded by LoadSpecies unless TotalPDF has already been called.
  fModelConfig->SetPdf(*fModel);
  fModelConfig->SetParametersOfInterest(GetParameters());
  return fModelConfig;
}
void  HSRooFit::ClearRF(){
  fVariables.removeAll();
  fAuxVars.removeAll();
  fBinVars.removeAll();
  fParameters.removeAll();
  fYields.removeAll();
  fPDFs.removeAll();
  fConstraints.removeAll();
  delete fModel;fModel=nullptr;
  CleanWSDataSets();
  RemoveDataSet();
  // if(fWS)delete fWS;fWS=nullptr;
  fID=nullptr;
}
//////////////////////////////////////////////////
///Create data sets for batch ToyMC analysis
void  HSRooFit::GenerateToys(Int_t Ntoys){
  if(!fModel) TotalPDF();
  Long64_t geni=0;
  for(Int_t i=0;i<Ntoys;i++){
    //Number of events to generate
    Long64_t nexp=RooRandom::randomGenerator()->Poisson(GetModel()->expectedEvents(GetVariables()));
    //GetModel()->SetGeni(geni);
    RooDataSet* DS=GetModel()->generate(GetVariables(),nexp);
    DS->SetName("ToyData");
    TFile* outfile=new TFile(GetOutDir()+Form("/Toy_%d.root",i),"recreate");
    DS->Write();
    outfile->Close();
    delete outfile;
    //geni=GetModel->GetGeni();
  }
}
