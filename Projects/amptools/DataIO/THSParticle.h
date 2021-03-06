//--Author      DI Glazier 30/06/2014
//--Rev
//--Update
//--Description
//HASPECT Event Reconstruction
//THSParticle
//Persistant Data structure
//Contains reconstructed information required for data analysis

#ifndef __THSParticle_h__
#define __THSParticle_h__

#include "TLorentzVector.h"
#include "TVector3.h"
#include "TDatabasePDG.h"
#include <iostream>
using namespace std;

class THSParticle {
 private:
 protected:
  TLorentzVector fP4;  //4-vector 
  TVector3 fVertex;     //particle vertex position
  //TVector3 fPol;     //polarisation vector
  Int_t fPDGCode;           //PDG number
  Double_t fPDGMass;
  Double_t fMeasMass; //Or other PID info
  Double_t fTime;
  //TMatrixD fCovarianceMatrix;
  Int_t fDetector=0; //detector code
  
  TLorentzVector fTruthP4; //true generated 4-vector
  TVector3 fTruthV; //true generated vertex
  Int_t fTruthPDG;
  
  Bool_t fTruthOnly=kFALSE;
  
 public:
  THSParticle();  	        //Constructor
  THSParticle(int code);  	        //Constructor
  THSParticle(TString pdgname);  	        //Constructor
  virtual ~THSParticle(){};	     	//Destructor


  //Setting functions
  void SetPDGcode(Int_t code){
    if(TDatabasePDG::Instance()->GetParticle(fPDGCode=code))
      fPDGMass = TDatabasePDG::Instance()->GetParticle(fPDGCode=code)->Mass();
    else fPDGMass=0;
  }
  void SetP4(TLorentzVector v){fP4=v;}
  void SetVectPDG(TLorentzVector v){fP4.SetVectM(v.Vect(),fPDGMass);}
  void SetP4(TLorentzVector *v){fP4=*v;}
  void SetXYZT(Double_t X,Double_t Y,Double_t Z,Double_t T){fP4.SetXYZT(X,Y,Z,T);}
  void SetXYZM(Double_t X,Double_t Y,Double_t Z,Double_t M){fP4.SetXYZM(X,Y,Z,M);}
  void SetVertex(TVector3 v){fVertex=v;}
  void SetVertex(Double_t X,Double_t Y,Double_t Z){fVertex.SetXYZ(X,Y,Z);}
  //void SetPol(TVector3 p){fPol=p;}
  //void SetPol(Double_t X,Double_t Y,Double_t Z){fPol.SetXYZ(X,Y,Z);}
  void SetTime(Double_t time){fTime=time;};
  void SetDetector(Int_t det){fDetector=det;};
  void SetMeasMass(Double_t mass){fMeasMass=mass;};
  void TakePDGMass(){SetVectPDG(fP4);}; //Preserves momentum
  void TakePDGMassFromE(){Double_t rho=sqrt(fP4.E()*fP4.E()-fPDGMass*fPDGMass);fP4.SetRho(rho);}; //preserves energy
  // void CreateTruth(){fTruth=new THSParticle();};
  void SetTruth(THSParticle* part){fTruthP4=part->P4();fTruthV=part->Vertex();fTruthPDG=part->PDG();};
  void SetTruth(THSParticle part){fTruthP4=part.P4();fTruthV=part.Vertex();fTruthPDG=part.PDG();};
  void SetTruth(TLorentzVector part,TVector3 ver,Int_t pdg){fTruthP4=part;fTruthV=ver;fTruthPDG=pdg;};
  void SetTruthOnly(Bool_t tr=kTRUE){fTruthOnly=tr;}
  //Getting functions
  TLorentzVector P4(){return fP4;}
  TLorentzVector* P4p(){return &fP4;}
  TVector3 Vertex(){return fVertex;}
  //TVector3 Pol(){return fPol;}
  Int_t PDG(){return fPDGCode;}
  Double_t PDGMass(){return fPDGMass;}
  Double_t MeasMass(){return fMeasMass;}
  Double_t MassDiff(){return fPDGMass-fMeasMass;}
  Double_t Time(){return fTime;}
  Int_t Detector(){return fDetector;}
  
  TLorentzVector* TruthP4p(){return &fTruthP4;};
  TLorentzVector TruthP4(){return fTruthP4;};
  TVector3* TruthVer(){return &fTruthV;};
  Int_t TruthPDG(){return fPDGCode;};
  
  Bool_t TruthOnly(){return fTruthOnly;}
  
  void CopyParticle(THSParticle* part);
  //Utility functions
  virtual void Print(Option_t *option="") const;

 public:
  //need to permutate class
  //order in vector based on particle momentum
  //nb comparitive operator cannot work on pointers so vectors need
  //to be filled with object not pointers for this to work
  friend bool operator< ( const THSParticle& lhs, const THSParticle& rhs ){return lhs.fP4.Rho() < rhs.fP4.Rho(); };

  Double_t p3Distance(TVector3 vec){return (fP4.Vect()-vec).Mag();}

  Double_t ResTheta(){return fP4.Theta()-fTruthP4.Theta();};
  Double_t ResPhi(){return fP4.Phi()-fTruthP4.Phi();};
  Double_t ResRho(){return fP4.Rho()-fTruthP4.Rho();};
  Double_t ResE(){return fP4.E()-fTruthP4.E();};
  ClassDef(THSParticle,1) //class THSParticle
};

//inline bool THSParticle::operator<( const THSParticle& rhs ) {cout<<" "<<rhs.fP4.Rho()<<endl;return fP4.Rho() < rhs.fP4.Rho(); }
//inline bool THSParticle::operator<( const THSParticle& rhs ) {cout<<" "<<rhs.fP4.Rho()<<endl;return this->fP4.Rho() < rhs.fP4.Rho(); }
//inline bool THSParticle::IsFaster( const THSParticle& lhs,const THSParticle& rhs ) {cout<<" "<<rhs.fP4.Rho()<<endl;return lhs.fP4.Rho() < rhs.fP4.Rho(); }
#endif
