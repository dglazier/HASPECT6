// Author: Michael Williams 2018 
// Modified: Derek Glazier 2018

/**********************************************************************************
* Project: HSFinalState && HSMVA                                                              *
* Package:                                                                       *
* Class  : VarsParticle                                                            *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*     For creating TMVA training tree in THSFinalState                           *
*     Given a THSParticle it will create default branches                        *
*     from datamembers of the THSParticle class                                  *
*     For each combitorial event it will then fill the tree                      *
*                                                                                *
**********************************************************************************/
#include "VarsParticle.h"
#include "TROOT.h"
#include <TSystem.h>



void HS::VarsParticle::AddVarsFromParticle(Int_t tmpPCount) {
  
  //Get the HSParticle particle
  auto tmpParticle=GetParticle(tmpPCount);

  UInt_t countF = 0;
  // add values depnding on method used to add variables
  // if (!fVarNames.empty()){
  for (auto const& v : fPVarIndex[tmpPCount]) {
    //cout<<v<<" "<<fPVarIndex[tmpPCount].size()<<endl;
    if (v == kPartTime) {fVars[tmpPCount][countF++] = tmpParticle->DeltaTime(); }
    else if (v == kPartEdep) {fVars[tmpPCount][countF++] = tmpParticle->Edep();}
    else if (v == kPartDeltaE) {fVars[tmpPCount][countF++] = tmpParticle->DeltaE(); }
    else if (v == kPartPreE) {fVars[tmpPCount][countF++] = tmpParticle->PreE();}
    else if (v == kPartP) {fVars[tmpPCount][countF++] = tmpParticle->P4p()->P();}
    else if (v == kPartTh) {fVars[tmpPCount][countF++] = tmpParticle->P4p()->Theta(); }
    else if (v == kPartPhi) {fVars[tmpPCount][countF++] = tmpParticle->P4p()->Phi();}
    else if (v == kPartVz) {fVars[tmpPCount][countF++] = tmpParticle->Vertex().Z();}
    else if (v == kPartChi2) {fVars[tmpPCount][countF++] = tmpParticle->TrChi2(); }
    else if (v == kPartNPhot) {fVars[tmpPCount][countF++] = tmpParticle->NPhot(); }
    else {cout<<"Warning HS::VarsParticle::AddVarsFromParticle unknown variable"<<endl;exit(1);}
    
  }	
}
void HS::VarsParticle::FillVars(){

  for (UInt_t  i = 0 ; i<fParticlesAdded; ++i){
    AddVarsFromParticle(i);
  }
}
/*
 * Find the particle variable index for this name
 */
Int_t HS::VarsParticle::GetPVarIndex(TString name){
  for(auto const& pvi : fPVarList)
    if(pvi.first==name) return pvi.second;
  
  cout<<"Error HS::VarsParticle::GetPVarIndex "<<name<<" not in list"<<endl;
  exit(1);
}
/**
 * Add a particle and its variables and their types
 *
 */
void HS::VarsParticle::AddParticle(TString name, THSParticle *part, vecNames variables){
  std::cout<<"Adding "<<name<<std::endl;
  // fill vector of pointers
  fParticles.push_back(part);
  // if (types.empty()){
  //       std::cout<<"    Adding all variables as Float_t"<<std::endl;
  //       if (variables.empty()){
  //           if (fDefaultVariables.empty()) {std::cout<<"ERROR: no default variables set"; exit(1);};
  //               types.resize(fDefaultVariables.size(), "F");
  //       }
  //       else{
  //           types.resize(variables.size(), "F");
  //       }
  //   }
    // add particle and its variables
    //if (variables.empty()) AddParticle(name, fDefaultVariables);
    //else{AddParticle(name, variables);}
  AddParticle(name, variables);
}
void HS::VarsParticle::CheckVariable(TString name){
  for(auto const& pvi : fPVarList)
    if(pvi.first==name) return;

  cout<<"Error HS::VarsParticle::CheckVariable "<<name <<"not in PVarList"<<endl;
  exit(1);
}

void HS::VarsParticle::AddParticle(TString name, vecNames variables){

  std::cout<<"    Current number of particles: "<<fParticleNames.size()<<std::endl;
   
    // make sure no prexisting config
    if (fParticleNames.size()!= fParticlesAdded) {fParticleNames = {};};
    // set default variables to empty array
    //if (!fVariableID.empty()) {fVariableID = {};};
    // add name to particle names
    fParticleNames.push_back(name);
    
    // resize to allow for new particle vector to be filled
    fVarNames.resize(fParticlesAdded+1);
    fVars.resize(fParticlesAdded+1);
    fPVarIndex.resize(fParticlesAdded+1);

    std::cout<<" Resized vectors to fill: "<<fVarNames.size()<<", "<<fVars.size()<<std::endl;

    // make vector of particle + variable e.g. ElP for electron momentum
    for (UInt_t i=0 ; i<variables.size(); i++){
      CheckVariable(variables[i]);
      // add to fVarNames and fVars
      fVarNames[fParticlesAdded].push_back(name + variables[i]);
      fVars[fParticlesAdded].push_back(0);
      fPVarIndex[fParticlesAdded].push_back(GetPVarIndex(variables[i]));
    }

    std::cout<<"Added "<<fVars[fParticlesAdded].size()<< " (Float_t) / " <<std::endl;
    fParticlesAdded++;

    std::cout<<"Current particles: ";
    for (auto const& p : fParticleNames) {std::cout<<p<<" ";}
    std::cout<<" "<<std::endl;

}
/*
 *Get the reference for variable name for linking to reader
 */
Float_t* HS::VarsParticle::GetVarRef(TString name){
  for(UInt_t ip=0;ip<fVarNames.size();ip++){
    for(UInt_t iv=0;iv<fVarNames[ip].size();iv++){
      if(fVarNames[ip][iv]==name) return &fVars[ip][iv];
    }
  }  
  return nullptr;
}
/**
 * Remove NaN values from an entry
 *
 */

void HS::VarsParticle::RemoveNaNs(){

    //std::cout<<"Removing NaNs..."<<std::endl;

    for (UInt_t iPar=0; iPar<fParticlesAdded; iPar++) {
        for (UInt_t iVar=0; iVar<fVars[iPar].size(); iVar++) {
            if (!std::isfinite(fVars[iPar][iVar])){
                fVars[iPar][iVar] = 0;
            }
        }
    } 

}

