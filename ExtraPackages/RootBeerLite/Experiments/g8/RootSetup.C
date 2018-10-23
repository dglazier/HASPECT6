 {
  gROOT->LoadMacro("$HSCODE/hsdata/LoadDataManager.C+");
  TString G8=gSystem->Getenv("G8");
  TString ROOTBEER_SLIB=gSystem->Getenv("ROOTBEER_SLIB");
  LoadMacro("THSRootBeer.C");

  gSystem->Load(ROOTBEER_SLIB+"/libeloss.so");
  //Linear polarisation
 }		
