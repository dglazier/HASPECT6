// root  LoadPi2.C RunFSRootPi2.C
//You need to replace Pi2 with your final state class name
{
  //Create FinalState
  Pi2 fs;
  // fs.SetGenerated(); //just analyse generated branch
  // fs.SetMaxParticles(10); //max number of particles of any 1 type
  
  //create ouput tree
   fs.CreateFinalTree("FinalTree","OUTPUT.root");

  
  //create datamanager
  auto dm=std::make_shared<DataManager>();
  
  //And make a chain of data files
  TChain chain("HSParticles");
  chain.Add("/indir/out_*root");
  dm->InitChain(&chain);

  //connect FinalState to Data
  fs.SetDataManager(dm);
  
  gBenchmark->Start("timer");

  //Analyse all the events in the data manager
  fs.ProcessData();

  
  gBenchmark->Stop("timer");
  gBenchmark->Print("timer");
  
  fs.EndAndWrite();
}
