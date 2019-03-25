//Run with 
//root --hsfit FitObsBins.C
{

  FitManager RF;
  RF.SetUp().SetOutDir("/work/Dropbox/HaSpect/dev/HASPECT6/tutorials/RooFitExamples/WeightedObservable/outObs/");
  ///////////////////////////////Load Variables
  RF.SetUp().LoadVariable("Phi[-180,180]"); 
  RF.SetUp().LoadVariable("Pol[0,1]"); 
  RF.SetUp().LoadCategory("PolState[Polp=1,Polm=-1]"); 
  RF.SetUp().SetIDBranchName("fgID");

  /////////////////////////////Make Model Signal
  RF.SetUp().FactoryPDF("PhiAsymmetryPDF::SigAsym( Phi,Pol,PolState,A[0,-1,1],B[0,-1,1] )");
  RF.SetUp().LoadSpeciesPDF("SigAsym",1);

  ////////////////////////////Make Bins
  //RF.Bins().LoadBinVar("Eg",4,3,4);
   
  ///////////////////////////Load Data
  //RF.Data().BootStrap(20);
  RF.LoadData("MyModel","/work/Dropbox/HaSpect/dev/HASPECT6/tutorials/RooFitExamples/WeightedObservable/Data.root");
  //RF.LoadSimulated("MyModel","MC.root","SigAsym");
  
  //////////////////////////Load Weights
  RF.Data().LoadWeights("Signal","outsPlot/Tweights.root");
  
  //  Here::Go(&RF);
  Proof::Go(&RF,10);
 
}
