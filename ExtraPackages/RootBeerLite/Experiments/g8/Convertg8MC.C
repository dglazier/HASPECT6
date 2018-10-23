//Run with  root --rootbeer $G8/RootSetup.C --THSCLASg8.C --hsin=testruns.txt --hsout=/w/work0/home/dglazier/test8/ --Edge=XXX Convertg8.C
{
  //look for edge position
  //  e.g --Edge=1300 (1500,1700,1900,2100,2300)
  Int_t	 EDGEVAL=0;	
 
 
  THSCLASg8* reader=new THSCLASg8();
  reader->SetEdge(EDGEVAL);
  reader->SetOutDir(HSout());
  reader->SetWriteGenBranch("Generated");
  
  //Fake chain just using the Add and GetListofFiles
  TChain chain("dst");
  //Give list of files
  TFileCollection fc("dum","",HSinFile());
  chain.AddFileInfoList(fc.GetList());
  
  gBenchmark->Start("time");

  reader->InitChain(&chain);
  reader->WriteParticles();
  cout<<"Analysed "<<reader->GetEntry()<<" events"<<endl;
  
  gBenchmark->Stop("time");
  gBenchmark->Print("time");
 
}
