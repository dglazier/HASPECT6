////////////////////////////////////////////////////////////////
///
///Class:               TreeParticleData
///Description:
///         Class to hold ParticleData for each topology
///         Each detected particle in the topolgy adds a
///         ParticleData object into fPData vector
///         ParticleDataManager holds a vector of TreeParticleData
///         with an entry for eah topology
///         In addtion a signal background flag is set based on
///         the fCorrect variable from the final state
///         This is useful for defining training data for MVA

#ifndef HSFS_TREEPARTICLEDATA_h
#define HSFS_TREEPARTICLEDATA_h

#include "THSParticle.h"
#include "FinalState.h"
#include "FiledTree.h"
#include "ParticleData.h"

namespace HS{

  using vecNames=std::vector<TString> ;
  using vecPartVars =std::vector<std::vector<TString>>;
  using vecWeights= vector<Float_t>;
 
  
  class TreeParticleData {

  public:
  TreeParticleData(TString tname,TString fname):fTree(FiledTree::Recreate(tname,fname)) {};
    TreeParticleData()=default;
    TreeParticleData(const TreeParticleData&)=default;
    TreeParticleData(TreeParticleData&&)=default;
    virtual ~TreeParticleData(){
      //  delete fTree;
    }
 
    void SaveTree(){ fTree.reset(); }
    
    void SetBranches();
    
    void Fill(){
         if(fFinalState->IsCorrect()){
	fSigWeight=1;fBckWeight=0;}
      else{
	fSigWeight=0;fBckWeight=1;}

      fUID=fFinalState->GetUID();
      FillVars();
      fTree->Fill();
      //Count the number of non-zero signal weights
      if(fNSig!=-1) fNSig+=(fSigWeight);
      if(fNBck!=-1) fNBck+=(fBckWeight);
    };
    
    //Float_t* GetVarRef(TString name) override;
    void SetWeights(vecWeights wgts){
      fSigWeight =wgts[0];fBckWeight=wgts[1];
    }
    
    Bool_t IsEnough(){
      if(fNRequested<0) return kFALSE;
      if(fNSig>fNRequested&&fNBck>fNRequested) return kTRUE;
      return kFALSE;
    } 

    //Functions for TreeParticleData
    void AddSigBck();
    void SetSigBck(Float_t wgts,Float_t wgtb){fSigWeight =wgts;fBckWeight=wgtb;}
    Long64_t GetNSig(){return fNSig;}
    Long64_t GetNBck(){return fNBck;}
    void SetN(Long64_t nn){fNRequested=nn;}
 
    void SetFinalState(FinalState* fs){fFinalState=fs;}

    void AddParticle(TString name, THSParticle *part, vecNames variables={});
    void FillVars() ;

    ttree_ptr GetTree(){return fTree->Tree();}
    void AddFinal(); //Add FinalState::TreeData branches
 
  private:
    
    Float_t fSigWeight=1;    
    Float_t fBckWeight=1;    
    Long64_t fNSig=-1;
    Long64_t fNBck=-1;
    Long64_t fNRequested=-1;
    Long64_t fUID=-1;

    //    FiledTree* fTree=nullptr;
    filed_uptr fTree;
    FinalState* fFinalState=nullptr;

  protected:
    vector<HS::ParticleData> fPData;
    vecPartVars fPVars;
     
  };//class TreeParticleData

};//namespace HSFinalState

#endif //
