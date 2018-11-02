#include <TSystem.h>
#include <TString.h>
#include <iostream>

void CleanExperiments(){
  

  gROOT->ProcessLine(".x $HSEXP/CleanMe.C");

  TString HSEXP0=TString(gSystem->Getenv("HSCODE"))+"/hsexperiments/";
  cout<<"Tidying up "<<HSEXP0<<endl;
  gSystem->Exec(Form("rm %s/*.so",HSEXP0.Data()));
  gSystem->Exec(Form("rm %s/*.d",HSEXP0.Data()));
  gSystem->Exec(Form("rm %s/*.pcm",HSEXP0.Data()));
  gSystem->Exec(Form("rm %s/*~",HSEXP0.Data()));


}
