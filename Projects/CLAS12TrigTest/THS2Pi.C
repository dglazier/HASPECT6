/**
 * \class THS2Pi
 * 
 * Template final class .
 * 
 * Users should create their own analysis specific project classes.
 * 
 */



#include "TDatabasePDG.h"
#include "THS2Pi.h"
#include <algorithm>


THS2Pi::THS2Pi(){
  SetVerbose(1);
  //CheckCombi(); //comment out to remove messages
  
  //Set final state detected particles
  //AddParticle(particle,true/false you want to write in final vector, genID for linking to generated truth value)
  //Note if particle is added to final with a valid genID it will be used
  //to determine the correct permutation of the simulated event
  AddParticle(&fElectron,kTRUE,-1);
  AddParticle(&fProton,kTRUE,-1);
  AddParticle(&fPip,kTRUE,-1);
  AddParticle(&fPim,kTRUE,-1);
  AddParticle(&fPi0,kTRUE,-1);

  //Set final state parents
  AddParticle(&fOmega,kTRUE,-1);
  ConfigParent(&fOmega,&fPip);
  ConfigParent(&fOmega,&fPim);
  ConfigParent(&fOmega,&fPi0);
  
  
  
  TString PID("NONE"); //set this to which particles you want to id via pdg code alone, or set it in individual AddTopology
  TString INCLUSIVE("ALL");//set this to which particles you want reaction to be inclusive of, or set it in individual AddTopology "ALL"=> completely inclusive

  //include topology for analysis and get index
  AddTopology("e-:pi+:pi-:proton",
             bind(&THS2Pi::Init_Iter0, this),
             bind(&THS2Pi::Topo_0, this),
             PID,INCLUSIVE);

  AddTopology("e-:pi+:proton",
             bind(&THS2Pi::Init_Iter1, this),
             bind(&THS2Pi::Topo_1, this),
             PID,INCLUSIVE);

  AddTopology("e-:pi-:proton",
             bind(&THS2Pi::Init_Iter2, this),
             bind(&THS2Pi::Topo_2, this),
             PID,INCLUSIVE);

  AddTopology("e-:pi+:pi-",
             bind(&THS2Pi::Init_Iter3, this),
             bind(&THS2Pi::Topo_3, this),
             PID,INCLUSIVE);

  
  
  THSFinalState::InitFS();
}

void THS2Pi::FileStart(){
  //May be called when a new file is opened
  fTrigger.SetParticles(frDetParts); //the detected particles
  fTrigger.SetEventInfo(fEventInfo);//once per event info
  fTrigger.SetRunInfo(fRunInfo);//once per run info
  // fTrigger.SetTimeShiftFT(174.85);
  fTrigger.SetTimeShiftFT(-7);
  fTrigger.SetSTimePeak(124.25);
  
  //Configure the cuts (default are delta timing cuts in ns)
  fCuts.SetElCut(1E5,1E5); //Just FT,FD
  fCuts.SetPionPCut(0,1E5,0,1E5);//FT,FDTOF,CD,FDCAL
  fCuts.SetPionMCut(0,1E5,0,1E5);//FT,FDTOF,CD,FDCAL
  fCuts.SetProtCut(0,1E5,1E5,1E5);//FT,FDTOF,CD,FDCAL
  fCuts.SetGammaCut(2E5,2E5,0,2E5);//FT,FDTOF,CD,FDCAL

  // if(THSFinalState::frGenParts) fTrigger.SetSim();//Should get this from RunInfo but not correct in EB at the moment
  
}

