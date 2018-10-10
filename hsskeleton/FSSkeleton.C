
#include "FSSkeleton.h"
#include <TSystem.h>
#include <iostream>

using namespace HS;

////////////////////////////////////////////////////
/// Create a FinalState project. \n
/// Set fFinalTopo with SetFinalStateTopo() \n
/// Set fFinalParts with SetFinalStateParts() \n
/// Set fFinalName with SetFinalState() \n
void FSSkeleton::MakeCode(){
  fPlace=0;
 
  if(fFinalTopo==TString(""))cout<<"Warning No finalstate topologies set, you will have to edit the files yourself"<<endl;
  else{
    fTopos=fFinalTopo.Tokenize(",");
  }
 
  if(fFinalParts==TString(""))cout<<"Warning No finalstate final state set, you will have to edit the files yourself"<<endl;
  else{
    fFinals=fFinalParts.Tokenize(",");
  }

  TString HSCODE=gSystem->Getenv("HSCODE");
  fHSSKEL=HSCODE+"/hsskeleton";

  //Copy template class header file
  gSystem->Exec(Form("cp %s/FinalState/FinalTemp.h %s.h",fHSSKEL.Data(),fFinalName.Data()));

  //Open the header file
  fCurMacro=TMacro(fFinalName+".h");

  //Replace FinalTemp with new class name
  ReplaceAllMacroText("FinalTemp",fFinalName);
  TString UpperFinalName=fFinalName;
  UpperFinalName.ToUpper();
  ReplaceAllMacroText("FINALTEMP",UpperFinalName);

  //Declare inti functions in .h
  DeclareInit();
  //Declare detected particles in .h
  DeclareDetected();
  //Now declare parent particles in .h
  DeclareParents();

  //For use in derived class to add additional functionalty
  DeclareExtras();
  
  //Save header code
  fCurMacro.SaveSource(fFinalName+".h");
  
  ///////////////////////////////////////////////////////
  //Copy the template class .C file
  gSystem->Exec(Form("cp %s/FinalState/FinalTemp.C %s.C",fHSSKEL.Data(),fFinalName.Data()));
  //Open code for editting
  fCurMacro=TMacro(fFinalName+".C");
  
  //replace all instances of FinalTemp with your defined name
  fPlace=0;
  ReplaceAllMacroText("FinalTemp",fFinalName);

  //Define Detected particles
  DefineDetected();
  //Define their parents if any declared
  if(fFinalParents!=TString("")) DefineParents(); 
  //Define each topology you have registered
  DefineTopologies();
  //Define the topology iterators
  DefineIterators();
  //Define topology functions
  //  DefineTopoFuncs(); //superceded by seperate TopoXXX.C file 
  //For use in derived class to add additional functionalty
  DefineExtras();

  //Save new source code
  fPlace=0;
  fCurMacro.SaveSource(fFinalName+".C");

  //Macros for running on data files
  CreateRunMacros();
 
  //Make the TreeData class
  CreateTreeData();
  //Now make a TopoFuncs file
  CreateTopoFuncs();
  //And the Kinematics file
  CreateKinematics();
  //And and the loader
  CreateLoader();
 
}

void FSSkeleton::DeclareInit(){
  //Declare Init functions
  fPlace=0;
  FindNextLineLike("//Init functions");
  for(Int_t io=0;io<fTopos->GetEntries();io++)
    ContinueLineAfter(Form("  void Init_Iter%d();",io));
  ContinueLineAfter("   //Topology action functions");
  for(Int_t io=0;io<fTopos->GetEntries();io++)
    ContinueLineAfter(Form("  void Topo_%d();",io));
}

void FSSkeleton::DeclareDetected(){
  //Declare detected particles in final state
  fPlace=0;
  FindNextLineLike("//Final Particles");
  for(Int_t io=0;io<fFinals->GetEntries();io++){
    TString sparticle=fFinals->At(io)->GetName();
    TString pname=TString(sparticle(0,sparticle.First(":")));
    if(pname==TString("Beam")){ //hack for tagged photons!
      ContinueLineAfter(Form("  THSParticle fBeam=THSParticle(-22);"));
    }
    else {
      ContinueLineAfter(Form("  THSParticle f%s=THSParticle(\"%s\");",TString(sparticle(0,sparticle.First(":"))).Data(),TString(sparticle(sparticle.First(":")+1,sparticle.Sizeof())).Data()));
    }
  }
}
void FSSkeleton::DeclareParents(){
   fPlace=0;
   if(fFinalParents!=TString("")){
     fParents=fFinalParents.Tokenize(",");
     fPlace=0;
     FindNextLineLike("//Final Parents");
     for(Int_t io=0;io<fParents->GetEntries();io++){
      TString sparticle=fParents->At(io)->GetName();
      ContinueLineAfter(Form("  THSParticle f%s=THSParticle(\"%s\");",TString(sparticle(0,sparticle.First(":"))).Data(),TString(sparticle(sparticle.First(":")+1,sparticle.First(";")-sparticle.First(":")-1)).Data()));
    }
  }
}
void FSSkeleton::DefineTopologies(){
  fPlace=0;
  FindNextLineLike("//include topology for analysis");
  for(Int_t io=0;io<fTopos->GetEntries();io++){
    ContinueLineAfter(Form("  AddNamesTopology(\"%s\",",fTopos->At(io)->GetName()));
    ContinueLineAfter(Form("             bind(&%s::Init_Iter%d, this),",fFinalName.Data(),io));
    ContinueLineAfter(Form("             bind(&%s::Topo_%d, this),",fFinalName.Data(),io));
    ContinueLineAfter(Form("             fPID,fINCLUSIVE);"));
    ContinueLineAfter("");
  }
}

