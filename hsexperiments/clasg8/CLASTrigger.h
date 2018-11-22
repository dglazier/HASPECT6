#ifndef CLASTRIGGER_h
#define CLASTRIGGER_h

#include <TTree.h>
#include "THSParticle.h"
#include "EventInfo.h"
#include "RunInfo.h"
#include <cmath>
#include <vector>

namespace HS{
  namespace CLASG8{
  
    class CLASTrigger{

    public :
      CLASTrigger()=default;
      ~CLASTrigger()=default;
    
    
    protected:
      vector<Short_t> fEventSectors=std::vector<Short_t>(9,0);
      vector<THSParticle> *fParticles=nullptr;
    
      EventInfo* fEventInfo=nullptr;
      RunInfo* fRunInfo=nullptr;
    
      Float_t fStartTime=0;
      Float_t fIsSim=kFALSE;
    
    public:
      Short_t Sector(Int_t det);
      Short_t HitsInSector(Int_t sect){return fEventSectors[sect];}
      Short_t NFDSectorsHit();
      void EventReset();
      Bool_t TrigStatus(Short_t status);
    
      void SetParticles(vector<THSParticle> *parts){fParticles=parts;}
      void SetEventInfo(BaseEventInfo* info){fEventInfo=dynamic_cast<HS::EventInfo*>(info);}
      void SetRunInfo(BaseRunInfo* info){fRunInfo=dynamic_cast<HS::RunInfo*>(info);if(fRunInfo->fType)SetSim();}
      void SetSim(){if(fRunInfo->fType==1)fIsSim=kTRUE;else fIsSim=kFALSE;};
      void SetSim(Bool_t sim){fIsSim=sim;};
      Bool_t IsSim(){return (Bool_t)(fRunInfo->fType);};

      void SetStartTime(){
	if(!fRunInfo->fType) fStartTime=fEventInfo->fCJSTTime; 
	else  fStartTime=0;
      }
    
      void ReadParticles();
    
      Short_t  HitsInFD();
      Short_t  HitsInTagger(){return fEventSectors[8];}

    
      void SubtractStartTimeBeam(THSParticle* part,THSParticle* beam); //subtract from HSParticle  
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
    
    };
  }//namespace CLASG8
}//namespace HS

inline Short_t HS::CLASG8::CLASTrigger::Sector(Int_t det){
  //return sector of particle and increment counter
  if(det<0) {fEventSectors[8]++;return 0;} //Tagger
  fEventSectors[det]++;
  return det;
}
inline Short_t  HS::CLASG8::CLASTrigger::HitsInFD(){
  return fEventSectors[1]+			\
    fEventSectors[2]+				\
    fEventSectors[3]+				\
    fEventSectors[4]+				\
    fEventSectors[5]+				\
    fEventSectors[6];
}
inline Short_t  HS::CLASG8::CLASTrigger::NFDSectorsHit(){
  Short_t nsect=0;
  for(Int_t i=1;i<7;i++) //only the 6 FD sectors
    nsect+=(fEventSectors[i]!=0);
  return nsect;
}
inline void  HS::CLASG8::CLASTrigger::EventReset(){
for(UInt_t i=0;i<fEventSectors.size();i++)
  fEventSectors[i]=0;
}
Bool_t  HS::CLASG8::CLASTrigger::TrigStatus(Short_t status){
//Use the EB status to tell what CAL,TOF fired

return kTRUE; //everything else
}

void HS::CLASG8::CLASTrigger::ReadParticles(){
EventReset();
for(UInt_t i=0;i<fParticles->size();i++)
  if(TrigStatus(fParticles->at(i).Status()))Sector(fParticles->at(i).Detector());
}

#endif
