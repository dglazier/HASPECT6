#include <TSystem.h>
#include <TString.h>
#include <iostream>

void CleanExperiments(){
  
  TString HSEXP=gSystem->Getenv("HSEXP");
  cout<<"Tidying up "<<HSEXP<<endl;
  gSystem->Exec(Form("rm %s/*.so",HSEXP.Data()));
  gSystem->Exec(Form("rm %s/*.d",HSEXP.Data()));
  gSystem->Exec(Form("rm %s/*.pcm",HSEXP.Data()));
  gSystem->Exec(Form("rm %s/*~",HSEXP.Data()));

  TString HSEXP0=TString(gSystem->Getenv("HSCODE"))+"/hsexperiments/";
  cout<<"Tidying up "<<HSEXP0<<endl;
  gSystem->Exec(Form("rm %s/*.so",HSEXP0.Data()));
  gSystem->Exec(Form("rm %s/*.d",HSEXP0.Data()));
  gSystem->Exec(Form("rm %s/*.pcm",HSEXP0.Data()));
  gSystem->Exec(Form("rm %s/*~",HSEXP0.Data()));


}
