// Author: Michael Williams 2018 
    
/**********************************************************************************
* Project: THSMVA                                                                *
* Package:                                                                       *
* Class  : THSMVAPrep                                                            *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*     For creating TMVA training tree in THSFinalState                           *
*     Given a THSParticle it will create default branches                        *
*     from datamembers of the THSParticle class                                  *
*     For each combitorial event it will then fill the tree                      *
*                                                                                *
**********************************************************************************/

#include "THSMVAPrep.h"
#include "TROOT.h"

ClassImp(THSMVAPrep);


//////////////////////////
/// Constructor 
//////////////////////////

THSMVAPrep::THSMVAPrep(){

}

/*
 * Set branches for variables necessary for MVA
 *
 */

void THSMVAPrep::SetBranches() {
    if (!fBaseTree) {
        std::cout<<"ERROR : Base tree not found..."<<std::endl;
        std::cout<<"      : exiting..."                <<std::endl;
        exit(1);
    }

    std::cout<<"Setting branches..."<<std::endl;
    
    fVariableCount = 0;
    fParticleCount = 0;

    // Now add branches for particles and variables
    std::cout<<"Printing variables: "<<std::endl;
    for (auto const& p : fNames ) { 
        for (auto const& n : p) {
            std::cout<<"            "<<n<<"   ";
            if (fTypes[fVariableCount] == "F") {
                std::cout<<fParticleCount << " / " <<fVariableCount<<std::endl;
                fBaseTree->Branch(n, &(fTreeVarsF[fParticleCount][fVariableCount]), n  + "/F");
            }
            if (fTypes[fVariableCount] == "I") {
                std::cout<<fParticleCount << " / " <<fVariableCount<<std::endl;
                fBaseTree->Branch(n, &(fTreeVarsI[fParticleCount][fVariableCount]), n  + "/I");
            }
            fVariableCount++;
        }
        fVariableCount = 0;
        fParticleCount++;
    }
}

/**
 * Remove NaN values from an entry
 *
 */

void THSMVAPrep::RemoveNaNs(){

    //std::cout<<"Removing NaNs..."<<std::endl;

    for (UInt_t iPar=0; iPar<fParticleID.size(); iPar++) {
        for (UInt_t iVar=0; iVar<fTreeVarsF[iPar].size(); iVar++) {
            if (!std::isfinite(fTreeVarsF[iPar][iVar])){
                fTreeVarsF[iPar][iVar] = 0;
            }
        }
        for (UInt_t iVar=0; iVar<fTreeVarsI[iPar].size(); iVar++) {
            if (!std::isfinite(fTreeVarsI[iPar][iVar])){
                fTreeVarsI[iPar][iVar] = 0;
            }
        }
    } 
    fN++;
}

/**
 * Add variables from a THSParticle with predefined options
 *
 */

void THSMVAPrep::AddVarsFromParticle(THSParticle* tmpParticle, Int_t tmpPCount) {
    fCountF = 0;
    fCountI = 0;
    // add values depnding on method used to add variables
    if (!fVarNames.empty()){
        for (auto const& v : fVarNames[tmpPCount]) {
            if (v == "Time") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->DeltaTime(); fCountF++;};
            if (v == "Edep") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->Edep(); fCountF++;};
            if (v == "DeltaE") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->DeltaE(); fCountF++;};
            if (v == "PreE") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->PreE(); fCountF++;};
            if (v == "P") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->P4p()->P(); fCountF++;};
            if (v == "Th") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->P4p()->Theta(); fCountF++;};
            if (v == "Phi") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->P4p()->Phi(); fCountF++;};
            if (v == "Vz") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->Vertex().Z(); fCountF++;};
            if (v == "TrChi2") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->TrChi2(); fCountF++;};
            // convert to float for training
            if (v == "Det") {fTreeVarsI[tmpPCount][fCountI] = tmpParticle->Detector(); fCountI++;
            }
        }
    }
    else{
        for (auto const& v : fVariableID) {
            if (v == "Time") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->DeltaTime(); fCountF++;};
            if (v == "Edep") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->Edep(); fCountF++;};
            if (v == "DeltaE") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->DeltaE(); fCountF++;};
            if (v == "PreE") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->PreE(); fCountF++;};
            if (v == "P") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->P4p()->P(); fCountF++;};
            if (v == "Th") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->P4p()->Theta(); fCountF++;};
            if (v == "Phi") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->P4p()->Phi(); fCountF++;};
            if (v == "Vz") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->Vertex().Z(); fCountF++;};
            if (v == "TrChi2") {fTreeVarsF[tmpPCount][fCountF] = tmpParticle->TrChi2(); fCountF++;};
            // convert to float for training
            if (v == "Det") {fTreeVarsI[tmpPCount][fCountI] = tmpParticle->Detector(); fCountI++;
            }
        }
    }
}

///////////////////////////////////////////////////////////
///Destructor
///////////////////////////////////////////////////////////

THSMVAPrep::~THSMVAPrep(){
    delete fBaseTree;
}
