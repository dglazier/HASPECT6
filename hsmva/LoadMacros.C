#include <TSystem.h>
#include <TString.h>
#include <TInterpreter.h>
#include <TROOT.h>

namespace HS{namespace MVA{}};
using namespace HS::MVA;

void LoadMacros(){
  
  TString HSCODE=gSystem->Getenv("HSCODE");
  TString mvapath="/hsmva";
  
  gInterpreter->AddIncludePath(HSCODE+mvapath);
  gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+mvapath).Data()));
 
  gROOT->LoadMacro("FiledTree.C+");
  gROOT->LoadMacro("TrainingInterface.C+");
  gROOT->LoadMacro("TrainSignalID.C+");
  gROOT->LoadMacro("TrainReg.C+");
  gROOT->LoadMacro("TrainComparison.C+");
  gROOT->LoadMacro("ResultInterface.C+");



}
