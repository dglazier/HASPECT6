//Run with 
//root --hsfit fitFormula.C
{

  //create toy manager to generate data
  ToyManager toys(1); //create 1 toy data set

  //get the current directory where the data is (PROOF needs full path)
  TString pwd = TString(gSystem->Getenv("PWD"))+"/";
  toys.SetUp().SetOutDir(pwd+"Toys/");
  
  ///////////////////////////////Load Variables
  toys.SetUp().LoadVariable("Phi[-180,180]"); 

  //define paramter (A) depending on other parameters (a1)
  toys.SetUp().LoadFormula("A=(@a[0.9,-1,1]*@a[])");// A=a^2

  //define function pdf
  toys.SetUp().FactoryPDF("EXPR::amplitude('1+A*cos(2*Phi/57.29578)',Phi,A)");
  toys.SetUp().LoadSpeciesPDF("amplitude",1000); //1000 events

  //Create a sample of data
  Here::Go(&toys);

    //now create a fitter from the toymanager
  auto fit=toys.Fitter();

  
  //And fit the sample data with MCMC
  fit->SetMinimiser(new RooMcmcSeq(1000,200,10));


  fit->SetUp().WS().var("a")->setVal(0);
  gBenchmark->Start("fit ");
  Here::Go(fit);
  gBenchmark->Stop("fit ");
  gBenchmark->Print("fit ");
  


}
