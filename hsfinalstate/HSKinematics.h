//Class to compute various common kinematic quantities
//THSParticle is based on ROOT::MATH::GENVECTOR see:
//https://root.cern.ch/root/html/MATH_GENVECTOR_Index.html
//These have less overheads than standard TLorentzVector etc.

#ifndef HS_KINEMATICS_h
#define HS_KINEMATICS_h


#include "THSParticle.h"
#include <Math/VectorUtil.h> //for boosts etc.

using namespace ROOT::Math::VectorUtil; //Just add VectorUtil:: to functions

namespace HS{
  class HSKinematics{
    
  private :
    HSLorentzVector fElin;
    HSLorentzVector fElsc;
    HSLorentzVector fGamma;
    HSLorentzVector fCM;
    HSLorentzVector fTar;
    HSLorentzVector fMes;
    HSLorentzVector fBar;
    HSLorentzVector fMes_d1;
    HSLorentzVector fMes_d2;
    HSLorentzVector fBar_d1;
    HSLorentzVector fBar_d2;
    
    HSMomentum fCMBoost;
    
    Double_t fCosTh=0;
    Double_t fPhi=0;
    Double_t fCosx=0;
    Double_t fCosy=0;
    Double_t fCosz=0;
    
  public :
    HSKinematics(){};
    ~HSKinematics(){};
    
    Double_t CosTheta(){return fCosTh;}
    Double_t Phi(){return fPhi;}
    
    void SetTarget(HSLorentzVector tar){fTar=tar;};
    void SetTarget(TLorentzVector tar){fTar=HSLorentzVector(tar.X(),tar.Y(),tar.Z(),tar.T());}
    
    /////////////////////////////////////////////////////////////
    /// Set electron scattering and target 4-vectors \n
    /// Use them to calculate cm 4-vector
    void SetElecsTarget(HSLorentzVector in,HSLorentzVector sc,HSLorentzVector tar){
      fElin=in;
      fElsc=sc;
      fGamma=fElin-fElsc;
      fTar=tar;
      fCM=fGamma+fTar;
      fCMBoost=fCM.BoostToCM();
    }
    void SetElecsTarget(TLorentzVector in,TLorentzVector sc,TLorentzVector tar){
      fElin=HSLorentzVector(in.X(),in.Y(),in.Z(),in.T());
      fElsc=HSLorentzVector(sc.X(),sc.Y(),sc.Z(),sc.T());
      fGamma=fElin-fElsc;
      fTar=HSLorentzVector(tar.X(),tar.Y(),tar.Z(),tar.T());
      fCM=fGamma+fTar;
      fCMBoost=fCM.BoostToCM();
    }
    /////////////////////////////////////////////////////////////
    /// Set incoming photon and target 4-vectors \n
    /// Use them to calculate cm 4-vector
    void SetGammaTarget(HSLorentzVector gamma,HSLorentzVector tar){
      fGamma=gamma;
      fTar=tar;
      fCM=gamma+tar;
      fCMBoost=fCM.BoostToCM();
    }
    void SetGammaTarget(TLorentzVector gamma,TLorentzVector tar){
      fGamma=HSLorentzVector(gamma.X(),gamma.Y(),gamma.Z(),gamma.T());
      fTar=HSLorentzVector(tar.X(),tar.Y(),tar.Z(),tar.T());
      fCM=fGamma+fTar;
      fCMBoost=fCM.BoostToCM();
    }
    ///////////////////////////////////////////////////////////
    /// Set primary decay products of the CM system. 
    void SetMesonBaryon(HSLorentzVector mes,HSLorentzVector bar){
      fMes=mes;
      fBar=bar;
    }
    void SetMesonBaryon(TLorentzVector mes,TLorentzVector bar){
      fMes=HSLorentzVector(mes.X(),mes.Y(),mes.Z(),mes.T());
      fBar=HSLorentzVector(bar.X(),bar.Y(),bar.Z(),bar.T());
    }
    ///////////////////////////////////////////////////////////
    /// Set decay products of the meson. \n
    /// d1 will be used to calculate angles in GJ and helicity frame.
    void SetMesonDecay(HSLorentzVector d1,HSLorentzVector d2){
      fMes_d1=d1;
      fMes_d2=d2;
    }
    void SetMesonDecay(TLorentzVector d1,TLorentzVector d2){
      fMes_d1=HSLorentzVector(d1.X(),d1.Y(),d1.Z(),d1.T());
      fMes_d2=HSLorentzVector(d2.X(),d2.Y(),d2.Z(),d2.T());
    }
    ///////////////////////////////////////////////////////////
    /// Set decay products of the baryon. \n
    /// d1 will be used to calculate angles in GJ and helicity frame.
    void SetBaryonDecay(HSLorentzVector d1,HSLorentzVector d2){
      fBar_d1=d1;
      fBar_d2=d2;
    }
    void SetBaryonDecay(TLorentzVector d1,TLorentzVector d2){
      fBar_d1=HSLorentzVector(d1.X(),d1.Y(),d1.Z(),d1.T());
      fBar_d2=HSLorentzVector(d2.X(),d2.Y(),d2.Z(),d2.T());
    }
    
