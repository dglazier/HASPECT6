////////////////////////////////////////////////////////////////
///
///Class:               MVASignalID
///Description:
///         Class to hold ParticleData for each topology
///         and link it to MVA ResultByRefLink to evaluate classifier
///         Each detected particle in the topolgy adds a
///         ParticleData object into fPData vector
///         MVASignalIDManager holds a vector of MVASignalIDs
///         with an entry for each topology

#ifndef HSFS_MVASIGNALID_h
#define HSFS_MVASIGNALID_h

#include "THSParticle.h"
#include "TreeParticleData.h"
#include "ResultInterface.h"

namespace HS{


  class MVASignalID : public TreeParticleData {

  public:
    void SetVarLinks();
    Float_t  Eval(){
      FillVars();
      return fResult.get()->Eval();
    }
    
    void CreateResult(TString methname,TString dirname);

  private:
    unique_ptr<HS::MVA::ResultByRefLink> fResult;
    
    HS::MVA::mapNameFloat fParticleLinks;

  }; //class MVASignalID

}//namespace HS


#endif

 
