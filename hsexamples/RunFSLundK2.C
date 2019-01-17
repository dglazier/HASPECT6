//root  LoadK2.C  RunFSLundK2.C
//You need to replace K2 with your final state class name
{
  //Create FinalState
  K2 fs;
 
  //create ouput tree
  fs.CreateFinalTree("FinalTree","OUTPUT.root");
  
  //create datamanager
  auto dm=make_shared<LundReader>();
  //add files
  TChain chain("HSParticles");
  chain.Add("/indir/out_*lund");
  dm->InitChain(&chain);

  fs->SetDataManager(dm);
  
  gBenchmark->Start("timer");
  
 //Analyse all the events in the data manager
  fs.ProcessData();
  
  gBenchmark->Stop("timer");
  gBenchmark->Print("timer");
  
  fs.EndAndWrite();

}
