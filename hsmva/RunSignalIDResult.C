//Based on $ROOTSYS/tutorials/tmva/TMVAClassificationApplication.C
//You can replace the default classifier name with any other you trained pervious (here defMLP)
////////////////////////////////////////////////////////////////////////////////
//This demonstrates automated usage where you just give the path to the Training.root file
//and can then set the tree brances automatically assuming they are all floats

#include "ResultInterface.h"
#include "GetTutorialFile.h"
using namespace HS::MVA;

void RunSignalIDResult(){

  
  auto input = GetClassificationFile();
  
   TTree *signalTree     = (TTree*)input->Get("TreeS");

   //If I know the tree only contains floats
   ResultByFloatTree classif("TMVAClassificationTut","MLP",signalTree);
   
   gBenchmark->Start("allfloat");

   Long64_t Nent=signalTree->GetEntries();
   for(Int_t i=0;i<Nent;i++){
     signalTree->GetEntry(i);
     classif.Eval();
   }

   //if the tree contains other than floats I will convert
   //and add the response to the interal tree
  ResultByTree classif2("TMVAClassificationTut","MLP",signalTree);
  classif2.AddToTree();
  //now can look in MLP.root for tree + response
  
  gBenchmark->Stop("allfloat");
  gBenchmark->Print("allfloat");

 
}
