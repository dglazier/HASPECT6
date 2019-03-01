//root --hsfit  FitHSMCModel.C
{

  sPlot RF;
  RF.SetUp().SetOutDir("outBins/");
  ///////////////////////////////Load Variables
  RF.SetUp().LoadVariable("Mmiss[0,9.5]");//should be same name as variable in tree
  RF.SetUp().LoadAuxVar("Eg[0,10]");
  // RF.SetUp().AddCut("Eg<3.2");

  RF.SetUp().SetIDBranchName("fgID");


  //////////////////////////////Make signal PDF
  RF.SetUp().FactoryPDF("RooHSEventsHistPDF::Signal(Mmiss,alpha[0,0,20],off[0,-2,2],scale[1,0.8,1.2])");
  RF.SetUp().LoadSpeciesPDF("Signal",1); 

  //////////////////////////////Make background PDF
  RF.SetUp().FactoryPDF("RooHSEventsHistPDF::BG(Mmiss,alphaB[0,0,5],offB[0,0,0],scaleB[1.0,0.8,1.2])");
  RF.SetUp().LoadSpeciesPDF("BG",1);

  ////////////////////////////Make Bins
  RF.Bins().LoadBinVar("Eg",5,3,4);

  ///////////////////////////Load Data
  RF.LoadData("MyModel","Data.root");
  RF.LoadSimulated("MyModel","SigData.root", "Signal");
  RF.LoadSimulated("MyModel","BGData.root", "BG");
  //RF.ReloadData("Data.root");
  //RF.ReloadSimulated("SigData.root", "Signal");
  //RF.ReloadSimulated("BGData.root", "BG");

  gBenchmark->Start("timer");
  Here::Go(&RF);
  //Proof::Go(&RF,4); //run proof with 4 workers
  gBenchmark->Stop("timer");
  gBenchmark->Print("timer");

  auto filetree=RF.WeightedTree("Signal");
  filetree->Tree()->Draw("Mmiss>>(100,0,10)","Signal");

}
