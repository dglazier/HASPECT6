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

  TString C12TOOL=gSystem->Getenv("CLAS12TOOL");

  TString HIPO=C12TOOL+"/Hipo";
  gSystem->Exec(Form("rm %s/*.so",HIPO.Data()));
  gSystem->Exec(Form("rm %s/*.d",HIPO.Data()));
  gSystem->Exec(Form("rm %s/*.pcm",HIPO.Data()));
  gSystem->Exec(Form("rm %s/*~",HIPO.Data()));

  TString BANKS=C12TOOL+"/Banks";  
  gSystem->Exec(Form("rm %s/*.so",BANKS.Data()));
  gSystem->Exec(Form("rm %s/*.d",BANKS.Data()));
  gSystem->Exec(Form("rm %s/*.pcm",BANKS.Data()));
  gSystem->Exec(Form("rm %s/*~",BANKS.Data()));

  
 
}
