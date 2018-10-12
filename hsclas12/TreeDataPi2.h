#ifndef TREEDATAPi2_h
#define TREEDATAPi2_h 
#include "TreeData.h"

class TreeDataPi2: public HS::TreeData{
 public:
  //data member for tree branches below here
  Double_t MissMass=0;
  Double_t MissMass2=0;
  
  ClassDef(TreeDataPi2,1);
};
#endif