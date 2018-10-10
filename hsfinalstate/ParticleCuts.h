// Modified: Derek Glazier 2018

/**********************************************************************************
* Project: HSFinalState 			                                 *
* Package:                                                                      *
* Class  : ParticleCuts                                                            *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*     Tree in FinalState                                                      *
*     Given a THSParticle and a cut object (inheriting from Cuts)             *
*      it will decide if cut is passed                                           *
*                                                                                *
**********************************************************************************/
#ifndef HSFS_PARTICLECUTS_h
#define HSFS_PARTICLECUTS_h

#include "THSParticle.h"
#include "Cuts.h"
#include "ParticleCuts.h"
#include <vector>
#include <memory>

namespace HS{


  class ParticleCuts {

  public:
    ParticleCuts(){};
    virtual ~ParticleCuts()=default;
 
    void AddParticle(shared_ptr<Cuts> cut,THSParticle* particle){
      fCuts.push_back(cut);
      fParticles.push_back(particle);
    }

    Bool_t  CheckCuts();
    
private:

    //These vectors should be in sync, 1 cut for 1 particle
    std::vector<shared_ptr<Cuts> > fCuts; 
    std::vector<THSParticle* > fParticles;   
    
  };//class ParticleCuts

};//namespace HSFinalState

#endif //
