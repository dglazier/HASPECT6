/**
	\class CLAS12Trigger
	
	Class to handle issues related to the CLAS12 experimental trigger
	Includes, 
	
-	Finding offsets between FT and CLAS12

	     e.g.  fTrigger.FindTimeOffSetFT(tree);
        
-	Finding peak position in (e- vertex time) -RFTime (required for RFTime)

             e.g. fTrigger.FindTimeRFTimePeak(tree);
	
-	Finding the current event starttime (RF corrected)

	     e.g. fTrigger.StartTime(&fElectron);
        
-	Correct particle times for starttime

  	     e.g.  fTrigger.SubtractStartTime(&fElectron,&fProton,&fPip,&fPim);
	
-	Returning the number of hits in FT,CD or FD Sectors 
	for use in Simulated trigger
       
	Currently the default fTimeShiftFT and fSTimePeak are set for run 3432
	You will need to change this by hand or run FindTimeOffSetFT,  
	FindTimeRFTimePeak. 
	This class needs extended to make use of THSEventInfo::TrigBit()
	and the trigger configuration for a given CLAS12 run which
	changed regularly throughout the beamtime
*/
#include "CLAS12Trigger.h"
#include <TH1.h>
#include <TSpectrum.h>

using namespace HS;

////////////////////////////////////////////////////////////////////////
///Look for global FT-CLAS12 offset
///This can be run at the start of every new Run to make sure times are aligned
///Input arguemnts are the tree to be analysed and draw option (goff by default)
void CLAS12Trigger::FindTimeOffSetFT(TTree* tree,TString option){
  TH1F* hisFTCLAS12=new TH1F("ftclas12","ftclas12",10000,-500,500);
  tree->Draw("Particles[0].DeltaTime()-Particles.DeltaTime()>>ftclas12","Particles.Detector()<0&&Particles[0].Time()!=0&&Particles.Time()!=Particles[0].Time()&&Particles.Detector()!=10000",option);
  TSpectrum s1(1);
  //use TSpectrum to find time difference peak
  Int_t nfound = s1.Search(hisFTCLAS12,1,"",0.50);
  Double_t *xpeaks=0;
  xpeaks = s1.GetPositionX();
  //Use this as FT time shift
  fTimeShiftFT=xpeaks[0];
  cout<<"CLAS12Trigger::FindTimeOffSetFT Detected FT offset of "<<fTimeShiftFT<<endl;
  if(option==TString("goff"))delete  hisFTCLAS12;
}
////////////////////////////////////////////////////////////////////////
///Look for global CLAS12-RFTime peak in Particles.DeltaTime()-EventInfo.fRFTime
///Spectrum, this is used to align the beam bucket windows
///This can be run at the start of every new Run to make sure times are aligned
///Input arguemnts are the tree to be analysed and draw option (goff by default)
void CLAS12Trigger::FindTimeRFTimePeak(TTree* tree,TString option){
  //Now look for a RF-FDe- time peak to align to
    TH1F* his=new TH1F("peaks","peaks",800,100,180);
  //TH1F* his=new TH1F("peaks","peaks",800,-80,0);
  tree->Draw("Particles.DeltaTime()-EventInfo.fRFTime>>peaks","Particles.PDG()==11",option);
  TSpectrum s20(20);
  Int_t nfound = s20.Search(his,0.4,"",0.50);
  Double_t *xpeaks=0;
  xpeaks = s20.GetPositionX();
  fSTimePeak=xpeaks[0];
  cout<<"CLAS12Trigger::FindTimeRFTimePeak position "<<fSTimePeak<<endl;
  if(option==TString("goff"))delete his;
}
////////////////////////////////////////////////////////////////////////
///subtract the event startime from the given particle
///Should be called after fTrigger.StartTime(&fElectron);
void CLAS12Trigger::SubtractStartTime(THSParticle* part){
  part->ShiftTime(-fStartTime);
}
////////////////////////////////////////////////////////////////////////
///subtract the event startime from the given particle
///Should be called after fTrigger.StartTime(&fElectron);
void CLAS12Trigger::SubtractStartTime(THSParticle* part0,THSParticle* part1){
  Float_t startime=fStartTime;
  part0->ShiftTime(-startime);
  part1->ShiftTime(-startime);
}
////////////////////////////////////////////////////////////////////////
///subtract the event startime from the given particle
///Should be called after fTrigger.StartTime(&fElectron);
void CLAS12Trigger::SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2){
  Float_t startime=fStartTime;
  part0->ShiftTime(-startime);
  part1->ShiftTime(-startime);
  part2->ShiftTime(-startime);
}
////////////////////////////////////////////////////////////////////////
///subtract the event startime from the given particle
///Should be called after fTrigger.StartTime(&fElectron);
void CLAS12Trigger::SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3){
  Float_t startime=fStartTime;
  part0->ShiftTime(-startime);
  part1->ShiftTime(-startime);
  part2->ShiftTime(-startime);
  part3->ShiftTime(-startime);
}
////////////////////////////////////////////////////////////////////////
///subtract the event startime from the given particle
///Should be called after fTrigger.StartTime(&fElectron);
void CLAS12Trigger::SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4){
  Float_t startime=fStartTime;
  part0->ShiftTime(-startime);
  part1->ShiftTime(-startime);
  part2->ShiftTime(-startime);
  part3->ShiftTime(-startime);
  part4->ShiftTime(-startime);
}
////////////////////////////////////////////////////////////////////////
///subtract the event startime from the given particle
///Should be called after fTrigger.StartTime(&fElectron);
void CLAS12Trigger::SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5){
  Float_t startime=fStartTime;
  part0->ShiftTime(-startime);
  part1->ShiftTime(-startime);
  part2->ShiftTime(-startime);
  part3->ShiftTime(-startime);
  part4->ShiftTime(-startime);
  part5->ShiftTime(-startime);
}
////////////////////////////////////////////////////////////////////////
///subtract the event startime from the given particle
///Should be called after fTrigger.StartTime(&fElectron);
void CLAS12Trigger::SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6){
  Float_t startime=fStartTime;
  part0->ShiftTime(-startime);
  part1->ShiftTime(-startime);
  part2->ShiftTime(-startime);
  part3->ShiftTime(-startime);
  part4->ShiftTime(-startime);
  part5->ShiftTime(-startime);
  part6->ShiftTime(-startime);
}
////////////////////////////////////////////////////////////////////////
///subtract the event startime from the given particle
///Should be called after fTrigger.StartTime(&fElectron);
void CLAS12Trigger::SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6,THSParticle* part7){
  Float_t startime=fStartTime;
  part0->ShiftTime(-startime);
  part1->ShiftTime(-startime);
  part2->ShiftTime(-startime);
  part3->ShiftTime(-startime);
  part4->ShiftTime(-startime);
  part5->ShiftTime(-startime);
  part6->ShiftTime(-startime);
  part7->ShiftTime(-startime);
}
////////////////////////////////////////////////////////////////////////
///subtract the event startime from the given particle
///Should be called after fTrigger.StartTime(&fElectron);
void CLAS12Trigger::SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6,THSParticle* part7,THSParticle* part8){
  Float_t startime=fStartTime;
  part0->ShiftTime(-startime);
  part1->ShiftTime(-startime);
  part2->ShiftTime(-startime);
  part3->ShiftTime(-startime);
  part4->ShiftTime(-startime);
  part5->ShiftTime(-startime);
  part6->ShiftTime(-startime);
  part7->ShiftTime(-startime);
  part8->ShiftTime(-startime);
}
////////////////////////////////////////////////////////////////////////
///subtract the event startime from the given particle
///Should be called after fTrigger.StartTime(&fElectron);
void CLAS12Trigger::SubtractStartTime(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6,THSParticle* part7,THSParticle* part8,THSParticle* part9){
  Float_t startime=fStartTime;
  part0->ShiftTime(-startime);
  part1->ShiftTime(-startime);
  part2->ShiftTime(-startime);
  part3->ShiftTime(-startime);
  part4->ShiftTime(-startime);
  part5->ShiftTime(-startime);
  part6->ShiftTime(-startime);
  part7->ShiftTime(-startime);
  part8->ShiftTime(-startime);
  part9->ShiftTime(-startime);
}
