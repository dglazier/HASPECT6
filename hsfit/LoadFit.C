#include <TSystem.h>
#include <TString.h>
#include <TInterpreter.h>
#include <TROOT.h>
#include <iostream>

namespace HS{namespace FIT{namespace PROCESS{}}};
using namespace HS;
using namespace HS::FIT;
using namespace HS::FIT::PROCESS;

void LoadFit(TString Selection=""){
  
  TString HSCODE=gSystem->Getenv("HSCODE");
  TString fitpath="/hsfit";
  TString dmpath="/hsdata";
   
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSCODE+fitpath)){
    gInterpreter->AddIncludePath(HSCODE+fitpath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+fitpath).Data()));
  }
  
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSCODE+dmpath)){
    gInterpreter->AddIncludePath(HSCODE+dmpath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+dmpath).Data()));
  }

  //Now finalsstate classes
  vector<TString > FITClasses={"FiledTree","Bins","Weights","RooHSComplex","RooHSEventsPDF","RooHSEventsHistPDF","RooComponentsPDF","RooHSSphHarmonic","Setup","Data","Binner","Minimiser","HSSequentialProposal","HSMetropolisHastings","RooMcmc","PlotResults","BootStrapper","FitManager","sPlot","ToyManager","FitSelector","Process","PdfParser","ComponentsPdfParser","PredefinedParsers"};

  for(auto const& name : FITClasses){
    if(Selection!=TString())
      if(!Selection.Contains(name)) continue;
    
    std::cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ "<<name<<std::endl;
    if(!gROOT->GetListOfClasses()->Contains(name))
      gROOT->LoadMacro(name+".C+");
  }


  //  gROOT->LoadMacro("Setup.C+");
  //gROOT->LoadMacro("Data.C+");
 


}
