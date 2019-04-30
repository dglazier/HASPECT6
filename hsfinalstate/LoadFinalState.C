#include <TSystem.h>
#include <TString.h>
#include <TInterpreter.h>
#include <TROOT.h>
#include <vector>
#include <iostream>

namespace HS{};
using namespace HS;

void LoadFinalState(TString Selection=""){
  
  TString HSCODE=gSystem->Getenv("HSCODE");
  TString mvapath="/hsmva";
  TString dmpath="/hsdata";
  TString fspath="/hsfinalstate";
  TString phpath="/hsphysics";

  //Add HSMVA include path
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSCODE+mvapath)){
    gInterpreter->AddIncludePath(HSCODE+mvapath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+mvapath).Data()));
  }
  //Add HSFinalState include path
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSCODE+fspath)){
    gInterpreter->AddIncludePath(HSCODE+fspath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+fspath).Data()));
  }
  //Add HSDataManager include path
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSCODE+dmpath)){
    gInterpreter->AddIncludePath(HSCODE+dmpath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+dmpath).Data()));
  }
  //Add HSPhysics include path
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSCODE+phpath)){
    gInterpreter->AddIncludePath(HSCODE+phpath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+phpath).Data()));
  }

  //First need Physics
  gROOT->ProcessLine(".x $HSCODE/hsphysics/LoadPhysics.C+");


  //Need hsmva results interface
  if(!gROOT->GetListOfClasses()->Contains("ResultInterface"))
    gROOT->LoadMacro("ResultInterface.C+");
  
  //Now finalsstate classes
  vector<TString > FSClasses={"Cuts","Combitorial","ParticleIter","Topology","FinalState","FiledTree","TopoActionManager","ParticleCuts","TreeParticleData","MVASignalID","ParticleCutsManager","ParticleDataManager","MVASignalIDManager"};

  for(auto const& name : FSClasses){
    if(Selection!=TString())
      if(!Selection.Contains(name)) continue;
    
    cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&& "<<name<<endl;
    if(!gROOT->GetListOfClasses()->Contains(name))
      gROOT->LoadMacro(name+".C+");
  }

 
}

