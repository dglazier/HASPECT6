#include <TSystem.h>
#include <TString.h>
#include <TInterpreter.h>
#include <TApplication.h>
#include <TROOT.h>
#include <TProof.h>
#include <iostream>

namespace HS{namespace FIT{}};
using namespace HS;
using namespace HS::FIT;

void LoadFitProof(Int_t Nworkers=1,TString Selection=""){
  
  TString HSCODE=gSystem->Getenv("HSCODE");
  TString fitpath=HSCODE+"/hsfit";
  TString dmpath=HSCODE+"/hsdata";
  TString PWD=gSystem->Getenv("PWD");

  //Now finalsstate classes
  vector<TString > DATAClasses={"FiledTree","Bins","Weights"};
  vector<TString > FITClasses= {"RooHSEventsPDF","RooHSEventsHistPDF","Setup","Data","Binner","PlotResults","BootStrapper","FitManager","sPlot","FitSelector","Process"};


  if(!TString(gInterpreter->GetIncludePath()).Contains(fitpath)){
    gInterpreter->AddIncludePath(fitpath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(fitpath).Data()));
  }
  
  if(!TString(gInterpreter->GetIncludePath()).Contains(dmpath)){
    gInterpreter->AddIncludePath(dmpath);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(dmpath).Data()));
  }
  if(!TString(gInterpreter->GetIncludePath()).Contains(PWD)){
    gInterpreter->AddIncludePath(PWD);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(PWD).Data()));
  }
  gSystem->Load("libProof.so");
  TProof *proof =nullptr;
  if(!gProof) 
    proof = TProof::Open("://lite");
  else
    proof=gProof;
  
  Int_t NCores=Nworkers;
  proof->SetParallel(NCores);
  
  proof->Load("PhiAsymmetryPDF.cxx+");

  proof->AddIncludePath(fitpath);
  proof->AddIncludePath(dmpath);

  for(auto const& name : DATAClasses){
    if(Selection!=TString())
      if(!Selection.Contains(name)) continue;
    
    std::cout<<"DDDDDDDDDDDDDDDDDDDDDD "<<name<<std::endl;
    if(!gROOT->GetListOfClasses()->Contains(name))
      proof->Load(dmpath+"/"+name+".C++",kTRUE);
  }
  for(auto const& name : FITClasses){
    if(Selection!=TString())
      if(!Selection.Contains(name)) continue;
    
    std::cout<<"FFFFFFFFFFFFFFFFFFFFFFF "<<name<<std::endl;
    if(!gROOT->GetListOfClasses()->Contains(name))
      proof->Load(fitpath+"/"+name+".C++",kTRUE);
  }

  
  // for(Int_t i=1;i<gApplication->Argc();i++){
  //   TString opt=gApplication->Argv(i);
  //  if(opt.Contains("--")&&opt.Contains(".cxx")){opt.Remove(0,2); cout<<"Loading "<<opt<<endl;proof->Load(opt);} //Load additional THS classes
  //   if(opt.Contains("--")&&opt.Contains(".cpp")){opt.Remove(0,2); cout<<"Loading "<<opt<<endl;proof->Load(opt);} //Load additional THS classes
  //   if(opt.Contains("--")&&opt.Contains(".C")){opt.Remove(0,2); cout<<"Loading "<<opt<<endl;proof->Load(opt);} //Load additional THS classes
  //   if(opt.Contains("--")&&opt.Contains(".cc")){opt.Remove(0,2); cout<<"Loading "<<opt<<endl;proof->Load(opt);} //Load additional THS classes
  // }

}
