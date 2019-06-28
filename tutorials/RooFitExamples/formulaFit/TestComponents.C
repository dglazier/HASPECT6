{
  // RooAbsData::setDefaultStorageType(RooAbsData::Tree);
   
  FitManager RF;
  RF.SetUp().SetOutDir("outComps/");

  RF.SetUp().LoadVariable("Phi[-90,90]");
  
  //  RF.SetUp().LoadFormula("ONE=1");
  // RF.SetUp().LoadFormula("@D[0,-0.5,0.5]");
   RF.SetUp().LoadFormula("COS2=cos(2*(@Phi[])/57.29578)");
  // RF.SetUp().LoadFormula("COS2=@E[0,-0.5,0.5]*cos(2*(@Phi[]+@Phi0[0,-10,10])/57.29578)");
  RF.SetUp().LoadFormula("SIN2=sin(2*(@Phi[])/57.29578)");
  //RF.SetUp().LoadFormula("COS2=cos(2*(@Phi[]+@Phi0[0,-10,10])/57.29578)");
  //RF.SetUp().LoadFormula("SIN2=sin(2*(@Phi[]+@Phi0[])/57.29578)");
  //RF.SetUp().LoadFormula("COS2=cos(2*@Phi[]/57.29578)");
  ///  RF.SetUp().LoadFormula("SIN2=sin(2*@Phi[]/57.29578)");
  
  RF.SetUp().LoadParameter("A[0,-1,1]");
  // RF.SetUp().LoadParameter("A[0.25]");
  RF.SetUp().LoadParameter("B[0,-1,1]");

  // auto ws=RF.SetUp().WS();
  
  //vector<RooArgList> components={{*ws.function("ONE")},{*ws.var("A"),*ws.function("COS2")},{*ws.var("B"),*ws.function("SIN2")}};

  //RooArgList obs = {*ws.var("Phi")};
  //auto pdf=new RooComponentsPDF("comps","comps",obs,components);

  RF.SetUp().FactoryPDF("RooComponentsPDF::COS2SIN2(1,{Phi},=A;COS2:B;SIN2)");
  // RF.SetUp().FactoryPDF("RooComponentsPDF::COS2SIN2(1,{Phi},=A[0,-1,1];COS2:B[0,-1,1];SIN2)");
  
  // RF.SetUp().FactoryPDF("RooComponentsPDF::COS2SIN2(1,{Phi},=A[0,-1,1];COS2=cos(2*@Phi[]/57.29578):B[0,-1,1];SIN2=sin(2*@Phi[]/57.29578))");
  //  RF.SetUp().FactoryPDF("RooComponentsPDF::COS2SIN2(1,{Phi},=A[0,-1,1];COS2=cos(2*@Phi[]/57.29578)+@C[0,-1,1]*cos(3*@Phi[]/57.29578):B[0,-1,1];SIN2=sin(2*@Phi[]/57.29578))");

  RF.SetUp().LoadSpeciesPDF("COS2SIN2");
  
  // RF.LoadData("ToyData","Toys/Toy0.root");
  //RF.LoadSimulated("ToyData","ToysFlat/Toy0.root","COS2SIN2");
  RF.LoadData("ToyData","ToysAcc/Toy0.root");
  RF.LoadSimulated("ToyData","ToysAccFlat/Toy0.root","COS2SIN2");

  //And fit the sample data with MCMC
  gBenchmark->Start("fit ");
  //RF.SetMinimiser(new RooMcmcSeq(200,20,10));
  //  RF.SetUp().AddFitOption(RooFit::NumCPU(3));
  RF.SetUp().AddFitOption(RooFit::Optimize(1));
  Here::Go(&RF);
  gBenchmark->Stop("fit ");
  gBenchmark->Print("fit ");
  

  
}
