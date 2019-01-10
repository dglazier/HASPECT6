#ifndef TREEDATAXXX_h
#define TREEDATAXXX_h 
#include "TreeData.h"
#include "FiledTree.h"

class TreeDataXXX: public HS::TreeData{
 public:
  //data member for tree branches below here
  Double_t MissMass=0;
  Double_t MissMass2=0;


  //Function required to set tree branches
  void Branches(HS::ttree_ptr tree) final{
    TreeData::Branches(tree,Class()->GetListOfDataMembers());
  }
  ClassDefOverride(TreeDataXXX,1);
};
#endif
