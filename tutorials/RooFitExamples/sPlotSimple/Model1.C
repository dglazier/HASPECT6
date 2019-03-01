
//Run with 
//root 'Model1.C( "Data.root" )'

void Model1(TString filename){

  TFile* file=new TFile(filename,"recreate");

  Double_t Eg,Mmiss,M1,M2,fgID,Sig,Mmiss_M1;
  TTree* tree=new TTree("MyModel","MyModel");
  tree->Branch("Eg",&Eg,"Eg/D");
  tree->Branch("Mmiss",&Mmiss,"Mmiss/D");
  tree->Branch("M1",&M1,"M1/D");
  tree->Branch("Mmiss_M1",&Mmiss_M1,"Mmiss_M1/D");
  tree->Branch("M2",&M2,"M2/D");
  tree->Branch("fgID",&fgID,"fgID/D");
  tree->Branch("Sig",&Sig,"Sig/D");

  //signal
  TF1* fM1s=new TF1("m1s","gaus(0)+gaus(3)+[6]",0,10);
  fM1s->SetParameters(1,3,0.5,0.5,7,2,0.1);
  TF1* fM2s=new TF1("m2s","gaus(0)+[3]*x",0,10);
  fM2s->SetParameters(1,5,0.1,0.1);
  TF1* fMmisss=new TF1("mmisss","gaus(0)",0,10);
  //fMmisss->SetParameters(1,0.1,1);
  fMmisss->SetParameters(1,5,0.7);
 
  //bakcground
  TF1* fM1b=new TF1("m1b","2-[0]*x",0,10);
  fM1b->SetParameter(0,0.1);
  TF1* fM2b=new TF1("m2b","2-[0]*x",0,10);
  fM2b->SetParameter(0,0.05);
  TF1* fMmissb=new TF1("mmissb","[0]*(x-4)+2",0,10);
  //fMmissb->SetParameter(0,0);
  fMmissb->SetParameter(0,0.2);
  Int_t Nev=1E5;
  for(Int_t i=0;i<Nev;i++){
    fgID=i;
    if(gRandom->Uniform()>0.5){
      Eg=gRandom->Uniform(3,4);
      M1=fM1s->GetRandom();
      M2=fM2s->GetRandom();
      Mmiss=fMmisss->GetRandom();
      Sig=1;
     }
    else{
      Eg=gRandom->Uniform(3,4);
      M1=fM1b->GetRandom();
      M2=fM2b->GetRandom();
      Mmiss=fMmissb->GetRandom();
      Sig=-1;
    }
    tree->Fill();
  }

  tree->Write();
  file->Close();

}
