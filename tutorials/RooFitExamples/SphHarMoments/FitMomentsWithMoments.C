{



  auto parser=HS::PARSER::SphHarmonicMoments("Moments","CosTh","Phi",4,0,4);
  string sum;
  sum+="H_0_0_0[1]*ReY_0_0(CosTh,Phi,Y_0_0)"; //constant /H_0_0_0== 1, Y_0_0_Re = constant (required for scale)
  sum+="+SUM(L[1|4],M[0|4<L+1]){H_0_L_M[0,-1,1]*ReY_L_M(CosTh,Phi,Y_L_M)}";//H_0_0_0==1 M=0,1,2, for -1,0,1 =>M[-1|1<L+1] or M[-1,0,1<L+1]




  /////////////////////////////////////////////////////////
  ///Generate flat data
  ToyManager Flat;
  Flat.SetUp().SetOutDir("flatMoments/");

  Flat.SetUp().LoadVariable("CosTh[0,-1,1]");
  Flat.SetUp().LoadVariable("Phi[-3.14159,3.14159]");
  Flat.SetUp().LoadFunctionVar("RooConstVar::Val(1)");
  Flat.SetUp().FactoryPDF("RooComponentsPDF::Flat(1,{CosTh,Phi},=Val)");

  Flat.SetUp().LoadSpeciesPDF("Flat",1000000); //2000 events
  Here::Go(&Flat);


  ////////////////////////////////////////////////////////////
  ToyManager Generator;
  Generator.SetUp().SetOutDir("genMoments/");

  Generator.SetUp().LoadVariable("CosTh[-0.5,-1,1]");
  Generator.SetUp().LoadVariable("Phi[0,-3.14159,3.14159]");

  
  Generator.SetUp().ParserPDF(sum,parser);
  Generator.SetUp().SetParVal("H_0_1_0",0.4472);
  Generator.SetUp().SetParVal("H_0_2_0",-0.0286);
  Generator.SetUp().SetParVal("H_0_2_2",-0.2100);
  Generator.SetUp().SetParVal("H_0_3_0",-0.1917);
  Generator.SetUp().SetParVal("H_0_3_2",-0.1750);
  Generator.SetUp().SetParVal("H_0_4_0",-0.0952);
  Generator.SetUp().SetParVal("H_0_4_2",-0.0753);
  
  Generator.SetUp().LoadSpeciesPDF("Moments",100000);
  Generator.LoadSimulated("ToyData","flatMoments/Toy0.root","Moments");  
  Here::Go(&Generator);



  // FitManager Fitter;
  // Fitter.SetUp().SetOutDir("outMoments/");

  // Fitter.SetUp().LoadVariable("CosTh[0,-1,1]");
  // Fitter.SetUp().LoadVariable("Phi[-3.14159,3.14159]");
  // Fitter.SetUp().ParserPDF(sum,parser);

  // Fitter.SetUp().LoadSpeciesPDF("Moments",1); //2000 events


  // Fitter.LoadData("ToyData","genMoments/Toy0.root");
  // Fitter.LoadSimulated("ToyData","flatMoments/Toy0.root","Moments");

  
  // gBenchmark->Start("fit ");
  // Fitter.SetMinimiser(new RooMcmcSeq(10000,5000,1000));
  // Fitter.SetUp().AddFitOption(RooFit::Optimize(1));
  // Here::Go(&Fitter);
  // gBenchmark->Stop("fit ");
  // gBenchmark->Print("fit ");


}