void FSSkeleton::DefineIterators(){
  fPlace=0;
  FindNextLineLike("//Define topology Iterator functions");
  for(Int_t io=0;io<fTopos->GetEntries();io++){
    ContinueLineAfter(Form("void %s::Init_Iter%d(){",fFinalName.Data(),io));
    ContinueLineAfter("  //THSParticle iterator initialisation");
    ContinueLineAfter(Form("  //For topology %s",fTopos->At(io)->GetName()));
    ContinueLineAfter("");
    ContinueLineAfter("   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself");
    ContinueLineAfter("}");
    
  }
}
// void FSSkeleton::DefineTopoFuncs(){
//   fPlace=0;
//   FindNextLineLike("//Define topology functions");
//   for(Int_t io=0;io<fTopos->GetEntries();io++){
//     ContinueLineAfter(Form("void THS%s::Topo_%d(){",fFinalName.Data(),io));
//     ContinueLineAfter(Form("  //For topology %s",fTopos->At(io)->GetName()));

//     ContinueLineAfter("");
//     ContinueLineAfter("  //Reconstruct missing or combined particles");
//     ContinueLineAfter("  //HSLorentzVector miss=fBeam+fTarget-fElectron.P4()...;");
//     ContinueLineAfter("  //TD::MissMass2=miss.M2();");
//     ContinueLineAfter("  //TD::fMissMass=miss.M();");
//     ContinueLineAfter("}");
    
//   }

// }

void FSSkeleton::DefineDetected(){
  fPlace=0;
  FindNextLineLike("//Set final state detected particles");
  fPlace+=3;
  for(Int_t io=0;io<fFinals->GetEntries();io++){
    TString sparticle=fFinals->At(io)->GetName();
    TString pname=TString(sparticle(0,sparticle.First(":")));
    ContinueLineAfter(Form("  AddParticle(\"%s\",&f%s,kTRUE,-1);",pname.Data(),pname.Data()));
  }
}
void FSSkeleton::DefineParents(){
  fPlace=0;
  FindNextLineLike("//Set final state parents");
  for(Int_t io=0;io<fParents->GetEntries();io++){
    TString sparticle=fParents->At(io)->GetName();
    ContinueLineAfter(Form("  AddParticle(&f%s,kTRUE,-1);",TString(sparticle(0,sparticle.First(":"))).Data()));
    TObjArray *childs=sparticle.Tokenize(";");
    for(Int_t ic=1;ic<childs->GetEntries();ic++)
      ContinueLineAfter(Form("  ConfigParent(&f%s,&f%s);",TString(sparticle(0,sparticle.First(":"))).Data(),childs->At(ic)->GetName()));
  }
}

