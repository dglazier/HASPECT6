/**
	\class ResultReg1
	Derived from ResultInterface
	Used for evaluating a 1 output MVA regression function
	For example with a tree :
	     ResultReg1 regres("MyMultiDimensionFunction","defMLP");
	     regres.SetBranchAddresses(regTree);
	     for(Int_t i=0;i<Nent;i++){
	        regTree->GetEntry(i);
		regres.EvalTree(); //get the value of the function
	     }
	@example RunReg1Result_B.C RunReg1Result.C RunReg1Result_C.C
*/

#include "ResultReg1.h"
#include <TObjArray.h>
#include <TFile.h>
#include <TTree.h>

ClassImp(HSMVA::ResultReg1);

////////////////////////////////////////////////////////////
///Specific implemntation requires:
///name, a name for this result object
///varlist, the list of variables used to train this result
///methodname, the name given to the method in training
///weightfile, the full path to the file containing the trained weights

HSMVA::ResultReg1::ResultReg1(TString name,TString varlist,TString methodname,TString weightfile) : ResultInterface(name,varlist,methodname,weightfile){

}
//////////////////////////////////////////////////////////////////
///Connect the variables in the method to a tree containing branches
///with the same names as the MVA was trained with
// void HSMVA::ResultReg1::SetBranchAddresses(TTree* tree){
//   for(UInt_t i=0;i<Method()->GetNVariables();i++){
//     tree->SetBranchAddress(Method()->GetInputVar(i),&fVars[i]);
//   }
// }

// void HSMVA::ResultReg1::AddDToTree(TString filename,TString treename,TString target){

//   TFile* file=TFile::Open(filename,"update");
//   TTree* tree=(TTree*)file->Get(treename);
  
//   //Add branches
//   for(UInt_t i=0;i<Method()->GetNVariables();i++){
//     tree->SetBranchAddress(Method()->GetInputVar(i),&fVars[i]);
//   }
//   Double_t val=0;
//   TBranch* branch=tree->Branch(target,&val,target+"/D");

//   for(Int_t iev=0;iev<tree->GetEntries();iev++){
//     tree->GetEntry(iev);
//     val=Eval();
//     branch->Fill();
//   }
//   tree->Write(tree->GetName(),TObject::kOverwrite);
//   delete tree;
//   delete file;
// }
