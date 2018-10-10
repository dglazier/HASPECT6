#include <TSystem.h>
#include <TString.h>
#include <TInterpreter.h>
#include <TROOT.h>

namespace HS{};
using namespace HS;

void LoadMacros(){
  
  TString HSCODE=gSystem->Getenv("HSCODE");
  TString mvapath="/hsmva";
  TString fspath="/hsfinalstate";
  TString hspath="/HaSpect";
   
  gInterpreter->AddIncludePath(HSCODE+mvapath);
  gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+mvapath).Data()));
  gInterpreter->AddIncludePath(HSCODE+fspath);
  gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+fspath).Data()));
   gInterpreter->AddIncludePath(HSCODE+hspath);
  gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+hspath).Data()));

  gROOT->LoadMacro("THSParticle.C+");
  gROOT->LoadMacro("THSFinalState.C+");
  
  gROOT->LoadMacro("FiledTree.C+");
  gROOT->LoadMacro("TreeData.C+");
  //gROOT->LoadMacro("ResultInterface.C+");
  
  gROOT->LoadMacro("TopoActionManager.C+");
  gROOT->LoadMacro("ParticleCuts.C+");
  gROOT->LoadMacro("VarsParticle.C+");
  gROOT->LoadMacro("TreePrepParticle.C+");
  gROOT->LoadMacro("MVASignalID.C+");
  gROOT->LoadMacro("ParticleCutsManager.C+");
  gROOT->LoadMacro("TreePrepManager.C+");
  gROOT->LoadMacro("MVASignalIDManager.C+");


}
