/**
	\class HipoTrigger
	
	Class to fill once per run THSRunInfo and 
	once per event THSEventInfo from hipo files.
	
	Inherits from HipoReader which sorts the THSParticle vector
	for the event tracks.

	Mainly uses REC::Event

	This class uses the stand-alone THipo library to interface
	to the values in the banks

*/
#include "HipoTrigger.h"

using namespace HS;


/////////////////////////////////////////////////////////////
/// Configure the REC::Event and RAW::Scaler banks
/// Additional items may be added in a similar fashion
Bool_t  CLAS12::HipoTrigger::Init(TString filename,TString name){

  if(!fRawScalBank){
    //Add the trigger banks to those to be configured
    Info("HipoTrigger","Opened file");
    fHipo->ConfigOnlyBank("RAW::scaler");
    fHipo->ConfigOnlyBank("RAW::vtp");
  }
   CLAS12::HipoReader::Init(filename,name);
  
  if(!fRecEvNRun){
    fRecEvNRun=dynamic_cast<THipoItemI*>(fEvBank->GetItem("NRUN"));
    fRecEvNEVENT=dynamic_cast<THipoItemI*>(fEvBank->GetItem("NEVENT"));
    fRecEvTYPE=dynamic_cast<THipoItemB*>(fEvBank->GetItem("TYPE"));
    fRecEvTRG=dynamic_cast<THipoItemL*>(fEvBank->GetItem("TRG"));
    fRecEvHelic=dynamic_cast<THipoItemB*>(fEvBank->GetItem("Helic"));
    fRecEvRFTime=dynamic_cast<THipoItemF*>(fEvBank->GetItem("RFTime"));
    fRecEvBCG=dynamic_cast<THipoItemF*>(fEvBank->GetItem("BCG"));    
  }
  fRawScalBank=fHipo->GetBank("RAW::scaler");
  
  fRawScalChan=dynamic_cast<THipoItemS*>(fRawScalBank->GetItem("channel")); 
  fRawScalSlot=dynamic_cast<THipoItemB*>(fRawScalBank->GetItem("slot"));
  fRawScalVal=dynamic_cast<THipoItemI*>(fRawScalBank->GetItem("value"));
  fRawScalHel=dynamic_cast<THipoItemB*>(fRawScalBank->GetItem("helicity"));
  
  fVTPTrigBank=fHipo->GetBank("RAW::vtp");
  fVTPDBCrate=dynamic_cast<THipoItemB*>(fVTPTrigBank->GetItem("crate"));
  fVTPDBWord=dynamic_cast<THipoItemI*>(fVTPTrigBank->GetItem("word"));

  fCharge=0;
  // fHelicity=-1;
  fTotCharge=0;
  fNScalerReads=0;
  return kTRUE;
}

void  CLAS12::HipoTrigger::InitOutput(TString filename){
  DataManager::InitOutput(filename);
}

