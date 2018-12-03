// Author: Michael Williams 2018 
// Modified: Derek Glazier 2018

/**********************************************************************************
* Project: HSFinalState && HSMVA                                                 *
* Package:                                                                       *
* Class  : ParticleDataManager                                                   *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*     For creating TMVA training tree in FinalState                              *
*     Interface class. Derived classes should be implemented to                  *  
*     define and control the variables                                           *
**********************************************************************************/
#include "ParticleDataManager.h"
#include "TreePrepParticle.h"
#include "Topology.h"
using namespace HS;


void ParticleDataManager::ConfigureTreeParticles(FinalState* fs,vecNames defList){
  
//set default variables
  SetParticleVars("default",defList);

  auto topos=fs->GetTopologies();

  for(auto const& topo : *topos){
    cout<<"NExt topo "<<endl;
    auto prep=TreePDPtr(new TreeParticleData("ParticleVars",fOutDir+Form("ParticleVariables_%d.root",topo->ID()))); //construct tree
    prep->SetFinalState(fs);
    
    //Loop over particles and add variables
    UInt_t nparts=topo->NParts();
    for(UInt_t ip=0;ip<nparts;ip++){
      auto pname=topo->GetPartName(ip);
      //If selected variables have been chosen for this particle use them
      if(!(fPartVars[pname].empty()))
	prep->AddParticle(pname,topo->GetParticle(ip),fPartVars[pname]);
      else //if not use defaults
	prep->AddParticle(pname,topo->GetParticle(ip),fPartVars["default"]);
    }
    prep->SetBranches(); //set tree branches
    cout<<"Register"<<endl;
    RegisterPrep(std::move(prep));
    cout<<"done "<<endl;
  }

}


Bool_t ParticleDataManager::IsEnough(){
  Bool_t is_enough=kTRUE;
  for(auto& prep : fPreps) 
    is_enough*=prep->IsEnough();
  return is_enough;
}
void  ParticleDataManager::SetN(Long64_t nn){
  if(fPreps.empty())cout<<"Warning ParticleDataManager::SetN no preps defined yet"<<endl;
  for(auto& prep : fPreps) 
    prep->SetN(nn);
}
