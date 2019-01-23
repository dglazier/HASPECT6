//root --hsdata --hsfinal=THSEl RunFSRootEl.C
//You need to replace El with your final state class name
{
  //Create FinalState
  THSEl* fs=new THSEl();
  // fs->SetGenerated(); //just analyse generated branch
   fs->SetMaxParticles(10);
  //create datamanager
  THSDataManager* dm=new THSDataManager();
  TChain chain("HSParticles");
  chain.Add("/home/dglazier/clas12data/Andrea/Run004279/out_*.hipo.root");
  dm->InitChain(&chain);
  //connect Project to HSParticles
  fs->SetDataManager(dm);
  Int_t counter=0;
  
  //create ouput tree
  TFile* outfile=new TFile("~/TriggerData/ElRun004279_MAX10_TimeAll.root","recreate");
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
