
{


  ToyManager Flat;
  Flat.SetUp().SetOutDir("flatSphHarmonic/");

  Flat.SetUp().LoadVariable("CosTh[0,-1,1]");
  Flat.SetUp().LoadVariable("Phi[-3.14159,3.14159]");

  
 
  Flat.SetUp().LoadFunctionVar("RooRealSphHarmonic::Y_0_0(CosTh,Phi,0,0)");

  Flat.SetUp().FactoryPDF("RooComponentsPDF::Flat(1,{CosTh,Phi},=y00[0,-1,1];Y_0_0)");

  Flat.SetUp().LoadSpeciesPDF("Flat",1000000); //2000 events

  //Create a sample of data
  // Here::Go(&Flat);


  ToyManager Generator;
  Generator.SetUp().SetOutDir("genSphHarmonic/");

  Generator.SetUp().LoadVariable("CosTh[0,-1,1]");
  Generator.SetUp().LoadVariable("Phi[-3.14159,3.14159]");

  
 
  Generator.SetUp().LoadFunctionVar("RooRealSphHarmonic::Y_2_1(CosTh,Phi,2,1)");
  Generator.SetUp().LoadFunctionVar("RooRealSphHarmonic::Y_3_0(CosTh,Phi,3,0)");

  Generator.SetUp().FactoryPDF("RooComponentsPDF::Y2(1,{CosTh,Phi},=y21[0.5,-1,1];Y_2_1:y30[-0.2,-1,1];Y_3_0)");

  Generator.SetUp().LoadSpeciesPDF("Y2",100000); //2000 events

  //Create a sample of data
  //Here::Go(&Generator);


  FitManager Fitter;
  Fitter.SetUp().SetOutDir("outSphHarmonic/");

  Fitter.SetUp().LoadVariable("CosTh[0,-1,1]");
  Fitter.SetUp().LoadVariable("Phi[0,-3.14159,3.14159]");
 
  //Fitter.SetUp().LoadFunctionVar("RooRealSphHarmonic::Y_2_1(CosTh,Phi,2,1)");
  // Fitter.SetUp().LoadFunctionVar("RooRealSphHarmonic::Y_3_0(CosTh,Phi,3,0)");
  // Fitter.SetUp().LoadFunctionVar("RooRealSphHarmonic::Y_1_0(CosTh,Phi,1,0)");

  // Fitter.SetUp().FactoryPDF("RooComponentsPDF::Y2(1,{CosTh,Phi},=y21[0.,-1,1];Y_2_1:y30[-0.,-1,1];Y_3_0:y10[-0.,-1,1];Y_1_0)");


   auto configPDF=EXPAND::ComponentsRealSphHarmomic(Fitter.SetUp(),"Moments","CosTh","Phi",3,2);
   Fitter.SetUp().FactoryPDF(configPDF);
  
  Fitter.SetUp().LoadSpeciesPDF("Moments",1); //2000 events


  Fitter.LoadData("ToyData","genSphHarmonic/Toy0.root");
  Fitter.LoadSimulated("ToyData","flatSphHarmonic/Toy0.root","Moments");

  
  gBenchmark->Start("fit ");
  // RF.SetMinimiser(new RooMcmcSeq(1000,20,10));
  //Fitter.SetUp().AddFitOption(RooFit::NumCPU(4));
  //RF.SetUp().AddFitOption(RooFit::NumCPU(3));
  Fitter.SetUp().AddFitOption(RooFit::Optimize(1));
  Here::Go(&Fitter);
  gBenchmark->Stop("fit ");
  gBenchmark->Print("fit ");

}
