//Datareader class for converting Lund format txt files
//into THSParticles
#ifndef HS_HIPOTRIGGER_h
#define HS_HIPOTRIGGER_h

#include "HipoReader.h"
#include <bitset>

namespace HS{
  namespace CLAS12{
    class HipoTrigger: public HipoReader{
      
    public :
      //virtual ~HipoTrigger()=default;
      
      Bool_t ReadEvent(Long64_t entry=0) override;
      void InitOutput(TString filename) override;
      Bool_t Init(TString filename,TString name) override;
      
      
      
      void  RawScaler();
      Int_t makeVTPTriggers();
      void decodeVTPTrigger(Int_t word1vtp, Int_t word2vtp);
      void addVTPTriggerToEvent(Long_t pattern);
      
    private :
      
      
      Float_t fCharge=0;
      Float_t fTotCharge=0;
      Short_t fHelicity=0;
      Int_t fNScalerReads=0;
      
      //Int_t fTrigBits[sizeof(int) * 8];
      //vector<Long_t> fVTPTriggers;
      std::bitset<32> fVTPBitSet;
      
      
      Float_t fCurFactor=1; //attenuation factor due to beam blocker
      //@(10.7)=9.808%  CLAS-NOTE 2018 - 003
      //@(6.4) =16.283% CLAS-NOTE 2018 - 004
      
      THipoBank* fRawScalBank=nullptr;
      THipoBank* fVTPTrigBank=nullptr;
      
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
      THipoItemF* fRecEvRFTime=nullptr;
      THipoItemF* fRecEvPTIME=nullptr;
      
      THipoItemS* fRawScalChan=nullptr;; 
      THipoItemB* fRawScalSlot=nullptr;;
      THipoItemI* fRawScalVal=nullptr;;
      THipoItemB* fRawScalHel=nullptr;;
      
      THipoItemB* fVTPDBCrate=nullptr;
      THipoItemI* fVTPDBWord=nullptr;
      
    };
  }//namespace CLAS12
}//namespace HS
#endif //ifdef HS_HIPOTRIGGER
