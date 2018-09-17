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
	Or if you are using a tree you can link the branches through SetBranchAllFloats()
	if you know all branches are floats
	Or with SetBranchAddresses(tree); if they have different types
	**Note In this case you must use result.EvalTree(); inplace of Eval()

*/

#include <TSystem.h>
#include "ResultInterface.h"

ClassImp(HSMVA::ResultInterface);

////////////////////////////////////////////////////////////
///Specific implemntation requires:
///name, a name for this result object
///varlist, the list of variables used to train this result
///methodname, the name given to the method in training
///weightfile, the full path to the file containing the trained weights
HSMVA::ResultInterface::ResultInterface(TString name,TString varlist,TString methodname,TString weightfile) {

  //Split the string with the variables list (v1:v2:v3:...) 
  auto svars=varlist.Tokenize(":");
  
  //Add variables from constructor list to the reader
  //And link to this fVars
  fVars.resize(svars->GetEntries());
  for(Int_t ivars=0;ivars<svars->GetEntries();ivars++){
    Reader()->AddVariable(svars->At(ivars)->GetName(),&fVars[ivars]);
   }

  InitMethod(methodname,weightfile); 
}
HSMVA::ResultInterface::ResultInterface(TString trainpath,TString methodname) {
  //Assumes used HSMVA::TrainingInterface
  TFile* trainFile=TFile::Open(trainpath+"/Training.root");
  TMVA::DataSetInfo* dsi=dynamic_cast<TMVA::DataSetInfo* >(trainFile->Get("DataSetInfo"));
  
  fVars.resize(dsi->GetNVariables());
  //Note internal name in principle could have been a formula in TMVA
  //in HSMVA only actual branch variables are supported
  for(UInt_t i=0;i<dsi->GetNVariables();i++)
    Reader()->AddVariable(dsi->GetVariableInfo(i).GetInternalName(),&fVars[i]);

  //Now the training jobname=name of the top level directory
  //This allows us to make the name of the weights file
  //make sure no / at end so BaseName works
  if(trainpath.EndsWith("/")) trainpath.Remove(TString::kTrailing,'/');
  TString jobname=gSystem->BaseName(trainpath);
  InitMethod(methodname,trainpath+"/weights/"+jobname+"_"+methodname+".weights.xml"); 
  SetName(jobname+"Result"); 
}
//////////////////////////////////////////////////////////////////
///In the case we know all branches are floats we can just
//directly link the branch addresses to fVars
void HSMVA::ResultInterface::SetBranchAllFloats(TTree* tree){
  for(UInt_t i=0;i<Method()->GetNVariables();i++){
     auto res=tree->SetBranchAddress(Method()->GetInputVar(i),&fVars[i]);
     if(res!=0){
       cout<<"Error HSMVA::ResultInterface::SetBranchAllFloats, Branch "<<Method()->GetInputVar(i) <<" not set, perhaps it is not a float "<<tree->GetBranch(Method()->GetInputVar(i))->GetTitle()<<endl;
       exit(1);
     }
  }
}
//////////////////////////////////////////////////////////////////
///Connect the variables in the method to a tree containing branches
///with the same names as the MVA was trained with
//To allow for non float branches we connect to other types
//first then transfer to fVars in each event
void HSMVA::ResultInterface::SetBranchAddresses(TTree* tree){
  const auto nvars=Method()->GetNVariables();
  fTreeVarsD.resize(nvars);
  fTreeVarsF.resize(nvars);
  fTreeVarsL.resize(nvars);
  fTreeVarsI.resize(nvars);
 
  for(UInt_t i=0;i<nvars;i++){
    //First get the branch type
    auto branch=tree->GetBranch(Method()->GetInputVar(i));
    Int_t res=-1;
    if(TString(branch->GetTitle()).Contains("/F")){
      UInt_t vsize=fIsVarF.size();
      fTreeVarsF[vsize]=0;
      res=tree->SetBranchAddress(Method()->GetInputVar(i),&fTreeVarsF[vsize]);
      fIsVarF.push_back(i);
    }
    if(TString(branch->GetTitle()).Contains("/D")){
      UInt_t vsize=fIsVarD.size();
      fTreeVarsD[vsize]=0;
      res=tree->SetBranchAddress(Method()->GetInputVar(i),&fTreeVarsD[fTreeVarsD.size()-1]);
      fIsVarD.push_back(i);
    }
    if(TString(branch->GetTitle()).Contains("/I")){
      UInt_t vsize=fIsVarI.size();
      fTreeVarsI[vsize]=0;
      res=tree->SetBranchAddress(Method()->GetInputVar(i),&fTreeVarsI[fTreeVarsI.size()-1]);
      fIsVarI.push_back(i);
    }
     
    if(TString(branch->GetTitle()).Contains("/L")){
      UInt_t vsize=fIsVarL.size();
      fTreeVarsL[vsize]=0;
      res=tree->SetBranchAddress(Method()->GetInputVar(i),&fTreeVarsL[fTreeVarsL.size()-1]);
      fIsVarL.push_back(i);
    }
      
    if(res!=0)
      cout<<"HSMVA::ResultInterface::SetBranchAddresses, Branch "<< Method()->GetInputVar(i) <<"not set "<<endl;
      
  }
  
  fTreeVarsD.resize(fIsVarD.size());
  fTreeVarsF.resize(fIsVarF.size());
  fTreeVarsL.resize(fIsVarL.size());
  fTreeVarsI.resize(fIsVarI.size());

  fTreeVarsD.shrink_to_fit();
  fTreeVarsF.shrink_to_fit();
  fTreeVarsL.shrink_to_fit();
  fTreeVarsI.shrink_to_fit();
  
  cout<<" HSMVA::ResultInterface::SetBranchAddresses found branches : "<<endl;
  cout<< "   double "<<fIsVarD.size()<<endl;
  cout<< "   float "<<fIsVarF.size()<<endl;
  cout<< "   long "<<fIsVarL.size()<<endl;
  cout<< "   int "<<fIsVarI.size()<<endl;
  cout<<"   total vars in reader are "<<fVars.size()<<endl;
}

Float_t HSMVA::ResultInterface::EvalTree(){

  for(UInt_t i=0;i<fIsVarD.size();i++)
    fVars[fIsVarD[i]]=fTreeVarsD[i];
   
  for(UInt_t i=0;i<fIsVarF.size();i++)
    fVars[fIsVarF[i]]=fTreeVarsF[i];
   
  for(UInt_t i=0;i<fIsVarL.size();i++)
    fVars[fIsVarL[i]]=fTreeVarsL[i];
   
  for(UInt_t i=0;i<fIsVarI.size();i++)
    fVars[fIsVarI[i]]=fTreeVarsI[i];
  
  return Eval();
}
HSMVA::ResultInterface::~ResultInterface(){
  if(fReader) delete fReader;
}

