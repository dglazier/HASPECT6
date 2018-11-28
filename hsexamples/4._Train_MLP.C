{
  
  //gROOT->ProcessLine(".x LoadK2.C+");

 K2 fs("Beam","Beam");
  // fs.SetGenerated(); //just analyse generated branch
  // fs.SetMaxParticles(10); //max number of particles of any 1 type
 

auto output = new HS::FiledTree("tt","testcuts.root");
fs.FinalStateOutTree(output->Tree()); //connect ouput tree to final state branches

ParticleCutsManager cutsman;
auto beamCut=make_shared<DeltaTimePCut>(20,3); //7ns delta time cut
auto otherCut=make_shared<DeltaTimePCut>(20,3); //10ns cut for all other particles
cutsman.AddParticleCut("Beam",beamCut); //assign to manager
cutsman.SetDefaultCut(otherCut); //assign to manager
cutsman.ConfigureCuts(&fs);    //propogate the cuts to topologies in fs

fs.RegisterPostTopoAction(&cutsman);

auto treeman=new TreePrepManager("/work/g8dump/particlesTrain");
treeman->SetParticleVars("Beam",{"P","Time"}); //For beam only interesetef in energy and time
treeman->ConfigureTreeParticles(&fs); //propogate through topologies
//treeman.SetN(50000); //Number of events required for each topo. Number of train+test events must be less than this
fs.RegisterPostWorkAction(treeman); //register post-work i.e. after kinematics is called and all calculations

 //create datamanager
  auto dm=std::make_shared<DataManager>();

  //And make a chain of data files
  TChain chain("HSParticles");
  //Add actual data to train as background
  chain.Add("/home/dglazier/fastdata/g8/flist_048200.dat.root");
  //Add simulated data to train as signal
  chain.Add("/home/dglazier/fastdata/g8/rec_edgen_.root");
  dm->InitChain(&chain);

  //connect FinalState to Data by moving the pointer
  fs.SetDataManager(dm);

cout<<"Number of Events to process "<<chain.GetEntries()<<endl;
fs.ProcessData(); //No number give, analyse all events in chain
cout<<"Done "<<dm->GetEntry()<< " events "<<endl;

//delete output;

//%jsroot on

TCanvas c3;
c3.Divide(2,2);
c3.cd(1);
treeman->GetPrep(0)->Tree()->Draw("BeamP:BeamTime>>h1(100,-10,10,100,0.4)","","col1");
c3.cd(2);
treeman->GetPrep(0)->Tree()->Draw("ProtonP:ProtonTime>>h2(100,-10,10,100,0,4)","","col1");
c3.cd(3);
treeman->GetPrep(0)->Tree()->Draw("KpP:KpTime>>h3(100,-10,10,100,0,4)","","col1");
c3.cd(4);
treeman->GetPrep(0)->Tree()->Draw("KmP:KmTime>>h4(100,-10,10,100,0,4)","","col1");


c3.Draw();

//gROOT->ProcessLine(".x $HSCODE/hsmva/LoadHSMVA.C+");

 for(UInt_t ip=0;ip<treeman->NPreps();ip++ ){ //Loop over topologies
   auto prep=treeman->GetPrep(ip);
   cout<<prep<<endl;
   auto trainer=  new TrainSignalID(Form("Topo%d",ip));
     
   trainer->SetOutDir(treeman->OutDir());
   trainer->IgnoreBranches("Signal:Background"); //ignore these branches for training
   trainer->AddSignalTree(prep->Tree(),"Signal"); //Use "Signal" branch to filter Signal events
   trainer->AddBackgroundTree(prep->Tree(),"Background"); //Use "Background" branch for bg events
   trainer->SetNTrainTest(50000,50000); //set number of training and testing events, there must be sufficient number in the trees for each topo
   trainer->PrepareTrees(); 
   //trainer->BookMethod(Meths.BDTA); //choose some classifiers
   trainer->BookMethod(Meths.MLP); //choose some classifiers
   trainer->DoTraining();
   trainer->DrawROCCurve();
   //trainer->DrawResponses();
   delete trainer;
  }

delete treeman;
}
