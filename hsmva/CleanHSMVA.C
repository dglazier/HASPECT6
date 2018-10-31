#include <TSystem.h>
#include <TString.h>
#include <iostream>

void CleanHSMVA(){
  
  TString HSMVA=TString(gSystem->Getenv("HSCODE"))+"/hsmva/";
  cout<<"Tidying up "<<HSMVA<<endl;
  gSystem->Exec(Form("rm %s/*.so",HSMVA.Data()));
  gSystem->Exec(Form("rm %s/*.d",HSMVA.Data()));
  gSystem->Exec(Form("rm %s/*.pcm",HSMVA.Data()));
  gSystem->Exec(Form("rm %s/*~",HSMVA.Data()));

}
