
#ifndef HS_HIPOTOOLSREADER_h
#define HS_HIPOTOOLSREADER_h

#include <iostream>
#include <fstream>

#include "THSParticle.h"
#include "DataManager.h"
#include "EventInfo.h"
#include "RunInfo.h"
#include "THipo.h"

namespace HS{
  namespace CLAS12{

    class HipoToolsReader: public DataManager{
      
    public :
      HipoToolsReader();
      virtual ~HipoToolsReader(){if(fHipo) delete fHipo;};
      
      Bool_t Init(TString filename,TString name="") override;
      Bool_t ReadEvent(Long64_t entry=0) override;
      void CloseReadTree() override;
      void InitOutput(TString filename) override;
      void CloseOutput() override;
      
      Int_t GetRunNumber(TString filen);
      void SetCombineFiles(Bool_t setf=kTRUE){fCombineFiles=kTRUE;};
      
    protected :
      
    
      clas12::mesonex_event fEvent;

      Bool_t fCombineFiles=kFALSE;
      Int_t fRunNumber=0;
      
      CLAS12::EventInfo *fEventInfo=nullptr;
      CLAS12::RunInfo *fRunInfo=nullptr;
    
    
    };//	class HipoToolsReader
  }//namespace CLAS12
}//namespace HS
#endif //
