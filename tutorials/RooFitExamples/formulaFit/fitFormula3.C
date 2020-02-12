//Run with 
//root --hsfit fitFormula2.C
{
  // ROOT::EnableImplicitMT();

  //create toy manager to generate data
  ToyManager toys(1); //create 1 toy data set

  //get the current directory where the data is (PROOF needs full path)
  TString pwd = TString(gSystem->Getenv("PWD"))+"/";
  toys.SetUp().SetOutDir(pwd+"ToysSmall/");
  
  ///////////////////////////////Load Variables
  toys.SetUp().LoadVariable("Phi[-180,180]"); 
  toys.SetUp().LoadVariable("Theta[0,-180,180]"); 

  //define paramter (A) depending on other parameters (a1)
  toys.SetUp().LoadFormula("A=(@a[0.5,-1,1]*@a[])");// A=a^2

  //define function pdf
  //toys.SetUp().FactoryPDF("EXPR::amplitude('sin(Phi/57.29578)*sin(Phi/57.29578)*(1+A*cos(2*Phi/57.29578))',Phi,A)");
 toys.SetUp().FactoryPDF("EXPR::amplitude('(1+A*cos(2*Phi/57.29578))',Phi,A)");
  toys.SetUp().LoadSpeciesPDF("amplitude",100); //1000 events

  //Create a sample of data
  Here::Go(&toys);


 
  Loader::Compile("PhiThAsymmetryPDF.cxx");
  Loader::Compile("PhiAsymmetryPDF.cxx");
  Loader::Compile("PhiAsymmetryPDFVar.cxx");
 
  FitManager RF;
  RF.SetUp().SetOutDir(pwd+"outObs/");
  ///////////////////////////////Load Variables
  RF.SetUp().LoadVariable("Phi[-100,100]");
  //RF.SetUp().LoadVariable("Theta1[0,-180,180]");
  
  // RF.SetUp().LoadFormula("COS2=cos(2*@Phi[]/57.29578)");
  //RF.SetUp().LoadFormula("SIN2=sin(2*@Phi[]/57.29578)");
   //RF.SetUp().LoadFormula("SIN2=0");
   
  // RF.SetUp().FactoryPDF("PhiAsymmetryPDFVar::SigAsym( Phi,A[0,-1,1],B[0,-1,1],COS2,SIN2 )");
  RF.SetUp().FactoryPDF("PhiAsymmetryPDF::SigAsym( Phi,A[0,-1,1],B[0,-1,1] )");
  //RF.SetUp().FactoryPDF("PhiThAsymmetryPDF::SigAsym( Phi,Theta1,A[0,-1,1],B[0,-1,1] )");

  // RF.SetUp().FactoryPDF("EXPR::aCOS2('1+AA*cos(2*Phi/57.29578)+BB*sin(2*Phi/57.29578)',Phi,AA[0,-1,1],BB[0,-1,1])");


  RF.SetUp().LoadSpeciesPDF("SigAsym",1);
   
  RF.LoadData("ToyData",pwd+"ToysAcc/Toy0.root");
  RF.LoadSimulated("ToyData","ToysAccFlat/Toy0.root","SigAsym");

  //And fit the sample data with MCMC
  gBenchmark->Start("fit ");
  // RF.SetMinimiser(new RooMcmcSeq(1000,20,10));
  //RF.SetUp().AddFitOption(RooFit::NumCPU(4));
  RF.SetUp().AddFitOption(RooFit::NumCPU(3));
  //  RF.SetUp().AddFitOption(RooFit::Optimize(1));
  Here::Go(&RF);
  gBenchmark->Stop("fit ");
  gBenchmark->Print("fit ");
  


}
