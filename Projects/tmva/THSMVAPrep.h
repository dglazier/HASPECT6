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

#ifndef THSMVAPREP_h
#define THSMVAPREP_h

#include <TTree.h>
#include <TString.h>
#include <TFile.h>
#include <THSParticle.h>

#include "THSMVA.h"

class THSMVAPrep : public THSMVA {

    public :
        THSMVAPrep();
        virtual ~THSMVAPrep();
  
        THSMVAPrep(TString name) : THSMVA(name){};
    protected :
        // TTree to fill
        TTree* fBaseTree=nullptr;//!

        Int_t fTmpInt=0;
        Int_t fCountF = 0;
        Int_t fCountI = 0;
        Int_t fN = 0;

        UInt_t fNVarsF = 0;
        UInt_t fNVarsI = 0;

    public:

        void SetTree(TTree* tree) {fBaseTree = tree;};
        void SetBranches();
        void RemoveNaNs();
        void AddVarsFromParticle(THSParticle* tmpParticle, Int_t tmpPCount);

  ClassDef(THSMVAPrep,1) //class THSParticle

};

#endif //
