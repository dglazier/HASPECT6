{


  FitManager Fitter;
  Fitter.SetUp().SetOutDir("out2FitAmpsWithMomentsIm/");

  Fitter.SetUp().LoadVariable("CosTh[0,-1,1]");
  Fitter.SetUp().LoadVariable("Phi[-3.14159,3.14159]");

  auto parser=HS::PARSER::SphHarmonicMoments("Moments","CosTh","Phi",4,0,4);
  string sum;
  //Note JPAC paper => I_0 = Sum(L,M){ ( sqrt((2L+1)/4pi) * tau* H_0(L,M)*Y_L^M*} so extra factor sqrt((2L+1)/4pi) to include
  //(A15a) I_0 = Sum(L,M){ (2L+1)/4pi * tau* H_0(L,M)*d^L_M0(theta)*cosMphi }
  //This is given in main.cpp after comment  // the intensities from moments
  //Relationship between d and Y : Y_L^M*  = sqrt((2L+1)/4pi) *d^L_M0(theta)*cosMphi
  //=>d^L_M0(theta)*cosMphi = Y_L^M*sqrt((4pi/(2L+1))
  //So A15a for Y => I_0 = Sum(L,M){ ( sqrt((2L+1)/4pi) * tau* H_0(L,M)*Y_L^M*}
  sum+="K_0*H_0_0_0[1]*ReY_0_0(CosTh,Phi,Y_0_0)"; //constant /H_0_0_0== 1, Y_0_0_Re = constant (required for scale)
  sum+="+SUM(L[1|4],M[0|4<L+1]){K_L*H_0_L_M[0,-1,1]*ReY_L_M(CosTh,Phi,Y_L_M)}";//H_0_0_0==1 M=0,1,2, for -1,0,1 =>M[-1|1<L+1] or M[-1,0,1<L+1]

  //Fitter.SetUp().LoadFormula("K_0=TMath::Sqrt(1.)/TMath::Sqrt(4*TMath::Pi())");
  //Fitter.SetUp().LoadFormula("K_1=TMath::Sqrt(2.+1.)/TMath::Sqrt(4*TMath::Pi())");
  //Fitter.SetUp().LoadFormula("K_2=TMath::Sqrt(2*2.+1.)/TMath::Sqrt(4*TMath::Pi())");
  //Fitter.SetUp().LoadFormula("K_3=TMath::Sqrt(2*3.+1.)/TMath::Sqrt(4*TMath::Pi())");
  //Fitter.SetUp().LoadFormula("K_4=TMath::Sqrt(2*4.+1.)/TMath::Sqrt(4*TMath::Pi())");
  Fitter.SetUp().LoadParameter("K_0[0.28209479]");//=TMath::Sqrt(1.)/TMath::Sqrt(4*TMath::Pi())
  Fitter.SetUp().LoadParameter("K_1[0.48860251]");//=TMath::Sqrt(2.+1.)/TMath::Sqrt(4*TMath::Pi())
  Fitter.SetUp().LoadParameter("K_2[0.63078313]");//=TMath::Sqrt(2*2.+1.)/TMath::Sqrt(4*TMath::Pi())")
  Fitter.SetUp().LoadParameter("K_3[0.74635267]");//=TMath::Sqrt(2*3.+1.)/TMath::Sqrt(4*TMath::Pi())")
  Fitter.SetUp().LoadParameter("K_4[0.84628438]");//=TMath::Sqrt(2*4.+1.)/TMath::Sqrt(4*TMath::Pi())")
  
  Fitter.SetUp().ParserPDF(sum,parser);

  Fitter.SetUp().LoadSpeciesPDF("Moments",1); //2000 events


  Fitter.LoadData("ToyData","genPi2AmpsBothIm/Toy0.root");
  // Fitter.LoadData("ToyData",Generator.GetToyFileNames());
  Fitter.LoadSimulated("ToyData","flatSphHarmonic/Toy0.root","Moments");

  
  gBenchmark->Start("fit ");
  //Fitter.SetMinimiser(new RooMcmcSeq(30000,10000,1000));
  //Fitter.SetUp().AddFitOption(RooFit::Optimize(1));
  Here::Go(&Fitter);
  gBenchmark->Stop("fit ");
  gBenchmark->Print("fit ");


}
