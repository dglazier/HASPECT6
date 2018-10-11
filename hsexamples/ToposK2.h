#include "K2.h"
void K2::Topo_0(){
  //For topology Beam:Proton:Kp:Km

  //Subtract starttime from all particles
  //This has been predetermined from the tagger time
  fTrigger.SubtractStartTime(&fProton,&fKp,&fKm);
  fTrigger.SubtractStartTimeBeam(&fProton,&fBeam);

  fProton.TakeCorrectedP();//Apply eloss
  fKp.TakeCorrectedP();//Apply eloss
  fKm.TakeCorrectedP();//Apply eloss

  //Reconstruct missing or combined particles
  HSLorentzVector miss= fBeam.P4() + fTarget -fProton.P4() -fKp.P4() -fKm.P4();
  TD.MissMass2=miss.M2();
  TD.MissMass=miss.M();
}
void K2::Topo_1(){
  //For topology Beam:Proton:Kp

  //Subtract starttime from all particles
  //This has been predetermined from the tagger time
  fTrigger.SubtractStartTime(&fProton,&fKp);
  fTrigger.SubtractStartTimeBeam(&fProton,&fBeam);

  fProton.TakeCorrectedP();//Apply eloss
  fKp.TakeCorrectedP();//Apply eloss
  
  //Reconstruct missing or combined particles
  HSLorentzVector miss= fBeam.P4() + fTarget -fProton.P4() -fKp.P4();
  TD.MissMass2=miss.M2();
  TD.MissMass=miss.M();
  fKm.FixP4(miss);
}
void K2::Topo_2(){
  //For topology Beam:Proton:Km

  //Subtract starttime from all particles
  //This has been predetermined from the tagger time
  fTrigger.SubtractStartTime(&fProton,&fKm);
  fTrigger.SubtractStartTimeBeam(&fProton,&fBeam);

  fProton.TakeCorrectedP();//Apply eloss
  fKm.TakeCorrectedP();//Apply eloss

  //Reconstruct missing or combined particles
  HSLorentzVector miss= fBeam.P4() + fTarget -fProton.P4() -fKm.P4();
  TD.MissMass2=miss.M2();
  TD.MissMass=miss.M();
  fKp.FixP4(miss);
}
void K2::Topo_3(){
  //For topology Beam:Kp:Km

  //Subtract starttime from all particles
  //This has been predetermined from the tagger time
  fTrigger.SubtractStartTime(&fKp,&fKm);
  fTrigger.SubtractStartTimeBeam(&fKp,&fBeam);

  fKp.TakeCorrectedP();//Apply eloss
  fKm.TakeCorrectedP();//Apply eloss

//Reconstruct missing or combined particles
  HSLorentzVector miss= fBeam.P4() + fTarget -fKp.P4() -fKm.P4();
  TD.MissMass2=miss.M2();
  TD.MissMass=miss.M();
  
  fProton.FixP4(miss);
}