/**
 * \class FinalTemp
 * 
 * Template final class .
 * 
 * Users should create their own analysis specific project classes.
 * 
 */



#include "TDatabasePDG.h"
#include "FinalTemp.h"
#include "KinematicsFinalTemp.h"
#include "ToposFinalTemp.h"
#include <algorithm>

using namespace HS;

FinalTemp::FinalTemp(TString pid,TString inc):fPID(pi),fINCLUSIVE(inc){
  SetVerbose(1);
  CheckCombi(); //comment out to remove messages
  
  //Set final state detected particles
  //AddParticle(particle,true/false you want to write in final vector, genID for linking to generated truth value)
  //Note if particle is added to final with a valid genID it will be used
  //to determine the correct permutation of the simulated event

  //Set final state parents
  
  
  //include topology for analysis and get index
  
  
  FinalState::InitFS();
}

void FinalTemp::FileStart(){
  //May be called when a new file is opened
  
}
///Will be called after the Topo_ functions
///And before PostTopoManager
void FinalTemp::UserPostTopo() {
}
void FinalTemp::FinalStateOutTree(TTree* tree){
  HS::FinalState::fFinalTree=tree;
  //tree->Branch("Final",&fFinal);//If you want to save the final THSParticles

  //Variables held in the base HS::FinalState class
  tree->Branch("Topo",&fTopoID,"Topo/I");
  tree->Branch("Correct",&fCorrect,"Correct/I");
  tree->Branch("NPerm",&fNPerm,"NPerm/I");
  tree->Branch("NDet",&fNDet,"NDet/I");

  //make branches with TreeData object
  TD.Branches(tree,&TD);
}
//////////////////////////////////////////////////
/// Define conditions for track to be considered
/// good in event. Adding conditions on junk tracks
///  can greatly reduce combitorials etc.
/// kFALSE=> track ignored completely
Bool_t FinalTemp::CheckParticle(THSParticle* part){
  return kTRUE;
}
