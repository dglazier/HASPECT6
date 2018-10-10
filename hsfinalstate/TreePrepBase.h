// Author: Michael Williams 2018 
// Modified: Derek Glazier 2018

/**********************************************************************************
* Project: HSFinalState && HSMVA                                                              *
* Package:                                                                       *
* Class  : TreePrep                                                            *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*
*                                                                                *
**********************************************************************************/
#ifndef HSFS_TREEPREPBASE_h
#define HSFS_TREEPREPBASE_h

#include "FiledTree.h"

//using namespace HS;

namespace HS{

  using vecWeights= vector<Float_t>;

  class TreePrepBase : public FiledTree {
    
  public:
    TreePrepBase(TString tname,TString fname):FiledTree(tname,fname) {};
    TreePrepBase(){};
    virtual ~TreePrepBase(){}
 
    virtual void SetBranches()=0; //branches of tree to variabels in derived class
    virtual void Fill()=0;    //Fill fVars data vector before TTree::Fill
//virtual Float_t* GetVarRef(TString name) =0; //For linking to reader
    virtual void SetWeights(vecWeights wgts)=0;
    virtual Bool_t IsEnough()=0; //Do we have enough events? 

    void SetN(Long64_t nn){fNRequested=nn;}
  
    Long64_t fNRequested=-1;

   
 };//class TreePrepBase

};//namespace HSFinalState

#endif //
