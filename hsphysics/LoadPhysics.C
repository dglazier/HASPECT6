#include <TSystem.h>
#include <TString.h>
#include <TInterpreter.h>
#include <TROOT.h>
#include <vector>
#include <iostream>

namespace HS{};
using namespace HS;

void LoadPhysics(TString Selection=""){
  
  TString HSCODE=gSystem->Getenv("HSCODE");
  TString phpath="/hsphysics";

  //Add HSPhysics include path
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSCODE+phpath)){
    gInterpreter->AddIncludePath(HSCODE+phpath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+phpath).Data()));
  }
  

  //Now finalsstate classes
  vector<TString > PHClasses={"HSKinematics","THSLongPS","THSIsobarPS"};

  for(auto const& name : PHClasses){
    if(Selection!=TString())
      if(!Selection.Contains(name)) continue;
    
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!! "<<name<<endl;
    if(!gROOT->GetListOfClasses()->Contains(name))
      gROOT->LoadMacro(name+".C+");
  }

 
}

