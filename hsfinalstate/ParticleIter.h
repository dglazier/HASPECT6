#ifndef HS_PARTICLEITER_h
#define HS_PARTICLEITER_h

#include "Combitorial.h"
#include "THSParticle.h"

namespace HS{
  class Combitorial;
  
  class ParticleIter{
    
  public :
    ParticleIter()=default;
    virtual ~ ParticleIter(){
      delete fExtraParticle;
      if(fInnerIter) delete fInnerIter;
    }
 
    Combitorial* GetCombi(){return &fCombi;}
    
    void SetNSel(Int_t n){fNSel=n;}
    void SetNIdentical(Int_t n){fNIdentical=n;}
    Int_t GetNSel(){return fNSel;}
    Int_t GetNIdentical(){return fNIdentical;}
    
    vector<THSParticle*>* GetAllParticles(){return fAllParticles;}
    void SetParticles(vector<THSParticle*> *parts){fAllParticles=parts;}
    void SetSelParticles(vector<THSParticle*> parts){fSelected=parts;}
    
    
    void SetSelIter(ParticleIter* com){fSelIter=com;}
    void SetRemIter(ParticleIter* com){fRemIter=com;}
    
    void AddEventParticle(THSParticle* part){fEvParts.push_back(part);};
    void AddEventParticles(THSParticle* part0=nullptr,THSParticle* part1=nullptr,THSParticle* part2=nullptr,THSParticle* part3=nullptr,THSParticle* part4=nullptr,THSParticle* part5=nullptr,THSParticle* part6=nullptr,THSParticle* part7=nullptr,THSParticle* part8=nullptr,THSParticle* part9=nullptr);
    void SetEventParticles(vector<THSParticle*> parts){fEvParts=parts;};
    
    void SortEvent();
    void SetCombi(Combitorial combi){fCombi=combi;fUseCombi=kTRUE;}
    void GotoStart(){ fCombi.ResetNiter();fDoneSelRem=kTRUE;if(fInnerIter) fInnerIter->GotoStart();}
    
    THSParticle* NextParticle();
    Bool_t NextCombitorial();
    
    void ConfigureIters();
    void SetNextInnerIter(ParticleIter *_iter);
    void SelectXofY(Int_t _X, Int_t _Y, Combitorial* sel_iter=nullptr);
    
    Int_t PDG(){return fPDG;}
    void SetPDG(Int_t pdg){fPDG=pdg;}; 
    void Print(Int_t verbose);
    void SetName(TString name){fName=name;}
    TString GetName(){return fName;}

  private:

    TString fName;
    Int_t fPDG=0; //PDG code for particles in this iterator
    Combitorial fCombi; //handler for the combination/permuations
    ParticleIter *fInnerIter=nullptr;  //recursive iterator
    ParticleIter *fSelIter=nullptr;  //selected iterator
    ParticleIter *fRemIter=nullptr;  //remaining iterator
    vector<THSParticle*> *fAllParticles=nullptr; //vector of particles for this event
    vector<THSParticle*>  fSelected; //combitorial for selected particles
    vector<THSParticle*>  fRemainder; //combitorial for unselected particles
    
    vector<THSParticle*>  fEvParts; //particles to be used in event
    
    UInt_t fParti=0;// index of next particle
    Bool_t fUseCombi=kFALSE;
    Bool_t   fDoneSelRem=kTRUE;
    Bool_t fIsConfigured=kFALSE;
    Int_t fNSel=0;
    Int_t fNIdentical=1;
    
    THSParticle* fExtraParticle=new THSParticle(-1);
  
  }; //class ParticleIter
}//namespace HS

#endif
