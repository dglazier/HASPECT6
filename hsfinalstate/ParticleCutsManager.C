// Author: Derek Glazier 2018

/**********************************************************************************
* Project: HSFinalState                                                          *
* Package:                                                                       *
* Class  : ParticleCutsManager                                                   *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*     For creating cuts based analysis                                           *
*     Users must supply cuts object for each particle species (Can be the same)  *
*     These are then propogated through each topology and assessed as a          *
*     TopoActionManager    
*     Usage :                                                                    *
            unique_ptr<ParticleCutsManager> cm{new ParticleCutsManager()};
            shared_ptr<THSDeltaTimeCut> cutBeam{new THSDeltaTimeCut(2)};
            shared_ptr<THSDeltaTimeCut> cutOthers{new THSDeltaTimeCut(4)};

            cm->AddParticleCut("Beam",cutBeam);
            cm->SetDefaultCut(cutOthers);

            cm->ConfigureCuts(fs);

            finalstate->RegisterPostTopoAction(cm.get());
**********************************************************************************/
#include "ParticleCutsManager.h"
#include "TreePrepParticle.h"
#include "Topology.h"
using namespace HS;


/////////////////////////////////////////////////////////////////
///MAke an HSMVA::ResultByRefLink for each topology
void ParticleCutsManager::ConfigureCuts(FinalState* fs){

  auto topos=fs->GetTopologies();

  UInt_t NTopo=0;
  for(auto const& topo : *topos){

    auto pcuts=ParticleCutsPtr(new ParticleCuts());//don't construct tree
    //temporaty pointer to raw signalID
    //auto rawsigid=sigid.get();

    //    UInt_t nparts=topo->NParts();
    // for(UInt_t ip=0;ip<nparts;ip++){

    //Loop over all particles in this topology and assign a cut
    auto topo_parts=topo->GetParticles();
    for(auto const& particle : topo_parts){
 
      Int_t pdg = particle->PDG();
      //check if cut assigned for particular particle species
      if(fpdgToCut.find(pdg)==fpdgToCut.end())
	pcuts->AddParticle(fDefaultCut,particle);
      else //if not use default
	pcuts->AddParticle(fpdgToCut[pdg],particle);
    }
    Register(std::move(pcuts));
    NTopo++;
  }

}
