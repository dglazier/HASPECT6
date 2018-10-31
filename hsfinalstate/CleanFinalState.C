#include <TSystem.h>
#include <TString.h>
#include <iostream>

void CleanFinalState(){
  
  TString HSFS=TString(gSystem->Getenv("HSCODE"))+"/hsfinalstate/";
  cout<<"Tidying up "<<HSFS<<endl;
  gSystem->Exec(Form("rm %s/*.so",HSFS.Data()));
  gSystem->Exec(Form("rm %s/*.d",HSFS.Data()));
  gSystem->Exec(Form("rm %s/*.pcm",HSFS.Data()));
  gSystem->Exec(Form("rm %s/*~",HSFS.Data()));

}
