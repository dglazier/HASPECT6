#include "TDatabasePDG.h"
#include "THSFinalTemp.h"
#include <algorithm>

//ClassImp(THSFinalTemp)

THSFinalTemp::THSFinalTemp(){
  //include topology for analysis and get index
 
  //Set final state
}
Bool_t THSFinalTemp::WorkOnEvent(){
  //Should this event be saved?
  fGoodEvent=kTRUE;
  fCorrect=0; //Correct permutation? used for simulation only
  //If generated MC events
  if(fIsGenerated) Init_Generated();
  else{//Look for reconstructed events
    //if reconstructed Find the detected particles in this event
    if(FindTopology()==-1) {fGoodEvent=kFALSE;return fIsPermutating0=kFALSE;}
    //Do they correspond to a defined topology?
    // else if(fCurrTopo==fTID_) Init_();
    else fGoodEvent=kFALSE;
    //Get truth values
    Init_Generated();
  }
  
  //Calc kinematics
  Kinematics();
  
  //Check if assigned vectors agree with true generated
  //Simulation only
  CheckTruth();
  
  //Can do some checks if event is worth writing or not
  //if()fGoodEvent=kTRUE;
  //else() fGoodEvent =kFALSE;
  if(fIsGenerated) return kFALSE; //Generated only 1 permutation
  PermutateParticles();
  return kFALSE;
}
void THSFinalTemp::Init_Generated(){
  if(!frGenParts) return;
  if(frGenParts->size()!=REPLACE_WITH_N_GENERATED_PARTICLES) {fGoodEvent=kFALSE;return;}
  //Fill our data member particles
  //User is responsible for indicing right
  //comes from order in generated file (e.g LUND)
  if(fIsGenerated){
    //fElectron=*frGenParts->at(0);
  }
  else{//Just assign truth values
    //fElectron.SetTruth(frGenParts->at(0));
  }
}
//Define topology Init functions
// void THSFinalTemp::Init_(){
//   //Fill data member particles
//   //Particle vectors will be permutated over
//   //fElectron=*fVecMinus.at(0);
//   //(OR if PID) fElectron=*fVecEls.at(0);

// }

void THSFinalTemp::Kinematics(){
  if(!fGoodEvent) return;//don't do calculations
  //Do calculations if Good Event

}

void THSFinalTemp::FinalStateOutTree(TTree* tree){
  fFinalTree=tree;
  tree->Branch("Final",&fFinal);
  tree->Branch("MissMass",&fMissMass,"MissMass/D");

}