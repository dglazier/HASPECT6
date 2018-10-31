#include "Pi2.h"
void Pi2::Kinematics(){
  TD.TrigNSector=fTrigger.TrigNSectors();
  TD.TrigNSectorRoads=fTrigger.TrigNSectorsRoads();

   //Calculate possible resonances
  HSLorentzVector pMeson=fPip.P4()+fPim.P4();
  HSLorentzVector pDpp=fProton.P4()+fPip.P4();
  HSLorentzVector pD0=fProton.P4()+fPim.P4();
  //invariant masses
  TD.MesonMass=pMeson.M();
  TD.DppMass=pDpp.M();
  TD.D0Mass=pD0.M();
  
  fKine.SetElecsTarget(fBeam,fElectron.P4(),fTarget);
  TD.W=fKine.W(); //photon bem energy
  TD.Q2=fKine.Q2();
  TD.Pol=fKine.GammaPol();
  TD.Egamma=fKine.GammaE();
  
  //calculate CM production kinematics for meson
  fKine.SetMesonBaryon(pMeson,fProton.P4());
  fKine.ElectroCMDecay();
  TD.MesonCosTh=fKine.CosTheta();//prefix all variables to be saved wiht TM.
  TD.MesonPhi=fKine.Phi();
  
  TD.ElTh=fElectron.P4p()->Theta()*TMath::RadToDeg();
  TD.ElP=fElectron.P4p()->P();
  TD.ElTime=fElectron.DeltaTime();
  TD.ProtTh=fProton.P4p()->Theta()*TMath::RadToDeg();
  TD.ProtP=fProton.P4p()->P();
  TD.ProtTime=fProton.DeltaTime();
  TD.PipTh=fPip.P4p()->Theta()*TMath::RadToDeg();
  TD.PipP=fPip.P4p()->P();
  TD.PipTime=fPip.DeltaTime();
  TD.PimTh=fPim.P4p()->Theta()*TMath::RadToDeg();
  TD.PimP=fPim.P4p()->P();
  TD.PimTime=fPim.DeltaTime();

  
}