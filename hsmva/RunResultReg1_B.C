//Based on $ROOTSYS/tutorials/tmva/TMVARegressionApplication.C
//You can replace the default classifier name with any other you trained pervious (here defMLP)
////////////////////////////////////////////////////////////////////////////////
//This demonstrates automated usage where you just give the path to the Training.root file
//and can then set the tree brances automatically assuming they are all floats

#include "ResultReg1.h"
#include "GetTutorialFile.h"

using namespace HSMVA;

void RunReg1Result_B(){

  auto input = GetRegressionFile();

  auto regTree = dynamic_cast<TTree*>(input->Get("TreeR"));
 
  ResultReg1 regres("TMVARegressionTut","defMLP");
  regres.SetBranchAllFloats(regTree);
    
  gBenchmark->Start("reg1");
  Int_t Nent = regTree->GetEntries();
  for(Int_t i=0;i<Nent;i++){
     regTree->GetEntry(i);
     regres.Eval(); //get the value of the function
   }
   gBenchmark->Stop("reg1");
   gBenchmark->Print("reg1");
   
 }
