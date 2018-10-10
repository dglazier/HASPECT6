#include <TSystem.h>
#include <TString.h>
#include <TInterpreter.h>
#include <TROOT.h>
#include <vector>
#include <iostream>

namespace HS{};
using namespace HS;

void LoadSkeleton(){
  
  TString HSCODE=gSystem->Getenv("HSCODE");
  TString skpath="/hsskeleton";

  //Add HSMVA include path
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSCODE+skpath)){
    gInterpreter->AddIncludePath(HSCODE+skpath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+skpath).Data()));
  }

  vector<TString > SkClasses={"Skeleton","FSSkeleton","CLAS12Skeleton","CLASSkeleton"};
  
  for(auto const& name : SkClasses){
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$ "<<name<<endl;
    if(!gROOT->GetListOfClasses()->Contains(name))
      gROOT->LoadMacro(name+".C+");
  }


}
