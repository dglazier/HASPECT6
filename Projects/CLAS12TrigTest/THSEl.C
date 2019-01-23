/**
 * \class THSEl
 * 
 * Template final class .
 * 
 * Users should create their own analysis specific project classes.
 * 
 */



#include "TDatabasePDG.h"
#include "THSEl.h"
#include <algorithm>


THSEl::THSEl(){
  SetVerbose(1);
  //CheckCombi(); //comment out to remove messages
  
  //Set final state detected particles
  //AddParticle(particle,true/false you want to write in final vector, genID for linking to generated truth value)
  //Note if particle is added to final with a valid genID it will be used
  //to determine the correct permutation of the simulated event
  AddParticle(&fElectron,kTRUE,-1);
  AddParticle(&fProton,kTRUE,-1);

  //Set final state parents
  
  
  
  TString PID("NONE"); //set this to which particles you want to id via pdg code alone, or set it in individual AddTopology
  TString INCLUSIVE("ALL");//set this to which particles you want reaction to be inclusive of, or set it in individual AddTopology "ALL"=> completely inclusive

  //include topology for analysis and get index
  AddTopology("e-",
             bind(&THSEl::Init_Iter0, this),
             bind(&THSEl::Topo_0, this),
             PID,INCLUSIVE);

  AddTopology("e-:proton",
             bind(&THSEl::Init_Iter1, this),
             bind(&THSEl::Topo_1, this),
             PID,INCLUSIVE);

  
  
  THSFinalState::InitFS();
}

void THSEl::FileStart(){
  //May be called when a new file is opened
  fTrigger.SetParticles(frDetParts); //the detected particles
  fTrigger.SetEventInfo(fEventInfo);//once per event info
  fTrigger.SetRunInfo(fRunInfo);//once per run info

  //Configure the cuts (default are delta timing cuts in ns)
  fCuts.SetElCut(1,0); //Just FT,FD
  fCuts.SetPionPCut(0,2,0,2);//FT,FDTOF,CD,FDCAL
  fCuts.SetPionMCut(0,2,0,2);//FT,FDTOF,CD,FDCAL
  fCuts.SetProtCut(0,2,1,2);//FT,FDTOF,CD,FDCAL
  fCuts.SetGammaCut(2,2,0,2);//FT,FDTOF,CD,FDCAL

  if(THSFinalState::frGenParts) fTrigger.SetSim();//Should get this from RunInfo but not correct in EB at the moment
  
}

