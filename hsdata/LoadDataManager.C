#include <TSystem.h>
#include <TString.h>
#include <TInterpreter.h>
#include <TROOT.h>
#include <vector>
#include <iostream>

namespace HS{};
using namespace HS;

void LoadDataManager(){
  
  TString HSCODE=gSystem->Getenv("HSCODE");
  TString dmpath="/hsdata/";

  //Add HSDataManager include path
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSCODE+dmpath)){
    gInterpreter->AddIncludePath(HSCODE+dmpath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+dmpath).Data()));
  }

  //Add classes
  std::vector<TString > DMClasses={"BaseEventInfo","BaseRunInfo","THSWeights","DataManager","LundReader"};

  for(auto const& name : DMClasses){
    std::cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%    "<<name<<std::endl;
    if(!gROOT->GetListOfClasses()->Contains(name))
      gROOT->LoadMacro(HSCODE+dmpath+name+".C+");
  }

  
}

