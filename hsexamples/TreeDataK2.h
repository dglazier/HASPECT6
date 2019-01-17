#ifndef TREEDATAK2_h
#define TREEDATAK2_h 
#include "TreeData.h"
#include "FiledTree.h"

class TreeDataK2: public HS::TreeData{
 public:
  //data member for tree branches below here
  Double_t MissMass=0;
  Double_t MissMass2=0;
  
  Double_t MesonMass=0;
  Double_t HyperonMass=0;
  
  Double_t MesonCosTh=0;
  Double_t MesonPhi=0;
  Double_t HyperonCosTh=0;
  Double_t HyperonPhi=0;
  Double_t Eg=0;
  Double_t t=0;
  
  Double_t HelCosTh=0;
  Double_t HelPhi=0;
  
  Double_t ProtP=0;
  Double_t ProtTh=0;
  Double_t ProtTime=0;
  Double_t KpP=0;
  Double_t KpTh=0;
  Double_t KpTime=0;
  Double_t KmP=0;
  Double_t KmTh=0;
  Double_t KmTime=0;
  Double_t BeamTime=0;

  Double_t Pol=0;
  Int_t PolState=0;
  
    //Function required to set tree branches
  void Branches(HS::ttree_ptr tree) final{
    TreeData::Branches(tree,Class()->GetListOfDataMembers());
  }

  ClassDef(TreeDataK2,1);
};
#endif