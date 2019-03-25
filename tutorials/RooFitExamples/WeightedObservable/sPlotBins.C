//Run with 
//root --hsfit sPlotBins.C
{

  sPlot RF;
  RF.SetUp().SetOutDir("outsPlot/");
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

  ///////////////////////////Load Data
  RF.LoadData("MyModel","Data.root");


  Here::Go(&RF);
  //Proof::Go(&RF,4); //run proof with 4 workers
  
  new TCanvas;
  RF.DrawWeighted("M1>>(100,0,10)","Signal");
  //compare to true signal
  FiledTree::Read("MyModel","Data.root")->Tree()->Draw("M1","Sig==1","same");
    
}
