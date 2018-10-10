//Based on $ROOTSYS/tutorials/tmva/TMVARegressionApplication.C
//You can replace the default classifier name with any other you trained pervious (here defMLP)
////////////////////////////////////////////////////////////////////////////////
//This demonstrates
//Set the reader variables using ResultByRefLink and connect to local variables;
//These variables in general do not have to be part of a tree
//They can be any references to floats

#include "ResultInterface.h"
#include "GetTutorialFile.h"

using namespace HS::MVA;

void RunResultReg1_A(){

  auto input = GetRegressionFile();

  auto regTree = dynamic_cast<TTree*>(input->Get("TreeR"));
  Float_t v1,v2,val;
  regTree->SetBranchAddress( "var1", &v1 );
  regTree->SetBranchAddress( "var2", &v2 );
  regTree->SetBranchAddress( "fvalue", &val );

  //Make a map to link variable name (from training) to local variable
  mapNameFloat links;
  links["var1"]=&v1; //these do not have to be variables linked to a tree
  links["var2"]=&v2; //they can be a reference to any Float_t
  
  ResultByRefLink regres("TMVARegressionTut","MLP",links);
  auto hist=new TH1F("TargetResidual","Target Residual Distribution",100,-10,10);
  gBenchmark->Start("reg1");
  Int_t Nent = regTree->GetEntries();
  for(Int_t i=0;i<Nent;i++){
     regTree->GetEntry(i);
     Float_t result= regres.Eval();
     hist->Fill(result-val);
   }
   gBenchmark->Stop("reg1");
   gBenchmark->Print("reg1");
   hist->DrawCopy();
 }
