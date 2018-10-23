//Datareader class for interacing to CLAS DST and BOS files with RootBeer
//into THSParticles
#ifndef THSROOTBEER_h
#define THSROOTBEER_h

#include <iostream>

#include "TRootBeer.h"
#include "THSParticle.h"
#include "DataManager.h"

class THSRootBeer: public HS::DataManager{

 public :
  THSRootBeer(){};
  THSRootBeer(TString banks);
  ~THSRootBeer(){};

  virtual Bool_t Init(TString filename,TString name="");
  virtual Bool_t ReadEvent(Long64_t entry=0);
  virtual Bool_t RBEvent(Long64_t entry=0);
  virtual void CloseReadTree();

 protected :
  TRootBeer* fRootBeer=nullptr;
  Int_t fRun_number;
  TString fMyBanks;
  Bool_t fIsSim=kFALSE;

 public :
  virtual void MakeDetected();
  virtual void MakeParticle(Int_t ip);
 
  void SetSim() {fIsSim=kTRUE;}
 
};

#endif //ifdef THSLUNDREADER
