//--Author      DI Glazier 23/03/2018
//--Rev
//--Update
//--Description
//HASPECT Event Reconstruction
//THSParticle
//Optimised Persistant Data structure
//Contains reconstructed information required for data analysis

#ifndef __THSParticle_h__
#define __THSParticle_h__

#include "TLorentzVector.h"
#include "TVector3.h"
#include "TDatabasePDG.h"
#include "TMatrixD.h"
#include <vector>
#include <map>
#include <iostream>
#include <Math/Vector4D.h>
#include <Math/Point3D.h>
#include <Math/DisplacementVector3D.h>
#include <Math/VectorUtil.h> //for boosts etc.

using namespace std;

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<Double32_t> > HSLorentzVector;
typedef ROOT::Math::PositionVector3D< ROOT::Math::Cartesian3D< Double32_t >, ROOT::Math::DefaultCoordinateSystemTag > HSPosition;

typedef ROOT::Math::DisplacementVector3D< ROOT::Math::Cartesian3D< Double_t >, ROOT::Math::DefaultCoordinateSystemTag > HSMomentum;

#pragma link C++ class vector<THSParticle >+;
#pragma link C++ class vector<THSParticle* >+;


class THSParticle {
 private:
 protected:
  HSLorentzVector fP4;  //4-vector 
  HSLorentzVector fTruthP4;//! true generated 4-vector
  HSPosition fVertex;     //particle vertex position
  HSPosition fTruthV;//! true generated vertex
  Double32_t fPDGMass=0;
  Double32_t fMeasMass=0; //Or other PID info
  Double32_t fTime=0;
  Double32_t fPath=0;
  Double32_t fDoca=0;//!
  Double32_t fEdep=0;
  Double32_t fDeltaE=0;
  Double32_t fPreE=0;
  vector<Double32_t> fHypPList={0,0,0,0,0,0}; //List of corrected momenta for different species hypothesis

  Float_t fTrChi2=0;
  Int_t fNPhot=0;
  Short_t fPDGCode=0;           //PDG number
  Short_t fTruthPDG=0;//! true PDG code
  Short_t fDetector=0; //detector code
  Short_t fStatus=0;
  Short_t fFiducialCut=1;
  UShort_t fHypIndex=0;//!
  std::map<Long64_t,Int_t> gHSParticleHypMap{{11*11,1},{211*211,2},{321*321,3},{2212*2212,4},{2112*2112,4},{22*22,1},{13*13,5}};//!
 
  //Allow space for covariance matrix
  //The vector will need decoded into the TMatrix for calculations
  vector<Float_t> fCovaMatEntries;//!
  TMatrixD fCovarianceMatrix;//!

  //Note if you want to store these in a file
  //you need to remove the !
  
  
 public:
  THSParticle()=default;  	        //Constructor
  THSParticle(int code);  	        //Constructor
  THSParticle(TString pdgname);  	        //Constructor
  ~THSParticle()=default;	     	//Destructor


  //Setting functions
  void SetPDGcode(Int_t code){
    if(TDatabasePDG::Instance()->GetParticle(fPDGCode=code)){
      TParticlePDG* part=TDatabasePDG::Instance()->GetParticle(fPDGCode=code);
      fPDGMass = part->Mass();}
    else fPDGMass=0;
    //Get Hypothesis index, will by =6 if not predefined
    fHypIndex=gHSParticleHypMap.find(code*code)->second;
  }
  void SetP4(HSLorentzVector v){fP4=v;}
  void SetVectPDG(HSLorentzVector v){fP4.SetXYZT(v.X(),v.Y(),v.Z(),sqrt(v.P2()+fPDGMass*fPDGMass));}
  void SetP4(HSLorentzVector *v){fP4=*v;}
  void SetXYZT(Double_t X,Double_t Y,Double_t Z,Double_t T){fP4.SetXYZT(X,Y,Z,T);}
  void SetXYZM(Double_t X,Double_t Y,Double_t Z,Double_t M){fP4.SetXYZT(X,Y,Z,sqrt(M*M+X*X+Y*Y+Z*Z));}
  void SetP(Double_t nP){Double_t rp=nP/fP4.P();fP4.SetXYZT(fP4.X()*rp,fP4.Y()*rp,fP4.Z()*rp,sqrt(fP4.M()*fP4.M()+nP*nP));}
  void SetVertex(HSPosition v){fVertex=v;}
  void SetVertex(Double_t X,Double_t Y,Double_t Z){fVertex.SetXYZ(X,Y,Z);}
  //void SetPol(HSPosition p){fPol=p;}
  //void SetPol(Double_t X,Double_t Y,Double_t Z){fPol.SetXYZ(X,Y,Z);}
  void SetTime(Double_t time){fTime=time;};
  void SetPath(Double_t path){fPath=path;};
  void SetDoca(Double_t doca){fDoca=doca;};
  void SetEdep(Double_t edep){fEdep=edep;};
  void SetPreE(Double_t edep){fPreE=edep;};
  void SetTrChi2(Float_t chi2){fTrChi2=chi2;};
  void SetDeltaE(Double_t edep){fDeltaE=edep;};
  void SetNPhot(Int_t np){fNPhot=np;};
  void SetDetector(Int_t det){fDetector=det;};
  void SetStatus(Int_t status){fStatus=status;}
  void SetFidCut(Int_t fc){fFiducialCut=fc;}
  void SetMeasMass(Double_t mass){fMeasMass=mass;};

