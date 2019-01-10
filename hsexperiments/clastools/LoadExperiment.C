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
    TString LZ4=C12TOOL+"Lz4/lib";
    gSystem->AddDynamicPath(LZ4);
    if(!gSystem->Load("liblz4")){
      //Found liblz4 in LD_LIBRARY_PATH 
      gROOT->ProcessLine("#define __LZ4__");
      gSystem->AddIncludePath("-D__LZ4__");
      gSystem->AddIncludePath(TString("-I")+LZ4);
    }
    else{
      printf("\n   >>>>> LZ4 compression is not supported.");
      printf("\n   >>>>> check if libz4 is installed on your system.");  
      printf("\n   >>>>> and included in LD_LIBRARY_PATH");  
    }
    //Add CLAS12TOOL Hipo classes
    gROOT->SetMacroPath(Form("%s:%s/Hipo",gROOT->GetMacroPath(),C12TOOL.Data()));
    gSystem->AddIncludePath(TString("-I")+C12TOOL+"/Hipo");
    gROOT->SetMacroPath(Form("%s:%s/Banks",gROOT->GetMacroPath(),C12TOOL.Data()));
    gSystem->AddIncludePath(TString("-I")+C12TOOL+"/Banks");
    
    std::vector<TString > HipoClasses={"utils","dictionary","node","event","record","reader","bank"};
    for(auto const& name : HipoClasses){
      std::cout<<"C12C12C12C12C12C12C12C12C12    "<<name<<std::endl;
      if(!gROOT->GetListOfClasses()->Contains(name))
	gROOT->LoadMacro(C12TOOL+"/Hipo/"+name+".cpp+");
    }
    
    std::vector<TString > C12BClasses={"header","particle","mcparticle","particle_detector","scintillator","calorimeter","cherenkov","forwardtagger","tracker","covmatrix","region_particle","region_ft","region_fdet","region_cdet","hallB_event"};
    for(auto const& name : C12BClasses){
      std::cout<<"C12C12C12C12C12C12C12C12C12    "<<name<<std::endl;
      if(!gROOT->GetListOfClasses()->Contains(name))
	gROOT->LoadMacro(C12TOOL+"/Banks/"+name+".cpp+");
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
