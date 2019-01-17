////////////////////////////////////////////////////////////////
///     HSDATA
///Class:               BaseParticleData
///Description:
///            Base class to be used as tree branches for THSParticles !
///            This class has to be defined for each experiment
///            It will be linked to the experiment THSParticle
///            Construct with e.g. MyParticleData("Proton",&fProton);
///
#ifndef HS_PARTICLEDATA_h
#define HS_PARTICLEDATA_h 
#include "TreeData.h"
#include "THSParticle.h"
#include <TMath.h>

namespace HS{

  class BaseParticleData: public HS::TreeData{

  public:
   
   /////////////////////////////////////////////////
 
    BaseParticleData()=default;
    BaseParticleData(TString name,HS::THSParticle* p)
      : TreeData(name),fParticle(p) {};
    BaseParticleData(const BaseParticleData&)=default;
    BaseParticleData(BaseParticleData&&)=default;
    virtual ~BaseParticleData()=default;

     virtual void FillData() =0 ;

    //Function required to set tree branches
    //virtual void Branches(ttree_ptr tree) =0 ;
    

  protected:
    HS::THSParticle* fParticle=nullptr;//!

  private:
    

    ClassDefOverride(BaseParticleData,1);

  };//class BaseParticleData

}//namespace HS
#endif
