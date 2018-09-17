//Based on $ROOTSYS/tutorials/tmva/TMVARegressionApplication.C
//You can replace the default classifier name with any other you trained pervious (here defMLP)
////////////////////////////////////////////////////////////////////////////////
//This demonstrates manual usage where you the full path to the weights files;
//Set the tree variables to the RegResult1 in the constructor and connect to tree;
//and give the variable values each event via a vector

#include "RegResult1.h"
#include "GetTutorialFile.h"

using namespace HSMVA;

void RunReg1Result(){

  auto input = GetRegressionFile();

  auto regTree = dynamic_cast<TTree*>(input->Get("TreeR"));
 
  RegResult1 regres("Sim","var1:var2","defMLP","TMVARegressionTut/weights/TMVARegressionTut_defMLP.weights.xml");

  
  Float_t v1,v2;
  regTree->SetBranchAddress( "var1", &v1 );
  regTree->SetBranchAddress( "var2", &v2 );
    
  gBenchmark->Start("reg1");
   for(Int_t i=0;i<1E5;i++){
     regTree->GetEntry(i);
     vector<Float_t> vars={v1,v2};
     regres.Eval(vars); //get the value of the function
   }
   gBenchmark->Stop("reg1");
   gBenchmark->Print("reg1");
   
 }
