//Run with 
//root --hsfit FitHSSimple.C
{

    sPlot RF;
  RF.SetUp().SetOutDir("outBins/");
  ///////////////////////////////Load Variables
  RF.SetUp().LoadVariable("Mmiss[0,10]");//should be same name as variable in tree  
  RF.SetUp().SetIDBranchName("fgID");

  /////////////////////////////Make Model Signal
  RF.SetUp().FactoryPDF("Gaussian::Signal( Mmiss, SIMm[6,4,7], SIMw[0.2,0.0001,3] )");
  RF.SetUp().LoadSpeciesPDF("Signal",1);

  ////////////////////////////////Additional background
  RF.SetUp().FactoryPDF("Chebychev::BG(Mmiss,{a0[-0.1,-1,1],a1[0.1,-1,1]})");
  RF.SetUp().LoadSpeciesPDF("BG",1);

  ////////////////////////////Make Bins
  RF.Bins().LoadBinVar("Eg",4,3,4);
  
  ROOT::EnableThreadSafety();
  TH1::AddDirectory(false);
  ROOT::TThreadExecutor pool(4);
  
  static std::string logfile = "mp105_processEntryList.log";
  static RedirectHandle_t gRH;
  gSystem->RedirectOutput(logfile.c_str(), "w", &gRH);

 ///////////////////////////Load Data
  RF.LoadData("MyModel","Data.root");

  auto runFits = [&RF](int idata = 0){
    cout<<"fit "<<idata<<endl;
    RF.Run(idata);
    // RF.Clear(idata);

    return idata;
  };
  
  // for (UInt_t i=0;i<4;i++){
  //   runFits(i);
  // }
  // for (auto i : ROOT::TSeqUL(4)){
  //   runFits();
  // }
  auto ibins = ROOT::TSeqI(2);
  //ROOT::ExecutorUtils::ReduceObjects<TH1F* > redfunc;
  pool.Map(runFits, ibins);
  
  gBenchmark->Stop("bins");
  gBenchmark->Print("bins");

}
