//Run with 
//root --hsfit optimisedFormula.C
{


  //create toy manager to generate data
  ToyManager toys(1); //create 1 toy data set

  //get the current directory where the data is (PROOF needs full path)
  TString pwd = TString(gSystem->Getenv("PWD"))+"/";
  toys.SetUp().SetOutDir(pwd+"ToysSmall/");
  
  ///////////////////////////////Load Variables
  toys.SetUp().LoadVariable("Phi[-180,180]");
  







}
