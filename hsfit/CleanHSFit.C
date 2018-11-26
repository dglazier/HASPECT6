#include <TSystem.h>
#include <TString.h>
#include <iostream>

void CleanHSFit(){
  
  TString HSFIT=TString(gSystem->Getenv("HSCODE"))+"/hsfit/";
  cout<<"Tidying up "<<HSFIT<<endl;
  gSystem->Exec(Form("rm %s/*.so",HSFIT.Data()));
  gSystem->Exec(Form("rm %s/*.d",HSFIT.Data()));
  gSystem->Exec(Form("rm %s/*.pcm",HSFIT.Data()));
  gSystem->Exec(Form("rm %s/*~",HSFIT.Data()));

}
