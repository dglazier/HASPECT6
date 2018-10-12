#include "Pi2.h"
void Pi2::Topo_0(){
  //For topology Electron:Proton:Pip:Pim

  //if(fElectron.Detector()>0) {fGoodEvent=kFALSE;return;} //Put some cuts on particle detectors etc...
  //Define starttime from electron candidate
  fTrigger.StartTime(&fElectron);
  //Subtract starttime from all particles
  fTrigger.SubtractStartTime(&fElectron,&fProton,&fPip,&fPim);

  //Reconstruct missing or combined particles
  HSLorentzVector miss= fBeam + fTarget -fElectron.P4() -fProton.P4() -fPip.P4() -fPim.P4();
  TD.MissMass2=miss.M2();
  TD.MissMass=miss.M();
}
void Pi2::Topo_1(){
  //For topology Electron:Proton:Pip

  //if(fElectron.Detector()>0) {fGoodEvent=kFALSE;return;} //Put some cuts on particle detectors etc...
  //Define starttime from electron candidate
  fTrigger.StartTime(&fElectron);
  //Subtract starttime from all particles
  fTrigger.SubtractStartTime(&fElectron,&fProton,&fPip);

  //Reconstruct missing or combined particles
  HSLorentzVector miss= fBeam + fTarget -fElectron.P4() -fProton.P4() -fPip.P4();
  TD.MissMass2=miss.M2();
  TD.MissMass=miss.M();
  fPim.FixP4(miss);
}
void Pi2::Topo_2(){
  //For topology Electron:Proton:Pim

  //if(fElectron.Detector()>0) {fGoodEvent=kFALSE;return;} //Put some cuts on particle detectors etc...
  //Define starttime from electron candidate
  fTrigger.StartTime(&fElectron);
  //Subtract starttime from all particles
  fTrigger.SubtractStartTime(&fElectron,&fProton,&fPim);

  //Reconstruct missing or combined particles
  HSLorentzVector miss= fBeam + fTarget -fElectron.P4() -fProton.P4() -fPim.P4();
  TD.MissMass2=miss.M2();
  TD.MissMass=miss.M();
  fPip.FixP4(miss);
}
void Pi2::Topo_3(){
  //For topology Electron:Pip:Pim

  //if(fElectron.Detector()>0) {fGoodEvent=kFALSE;return;} //Put some cuts on particle detectors etc...
  //Define starttime from electron candidate
  fTrigger.StartTime(&fElectron);
  //Subtract starttime from all particles
  fTrigger.SubtractStartTime(&fElectron,&fPip,&fPim);

  //Reconstruct missing or combined particles
  HSLorentzVector miss= fBeam + fTarget -fElectron.P4() -fPip.P4() -fPim.P4();
  TD.MissMass2=miss.M2();
  TD.MissMass=miss.M();
  
  fProton.FixP4(miss);
}