  void SetHypPElGam(Double_t pp){fHypPList[1]=pp;};
  void SetHypPPi(Double_t pp){fHypPList[2]=pp;};
  void SetHypPK(Double_t pp){fHypPList[3]=pp;};
  void SetHypPNuc(Double_t pp){fHypPList[4]=pp;};
  void SetHypPMu(Double_t pp){fHypPList[5]=pp;};
  void SetHypPMisc(Double_t pp){fHypPList[0]=pp;};

  void TakePDGMass(){SetVectPDG(fP4);}; //Preserves momentum
  void TakeCorrectedP(){if(fHypIndex==gHSParticleHypMap.size()) return; Double_t rho0=fP4.P();Double_t rho=fHypPList[fHypIndex];if(!rho) return; rho/=rho0;fP4.SetXYZT(fP4.X()*rho,fP4.Y()*rho,fP4.Z()*rho,fP4.E());SetVectPDG(fP4);};
  void TakePDGMassFromE(){Double_t rho0=fP4.P();Double_t rho=sqrt(fP4.E()*fP4.E()-fPDGMass*fPDGMass);rho/=rho0;fP4.SetXYZT(fP4.X()*rho,fP4.Y()*rho,fP4.Z()*rho,fP4.E());}; //preserves energy
  // void CreateTruth(){fTruth=new THSParticle();};
  void SetTruth(THSParticle* part){fTruthP4=part->P4();fTruthV=part->Vertex();fTruthPDG=part->PDG();};
  void SetTruth(THSParticle part){fTruthP4=part.P4();fTruthV=part.Vertex();fTruthPDG=part.PDG();};
  void SetTruth(HSLorentzVector part,HSPosition ver,Int_t pdg){fTruthP4=part;fTruthV=ver;fTruthPDG=pdg;};
  //Getting functions
  HSLorentzVector P4(){return fP4;}
  HSLorentzVector* P4p(){return &fP4;}
  HSPosition Vertex(){return fVertex;}
  //HSPosition Pol(){return fPol;}
   Double_t PDGMass(){return fPDGMass;}
  Double_t MeasMass(){return fMeasMass;}
  Double_t Time(){return fTime;}
  Double_t MassDiff(){return fPDGMass-fMeasMass;}
  Double_t Edep(){return fEdep;}
  Double_t PreE(){return fPreE;}
  Double_t DeltaE(){return fDeltaE;}
  Double_t Doca(){return fDoca;}
  Double_t Path(){return fPath;}
  Double_t Beta(){return fPath/fTime/2.99792e+08*1E9;}//time ns, path m
  Double_t HypBeta(){Double_t pp=fP4.P();return pp/sqrt(pp*pp+fPDGMass*fPDGMass);}
  Double_t HypTime(){return fPath/HypBeta()/2.99792e+08*1E9  ;} //in ns
  //  Double_t DeltaTime(){return HypTime()-fTime;};
  Double_t DeltaTime(){return fTime-HypTime();};
  Double_t DeltaTimeVer(){return DeltaTime()-fVertex.Z()/2.99792e+08*1E9;}
  Float_t TrChi2(){return fTrChi2;}
  Int_t NPhot(){return fNPhot;}
  Short_t Detector(){return fDetector;}
  Short_t Status(){return fStatus;}
  Short_t FidCut(){return fFiducialCut;}
  Short_t PDG(){return fPDGCode;}
  Int_t Charge();
  void ShiftTime(Float_t shift){fTime+=shift;}

  HSLorentzVector* TruthP4p(){return &fTruthP4;};
  HSLorentzVector TruthP4(){return fTruthP4;};
  HSPosition* TruthVer(){return &fTruthV;};
  Short_t TruthPDG(){return fPDGCode;};
   
