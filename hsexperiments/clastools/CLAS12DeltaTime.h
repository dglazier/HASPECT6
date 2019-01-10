///////////////////////////////////////////////////
///Persistant cuts base class for use with THSFinalState
///Defaults to time cuts on each partcle
#ifndef HS_CLAS12DELTATIME_h
#define HS_CLAS12DELTATIME_h

#include "Cuts.h"

namespace HS{
  
  class Cuts;

  namespace CLAS12{
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
    
      Bool_t ParticleCut(HS::THSParticle* part) const override ;
    
      Short_t Detector(Int_t det,Int_t status) const;
      //   Bool_t Cherenkov(Int_t det);
      Bool_t isFDToF(Int_t status) const;
    
    
    protected:
      //                        FT,FD,CD,FTCAL
      Float_t fCLAS12TimeCuts[4]={2, 2, 2, 2};
    
    };
  }//namespace CLAS12
}//namespace HS
inline Short_t HS::CLAS12::CLAS12DeltaTime::Detector(Int_t det,Int_t status) const{
  if(det==clas12::FT) return 0; //FT
  else if(det==clas12::FD){
    if(isFDToF(status) ) return 1; //FD
    else return 3;//FDCAL no scintillator
  }
  else if(det==clas12::CD) return 2; //CD
  return 10;
}

inline Bool_t  HS::CLAS12::CLAS12DeltaTime::isFDToF(Int_t status) const{
  if(status>2090&&status<3000) //FD with TOF
    return kTRUE;
  else return kFALSE;
}
//////////////////////////////////////////////////
///Timing cuts for CLAS12 protons
inline Bool_t HS::CLAS12::CLAS12DeltaTime::ParticleCut(HS::THSParticle* part) const{
  if(part->Time()==0) return kFALSE;
  
  Short_t det=Detector(part->CLAS12()->region(),part->CLAS12()->par()->getStatus());
  if(det>3) return kFALSE; //not a defined detector
  
  //FT det=0, FD det=1, CD det=2, FDCAL det=3
  if(TMath::Abs(part->DeltaTime())<fCLAS12TimeCuts[det]) return kTRUE;
  
  return kFALSE;
}


#endif
