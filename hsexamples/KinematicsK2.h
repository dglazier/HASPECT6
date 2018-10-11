#include "K2.h"
void K2::Kinematics(){

  //Calculate possible resonances
  HSLorentzVector pMeson=fKp.P4()+fKm.P4();
  HSLorentzVector pHyperon=fProton.P4()+fKm.P4();
  //invariant masses
  TD.MesonMass=pMeson.M();
  TD.HyperonMass=pHyperon.M();
  
  fKine.SetGammaTarget(fBeam.P4(),fTarget);
  TD.Eg=fBeam.P4().E(); //photon bem energy

  //calculate CM production kinematics for meson
  fKine.SetMesonBaryon(pMeson,fProton.P4());
  fKine.PhotoCMDecay();
  TD.MesonCosTh=fKine.CosTheta();//prefix all variables to be saved wiht TM.
  TD.MesonPhi=fKine.Phi();
  
  //calculate CM production kinematics for hyperon
  fKine.SetMesonBaryon(fKp.P4(),pHyperon);
  fKine.PhotoCMDecay();
  TD.HyperonCosTh=fKine.CosTheta();//prefix all variables to be saved wiht TM.
  TD.HyperonPhi=fKine.Phi();

}