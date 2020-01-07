//Run with 
//root --hsfit componentsPDFToys.C
{
 
 //get the current directory where the data is (PROOF needs full path)
  TString pwd = TString(gSystem->Getenv("PWD"))+"/";
  
  FitManager RF;
  RF.SetUp().SetOutDir(pwd+"outCompToy/");
  ///////////////////////////////Load Variables
  RF.SetUp().LoadVariable("Phi[-180,180]"); 
  RF.SetUp().LoadVariable("Pol[0,1]"); 
  RF.SetUp().LoadCategory("PolState[Polp=1,Pol0=0,Polm=-1]"); 
  //RF.SetUp().LoadAuxVar("AUX[0,300]"); //Load Aux Var, limits used as cut 
 
  ///////////////////////////////Make additional cut on an AuxVar
  //RF.SetUp().AddCut("AUX>2"); //Additional cut based on vars or aux vars
  RF.SetUp().LoadFormula("COS2=@Pol[]*@PolState[]*cos(2*@Phi[]*TMath::DegToRad())");
  RF.SetUp().LoadFormula("SIN2=@Pol[]*@PolState[]*sin(2*@Phi[]*TMath::DegToRad())");
  RF.SetUp().LoadParameter("A[0,-1,1]");
  RF.SetUp().LoadParameter("B[0,-1,1]");
  /////////////////////////////Make Model Signal
  RF.SetUp().FactoryPDF("RooComponentsPDF::SigAsym(1,{Phi,Pol,PolState},=A;COS2:B;SIN2)");
  RF.SetUp().LoadSpeciesPDF("SigAsym",1);

  ////////////////////////////Make Bins
  //RF.Bins().LoadBinVar("Eg",4,3,4);
   
  ///////////////////////////Load Data
  //RF.Data().BootStrap(2);
  RF.LoadData("MyModel","DataSignal.root");
  RF.LoadSimulated("MyModel","MC.root","SigAsym");
  

  //use Minuit2(5) to run 5 fits and take the best likelihood
  // RF.SetMinimiser(new Minuit2());
  RF.SetUp().AddFitOption(RooFit::Optimize(1));

  //Or try an mcmc minimser 1000-># of points, 200->burnin 200 ~ 1/step size
  // RF.SetMinimiser(new RooMcmcSeq(1000,200,200));
  

  Here::Go(&RF);
  //OR run with PROOF-LITE on N=4 cores (you can change the 4)
  // Proof::Go(&RF,4);
  auto toy=ToyManager::GetFromFit(5,RF,"ResultsHSMinuit2.root");
  toy->SetUp().SetOutDir("outCompToy2");
  toy->LoadData("MyModel","DataSignal.root");//need data for protodata PolState and Pol
  toy->LoadSimulated("MyModel","MC.root","SigAsym");
  RooMsgService::instance().addStream(RooFit::DEBUG,Topic(RooFit::Generation));
  RooMsgService::instance().getStream(0).addTopic(RooFit::Generation) ;
  Here::Go(toy); //generate toys
  Here::Go(toy->Fitter()); //fit toys
  toy->Summarise();

}
