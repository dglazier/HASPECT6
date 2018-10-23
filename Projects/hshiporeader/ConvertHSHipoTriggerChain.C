//Run with root $HSCODE/hsdata/LoadHipo.C+ ConvertHSHipoTriggerChain.C --hsin=indir --hsout=outdir
{

  auto reader=new HipoTrigger();
  reader->SetOutDir(HSout());
  //  reader->SetWriteGenBranch("Generated"); //simulation only

  TChain chain("hipo");
  chain.Add(HSin()+"/*.hipo");


  gBenchmark->Start("time");
 
  reader->InitChain(&chain);
  reader->WriteParticles();

  
  cout<<"Analysed "<<reader->GetEntry()<<" events"<<endl;
  
  gBenchmark->Stop("time");
  gBenchmark->Print("time");


}
