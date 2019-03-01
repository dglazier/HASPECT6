{
  //gROOT->ProcessLine(".x LoadPi2.C+"); //Load the classes

 Pi2 fs("NONE","ALL"); //string arguments => PID, INCLUSIVE 

  //strings = treename and filename (give full path)
 fs.CreateFinalTree("FinalTree","OUTPUT.root");

auto cutsman=make_shared<ParticleCutsManager>();
auto eCut=make_shared<CLAS12DeltaTime>(4,4,0,0); //4ns FT,FD,
auto protCut=make_shared<CLAS12DeltaTime>(0,5,5,0); //5ns FD,CD
auto otherCut=make_shared<CLAS12DeltaTime>(0,5,0,0); //5ns FD
cutsman->AddParticleCut("e-",eCut); //assign to manager
cutsman->AddParticleCut("proton",protCut); //assign to manager
cutsman->SetDefaultCut(otherCut); //assign to manager
cutsman->ConfigureCuts(&fs);   

fs.RegisterPostTopoAction(cutsman);

auto treeman=make_shared<ParticleDataManager>("particleTrees");
treeman->ConfigureTreeParticles(&fs); //propogate through topologies
treeman->AddFinal(); //if you want the final tree branches included with particles
fs.RegisterPostWorkAction(treeman); //register post-work i.e. after

 //create datamanager
  auto dm=std::make_shared<HipoToolsReader>();

  //And make a chain of data files
  TChain chain("HSParticles");
  chain.Add("/work/jlab/clas12data/trains/v1/5bp6p2/skim3_mesonx_vs/skim3_3933.hipo");
  dm->InitChain(&chain);

  //connect FinalState to Data by moving the pointer
  fs.SetDataManager(dm);

fs.ProcessData(); //No number given, analyse all events in chain


TCanvas c1;
fs.FinalTree()->Draw("MissMass2>>h1(100,-0.5,0.5)","Topo==0");
//fs.FinalTree()->Draw("MissMass2","Topo==1","same");
//fs.FinalTree()->Draw("MissMass2","Topo==2","same");
//fs.FinalTree()->Draw("MissMass2","Topo==3","same");
//h1->SetMinimum(0);
c1.Draw();

TCanvas c3;
c3.Divide(2,1);
c3.cd(1);
treeman->GetParticleData(0)->GetTree()->Draw("ElectronP:ElectronTime>>h2(100,-10,10,100,0,12)","","col1");
c3.cd(2);
treeman->GetParticleData(0)->GetTree()->Draw("ProtonP:ProtonTime>>h3(100,-10,10,100,0,10)","","col1");


fs.EndAndWrite();
}
