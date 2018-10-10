/**
	\class ResultInterface
	Absract Base class for getting values of the TMVA result
	You will need to use derived classes for regreesion or classification tasks
	These can be constructed in manual mode where you sepcify the variables 
	and weightfile directly in the constructor
	OR you run automated by just providing the directory of the Training.root file
	It will only run 1 method at a time which must also be specified in the constructor
	The result value can be retrieved for an event using the Eval() function
	If you want the value for a non-TTree event you must give the variables
	via a vector<Float_t> : e.g. vector<Float_t > vars={v1,v2,v3...}; result.Eval(vars);

*/

#include <TSystem.h>
#include "ResultInterface.h"

using namespace HS::MVA;

ResultInterface::ResultInterface(TString trainpath,TString methodname) {
  //Assumes used TrainingInterface
  TFile* trainFile=TFile::Open(trainpath+"/Training.root");
  if(!trainFile) throw runtime_error{"ResultInterface::ResultInterface could not open %s"};
  
  fDataSetInfo.reset(dynamic_cast<TMVA::DataSetInfo* >(trainFile->Get("DataSetInfo")));
  

  delete trainFile;
}
void ResultInterface::InitMethod(TString trainpath,TString methodname){
  //Now the training jobname=name of the top level directory
  //This allows us to make the name of the weights file
  //make sure no / at end so BaseName works
  if(trainpath.EndsWith("/")) trainpath.Remove(TString::kTrailing,'/');
  TString jobname=gSystem->BaseName(trainpath);
  SetName(jobname+"Result");
  TString weightfile=trainpath+"/weights/"+jobname+"_"+methodname+".weights.xml";
  fMethod=dynamic_cast<TMVA::MethodBase *>(Reader()->BookMVA( methodname, weightfile ));
}
void ResultInterface::AddToTree(){
  if(!Tree()){
    cout<<"ResultByTree::AddToTree() I do not own a tree!"<<endl;
  }
  if(Method()->DoRegression())
    AddRegressionToTree();
  else
    AddClassificationToTree();
}
void ResultInterface::AddRegressionToTree(){
  auto vecTargets=DataSetInfo()->GetTargetInfos();
  vector<Float_t> varTargets(vecTargets.size());
  vector<TBranch*> branches;
  UInt_t iv=0;
  for(auto const& target: vecTargets){
    TString name=target.GetInternalName();
    cout<<name<<" "<<varTargets[iv]<<endl;
    branches.push_back(Tree()->Branch(name+"_reg",&varTargets[iv++],name+"_reg/F"));
  }
  while(NextEntry()){
      auto vecRes=EvalRegN();
      varTargets=vecRes;
      for(auto const& branch: branches)
	branch->Fill();
  }
    
}
void ResultInterface::AddClassificationToTree(){
 
  Float_t response=0;
  auto branch=Tree()->Branch(Method()->GetName(),&response,TString(Method()->GetName())+"/F");
  
  //classification
  while(NextEntry()){
    response=Eval();
    branch->Fill();
  }
  
}
/////////////////////////////////////////ResultByFloatTree
ResultByFloatTree::ResultByFloatTree(TString trainpath,TString methodname,TTree *tree):
  ResultInterface(trainpath,methodname){

  //Create fVars for linking tree to Reader
  const UInt_t NVars=DataSetInfo()->GetNVariables();
  auto vars=Vars();
  vars->resize(NVars);
  //Note internal name in principle could have been a formula in TMVA
  //in HSMVA only actual branch variables are supported
  for(UInt_t i=0;i<NVars;i++)
    Reader()->AddVariable(DataSetInfo()->GetVariableInfo(i).GetInternalName(),&(vars->at(i)));

  SetBranchAddresses(tree);

  InitMethod(trainpath,methodname);
};
  
//////////////////////////////////////////////////////////////////
///In the case we know all branches are floats we can just
//directly link the branch addresses to fVars
void ResultByFloatTree::SetBranchAddresses(TTree* tree){
  auto vars=Vars();
  const UInt_t NVars=DataSetInfo()->GetNVariables();
   for(UInt_t i=0;i<NVars;i++){
    auto res=tree->SetBranchAddress(DataSetInfo()->GetVariableInfo(i).GetInternalName(),&(*vars)[i]);
     if(res!=0){
       cout<<"Error ResultInterface::SetBranchAllFloats, Branch "<<Method()->GetInputVar(i) <<" not set, perhaps it is not a float "<<tree->GetBranch(Method()->GetInputVar(i))->GetTitle()<<endl;
       exit(1);
     }
  }
}
/////////////////////////////////////////////////ResultByTree
//Path to training dir, methodname for this result,
//tree you want to manipulate, copyTree(default false) make a copy of tree
//copy needed for AddToTree()
ResultByTree::ResultByTree(TString trainpath,TString methodname,TTree *tree,Bool_t copyTree):
  ResultInterface(trainpath,methodname){

  //Create fVars for linking tree to Reader
  const UInt_t NVars=DataSetInfo()->GetNVariables();
  auto vars=Vars();
  vars->resize(NVars);
  //Note internal name in principle could have been a formula in TMVA
  //in HSMVA only actual branch variables are supported
  for(UInt_t i=0;i<NVars;i++)
    Reader()->AddVariable(DataSetInfo()->GetVariableInfo(i).GetInternalName(),&(vars->at(i)));
  if(copyTree){
    //Make a copy of the tree
    TreePtr()->reset(new HS::FiledTree(1,tree,methodname+".root"));
    fNEntries=Tree()->GetEntries();
    SetBranchAddresses(Tree());
  }
  else //just link to tree
    SetBranchAddresses(tree);
  
  InitMethod(trainpath,methodname);
};

