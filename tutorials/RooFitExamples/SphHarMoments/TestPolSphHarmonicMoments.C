
{


  ToyManager Flat;
  Flat.SetUp().SetOutDir("flatSphHarmonic/");

  Flat.SetUp().LoadVariable("CosTh[0,-1,1]");
  Flat.SetUp().LoadVariable("Phi[-3.14159,3.14159]");

  
 
  Flat.SetUp().LoadFunctionVar("RooHSSphHarmonic::Y_0_0(CosTh,0,0)");
  Flat.SetUp().LoadFunctionVar("RooHSSphHarmonicRe::Y_0_0_Re(CosTh,Phi,Y_0_0)");
  Flat.SetUp().LoadFunctionVar("RooHSSphHarmonicIm::Y_0_0_Im(CosTh,Phi,Y_0_0)");

  Flat.SetUp().FactoryPDF("RooComponentsPDF::Flat(1,{CosTh,Phi},=y00[0,-1,1];Y_0_0_Re:y00i[0,-1,1];Y_0_0_Im)");

  Flat.SetUp().LoadSpeciesPDF("Flat",1000000); //2000 events

  // Create a sample of data
  gBenchmark->Start("flat");
  Here::Go(&Flat);
  gBenchmark->Stop("flat");
  gBenchmark->Print("flat");


  ToyManager Generator;
  Generator.SetUp().SetOutDir("genSphHarmonic/");

  Generator.SetUp().LoadVariable("CosTh[0,-1,1]");
  Generator.SetUp().LoadVariable("Phi[-3.14159,3.14159]");

  
 
  Generator.SetUp().LoadFunctionVar("RooHSSphHarmonic::Y_2_1(CosTh,2,1)");
  Generator.SetUp().LoadFunctionVar("RooHSSphHarmonicRe::Y_2_1_Re(CosTh,Phi,Y_2_1)");
  Generator.SetUp().LoadFunctionVar("RooHSSphHarmonicIm::Y_2_1_Im(CosTh,Phi,Y_2_1)");
  Generator.SetUp().LoadFunctionVar("RooHSSphHarmonic::Y_3_0(CosTh,3,0)");
  Generator.SetUp().LoadFunctionVar("RooHSSphHarmonicRe::Y_3_0_Re(CosTh,Phi,Y_3_0)");
  Generator.SetUp().LoadFunctionVar("RooHSSphHarmonicIm::Y_3_0_Im(CosTh,Phi,Y_3_0)");

  Generator.SetUp().FactoryPDF("RooComponentsPDF::Y2(1,{CosTh,Phi},=y21r[0.5,-1,1];Y_2_1_Re:y21i[0.4,-1,1];Y_2_1_Im:y30r[-0.2,-1,1];Y_3_0_Re:y30i[-0.4,-1,1];Y_3_0_Im)");

  Generator.SetUp().LoadSpeciesPDF("Y2",100000); //2000 events

  //Create a sample of data
  gBenchmark->Start("gen");
  Here::Go(&Generator);
  gBenchmark->Stop("gen");
  gBenchmark->Print("gen");


  FitManager Fitter;
  Fitter.SetUp().SetOutDir("outSphHarmonic/");

  Fitter.SetUp().LoadVariable("CosTh[0,-1,1]");
  Fitter.SetUp().LoadVariable("Phi[0,-3.14159,3.14159]");
 
  Fitter.SetUp().LoadFunctionVar("RooHSSphHarmonic::Y_2_1(CosTh,2,1)");
  Fitter.SetUp().LoadFunctionVar("RooHSSphHarmonicRe::Y_2_1_Re(CosTh,Phi,Y_2_1)");
  Fitter.SetUp().LoadFunctionVar("RooHSSphHarmonicIm::Y_2_1_Im(CosTh,Phi,Y_2_1)");
  Fitter.SetUp().LoadFunctionVar("RooHSSphHarmonic::Y_3_0(CosTh,3,0)");
  Fitter.SetUp().LoadFunctionVar("RooHSSphHarmonicRe::Y_3_0_Re(CosTh,Phi,Y_3_0)");
  Fitter.SetUp().LoadFunctionVar("RooHSSphHarmonicIm::Y_3_0_Im(CosTh,Phi,Y_3_0)");

  Fitter.SetUp().FactoryPDF("RooComponentsPDF::Moments(1,{CosTh,Phi},=y21r[0,-1,1];Y_2_1_Re:y21i[0,-1,1];Y_2_1_Im:y30r[-0.,-1,1];Y_3_0_Re:y30i[-0.,-1,1];Y_3_0_Im)");
 

  //auto configPDF=EXPAND::ComponentsRealSphHarmomic(Fitter.SetUp(),"Moments","CosTh","Phi",3,2);
  //Fitter.SetUp().FactoryPDF(configPDF);
  
  Fitter.SetUp().LoadSpeciesPDF("Moments",1); //2000 events


  Fitter.LoadData("ToyData","genSphHarmonic/Toy0.root");
  Fitter.LoadSimulated("ToyData","flatSphHarmonic/Toy0.root","Moments");

  
  gBenchmark->Start("fit ");
   Fitter.SetMinimiser(new RooMcmcSeq(500,50,100));
  //Fitter.SetUp().AddFitOption(RooFit::NumCPU(4));
  //RF.SetUp().AddFitOption(RooFit::NumCPU(3));
  Fitter.SetUp().AddFitOption(RooFit::Optimize(1));
  Here::Go(&Fitter);
  gBenchmark->Stop("fit ");
  gBenchmark->Print("fit ");

}
