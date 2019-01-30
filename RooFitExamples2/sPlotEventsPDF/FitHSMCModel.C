//root --hsfit  FitHSMCModel.C
{
  //RooFit::Minimizer("Minuit");
  //RooFit::PrintLevel(1) ;
  // RooAbsData::setDefaultStorageType(RooAbsData::Tree);//seems to use less memory

  sPlot RF;
  RF.SetUp().SetOutDir("out/");
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

  
  ///////////////////////////Load Data
  RF.LoadData("MyModel","/work/Dropbox/HaSpect/dev/HASPECT6/RooFitExamples/newEventsPDF/Data.root");
  RF.LoadSimulated("MyModel","/work/Dropbox/HaSpect/dev/HASPECT6/RooFitExamples/newEventsPDF/SigData.root", "Sig");
  RF.LoadSimulated("MyModel","/work/Dropbox/HaSpect/dev/HASPECT6/RooFitExamples/newEventsPDF/BGData.root", "BG");

  gBenchmark->Start("timer");
  RF.RunAll();
  gBenchmark->Stop("timer");
  gBenchmark->Print("timer");

 
  // RF->DrawTreeVar("Mmiss",100,0,10);
  // RF->DrawTreeVar("M1",100,0,10);
  // RF->DrawTreeVar("M2",100,0,10);

}
