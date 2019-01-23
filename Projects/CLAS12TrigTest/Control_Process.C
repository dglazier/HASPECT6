{
  //optional Set input file directory, could be done with --hsin or setenv HSIN
  //HSin("/home/dglazier/clas12data/Andrea/Run004280/");
  //optional set ouput directory or file.
  //Directory=>1 out file for every in file
  //file=> 1 total output file
  //HSout("FULL_PATH_OUTPUT_FILE_DIR_OR_FILE");
  
  //Set up the input chain to be analysed,could remove HSin() if you want
  TChain* tree=new TChain("HSParticles","datachain");
  tree->Add(HSin()+"out_clas_004280.evio.0_9.hipo.root");

  //if using proof
  //Give proof destination file (env variables can't be read directly
  if(gProof) {gProof->AddInput(new TNamed("HSOUT",HSout().Data()));gProof->AddInput(new TNamed("HSPROOF","Using Proof"));tree->SetProof();}

  gBenchmark->Start("SelectorTimer");

  tree->Process("Process.C+");
  
  gBenchmark->Stop("SelectorTimer");
  gBenchmark->Print("SelectorTimer");
  tree->PrintCacheStats();

  //Not actually sure if this is needed or not...
  if(gProof)gProof->ClearData(TProof::kUnregistered | TProof::kForceClear);
}
