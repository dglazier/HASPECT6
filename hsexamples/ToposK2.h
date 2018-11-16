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
  
    //particle kine
  TD.ProtP=fProton.P4p()->P();
  TD.ProtTh=fProton.P4p()->Theta()*TMath::RadToDeg();
  TD.ProtTime=fProton.DeltaTime();
  
  TD.KpP=fKp.P4p()->P();
  TD.KpTh=fKp.P4p()->Theta()*TMath::RadToDeg();
  TD.KpTime=fKp.DeltaTime();
  
  TD.KmP=fKm.P4p()->P();
  TD.KmTh=fKm.P4p()->Theta()*TMath::RadToDeg();
  TD.KmTime=fKm.DeltaTime();
  
  TD.BeamTime=fBeam.DeltaTime();

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
  
    //particle kine
  TD.ProtP=fProton.P4p()->P();
  TD.ProtTh=fProton.P4p()->Theta()*TMath::RadToDeg();
  TD.ProtTime=fProton.DeltaTime();
  
  TD.KpP=fKp.P4p()->P();
  TD.KpTh=fKp.P4p()->Theta()*TMath::RadToDeg();
  TD.KpTime=fKp.DeltaTime();
  
  TD.KmP=0;
  TD.KmTh=0;
  TD.KmTime=0;
  
  TD.BeamTime=fBeam.DeltaTime();

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

  //particle kine
  TD.ProtP=fProton.P4p()->P();
  TD.ProtTh=fProton.P4p()->Theta()*TMath::RadToDeg();
  TD.ProtTime=fProton.DeltaTime();
  
  TD.KpP=0;
  TD.KpTh=0;
  TD.KpTime=0;
  
  TD.KmP=fKm.P4p()->P();
  TD.KmTh=fKm.P4p()->Theta()*TMath::RadToDeg();
  TD.KmTime=fKm.DeltaTime();
  
  TD.BeamTime=fBeam.DeltaTime();

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

  //particle kine
  TD.ProtP=0;
  TD.ProtTh=0;
  TD.ProtTime=0;
  
  TD.KpP=fKp.P4p()->P();
  TD.KpTh=fKp.P4p()->Theta()*TMath::RadToDeg();
  TD.KpTime=fKp.DeltaTime();
  
  TD.KmP=fKm.P4p()->P();
  TD.KmTh=fKm.P4p()->Theta()*TMath::RadToDeg();
  TD.KmTime=fKm.DeltaTime();
  
  TD.BeamTime=fBeam.DeltaTime();

}