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
  RF.SetUp().FactoryPDF("RooHSEventsHistPDF::Sig(Mmiss,alpha[0,0,20],off[0,-2,2],scale[1,0.8,1.2])");
  RF.SetUp().LoadSpeciesPDF("Sig",1); 

  //////////////////////////////Make background PDF
  RF.SetUp().FactoryPDF("RooHSEventsHistPDF::BG(Mmiss,alphaB[0,0,5],offB[0,0,0],scaleB[1.0,0.8,1.2])");
  RF.SetUp().LoadSpeciesPDF("BG",1);

  ////////////////////////////Make Bins
  RF.Bins().LoadBinVar("Eg",5,3,4);

  ///////////////////////////Load Data
  // RF.LoadData("MyModel","Data.root");
  // RF.LoadSimulated("MyModel","SigData.root", "Sig");
  // RF.LoadSimulated("MyModel","BGData.root", "BG");
  RF.ReloadData("Data.root");
  RF.ReloadSimulated("SigData.root", "Sig");
  RF.ReloadSimulated("BGData.root", "BG");

  gBenchmark->Start("timer");
  RF.RunAll();
  gBenchmark->Stop("timer");
  gBenchmark->Print("timer");

 
  // RF->DrawTreeVar("Mmiss",100,0,10);
  // RF->DrawTreeVar("M1",100,0,10);
  // RF->DrawTreeVar("M2",100,0,10);

}
