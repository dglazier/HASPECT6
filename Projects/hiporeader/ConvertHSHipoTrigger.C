//Run with root --hsdata ConvertHSHipoTrigger.C --hsin=out_out.hipo --hsout=file.root
{

  THSHipoTrigger* reader=new THSHipoTrigger();
  reader->SetOutDir(HSout());
  //  reader->SetWriteGenBranch("Generated"); //simulation only



  gBenchmark->Start("time");
  reader->SetTrigPeriod(1);                                                
  reader->SetCurFactor(0.16283); //for 6GeV, for 10GeV you can remove this line 

  cout<<"Analysing file "<<HSin()<<endl;
  TChain chain("hipo");
  chain.Add(HSin()+"/*.hipo");


  reader->InitChain(&chain);
  reader->WriteParticles();

  
  cout<<"Analysed "<<reader->GetEntry()<<" events"<<endl;
  
  gBenchmark->Stop("time");
  gBenchmark->Print("time");


}
