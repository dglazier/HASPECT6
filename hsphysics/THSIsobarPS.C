//--Author      DI Glazier 20/05/2016
//--Rev
//--Update
//--Description
//HASPECT Event Reconstruction

/**
	\class THSIsobarPS
	
	Class to identify particles which may have come from an isobar and which may not.
	Assume t-channel process for calculations.
	
*/

#include "THSIsobarPS.h"
#include <TLorentzRotation.h>

THSIsobarPS::THSIsobarPS(Int_t Np){
  // fNpart=Np;
  // fP4s.reserve(fNpart);
  // fCM.SetXYZT(0,0,0,0);
  // fSector=0;
  // fSize=0;
  // //fSectName.reserve(Nsector);
  //  for(Int_t i=1;i<fNpart;i++){//loop over numbers at top,bottom vertex (1->fNpart-1) must always have at least 1 on top and bottom!!
  //   //increment the sector number
  //   Int_t NT=fNpart-i; //number of particles on top 
  //   Int_t NB=fNpart-NT;  //number of particles on bottom
  //   MakeIndices(Np,NT);  //make vectors with Top and Botton particle indices
 
  //  }//end topologies

  // cout<<"For "<<Np <<"  particles there are "<<fSector<< "valid sectors"<<endl; 
  // fNSector=fSector;
  // fSector=0;
}

