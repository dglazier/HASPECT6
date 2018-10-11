//root --hsdata --hsfinal=K2 RunFSRootK2.C
//You need to replace K2 with your final state class name
{
  //Create FinalState
  K2 fs;
  // fs.SetGenerated(); //just analyse generated branch
  // fs.SetMaxParticles(10); //max number of particles of any 1 type
  
  //create ouput tree
  //strings = treename and filename (give full path)
  auto output= new FiledTree("FinalTree","OutPUT.root");
  fs.FinalStateOutTree(output->Tree()); //connect ouput tree to project branches

  
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

  //write the tree to disk
  delete output;
  
  gBenchmark->Stop("timer");
  gBenchmark->Print("timer");
  
}
