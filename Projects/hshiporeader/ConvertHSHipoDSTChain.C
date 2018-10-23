//Run with root -b -q $HSCODE/hsdata/LoadHipo.C+ ConvertHSHipoDSTChainMC.C --hsin=indir --hsout=outdir
{

  auto reader=new HipoDST();
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
