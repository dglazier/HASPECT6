
#include "Cuts.h"

class DeltaTimePCut : public Cuts{
  
 public:
 //Define consructor taking cut value arguments
  DeltaTimePCut(Float_t cutT=FLT_MAX,Float_t cutP=FLT_MAX){
    fTimeCut=cutT; fPCut=cutP;
    }
//Define function to test cut
  Bool_t ParticleCut(THSParticle* part) const{
    if(TMath::Abs(part->DeltaTime())<fTimeCut
        &&(part->P4p()->P())<fPCut) return kTRUE;
    return kFALSE;
  }

 private:
  Float_t fTimeCut=FLT_MAX;
  Float_t fPCut=FLT_MAX;
};