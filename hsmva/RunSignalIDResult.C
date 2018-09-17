//Based on $ROOTSYS/tutorials/tmva/TMVAClassificationApplication.C
//You can replace the default classifier name with any other you trained pervious (here defMLP)
////////////////////////////////////////////////////////////////////////////////
//This demonstrates automated usage where you just give the path to the Training.root file
//and can then set the tree brances automatically assuming they are all floats

#include "ClassResult.h"
#include "GetTutorialFile.h"
using namespace HSMVA;

void RunSignalIDResult(){

  
  auto input = GetClassificationFile();
  
   TTree *signalTree     = (TTree*)input->Get("TreeS");

   ClassResult classif("SignalID","defMLP");
   classif.SetBranchAllFloats(signalTree);
   
   gBenchmark->Start("allfloat");

   Long64_t Nent=signalTree->GetEntries();
   for(Int_t i=0;i<Nent;i++){
     signalTree->GetEntry(i);
     classif.Eval();
   }

   gBenchmark->Stop("allfloat");
   gBenchmark->Print("allfloat");

 
}
