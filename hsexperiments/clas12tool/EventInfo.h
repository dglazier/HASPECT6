//Information required 1 time per event
//CLAS12 based info
#ifndef HS_CLAS12_EVENTINFO_h
#define HS_CLAS12_EVENTINFO_h

#include "BaseEventInfo.h"


namespace HS{
  namespace CLAS12{

    class EventInfo : public BaseEventInfo{

    public :
      EventInfo()=default;
      virtual ~EventInfo()=default;
  
      Long_t fVTPTrigBit=0; //clas12 vtp trigger bit
      Long_t fTrigBit=0; //clas12 trigger bit
      Float_t fStartTime=0;//COATJAVA defined starttime
      Float_t fFTBStartTime=0;//COATJAVA defined starttime
      Float_t fRFTime=0;//RF Time (ns)
      Float_t fBeamPol=0; //helicity polarisation of beam
      Float_t fTarPol=0; //!helicity polarisation of beam
      Int_t fNEvent=0;//Event Number
      Short_t fBeamHel=0; //helcity direction of beam
      Short_t fTarPolDir=0; //!helcity direction of beam
      
      
    public:
      /* void SetTrigBit(Long_t trig){fTrigBit=trig;} */
      /* Float_t CJStartTime(){return fCJSTTime;} */
      /* void SetCJStartTime(Float_t st){fCJSTTime=st;} */
      /* Float_t RFTime(){return fRFTime;} */
      /* void SetRFTime(Float_t st){fRFTime=st;} */
      /* Int_t NEvent(){return fNEvent;} */
      /* void SetNEvent(Int_t st){fNEvent=st;} */
      /* Short_t BeamHel(){return fBeamHel;} */
      /* void SetBeamHel(Short_t st){fBeamHel=st;} */
      /* void SetTarPolDir(Short_t st){fTarPolDir=st;} */
      /* Short_t TarPolDir(){return fTarPolDir;} */
      /* Float_t BeamPol(){return fBeamPol;} */
      /* void SetBeamPol(Float_t st){fBeamPol=st;} */
      /* Float_t TarPol(){return fTarPol;} */
      /* void SetTarPol(Float_t st){fTarPol=st;} */
      
      
         
    };
  } //namespace CLAS12
}//namespace HS
  
#endif //
