//root  LoadPi2.C  RunFSLundPi2.C
//You need to replace Pi2 with your final state class name
{
  //Create FinalState
  Pi2 fs;
 
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
