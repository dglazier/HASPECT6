//root --hsdata --hsfinal=K2 RunFSLundK2.C
//You need to replace K2 with your final state class name
{
  //Create FinalState
  K2* fs=new K2();
  //create datamanager
  LundReader* dm=new LundReader();
  dm->Init("/lund/file/name.lund","HSParticles");
  fs->SetDataManager(dm);
  Int_t counter=0;
  
  //create ouput tree
  
  TFile* outfile=new TFile("gentest.root","recreate");
  TTree* outtree=new TTree("FinalTree","output tree");
  fs->FinalStateOutTree(outtree); //connect ouput tree to project branches
  
  gBenchmark->Start("timer");
  
  while(dm->ReadEvent()){//loop over events
    fs->ProcessEvent();
  }
  gBenchmark->Stop("timer");
  gBenchmark->Print("timer");
  
  outfile->cd();
  outtree->Write();
  delete outfile;
}
