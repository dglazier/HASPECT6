
{


  Loader::Compile("RooHSSphHarmonic.C");
  // Loader::Compile("PDFExpand.C");
  
  ToyManager Flat;
  Flat.SetUp().SetOutDir("flatSphHarmonic/");

  Flat.SetUp().LoadVariable("CosTh[0,-1,1]");
  Flat.SetUp().LoadVariable("Phi[-3.14159,3.14159]");
  Flat.SetUp().LoadVariable("PolPhi[-3.14159,3.14159]");
  Flat.SetUp().LoadVariable("Pol[0.5,0.2,0.6]");

  
  Flat.SetUp().LoadFunctionVar("RooConstVar::Val(1)");
  Flat.SetUp().FactoryPDF("RooComponentsPDF::Flat(1,{CosTh,Phi,PolPhi,Pol},=Val)");

  Flat.SetUp().LoadSpeciesPDF("Flat",1000000); //2000 events

  // Create a sample of data
  gBenchmark->Start("flat");
  // Here::Go(&Flat);
  gBenchmark->Stop("flat");
  gBenchmark->Print("flat");


  ToyManager Generator;
  Generator.SetUp().SetOutDir("genSphHarmonic/");

  Generator.SetUp().LoadVariable("CosTh[0,-1,1]");
  Generator.SetUp().LoadVariable("Phi[-3.14159,3.14159]");
  Generator.SetUp().LoadVariable("PolPhi[-3.14159,3.14159]");
  Generator.SetUp().LoadVariable("Pol[0.5,0.2,0.6]");
 
  auto configGenPDF=HS::FIT::EXPAND::ComponentsPolSphHarmonic(Generator.SetUp(),"Moments","CosTh","Phi","PolPhi","Pol",3,2);
  //  Generator.SetUp().WS().var("H0_0_0")->setVal(1);
  Generator.SetUp().WS().var("H1_0_0")->setVal(0.5);
  Generator.SetUp().WS().var("H2_2_2")->setVal(0.3);
  
  Generator.SetUp().FactoryPDF(configGenPDF);

  Generator.SetUp().LoadSpeciesPDF("Moments",100000); //2000 events

  //Create a sample of data
  gBenchmark->Start("gen");
  // Here::Go(&Generator);
  gBenchmark->Stop("gen");
  gBenchmark->Print("gen");


  FitManager Fitter;
  Fitter.SetUp().SetOutDir("outSphHarmonic/");

  Fitter.SetUp().LoadVariable("CosTh[0,-1,1]");
  Fitter.SetUp().LoadVariable("Phi[-3.14159,3.14159]");
  Fitter.SetUp().LoadVariable("PolPhi[-3.14159,3.14159]");
  Fitter.SetUp().LoadVariable("Pol[0.5,0.2,0.6]");
 
  auto configFitPDF=HS::FIT::EXPAND::ComponentsPolSphHarmonic(Fitter.SetUp(),"Moments","CosTh","Phi","PolPhi","Pol",3,2);
  //Fitter.SetUp().WS().var("H0_0_0")->setVal(1);
  //Fitter.SetUp().WS().var("H0_0_0")->setConstant(1);
  
  Fitter.SetUp().WS().var("H1_0_0")->setVal(0);
  
  Fitter.SetUp().FactoryPDF(configFitPDF);

  Fitter.SetUp().LoadSpeciesPDF("Moments",1); //2000 events


  Fitter.LoadData("ToyData","genSphHarmonic/Toy0.root");
  Fitter.LoadSimulated("ToyData","flatSphHarmonic/Toy0.root","Moments");

  
  gBenchmark->Start("fit ");
  //Fitter.SetMinimiser(new RooMcmcSeq(1000,100,70));
  //Fitter.SetUp().AddFitOption(RooFit::Optimize(1));
  //Here::Go(&Fitter);
  gBenchmark->Stop("fit ");
  gBenchmark->Print("fit ");

  gBenchmark->Start("minuit ");
  Fitter.SetMinimiser(new Minuit2());
  Fitter.SetUp().AddFitOption(RooFit::Optimize(1));
  Proof::Go(&Fitter,1);
  gBenchmark->Stop("minuit ");
  gBenchmark->Print("minuit ");

}
