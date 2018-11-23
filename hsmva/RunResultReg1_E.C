//run with root $HSCODE/hsmva/LoadHSMVA.C+ RunResultReg1_E.C
//Based on $ROOTSYS/tutorials/tmva/TMVARegressionApplication.C
//You can replace the default classifier name with any other you trained pervious (here defMLP)
////////////////////////////////////////////////////////////////////////////////
//This demonstrates automated usage where you just give the path to the Training.root file
//and can then set the tree branches automatically EVEN IF THEY ARE NOT ALL floats 

#include "ResultInterface.h"
#include "GetTutorialFile.h"
#include <TSystem.h>
#include <TBenchmark.h>
#include <TFile.h>
#include <TTree.h>
using namespace HS::MVA;

void RunResultReg1_E(){
  // ROOT::EnableImplicitMT();
  auto input = GetRegressionFile();

  auto regTree = dynamic_cast<TTree*>(input->Get("TreeR"));
  gBenchmark->Start("reg1");

  //kTRUE here => Copy the trees (so can add the result)
  //these wil be output in files MLP.root and BDT.root
  ResultByTree regresMLP("TMVARegressionTut","MLP",regTree,kTRUE);
  ResultByTree regresBDT("TMVARegressionTut","BDT",regTree,kTRUE);

  //Add the new result branch to tree
  regresMLP.AddToTree();
  regresBDT.AddToTree();
  
  gBenchmark->Stop("reg1");
  gBenchmark->Print("reg1");
  regresMLP.Tree()->Print();

  regresMLP.Tree()->Draw("fvalue_reg:fvalue","","");

  delete regTree;
  delete input;
} 
