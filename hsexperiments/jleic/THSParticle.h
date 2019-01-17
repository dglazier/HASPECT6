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

#pragma link C++ class std::vector<HS::THSParticle >+;
#pragma link C++ class std::vector<HS::THSParticle* >+;

//using namespace std;
namespace HS{
    using  HSLorentzVector=ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<Double32_t> > ;
    using HSPosition= ROOT::Math::PositionVector3D< ROOT::Math::Cartesian3D< Double32_t >, ROOT::Math::DefaultCoordinateSystemTag >;
    
    using  HSMomentum=ROOT::Math::DisplacementVector3D< ROOT::Math::Cartesian3D< Double_t >, ROOT::Math::DefaultCoordinateSystemTag >;
    
    
    
    class THSParticle {
 
    protected:
      HSLorentzVector fP4;  //4-vector 
      HSLorentzVector fTruthP4;//! true generated 4-vector
      HSPosition fVertex;     //particle vertex position
      HSPosition fTruthV;//! true generated vertex
      Double32_t fPDGMass=0;
      Double32_t fMeasMass=0; //Or other PID info
      Short_t fPDGCode=0;
      Short_t fTruthPDG=0;
      Short_t fDetector=0;
      
    public:
      THSParticle()=default;  	        //Constructor
      THSParticle(int code);  	        //Constructor
      THSParticle(TString pdgname);  	        //Constructor
      //   ~THSParticle()=default;	     	//Destructor


      //Setting functions
      void SetPDGcode(Int_t code){
	if(TDatabasePDG::Instance()->GetParticle(fPDGCode=code)){
	  TParticlePDG* part=TDatabasePDG::Instance()->GetParticle(fPDGCode=code);
	  fPDGMass = part->Mass();}
	else fPDGMass=0;
   }
      void SetP4(HSLorentzVector v){fP4=v;}
      void FixP4(HSLorentzVector v){fP4=v;TakePDGMass();}
      void SetVectPDG(HSLorentzVector v){fP4.SetXYZT(v.X(),v.Y(),v.Z(),sqrt(v.P2()+fPDGMass*fPDGMass));}
      void SetP4(HSLorentzVector *v){fP4=*v;}
      void SetXYZT(Double_t X,Double_t Y,Double_t Z,Double_t T){fP4.SetXYZT(X,Y,Z,T);}
      void SetXYZM(Double_t X,Double_t Y,Double_t Z,Double_t M){fP4.SetXYZT(X,Y,Z,sqrt(M*M+X*X+Y*Y+Z*Z));}
      void SetP(Double_t nP){Double_t rp=nP/fP4.P();fP4.SetXYZT(fP4.X()*rp,fP4.Y()*rp,fP4.Z()*rp,sqrt(fP4.M()*fP4.M()+nP*nP));}
      void SetVertex(HSPosition v){fVertex=v;}
      void SetVertex(Double_t X,Double_t Y,Double_t Z){fVertex.SetXYZ(X,Y,Z);}
  
      void TakePDGMass(){SetVectPDG(fP4);}; //Preserves momentum
      void SetTruth(THSParticle* part){fTruthP4=part->P4();fTruthV=part->Vertex();fTruthPDG=part->PDG();};
      void SetTruth(THSParticle part){fTruthP4=part.P4();fTruthV=part.Vertex();fTruthPDG=part.PDG();};
      void SetTruth(HSLorentzVector part,HSPosition ver,Int_t pdg){fTruthP4=part;fTruthV=ver;fTruthPDG=pdg;};
      void  SetMeasMass(Double_t mass){fMeasMass=mass;};
      void SetDetector(Short_t det){fDetector=det;};
      

      
      //Getting functions
      HSLorentzVector P4(){return fP4;}
      HSLorentzVector* P4p(){return &fP4;}
      HSPosition Vertex(){return fVertex;}
      //HSPosition Pol(){return fPol;}
      Double_t PDGMass(){return fPDGMass;}
      Short_t PDG(){return fPDGCode;}
      Int_t Charge();
      HSLorentzVector* TruthP4p(){return &fTruthP4;};
      HSLorentzVector TruthP4(){return fTruthP4;};
      HSPosition* TruthVer(){return &fTruthV;};
      Short_t TruthPDG(){return fPDGCode;};
      Double_t MeasMass(){return  fMeasMass;}
      Short_t Detector(){return fDetector;}
      Double_t DeltaTime(){return 0;}
            
      TLorentzVector GetTLorentzVector(){return TLorentzVector(fP4.X(),fP4.Y(),fP4.Z(),fP4.T());}
      TVector3 GetVertex3(){return TVector3(fVertex.X(),fVertex.Y(),fVertex.Z());}

      void Clear();
      void MinorClear();
  
      void CopyParticle(THSParticle* part,Bool_t andPDG);
      //Utility functions
      virtual void Print(Option_t *option="") const;

      //Add 4-vectors, doca vertices, fix pdg(optional)
      void Add(THSParticle *hsp1, THSParticle *hsp2,Int_t pdg=0);

   
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
      ClassDef(THSParticle,1); //class THSParticle
    };
}//namespace HS

inline Int_t HS::THSParticle::Charge(){
  
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
inline void HS::THSParticle::Clear(){
  fP4.SetXYZT(0,0,0,0);
  fTruthP4.SetXYZT(0,0,0,0);
  fPDGMass=0;
  fMeasMass=0; //Or other PID info
  fPDGCode=0;           //PDG number
  fTruthPDG=0;//! true PDG code

}
inline void HS::THSParticle::MinorClear(){
  fP4.SetXYZT(0,0,0,0);
  fTruthP4.SetXYZT(0,0,0,0);
  fPDGMass=0;
  fMeasMass=0; //Or other PID info

 }

#endif
