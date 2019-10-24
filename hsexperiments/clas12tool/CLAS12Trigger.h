#ifndef HS_CLAS12TRIGGER_h
#define HS_CLAS12TRIGGER_h

#include <TTree.h>
#include "THSParticle.h"
#include "EventInfo.h"
#include "RunInfo.h"
#include <cmath>
#include <vector>

namespace HS{
  namespace CLAS12{
    class CLAS12Trigger{
      
    public :
      CLAS12Trigger()=default;
      ~CLAS12Trigger()=default;      

      void EventReset();
      Bool_t TrigStatus(Short_t status);
      
      void SetParticles(vector<THSParticle> *parts){fParticles=parts;}
      
      void SetEventInfo(BaseEventInfo* info){fEventInfo=dynamic_cast<HS::CLAS12::EventInfo*>(info);}
      void SetRunInfo(BaseRunInfo* info){fRunInfo=dynamic_cast<HS::CLAS12::RunInfo*>(info);if(fRunInfo->fType)SetSim();}

      void SetSim(){fSTimePeak=124.25;fTimeShiftFT=0;};
      
      void ReadParticles();
      Float_t FTBStartTime();
      Float_t FDBStartTime();

      Float_t StartTime(Float_t ptime); //calculate event start time
      Float_t StartTime(THSParticle* part); //calculate event start time
      Float_t GetStartTime(){return fStartTime;}
      void SetSTimePeak(Float_t tt){fSTimePeak=tt;};
      void SetTimeShiftFT(Float_t tt){fTimeShiftFT=tt;};
      
      void FindTimeOffSetFT(TTree* tree,TString option="goff");
      void FindTimeRFTimePeak(TTree* tree,TString option="goff");
      
      /* Short_t  TrigNSectors(); */
      /* Short_t  TrigNSectorsRoads(); */
      Short_t NFDSectorsHit();
      
      void SubtractStartTime(THSParticle* part); //subtract from HSParticle  
      void SubtractStartTime(THSParticle* part0,THSParticle* part1);
      void SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2);
      void SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3);
      void SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4);
      void SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5);
      void SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6);
      void SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6,THSParticle* part7);
      void SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6,THSParticle* part7,THSParticle* part8);
      void SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6,THSParticle* part7,THSParticle* part8,THSParticle* part9);
      
      Int_t TrigBit(Int_t  k)
      { //borrowed from M.Dugger
      	return (fEventInfo->fTrigBit & (1<<k)) != 0;
      }
      Int_t VTPTrigBit(Int_t  k)
      { 
      	return (fEventInfo->fVTPTrigBit & (1<<k)) != 0;
      }
      HS::CLAS12::EventInfo* EventInfo(){return fEventInfo;}
      HS::CLAS12::RunInfo* RunInfo(){return fRunInfo;}

    private:
      
      vector<Short_t> fEventSectors=std::vector<Short_t>(11,0);
      vector<THSParticle> *fParticles=nullptr;
      
      HS::CLAS12::EventInfo* fEventInfo=nullptr;
      HS::CLAS12::RunInfo* fRunInfo=nullptr;
      
      Float_t fStartTime=0;
      Float_t fSTimePeak=44.125;
      Float_t fTimeShiftFT=44.125-44.1;
      //Float_t fStartTime=124.25; //GEMC
      //Float_t fSTimePeak=124.25; //GEMC
      //Float_t fTimeShiftFT=0; // GEMC
    };
  }//namespace CLAS12
}//namespace HS
inline Float_t HS::CLAS12::CLAS12Trigger::StartTime(HS::THSParticle* part){
  //If FT shift time first
  if(part->CLAS12()->getRegion()==clas12::FT){part->ShiftTime(fTimeShiftFT);return StartTime(part->DeltaTime());}
  //else
  return StartTime(part->DeltaTime());
}

inline Float_t HS::CLAS12::CLAS12Trigger::StartTime(Float_t ptime){
  //supply chosen (e-) particle vertex time
  Float_t rftime=fEventInfo->fRFTime;
  //Find the nearest rf beam bucket
  fStartTime=fSTimePeak-4.0080160*((Int_t)(std::round(((fSTimePeak-(ptime-rftime))/4.0080160))))+rftime;
  return fStartTime;
}
inline Float_t HS::CLAS12::CLAS12Trigger::FDBStartTime(){
 
  return fStartTime=fEventInfo->fStartTime;
}
inline Float_t HS::CLAS12::CLAS12Trigger::FTBStartTime(){
 
  return fStartTime=fEventInfo->fFTBStartTime;
}

inline void  HS::CLAS12::CLAS12Trigger::EventReset(){
for(UInt_t i=0;i<fEventSectors.size();i++)
  fEventSectors[i]=0;
}

Bool_t  HS::CLAS12::CLAS12Trigger::TrigStatus(Short_t status){
//Use the EB status to tell what CAL,TOF fired
if(status==4010) return kFALSE; //No CD TOF
if(status==1000) return kTRUE;  //FT
if(status==4100) return kTRUE;  //CD with TOF
if(status>2090&&status<3000) //FD with TOF
  if(status%100)             //and CAL
    return kTRUE;

return kFALSE; //everything else
}

// number of forward detector sector hits (first 6 sectors)
Short_t HS::CLAS12::CLAS12Trigger::NFDSectorsHit(){
  // all the following come out as zero
  //cout << fEventSectors << endl;
  //cout << std::accumulate(fEventSectors.begin(), fEventSectors.end(), 0) << endl;
  //cout << std::count_if(fEventSectors.begin(), fEventSectors.begin()+6, [](Int_t i){return i > 0;}) << endl;
  return std::count_if(fEventSectors.begin(), fEventSectors.begin()+6, [](Int_t i){return i > 0;});
}


#endif
