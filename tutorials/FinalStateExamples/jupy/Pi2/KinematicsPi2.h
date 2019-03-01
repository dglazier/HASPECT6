#include "Pi2.h"
void Pi2::Kinematics(){
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

}