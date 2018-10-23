/**
	\class HipoDST
	
	Class to fill once per run THSRunInfo and 
	once per event THSEventInfo from hipo DST files.
	
	Inherits from HipoReader which sorts the THSParticle vector
	for the event tracks.

	Mainly uses REC::Event

	This class uses the stand-alone THipo library to interface
	to the values in the banks

*/
#include "HipoDST.h"

using namespace HS;

HipoDST::HipoDST(){
  fEventInfo=new EventInfo();
}

/////////////////////////////////////////////////////////////
/// Configure the REC::Event and RAW::Scaler banks
/// Additional items may be added in a similar fashion
Bool_t HipoDST::Init(TString filename,TString name){

  if(!fRawScalBank){
    //Add the trigger banks to those to be configured
    Info("HipoDST","Opened file");
  }
  HipoReader::Init(filename,name);
  
  if(!fRecEvNRun){
    fRecEvNRun=dynamic_cast<THipoItemI*>(fEvBank->GetItem("NRUN"));
    fRecEvNEVENT=dynamic_cast<THipoItemI*>(fEvBank->GetItem("NEVENT"));
    fRecEvTYPE=dynamic_cast<THipoItemB*>(fEvBank->GetItem("TYPE"));
    fRecEvTRG=dynamic_cast<THipoItemL*>(fEvBank->GetItem("TRG"));
    fRecEvHelic=dynamic_cast<THipoItemB*>(fEvBank->GetItem("Helic"));
    fRecEvRFTime=dynamic_cast<THipoItemF*>(fEvBank->GetItem("RFTime"));
    fRecEvBCG=dynamic_cast<THipoItemF*>(fEvBank->GetItem("BCG"));    
  }

  fCharge=0;
  // fHelicity=-1;
  fTotCharge=0;
  fNScalerReads=0;
  return kTRUE;
}

void HipoDST::InitOutput(TString filename){
  DataManager::InitOutput(filename);
}

/////////////////////////////////////////////////////////
/// Read the event from THipo.
/// Write RunInfo at the end of file (when the gated charge is known).
/// Call HipoReader::ReadEvent to fill event THSParticle vector.
/// Fill the EventInfo from REC::Event.
Bool_t HipoDST::ReadEvent(Long64_t entry){

  //cout<<"HipoDST::ReadEvent("<<endl;    

  //Note include an extra fill in case there is an extra scaler current
  if(!fHipo->NextEvent()) {
    //End of file write the total current
    if(fRunTree){
      fEvBank->SetEntry(0);
      fRunInfo->SetNRun(fRecEvNRun->Val());
      if(fAddGenerated)fRunInfo->SetType(1);
      else fRunInfo->SetType(0);
      fRunInfo->SetTotalCharge(fTotCharge);
    }
    cout<<"HipoDST::ReadEvent total charge for this file "<<fTotCharge<<endl;
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
  

  //Now check Event Builder Banks, -2 =>we have all ready got event
  //Note that this function will call fEvBank->NextEntry()
  HipoReader::ReadEvent(-2); 

  //now other event scalars
  if(fEvBank->GetEntry()<0) return kTRUE;
  fWriteThis=kTRUE; //Got a REC::Event 
  
  fEventInfo->SetTrigBit(fRecEvTRG->Val());
  fEventInfo->SetCJStartTime(fRecEvSTTime->Val());
  fEventInfo->SetRFTime(fRecEvRFTime->Val());
  fEventInfo->SetBeamHel(fRecEvHelic->Val());
  fEventInfo->SetNEvent(fRecEvNEVENT->Val());

  //Keep our own running total of  beam charge
  fTotCharge+=fRecEvBCG->Val()-fCharge;

  //set fCharge to the hipo running total
  fCharge=fRecEvBCG->Val();

 
  return kTRUE;

}
