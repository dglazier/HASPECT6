//root --hsdata --hsfinal=Pi2 RunFSRootPi2.C
//You need to replace Pi2 with your final state class name
{
  //Create FinalState
  Pi2 fs;
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
  chain.Add("/w/work1/jlab/hallb/clas12/RG-A/hs/fall18/cooked/run4909/out_clas_pin_004909.evio.00555.hipo.root");
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