//////////////////////////////////////////////////////////////////
///Connect the variables in the method to a tree containing branches
///with the same names as the MVA was trained with
//To allow for non float branches we connect to other types
//first then transfer to fVars in each event
void ResultByTree::SetBranchAddresses(TTree* tree){
  auto vars=Vars();
  const UInt_t NVars=DataSetInfo()->GetNVariables();
 
  fTreeVarsD.resize(NVars);
  fTreeVarsF.resize(NVars);
  fTreeVarsL.resize(NVars);
  fTreeVarsI.resize(NVars);
 
  for(UInt_t i=0;i<NVars;i++){
    //First get the branch type
    TString bname=DataSetInfo()->GetVariableInfo(i).GetInternalName();
    auto branch=tree->GetBranch(bname);
    Int_t res=-1;
    if(TString(branch->GetTitle()).Contains("/F")){
      UInt_t vsize=fIsVarF.size();
      fTreeVarsF[vsize]=0;
      res=tree->SetBranchAddress(bname,&fTreeVarsF[vsize]);
      fIsVarF.push_back(i);
    }
    if(TString(branch->GetTitle()).Contains("/D")){
      UInt_t vsize=fIsVarD.size();
      fTreeVarsD[vsize]=0;
      res=tree->SetBranchAddress(bname,&fTreeVarsD[fTreeVarsD.size()-1]);
      fIsVarD.push_back(i);
    }
    if(TString(branch->GetTitle()).Contains("/I")){
      UInt_t vsize=fIsVarI.size();
      fTreeVarsI[vsize]=0;
      res=tree->SetBranchAddress(bname,&fTreeVarsI[fTreeVarsI.size()-1]);
      fIsVarI.push_back(i);
    }
     
    if(TString(branch->GetTitle()).Contains("/L")){
      UInt_t vsize=fIsVarL.size();
      fTreeVarsL[vsize]=0;
      res=tree->SetBranchAddress(bname,&fTreeVarsL[fTreeVarsL.size()-1]);
      fIsVarL.push_back(i);
    }
      
    if(res!=0)
      cout<<"ResultInterface::SetBranchAddresses, Branch "<< Method()->GetInputVar(i) <<"not set "<<endl;
      
  }
  
  fTreeVarsD.resize(fIsVarD.size());
  fTreeVarsF.resize(fIsVarF.size());
  fTreeVarsL.resize(fIsVarL.size());
  fTreeVarsI.resize(fIsVarI.size());

  fTreeVarsD.shrink_to_fit();
  fTreeVarsF.shrink_to_fit();
  fTreeVarsL.shrink_to_fit();
  fTreeVarsI.shrink_to_fit();
  
  cout<<" ResultInterface::SetBranchAddresses found branches : "<<endl;
  cout<< "   double "<<fIsVarD.size()<<endl;
  cout<< "   float "<<fIsVarF.size()<<endl;
  cout<< "   long "<<fIsVarL.size()<<endl;
  cout<< "   int "<<fIsVarI.size()<<endl;
  cout<<"   total vars in reader are "<<vars->size()<<endl;
}

void ResultByTree::ReadVars(){
  auto vars=Vars();

  for(auto const& val : *vars)
  //   cout<<val<<" ";
  // cout<<endl;
  for(UInt_t i=0;i<fIsVarD.size();i++)
    (*vars)[fIsVarD[i]]=fTreeVarsD[i];
   
  for(UInt_t i=0;i<fIsVarF.size();i++)
    (*vars)[fIsVarF[i]]=fTreeVarsF[i];
   
  for(UInt_t i=0;i<fIsVarL.size();i++)
    (*vars)[fIsVarL[i]]=fTreeVarsL[i];
   
  for(UInt_t i=0;i<fIsVarI.size();i++)
    (*vars)[fIsVarI[i]]=fTreeVarsI[i];
}
///////////////////////////////////////////////////ResultByRefLink
////////////////////////////////////////////////////////////////
///Class to link reader variables to float references via
/// map<TString, Float_t* > (aka mapNameFloat!)
///e.g. map<TString, Float_t& > mylinks;
///     Float_t v1=0;
///     mylinks["v1"]=&v1;
///     ...
///     ResultByRefLink result("/path/to/Training.root","defBDT",mylinks);
ResultByRefLink::ResultByRefLink(TString trainpath,TString methodname,mapNameFloat links):
  ResultInterface(trainpath,methodname){

  const UInt_t NVars=DataSetInfo()->GetNVariables();
  //fVars.resize(NVars);//Not used!
  for(UInt_t i=0;i<NVars;i++){
    //***********************************************************
    //Here is different use external links rather than fVars
    TString name=DataSetInfo()->GetVariableInfo(i).GetInternalName();
    if(!links[name]){
      cout<<" variable "<<name<<endl;
      throw std::runtime_error{"ResultByRefLink variable does not exist in link map"};
    }
    Reader()->AddVariable(name,links[name]);
  }
  InitMethod(trainpath,methodname);

}
