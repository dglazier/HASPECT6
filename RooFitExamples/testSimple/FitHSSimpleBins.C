//Run with 
//root --hsfit FitHSSimpleBins.C
{
  THSsPlot* RF=new THSsPlot("binFit"); 
  RF->SetOutDir("outBins2/");
 ///////////////////////////////Load Variables
  RF->LoadVariable("Mmiss[0,10]");//should be same name as variable in tree
  RF->LoadBinVars("Eg",1,3,4);//should be same name as variable in tree 
  RF->LoadBinVars("M1",4,0,10);//should be same name as variable in tree 
  RF->LoadAuxVars("M2[-100,100]");//Load M2 so we can cut on it

  //RF->AddCut("M2>4");
   ///////////////////////////Load Data
  TChain chain("MyModel");
  chain.Add("Data.root");
  RF->SetIDBranchName("fgID");
  //////////////////////////////Split data into bins and load them
  RF->MakeBinnedTrees(&chain,"Data");
  RF->ConfigureSavedBins(RF->GetOutDir());
  
  /////////////////////////////Make Model Signal
  RF->Factory("Gaussian::Signal( Mmiss, SIMm[6,4,7], SIMw[0.2,0.0001,3] )");
  RF->LoadSpeciesPDF("Signal");

  ////////////////////////////////Additional background
  RF->Factory("Chebychev::BG(Mmiss,{a0[0.1,-0.4,0.4],a1[-0.1,-0.3,0.3]})");
  RF->LoadSpeciesPDF("BG");

  gBenchmark->Start("Binned");
  RF->FitSavedBins(2);//argument gives number of parameter fits to perform
  gBenchmark->Stop("Binned");
  gBenchmark->Print("Binned");

  //chain deleted so recreate for extra plots  
  TChain chain2("MyModel");
  chain2.Add("Data.root");
  RF->LoadDataSet(&chain2);
 
  RF->DrawTreeVar("M1",100,0,10);
  RF->DrawTreeVar("M2",100,0,10);


  RF->GetWeights()->Save();
 
}
