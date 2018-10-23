#include <TSystem.h>
#include <TString.h>
#include <TInterpreter.h>
#include <TROOT.h>
#include <vector>
#include <iostream>

namespace HS{};
using namespace HS;

void LoadHipo(){
  
  TString HSCODE=gSystem->Getenv("HSCODE");
  TString dmpath="/hsdata/";

  //Add HSDataManager include path
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSCODE+dmpath)){
    gInterpreter->AddIncludePath(HSCODE+dmpath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+dmpath).Data()));
  }

  TString RHIPO=gSystem->Getenv("RHIPO");
  if(RHIPO==TString("")) {cout<<"Error LoadHipo() You need to set RHIPO"<<endl; exit(1);}

  //First need DataManager
  gROOT->ProcessLine(".x LoadDataManager.C+");

  //Now THipo
  gROOT->ProcessLine(".x $RHIPO/Hipo2Root.C+");


  //Add classes
  std::vector<TString > DMClasses={"HipoReader","HipoTrigger","HipoDST"};
  for(auto const& name : DMClasses){
    std::cout<<"HHHHHHHHHHHHHHHHHHHHHHHH    "<<name<<std::endl;
    if(!gROOT->GetListOfClasses()->Contains(name))
      gROOT->LoadMacro(HSCODE+dmpath+name+".C+");
  }


}
