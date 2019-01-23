
#ifndef THSEL_h
#define THSEL_h

#include "THSFinalState.h"
#include "THSParticle.h"
#include "THSCLAS12Trigger.h"
#include "THSCLAS12DeltaTime.h"
#include <vector>

class THSEl : public THSFinalState{

 public :
  THSEl();
  ~THSEl()=default;


  //Init functions
  void Init_Iter0();
  void Init_Iter1();
   //Topology action functions
  void Topo_0();
  void Topo_1();
  void Init_Generated();
  //void Init_IterX();
  //void Topo_X();
  virtual void FileStart();
  virtual Bool_t  CheckParticle(THSParticle* part);

  void Kinematics();
  protected :

  THSCLAS12Trigger fTrigger;//For CLAS12 trigger info
  THSCLAS12DeltaTime fCuts; //For particle cuts
  
  //Initial state
  HSLorentzVector fBeam=HSLorentzVector(0,0,10.6,10.6);
  HSLorentzVector fTarget=HSLorentzVector(0,0,0,0.938272);

  //Final Particles Detected
  THSParticle fElectron=THSParticle("e-");
  THSParticle fProton=THSParticle("proton");
 
  //Final Parents
 
  //Observables
  Double_t f_t;
  Double_t f_Q2;
  Double_t f_W;
  Double_t f_EGamma;
  Double_t f_Pol;
  Double_t fCMCosTh;
  Double_t fCMPhi;

  //Discriminators
  Double_t fMissMass=0;
  Double_t fMissP=0;
  Double_t fMissTheta=0;
  Double_t fAngle=0;
  Double_t fDeltaPhi=0;
  Double_t fMissMass2=0;
  Float_t fElTime=0;
  Float_t fElEdep=0;
  Float_t fElDeltaE=0;
  Float_t fElPreE=0;
  Float_t fElP=0;
  Float_t fElTh=0;
  Float_t fElPhi=0;
  Float_t fElVz=0;
  Float_t fElTrChi2=0;
  Int_t fElDet=0;

  Float_t fPTime=0;
  Float_t fPEdep=0;
  Float_t fPDeltaE=0;
  Float_t fPPreE=0;
  Float_t fPP=0;
  Float_t fPTh=0;
  Float_t fPPhi=0;
  Float_t fPVz=0;
  Float_t fPTrChi2=0;
  Int_t fPDet=0;

   public :
  virtual void FinalStateOutTree(TTree* tree);
  void TMVAFill();
 

};

#endif //ifdef THSEl
