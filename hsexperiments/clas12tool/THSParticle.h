//HASPECT Event Reconstruction
//THSParticle
//Optimised Persistant Data structure
//Contains reconstructed information required for data analysis

#ifndef HS_THSPARTICLE_H
#define HS_THSPARTICLE_H

#include "BaseParticle.h"
#include "region_particle.h"

//Allow THSParticle to be written to tree
#pragma link C++ class std::vector<HS::THSParticle >+;
#pragma link C++ class std::vector<HS::THSParticle* >+;

//using namespace std;
namespace HS{
  
   
  class THSParticle : public BaseParticle {
 
  
  public:
    
    THSParticle()=default;
    THSParticle(int code);
    THSParticle(TString pdgname);
    //THSParticle(c12_ptr ev);
      
    ~THSParticle()=default;
    THSParticle(const THSParticle& other) = default;
    THSParticle(THSParticle&& other) = default;
    
    THSParticle& operator=(const THSParticle& other)=default;
    THSParticle& operator=(THSParticle&& other)=default;
      
  
    //void Clear() override;
    void MinorClear() final; 

    //Add and Copy derived particles
    void CopyTransient(const THSParticle* part);
    void CopyParticle(const THSParticle* part,Bool_t andPDG);
    void Add(const THSParticle* hsp1, const THSParticle* hsp2,Int_t pdg);

    //New functions
    void SetCLAS12Particle(clas12::region_part_ptr p){fC12Particle=p;};
    clas12::region_part_ptr CLAS12() const {return fC12Particle;}
    void SetPath(Double_t path){fPath=path;}
    Double_t Path()const {return fPath;}
      


    Double_t Beta(){return fPath/fTime/2.99792e+08*1E9;}//time ns, path m
    // Double_t HypBeta(){Double_t pp=fP4.P();return 1;}//pp/sqrt(pp*pp+fPDGMass*fPDGMass);}
    Double_t HypBeta(){Double_t pp=fP4.P();return pp/sqrt(pp*pp+fPDGMass*fPDGMass);}
    Double_t HypTime(){return fPath/HypBeta()/2.99792e+08*1E9  ;} //in ns
    Double_t DeltaTime() override{return fTime-HypTime();};
    Double_t DeltaTimeVer(){return DeltaTime()-fVertex.Z()/2.99792e+08*1E9;}
 
  private:
    Double32_t fPath=0;
      
    clas12::region_part_ptr fC12Particle;
      
    Short_t fIndex=-1; //index of this particle in fEvent

       
    ClassDefOverride(HS::THSParticle,1); //class THSParticle
  };
}//namespace HS


inline void HS::THSParticle::MinorClear(){
  BaseParticle::MinorClear();
  //Reset any additional data members here
  fPath=0;
  fIndex=-1;
  fC12Particle=nullptr;//.reset();
}
inline void HS::THSParticle::CopyTransient(const THSParticle* part){
  BaseParticle::CopyTransient(part);
  fC12Particle=part->CLAS12();
  fPath=part->Path();
}
inline void HS::THSParticle::CopyParticle(const THSParticle* part,Bool_t andPDG){
  //This should be replaced by CopyTransient, but requires change of FinalState
  //And all THSParticle definitons must have it
  // BaseParticle::CopyParticle(part,andPDG);
  CopyTransient(part);
}

inline void HS::THSParticle::Add(const THSParticle* hsp1, const THSParticle* hsp2,Int_t pdg){
  BaseParticle::Add(hsp1,hsp2,pdg); 
}	

#endif