  TLorentzVector GetTLorentzVector(){return TLorentzVector(fP4.X(),fP4.Y(),fP4.Z(),fP4.T());}
  TVector3 GetVertex3(){return TVector3(fVertex.X(),fVertex.Y(),fVertex.Z());}

  void Clear();
  void MinorClear();
  
  void CopyParticle(THSParticle* part,Bool_t andPDG);
  //Utility functions
  virtual void Print(Option_t *option="") const;

  //Add 4-vectors, doca vertices, fix pdg(optional)
  void Add(THSParticle *hsp1, THSParticle *hsp2,Int_t pdg=0);

  //DOCA routines
  /* Double_t MakeVirtualVertex(THSParticle* p1,THSParticle *p2); */
  /* Double_t Calc_dtfDOCA( HSPosition locVertex1, HSPosition locUnitDir1, HSPosition locVertex2, HSPosition locUnitDir2, HSPosition *result); */
  /* void Calc_dtfInterDOCA( HSPosition locUnitDir1, HSPosition locUnitDir2, HSPosition locVertex1,  HSPosition locVertex2, HSPosition *locInterDOCA1, HSPosition *locInterDOCA2); */

 public:
  //need to permutate class
  //order in vector based on particle momentum
  //nb comparitive operator cannot work on pointers so vectors need
  //to be filled with object not pointers for this to work
  friend bool operator< ( const THSParticle& lhs, const THSParticle& rhs ){return lhs.fP4.P() < rhs.fP4.P(); };

  Double_t p3Distance(HSMomentum vec){return (fP4.Vect()-vec).Mag2();}

  Double_t ResTheta(){return fP4.Theta()-fTruthP4.Theta();};
  Double_t ResPhi(){return fP4.Phi()-fTruthP4.Phi();};
  Double_t ResP(){return fP4.P()-fTruthP4.P();};
  Double_t ResE(){return fP4.E()-fTruthP4.E();};
  Double_t ResAngle(){return ROOT::Math::VectorUtil::Angle(fP4,fTruthP4);};
  ClassDef(THSParticle,5) //class THSParticle
};
inline Int_t THSParticle::Charge(){
  
  if(fPDGCode==1E4) return 1;
  else if(fPDGCode==-1E4) return -1;

  TParticlePDG *part=TDatabasePDG::Instance()->GetParticle(fPDGCode);
  if(part){
    Int_t charge=part->Charge();
    if(charge!=0)charge=(Int_t) charge/TMath::Abs(charge); //just get sign not mag.
    return charge;
  }
  else return 0;
}
inline void THSParticle::Clear(){
  fP4.SetXYZT(0,0,0,0);
  fTruthP4.SetXYZT(0,0,0,0);
  fPDGMass=0;
  fMeasMass=0; //Or other PID info
  fTime=0;
  fPath=0;
  fDoca=0;//!
  fEdep=0;
  fDeltaE=0;
  fPreE=0;
  for(UInt_t ip=0;ip<5;ip++)
    fHypPList.at(ip)=0;
  fTrChi2=0;
  fNPhot=0;
  fPDGCode=0;           //PDG number
  fTruthPDG=0;//! true PDG code
  fDetector=0; //detector code
  fFiducialCut=1;
  fHypIndex=0;

}
inline void THSParticle::MinorClear(){
  fP4.SetXYZT(0,0,0,0);
  fMeasMass=0; //Or other PID info
  fTime=0;
  fPath=0;
  fDoca=0;//!
  fEdep=0;
  fDeltaE=0;
  fPreE=0;
  for(UInt_t ip=0;ip<5;ip++)
    fHypPList.at(ip)=0;
  fTrChi2=0;
  fNPhot=0;
  fDetector=0; //detector code
  fFiducialCut=1;
 }

//inline bool THSParticle::operator<( const THSParticle& rhs ) {cout<<" "<<rhs.fP4.Rho()<<endl;return fP4.Rho() < rhs.fP4.Rho(); }
//inline bool THSParticle::operator<( const THSParticle& rhs ) {cout<<" "<<rhs.fP4.Rho()<<endl;return this->fP4.Rho() < rhs.fP4.Rho(); }
//inline bool THSParticle::IsFaster( const THSParticle& lhs,const THSParticle& rhs ) {cout<<" "<<rhs.fP4.Rho()<<endl;return lhs.fP4.Rho() < rhs.fP4.Rho(); }
#endif
