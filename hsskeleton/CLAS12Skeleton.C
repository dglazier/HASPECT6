#include "CLAS12Skeleton.h"
#include <TSystem.h>
#include <iostream>

using namespace HS;


void CLAS12Skeleton::CreateRunMacros(){
  //Create some sample Run macros
  //First for LUND files
  gSystem->Exec(Form("cp %s/FinalState/RunFSLund.C RunFSLund%s.C",fHSSKEL.Data(),fFinalName.Data()));
  fCurMacro=TMacro(TString("RunFSLund")+fFinalName+".C");
  fPlace=0;
  ReplaceAllMacroText("XXX",fFinalName);
  fCurMacro.SaveSource(TString("RunFSLund")+fFinalName+".C");

  //And for ROOT files
  gSystem->Exec(Form("cp %s/FinalState/RunFSRoot.C RunFSRoot%s.C",fHSSKEL.Data(),fFinalName.Data()));
  fCurMacro=TMacro(TString("RunFSRoot")+fFinalName+".C");
  fPlace=0;
  ReplaceAllMacroText("XXX",fFinalName);
  fCurMacro.SaveSource(TString("RunFSRoot")+fFinalName+".C");

  gSystem->Exec(Form("cp %s/FinalState/RunFSHipo.C RunFSHipo%s.C",fHSSKEL.Data(),fFinalName.Data()));
  fCurMacro=TMacro(TString("RunFSHipo")+fFinalName+".C");
  fPlace=0;
  ReplaceAllMacroText("XXX",fFinalName);
  fCurMacro.SaveSource(TString("RunFSHipo")+fFinalName+".C");
}
void CLAS12Skeleton::DeclareCLAS12(){
    fPlace=0;
    FindNextLineLike("THSParticle.h");
    ContinueLineAfter("#include \"CLAS12Trigger.h\"");
    ContinueLineAfter("#include \"CLAS12DeltaTime.h\"");
    
    FindNextLineLike("//Initial state");
    fPlace-=2;
    ContinueLineAfter("  HS::CLAS12::CLAS12Trigger fTrigger;//For CLAS12 trigger info");
    ContinueLineAfter("  HS::CLAS12::CLAS12DeltaTime fCuts; //For particle cuts");

    FindNextLineLike("//Initial state");
    ContinueLineAfter("  HS::HSLorentzVector fBeam=HS::HSLorentzVector(0,0,10.6,10.6);");
   
}

void CLAS12Skeleton::DefineCLAS12(){
  // fCurMacro=TMacro(fFinalName+".C");
  fPlace=0;

  FindNextLineLike("FileStart(){");
  fPlace++;
  ContinueLineAfter("  //Pass the data to the trigger object");
  ContinueLineAfter("  fTrigger.SetParticles(frDetParts); //the detected particles");
  ContinueLineAfter("  fTrigger.SetEventInfo(fEventInfo);//once per event info");
  ContinueLineAfter("  fTrigger.SetRunInfo(fRunInfo);//once per run info");
  ContinueLineAfter("");
  ContinueLineAfter("  //fTrigger.SetTimeShiftFT(16.45)");
  ContinueLineAfter("  //fTrigger.SetSTimePeak(125.45);");

  FindNextLineLike("UserPostTopo()");
  ContinueLineAfter("  //configure trigger for this event");
  ContinueLineAfter("  fTrigger.ReadParticles();");
  
  fPlace=0;
  FindNextLineLike("CheckParticle(THSParticle* part){");
  ContinueLineAfter("  //Can place some cuts on tracks we do not like...");
  ContinueLineAfter("  //These will be completly ignored");
  ContinueLineAfter("  //if(part->Detector()<0)return kTRUE; //All FT tracks");
  ContinueLineAfter("  //if(part->PDG()==45)return kFALSE; //? what are these?");
  ContinueLineAfter("  //if(part->Time()==0)return kFALSE;   //Track needs time");
  ContinueLineAfter("  //if(part->Charge()&&part->DeltaE()<2)return kFALSE; //Charged track needs deltaE>2");
  ContinueLineAfter("");

  //fCurMacro.SaveSource(fFinalName+".C");

}

void CLAS12Skeleton::CreateTopoFuncs(){
  fCurMacro=TMacro();
  fPlace=0;
  ContinueLineAfter(Form("#include \"%s.h\"",fFinalName.Data()));
  for(Int_t io=0;io<fTopos->GetEntries();io++){
    ContinueLineAfter(Form("void %s::Topo_%d(){",fFinalName.Data(),io));
    ContinueLineAfter(Form("  //For topology %s",fTopos->At(io)->GetName()));
    ////////////////////////////////////////////////////
    //Additional stuff here
    ContinueLineAfter("");
    ContinueLineAfter("  //if(fElectron.Detector()>0) {fGoodEvent=kFALSE;return;} //Put some cuts on particle detectors etc...");
    ContinueLineAfter("  //Define starttime from electron candidate");
    ContinueLineAfter("  fTrigger.StartTime(&fElectron);");
    ContinueLineAfter("  //Subtract starttime from all particles");

    fFinals=TString(fTopos->At(io)->GetName()).Tokenize(":");
    cout<<" Create Topo "<<fTopos->At(io)->GetName()<<" "<<fFinals->GetEntries()<<endl;

    TString nextline="  fTrigger.SubtractStartTime(";
    for(Int_t io=0;io<fFinals->GetEntries();io++){
      TString pname=fFinals->At(io)->GetName();
      nextline+="&f";
      nextline+=pname;
      if(io!=fFinals->GetEntries()-1)nextline+=",";
      else nextline+=");";
    }
    ContinueLineAfter(nextline);
    ContinueLineAfter("");
    //Done
    //////////////////////////////////////////////////////
    ContinueLineAfter("  //Reconstruct missing or combined particles");
    nextline="  HSLorentzVector miss= fBeam + fTarget ";
    for(Int_t io=0;io<fFinals->GetEntries();io++){
      TString pname=fFinals->At(io)->GetName();
      nextline+="-f";
      nextline+=pname;
      nextline+=".P4()";
      if(io!=fFinals->GetEntries()-1)nextline+=" ";
      else nextline+=";";
    }
    ContinueLineAfter(nextline);
    ContinueLineAfter("  TD.MissMass2=miss.M2();");
    ContinueLineAfter("  TD.MissMass=miss.M();");
    ContinueLineAfter("}");
    
  }
  fCurMacro.SaveSource(TString("Topos")+fFinalName+".h");
}
