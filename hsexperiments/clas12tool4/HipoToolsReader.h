
#ifndef HS_HIPOTOOLSREADER_h
#define HS_HIPOTOOLSREADER_h

#include <iostream>
#include <fstream>

#include "THSParticle.h"
#include "DataManager.h"
#include "EventInfo.h"
#include "RunInfo.h"
#include "reader.h"
#include "clas12reader.h"

namespace HS{
  namespace CLAS12{

    class HipoToolsReader: public DataManager{
      
    public :
      HipoToolsReader();
      virtual ~HipoToolsReader()=default;
      
      Bool_t Init(TString filename,TString name="") final;
      Bool_t ReadEvent(Long64_t entry=0) final;
      void SetEventInfo();
      void SetStartRunInfo();
      void SetEndRunInfo();
      void FillParticles();
      void FillGenerated();
      
      // const hipo::reader* GetHipoReader()const {return &fReader;}
      
    private :
      
      //clas12tools
       unique_ptr<clas12::clas12reader> fEvent;

      //HS data objects
      HS::THSParticle fParticle;
      CLAS12::EventInfo *fEventInfo=nullptr;
      CLAS12::RunInfo *fRunInfo=nullptr;

      Float_t fTotCharge=0;
      Bool_t fRunEnd=kTRUE;
    
    };//	class HipoToolsReader
  }//namespace CLAS12
}//namespace HS
#endif //