//Define topology Iterator functions
void THS2Pi::Init_Iter0(){
  //THSParticle iterator initialisation
  //For topology e-:pi+:pi-:proton

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
void THS2Pi::Init_Iter1(){
  //THSParticle iterator initialisation
  //For topology e-:pi+:proton

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
void THS2Pi::Init_Iter2(){
  //THSParticle iterator initialisation
  //For topology e-:pi-:proton

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
void THS2Pi::Init_Iter3(){
  //THSParticle iterator initialisation
  //For topology e-:pi+:pi-

   AutoIter(); //Let finalstate try and work out the iterattor for you, you can remove this if you want to do it yourself
}
// void THS2Pi::Init_IterX(){
//  THSParticleIter* diter=CreateParticleIter(fTID_X,&fVecY,NPARTICLES);
//  ...
// }
//Define topology functions
void THS2Pi::Topo_0(){
  //For topology e-:pi+:pi-:proton
  //if(fElectron.Detector()>0) {fGoodEvent=kFALSE;return;} //Put some cuts on particle detectors
  //Define starttime from electron candidate
  fTrigger.StartTime(&fElectron);
  //Subtract sarttime from all particles
  fTrigger.SubtractStartTime(&fElectron,&fProton,&fPip,&fPim);

  //Can apply some timing cuts now
  // if(!fCuts.ElCut(&fElectron)){fGoodEvent=kFALSE;return;}
  // if(!fCuts.ProtCut(&fProton)){fGoodEvent=kFALSE;return;}
  // if(!fCuts.PionPCut(&fPip)){fGoodEvent=kFALSE;return;}
  // if(!fCuts.PionMCut(&fPim)){fGoodEvent=kFALSE;return;}
 //etc, e.g if(!fCuts.PionPCut(&fPip1)){fGoodEvent=kFALSE;return;}

  fMissV=fBeam+fTarget-fElectron.P4()-fProton.P4();
  fMissMassP=fMissV.M();
  fMissV=fBeam+fTarget-fElectron.P4()-fProton.P4();
  fMissMass=fMissV.M();
  fMissV=fBeam+fTarget-fElectron.P4()-fProton.P4()-fPip.P4()-fPim.P4();
  fMissE=fMissV.E();
  fMissMom=fMissV.P();
  fMissMomX=fMissV.X();
  fMissMomY=fMissV.Y();  
  fMissMass2=fMissV.M2();
  fMissMass=fMissV.M();
  
}
void THS2Pi::Topo_1(){
  //For topology e-:pi+:proton
  //if(fElectron.Detector()>0) {fGoodEvent=kFALSE;return;} //Put some cuts on particle detectors
  //Define starttime from electron candidate
  fTrigger.StartTime(&fElectron);
  //Subtract sarttime from all particles
  fTrigger.SubtractStartTime(&fElectron,&fProton,&fPip);

  //Can apply some timing cuts now
  //if(!fCuts.ElCut(&fElectron)){fGoodEvent=kFALSE;return;}
  //etc, e.g if(!fCuts.PionPCut(&fPip1)){fGoodEvent=kFALSE;return;}
  // if(!fCuts.ElCut(&fElectron)){fGoodEvent=kFALSE;return;}
  // if(!fCuts.ProtCut(&fProton)){fGoodEvent=kFALSE;return;}
  // if(!fCuts.PionPCut(&fPip)){fGoodEvent=kFALSE;return;}

  //Reconstruct missing or combined particles
  //HSLorentzVector miss=fBeam+fTarget-fElectron.P4()...;
  //fMissMass2=miss.M2();
  //fMissMass=miss.M();
  fMissV=fBeam+fTarget-fElectron.P4()-fProton.P4();
  fMissMassP=fMissV.M();
   fMissV=fBeam+fTarget-fElectron.P4()-fProton.P4()-fPip.P4();
  fMissE=fMissV.E();
  fMissMom=fMissV.P();
  fMissMomX=fMissV.X();
  fMissMomY=fMissV.Y();  
  fMissMass2=fMissV.M2();
  fMissMass=fMissV.M();
}
void THS2Pi::Topo_2(){
  //For topology e-:pi-:proton
  //if(fElectron.Detector()>0) {fGoodEvent=kFALSE;return;} //Put some cuts on particle detectors
  //Define starttime from electron candidate
  fTrigger.StartTime(&fElectron);
  //Subtract sarttime from all particles
  fTrigger.SubtractStartTime(&fElectron,&fProton,&fPim);

  //Can apply some timing cuts now
  //  if(!fCuts.ElCut(&fElectron)){fGoodEvent=kFALSE;return;}
  //etc, e.g if(!fCuts.PionPCut(&fPip1)){fGoodEvent=kFALSE;return;}
  // if(!fCuts.ElCut(&fElectron)){fGoodEvent=kFALSE;return;}
  // if(!fCuts.ProtCut(&fProton)){fGoodEvent=kFALSE;return;}
  // if(!fCuts.PionMCut(&fPim)){fGoodEvent=kFALSE;return;}
 
  //Reconstruct missing or combined particles
  //HSLorentzVector miss=fBeam+fTarget-fElectron.P4()...;
  //fMissMass2=miss.M2();
  //fMissMass=miss.M();
  fMissV=fBeam+fTarget-fElectron.P4()-fProton.P4();
  fMissMassP=fMissV.M();
  fMissV=fBeam+fTarget-fElectron.P4()-fProton.P4()-fPim.P4();
  fMissE=fMissV.E();
  fMissMom=fMissV.P();
  fMissMomX=fMissV.X();
  fMissMomY=fMissV.Y();  
  fMissMass2=fMissV.M2();
  fMissMass=fMissV.M();
}
void THS2Pi::Topo_3(){
  //For topology e-:pi+:pi-
  //if(fElectron.Detector()>0) {fGoodEvent=kFALSE;return;} //Put some cuts on particle detectors
  //Define starttime from electron candidate
  fTrigger.StartTime(&fElectron);
  //Subtract sarttime from all particles
  fTrigger.SubtractStartTime(&fElectron,&fProton,&fPip,&fPim);

  // if(!fCuts.ElCut(&fElectron)){fGoodEvent=kFALSE;return;}
  // if(!fCuts.PionPCut(&fPip)){fGoodEvent=kFALSE;return;}
  // if(!fCuts.PionMCut(&fPim)){fGoodEvent=kFALSE;return;}

  //Reconstruct missing or combined particles
  //HSLorentzVector miss=fBeam+fTarget-fElectron.P4()...;
  //fMissMass2=miss.M2();
  //fMissMass=miss.M();
  fMissV=fBeam+fTarget-fElectron.P4()-fProton.P4();
  fMissMassP=fMissV.M();
  fMissV=fBeam+fTarget-fElectron.P4()-fPip.P4()-fPim.P4();
  fMissE=fMissV.E();
  fMissMom=fMissV.P();
  fMissMomX=fMissV.X();
  fMissMomY=fMissV.Y();  
  fMissMass2=fMissV.M2();
  fMissMass=fMissV.M();
}

void THS2Pi::Kinematics(){
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
Bool_t THS2Pi::CheckParticle(THSParticle* part){
  if(part->Detector()<0)return kTRUE; //All FT tracks
  if(part->PDG()==45)return kFALSE; //? what are these?
  if(part->Time()==0)return kFALSE;   //Track needs time
  if(part->Charge()&&part->DeltaE()<2)return kFALSE; //Charged track needs deltaE>2

  return kTRUE;
}

void THS2Pi::FinalStateOutTree(TTree* tree){
  THSFinalState::fFinalTree=tree;
  //tree->Branch("Final",&fFinal);//If you want to save the final THSParticles
  tree->Branch("MissMass",&fMissMass,"MissMass/D");
  tree->Branch("Topo",&fTopoID,"Topo/I");
  tree->Branch("NPerm",&fNPerm,"NPerm/I");
  tree->Branch("NDet",&fNDet,"NDet/I");
  tree->Branch("MissMass2Pi",&fMissMass2Pi,"MissMass2Pi/D");
  tree->Branch("MissMass2",&fMissMass2,"MissMass2/D");
  tree->Branch("MissMassP",&fMissMassP,"MissMassP/D");
  tree->Branch("MissE",&fMissE,"MissE/D");
  tree->Branch("MissMom",&fMissMom,"MissMom/D");
  tree->Branch("MissMomX",&fMissMomX,"MissMomX/D");
  tree->Branch("MissMomY",&fMissMomY,"MissMomY/D");

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
 
  tree->Branch("PipTime",&fPipTime,"PipTime/F");
  tree->Branch("PipEdep",&fPipEdep,"PipEdep/F");
  tree->Branch("PipDeltaE",&fPipDeltaE,"PipDeltaE/F");
  tree->Branch("PipPreE",&fPipPreE,"PipPreE/F");
  tree->Branch("PipP",&fPipP,"PipP/F");
  tree->Branch("PipTh",&fPipTh,"PipTh/F");
  tree->Branch("PipPhi",&fPipPhi,"PipPhi/F");
  tree->Branch("PipVz",&fPipVz,"PipVz/F");
  tree->Branch("PipTrChi2",&fPipTrChi2,"PipTrChi2/F");
  tree->Branch("PipDet",&fPipDet,"PipDet/I");

  tree->Branch("PimTime",&fPimTime,"PimTime/F");
  tree->Branch("PimEdep",&fPimEdep,"PimEdep/F");
  tree->Branch("PimDeltaE",&fPimDeltaE,"PimDeltaE/F");
  tree->Branch("PimPreE",&fPimPreE,"PimPreE/F");
  tree->Branch("PimP",&fPimP,"PimP/F");
  tree->Branch("PimTh",&fPimTh,"PimTh/F");
  tree->Branch("PimPhi",&fPimPhi,"PimPhi/F");
  tree->Branch("PimVz",&fPimVz,"PimVz/F");
  tree->Branch("PimTrChi2",&fPimTrChi2,"PimTrChi2/F");
  tree->Branch("PimDet",&fPimDet,"PimDet/I");
}
void THS2Pi::TMVAFill(){
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

  fPipTime=fPip.DeltaTime();
  fPipEdep=fPip.Edep();
  fPipDeltaE=fPip.DeltaE();
  fPipPreE=fPip.PreE();
  fPipP=fPip.P4p()->P();
  fPipTh=fPip.P4p()->Theta();
  fPipPhi=fPip.P4p()->Phi();
  fPipVz=fPip.Vertex().Z();
  fPipTrChi2=fPip.TrChi2();
  fPipDet=fCuts.Detector(fPip.Detector());

  fPimTime=fPim.DeltaTime();
  fPimEdep=fPim.Edep();
  fPimDeltaE=fPim.DeltaE();
  fPimPreE=fPim.PreE();
  fPimP=fPim.P4p()->P();
  fPimTh=fPim.P4p()->Theta();
  fPimPhi=fPim.P4p()->Phi();
  fPimVz=fPim.Vertex().Z();
  fPimTrChi2=fPim.TrChi2();
  fPimDet=fCuts.Detector(fPip.Detector());
}
