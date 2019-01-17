//root --hsdata --hsfinal=THSPi2 RunFSHipoPi2.C
//You need to replace Pi2 with your final state class name
{
  //Create FinalState
  //Pi2* fs=new Pi2("NONE","ALL");
  Pi2 fs("NONE","ALL");
  //   fs->SetGenerated(); //just analyse gemc generated branch
  //create ouput tree
  // auto output = filed_uptr(FiledTree::Recreate("FinalTree","OUTPUT3.root"));
  //fs.FinalStateOutTree(output->Tree());
  fs.CreateFinalTree("FinalTree","OUTPUT3.root");
  
  auto treeman=make_shared<ParticleDataManager>("particleTrees3");
  treeman->ConfigureTreeParticles(&fs); //propogate through topologies
  fs.RegisterPostWorkAction((treeman)); //register post-work i.e. after

  auto dm=make_shared<HipoToolsReader>();
  TChain chain("HSParticles");
  chain.Add("/home/dglazier/fastdata/skim3_3933.hipo");
  // chain.Add("/home/dglazier/fastdata/sim/EptoRhop_54.hipo");
  dm->InitChain(&chain);

  //connect Project to HSParticles
  fs.SetDataManager(dm);
  
  Long64_t counter=0;
  gBenchmark->Start("timer");
   // Record start time
  auto start = std::chrono::high_resolution_clock::now();

  fs.ProcessData(1E6);
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "Elapsed time: " << elapsed.count() <<" events = "<< counter <<" s\n";
  gBenchmark->Stop("timer");
  gBenchmark->Print("timer");
  
  // outfile->cd();
  //  outtree->Write();
  // treeman.reset();
  cout<<treeman.use_count()<<endl;
  fs.EndAndWrite();
  cout<<treeman.use_count()<<endl;
}
