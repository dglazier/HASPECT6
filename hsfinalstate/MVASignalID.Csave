// Author: Michael Williams 2018 
// Modified: Derek Glazier 2018

/**********************************************************************************
* Project: HSFinalState && HSMVA                                                              *
* Package:                                                                       *
* Class  : MVASignalID                                                            *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*     For creating TMVA training tree in FinalState                           *
*     Given a THSParticle it will create default branches                        *
*     from datamembers of the THSParticle class                                  *
*     For each combitorial event it will then fill the tree                      *
*                                                                                *
**********************************************************************************/
#include "MVASignalID.h"
#include "TROOT.h"
#include <TSystem.h>


/*
 * Set TTree branches for variables necessary for MVA
 *
 */

void HS::MVASignalID::CreateResult(TString methname,TString dirname){
  SetVarLinks();
  //Create mva result giving directory, method and links
  fResult.reset(new HS::MVA::ResultByRefLink(dirname,methname,fParticleLinks));

}
void HS::MVASignalID::SetVarLinks() {
 
  std::cout<<"Setting variable links..."<<std::endl;
    
   UInt_t VariableCount = 0;
   UInt_t ParticleCount = 0;

    // Now add branches for particles and variables
   std::cout<<"Printing variables: "<<" "<<fVarNames.size()<<std::endl;
    for (auto const& p : fVarNames ) { 
      std::cout<<"   number of vars "<<p.size()<<endl;
        for (auto const& n : p) {
            std::cout<<"            "<<n<<"   ";
	    //  if (fTypes[fVariableCount] == "F") {
	    std::cout<<ParticleCount << " / " <<VariableCount<<std::endl;
	    fParticleLinks[n]=&(fVars[ParticleCount][VariableCount]);
		// }
	    VariableCount++;
        }
        VariableCount = 0;
        ParticleCount++;
    }
}


