
//Run with 
//root 'Model1.C( "Data.root",1 )' //For data
//root 'Model1.C( "MC.root",0 )' //For MC

void Model1(TString filename,Bool_t IsData=kTRUE){

  TFile* file=new TFile(filename,"recreate");

  Double_t Eg,Mmiss,M1,M2,fgID,Sig,Phi,Pol;
  Int_t PolState;
  TTree* tree=new TTree("MyModel","MyModel");
  tree->Branch("Eg",&Eg,"Eg/D");
  tree->Branch("Mmiss",&Mmiss,"Mmiss/D");
  tree->Branch("M1",&M1,"M1/D");
  tree->Branch("Phi",&Phi,"Phi/D");
  tree->Branch("M2",&M2,"M2/D");
  tree->Branch("fgID",&fgID,"ID/D");
  tree->Branch("Sig",&Sig,"Sig/D");
  if(IsData){
  tree->Branch("PolState",&PolState,"PolState/I");
  tree->Branch("Pol",&Pol,"Pol/D");
  }
  //signal
  TF1* fM1s=new TF1("m1s","gaus(0)+gaus(3)+[6]",0,10);
  fM1s->SetParameters(1,3,0.5,0.5,7,2,0.1);
  TF1* fM2s=new TF1("m2s","gaus(0)+[3]*x",0,10);
  fM2s->SetParameters(1,5,0.1,0.1);
  TF1* fMmisss=new TF1("mmisss","gaus(0)",0,10);
  //fMmisss->SetParameters(1,0.1,1);
  fMmisss->SetParameters(1,5,0.7);
  TF1* fPhip=new TF1("phip","1+[2]*([0]*cos(2*TMath::DegToRad()*x)+[1]*sin(2*TMath::DegToRad()*x))",-180,180);
  if(IsData)fPhip->SetParameters(0.4,-0.6,1);
  else fPhip->SetParameters(0,0,0);
  
  //bakcground
  TF1* fM1b=new TF1("m1b","2-[0]*x",0,10);
  fM1b->SetParameter(0,0.1);
  TF1* fM2b=new TF1("m2b","2-[0]*x",0,10);
  fM2b->SetParameter(0,0.05);
  TF1* fMmissb=new TF1("mmissb","[0]*(x-4)+2",0,10);
  fMmissb->SetParameter(0,0.2);
  Int_t Nev=100000;
  if(!IsData) Nev*=10;
  for(Int_t i=0;i<Nev;i++){
    fgID=i;
    if(gRandom->Uniform()>0.5) PolState=1;
    else PolState=-1;
    if(gRandom->Uniform()>0.5||!IsData){//Signal
      Eg=gRandom->Uniform(3,4);
      Pol=Eg/2-1; //should be 0.5-1
      M1=fM1s->GetRandom();
      M2=fM2s->GetRandom();
      Mmiss=fMmisss->GetRandom();
      if(IsData)fPhip->SetParameter(2,PolState*Pol);
      Phi=fPhip->GetRandom();
      Sig=1;
     }
    else{//Background
      Eg=gRandom->Uniform(3,4);
      Pol=Eg/2-1; //should be 0.5-1
      M1=fM1b->GetRandom();
      M2=fM2b->GetRandom();
      // fMmissb->SetParameter(0,0);
      Mmiss=fMmissb->GetRandom();
      Phi=gRandom->Uniform(-180,180);
      Sig=-1;
    }
    tree->Fill();
  }

  tree->Write();
  file->Close();

}
