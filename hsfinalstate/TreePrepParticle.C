// Author: Michael Williams 2018 
// Modified: Derek Glazier 2018

/**********************************************************************************
* Project: HSFinalState && HSMVA                                                              *
* Package:                                                                       *
* Class  : TreePrepParticle                                                            *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*     For creating TMVA training tree in FinalState                           *
*     Given a THSParticle it will create default branches                        *
*     from datamembers of the THSParticle class                                  *
*     For each combitorial event it will then fill the tree                      *
*                                                                                *
**********************************************************************************/
#include "TreePrepParticle.h"
#include "TROOT.h"
#include <TSystem.h>


/*
 * Set TTree branches for variables necessary for MVA
 *
 */
void HS::TreePrepParticle::SetBranches() {
  TTree* tree=Tree();  
  if (!tree) {
        std::cout<<"ERROR : Base tree not found..."<<std::endl;
        std::cout<<"      : exiting..."                <<std::endl;
        exit(1);
    }

  std::cout<<"Setting branches..."<<std::endl;
    
   UInt_t VariableCount = 0;
   UInt_t ParticleCount = 0;

    // Now add branches for particles and variables
    std::cout<<"Printing variables: "<<std::endl;
    for (auto const& p : *VarNames() ) { 
        for (auto const& n : p) {
            std::cout<<"            "<<n<<"   ";
	    //  if (fTypes[fVariableCount] == "F") {
	    std::cout<<ParticleCount << " / " <<VariableCount<<std::endl;
	    tree->Branch(n, &(fVars[ParticleCount][VariableCount]), n  + "/F");
		// }
	    VariableCount++;
        }
        VariableCount = 0;
        ParticleCount++;
    }
    AddSigBck(); //Add branches for signal and backgrpound weights
}

void HS::TreePrepParticle::AddSigBck(){
  Tree()->Branch("Signal",&fSigWeight,"Sig/F");
  fNSig=0;	
  Tree()->Branch("Background",&fBckWeight,"Bck/F");
  fNBck=0;	
}

