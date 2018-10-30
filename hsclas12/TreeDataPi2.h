#ifndef TREEDATAPi2_h
#define TREEDATAPi2_h 
#include "TreeData.h"

class TreeDataPi2: public HS::TreeData{
 public:
  //data member for tree branches below here
  Double_t MissMass=0;
  Double_t MissMass2=0;
  
  Double_t TrigNSector=0;
  Double_t TrigNSectorRoads=0;

  Double_t MesonMass=0;
  Double_t DppMass=0;
  Double_t D0Mass=0;
  
  Double_t W=0; 
  Double_t Q2=0;
  Double_t Pol=0;
  Double_t Egamma=0;
  
  Double_t MesonCosTh=0;
  Double_t MesonPhi=0;  
  
  Double_t ElTh=0;
  Double_t ElP=0;
  Double_t ElTime=0;
  Double_t ProtTh=0;
  Double_t ProtP=0;
  Double_t ProtTime=0;
  Double_t PipTh=0;
  Double_t PipP=0;
  Double_t PipTime=0;
  Double_t PimTh=0;
  Double_t PimP=0;
  Double_t PimTime=0;


  ClassDef(TreeDataPi2,1);
};
#endif