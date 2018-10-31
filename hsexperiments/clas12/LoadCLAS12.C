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

void LoadCLAS12(){
  
  TString HSCODE=gSystem->Getenv("HSCODE");
  //First need DataManager
  gROOT->ProcessLine(".x $HSCODE/hsdata/LoadDataManager.C+");


  //Now CLAS12 specific setup  
  TString HSEXP=gSystem->Getenv("HSEXP");

  //Add HSMVA include path
  if(!TString(gInterpreter->GetIncludePath()).Contains(HSEXP)){
    gInterpreter->AddIncludePath(HSEXP);
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSEXP).Data()));
  }

  vector<TString > SkClasses={"EventInfo","RunInfo"};
  
  for(auto const& name : SkClasses){
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

}
