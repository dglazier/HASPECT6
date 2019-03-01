#ifndef TREEDATAPi2_h
#define TREEDATAPi2_h 
#include "TreeData.h"
#include "FiledTree.h"

class TreeDataPi2: public HS::TreeData{
 public:
  //data member for tree branches below here
  Double_t MissMass=0;
  Double_t MissMass2=0;

  Double_t MesonMass=0;
  Double_t DppMass=0;
  Double_t D0Mass=0;
  
  Double_t W=0; 
  Double_t Q2=0;
  Double_t Pol=0;
  Double_t Egamma=0;
  
  Double_t MesonCosTh=0;
  Double_t MesonPhi=0;  
  
  //Function required to set tree branches
  void Branches(HS::ttree_ptr tree) final{
    TreeData::Branches(tree,Class()->GetListOfDataMembers());
  }
  ClassDefOverride(TreeDataPi2,1);
};
#endif