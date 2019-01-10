/**
 * \class Pi2
 * 
 * Template final class .
 * 
 * Users should create their own analysis specific project classes.
 * 
 */



#include "TDatabasePDG.h"
#include "Pi2.h"
#include "KinematicsPi2.h"
#include "ToposPi2.h"
#include <algorithm>

using namespace HS;

Pi2::Pi2(TString pid,TString inc):fPID(pid),fINCLUSIVE(inc){
  SetVerbose(1);
  // CheckCombi(); //comment out to remove messages
  
  //Set final state detected particles
  //AddParticle(particle,true/false you want to write in final vector, genID for linking to generated truth value)
  //Note if particle is added to final with a valid genID it will be used
  //to determine the correct permutation of the simulated event
  AddParticle("Electron",&fElectron,kTRUE,3);
  AddParticle("Proton",&fProton,kTRUE,2);
  AddParticle("Pip",&fPip,kTRUE,0);
  AddParticle("Pim",&fPim,kTRUE,1);

  //Set final state parents
  
  
  //include topology for analysis and get index
  AddNamesTopology("Electron:Proton:Pip:Pim",
             bind(&Pi2::Init_Iter0, this),
             bind(&Pi2::Topo_0, this),
             fPID,fINCLUSIVE);

  AddNamesTopology("Electron:Proton:Pip",
             bind(&Pi2::Init_Iter1, this),
             bind(&Pi2::Topo_1, this),
             fPID,fINCLUSIVE);

  AddNamesTopology("Electron:Proton:Pim",
             bind(&Pi2::Init_Iter2, this),
             bind(&Pi2::Topo_2, this),
             fPID,fINCLUSIVE);

  AddNamesTopology("Electron:Pip:Pim",
             bind(&Pi2::Init_Iter3, this),
             bind(&Pi2::Topo_3, this),
             fPID,fINCLUSIVE);

  
  
  FinalState::InitFS();
}

void Pi2::FileStart(){
  //May be called when a new file is opened
  //Pass the data to the trigger object
  fTrigger.SetParticles(frDetParts); //the detected particles
  fTrigger.SetEventInfo(fEventInfo);//once per event info
  fTrigger.SetRunInfo(fRunInfo);//once per run info
  fTrigger.SetTimeShiftFT(0);
  //  fTrigger.SetTimeShiftFT(16.45);
  //  fTrigger.SetSTimePeak(125.45);
  fTrigger.SetSTimePeak(124.2);

   
}
///Will be called after the Topo_ functions
///And before PostTopoManager
void Pi2::UserPostTopo() {
  //configure trigger for this event
  //fTrigger.ReadParticles();
}
void Pi2::FinalStateOutTree(ttree_ptr tree){
  //  HS::FinalState::fFinalTree=tree;
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
Bool_t Pi2::CheckParticle(THSParticle* part){
  //Can place some cuts on tracks we do not like...
  //These will be completly ignored
  //if(part->Detector()<0)return kTRUE; //All FT tracks
  if(part->PDG()==45)return kFALSE; //? what are these?
  //if(part->Time()==0)return kFALSE;   //Track needs time
  //if(part->Charge()&&part->DeltaE()<2)return kFALSE; //Charged track needs deltaE>2

  return kTRUE;
}
void Pi2::Init_Iter0(){
  //THSParticle iterator initialisation
  //For topology Electron:Proton:Pip:Pim

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
void Pi2::Init_Iter1(){
  //THSParticle iterator initialisation
  //For topology Electron:Proton:Pip

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
void Pi2::Init_Iter2(){
  //THSParticle iterator initialisation
  //For topology Electron:Proton:Pim

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
void Pi2::Init_Iter3(){
  //THSParticle iterator initialisation
  //For topology Electron:Pip:Pim

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
