
{


  //Define the Spherical harmonic fit function
  //First Load all spherical harmonic moment functions needed

  //PolarisedSphHarmonicMoments("NAME","CosTh","Phi","PolPhi","Pol",LMAX,MMIN,MMAX);
  
  auto parser=HS::PARSER::PolarisedSphHarmonicMoments("Moments","CosTh","Phi","PolPhi","Pol",4,0,3);

  //Now specify the specific spherical harmonics for this fit
  //Note the factor tau from JPAC paper is cared for in
  //PolarisedSphHarmonicMoments function
  string sum;
  sum+="K_0*H_0_0_0[1]*ReY_0_0(CosTh,Phi,Y_0_0)"; 
  sum+="+SUM(L[1|4],M[0|3<L+1]){K_L*H_0_L_M[0,-1,1]*ReY_L_M(CosTh,Phi,Y_L_M)}";
  sum+="+SUM(L[0|4],M[0|3<L+1]){K_L*H_1_L_M[0,-1,1]*ReY_L_M(CosTh,Phi,Y_L_M)*COS2PHI}";
  sum+="+SUM(L[1|4],M[1|3<L+1]){K_L*H_2_L_M[0,-1,1]*ImY_L_M(CosTh,Phi,Y_L_M)*SIN2PHI}";


  //Generate flat MC data for normalisation integral
  ToyManager Flat;
  Flat.SetUp().SetOutDir("flatSphHarmonic/");

  Flat.SetUp().LoadVariable("CosTh[0,-1,1]");
  Flat.SetUp().LoadVariable("Phi[-3.14159,3.14159]");
  Flat.SetUp().LoadVariable("PolPhi[-3.14159,3.14159]");
  Flat.SetUp().LoadVariable("Pol[0.5,0.2,0.6]");

  
  Flat.SetUp().LoadFunctionVar("RooConstVar::Val(1)");
  Flat.SetUp().FactoryPDF("RooComponentsPDF::Flat(1,{CosTh,Phi,PolPhi,Pol},=Val)");

  Flat.SetUp().LoadSpeciesPDF("Flat",100000); //2000 events

  // Create a sample of data
  gBenchmark->Start("flat");
  Here::Go(&Flat);
  gBenchmark->Stop("flat");
  gBenchmark->Print("flat");



  //Generate pseudo data for fitting
  ToyManager Generator(1);
  Generator.SetUp().SetOutDir("genSphHarmonic/");

  Generator.SetUp().LoadVariable("CosTh[0,-1,1]");
  Generator.SetUp().LoadVariable("Phi[-3.14159,3.14159]");
  Generator.SetUp().LoadVariable("PolPhi[-3.14159,3.14159]");
  Generator.SetUp().LoadVariable("Pol[0.5,0.2,0.6]");

  //Create normalisation factors
  Generator.SetUp().LoadParameter("K_0[0.28209479]");//=TMath::Sqrt(1.)/TMath::Sqrt(4*TMath::Pi())
  Generator.SetUp().LoadParameter("K_1[0.48860251]");//=TMath::Sqrt(2.+1.)/TMath::Sqrt(4*TMath::Pi())
  Generator.SetUp().LoadParameter("K_2[0.63078313]");//=TMath::Sqrt(2*2.+1.)/TMath::Sqrt(4*TMath::Pi())")
  Generator.SetUp().LoadParameter("K_3[0.74635267]");//=TMath::Sqrt(2*3.+1.)/TMath::Sqrt(4*TMath::Pi())")
  Generator.SetUp().LoadParameter("K_4[0.84628438]");//=TMath::Sqrt(2*4.+1.)/TMath::Sqrt(4*TMath::Pi())")
 
  //Use ParserPDF rather than FactorPDF
  Generator.SetUp().ParserPDF(sum,parser);

  Generator.SetUp().LoadSpeciesPDF("Moments",10000); //2000 events
  Generator.SetUp().WS().var("H_0_3_2")->setVal(0.1);
  Generator.SetUp().WS().var("H_0_2_0")->setVal(-0.1);
  Generator.SetUp().WS().var("H_1_1_1")->setVal(0.03);
  Generator.SetUp().WS().var("H_1_2_2")->setVal(-0.1);
  Generator.SetUp().WS().var("H_2_1_1")->setVal(-0.03);
  Generator.SetUp().WS().var("H_2_2_2")->setVal(0.1);

  //Create a sample of data
  gBenchmark->Start("gen");
  Here::Go(&Generator);
  gBenchmark->Stop("gen");
  gBenchmark->Print("gen");



  //Now create fitter using the same Moments configuration
  //= the string sum
  
  FitManager Fitter;
  Fitter.SetUp().SetOutDir("outSphHarmonicParserDoubleFit3/");

  Fitter.SetUp().LoadVariable("CosTh[0,-1,1]");
  Fitter.SetUp().LoadVariable("Phi[-3.14159,3.14159]");
  Fitter.SetUp().LoadVariable("PolPhi[-3.14159,3.14159]");
  Fitter.SetUp().LoadVariable("Pol[0.5,0.2,0.6]");
 
 
  //Create normalisation factors
  Fitter.SetUp().LoadParameter("K_0[0.28209479]");//=TMath::Sqrt(1.)/TMath::Sqrt(4*TMath::Pi())
  Fitter.SetUp().LoadParameter("K_1[0.48860251]");//=TMath::Sqrt(2.+1.)/TMath::Sqrt(4*TMath::Pi())
  Fitter.SetUp().LoadParameter("K_2[0.63078313]");//=TMath::Sqrt(2*2.+1.)/TMath::Sqrt(4*TMath::Pi())")
  Fitter.SetUp().LoadParameter("K_3[0.74635267]");//=TMath::Sqrt(2*3.+1.)/TMath::Sqrt(4*TMath::Pi())")
  Fitter.SetUp().LoadParameter("K_4[0.84628438]");//=TMath::Sqrt(2*4.+1.)/TMath::Sqrt(4*TMath::Pi())")

  Fitter.SetUp().ParserPDF(sum,parser);

  Fitter.SetUp().LoadSpeciesPDF("Moments",1); //2000 events


  //  Fitter.LoadData("ToyData","genSphHarmonic/Toy0.root");
  Fitter.LoadData("ToyData",Generator.GetToyFileNames());
  Fitter.LoadSimulated("ToyData","flatSphHarmonic/Toy0.root","Moments");

  
  gBenchmark->Start("fit ");
  Fitter.SetMinimiser(new RooMcmcSeq(2000,1000,50));
  Fitter.SetUp().AddFitOption(RooFit::Optimize(1));
  //   Here::Go(&Fitter);
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
