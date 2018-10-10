// Author: Michael Williams 2018 
// Modified: Derek Glazier 2018

/**********************************************************************************
* Project: HSFinalState 			                                 *
* Package:                                                                      *
* Class  : TreePrepParticle                                                            *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*     Tree in THSFinalState                                                      *
*     Given a THSParticle it will create default branches                        *
*     from datamembers of the THSParticle class                                  *
*     For each combitorial event it will then fill the tree                      *
*                                                                                *
**********************************************************************************/
#ifndef HSFS_VARSPARTICLE_h
#define HSFS_VARSPARTICLE_h

#include "THSParticle.h"
//#include "TreePrepBase.h"

namespace HS{

  enum EVarType{kPartP,kPartTh,kPartPhi,kPartVz,kPartTime,kPartEdep,kPartDeltaE,kPartPreE,kPartChi2,kPartNPhot};

  using vecNames=std::vector<TString> ;

  //Class to connect HSParticle Object to variables that can be
  //Added to trees, used in MVA, ...

  class VarsParticle  {

  public:
    //    VarsParticle(TString tname,TString fname);
    VarsParticle(){};
    virtual ~VarsParticle()=default;
 
    void FillVars();    //Fill fVars data vector before TTree::Fill
    Float_t* GetVarRef(TString name); //For linking to reader
 
    THSParticle *GetParticle(Int_t ii){return fParticles[ii];}
    void SetParticle(Int_t ii,THSParticle* part){fParticles[ii]=part;}
    void AddParticle(TString name, THSParticle *part, vecNames variables={});
    void AddParticle(TString name, vecNames variables);

    vecNames GetDefaultVariables(){return fDefaultVariables;}
    void SetDefaultVariables(vecNames variables){fDefaultVariables=variables;};

    virtual void AddVarsFromParticle(Int_t tmpPCount);//may want to override this
    Int_t GetPVarIndex(TString name);
    void CheckVariable(TString name);

    void RemoveNaNs();
 
    std::vector<vecNames>* VarNames(){return &fVarNames;}
    std::vector<vecNames> fVarNames;     // variable names for each particle name in vecNames
 
    std::vector<std::vector<Float_t>> fVars; // Float_t type variables for tree

  private:
  
  
    vector<THSParticle * > fParticles;   //vector of particles to get data from
   
    vecNames fParticleNames; //Names of particles to be included
    std::vector<std::vector<Int_t>> fPVarIndex; //Index to particle variable function

    vecNames fDefaultVariables;
    
    UInt_t fParticlesAdded = 0;
 
    const std::vector< std::pair< TString , Int_t > > fPVarList={{"P",kPartP},{"Th",kPartTh},{"Phi",kPartPhi},{"Vz",kPartVz},{"Time",kPartTime},{"Edep",kPartEdep},{"DeltaE",kPartDeltaE},{"PreE",kPartPreE},{"Chi2",kPartChi2},{"NPhot",kPartNPhot}};

  };//class VarsParticle

};//namespace HSFinalState

#endif //
