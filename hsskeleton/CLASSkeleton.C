
#include "CLASSkeleton.h"
#include <TSystem.h>
#include <iostream>

using namespace HS;

void CLASSkeleton::DeclareCLAS(){
    fPlace=0;
    FindNextLineLike("THSParticle.h");
    ContinueLineAfter("#include \"CLASTrigger.h\"");
    //ContinueLineAfter("#include \"DeltaTimeCut.h\"");
    
    FindNextLineLike("//Initial state");
    fPlace-=2;
    ContinueLineAfter("  HS::CLASTrigger fTrigger;//For CLAS trigger info");
    //ContinueLineAfter("  CLASDeltaTime fCuts; //For particle cuts");

    FindNextLineLike("//Initial state");
    
}

void CLASSkeleton::DefineCLAS(){
  // fCurMacro=TMacro(fFinalName+".C");
  fPlace=0;

  FindNextLineLike("FileStart(){");
  fPlace++;
  ContinueLineAfter("  //Pass the data to the trigger object");
  ContinueLineAfter("  fTrigger.SetParticles(frDetParts); //the detected particles");
  ContinueLineAfter("  fTrigger.SetEventInfo(fEventInfo);//once per event info");
  ContinueLineAfter("  fTrigger.SetRunInfo(fRunInfo);//once per run info");
  ContinueLineAfter("");
  ContinueLineAfter("");
  ContinueLineAfter("  if(fRunInfo->Type()) fTrigger.SetSim();//Should get this from RunInfo but not correct in EB at the moment");

  FindNextLineLike("UserPostTopo()");
  ContinueLineAfter("  //configure trigger for this event");
  ContinueLineAfter("  fTrigger.ReadParticles();");
  
  fPlace=0;
  FindNextLineLike("CheckParticle(THSParticle* part){");
  ContinueLineAfter("  //Can place some cuts on tracks we do not like...");
  ContinueLineAfter("  //These will be completly ignored");
 
  ContinueLineAfter("  //if(part->Time()==0)return kFALSE;   //Track needs time");
  ContinueLineAfter("");

  //fCurMacro.SaveSource(fFinalName+".C");

}

void CLASSkeleton::CreateTopoFuncs(){
  fCurMacro=TMacro();
  fPlace=0;
  ContinueLineAfter(Form("#include \"%s.h\"",fFinalName.Data()));
  for(Int_t io=0;io<fTopos->GetEntries();io++){
    ContinueLineAfter(Form("void %s::Topo_%d(){",fFinalName.Data(),io));
    ContinueLineAfter(Form("  //For topology %s",fTopos->At(io)->GetName()));

    fFinals=TString(fTopos->At(io)->GetName()).Tokenize(":");
    cout<<" Create Topo "<<fTopos->At(io)->GetName()<<" "<<fFinals->GetEntries()<<endl;
  
    
    ////////////////////////////////////////////////////
    //Additional stuff here
    ContinueLineAfter("");
    ContinueLineAfter("  //Subtract starttime from all particles");
    ContinueLineAfter("  //This has been predetermined from the tagger time");
    
    TString nextline="  fTrigger.SubtractStartTime(";
    for(Int_t io=0;io<fFinals->GetEntries();io++){
      TString pname=fFinals->At(io)->GetName();
      cout<<pname<<endl;
      if(pname==TString("Beam")) continue;
      nextline+="&f";
      nextline+=pname;
      if(io!=fFinals->GetEntries()-1)nextline+=",";
      else nextline+=");";
    }
    ContinueLineAfter(nextline);
    ContinueLineAfter("  //Now correct the beam time with z-vertex");
    ContinueLineAfter("  //You should give a particle with a good z-vertex here along with the beam");
    ContinueLineAfter("  //fTrigger.SubtractStartTimeBeam(&PPP,&fBeam);"); //replae PPP wiht your best particle vertex and comment in line
    ContinueLineAfter("");
    //Done
    //////////////////////////////////////////////////////
    ContinueLineAfter("  //Reconstruct missing or combined particles");
    // ContinueLineAfter("  //HSLorentzVector miss=fBeam+fTarget-...;");
    nextline="  HSLorentzVector miss= fBeam.P4() + fTarget ";
    for(Int_t io=0;io<fFinals->GetEntries();io++){
      TString pname=fFinals->At(io)->GetName();
      if(pname=="Beam") continue;
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
