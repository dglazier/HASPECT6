//Run with 
//root --hsfit fitFormula2.C
{
  // ROOT::EnableImplicitMT();

  //create toy manager to generate data
  ToyManager toys(1); //create 1 toy data set

  //get the current directory where the data is (PROOF needs full path)
  TString pwd = TString(gSystem->Getenv("PWD"))+"/";
  toys.SetUp().SetOutDir(pwd+"Toys/");
  
  ///////////////////////////////Load Variables
  toys.SetUp().LoadVariable("Phi[-180,180]"); 

  //define paramter (A) depending on other parameters (a1)
  toys.SetUp().LoadFormula("A=(@a[0.5,-1,1]*@a[])");// A=a^2

  //define function pdf
  toys.SetUp().FactoryPDF("EXPR::amplitude('1+A*cos(2*Phi/57.29578)',Phi,A)");
  toys.SetUp().LoadSpeciesPDF("amplitude",2000000); //1000 events

  //Create a sample of data
  Here::Go(&toys);


 

  FitManager RF;
  RF.SetUp().SetOutDir(pwd+"outObs/");
  ///////////////////////////////Load Variables
  RF.SetUp().LoadVariable("Phi[-180,180]"); 

  //TF1 *func = new TF1("FCOS2","+cos(2*x/57.29578)",-180,180);
  
  // Create binding of TF1 object to above observable
  //RooAbsReal* fcos2 = RooFit::bindFunction(fa1,*RF.SetUp().WS().var("Phi")) ;


  //RF.SetUp().LoadFormula("COS2=cos(2*@Phi[]/57.29578)"); //
  //RF.SetUp().LoadFormula("SIN2=sin(2*@Phi[]/57.29578)"); //
  //RF.SetUp().FactoryPDF("EXPR::aCOS2('1+AA*COS2+BB*SIN2',AA[0,-1,1],BB[0,-1,1],COS2,SIN2)");


  RF.SetUp().FactoryPDF("EXPR::aCOS2('1+AA*cos(2*Phi/57.29578)+BB*sin(2*Phi/57.29578)',Phi,AA[0,-1,1],BB[0,-1,1])");


  RF.SetUp().LoadSpeciesPDF("aCOS2",1);
   
  RF.LoadData("ToyData",pwd+"Toys/Toy0.root");
 
  //And fit the sample data with MCMC
  gBenchmark->Start("fit ");
  //  RF.SetMinimiser(new RooMcmcSeq(100,20,10));
  //RF.SetUp().AddFitOption(RooFit::NumCPU(4));
  RF.SetUp().AddFitOption(RooFit::Optimize(0));
  Here::Go(&RF);
  gBenchmark->Stop("fit ");
  gBenchmark->Print("fit ");
  


}
