/**
 * \class K2
 * 
 * Template final class .
 * 
 * Users should create their own analysis specific project classes.
 * 
 */



#include "TDatabasePDG.h"
#include "K2.h"
#include <algorithm>

using namespace HS;
#include "KinematicsK2.h"
#include "ToposK2.h"

K2::K2(TString pid,TString inc):fPID(pid),fINCLUSIVE(inc){
  SetVerbose(1);
  // CheckCombi(); //comment out to remove messages
  
  //Set final state detected particles
  //AddParticle(particle,true/false you want to write in final vector, genID for linking to generated truth value)
  //Note if particle is added to final with a valid genID it will be used
  //to determine the correct permutation of the simulated event
  AddParticle("Beam",&fBeam,kTRUE,-1);
  AddParticle("Proton",&fProton,kTRUE,-1);
  AddParticle("Kp",&fKp,kTRUE,-1);
  AddParticle("Km",&fKm,kTRUE,-1);

  //Set final state parents
  
  
  //include topology for analysis and get index
  AddNamesTopology("Beam:Proton:Kp:Km",
             bind(&K2::Init_Iter0, this),
             bind(&K2::Topo_0, this),
             fPID,fINCLUSIVE);

  AddNamesTopology("Beam:Proton:Kp",
             bind(&K2::Init_Iter1, this),
             bind(&K2::Topo_1, this),
             fPID,fINCLUSIVE);

  AddNamesTopology("Beam:Proton:Km",
             bind(&K2::Init_Iter2, this),
             bind(&K2::Topo_2, this),
             fPID,fINCLUSIVE);

  AddNamesTopology("Beam:Kp:Km",
             bind(&K2::Init_Iter3, this),
             bind(&K2::Topo_3, this),
             fPID,fINCLUSIVE);

  
  
  FinalState::InitFS();
}

void K2::FileStart(){
  //May be called when a new file is opened
  //Pass the data to the trigger object
  fTrigger.SetParticles(frDetParts); //the detected particles
  fTrigger.SetEventInfo(fEventInfo);//once per event info
  fTrigger.SetRunInfo(fRunInfo);//once per run info


  //if(fRunInfo->fType) fTrigger.SetSim();//Should get this from RunInfo but not correct in EB at the moment
  
}
///Will be called after the Topo_ functions
///And before PostTopoManager
void K2::UserPostTopo() {
  //configure trigger for this event
  fTrigger.ReadParticles();
 }
void K2::FinalStateOutTree(TTree* tree){
  HS::FinalState::fFinalTree=tree;
  //tree->Branch("Final",&fFinal);//If you want to save the final THSParticles

  //Variables held in the base HS::FinalState class
  tree->Branch("Topo",&fTopoID,"Topo/I");
  tree->Branch("Correct",&fCorrect,"Correct/I");
  tree->Branch("NPerm",&fNPerm,"NPerm/I");
  tree->Branch("NDet",&fNDet,"NDet/I");
  tree->Branch("UID",&fUID,"UID/D");

  //make branches with TreeData object
  TD.Branches(tree);
}
//////////////////////////////////////////////////
/// Define conditions for track to be considered
/// good in event. Adding conditions on junk tracks
///  can greatly reduce combitorials etc.
/// kFALSE=> track ignored completely
Bool_t K2::CheckParticle(HS::THSParticle* part){
  return kTRUE;
}
void K2::Init_Iter0(){
  //THSParticle iterator initialisation
  //For topology Beam:Proton:Kp:Km

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
void K2::Init_Iter1(){
  //THSParticle iterator initialisation
  //For topology Beam:Proton:Kp

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
void K2::Init_Iter2(){
  //THSParticle iterator initialisation
  //For topology Beam:Proton:Km

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
void K2::Init_Iter3(){
  //THSParticle iterator initialisation
  //For topology Beam:Kp:Km

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
  //Can place some cuts on tracks we do not like...
  //These will be completly ignored
  //if(part->Time()==0)return kFALSE;   //Track needs time

