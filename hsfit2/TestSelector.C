{
  TChain chain("bins");
  chain.Add("BinIndices.root");
  chain.SetProof();
  gProof->SetParameter("PROOF_PacketizerCalibNum", 1);
  chain.Process("FitSelector.C+");



}
