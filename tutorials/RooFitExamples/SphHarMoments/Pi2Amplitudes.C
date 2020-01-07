{


  HS::PARSER::ComponentsPdfParser Pi2Amps("Amplitudes");
  Pi2Amps.SetVars("CosTh,Phi");
  
  Pi2Amps.AddComplexFunctionTemplate("RooHSSphHarmonic","Y_*_*(*,*,*,*)");
  //Pi2Amps.AddComplexFunctionTemplate("RooHSSphHarmonic","Y_*_*CONJ(*,*,*,*)");
  //Pi2Amps.AddComplexFunctionTemplate("RooHSSphHarmonic","Y_*_*_Conj(*,*,*,*)");
   
  // string sum = Pi2Amps.ReplaceComplexSumSqd("SUM(L[0|2],M[-1|1<L+1>-L-1]){h_L_M[0,-1,1][0,-1,1]*Y_L_M(CosTh,Phi,L,M)}^2");
  // string sum = Pi2Amps.ReplaceComplexSumSqd("SUM(L[0|2],M[-1|1<L+1>-L-1]){h_L_M[0,-1,1][0,-1,1]*Y_L_M^CONJ(CosTh,Phi,L,M)}^2");
  string sum = Pi2Amps.ReplaceComplexSumSqd("SUM(L[0|2],M[-1|1<L+1>-L-1]){h_L_M[0,-1,1][0,-1,1]*Y_L_M(CosTh,Phi,L,M)}^2 + SUM(L[0|2],M[-1|1<L+1>-L-1]){h_L_M[0,-1,1][0,-1,1]*Y_L_M^CONJ(CosTh,Phi,L,M)}^2 ");
  // string sum = "SUM(L[0|2],M[-1|1<L+1>-L-1])
  //                       {h_L_M[0,-1,1][0,-1,1]*Y_L_M(CosTh,Phi,L,M)}^2 
  //              + SUM(L[0|2],M[-1|1<L+1>-L-1])
  //                       {h_L_M[0,-1,1][0,-1,1]*Y_L_M^CONJ(CosTh,Phi,L,M)}^2 ";
   
  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_2_1_h_2_1(Imh_2_1,Reh_2_1,Reh_2_1,Imh_2_1,-1,-1)*_CSST3_Y_2_1_Y_2_1(ImY_2_1,ReY_2_1,ReY_2_1,ImY_2_1,-1,-1)","");
  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_2_0_h_2_0(Imh_2_0,Reh_2_0,Reh_2_0,Imh_2_0,-1,-1)*_CSST3_Y_2_0_Y_2_0(ImY_2_0,ReY_2_0,ReY_2_0,ImY_2_0,-1,-1)","");
  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_2_-1_h_2_-1(Imh_2_-1,Reh_2_-1,Reh_2_-1,Imh_2_-1,-1,-1)*_CSST3_Y_2_-1_Y_2_-1(ImY_2_-1,ReY_2_-1,ReY_2_-1,ImY_2_-1,-1,-1)","");
  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_1_1_h_1_1(Imh_1_1,Reh_1_1,Reh_1_1,Imh_1_1,-1,-1)*_CSST3_Y_1_1_Y_1_1(ImY_1_1,ReY_1_1,ReY_1_1,ImY_1_1,-1,-1)","");
  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_1_0_h_1_0(Imh_1_0,Reh_1_0,Reh_1_0,Imh_1_0,-1,-1)*_CSST3_Y_1_0_Y_1_0(ImY_1_0,ReY_1_0,ReY_1_0,ImY_1_0,-1,-1)","");
  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_1_-1_h_1_-1(Imh_1_-1,Reh_1_-1,Reh_1_-1,Imh_1_-1,-1,-1)*_CSST3_Y_1_-1_Y_1_-1(ImY_1_-1,ReY_1_-1,ReY_1_-1,ImY_1_-1,-1,-1)","");
  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_0_0_h_0_0(Imh_0_0,Reh_0_0,Reh_0_0,Imh_0_0,-1,-1)*_CSST3_Y_0_0_Y_0_0(ImY_0_0,ReY_0_0,ReY_0_0,ImY_0_0,-1,-1)","");


  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_2_1_h_2_1(Imh_2_1,Reh_2_1,Reh_2_1,Imh_2_1,-1,-1)*_CSST3_Y_2_1_Y_2_1_CONJ(CoImY_2_1,ReY_2_1,ReY_2_1,CoImY_2_1,-1,-1)","");
  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_2_0_h_2_0(Imh_2_0,Reh_2_0,Reh_2_0,Imh_2_0,-1,-1)*_CSST3_Y_2_0_Y_2_0_CONJ(CoImY_2_0,ReY_2_0,ReY_2_0,CoImY_2_0,-1,-1)","");
  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_2_-1_h_2_-1(Imh_2_-1,Reh_2_-1,Reh_2_-1,Imh_2_-1,-1,-1)*_CSST3_Y_2_-1_Y_2_-1_CONJ(CoImY_2_-1,ReY_2_-1,ReY_2_-1,CoImY_2_-1,-1,-1)","");
  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_1_1_h_1_1(Imh_1_1,Reh_1_1,Reh_1_1,Imh_1_1,-1,-1)*_CSST3_Y_1_1_Y_1_1_CONJ(CoImY_1_1,ReY_1_1,ReY_1_1,CoImY_1_1,-1,-1)","");
  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_1_-1_h_1_-1(Imh_1_-1,Reh_1_-1,Reh_1_-1,Imh_1_-1,-1,-1)*_CSST3_Y_1_-1_Y_1_-1_CONJ(CoImY_1_-1,ReY_1_-1,ReY_1_-1,CoImY_1_-1,-1,-1)","");
  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_1_0_h_1_0(Imh_1_0,Reh_1_0,Reh_1_0,Imh_1_0,-1,-1)*_CSST3_Y_1_0_Y_1_0_CONJ(CoImY_1_0,ReY_1_0,ReY_1_0,CoImY_1_0,-1,-1)","");

  sum=HS::PARSER::StringReplaceAll(sum,"+_CSST3_h_0_0_h_0_0(Imh_0_0,Reh_0_0,Reh_0_0,Imh_0_0,-1,-1)*_CSST3_Y_0_0_Y_0_0_CONJ(CoImY_0_0,ReY_0_0,ReY_0_0,CoImY_0_0,-1,-1)","");

  /////////////////////////////////////////////////////////
  ///Generate flat data
  ToyManager Flat;
  Flat.SetUp().SetOutDir("flatPi2Amps/");

  Flat.SetUp().LoadVariable("CosTh[0,-1,1]");
  Flat.SetUp().LoadVariable("Phi[-3.14159,3.14159]");
  Flat.SetUp().LoadFunctionVar("RooConstVar::Val(1)");
  Flat.SetUp().FactoryPDF("RooComponentsPDF::Flat(1,{CosTh,Phi},=Val)");

  Flat.SetUp().LoadSpeciesPDF("Flat",100000); //2000 events
  //Here::Go(&Flat);

 /////////////////////////////////////////////////////////
 ///Generate model events
  ToyManager Generator;
  Generator.SetUp().SetOutDir("genPi2AmpsBothImTest/");

  Generator.SetUp().LoadVariable("CosTh[-0.5,-1,1]");
  Generator.SetUp().LoadVariable("Phi[0,-3.14159,3.14159]");
  //Fitter.SetUp().LoadVariable("PolPhi[-3.14159,3.14159]");
  //Fitter.SetUp().LoadVariable("Pol[0.5,0.2,0.6]");

  
  Generator.SetUp().ParserPDF(sum,Pi2Amps);

  Double_t val =1;
  Double_t normVal=val/9*sqrt(val);
  Generator.SetUp().SetParVal("Reh_0_0",0);
  Generator.SetUp().SetParVal("Imh_1_1",val);
  Generator.SetUp().SetParVal("Reh_1_1",val);
  Generator.SetUp().SetParVal("Imh_1_-1",0);
  Generator.SetUp().SetParVal("Reh_1_-1",val);
  Generator.SetUp().SetParVal("Reh_2_1",val);
  Generator.SetUp().SetParVal("Imh_2_1",0);
  Generator.SetUp().SetParVal("Reh_2_-1",val);
  Generator.SetUp().SetParVal("Imh_2_-1",0);
  //Generator.SetUp().SetParVal("Reh_2_2",-0.3);
  //Generator.SetUp().SetParVal("Imh_2_2",0.2);
  //  Generator.SetUp().SetParVal("Reh_2_0",0.3);

  Generator.SetUp().LoadSpeciesPDF("Amplitudes",10000);
  Generator.LoadSimulated("ToyData","flatPi2Amps/Toy0.root","Amplitudes");  
 Here::Go(&Generator);

  //auto Fitter=Generator.Fitter();
  //Fitter->SetUp().AddFitOption(RooFit::Optimize(1));
  //Here::Go(Fitter);
  ///////////////////////////////////////////////////////////
  FitManager Fitter;
  Fitter.SetUp().SetOutDir("outPi2Amps/");

  Fitter.SetUp().LoadVariable("CosTh[0,-1,1]");
  Fitter.SetUp().LoadVariable("Phi[-3.14159,3.14159]");

  Fitter.SetUp().ParserPDF(sum,Pi2Amps);
  Fitter.SetUp().LoadSpeciesPDF("Amplitudes",1);

  Fitter.LoadData("ToyData","genPi2AmpsBothImTest/Toy0.root","Amplitudes");
  Fitter.LoadSimulated("ToyData","flatPi2Amps/Toy0.root","Amplitudes");
  
  Fitter.SetMinimiser(new RooMcmcSeq(20000,1000,50));
  //Fitter.SetUp().AddFitOption(RooFit::Optimize(1));
  Here::Go(&Fitter);

}
