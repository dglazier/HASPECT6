//root --hsdata --hsfinal=THS2Pi RunFSRoot2Pi.C
//You need to replace 2Pi with your final state class name
{
  //Create FinalState
  THS2Pi* fs=new THS2Pi();
  // fs->SetGenerated(); //just analyse generated branch
   fs->SetMaxParticles(15);
  //create datamanager
  THSDataManager* dm=new THSDataManager();
  TChain chain("HSParticles");
  chain.Add("/home/dglazier/clas12data/Andrea/Run004279/out_**.hipo.root");
  dm->InitChain(&chain);
  //connect Project to HSParticles
  fs->SetDataManager(dm);
  Int_t counter=0;
  
  //create ouput tree
  TFile* outfile=new TFile("files5.4/Run004288_MAX15_TimeAll.root","recreate");
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
