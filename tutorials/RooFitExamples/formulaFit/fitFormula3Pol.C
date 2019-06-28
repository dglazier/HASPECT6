// To generate the flat data you need to rerun this macro with :
// toys.SetUp().SetOutDir(pwd+"ToysAccPolFlat/");
// toys.SetUp().LoadFormula("A=(@a[0,-1,1]*@a[])");
//Run with 
//root --hsfit fitFormula3Pol.C
{
  // ROOT::EnableImplicitMT();

  //create toy manager to generate data
  ToyManager toys(1); //create 1 toy data set

  //get the current directory where the data is (PROOF needs full path)
  TString pwd = TString(gSystem->Getenv("PWD"))+"/";
  //  toys.SetUp().SetOutDir(pwd+"ToysAccPolFlat/");
  toys.SetUp().SetOutDir(pwd+"ToysAccPol/");
  
  ///////////////////////////////Load Variables
  toys.SetUp().LoadVariable("Phi[-180,180]"); 
  toys.SetUp().LoadCategory("Pol[p=1,m=-1]"); 

  //define paramter (A) depending on other parameters (a1)
  toys.SetUp().LoadFormula("A=(@a[0.5,-1,1]*@a[])");// A=a^2

  //define function pdf
  toys.SetUp().FactoryPDF("EXPR::amplitude('sin(Phi/57.29578)*sin(Phi/57.29578)*(1+A*Pol*cos(2*Phi/57.29578))',Phi,Pol,A)");
  toys.SetUp().LoadSpeciesPDF("amplitude",2000000); //1000 events

  //Create a sample of data
  Here::Go(&toys);


 
  Loader::Compile("PhiThAsymmetryPDF.cxx");
  Loader::Compile("PhiAsymmetryPDF.cxx");
  Loader::Compile("PhiAsymmetryPDFVar.cxx");
 
  FitManager RF;
  RF.SetUp().SetOutDir(pwd+"outObs/");
  ///////////////////////////////Load Variables
  RF.SetUp().LoadVariable("Phi[-180,180]");
  RF.SetUp().LoadCategory("Pol[p=1,m=-1]"); 

  RF.SetUp().FactoryPDF("EXPR::aCOS2('1+AA*Pol*cos(2*Phi/57.29578)+BB*sin(2*Phi/57.29578)',Phi,Pol,AA[0,-1,1],BB[0,-1,1])");


  RF.SetUp().LoadSpeciesPDF("aCOS2",1);
   
  RF.LoadData("ToyData",pwd+"ToysAccPol/Toy0.root");
  RF.LoadSimulated("ToyData","ToysAccFlat/Toy0.root","SigAsym");

  //And fit the sample data with MCMC
  gBenchmark->Start("fit ");
  // RF.SetMinimiser(new RooMcmcSeq(1000,20,10));
  //RF.SetUp().AddFitOption(RooFit::NumCPU(4));
  // RF.SetUp().AddFitOption(RooFit::NumCPU(3));
  Here::Go(&RF);
  gBenchmark->Stop("fit ");
  gBenchmark->Print("fit ");
  


}
