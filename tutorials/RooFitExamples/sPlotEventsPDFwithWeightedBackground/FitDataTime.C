//Run with 
//root --hsfit FitDataTime.C
//We want to remove the random data from our background shape
//To do this we fit on the time peak which is Gaussian for background
//(same distribution as for signal) and flat for random data 
{
  sPlot RF;
  RF.SetUp().SetOutDir("outDataTime/");
  ///////////////////////////////Load Variables
  RF.SetUp().LoadVariable("Time[-10,10]");

  RF.SetUp().SetIDBranchName("fgID");
  
  /////////////////////////////Make Model Signal
  RF.SetUp().FactoryPDF("Gaussian::TimeCoinc( Time, mean[0,-10,10], SIMw[1,0.0001,10] )");
  RF.SetUp().LoadSpeciesPDF("TimeCoinc");

  ////////////////////////////////Additional background
  RF.SetUp().FactoryPDF("Chebychev::Random(Time,{a0[0.1,-0.4,0.4],a1[-0.1,-0.3,0.3]})");
  RF.SetUp().LoadSpeciesPDF("Random");


  ////////////////////////////Make Bins
  RF.Bins().LoadBinVar("Eg",4,3,4);

  ///////////////////////////Load Data
  RF.LoadData("MyModel","Data.root");

  Here::Go(&RF);

 TCanvas* can = new TCanvas;
 can->Divide(3,1);
 can->cd(1);
 RF.DrawWeighted("Mmiss>>miss(100,0,10)","TimeCoinc");
 can->cd(2);
 RF.DrawWeighted("M1>>m1(100,0,10)","TimeCoinc");
 can->cd(3);
 RF.DrawWeighted("M2>>m2(100,0,10)","TimeCoinc");
}