/////////////////////////////////////////////////////////
/// Read the event from THipo.
/// Write RunInfo at the end of file (when the gated charge is known).
/// Call HipoReader::ReadEvent to fill event THSParticle vector.
/// Fill the EventInfo from REC::Event.
Bool_t  CLAS12::HipoTrigger::ReadEvent(Long64_t entry){

  //cout<<"HipoTrigger::ReadEvent("<<endl;    

  //Note include an extra fill in case there is an extra scaler current
  if(!fHipo->NextEvent()) {
    //End of file write the total current
    if(fRunTree){
      fEvBank->SetEntry(0);
      fRunInfo->fNRun=(fRecEvNRun->Val());
      //fRunInfo->SetType(fRecEvTYPE->Val());
      if(fAddGenerated)fRunInfo->fType=(1);
      else fRunInfo->fType=(0);
      fRunInfo->fTotCharge=(fTotCharge);
      fRunInfo->fMeanCurrent=(fTotCharge/fNScalerReads/0.033);
    }
    cout<<"HipoTrigger::ReadEvent total charge for this file "<<fTotCharge<<endl;
    //cout<<"  at average of current of "<<fTotCharge/fNScalerReads/0.033<<"nA per read. "<<endl; 

    if(fChainFiles){
      if(!NextChainFile())//check if another file and initilaise
	return kFALSE; //end of all files
      else fHipo->NextEvent(); //first event of new file
    }
    else return kFALSE; //Only analysing 1 file
  }


  
  fEntry++;
 
  fWriteThis=kFALSE; //don't write scaler events on their own, accumulate and write at end or with other events
  RawScaler();

  //Now check Event Builder Banks, -2 =>we have all ready got event
  //Note that this function will call fEvBank->NextEntry()
   CLAS12::HipoReader::ReadEvent(-2); 

  //now other event scalars
  if(fEvBank->GetEntry()<0) return kTRUE;
  fWriteThis=kTRUE; //Got a REC::Event 
  
  fEventInfo->fTrigBit=(fRecEvTRG->Val());
  fEventInfo->fCJSTTime=(fRecEvSTTime->Val());
  fEventInfo->fRFTime=(fRecEvRFTime->Val());
  fEventInfo->fBeamHel=(fRecEvHelic->Val());
  fEventInfo->fNEvent=(fRecEvNEVENT->Val());

  makeVTPTriggers();
  fEventInfo->fVTPTrigBit=(fVTPBitSet.to_ulong());
  
  // for(auto &jt : fVTPTriggers)
  //   cout<<jt<<" ";
  // cout<<"\n";
  
  return kTRUE;

}
void   CLAS12::HipoTrigger::RawScaler()
{
  Double_t GatedFC=0;
  Double_t UnGatedFC=0;

  while(fRawScalBank->NextEntry()){
    if(fRawScalBank->GetEntry()<0) break;
    
    if(fRawScalChan->Val()==0 && fRawScalSlot->Val()==0)
      GatedFC=fRawScalVal->Val();
    if(fRawScalChan->Val()==0 && fRawScalSlot->Val()==1)
      UnGatedFC=fRawScalVal->Val();
    
 
    }
  if(GatedFC==0) return;
  
  Float_t trueFreq = GatedFC / (0.03333 - 0.0005);
  Float_t beamCurrent = (trueFreq-100)/906.2/fCurFactor;

  fCharge=beamCurrent*0.033;//0.033ms scaler read
  fTotCharge+=fCharge;
  fNScalerReads++;

}

Int_t  CLAS12::HipoTrigger::makeVTPTriggers() {

  fVTPBitSet.reset();
  Int_t nVTPTriggers = 0;
  
  Int_t nrows1 = 0;
  
  Int_t crate= 0;
  Int_t nwords= 0;
  Int_t word1VTP, word2VTP, word3VTP= 0;
  const Int_t trig2VTP=100;
  
 
  while (fVTPTrigBank->NextEntry()) {

    crate = fVTPDBCrate->Val();
    
    if (crate == trig2VTP) {
      nwords = fVTPDBWord->Val();
      if (nwords == 4)
	nVTPTriggers = 0;
      else
	nVTPTriggers = (nwords - 4) / 2;
      // decode them
      fVTPTrigBank->SetEntry(fVTPTrigBank->GetEntry()+4); //like loop1+=4
      for (Int_t loop2 = 0; loop2 < nVTPTriggers; loop2++) {
	word1VTP = fVTPDBWord->Val();
	fVTPTrigBank->NextEntry(); //loop1++
	if (((word1VTP >> 27) & 0x1F) == 0x1D) {
	  word2VTP = fVTPDBWord->Val();
	  fVTPTrigBank->NextEntry(); //loop1++
	 
	  decodeVTPTrigger(word1VTP, word2VTP);
	}
      }
    } 
    else {
      fVTPTrigBank->NextEntry(); //loop1++ 
    }
  }
  
  return 0;
  
}

void  CLAS12::HipoTrigger::decodeVTPTrigger(Int_t word1vtp, Int_t word2vtp) {
  Int_t time, trgL, trgH;
  time = (word1vtp >> 16) & 0x7FF; // 11 bits time
  trgL = (word1vtp & 0xFFFF); // 16 bits
  trgH = (word2vtp & 0xFFFF); // 16 bits
  Long_t pattern=(trgL&0xFFFF)|((trgH<<16)&0xFFFF0000);
  addVTPTriggerToEvent(pattern);
}

void  CLAS12::HipoTrigger::addVTPTriggerToEvent(Long_t pattern){
  const UInt_t bitsize= fVTPBitSet.size();
  for(UInt_t ib=0;ib<bitsize;ib++)
    fVTPBitSet.set(ib,(pattern& (1<<ib)) !=0);
}
