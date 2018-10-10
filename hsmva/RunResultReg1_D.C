//Based on $ROOTSYS/tutorials/tmva/TMVARegressionApplication.C
//You can replace the default classifier name with any other you trained pervious (here defMLP)
////////////////////////////////////////////////////////////////////////////////
//This demonstrates automated usage where you just give the path to the Training.root file
//and can then set the tree branches automatically EVEN IF THEY ARE NOT ALL floats
//Iterates over events using NextEntry

#include "ResultInterface.h"
#include "GetTutorialFile.h"

using namespace HS::MVA;

void RunResultReg1_D(){
  // ROOT::EnableImplicitMT();
  auto input = GetRegressionFile();

  auto regTree = dynamic_cast<TTree*>(input->Get("TreeR"));
   gBenchmark->Start("reg1");

  ResultByTree regresMLP("TMVARegressionTut","MLP",regTree);
    
  ResultByTree regresBDT("TMVARegressionTut","BDT",regTree);
    
  while(regresMLP.NextEntry()&&regresBDT.NextEntry()){
     regresMLP.Eval(); //get the value of the function
     regresBDT.Eval(); //get the value of the function
   }
   gBenchmark->Stop("reg1");
   gBenchmark->Print("reg1");

   delete regTree;
   delete input;
 }
