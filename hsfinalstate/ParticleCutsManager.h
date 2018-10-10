
#ifndef HSFS_PARTICLECUTSMANAGER_h
#define HSFS_PARTICLECUTSMANAGER_h

#include "THSParticle.h"
#include "Cuts.h"
#include "ParticleCuts.h"
#include "TopoActionManager.h"
#include "FinalState.h"
#include <TSystem.h>
#include <vector>
#include <map>
#include <iostream>
#include <stdexcept>

namespace HS{
  
  using ParticleCutsPtr = std::unique_ptr<ParticleCuts >;
  using vecParticleCuts = std::vector< ParticleCutsPtr >;
 
  ////////////////////////////////////////////////////////////////////////
  class ParticleCutsManager  : public TopoActionManager {
    
  public:
    ///Must give an output directory for saving trees to
    ParticleCutsManager(){
      //default delta time cut = no cut!
      shared_ptr<Cuts> defcut{new DeltaTimeCut()};
      SetDefaultCut(std::move(defcut));
      AddParticleCut(0,fDefaultCut);
    }
    virtual ~ParticleCutsManager()=default;
 
    Bool_t Execute(TopoIndex ti) override{
      return fParticleCuts[ti]->CheckCuts();
    }

    void ConfigureCuts(FinalState* fs);
    //this will now have ownership of prep
    void Register( ParticleCutsPtr pcuts ){fParticleCuts.push_back(std::move(pcuts));};
    void SetDefaultCut(shared_ptr<Cuts> defcut) {fDefaultCut.reset();fDefaultCut=defcut;}
  
    void AddParticleCut(Int_t type,shared_ptr<Cuts> cut){
      if(fpdgToCut.find(type)!=fpdgToCut.end())
	cout<<"Warning ParticleCutsManager AddParticleCut already got cut for "<<type<<endl;
      else {
	cout<<"Info ParticleCutsManager AddParticleCut set cut for "<<type<<endl;
	fpdgToCut[type]=cut;
      }
    };
    void AddParticleCut(TString type,shared_ptr<Cuts> cut){
      Int_t pdg=0;     
      if(type==TString("Beam")) pdg=-22;
      else if(TDatabasePDG::Instance()->GetParticle(type))
	pdg=TDatabasePDG::Instance()->GetParticle(type)->PdgCode();
      AddParticleCut(pdg,cut);
    };

  private:
    
    //This class manages ParticleCuts 
    vecParticleCuts fParticleCuts;
    //This links particles pdg code to correct cut object
    std::map<Int_t,shared_ptr<Cuts> > fpdgToCut;

    //default cut
    shared_ptr<Cuts>  fDefaultCut;

  };//class ParticleCutsManager

};//namespace HSFinalState

#endif //
