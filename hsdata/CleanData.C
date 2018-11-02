#include <TSystem.h>
#include <TString.h>
#include <iostream>
void CleanData(){
  
  TString HSDATA=TString(gSystem->Getenv("HSCODE"))+"/"+"hsdata";
  cout<<"Tidying up "<<HSDATA<<endl;
  gSystem->Exec(Form("rm %s/*.so",HSDATA.Data()));
  gSystem->Exec(Form("rm %s/*.d",HSDATA.Data()));
  gSystem->Exec(Form("rm %s/*.pcm",HSDATA.Data()));
  gSystem->Exec(Form("rm %s/*~",HSDATA.Data()));

}
