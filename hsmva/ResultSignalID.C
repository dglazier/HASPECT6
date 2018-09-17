/**
	\class ResultSignalID
	Derived from ResultInterface
	Used for evaluating classifier output of signal and background
	For example :
	  ResultSignalID classif("SignalID","defMLP");
	  classif.SetBranchAllFloats(signalTree);
	  for(Int_t i=0;i<Nent;i++){
	     signalTree->GetEntry(i);
	  classif.Eval();
	  }

*/

#include "ResultSignalID.h"
#include <TObjArray.h>
#include <TFile.h>
#include <TTree.h>

ClassImp(HSMVA::ResultSignalID);

////////////////////////////////////////////////////////////
///Specific implemntation requires:
///name, a name for this result object
///varlist, the list of variables used to train this result
///methodname, the name given to the method in training
///weightfile, the full path to the file containing the trained weights

HSMVA::ResultSignalID::ResultSignalID(TString name,TString varlist,TString methodname,TString weightfile) : ResultInterface(name,varlist,methodname,weightfile){
 }
