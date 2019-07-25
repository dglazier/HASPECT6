
#ifndef HS_BASEPARTICLE_H
#define HS_BASEPARTICLE_H

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


namespace HS{
    using  HSLorentzVector=ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<Double32_t> > ;
    using  HSPosition= ROOT::Math::PositionVector3D< ROOT::Math::Cartesian3D< Double32_t >, ROOT::Math::DefaultCoordinateSystemTag >;
    
    using  HSMomentum=ROOT::Math::DisplacementVector3D< ROOT::Math::Cartesian3D< Double_t >, ROOT::Math::DefaultCoordinateSystemTag >;
    
    const Short_t UndefinedPDG=1E4;
    
    class BaseParticle {
 
    protected:
      HSLorentzVector fP4;  //4-vector 
      HSLorentzVector fTruthP4;//! true generated 4-vector
      HSPosition fVertex;     //particle vertex position
      HSPosition fTruthV;//! true generated vertex
      Double32_t fPDGMass=0;
      Double32_t fMeasMass=0; //Or other PID info
      Double32_t fTime=0;
      Short_t fPDGCode=0;           //PDG number
      Short_t fTruthPDG=0;//! true PDG code
      Short_t fDetector=0;//! some detector ID

  
  
  
    public:
      BaseParticle()=default;  	        //Constructor
      BaseParticle(int code);  	        //Constructor
      BaseParticle(TString pdgname);  	        //Constructor
      virtual ~BaseParticle()=default;	     	//Destructor
      BaseParticle(const BaseParticle& other) = default; //Copy Constructor
      BaseParticle(BaseParticle&& other) = default; //Move Constructor
      
      BaseParticle& operator=(const BaseParticle& other)=default;
      BaseParticle& operator=(BaseParticle&& other)=default;
      
      //Setting functions
      void SetPDGcode(Int_t code){
	fPDGCode=code;
	if(!fPDGCode) return;
	if(fPDGCode==UndefinedPDG||fPDGCode==-UndefinedPDG) return;

	auto partpdg=TDatabasePDG::Instance()->GetParticle(fPDGCode);
	if(partpdg){
	  fPDGMass = partpdg->Mass();}
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
     

      void TakePDGMass(){fMeasMass=fP4.M();SetVectPDG(fP4);}; //Preserves momentum
      void TakePDGMassFromE(){Double_t rho0=fP4.P();Double_t rho=sqrt(fP4.E()*fP4.E()-fPDGMass*fPDGMass);rho/=rho0;fP4.SetXYZT(fP4.X()*rho,fP4.Y()*rho,fP4.Z()*rho,fP4.E());}; //preserves energy
      // void CreateTruth(){fTruth=new BaseParticle();};
      void SetTruth(BaseParticle* part){fTruthP4=part->P4();fTruthV=part->Vertex();fTruthPDG=part->PDG();};
      void SetTruth(BaseParticle part){fTruthP4=part.P4();fTruthV=part.Vertex();fTruthPDG=part.PDG();};
      void SetTruth(HSLorentzVector part,HSPosition ver,Int_t pdg){fTruthP4=part;fTruthV=ver;fTruthPDG=pdg;};
      void SetDetector(Short_t det){fDetector=det;}
      void SetTime(Double_t ti){fTime=ti;};
      void SetMeasMass(Double_t ti){fMeasMass=ti;};
      
      //Getting functions
      HSLorentzVector P4() const {return fP4;}
      HSLorentzVector* P4p()  {return &fP4;}
      HSPosition Vertex() const {return fVertex;}
      Double_t PDGMass()const {return fPDGMass;}
      Short_t PDG()const {return fPDGCode;}
      Int_t Charge();

      //Functions required by FinalState
      void ShiftTime(Float_t shift){fTime+=shift;}
      virtual Double_t DeltaTime(){return fTime;};
      Double_t Time()const { return fTime;}
      Double_t MeasMass()const { return fMeasMass;}
      Short_t Detector()const {return fDetector;}
      virtual Short_t Status(){return 0;}
      virtual void Clear();
      virtual void MinorClear();
      void CopyParticle(const BaseParticle* part,Bool_t andPDG);
      void CopyTransient(const BaseParticle* part);
      virtual void Print(Option_t *option="") const;

      HSLorentzVector* TruthP4p(){return &fTruthP4;};
      HSLorentzVector TruthP4() const {return fTruthP4;};
      HSPosition* TruthVer(){return &fTruthV;};
      Short_t TruthPDG()const {return fPDGCode;};
   
      TLorentzVector GetTLorentzVector() const {return TLorentzVector(fP4.X(),fP4.Y(),fP4.Z(),fP4.T());}
      TVector3 GetVertex3()const {return TVector3(fVertex.X(),fVertex.Y(),fVertex.Z());}


      
 
      //Add 4-vectors, doca vertices, fix pdg(optional)
      void Add(const BaseParticle *hsp1, const BaseParticle *hsp2,Int_t pdg=0);

 
      //need to permutate class
      //order in vector based on particle momentum
      //nb comparitive operator cannot work on pointers so vectors need
      //to be filled with object not pointers for this to work
      friend bool operator< ( const BaseParticle& lhs, const BaseParticle& rhs ){return lhs.fP4.P() < rhs.fP4.P(); };

      Double_t p3Distance(HSMomentum vec){return (fP4.Vect()-vec).Mag2();}

      Double_t ResTheta(){return fP4.Theta()-fTruthP4.Theta();};
      Double_t ResPhi(){return fP4.Phi()-fTruthP4.Phi();};
      Double_t ResP(){return fP4.P()-fTruthP4.P();};
      Double_t ResE(){return fP4.E()-fTruthP4.E();};
      Double_t ResAngle(){return ROOT::Math::VectorUtil::Angle(fP4,fTruthP4);};
      ClassDef(HS::BaseParticle,1); //class BaseParticle
    };
}//namespace HS

inline Int_t HS::BaseParticle::Charge(){
  
  if(fPDGCode==HS::UndefinedPDG) return 1;
  else if(fPDGCode==HS::UndefinedPDG) return -1;

  TParticlePDG *part=TDatabasePDG::Instance()->GetParticle(fPDGCode);
  if(part){
    Int_t charge=part->Charge();
    if(charge!=0)charge=(Int_t) charge/TMath::Abs(charge); //just get sign not mag.
    return charge;
  }
  else return 0;
}
inline void HS::BaseParticle::Clear(){
  MinorClear();
  fPDGCode=0;
}
inline void HS::BaseParticle::MinorClear(){
  fP4.SetXYZT(0,0,0,0);
  fTruthP4.SetXYZT(0,0,0,0);
  fMeasMass=0;
  fTime=0;
  fDetector=0;
 }
inline void HS::BaseParticle::CopyParticle(const BaseParticle* part,Bool_t andPDG){
  SetP4(part->P4());
  SetVertex(part->Vertex());
}
inline void HS::BaseParticle::CopyTransient(const BaseParticle* part){
  SetP4(part->P4());
  SetVertex(part->Vertex());
  fMeasMass=part->MeasMass();
  fTime=part->Time();
  fDetector=part->Detector();
}
inline void HS::BaseParticle::Add(const BaseParticle* hsp1, const BaseParticle* hsp2,Int_t pdg){
  //  SetVertex(hsp1->Vertex()+hsp2->Vertex()); //average vertex
  SetP4(hsp1->P4()+hsp2->P4());
  SetPDGcode(pdg);
  if(pdg){
    TakePDGMass();
  }
  
}	

#endif
