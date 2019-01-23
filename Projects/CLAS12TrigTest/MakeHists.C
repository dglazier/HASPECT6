{

  TTree* tree=(TTree*)_file0->Get("FinalTree");

  new TCanvas;
  tree->Draw("MissMass>>MM(200,0,4)","Topo==0");
  tree->Draw("MissMass","Topo==1","same");

  new TCanvas;
  tree->Draw("MissTheta:PTh","Topo==1","col1");

  new TCanvas;
  FinalTree->Draw("DeltaPhi*TMath::RadToDeg()>>DPhi(100,-180,180)","Topo==1&&MissMass>0","");
  FinalTree->Draw("DeltaPhi*TMath::RadToDeg()","Topo==1&&MissMass>0&&MissTheta>1","same");

    new TCanvas;
 FinalTree->Draw("ElPhi*TMath::RadToDeg()>>ELPhi(100,-180,180)","Topo==0&&MissMass>0&&MissTheta>1","");
 FinalTree->Draw("ElPhi*TMath::RadToDeg()>>elELPhi","Topo==1&&MissMass>0&&MissTheta>1","same");

 new TCanvas;
 //elELPhi->Draw()
 //ELPhi->Draw()
 //elELPhi->Divide(ELPhi)
 //elELPhi->Draw()
}
