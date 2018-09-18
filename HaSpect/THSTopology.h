#ifndef THSTOPOLOGY_h
#define THSTOPOLOGY_h

#include <vector>
#include <functional>

#include "THSParticle.h"
#include "THSParticleIter.h"
#include "THSFinalState.h"



class THSTopology{

 public :

  THSTopology(){};
  THSTopology(TString topo,FinalState::VoidFuncs funcE,TString chPID="",TString incl="");
  virtual ~THSTopology();

  
  FinalState::VoidFuncs Exec;
 
 public:
  Bool_t CheckTopo(vector<Short_t> *detTopo);
  Bool_t CheckExclusiveTopo(vector<Short_t> *detTopo);
  Bool_t CheckInclusiveTopo(vector<Short_t> *detTopo);
  Bool_t AnyMissing(Short_t missID);
  void SetInclusive(TString parts);
  void SetChargePID(TString parts);

  void SetIter(THSParticleIter* iter){fIter=iter;};
  THSParticleIter* Iter(){return fIter;}

  void SetAlternative(THSTopology* alt){fAlternative=alt;}
  THSTopology*  Alternative(){return fAlternative;}
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

  UInt_t HowManyTrue(Short_t pdg);
  
  void Print(Int_t verbose);


private:

  vector<THSParticle*> fParticles; //contains particles from THSFinalState class

  THSParticleIter *fIter=nullptr;
  vector<Short_t> fTrueDefinition; //pdg codes needed for this topology
  vector<Short_t> fActualDefinition; //pids needed for this topology
  vector<Short_t> fIncParts; //particle allowed to be inclusive
  vector<Short_t> fChargeParts; //particle allowed be IDed by charge

  //Flag to do PID by charge not given pdg code
  Bool_t fUseChargePID=kFALSE;
  Bool_t fIsInclusive=kFALSE;

  Int_t fID; //reference number

  const Int_t fNoID=1E4;
  
  THSTopology* fAlternative=nullptr; //Another topology with same detected final state

};

#endif