//Define topology Iterator functions
void THSEl::Init_Iter0(){
  //THSParticle iterator initialisation
  //For topology e-

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
void THSEl::Init_Iter1(){
  //THSParticle iterator initialisation
  //For topology e-:proton

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
// void THSEl::Init_IterX(){
//  THSParticleIter* diter=CreateParticleIter(fTID_X,&fVecY,NPARTICLES);
//  ...
// }
//Define topology functions
void THSEl::Topo_0(){
  //For topology e-
  //if(fElectron.Detector()>0) {fGoodEvent=kFALSE;return;} //Put some cuts on particle detectors
  //Define starttime from electron candidate
  fTrigger.StartTime(&fElectron);
  //Subtract sarttime from all particles
  //e.g. fTrigger.SubtractStartTime(&fElectron,&fProton,&fPip,&fPim);
  fTrigger.SubtractStartTime(&fElectron);

  //Can apply some timing cuts now
  if(!fCuts.ElCut(&fElectron)){fGoodEvent=kFALSE;return;}
  //if(!fCuts.ElCut(&fElectron)){fGoodEvent=kFALSE;return;}
  //etc, e.g if(!fCuts.PionPCut(&fPip1)){fGoodEvent=kFALSE;return;}

  //Reconstruct missing or combined particles
  HSLorentzVector miss=fBeam+fTarget-fElectron.P4();
  //fMissMass2=miss.M2();
  fMissMass=miss.M();
  fMissTheta=miss.Theta();
  fMissP=miss.P();
  fAngle=TMath::Pi();
  fDeltaPhi=TMath::Pi();
}
void THSEl::Topo_1(){
  //For topology e-:proton
  //if(fElectron.Detector()>0) {fGoodEvent=kFALSE;return;} //Put some cuts on particle detectors
  //Define starttime from electron candidate
  fTrigger.StartTime(&fElectron);
  //Subtract sarttime from all particles
  //e.g. fTrigger.SubtractStartTime(&fElectron,&fProton,&fPip,&fPim);
  fTrigger.SubtractStartTime(&fElectron,&fProton);

  //Can apply some timing cuts now
  if(!fCuts.ElCut(&fElectron)){fGoodEvent=kFALSE;return;}
  if(!fCuts.ProtCut(&fProton)){fGoodEvent=kFALSE;return;}
  //etc, e.g if(!fCuts.PionPCut(&fPip1)){fGoodEvent=kFALSE;return;}

  //Reconstruct missing or combined particles
  //HSLorentzVector miss=fBeam+fTarget-fElectron.P4()...;
  //fMissMass2=miss.M2();
  //fMissMass=miss.M();
  HSLorentzVector miss=fBeam+fTarget-fElectron.P4();
  //fMissMass2=miss.M2();
  fMissMass=miss.M();
  fMissTheta=miss.Theta();
  fMissP=miss.P();
  fAngle=fKine.Angle(miss,fProton.P4());
  fDeltaPhi=fKine.DeltaPhi(miss,fProton.P4());
  
}
// void THSEl::Topo_X(){
// }

void THSEl::Kinematics(){
  //configure trigger for this event
  fTrigger.ReadParticles();
  //Do calculations if Good Event
  
  TMVAFill();
}
//////////////////////////////////////////////////
/// Define conditions for track to be considered
/// good in event. Adding conditions on junk tracks
///  can greatly reduce combitorials etc.
/// kFALSE=> track ignored completely
Bool_t THSEl::CheckParticle(THSParticle* part){
  if(part->Detector()<0)return kTRUE; //All FT tracks
  if(part->PDG()==45)return kFALSE; //? what are these?
  if(part->Time()==0)return kFALSE;   //Track needs time
  if(part->Charge()&&part->DeltaE()<2)return kFALSE; //Charged track needs deltaE>2

  return kTRUE;
}

void THSEl::FinalStateOutTree(TTree* tree){
  THSFinalState::fFinalTree=tree;
  //tree->Branch("Final",&fFinal);//If you want to save the final THSParticles
  tree->Branch("MissTheta",&fMissTheta,"MissTheta/D");
  tree->Branch("MissP",&fMissP,"MissP/D");
  tree->Branch("MissMass",&fMissMass,"MissMass/D");
  tree->Branch("Angle",&fAngle,"Angle/D");
  tree->Branch("DeltaPhi",&fDeltaPhi,"DeltaPhi/D");
  tree->Branch("Topo",&fTopoID,"Topo/I");
  tree->Branch("NPerm",&fNPerm,"NPerm/I");
  tree->Branch("NDet",&fNDet,"NDet/I");
  
  tree->Branch("ElTime",&fElTime,"ElTime/F");
  tree->Branch("ElEdep",&fElEdep,"ElEdep/F");
  tree->Branch("ElDeltaE",&fElDeltaE,"ElDeltaE/F");
  tree->Branch("ElPreE",&fElPreE,"ElPreE/F");
  tree->Branch("ElP",&fElP,"ElP/F");
  tree->Branch("ElTh",&fElTh,"ElTh/F");
  tree->Branch("ElPhi",&fElPhi,"ElPhi/F");
  tree->Branch("ElVz",&fElVz,"ElVz/F");
  tree->Branch("ElTrChi2",&fElTrChi2,"ElTrChi2/F");
  tree->Branch("ElDet",&fElDet,"ElDet/I");

  tree->Branch("PTime",&fPTime,"PTime/F");
  tree->Branch("PEdep",&fPEdep,"PEdep/F");
  tree->Branch("PDeltaE",&fPDeltaE,"PDeltaE/F");
  tree->Branch("PPreE",&fPPreE,"PPreE/F");
  tree->Branch("PP",&fPP,"PP/F");
  tree->Branch("PTh",&fPTh,"PTh/F");
  tree->Branch("PPhi",&fPPhi,"PPhi/F");
  tree->Branch("PVz",&fPVz,"PVz/F");
  tree->Branch("PTrChi2",&fPTrChi2,"PTrChi2/F");
  tree->Branch("PDet",&fPDet,"PDet/I");

}
void THSEl::TMVAFill(){
  fElTime=fElectron.DeltaTime();
  fElEdep=fElectron.Edep();
  fElDeltaE=fElectron.DeltaE();
  fElPreE=fElectron.PreE();
  fElP=fElectron.P4p()->P();
  fElTh=fElectron.P4p()->Theta();
  fElPhi=fElectron.P4p()->Phi();
  fElVz=fElectron.Vertex().Z();
  fElTrChi2=fElectron.TrChi2();
  fElDet=fCuts.Detector(fElectron.Detector());
 
  fPTime=fProton.DeltaTime();
  fPEdep=fProton.Edep();
  fPDeltaE=fProton.DeltaE();
  fPPreE=fProton.PreE();
  fPP=fProton.P4p()->P();
  fPTh=fProton.P4p()->Theta();
  fPPhi=fProton.P4p()->Phi();
  fPVz=fProton.Vertex().Z();
  fPTrChi2=fProton.TrChi2();
  fPDet=fCuts.Detector(fProton.Detector());
}
