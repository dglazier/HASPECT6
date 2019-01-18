#include <TSystem.h>
#include <TString.h>
#include <TInterpreter.h>
#include <TROOT.h>

namespace HS{namespace DF{}};
using namespace HS;
using namespace HS::DF;

void LoadDF(){
  
  TString HSCODE=gSystem->Getenv("HSCODE");
  TString dfpath="/hsdf";
  
  gInterpreter->AddIncludePath(HSCODE+dfpath);
  gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+dfpath).Data()));
 
  gROOT->LoadMacro("DataFrameApp.C+");
  gROOT->LoadMacro("Canvaser.C+");



}
