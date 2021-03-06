//Datareader class for converting Lund format txt files
//into THSParticles
#ifndef THSHIPOTRIGGER_h
#define THSHIPOTRIGGER_h

#include "THSHipoReader.h"

class THSHipoTrigger: public THSHipoReader{

 public :
  THSHipoTrigger();
  virtual ~THSHipoTrigger(){};

  //  virtual Bool_t Init(TString filename,TString name="");
  virtual Bool_t ReadEvent(Long64_t entry=0);
  virtual void InitOutput(TString filename);
  virtual Bool_t Init(TString filename,TString name);
  virtual void PostWrite();

  
  void SetSoftFTTrig(Int_t trig){fSoftFTTrig=trig;}
  Int_t GetSoftFTTrig(){return fSoftFTTrig;}
  void SetTrigPeriod(Int_t trig){fTrigPeriod=trig;}
  Int_t GetTrigPeriod(){return fTrigPeriod;}
  void SetUseUnGated(){fUseUnGated=kTRUE;}
  void SetCurFactor(Float_t val){fCurFactor=val;}
  
  void  RawScaler();
 protected :

  //banks
  //THipoBank* fRunConBank=nullptr;
  //  THipoBank* fRecEvBank=nullptr;
  THipoBank* fRawScalBank=nullptr;
    

  //items in banks
  THipoItemL* fRunTrig=nullptr;
  //THipoItem* fEvSTTime=nullptr;
  THipoItemI* fRecEvNRun=nullptr;
  THipoItemI* fRecEvNEVENT=nullptr;
  THipoItemB* fRecEvTYPE=nullptr;
  THipoItemL* fRecEvTRG=nullptr;
  THipoItemB* fRecEvHelic=nullptr;
  THipoItemF* fRecEvEVNTime=nullptr;
  THipoItemF* fRecEvBCG=nullptr;
  THipoItemD* fRecEvLT=nullptr;
  //  THipoItem* fRecEvSTTime=nullptr;
  THipoItemF* fRecEvRFTime=nullptr;
  THipoItemF* fRecEvPTIME=nullptr;

  THipoItemS* fRawScalChan=nullptr;; 
  THipoItemB* fRawScalSlot=nullptr;;
  THipoItemI* fRawScalVal=nullptr;;
  THipoItemB* fRawScalHel=nullptr;;
  
  
   //Trigger variables
  Int_t fSoftFTTrig=0;
  Int_t fTrigPeriod=0;
  Long_t fTrigFT=0; 
 

  Bool_t fUseUnGated=kFALSE; //temp fix for wrong DAQ scalers
  
  Int_t fNRun=0;//Run Number
  Int_t fNEvent=0;;//Event Number
  Float_t fEventTime=0;;//Event Time
  Int_t fType=0;;//Event Type (Data or MC)
  Int_t fTrig=0;;//Trigger Type (CLAS12_e-, FT_CLAS12_h,CLAS12_H,...) + Prescale Factor for that Trigger"}
 Float_t fBCG=0;;//Faraday Cup Gated (Coulomb)
  Float_t fLT=0;;//Clock
  Float_t fSTTime=0;;//Event Start Time (ns)
  Float_t fRFTime=0;;//RF Time (ns)
  Int_t fHelic=0;;//Helicity of Event
  Float_t fPTime=0;;//Event Processing Time (UNIX Time = seconds)
  
  Float_t fCharge=0;
  Float_t fTotCharge=0;
  Short_t fHelicity=0;
  Int_t fNScalerReads=0;
  
  Int_t fTrigBits[sizeof(int) * 8];

  Float_t fCurFactor=1; //attenuation factor due to beam blocker
                             //@(10.7)=9.808%  CLAS-NOTE 2018 - 003
                             //@(6.4) =16.283% CLAS-NOTE 2018 - 004
  
  // void CreateBitPattern(long val);
 public :
  
 
};

#endif //ifdef THSHIPOTRIGGER
