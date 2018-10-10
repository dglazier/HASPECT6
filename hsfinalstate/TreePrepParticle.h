// Author: Michael Williams 2018 
// Modified: Derek Glazier 2018

/**********************************************************************************
* Project: HSFinalState 			                                 *
* Package:                                                                      *
* Class  : TreePrepParticle                                                            *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*     Tree in FinalState                                                      *
*     Given a THSParticle it will create default branches                        *
*     from datamembers of the THSParticle class                                  *
*     For each combitorial event it will then fill the tree                      *
*                                                                                *
**********************************************************************************/
#ifndef HSFS_TREEPREPPARTICLE_h
#define HSFS_TREEPREPPARTICLE_h

#include "THSParticle.h"
#include "FinalState.h"
#include "TreePrepBase.h"
#include "VarsParticle.h"

namespace HS{


  class TreePrepParticle : public TreePrepBase, public VarsParticle {

  public:
    TreePrepParticle(TString tname,TString fname):TreePrepBase(tname,fname){};
    TreePrepParticle(){};
    virtual ~TreePrepParticle()=default;
 
   //derived classes from TreePrepBase
    void SetBranches() override;
    void Fill() override {  
      if(fFinalState->IsCorrect()){
	fSigWeight=1;fBckWeight=0;}
      else{
	fSigWeight=0;fBckWeight=1;}
      VarsParticle::FillVars();
      TreePrepBase::Tree()->Fill();
      //Count the number of non-zero signal weights
      if(fNSig!=-1) fNSig+=(fSigWeight);
      if(fNBck!=-1) fNBck+=(fBckWeight);

    };

    //Float_t* GetVarRef(TString name) override;
    void SetWeights(vecWeights wgts) override{fSigWeight =wgts[0];fBckWeight=wgts[1];}
    Bool_t IsEnough() override{
      //      cout<<fNRequested<<" "<<fNSig<<" "<<fNBck<<endl;
      if(fNRequested<0) return kFALSE;
      if(fNSig>fNRequested&&fNBck>fNRequested) return kTRUE;
      return kFALSE;
    } 
 
    void AddSigBck();
    void SetSigBck(Float_t wgts,Float_t wgtb){fSigWeight =wgts;fBckWeight=wgtb;}
    Long64_t GetNSig(){return fNSig;}
    Long64_t GetNBck(){return fNBck;}
  
    void SetFinalState(FinalState* fs){fFinalState=fs;}
  private:
    Float_t fSigWeight;    
    Float_t fBckWeight;    
    Long64_t fNSig=-1;
    Long64_t fNBck=-1;
 
    FinalState* fFinalState=nullptr;
  };//class TreePrepParticle

};//namespace HSFinalState

#endif //