    HSLorentzVector ParticleXYZM(Double_t X,Double_t Y,Double_t Z,Double_t M){HSLorentzVector p4;p4.SetXYZT(X,Y,Z,sqrt(M*M+X*X+Y*Y+Z*Z)); return p4;}
    
    
    HSLorentzVector Gamma(){return fGamma;}
    Double_t W(){ return fCM.M();}
    Double_t Q2() {return -fGamma.M2();}
    Double_t GammaE() {return fGamma.E();}
    Double_t GammaTh() {return fGamma.Theta();}
    Double_t ElScatTh() {return fElsc.Theta();}
    Double_t GammaPol(){return 1./(1+2*(1+GammaE()*GammaE()/Q2())*TMath::Tan(ElScatTh()/2)*TMath::Tan(ElScatTh()/2));}
    Double_t GammaFlux(){return(1./137/4/TMath::Pi()/TMath::Pi())/fElin.E()*fElsc.E()*((W()*W()-fTar.M2())/fTar.M())/Q2()/(1-GammaPol()); }
    
    
    Double_t t(){return t(fGamma,fMes);}//default gamma-meson
    Double_t t(HSLorentzVector p0,HSLorentzVector p1){
      // HSLorentzVector transfer=p0-p1;
      //return transfer.M2();
      return (p0-p1).M2();
    }
    Double_t t(TLorentzVector p0,TLorentzVector p1){
      // HSLorentzVector transfer=p0-p1;
      //return transfer.M2();
      return (p0-p1).M2();
    }
    Double_t t0(){return t0(fGamma,fMes);}//default gamma-meson
    Double_t t0(HSLorentzVector p0,HSLorentzVector p1);
    Double_t t0(TLorentzVector p0,TLorentzVector p1){return t0(HSLorentzVector(p0.X(),p0.Y(),p0.Z(),p0.T()),HSLorentzVector(p1.X(),p1.Y(),p1.Z(),p1.T()));};
    
    Double_t Cosx(){return fCosx;}  
    Double_t Cosy(){return fCosy;}  
    Double_t Cosz(){return fCosz;}
    
    Double_t CosThetaVector(HSMomentum *mm){return TMath::Cos(mm->Theta());}
    Double_t CosThetaVector(HSLorentzVector *mm){return TMath::Cos(mm->Theta());}
    //Decay angles
    void MesonDecayHelicity();
    void MesonDecayGJ();
    void BaryonDecayHelicity();
    void BaryonDecayGJ();
    void omegaMesonDecayHelicity();
    void omegaMesonDecayGJ();
    void ElectroCMDecay();
    void PhotoCMDecay();
    void LambdaDecay();
    void PolPhotoCMDecay();
  };
  
  inline Double_t HSKinematics::t0(HSLorentzVector p0,HSLorentzVector p1){
    //THIS FUNCTION IS PROBABLY NOT CORRECT AND NEEDS CHECKED
    HSLorentzVector cm0=boost(p0,fCMBoost);
    HSLorentzVector cm1=boost(p1,fCMBoost);
    
    Double_t P0CM=cm0.P();
    Double_t P1CM=cm1.P();
    
    Double_t t0=(p1.M2()/2/fCM.M())*(p1.M2()/2/fCM.M())-(P0CM-P1CM)*(P0CM-P1CM);
    return t(p0,p1) - t0;
  }
  
