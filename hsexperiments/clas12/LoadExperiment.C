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
  //DataManager need THSParticle
  gROOT->LoadMacro("$HSEXP/THSParticle.C+");

  //First need DataManager
  gROOT->ProcessLine(".x $HSCODE/hsdata/LoadDataManager.C+");
 

  vector<TString > DataClasses={"EventInfo","RunInfo","ParticleData"};
  
  for(auto const& name : DataClasses){
    cout<<"12121212121212121212121212 "<<name<<endl;
    if(!gROOT->GetListOfClasses()->Contains(name))
      gROOT->LoadMacro(name+".C+");
  }


  // Now we can load Hipo readers
  TString RHIPO=gSystem->Getenv("RHIPO");
  if(RHIPO!=TString("")) {
    gROOT->ProcessLine(".x $RHIPO/Hipo2Root.C+");
    //Add classes
    std::vector<TString > DMClasses={"HipoReader","HipoTrigger","HipoDST"};
    for(auto const& name : DMClasses){
      std::cout<<"HHHHHHHHHHHHHHHHHHHHHHHH    "<<name<<std::endl;
      if(!gROOT->GetListOfClasses()->Contains(name))
	gROOT->LoadMacro(HSEXP+"/"+name+".C+");
    }
  }
  else{
    cout<<"Warning : LoadHipo() You need to set RHIPO"<<endl;
  }

 // Now we can Load FinalState
  TString HSFINAL=gSystem->Getenv("HSFINAL");
  if(HSFINAL!=TString("")) {
    //First need DataManager
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
