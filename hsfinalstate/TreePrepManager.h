
#ifndef HSFS_TREEPREPMANAGER_h
#define HSFS_TREEPREPMANAGER_h

#include "THSParticle.h"
#include "TreePrepBase.h"
#include "VarsParticle.h"
#include "TopoActionManager.h"
#include "FinalState.h"
#include <TSystem.h>
#include <vector>
#include <iostream>
#include <stdexcept>

namespace HS{

  using TreePrepPtr = std::unique_ptr<TreePrepBase >;
  using vecTreePrep = std::vector< TreePrepPtr >;
  using mapStringVecNames = std::map< TString, vecNames >;

  class TreePrepManager  : public TopoActionManager {
    
  public:
    ///Must give an output directory for saving trees to
    TreePrepManager(TString outdir):fOutDir(outdir){

      if(gSystem->MakeDirectory(fOutDir)){
	cout<<"TreePrepManager OutDir "<<fOutDir<<" cannot make this directory, you may need to delete it first or make sure its parent directory exists"<<endl;
	throw std::runtime_error{"TreePrepManager cannot make give output directory"};
      }
      fOutDir+="/";
    }
    //when not making trees can use default
    TreePrepManager()=default;
    virtual ~TreePrepManager()=default;
 
    Bool_t Execute(TopoIndex ti) override{
      fPreps[ti]->Fill();
      return kTRUE;
    }

    //this will now have ownership of prep
    void RegisterPrep( TreePrepPtr prep ){fPreps.push_back(std::move(prep));};
    TreePrepBase* GetLastPrep(){return fPreps.back().get();}
    TreePrepBase* GetPrep(UInt_t i){return fPreps.at(i).get();};
    UInt_t NPreps(){return fPreps.size();}

    void ConfigureTreeParticles(FinalState* fs,vecNames defList={"P","Th","Phi","Time","Edep","DeltaE"});
 
    void SetParticleVars(TString name,vecNames varnames){fPartVars[name]=varnames;};

    // void SetAllBranches();
    Bool_t IsEnough(); //Got enough events can stop processing
    void SetN(Long64_t nn); //set total number of events requested for each topo
    TString OutDir(){return fOutDir;};


  private:
    
    //This class manages TreePreps so that is all the data it needs
    vecTreePrep fPreps;
    mapStringVecNames fPartVars;
    TString fOutDir;

  };//class TreePrepManager

};//namespace HSFinalState

#endif //
