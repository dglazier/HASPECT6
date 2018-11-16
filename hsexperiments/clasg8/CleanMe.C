#include <TSystem.h>
#include <TString.h>
#include <iostream>

void CleanMe(){
  
  TString HSEXP=gSystem->Getenv("HSEXP");
  cout<<"Tidying up "<<HSEXP<<endl;
  gSystem->Exec(Form("rm %s/*.so",HSEXP.Data()));
  gSystem->Exec(Form("rm %s/*.d",HSEXP.Data()));
  gSystem->Exec(Form("rm %s/*.pcm",HSEXP.Data()));
  gSystem->Exec(Form("rm %s/*~",HSEXP.Data()));

  if(gSystem->Getenv("RHIPO")){
    TString RHIPO=gSystem->Getenv("RHIPO");
    gSystem->Exec(Form("rm %s/*.so",RHIPO.Data()));
    gSystem->Exec(Form("rm %s/*.d",RHIPO.Data()));
    gSystem->Exec(Form("rm %s/*.pcm",RHIPO.Data()));
    gSystem->Exec(Form("rm %s/*~",RHIPO.Data()));

  }
  if(gSystem->Getenv("CHIPO")){
    TString CHIPO=gSystem->Getenv("CHIPO");
    gSystem->Exec(Form("rm %s/*.so",CHIPO.Data()));
    gSystem->Exec(Form("rm %s/*.d",CHIPO.Data()));
    gSystem->Exec(Form("rm %s/*.pcm",CHIPO.Data()));
    gSystem->Exec(Form("rm %s/*~",CHIPO.Data()));


  }

}
