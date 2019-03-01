//Datareader class for converting Lund format txt files
//into THSParticles
#ifndef HS_HIPODST_h
#define HS_HIPODST_h

#include "HipoReader.h"

namespace HS{
  namespace CLAS12{
    class HipoDST: public HipoReader{
      
    public :
 
      Bool_t ReadEvent(Long64_t entry=0) override;
      void InitOutput(TString filename) override;
      Bool_t Init(TString filename,TString name) override;
      
    private :
      
      
      Float_t fCharge=0;
      Float_t fTotCharge=0;
      Short_t fHelicity=0;
      Int_t fNScalerReads=0;
      
      Int_t fTrigBits[sizeof(int) * 8];
      
      Float_t fCurFactor=1; //attenuation factor due to beam blocker
      //@(10.7)=9.808%  CLAS-NOTE 2018 - 003
      //@(6.4) =16.283% CLAS-NOTE 2018 - 004
      
      THipoBank* fRawScalBank=nullptr;
      
      //items in banks
      THipoItemL* fRunTrig=nullptr;
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
      
      
    };
  }//namespace CLAS12
}//namepsace HS

#endif //ifdef HS_HIPODST
