{

  sPlot RF;
  RF.SetUp().SetOutDir("/work/Dropbox/HaSpect/dev/HASPECT6/RooFitExamples2/sPlotEventsPDF/outBoot/");
  ///////////////////////////////Load Variables
  RF.SetUp().LoadVariable("Mmiss[0,9.5]");//should be same name as variable in tree
  RF.SetUp().LoadAuxVar("Eg[0,10]");
  // RF.SetUp().AddCut("Eg<3.2");

  RF.SetUp().SetIDBranchName("fgID");

   //////////////////////////////Make signal PDF
  RF.SetUp().FactoryPDF("RooHSEventsHistPDF::Signal(Mmiss,alpha[0,0,2],off[0,-2,2],scale[1,0.8,1.2])");
  RF.SetUp().LoadSpeciesPDF("Signal",1); 

  //////////////////////////////Make background PDF
  RF.SetUp().FactoryPDF("RooHSEventsHistPDF::BG(Mmiss,alphaB[0,0,5],offB[0,0,0],scaleB[1.0,0.8,1.2])");
  RF.SetUp().LoadSpeciesPDF("BG",1);

  ////////////////////////////Make Bins
  RF.Bins().LoadBinVar("Eg",1,3,4);

  ///////////////////////////Load Data
  RF.Data().BootStrap(20);
  RF.LoadData("MyModel","/work/Dropbox/HaSpect/dev/HASPECT6/RooFitExamples2/sPlotEventsPDF/Data.root");
  RF.LoadSimulated("MyModel","/work/Dropbox/HaSpect/dev/HASPECT6/RooFitExamples2/sPlotEventsPDF/SigData.root", "Signal");
  RF.LoadSimulated("MyModel","/work/Dropbox/HaSpect/dev/HASPECT6/RooFitExamples2/sPlotEventsPDF/BGData.root", "BG");

  // RF.BootStrapData(2,"MyModel","/work/Dropbox/HaSpect/dev/HASPECT6/RooFitExamples2/sPlotEventsPDF/Data.root");

  Proof::Go(&RF,20);
  //Here::Go(&RF);
}
