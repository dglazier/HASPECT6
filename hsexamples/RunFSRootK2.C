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

  TreePrepManager treeman("/scratch/dglazier/g8/particles/t3MVA");
treeman.SetParticleVars("Beam",{"P","Time"}); //For beam only interesetef in energy and time
treeman.ConfigureTreeParticles(&fs); //propogate through topologies
treeman.SetN(50000); //Number of events required for each topo. Number of train+test events must be less than this
fs.RegisterPostWorkAction(&treeman);

  //create datamanager
  auto dm=std::make_shared<DataManager>();
  
  //And make a chain of data files
  TChain chain("HSParticles");
  // chain.Add("/w/work1/jlab/hallb/HS_g8/1_9_list/flist_048088.dat.root");
  chain.Add("/w/work1/jlab/hallb/HSg8/g8sim_2k_b/rec_edgen_.root");
  dm->InitChain(&chain);

  //connect FinalState to Data
  fs.SetDataManager(dm);
  
  gBenchmark->Start("timer");

  //Analyse all the events in the data manager
  fs.ProcessData(1E5);

  //write the tree to disk
  delete output;
  
  gBenchmark->Stop("timer");
  gBenchmark->Print("timer");
  
}
