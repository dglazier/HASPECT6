#ifndef TREEDATAK2_h
#define TREEDATAK2_h 
#include "TreeData.h"

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
  
  
  ClassDef(TreeDataK2,1);
};
#endif