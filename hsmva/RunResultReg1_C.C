//Based on $ROOTSYS/tutorials/tmva/TMVARegressionApplication.C
//You can replace the default classifier name with any other you trained pervious (here defMLP)
////////////////////////////////////////////////////////////////////////////////
//This demonstrates automated usage where you just give the path to the Training.root file
//and can then set the tree branches automatically EVEN IF THEY ARE NOT ALL floats 

#include "ResultReg1.h"
#include "GetTutorialFile.h"

using namespace HSMVA;

void RunReg1Result_C(){

  auto input = GetRegressionFile();

  auto regTree = dynamic_cast<TTree*>(input->Get("TreeR"));
 
  ResultReg1 regresMLP("TMVARegressionTut","defMLP");
  regresMLP.SetBranchAddresses(regTree);
    
  ResultReg1 regresBDT("TMVARegressionTut","BDT");
  regresBDT.SetBranchAddresses(regTree);
    
  gBenchmark->Start("reg1");
  Int_t Nent = regTree->GetEntries();
  for(Int_t i=0;i<Nent;i++){
     regTree->GetEntry(i);
     regresMLP.EvalTree(); //get the value of the function
     regresBDT.EvalTree(); //get the value of the function
   }
   gBenchmark->Stop("reg1");
   gBenchmark->Print("reg1");
   
 }