void FSSkeleton::CreateRunMacros(){
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

}
void FSSkeleton::CreateTreeData(){
  gSystem->Exec(Form("cp %s/FinalState/TreeDataXXX.C TreeData%s.C",fHSSKEL.Data(),fFinalName.Data()));
  fCurMacro=TMacro(TString("TreeData")+fFinalName+".C");
  fPlace=0;
  ReplaceAllMacroText("XXX",fFinalName);
  fCurMacro.SaveSource(TString("TreeData")+fFinalName+".C");

  gSystem->Exec(Form("cp %s/FinalState/TreeDataXXX.h TreeData%s.h",fHSSKEL.Data(),fFinalName.Data()));
  fCurMacro=TMacro(TString("TreeData")+fFinalName+".h");
  fPlace=0;
  ReplaceAllMacroText("XXX",fFinalName);
  fCurMacro.SaveSource(TString("TreeData")+fFinalName+".h");
}
void FSSkeleton::CreateKinematics(){
  //And the kinematics function
  fPlace=0;
  fCurMacro=TMacro();
  ContinueLineAfter(Form("#include \"%s.h\"",fFinalName.Data()));
  ContinueLineAfter(Form("void %s::Kinematics(){",fFinalName.Data()));
  ContinueLineAfter(Form("  //"));
  ContinueLineAfter("}");
  fCurMacro.SaveSource(TString("Kinematics")+fFinalName+".h");
}
void FSSkeleton::CreateTopoFuncs(){
  fCurMacro=TMacro();
  ContinueLineAfter(Form("#include \"%s.h\"",fFinalName.Data()));
  for(Int_t io=0;io<fTopos->GetEntries();io++){
    ContinueLineAfter(Form("void %s::Topo_%d(){",fFinalName.Data(),io));
    ContinueLineAfter(Form("  //For topology %s",fTopos->At(io)->GetName()));

    ContinueLineAfter("");
    ContinueLineAfter("  //Reconstruct missing or combined particles");
    ContinueLineAfter("  //HSLorentzVector miss=fBeam+fTarget-fElectron.P4()...;");
    ContinueLineAfter("  //fMissMass2=miss.M2();");
    ContinueLineAfter("  //fMissMass=miss.M();");
    ContinueLineAfter("}");
    
  }
  fCurMacro.SaveSource(TString("Topos")+fFinalName+".h");
}
void FSSkeleton::CreateLoader(){
  fCurMacro=TMacro();
  TString HSCODE=gSystem->Getenv("HSCODE");

  ContinueLineAfter(Form("{"));
  // ContinueLineAfter(Form("HSCODE=gSystem->Getenv(\"HSCODE\");"));
  ContinueLineAfter(Form("gROOT->ProcessLine(\".x %s/hsfinalstate/LoadFinalState.C+\");",HSCODE.Data()));
  ContinueLineAfter(Form("gROOT->LoadMacro(\"TreeData%s.C+\");",fFinalName.Data()));
  ContinueLineAfter(Form("gROOT->LoadMacro(\"%s.C+\");",fFinalName.Data()));
  ContinueLineAfter(Form("}"));
  fCurMacro.SaveSource(TString("Load")+fFinalName+".C");
}
// void FSSkeleton::DefineCLAS12(){
//     FindNextLineLike("FileStart(){");
//     fPlace++;
//     ContinueLineAfter("  fTrigger.SetParticles(frDetParts); //the detected particles");
//      ContinueLineAfter("  fTrigger.SetEventInfo(fEventInfo);//once per event info");
//     ContinueLineAfter("  fTrigger.SetRunInfo(fRunInfo);//once per run info");
//     ContinueLineAfter("");
//     ContinueLineAfter("  //Configure the cuts (default are delta timing cuts in ns)");
//     ContinueLineAfter("  fCuts.SetElCut(2,2); //Just FT,FD");
//     ContinueLineAfter("  fCuts.SetPionPCut(0,2,0,2);//FT,FDTOF,CD,FDCAL");
//     ContinueLineAfter("  fCuts.SetPionMCut(0,2,0,2);//FT,FDTOF,CD,FDCAL");
//     ContinueLineAfter("  fCuts.SetProtCut(0,2,1,2);//FT,FDTOF,CD,FDCAL");
//     ContinueLineAfter("  fCuts.SetGammaCut(2,2,0,2);//FT,FDTOF,CD,FDCAL");
//     ContinueLineAfter("");
//     ContinueLineAfter("  if(THSFinalState::frGenParts) fTrigger.SetSim();//Should get this from RunInfo but not correct in EB at the moment");

//     //  FindNextLineLike("Kinematics(){");
//     // ContinueLineAfter("  //configure trigger for this event");
//     //ContinueLineAfter("  fTrigger.ReadParticles();");

//     FindNextLineLike("CheckParticle(THSParticle* part){");
//     ContinueLineAfter("  //if(part->Detector()<0)return kTRUE; //All FT tracks");
//     ContinueLineAfter("  //if(part->PDG()==45)return kFALSE; //? what are these?");
//     ContinueLineAfter("  //if(part->Time()==0)return kFALSE;   //Track needs time");
//     ContinueLineAfter("  //if(part->Charge()&&part->DeltaE()<2)return kFALSE; //Charged track needs deltaE>2");
//     ContinueLineAfter("");


    // if(fIsCLAS12){
    //   ContinueLineAfter("  //if(fElectron.Detector()>0) {fGoodEvent=kFALSE;return;} //Put some cuts on particle detectors");
    //   ContinueLineAfter("  //Define starttime from electron candidate");
    //   ContinueLineAfter("  fTrigger.StartTime(&fElectron);");
    //   ContinueLineAfter("  //Subtract sarttime from all particles");
    //   ContinueLineAfter("  //e.g. fTrigger.SubtractStartTime(&fElectron,&fProton,&fPip,&fPim);");
    //   ContinueLineAfter("  fTrigger.SubtractStartTime(ADDPARTICLESHERE);");
    //   ContinueLineAfter("");
    //   ContinueLineAfter("  //Can apply some timing cuts now");
    //   ContinueLineAfter("  if(!fCuts.ElCut(&fElectron)){fGoodEvent=kFALSE;return;}");
    //   ContinueLineAfter("  //etc, e.g if(!fCuts.PionPCut(&fPip1)){fGoodEvent=kFALSE;return;}");
    // }
// }
