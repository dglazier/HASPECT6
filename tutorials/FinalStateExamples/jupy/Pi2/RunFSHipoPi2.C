//root  LoadPi2.C RunFSHipoPi2.C
//You need to replace Pi2 with your final state class name
{
  //Create FinalState
  Pi2 fs();
   // fs->SetGenerated(); //just analyse gemc generated branch

  //create ouput tree
   fs.CreateFinalTree("FinalTree","OUTPUT.root");
   
  //create datamanager
  auto dm=std::make_shared<HipoToolsReader>();
  TChain chain("HSParticles");
  chain.Add("/indir/out_*hipo");
  dm->InitChain(&chain);
  
  //connect Project to HSParticles
  fs->SetDataManager(dm);
  Int_t counter=0;
  
  
  gBenchmark->Start("timer");
  
  fs.ProcessData();
  
  gBenchmark->Stop("timer");
  gBenchmark->Print("timer");
  
  fs.EndAndWrite();
}
