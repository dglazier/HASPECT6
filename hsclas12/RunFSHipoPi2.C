//root --hsdata --hsfinal=THSPi2 RunFSHipoPi2.C
//You need to replace Pi2 with your final state class name
{
  //Create FinalState
  Pi2* fs=new Pi2("NONE","");
   // fs->SetGenerated(); //just analyse gemc generated branch
  //create datamanager
  //HipoTrigger* dm=new HipoTrigger();
  //  auto dm=std::make_shared<HipoTrigger>();
  auto dm=std::make_shared<HipoToolsReader>();
  TChain chain("HSParticles");
  chain.Add("/home/dglazier/fastdata/skim3_3933.hipo");
  dm->InitChain(&chain);
  //connect Project to HSParticles
  fs->SetDataManager(dm);
  Long64_t counter=0;
  
  //create ouput tree
  TFile* outfile=new TFile("OUTPUT.root","recreate");
  TTree* outtree=new TTree("FinalTree","output tree");
  fs->FinalStateOutTree(outtree); //connect ouput tree to project branches
  
  gBenchmark->Start("timer");
   // Record start time
  auto start = std::chrono::high_resolution_clock::now();

  auto reader=dm->GetHipoReader();
  while(dm->ReadEvent()){//loop over events
    fs->ProcessEvent();
    if(counter++==1E6) break;
  }
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "Elapsed time: " << elapsed.count() <<" events = "<< counter <<" s\n";
  gBenchmark->Stop("timer");
  gBenchmark->Print("timer");
  
  outfile->cd();
  outtree->Write();
  delete outfile;
}
