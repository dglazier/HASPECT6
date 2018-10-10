// Author: Michael Williams 2018 
// Modified: Derek Glazier 2018

/**********************************************************************************
* Project: HSFinalState && HSMVA                                                 *
* Package:                                                                       *
* Class  : MVASignalIDManager                                                    *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*     For creating TMVA training tree in FinalState                              *
*     Interface class. Derived classes should be implemented to                  *  
*     define and control the variables                                           *
**********************************************************************************/
#include "MVASignalIDManager.h"
#include "TreePrepParticle.h"
#include "Topology.h"
using namespace HS;


/////////////////////////////////////////////////////////////////
///MAke an HSMVA::ResultByRefLink for each topology
void MVASignalIDManager::ConfigureResults(TString mvaName,FinalState* fs,vecNames defList){
  
//set default variables
  SetParticleVars("default",defList);

  auto topos=fs->GetTopologies();

  UInt_t NTopo=0;
  for(auto const& topo : *topos){

    auto sigid=MVASignalIDPtr(new MVASignalID());//don't construct tree
    //temporaty pointer to raw signalID
    auto rawsigid=sigid.get();

    UInt_t nparts=topo->NParts();
    for(UInt_t ip=0;ip<nparts;ip++){
      auto pname=topo->GetPartName(ip);
      //If selected variables have been chosen for this particle use them
      if(!(fPartVars[pname].empty()))
	rawsigid->AddParticle(pname,topo->GetParticle(ip),fPartVars[pname]);
      else //if not use defaults
	rawsigid->AddParticle(pname,topo->GetParticle(ip),fPartVars["default"]);
    }
    rawsigid->CreateResult(mvaName,fInDir+Form("Topo%d",NTopo));
    Register(std::move(sigid));
    NTopo++;
  }
  if(!fs->FinalTree()){
	throw std::runtime_error{"MVASignalIDManager FinalState class needs an output tree before being passed here"};
 
  }
  //store the classifier response in output tree
  fs->FinalTree()->Branch(mvaName,&fResult,mvaName+"/F");
}
