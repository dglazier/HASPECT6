//root --hsdata --hsfinal=THS2pi RunFSRoot2piApp.C
//You need to replace 2pi with your final state class name
{
  //Create FinalState
  THS2pi* fs=new THS2pi();
  fs->SetTrain(kFALSE);
  // fs->SetGenerated(); //just analyse generated branch
   fs->SetMaxParticles(10);
  //create datamanager
  THSDataManager* dm=new THSDataManager();
  TChain chain("HSParticles");
  chain.Add("/w/work1/jlab/hallb/clas12/tmva_gemc_data/rho10_tm1_sm1_5.3.3/out_*root");
  dm->InitChain(&chain);
  //connect Project to HSParticles
  fs->SetDataManager(dm);
  Int_t counter=0;
  
  //create ouput tree
  TFile* outfile=new TFile("TestApp.root","recreate");
  TTree* outtree=new TTree("OutputTree","output tree");
  outtree->SetAutoSave(1E4);
  fs->FinalStateOutTree(outtree); //connect ouput tree to project branches
  //fs->TMVAOutTree(outtree); //connect ouput tree to project branches

  TFile* setupFile = new TFile("TestTrain.root","LOAD");
  THSMVA* setup; setupFile->GetObject("Setup;1", setup);

  fs->SetApplication(setup);

  gBenchmark->Start("timer");
   
  while(dm->ReadEvent()){//loop over events
    fs->ProcessEvent();
    if (counter == 5000){
        break;
    }
    counter++;
  }

  gBenchmark->Stop("timer");
  gBenchmark->Print("timer");

  fs->EndApplication(outfile);

  outfile->cd();
  outtree->Write();

  delete outfile;
}
