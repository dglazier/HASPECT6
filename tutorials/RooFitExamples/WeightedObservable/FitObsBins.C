//Run with 
//root --hsfit FitObsBins.C
{
 
  Loader::Compile("PhiAsymmetryPDF.cxx");
  
  //get the current directory where the data is (PROOF needs full path)
  TString pwd = TString(gSystem->Getenv("PWD"))+"/";
  
  FitManager RF;
  RF.SetUp().SetOutDir(pwd+"outObs/");
  ///////////////////////////////Load Variables
  RF.SetUp().LoadVariable("Phi[-180,180]"); 
  RF.SetUp().LoadVariable("Pol[0,1]"); 
  RF.SetUp().LoadCategory("PolState[Polp=1,Polm=-1]"); 
  //RF.SetUp().LoadAuxVar("AUX[0,300]"); //Load Aux Var, limits used as cut 
  RF.SetUp().SetIDBranchName("fgID");

  ///////////////////////////////Make additional cut on an AuxVar
  //RF.SetUp().AddCut("AUX>2"); //Additional cut based on vars or aux vars

  /////////////////////////////Make Model Signal
  RF.SetUp().FactoryPDF("PhiAsymmetryPDF::SigAsym( Phi,Pol,PolState,A[0,-1,1],B[0,-1,1] )");
  RF.SetUp().LoadSpeciesPDF("SigAsym",1);

  ////////////////////////////Make Bins
  // RF.Bins().LoadBinVar("Eg",4,3,4);
   
  ///////////////////////////Load Data
  //RF.Data().BootStrap(2);
  RF.LoadData("MyModel",pwd+"Data.root");
  RF.LoadSimulated("MyModel","MC.root","SigAsym");
  
  //////////////////////////Load Weight
  RF.Data().LoadWeights("Signal",pwd+"outsPlot/Tweights.root");


  //use Minuit2(5) to run 5 fits and take the best likelihood
  RF.SetMinimiser(new Minuit2());

  //Or try an mcmc minimser 1000-># of points, 200->burnin 200 ~ 1/step size
  //RF.SetMinimiser(new RooMcmcUniform2Seq(1000,200,200));
  

  Here::Go(&RF);
  //OR run with PROOF-LITE on N=4 cores (you can change the 4)
  // Proof::Go(&RF,4);
 
}
