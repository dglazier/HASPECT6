#include <TSystem.h>
#include <TString.h>
#include <TInterpreter.h>
#include <TROOT.h>
#include <vector>
#include <iostream>

namespace HS{};
using namespace HS;

void LoadHSFit(TString Selection=""){
  
  TString HSCODE=gSystem->Getenv("HSCODE");
  
  TString dmpath="/hsdata";
  TString fitpath="/hsfit";
  
  //Add HSDATA include path
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSCODE+dmpath)){
    gInterpreter->AddIncludePath(HSCODE+dmpath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+dmpath).Data()));
  }
  
  //Add HSFit include path
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSCODE+fitpath)){
    gInterpreter->AddIncludePath(HSCODE+fitpath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+fitpath).Data()));
  }
  
  //First need DataManager for weights and bins
  gROOT->ProcessLine(".x $HSCODE/hsdata/LoadDataManager.C+(\"Bins:Weights\")");
  
  
  //Now hsfit classes
  vector<TString > FSClasses={"RooHSEventsPDF","RooHSEventsHistPDF","HSMCMC","HSRooFit","HSsPlot"};

  for(auto const& name : FSClasses){
    if(Selection!=TString())
      if(!Selection.Contains(name)) continue;
    cout<<"FFFFFFFFFFFFFFFFFFFFFFFFF "<<name<<endl;
    if(!gROOT->GetListOfClasses()->Contains(name))
      gROOT->LoadMacro(name+".C+");
  }
  
  
}

