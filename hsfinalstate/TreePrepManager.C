// Author: Michael Williams 2018 
// Modified: Derek Glazier 2018

/**********************************************************************************
* Project: HSFinalState && HSMVA                                                              *
* Package:                                                                       *
* Class  : TreePrepManager                                                              *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*     For creating TMVA training tree in FinalState                           *
*     Interface class. Derived classes should be implemented to                  *  
*     define and control the variables                                           *
**********************************************************************************/
#include "TreePrepManager.h"
#include "TreePrepParticle.h"
#include "Topology.h"
using namespace HS;


void TreePrepManager::ConfigureTreeParticles(FinalState* fs,vecNames defList){
  
//set default variables
  SetParticleVars("default",defList);

  auto topos=fs->GetTopologies();

  for(auto const& topo : *topos){
    auto prep=TreePrepPtr(new TreePrepParticle("ParticleVars",fOutDir+Form("ParticleVariables_%d.root",topo->ID()))); //construct tree
    //fPreps.push_back(prep);
    auto rawprep=dynamic_cast<TreePrepParticle*>(prep.get());
    rawprep->SetFinalState(fs);
    //Loop over particles and add variables
    UInt_t nparts=topo->NParts();
    for(UInt_t ip=0;ip<nparts;ip++){
      auto pname=topo->GetPartName(ip);
      //If selected variables have been chosen for this particle use them
      if(!(fPartVars[pname].empty()))
	rawprep->AddParticle(pname,topo->GetParticle(ip),fPartVars[pname]);
      else //if not use defaults
	rawprep->AddParticle(pname,topo->GetParticle(ip),fPartVars["default"]);
    }
    rawprep->SetBranches(); //set tree branches
    RegisterPrep(std::move(prep));
  }

}

Bool_t TreePrepManager::IsEnough(){
  Bool_t is_enough=kTRUE;
  for(auto& prep : fPreps) 
    is_enough*=prep->IsEnough();
  return is_enough;
}
void  TreePrepManager::SetN(Long64_t nn){
  if(fPreps.empty())cout<<"Warning TreePrepManager::SetN no preps defined yet"<<endl;
  for(auto& prep : fPreps) 
    prep->SetN(nn);
}