  inline void HSKinematics::ElectroCMDecay(){
    //CM frame defined by e-scattering
    HSLorentzVector CMBeam=boost(fElin,fCMBoost);
    // HSLorentzVector CMScat=boost(fElsc,fCMBoost);
    HSLorentzVector CMMes=boost(fMes,fCMBoost);
    HSLorentzVector CMGamma=boost(fGamma,fCMBoost);
    
    HSMomentum zV=CMGamma.Vect().Unit();
    HSMomentum yV=CMGamma.Vect().Cross(CMBeam.Vect()).Unit();
    HSMomentum xV=yV.Cross(zV).Unit();
    
    HSMomentum angles(CMMes.Vect().Dot(xV),CMMes.Vect().Dot(yV),CMMes.Vect().Dot(zV));
    fCosTh=CosThetaVector(&angles);
    fPhi=angles.Phi();
  }
  ////////////////////////////////////////////////////////
  ///CM frame defined by CM boost. No rotation to lab phi.
  inline void HSKinematics::PhotoCMDecay(){
    HSLorentzVector CMMes=boost(fMes,fCMBoost);
    fCosTh=CosThetaVector(&CMMes);
    fPhi=CMMes.Phi();
  }
  ////////////////////////////////////////////////////////
  /// From Daria Sokhan thesis \n
  /// Assuming polarisation vector is (0,1,0) (the E vector) and B vector (1,0,0), these are components of the boosted E-vector.  
  inline void HSKinematics::PolPhotoCMDecay(){
    Double_t gamma=fCM.Gamma();
    Double_t beta=fCM.Beta();
    
    Double_t E1 = (gamma * (gamma-1.) * fCMBoost.X() * fCMBoost.Y() / (beta*beta)) - (fCMBoost.X() * fCMBoost.Y() * gamma*gamma);
    
    Double_t E2 = (fCMBoost.Z() * gamma) - (fCMBoost.Y()*(fCMBoost.Y()) * gamma*gamma) + gamma + (gamma * (gamma-1.) * pow(fCMBoost.Y(),2) / (beta*beta));
    
    Double_t E3 = (gamma * (gamma-1.) * fCMBoost.Y() * fCMBoost.Z() / (beta*beta)) - (fCMBoost.Y() * gamma) - (fCMBoost.Y() * fCMBoost.Z() * gamma*gamma);
    
    HSMomentum Polarisation(E1,E2,E3); //photon pol in CM 
    Polarisation=RotateZ(Polarisation,TMath::Pi()/2);
    HSLorentzVector CMGamma=boost(fGamma,fCMBoost);
    
    HSMomentum zV=CMGamma.Vect().Unit();
    HSMomentum yV=Polarisation.Unit().Cross(CMGamma.Vect()).Unit();
    HSMomentum xV=yV.Cross(zV).Unit();
    
    HSLorentzVector CMMes=boost(fMes,fCMBoost);
    HSMomentum angles(CMMes.Vect().Dot(xV),CMMes.Vect().Dot(yV),CMMes.Vect().Dot(zV));
    fCosTh=CosThetaVector(&angles);
    fPhi=angles.Phi();
    
  }
  
  /////////////////////////////////////////////////////
  ///z-axis along -baryon in meson rest frame
  inline void HSKinematics::MesonDecayHelicity(){
    HSMomentum decBoost=fMes.BoostToCM();
    HSLorentzVector decBar=boost(fBar,decBoost);
    HSLorentzVector decGamma=boost(fGamma,decBoost);
    HSMomentum zV=-decBar.Vect().Unit();
    HSMomentum yV=decBar.Vect().Cross(decGamma.Vect()).Unit();
    HSMomentum xV=yV.Cross(zV).Unit();
    
    HSLorentzVector decD1=boost(fMes_d1,decBoost);
    
    HSMomentum angles(decD1.Vect().Dot(xV),decD1.Vect().Dot(yV),decD1.Vect().Dot(zV));
    fCosTh=CosThetaVector(&angles);
    fPhi=angles.Phi();
  }
  
  ////////////////////////////////////////////////////////
  ///z-axis along gamma direction in meson rest frame
  inline void HSKinematics::MesonDecayGJ(){
    HSMomentum decBoost=fMes.BoostToCM();
    HSLorentzVector decBar=boost(fBar,decBoost);
    HSLorentzVector decGamma=boost(fGamma,decBoost);
    HSMomentum zV=decGamma.Vect().Unit();
    HSMomentum yV=decBar.Vect().Cross(decGamma.Vect()).Unit();
    HSMomentum xV=yV.Cross(zV).Unit();
    
    HSLorentzVector decD1=boost(fMes_d1,decBoost);
    
    HSMomentum angles(decD1.Vect().Dot(xV),decD1.Vect().Dot(yV),decD1.Vect().Dot(zV));
    fCosTh=CosThetaVector(&angles);
    fPhi=angles.Phi();
  }
  
