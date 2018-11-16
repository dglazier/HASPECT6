#include "K2.h"
void K2::Kinematics(){

  //Calculate possible resonances
  HSLorentzVector pMeson=fKp.P4()+fKm.P4();
  HSLorentzVector pHyperon=fProton.P4()+fKm.P4();
  //invariant masses
  TD.MesonMass=pMeson.M();
  TD.HyperonMass=pHyperon.M();
  
  fKine.SetGammaTarget(fBeam.P4(),fTarget);
  TD.Eg=fBeam.P4p()->E(); //photon bem energy

   TD.PolState=0;
   TD.Pol=fBeam.Vertex().X();
   if(TD.Pol)
      TD.PolState=1;
    else{
      TD.Pol=fBeam.Vertex().Y();
      if(TD.Pol)TD.PolState=-1;
    }
    
  //calculate CM production kinematics for meson
  fKine.SetMesonBaryon(pMeson,fProton.P4());
  fKine.PhotoCMDecay();
  TD.t=fKine.t();
  TD.MesonCosTh=fKine.CosTheta();//prefix all variables to be saved wiht TM.
  TD.MesonPhi=fKine.Phi();
  
  //Get phi decay variables
  fKine.SetMesonDecay(fKp.P4(),fKm.P4());
  fKine.MesonDecayHelicity();
  TD.HelCosTh=fKine.CosTheta();
  TD.HelPhi=fKine.Phi();

  //calculate CM production kinematics for hyperon
  fKine.SetMesonBaryon(fKp.P4(),pHyperon);
  fKine.PhotoCMDecay();
  TD.HyperonCosTh=fKine.CosTheta();//prefix all variables to be saved wiht TM.
  TD.HyperonPhi=fKine.Phi();
  

}