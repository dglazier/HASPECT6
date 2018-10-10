#ifndef HS_CUTS_h
#define HS_CUTS_h

#include <TNamed.h>
#include <TMath.h>
#include "THSParticle.h"
#include <cfloat>

class Cuts: public TNamed {
 public :

  Cuts()=default;
  Cuts(TString name):TNamed(name,name){};
  
  ~Cuts()=default;
  
  
  virtual Bool_t ParticleCut(THSParticle* part) const =0;
  
 protected:
  
};

//A simple derived cuts class
class DeltaTimeCut : public Cuts{
  
 public:
  DeltaTimeCut(Float_t cut=FLT_MAX){fTimeCut=cut;}

  Bool_t ParticleCut(THSParticle* part) const{
    if(TMath::Abs(part->DeltaTime())<fTimeCut) return kTRUE;
    return kFALSE;
  }
  void SetTimeCut(Float_t val){fTimeCut=val;}

 private:
  Float_t fTimeCut=FLT_MAX;

};

#endif