////////////////////////////////////////////////////////////////////////////////////
///Function to determine whether the d1,d2 particles could have formed an isobar
///from the 3 particle decay with z0 as the third particle. \n
///e.g. if one wants to study gp->p rho->p pi pi: \n
///In order to check if the two pions could come from an isobar (rho) one would call \n
///IsIsobar(ProtonVec,PiPlusVec,PiMinusVec,BeamVec)
Bool_t THSIsobarPS::IsIsobar(TLorentzVector z0,TLorentzVector d1,TLorentzVector d2,TLorentzVector beam){
  //Construct the 3 particle CM
  TLorentzVector CM=z0+d1+d2;
  TVector3 CMboost=-CM.BoostVector();
  TLorentzRotation CMRot(CMboost);
  TLorentzVector zVec=CM;
  //zVec*=CMboost;
  // zVec.Boost(CMboost); //boost z-axis to CM
  //zVec=-zVec; //switch to along -ve direction
  //fCM+=zVec;
  //Helicity angles
  TLorentzVector iso=d1+d2;
  TLorentzRotation isoBoost(-(iso).BoostVector());//boost into iso restfame
  TLorentzVector d1iso=isoBoost*d1;
  TLorentzVector d2iso=isoBoost*d2;
  TLorentzVector z0iso=isoBoost*z0;
  TLorentzVector  bmiso=isoBoost*CM;
  TVector3 zHel=-z0iso.Vect().Unit();
  TVector3 yHel=(z0iso.Vect().Unit().Cross(bmiso.Vect().Unit())).Unit();
  TVector3 xHel=yHel.Cross(zHel).Unit();
  TVector3 AnglesHel1(d1iso.Vect().Dot(xHel),d1iso.Vect().Dot(yHel),d1iso.Vect().Dot(zHel));
  fCosHel=AnglesHel1.CosTheta(); 

  //construct CMhel coordinate system
  iso*=CMboost;
  TVector3 zCM=zVec.Vect().Unit();//i.e. in the isobar momentum direction
  TVector3 yCM=(CMboost.Unit().Cross(iso.Vect().Unit())).Unit();//perp to z0 and CM
  TVector3 xCM=yCM.Cross(zCM).Unit(); //normal 

  d1*=CMboost; //boost daughters into CM 
  d2*=CMboost;
  // TVector3 AnglesCM1(d1.Vect().Dot(xCM),d1.Vect().Dot(yCM),d1.Vect().Dot(zCM));
  //TVector3 AnglesCM2(d2.Vect().Dot(xCM),d2.Vect().Dot(yCM),d2.Vect().Dot(zCM));
  fOmega=TMath::ATan2(d1.Z(),d2.Z());

  TVector3 AnglesCMIso(iso.Vect().Dot(xCM),iso.Vect().Dot(yCM),iso.Vect().Dot(zCM));
  fCosTh=AnglesCMIso.CosTheta();
  //   cout<<"COSTH "<<fCosTh<<" "<<TMath::Cos(CM.Angle(iso.Vect()))<<" "<<CM.Theta()<<" "<<CM.Rho()<<endl;

  TLorentzVector isoCM(iso); //Iso 4vector in CM
  isoCM.SetTheta(0); //"rotate" to along z-axis = iso CMhel momentum
  TVector3 boostIso=isoCM.BoostVector(); //boost vector to iso rest frame

  Double_t P12=breakupMomentum((d1+d2).M(),d1.M(),d2.M());
  Float_t Pmin1,Pmin2;
  Float_t Pmax1,Pmax2;

  //calculate the minimum momentum of each iso daugther in the 3 body CM system(BACKWARD)
  TLorentzVector pmin(0,0,-P12,sqrt(P12*P12+d2.M2())); //decay backward in iso helcity rest frame
  pmin.Boost(boostIso);//boost along helicity z axis from iso rest to CM
  Pmin2=pmin.Z(); //minium longitudinal momentum allowed for isobar
  pmin=TLorentzVector(0,0,-P12,sqrt(P12*P12+d1.M2())); //decay backward in iso  helcity rest frame
  pmin.Boost(boostIso);//boost along helicity z axis from Iso rest to CM
  Pmin1=pmin.Z(); //minium longitudinal momentum allowed for isobar
  //calculate the maximum momentum of each iso daugther in the 3 body CM system(FORWARD)
  pmin=TLorentzVector(0,0,P12,sqrt(P12*P12+d2.M2())); //forward in iso helcity rest frame
  pmin.Boost(boostIso);//boost along helicity z axis from iso rest to CM
  Pmax2=pmin.Z(); //minium longitudinal momentum allowed for isobar
  pmin=TLorentzVector(0,0,P12,sqrt(P12*P12+d1.M2())); //forward in helcity rest frame
  pmin.Boost(boostIso);//boost along helicity z axis to CM
  Pmax1=pmin.Z(); //minium longitudinal momentum allowed for isobar
  //calculate the omega limits for this event
  TVector2 vOmega0(0,1);
  TVector2 vOmega1(0,1);
  // Pmin1=Pmin2=0;
  if(fCosTh>0){
    vOmega0.SetMagPhi(1,TMath::ATan2(Pmin1,Pmax2));
    vOmega1.SetMagPhi(1,TMath::ATan2(Pmax1,Pmin2));
  }
  else{
    vOmega0.SetMagPhi(1,TMath::ATan2(-Pmin1,-Pmax2));
    vOmega1.SetMagPhi(1,TMath::ATan2(-Pmax1,-Pmin2));
  }
 
  //cout<<fCosTh<<endl;
  //  cout<<"Angles "<<AnglesCM1.Z()<<" "<<Pmin1<<" "<<" 2222 "<<AnglesCM2.Z()<<" "<<Pmin2<<" "<<fOmega*TMath::RadToDeg()<<" "<<fCosHel<<endl;
  //cout<<fOmega<<" "<<vOmega0.Phi()<<" "<<vOmega1.Phi()<<endl;
  TVector2 vOmega(0,1);
  vOmega.SetMagPhi(1,fOmega);
  //rotate for simpler cut evaluation
   TVector2 vvO=vOmega.Rotate(-vOmega.Phi()+TMath::Pi());
  TVector2 vvO0=vOmega0.Rotate(-vOmega.Phi()+TMath::Pi());
  TVector2 vvO1=vOmega1.Rotate(-vOmega.Phi()+TMath::Pi());
  //evaluate whether this event could have had a d1 d2 isobar 
  // Pmin1=Pmin2=0;
  // if(fCosTh>0&&AnglesCM1.Z()>-Pmin1&&AnglesCM2.Z()>-Pmin2) return kTRUE;
  // if(fCosTh<0&&AnglesCM1.Z()>-Pmin1&&AnglesCM2.Z()>-Pmin2) return kTRUE;
  //  else return kFALSE;
  // if(fOmega>0&&fOmega<90*TMath::DegToRad()) return kTRUE;
  //else return kFALSE;

  //if(fCosTh>0){
  // if(AnglesCM1.Z()>Pmin1&&AnglesCM2.Z()>Pmin2) return kTRUE;
  // else return kFALSE; 
  // }
  //else if(AnglesCM1.Z()>-Pmin1&&AnglesCM2.Z()>-Pmin2) return kTRUE;
  //else return kFALSE;
  //cout<<"Phis "<<vvO.Phi()<<" "<<vvO0.Phi()<<" "<<vvO1.Phi()<<endl;
  if(vvO.Phi()>vvO0.Phi()&&vvO.Phi()<vvO1.Phi())return kTRUE;
  else return kFALSE;
  //else if(vvO.Phi()<vvO0.Phi()&&vvO.Phi()>vvO1.Phi())return kTRUE;
  // Double_t L1=vOmega0.Phi();
  // Double_t L2=vOmega1.Phi();
  // if(L1>TMath::Pi())L1=L1-2*TMath::Pi();
  // if(L2>TMath::Pi())L2=L2-2*TMath::Pi();
  // cout<<"Finale "<<L1*TMath::RadToDeg()<<" "<<fOmega*TMath::RadToDeg()<<" "<<L2*TMath::RadToDeg()<<endl;
  // // L1*=L1;
  // //L2=L2;
  // if(L1<fOmega&&fOmega<L2) return kTRUE;
  // else return kFALSE;
}

Double_t THSIsobarPS::BetaPM(double p0, double m0){
  //Warning return -ve if p0<0 
 //beta =p/E
  return p0/sqrt(p0*p0+m0*m0);
}

// double THSIsobarPS::BetaPM(double p0, double m0){
//   //Warning return -ve if p0<0 
//  //beta =p/E
//   return p0/sqrt(p0*p0+m0*m0);
// }

Double_t THSIsobarPS::breakupMomentum( double mass0, double mass1, double mass2 ){
   
  Double_t q;
  
  // fabs -- correct?  consistent w/ previous E852 code
  q = sqrt( fabs(   mass0*mass0*mass0*mass0 + 
                    mass1*mass1*mass1*mass1 +
                    mass2*mass2*mass2*mass2 -
                    2.0*mass0*mass0*mass1*mass1 -
                    2.0*mass0*mass0*mass2*mass2 -
                    2.0*mass1*mass1*mass2*mass2  ) ) / (2.0 * mass0);
  
  return q;
  
}


