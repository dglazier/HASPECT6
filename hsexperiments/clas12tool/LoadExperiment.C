#include <TSystem.h>
#include <TString.h>
#include <TInterpreter.h>
#include <TROOT.h>
#include <vector>
#include <iostream>

namespace HS{
  namespace CLAS12{}
};
using namespace HS::CLAS12;

void LoadExperiment(){
  
  TString HSCODE=gSystem->Getenv("HSCODE");
  //Now CLAS12 specific setup  
  TString HSEXP=gSystem->Getenv("HSEXP");
  //Add CLAS12 include path
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSEXP)){
    gInterpreter->AddIncludePath(HSEXP);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSEXP).Data()));
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSEXP+"/scripts").Data()));
  }
  //Add CLAS12TOOL paths.
  TString C12TOOL=gSystem->Getenv("CLAS12TOOL");
  if(C12TOOL!=TString("")) {
    TString USE_HIPO4=gSystem->Getenv("USE_HIPO4");
    
    TString LIB=C12TOOL+"/lib/";
    gSystem->Load(LIB+"liblz4");
    if(USE_HIPO4!=TString()){
      gSystem->Load(LIB+"libHipo4");
      gSystem->Load(LIB+"libClas12Banks4");
    }
    else{
      gSystem->Load(LIB+"libHipo3");
    gSystem->Load(LIB+"libClas12Banks3");
    }
    
  }
  else{
    cout<<"Warning : LoadExperiment() You need to set CLAS12TOOL"<<endl;
  }
   
  //DataManager need THSParticle
  gROOT->LoadMacro("$HSEXP/BaseParticle.C+");
  gROOT->LoadMacro("$HSEXP/THSParticle.C+");
  //  gROOT->LoadMacro("$HSEXP/ParticleData.C+");

  //First need DataManager
  gROOT->ProcessLine(".x $HSCODE/hsdata/LoadDataManager.C+");
 

  vector<TString > DataClasses={"EventInfo","RunInfo","HipoToolsReader","ParticleData"};
  
  for(auto const& name : DataClasses){
    cout<<"12121212121212121212121212 "<<name<<endl;
    if(!gROOT->GetListOfClasses()->Contains(name))
      gROOT->LoadMacro(name+".C+");
  }

 
 // Now we can Load FinalState
  TString HSFINAL=gSystem->Getenv("HSFINAL");
  if(HSFINAL!=TString("")) {
    gROOT->ProcessLine(".x $HSCODE/hsfinalstate/LoadFinalState.C+");

    //additional classes for this experiment
    vector<TString > DataClasses={"CLAS12Trigger","CLAS12DeltaTime"};
  
    for(auto const& name : DataClasses){
      cout<<"12121212121212121212121212 "<<name<<endl;
      if(!gROOT->GetListOfClasses()->Contains(name))
	gROOT->LoadMacro(name+".C+");
    }
  
  }
 
  
}
