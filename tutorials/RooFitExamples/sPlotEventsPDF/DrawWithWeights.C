{
  THSWeights* wts=new THSWeights("TotalWeights");
  wts->Merge("outBins/WeightsEg","outBins/WeightsTotal.root","HSsWeights");
 
  TChain chain("MyModel");
  chain.AddFile("Data.root");
  Double_t ID,M1;
  chain.SetBranchAddress("fgID",&ID);
  chain.SetBranchAddress("M1",&M1);
  
  TH1F* histM1S=new TH1F("M1S","M1S",100,0,10);
  TH1F* histM1B=new TH1F("M1B","M1B",100,0,10);
  Double_t weight=0;
  
  for(Int_t i=0;i<chain.GetEntries();i++){
    chain.GetEntry(i);
    if(wts->GetEntryBinarySearch(ID)){//find the weight for this event
      histM1S->Fill(M1,wts->GetWeight("Signal"));
      histM1B->Fill(M1,wts->GetWeight("BG"));
    }
  }
  histM1S->Draw();
  histM1B->Draw("same");

}
