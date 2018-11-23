{
  TFile *_file0 = TFile::Open("testmvamlpinc2.root");
  TTree* tree=(TTree*)_file0->Get("tt");

  TFile* saveFile=new TFile("dump.root","recreate");

  // TTree* tree1=tree->CopyTree("Topo==1");

  TH1F* hmm0=new TH1F("mm0","mm0",1000,0.8,1.4);
  tree->Draw("MesonMass>>mm0","Topo==1&&MLP>0.98&&PolState!=0");

  TH1F* hmm1=new TH1F("mm1","mm1",1000,0.8,1.4);
  tree->Draw("MesonMass>>mm1","Topo==1&&MLP<0.98&&MLP>0.96&&PolState!=0");
  
  hmm1->Scale(0.45*0.7);

  new TCanvas();
  hmm0->Draw();
  hmm1->Draw("same");

  TH1F* hmmSub=(TH1F*)hmm0->Clone();
  hmmSub->Add(hmm1,-1);
  hmmSub->Draw("same");
    
}
