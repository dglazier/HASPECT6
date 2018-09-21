/**
	\class TrainingInterface
	Abstract Base class for interfacing to TMVA training.
	You will need to use a derived class for regression or classification
	Links to TMVA::DataLoader for connecting with input tree
	And to TMVA::Factory for defining models (BDT, MLP, ...)
	By default all branches in given tree are used in training
	To ignore some branches use IgnoreBranches("b1:b5:...")
	Constructor require and name which will be used as a directory name
	and can be used to connect to the result. If the same name is 
	used again results will be overwritten. You may also want to define
	an additional output directory SetOutDir("dirname") where the name dir
	will be copied to after training is completed
*/
#include <TROOT.h>
#include <TSystem.h>

#include "TrainingInterface.h"
using namespace HSMVA;

ClassImp(HSMVA::TrainingInterface);

////////////////////////////////////////////////////////////
///Specific implemntation requires:
TrainingInterface::TrainingInterface(TString name,TString opt):
  TNamed(name,name),
  fDataLoader{new  TMVA::DataLoader{name}}
{
  gSystem->Exec(Form("mkdir -p %s",GetName()));
  
  fOutFileName=name+"/"+fOutFileName;
  fOutputFile=TFile::Open( fOutFileName, "RECREATE" );

  //fFactory=std::unique_ptr<TMVA::Factory>(new TMVA::Factory(name,fOutputFile,opt));
  fFactory.reset(new TMVA::Factory(name,fOutputFile,opt));   
}
HSMVA::TrainingInterface::~TrainingInterface(){
  if(fOutputFile) delete fOutputFile;
  fOutputFile=nullptr;
}
///////////////////////////////////////////////////////////////////////
///Load a tree to DataLoader using all of its branches
///Unless branches turned off by IgnoreBranches or OnlyTheseBranches
void TrainingInterface::LoadTreeVars(TTree*  tree,Double_t weight){

  auto *loader=DataLoader();

  //Use first tree as tempate for variables
  //others assumed the same
  if(!fLoaded){
    TIter nextbr(tree->GetListOfBranches());
    while(auto br=nextbr()){

      if(std::count(fIgnoreBranches.begin(),fIgnoreBranches.end(),TString(br->GetName()))){cout<< "HSMVA::TrainingInterface::LoadTreeVars ingoring branch "<<br->GetName()<<endl;continue;}
      
      if(tree->GetBranchStatus(br->GetName())){
	if(TString(br->GetTitle()).Contains("/F"))
	  loader->AddVariable(br->GetName(),'F');    
	else if(TString(br->GetTitle()).Contains("/D"))
	  loader->AddVariable(br->GetName(),'F');
	else if(TString(br->GetTitle()).Contains("/I"))
	  loader->AddVariable(br->GetName(),'I');
	else Warning("HSMVA::TrainingInterface::AddTree","variable %s type not supported",br->GetName());	 
	//    tree->SetBranchAddress(br->GetName(),&fVars[i]);
      }
    }
  }
  fLoaded++;
}
void TrainingInterface::DoTraining(){
  auto factory=Factory();

  //MAke sure in ouput file
  fOutputFile->cd();
  DataLoader()->GetDataSetInfo().Write("DataSetInfo");

  // Train MVAs using the set of training events
  factory->TrainAllMethods();
  
  // Evaluate all MVAs using the set of test events
  factory->TestAllMethods();
  
  // Evaluate and compare performance of all configured MVAs
  factory->EvaluateAllMethods();

  delete fOutputFile;
  
  if(fOutDir!=TString("")){
    gSystem->Exec(Form("mkdir -p %s",fOutDir.Data()));
    TString trstring="Training.root";
    const char* exists= gSystem->FindFile(GetOutDir()+GetName(),trstring);
    if(exists){
      cout<<"Warning HSMVA::TrainingInterface::DoTraining() Directory already exists so I will remove it !"<<endl<<"                                               Sorry any previous data will be lost"<<endl;   
      gSystem->Exec(Form("rm  -r %s",(GetOutDir()+GetName()).Data()));
    }
    gSystem->Exec(Form("mv %s %s",GetName(),GetOutDir().Data()));
    // gSystem->Exec(Form("ln -s  %s %s",(GetOutDir()+GetName()).Data(),GetName()));
  }

  if (!gROOT->IsBatch()){
    gSystem->Load("libTMVAGui");
    Gui();  
  }

}
///////////////////////////////////////////////////////////////
///Do not load branches given in this list
void TrainingInterface::IgnoreBranches(TString branches){
  
 //Split the string with the variables list (v1:v2:v3:...) 
  auto bvars=branches.Tokenize(":");
  
  //Add variables from constructor list to the reader
  //And link to this fVars
   for(Int_t ib=0;ib<bvars->GetEntries();ib++)
     fIgnoreBranches.push_back(bvars->At(ib)->GetName());
}
////////////////////////////////////////////////////////////////////
///Set Branch Status to 0 if not listed in v0 ("v1:v2:v3:...")
void TrainingInterface::OnlyTheseBranches(TTree* tree,TString v0){
  //Get arrays of the variables to be used for each distribution
  auto bvars=v0.Tokenize(":");
  //Turn off all branches in tree
  tree->SetBranchStatus("*",0);
  //Turn on branches for distribution1
  for(Int_t i=0;i<bvars->GetEntries();i++)
    tree->SetBranchStatus(bvars->At(i)->GetName(),1);

}
