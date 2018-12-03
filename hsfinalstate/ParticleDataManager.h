////////////////////////////////////////////////////////////////
///
///Class:               ParticleDataManager
///Description:
///      Create trees for each topology containing particle data
///      Tree branches are given by $HSEXP/ParticleData.h class
///      An overall variable filter can be given in the Configure
///       ParticleDataManager::ConfigureTreeParticles(&fs,{"P","Theta","Time"}); 
///      For a specified particle additional filters applied by
///      ParticleDataManager::SetParticleVars("Beam",{"P","Time"});
///
#ifndef HSFS_PARTICLEDATAMANAGER_h
#define HSFS_PARTICLEDATAMANAGER_h

#include "THSParticle.h"
#include "TreePrepBase.h"
#include "TreeParticleData.h"
#include "TopoActionManager.h"
#include "FinalState.h"
#include <TSystem.h>
#include <vector>
#include <iostream>
#include <stdexcept>

namespace HS{

  //using TreePDPtr =TreeParticleData* ;
  using TreePDPtr = std::shared_ptr<TreeParticleData >;
  using vecTreePD = std::vector< TreePDPtr >;
  using mapStringVecNames = std::map< TString, vecNames >;

  class ParticleDataManager  : public TopoActionManager {
    
  public:
    ///Must give an output directory for saving trees to
    ParticleDataManager(TString outdir):fOutDir(outdir){

      if(gSystem->MakeDirectory(fOutDir)){
	cout<<"ParticleDataManager OutDir "<<fOutDir<<" cannot make this directory, you may need to delete it first or make sure its parent directory exists"<<endl;
	throw std::runtime_error{"ParticleDataManager cannot make give output directory"};
      }
      fOutDir+="/";
    }
    //when not making trees can use default
    ParticleDataManager()=default;
    virtual ~ParticleDataManager()=default;
 
    Bool_t Execute(TopoIndex ti) override{
      fPreps[ti]->Fill();
      return kTRUE;
    }

    //this will now have ownership of prep
    void RegisterPrep( TreePDPtr prep ){fPreps.push_back(std::move(prep));};
    //void RegisterPrep( TreePDPtr prep ){fPreps.push_back(prep);};
    TreeParticleData* GetLastParticleData(){return fPreps.back().get();}
    TreeParticleData* GetParticleData(UInt_t i){return fPreps.at(i).get();};
    UInt_t NData(){return fPreps.size();}

    // void ConfigureTreeParticles(FinalState* fs,vecNames defList={"P","Theta","Phi//","Time","Edep","DeltaE"});
    void ConfigureTreeParticles(FinalState* fs,vecNames defList={});
 
    void SetParticleVars(TString name,vecNames varnames){fPartVars[name]=varnames;};

    // void SetAllBranches();
    Bool_t IsEnough(); //Got enough events can stop processing
    void SetN(Long64_t nn); //set total number of events requested for each topo
    TString OutDir(){return fOutDir;};


  private:
    
    //This class manages TreePreps so that is all the data it needs
    vecTreePD fPreps;
    mapStringVecNames fPartVars;
    TString fOutDir;

  };//class ParticleDataManager

};//namespace HSFinalState

#endif //
