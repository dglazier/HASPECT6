#ifndef HS_TOPOLOGY_h
#define HS_TOPOLOGY_h

#include <vector>
#include <functional>

#include "THSParticle.h"
#include "ParticleIter.h"
#include "FinalState.h"


namespace HS{
  
  class Topology{

  public :
    
    Topology(){};
    Topology(TString topo,VoidFuncs funcE,TString chPID="",TString incl="");
    virtual ~Topology();
    
    
    VoidFuncs Exec;
    
  public:
    Bool_t CheckTopo(vector<Short_t> *detTopo);
    Bool_t CheckExclusiveTopo(vector<Short_t> *detTopo);
    Bool_t CheckInclusiveTopo(vector<Short_t> *detTopo);
    Bool_t AnyMissing(Short_t missID);
    void SetInclusive(TString parts);
    void SetChargePID(TString parts);
    
    void SetIter(ParticleIter* iter){fIter=iter;};
    ParticleIter* Iter(){return fIter;}
    
    vector<Short_t>* Definition() {return &fActualDefinition;}
    vector<Short_t>* True() {return &fTrueDefinition;}
    
    void SetID(Int_t id){fID=id;}
    Int_t ID(){return fID;}
    
    Short_t PDGtoCharge(Short_t pdg);
    Short_t ParticleID(Short_t pdg);
    void TopoToCharge(vector<Short_t> *thisTopo);
    
    vector<THSParticle*> GetParticles(){return fParticles;}
    THSParticle* GetParticle(UInt_t ip){return fParticles[ip];}
    void SetParticles(vector<THSParticle*> parts){fParticles=parts;};
    void SetPartNames(vector<TString> names){fPartNames=names;}
    vector<TString> GetPartNames(){return fPartNames;}
    TString GetPartName(UInt_t i){if(fPartNames.size()>i) return fPartNames[i]; cout<<"Warning Topology PartName not enough particles"<<endl; return TString();}
    
    UInt_t NParts(){return fTrueDefinition.size();}
    
    UInt_t HowManyTrue(Short_t pdg);
    
    void Print(Int_t verbose);
    
    
  private:
    
    vector<THSParticle*> fParticles; //contains particles from THSFinalState class
    vector<TString> fPartNames;
    
    ParticleIter *fIter=nullptr;
    vector<Short_t> fTrueDefinition; //pdg codes needed for this topology
    vector<Short_t> fActualDefinition; //pids needed for this topology
    vector<Short_t> fIncParts; //particle allowed to be inclusive
    vector<Short_t> fChargeParts; //particle allowed be IDed by charge
    
    //Flag to do PID by charge not given pdg code
    Bool_t fUseChargePID=kFALSE;
    Bool_t fIsInclusive=kFALSE;
    
    Int_t fID; //reference number
    
    const Short_t fNoID=1E4;
    
    
  }; //class Topology
}//namespace HS
#endif
  
