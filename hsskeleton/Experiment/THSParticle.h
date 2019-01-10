//HASPECT Event Reconstruction
//THSParticle
//Optimised Persistant Data structure
//Contains reconstructed information required for data analysis

#ifndef HS_THSPARTICLE_H
#define HS_THSPARTICLE_H

#include "BaseParticle.h"

//Allow THSParticle to be written to tree
#pragma link C++ class std::vector<HS::THSParticle >+;
#pragma link C++ class std::vector<HS::THSParticle* >+;

//using namespace std;
namespace HS{
      
    class THSParticle : public BaseParticle {
 
    protected:
  
    public:
      THSParticle()=default;  	        //Constructor
    THSParticle(int code):BaseParticle(code){};  	  //Constructor
    THSParticle(TString pdgname):BaseParticle(pdgname){}; //Constructor
      ~THSParticle()=default;	     	//Destructor
      THSParticle(const THSParticle& other) = default;
      THSParticle(THSParticle&& other) = default;

      THSParticle& operator=(const THSParticle& other)=default;
      THSParticle& operator=(THSParticle&& other)=default;
      
  
      void Clear() override;
      void MinorClear() override;

      //Add and Copy derived particles
      void CopyParticle(const THSParticle* part,Bool_t andPDG);
      void Add(const THSParticle* hsp1, const THSParticle* hsp2,Int_t pdg);
      
      ClassDefOverride(HS::THSParticle,1); //class THSParticle
    };
}//namespace HS


inline void HS::THSParticle::Clear(){
  BaseParticle::Clear();
  MinorClear();
}
inline void HS::THSParticle::MinorClear(){
  //Reset any additional data members here
}
inline void HS::THSParticle::CopyParticle(const THSParticle* part,Bool_t andPDG){
  BaseParticle::CopyParticle(part,andPDG);
}
inline void HS::THSParticle::Add(const THSParticle* hsp1, const THSParticle* hsp2,Int_t pdg){
  BaseParticle::Add(hsp1,hsp2,pdg); 
}	

#endif
