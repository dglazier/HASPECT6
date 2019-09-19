
{


  //  Loader::Compile("RooHSSphHarmonic.C");
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
  Here::Go(&Flat);
  gBenchmark->Stop("flat");
  gBenchmark->Print("flat");


  ToyManager Generator(1);
  Generator.SetUp().SetOutDir("genSphHarmonic/");

  Generator.SetUp().LoadVariable("CosTh[0,-1,1]");
  Generator.SetUp().LoadVariable("Phi[-3.14159,3.14159]");
  Generator.SetUp().LoadVariable("PolPhi[-3.14159,3.14159]");
  Generator.SetUp().LoadVariable("Pol[0.5,0.2,0.6]");
 
  auto configGenPDF=HS::FIT::EXPAND::ComponentsPolSphHarmonic(Generator.SetUp(),"Moments","CosTh","Phi","PolPhi","Pol",3,2);
  //  Generator.SetUp().WS().var("H0_0_0")->setVal(1);
  Generator.SetUp().WS().var("H0_3_2")->setVal(0.06);
  Generator.SetUp().WS().var("H0_2_0")->setVal(-0.1);
  Generator.SetUp().WS().var("H1_1_1")->setVal(0.07);
  Generator.SetUp().WS().var("H1_2_2")->setVal(-0.1);
  Generator.SetUp().WS().var("H2_1_1")->setVal(-0.08);
  Generator.SetUp().WS().var("H2_2_2")->setVal(0.1);
  
  Generator.SetUp().FactoryPDF(configGenPDF);

  Generator.SetUp().LoadSpeciesPDF("Moments",10000); //2000 events

  //Create a sample of data
  gBenchmark->Start("gen");
  Here::Go(&Generator);
  gBenchmark->Stop("gen");
  gBenchmark->Print("gen");


  FitManager Fitter;
  Fitter.SetUp().SetOutDir("outSphHarmonicParserDoubleFit3/");

  Fitter.SetUp().LoadVariable("CosTh[0,-1,1]");
  Fitter.SetUp().LoadVariable("Phi[-3.14159,3.14159]");
  Fitter.SetUp().LoadVariable("PolPhi[-3.14159,3.14159]");
  Fitter.SetUp().LoadVariable("Pol[0.5,0.2,0.6]");
 
  auto configFitPDF=HS::FIT::EXPAND::ComponentsPolSphHarmonic(Fitter.SetUp(),"Moments","CosTh","Phi","PolPhi","Pol",3,2);


  Fitter.SetUp().FactoryPDF(configGenPDF);

  Fitter.SetUp().LoadSpeciesPDF("Moments",1); //2000 events


  //  Fitter.LoadData("ToyData","genSphHarmonic/Toy0.root");
  Fitter.LoadData("ToyData",Generator.GetToyFileNames());
  Fitter.LoadSimulated("ToyData","flatSphHarmonic/Toy0.root","Moments");

  
  gBenchmark->Start("fit ");
  Fitter.SetMinimiser(new RooMcmcSeq(2000,1000,50));
  Fitter.SetUp().AddFitOption(RooFit::Optimize(1));
  // Here::Go(&Fitter);
  gBenchmark->Stop("fit ");
  gBenchmark->Print("fit ");

  gBenchmark->Start("minuit ");
  Fitter.SetMinimiser(new Minuit2());
  Fitter.SetUp().AddFitOption(RooFit::Optimize(1));
  Here::Go(&Fitter);
  gBenchmark->Stop("minuit ");
  gBenchmark->Print("minuit ");

}
//Fit2 Minuit 40s, MCMC 2000 260s 18% (found in 200)
//Fit3 Minuit 1475 calls 130s, MCMC 2000 360 18%
