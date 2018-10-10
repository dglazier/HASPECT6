
#ifndef HSFS_MVASIGNALIDMANAGER_h
#define HSFS_MVASIGNALIDMANAGER_h

#include "THSParticle.h"
#include "MVASignalID.h"
#include "VarsParticle.h"
#include "TopoActionManager.h"
#include "FinalState.h"
#include <TSystem.h>
#include <vector>
#include <iostream>
#include <stdexcept>

namespace HS{

  using MVASignalIDPtr = std::unique_ptr<MVASignalID >;
  using vecMVASignalID = std::vector< MVASignalIDPtr >;
  using mapStringVecNames = std::map< TString, vecNames >;
  ////////////////////////////////////////////////////////////////////////
  class MVASignalIDManager  : public TopoActionManager {
    
  public:
    ///Must give an input directory for getting MVA training weights
    MVASignalIDManager(TString indir):fInDir(indir){
      fInDir+="/";
    }
    MVASignalIDManager()=default;
    virtual ~MVASignalIDManager()=default;
 
    Bool_t Execute(TopoIndex ti) override{
      fResult=fMVASignalIDs[ti]->Eval();
      if(fResult>fCutVal) return kTRUE;
      return kFALSE;
    }

    void ConfigureResults(TString mvaName,FinalState* fs,vecNames defList={"P","Th","Phi","Time","Edep","DeltaE"});

    //this will now have ownership of signalID
    void Register( MVASignalIDPtr sigid ){fMVASignalIDs.push_back(std::move(sigid));};
    TString InDir(){return fInDir;};
    void SetCut(Float_t val){fCutVal=val;}

    void SetParticleVars(TString name,vecNames varnames){fPartVars[name]=varnames;};

  private:
    
    vecMVASignalID fMVASignalIDs;
    mapStringVecNames fPartVars;
    TString fInDir;
    Float_t fResult;
    Float_t fCutVal=FLT_MIN;
  };//class MVASignalIDManager

};//namespace HSFinalState

#endif //
