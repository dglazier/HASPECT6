//run with root --hsfit PolSphHarmonicMoments0.C
{


  //Create flat data for MC integration
  ToyManager Flat;
  Flat.SetUp().SetOutDir("flatSphHarmonic/");

  //polarised fit variables
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

  //////////////////////////////////////////////////////////////////////
  //////Create pseudo data
  ////// You can try different moments below
  ToyManager Generator(1);
  Generator.SetUp().SetOutDir("genSphHarmonic/");

  Generator.SetUp().LoadVariable("CosTh[0,-1,1]");
  Generator.SetUp().LoadVariable("Phi[-3.14159,3.14159]");
  Generator.SetUp().LoadVariable("PolPhi[-3.14159,3.14159]");
  Generator.SetUp().LoadVariable("Pol[0.5,0.2,0.6]");

  //Configure the polarised moments, the last 2 numbers give the Lmax and Mmax
  //Moments is the name the PDF will take
  //All Spherical harmonics and Cos2PolPhi functions are created here
  auto configGenPDF=HS::FIT::EXPAND::ComponentsPolSphHarmonic(Generator.SetUp(),"Moments","CosTh","Phi","PolPhi","Pol",3,2);


  //Give some dummy values need to be quite small <1/(sqrt(4pi))
  Generator.SetUp().WS().var("H0_3_2")->setVal(0.06);
  Generator.SetUp().WS().var("H0_2_0")->setVal(-0.1);
  Generator.SetUp().WS().var("H1_1_1")->setVal(0.07);
  Generator.SetUp().WS().var("H1_2_2")->setVal(-0.1);
  Generator.SetUp().WS().var("H2_1_1")->setVal(-0.08);
  Generator.SetUp().WS().var("H2_2_2")->setVal(0.1);

  //create and load PDF into the intensity function
  Generator.SetUp().FactoryPDF(configGenPDF);
  Generator.SetUp().LoadSpeciesPDF("Moments",10000); //2000 events

  //Create a sample of data
  gBenchmark->Start("gen");
  Here::Go(&Generator);
  gBenchmark->Stop("gen");
  gBenchmark->Print("gen");


  /////////////////////////////////////////////////////////////////
  ////Fit the data
  FitManager Fitter;
  Fitter.SetUp().SetOutDir("outSphHarmonic/");

  Fitter.SetUp().LoadVariable("CosTh[0,-1,1]");
  Fitter.SetUp().LoadVariable("Phi[-3.14159,3.14159]");
  Fitter.SetUp().LoadVariable("PolPhi[-3.14159,3.14159]");
  Fitter.SetUp().LoadVariable("Pol[0.5,0.2,0.6]");
 
  auto configFitPDF=HS::FIT::EXPAND::ComponentsPolSphHarmonic(Fitter.SetUp(),"Moments","CosTh","Phi","PolPhi","Pol",3,2);


  Fitter.SetUp().FactoryPDF(configGenPDF);

  Fitter.SetUp().LoadSpeciesPDF("Moments",1); //2000 events


  //Get the generated data
  Fitter.LoadData("ToyData","genSphHarmonic/Toy0.root");
  //flat data for mc integration
  Fitter.LoadSimulated("ToyData","flatSphHarmonic/Toy0.root","Moments");


  //could try MCMC
  gBenchmark->Start("fit ");
  Fitter.SetMinimiser(new RooMcmcSeq(2000,1000,50));
  Fitter.SetUp().AddFitOption(RooFit::Optimize(1));
  //Here::Go(&Fitter); //try MCMC comment in here
  gBenchmark->Stop("fit ");
  gBenchmark->Print("fit ");


  // Or just Minuit
  gBenchmark->Start("minuit ");
  Fitter.SetMinimiser(new Minuit2());
  Fitter.SetUp().AddFitOption(RooFit::Optimize(1));
  Here::Go(&Fitter);
  gBenchmark->Stop("minuit ");
  gBenchmark->Print("minuit ");

}