  //////////////////////////////////////////////////////
  ///z-axis along -meson in baryon rest frame
  inline void HSKinematics::BaryonDecayHelicity(){
    HSMomentum decBoost=fBar.BoostToCM();
    HSLorentzVector decMes=boost(fMes,decBoost);
    HSLorentzVector decGamma=boost(fGamma,decBoost);
    HSMomentum zV=-decMes.Vect().Unit();
    HSMomentum yV=decGamma.Vect().Cross(decMes.Vect()).Unit();
    HSMomentum xV=yV.Cross(zV).Unit();
    
    HSLorentzVector decD1=boost(fBar_d1,decBoost);
    
    HSMomentum angles(decD1.Vect().Dot(xV),decD1.Vect().Dot(yV),decD1.Vect().Dot(zV));
    fCosTh=CosThetaVector(&angles);
    fPhi=angles.Phi();
  }
  
  //////////////////////////////////////////////////////
  ///z-axis along -target direction in baryon rest frame
  inline void HSKinematics::BaryonDecayGJ(){
    HSMomentum decBoost=fBar.BoostToCM();
    HSLorentzVector decMes=boost(fMes,decBoost);
    HSLorentzVector decGamma=boost(fGamma,decBoost);
    HSLorentzVector decTar=boost(fTar,decBoost);
    HSMomentum zV=-decTar.Vect().Unit();
    HSMomentum yV=decGamma.Vect().Cross(decMes.Vect()).Unit();
    HSMomentum xV=yV.Cross(zV).Unit();
    
    HSLorentzVector decD1=boost(fBar_d1,decBoost);
    
    HSMomentum angles(decD1.Vect().Dot(xV),decD1.Vect().Dot(yV),decD1.Vect().Dot(zV));
    fCosTh=CosThetaVector(&angles);
    fPhi=angles.Phi();
  }
  
  /////////////////////////////////////////////////////
  ///z-axis along -baryon in meson rest frame
  inline void HSKinematics::omegaMesonDecayHelicity(){
    HSMomentum decBoost=fMes.BoostToCM();
    HSLorentzVector decBar=boost(fBar,decBoost);
    HSLorentzVector decGamma=boost(fGamma,decBoost);
    HSMomentum zV=-decBar.Vect().Unit();
    HSMomentum yV=decBar.Vect().Cross(decGamma.Vect()).Unit();
    HSMomentum xV=yV.Cross(zV).Unit();
    
    HSLorentzVector decD1=boost(fMes_d1,decBoost);
    HSLorentzVector decD2=boost(fMes_d2,decBoost);
    
    HSMomentum normal=(decD1.Vect().Cross(decD2.Vect())).Unit();
    
    HSMomentum angles(normal.Dot(xV),normal.Dot(yV),normal.Dot(zV));
    fCosTh=CosThetaVector(&angles);
    fPhi=angles.Phi();
    
  }
  ////////////////////////////////////////////////////////
  ///z-axis along gamma direction in meson rest frame
  inline void HSKinematics::omegaMesonDecayGJ(){
    HSMomentum decBoost=fMes.BoostToCM();
    HSLorentzVector decBar=boost(fBar,decBoost);
    HSLorentzVector decGamma=boost(fGamma,decBoost);
    HSMomentum zV=decGamma.Vect().Unit();
    HSMomentum yV=decBar.Vect().Cross(decGamma.Vect()).Unit();
    HSMomentum xV=yV.Cross(zV).Unit();
    
    HSLorentzVector decD1=boost(fMes_d1,decBoost);
    HSLorentzVector decD2=boost(fMes_d2,decBoost);
    
    HSMomentum normal=(decD1.Vect().Cross(decD2.Vect())).Unit();
    
    HSMomentum angles(normal.Dot(xV),normal.Dot(yV),normal.Dot(zV));
    fCosTh=CosThetaVector(&angles);
    fPhi=angles.Phi();
  }
  //////////////////////////////////////////////////////
  ///z-axis along gamma direction in meson decay frame
  inline void HSKinematics::LambdaDecay(){
    //z-axis along gamma direction in meson decay frame
    HSMomentum decBoost=fBar.BoostToCM();
    HSLorentzVector decBar=boost(fBar,decBoost);
    HSLorentzVector decGamma=boost(fGamma,decBoost);
    HSMomentum zV=decGamma.Vect().Unit();
    HSMomentum yV=decBar.Vect().Cross(decGamma.Vect()).Unit();
    HSMomentum xV=yV.Cross(zV).Unit();
    
    HSLorentzVector decD1=boost(fBar_d1,decBoost);
    fCosx=TMath::Cos(Angle(decD1.Vect(),xV));
    fCosy=TMath::Cos(Angle(decD1.Vect(),yV));
    fCosz=TMath::Cos(Angle(decD1.Vect(),zV));
    
  }
}//namespace HS
#endif //ifdef HSKinematics
