{


  // RooAbsData::setDefaultStorageType(RooAbsData::Tree);
 
  FitManager RF;
  RF.SetUp().SetOutDir("outCompsPol/");

  RF.SetUp().LoadVariable("Phi[-10,180]");
  RF.SetUp().LoadCategory("Pol[p=1,m=-1]"); 
  RF.SetUp().LoadFormula("SIN2=@Pol[]*sin(2*(@Phi[])/57.29578)");
  RF.SetUp().LoadFormula("COS2=@Pol[]*cos(2*(@Phi[])/57.29578)");
   
  RF.SetUp().LoadParameter("A[0,-1,1]");
  RF.SetUp().LoadParameter("B[0,-1,1]");


  RF.SetUp().FactoryPDF("RooComponentsPDF::COS2SIN2(1,{Phi,Pol},=A;COS2:B;SIN2)");

  RF.SetUp().LoadSpeciesPDF("COS2SIN2");
  
  RF.LoadData("ToyData","ToysAccPol/Toy0.root");
  RF.LoadSimulated("ToyData","ToysAccPolFlat/Toy0.root","COS2SIN2");

  //And fit the sample data with MCMC
  gBenchmark->Start("fit ");
  //  RF.SetMinimiser(new RooMcmcSeq(200,20,400));
  RF.SetUp().AddFitOption(RooFit::NumCPU(3));
  RF.SetUp().AddFitOption(RooFit::Optimize(1));
  Here::Go(&RF);
  gBenchmark->Stop("fit ");
  gBenchmark->Print("fit ");
  

  
}
