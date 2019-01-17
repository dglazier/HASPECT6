////////////////////////////////////////////////////////////////
///     CLAS12 EXPERIMENT
///Class:               ParticleData
///Description:
///            A derived class to be used as tree branches !
///            This class has to be defined for each experiment
///            It will be linked to the experiment THSParticle
///            Construct with e.g. ParticleData("Proton",&fProton);
///
#ifndef PARTICLEDATA_h
#define PARTICLEDATA_h 
#include "BaseParticleData.h"
#include "THSParticle.h"
#include "region_particle.h"
#include "clas12defs.h"
#include <TMath.h>

namespace HS{

  class ParticleData: public BaseParticleData{

  public:
    /////////////////////////////////////////////////
    /// data member for tree branches below here
    /// Experiment developers add your own data members
    /// if you want them in the tree
    /// then assign them in  ParticleData::FillData()
    Float_t P=0;
    Float_t Theta=0;
    Float_t Phi=0;
    Float_t Vz=0;
    Float_t Time=0;
    Float_t Edep=0;
    Float_t DeltaE=0;
    Float_t PreE=0;
    Float_t HTCC=0;
    Float_t LTCC=0;
    Float_t TrChi2=0;
    Short_t Region=-1;
    Short_t Sector=-1;
    Short_t Status=0;
    
   /////////////////////////////////////////////////
 
    ParticleData()=default;
    ParticleData(TString name,HS::THSParticle* p)
      : BaseParticleData(name,p) {};
    ParticleData(const ParticleData&)=default;
    ParticleData(ParticleData&&)=default;
    virtual ~ParticleData()=default;

    void FillData() override;

    //Function required to set tree branches
    //This should not need changed
   void Branches(ttree_ptr tree) override{
      TreeData::Branches(tree,Class()->GetListOfDataMembers());
    }
    
 
  private:
    
     ClassDefOverride(ParticleData,1);

  };//class ParticleData

  ////////////////////////////////////////////////////
  /// Fill in the data from the THSParticle functions
  /// Experiment developers fill your own data members here....
  inline void ParticleData::FillData(){
    //move the c12p object to this particle for getting detector data
    auto c12p=fParticle->CLAS12();
    
    auto r2d=TMath::RadToDeg();
 
    P     =  fParticle->P4p()->P();
    Theta =  fParticle->P4p()->Theta()*r2d;
    Phi   =  fParticle->P4p()->Phi()*r2d;
    Vz    =  fParticle->Vertex().Z();

    Time  =  fParticle->DeltaTime();

    //All
    Region = c12p->region();
    Edep = c12p->getDetEnergy();
    Sector = c12p->getSector();
    Status = c12p->par()->getStatus();
   
    //All Charged
    DeltaE = c12p->getDeltaEnergy();

    //Region(FT,FD,CD) specific variables
    switch(c12p->region()) {
      
    case clas12::FD :
      PreE = c12p->cal(clas12::PCAL)->getEnergy();
      // ECINM2u = c12p->cal(clas12::ECIN)->M2u();
      //ECOUTM2u = c12p->calorimetry(clas12::ECOUT)->M2u();
      
      HTCC = c12p->che(clas12::HTCC)->getNphe();
      LTCC = c12p->che(clas12::LTCC)->getNphe();
      
      TrChi2= c12p->trk(clas12::DC)->getChi2N();
      break;
    case clas12::FT :
      break;
    case clas12::CD :
      TrChi2= c12p->trk(clas12::CVT)->getChi2N();
      break;
    }
    
  }
}//namespace HS
#endif
