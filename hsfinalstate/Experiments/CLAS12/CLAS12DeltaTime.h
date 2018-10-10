///////////////////////////////////////////////////
///Persistant cuts base class for use with THSFinalState
///Defaults to time cuts on each partcle
#ifndef HS_CLAS12DELTATIME_h
#define HS_CLAS12DELTATIME_h

#include "Cuts.h"

namespace HS{
  
  class CLAS12DeltaTime: public Cuts {

  public :
    CLAS12DeltaTime()=default;
    CLAS12DeltaTime(Float_t FT,Float_t FD,Float_t CD,Float_t FDCAL):Cuts(){
      fCLAS12TimeCuts[0]=FT;
      fCLAS12TimeCuts[1]=FD;
      fCLAS12TimeCuts[2]=CD;
      fCLAS12TimeCuts[3]=FDCAL;
    };
    ~CLAS12DeltaTime()=default;
    
    Bool_t ParticleCut(THSParticle* part) const override ;
    
    Short_t Detector(Int_t det) const;
    //   Bool_t Cherenkov(Int_t det);
    
    
    
  protected:
    //                        FT,FD,CD,FTCAL
    Float_t fCLAS12TimeCuts[4]={2, 2, 2, 2};
    
  };
}//namespace HS

inline Short_t HS::CLAS12DeltaTime::Detector(Int_t det) const{
  if(det<0) return 0; //FT
  else if(det==0) return 10; //undefined
  else if(det<9999) return 1; //FD
  else if(det==10000) return 2; //CD
  else if(det%1000>99) return 3; //FDCAL no scintillator
  return 10;
}


//////////////////////////////////////////////////
///Timing cuts for CLAS12 protons
inline Bool_t HS::CLAS12DeltaTime::ParticleCut(THSParticle* part) const{
  if(part->Time()==0) return kFALSE;
  
  Short_t det=Detector(part->Detector());
  if(det>3) return kFALSE; //not a defined detector
  
  //FT det=0, FD det=1, CD det=2, FDCAL det=3
  if(TMath::Abs(part->DeltaTime())<fCLAS12TimeCuts[det]) return kTRUE;
  
  return kFALSE;
}


#endif
