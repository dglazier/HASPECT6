//Run with 
//root --hsfit FitDataTime.C
//We want to remove the random data from our background shape
//To do this we fit on the time peak which is Gaussian for background
//(same distribution as for signal) and flat for random data 
{
  sPlot RF;
  RF.SetUp().SetOutDir("outMMiss2/");
  ///////////////////////////////Load Variables
  RF.SetUp().LoadVariable("Mmiss[0.5,9.5]");
  RooRealVar * var=RF.SetUp().WS().var("Mmiss");
  var->setBins(100); //number of bins used in PDF histogram

  RF.SetUp().SetIDBranchName("fgID");
  
  /////////////////////////////Make Model Signal
  RF.SetUp().FactoryPDF("RooHSEventsHistPDF::Signal(Mmiss,alpha[0,0,20],off[0,-2,2],scale[1,0.8,1.2])");
  RF.SetUp().LoadSpeciesPDF("Signal");

  ////////////////////////////////Additional background
  //Give background weights with WEIGHTS@species,file,weights object name
  RF.SetUp().FactoryPDF("RooHSEventsHistPDF::BG(Mmiss,alphaB[0,0,1],offB[0,0,0],scaleB[1.0,0.8,1.2])WEIGHTS@TimeCoinc,outBGTime/Tweights.root,HSsWeights");
  RF.SetUp().LoadSpeciesPDF("BG");


  ////////////////////////////Make Bins
  RF.Bins().LoadBinVar("Eg",4,3,4);

  ///////////////////////////Load Data
  RF.LoadData("MyModel","Data.root");
  RF.LoadSimulated("MyModel","SigData.root", "Signal"); //Sig = PDFName
  RF.LoadSimulated("MyModel","BGData.root", "BG"); //BG= PDFName

  //////////////////////////Load Weight
  RF.Data().LoadWeights("TimeCoinc","outDataTime/Tweights.root","HSsWeights");


  //Proof::Go(&RF,4);
  Here::Go(&RF);

  auto ft=FiledTree::Read("MyModel","Data.root");
  TCanvas* can = new TCanvas;
  can->Divide(3,1);
  can->cd(1);
  RF.DrawWeighted("Mmiss>>miss(100,0,10)","Signal");
  ft->Tree()->Draw("Mmiss","Sig==1","same");
  can->cd(2);
  RF.DrawWeighted("M1>>m1(100,0,10)","Signal");
  ft->Tree()->Draw("M1","Sig==1","same");
  can->cd(3);
  RF.DrawWeighted("M2>>m2(100,0,10)","Signal");
  ft->Tree()->Draw("M2","Sig==1","same");

  
}
