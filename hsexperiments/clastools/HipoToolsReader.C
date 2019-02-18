/**
	\class HipoToolsReader
	
	Class to create THSParticle from hipo banks.
	
	Inherits from THSDataManager (see comments there).

	Mainly uses REC::Particle bank with associated REC:: detectors.

	This class uses the stand-alone THipo library to interface
	to the values in the banks

*/
#include "HipoToolsReader.h"
#include "particle.h"
#include "clas12defs.h"
#include <TSystem.h>

using namespace HS;

CLAS12::HipoToolsReader::HipoToolsReader(){
  //create CLAS12 data structures
  //and pass to HS::DataManager
  fEventInfo=new CLAS12::EventInfo();
  fBaseEventInfo=fEventInfo;
  
  fRunInfo=new CLAS12::RunInfo();
  fBaseRunInfo=fRunInfo;

  //Make vectors to hold pointers to THSParticles
  //These are just used for speed, new THSParticles
  //will be added when required by that event.
  //In the end this vector will contain max number of particles
  //from all the events
  fReadParticles=new vector<THSParticle>;


  //create "empty" event
  // fEvent=std::make_shared<clas12::hallb_event>();
  
  //fParticle.SetEvent(fEvent);
}
////////////////////////////////////////////////////////////
/// Initialise banks and items
Bool_t CLAS12::HipoToolsReader::Init(TString filename,TString name){
  fCurFileName=gSystem->BaseName(filename);

  //open new hipo file
  fReader.open(filename);
  fEvent.reset(new clas12::hallB_event(fReader));

  //  fEvent->init(fReader);
  return kTRUE;
}

/////////////////////////////////////////////////////////////////
///The important function.
/// Read the event from THipo.
/// Get values from THipo and but into THSParticle class.
/// Called once per hipo event.
Bool_t CLAS12::HipoToolsReader::ReadEvent(Long64_t entry){


  //get the next hallb_event
  if(!fEvent->next()) {//end of 1 file
    SetEndRunInfo();
    
    if(fChainFiles){
      if(!NextChainFile())//check if another file and initilaise
	return kFALSE; //end of all files
      else fEvent->next(); //first event of new file
    }
    else return kFALSE; //Only analysing 1 file
  }
  if(fRunEnd) SetStartRunInfo();
  
  fEntry++;

  SetEventInfo();
  
  if(fEntry%100000==0) cout<<fEntry<<endl;
  
  
  FillParticles();
  FillGenerated();
  
  return kTRUE;
}

///////////////////////////////////////////////////////
///Fill all the detected particles for this event
void CLAS12::HipoToolsReader::FillParticles(){
  fParticles.clear();//reset fParticles

  const Int_t Nin=fEvent->getNParticles();
  fParticles.reserve(Nin);
 
  //Get the particles for this event
  for(auto& p : fEvent->getDetParticles()){

    //give this particle all the clas12 data
    fParticle.Clear();
    fParticle.SetCLAS12Particle(p);

    //directly import the most used information
    auto pbank=p->par(); //get particle bank, this is only OK in loop!
    fParticle.SetXYZM(pbank->getPx() ,pbank->getPy() ,pbank->getPz() ,0);
    fParticle.SetVertex(pbank->getVx() ,pbank->getVy() ,pbank->getVz());
    //fParticle.SetStatus(pbank->getStatus());

    Short_t pid=pbank->getPid();
    if(!pid) fParticle.SetPDGcode(pbank->getCharge()*HS::UndefinedPDG);
    else  fParticle.SetPDGcode(pid);
    
    fParticle.SetTime(p->getTime());
    fParticle.SetPath(p->getPath()/100);
    //possibly do other stuff depending on region
    // switch(p->region()) {
    // case clas12::FD :
    //   break;
    // case clas12::FT :
    //   break;
    // case clas12::CD :
    //   break;
    // }
    fParticles.emplace_back(fParticle);
    
  }
}

///////////////////////////////////////////////////////
///Fill all the generated particles for this event
void CLAS12::HipoToolsReader::FillGenerated(){

  auto mcpbank=fEvent->mcparts();
  const Int_t  Ngen=mcpbank->getSize();

  fGenerated.clear();
  fGenerated.reserve(Ngen);

  for(Int_t i=0;i<Ngen;i++){
    fParticle.Clear();
    mcpbank->setEntry(i);
    
    fParticle.SetXYZM(mcpbank->getPx() ,mcpbank->getPy() ,mcpbank->getPz() ,mcpbank->getMass());
    fParticle.SetVertex(mcpbank->getVx() ,mcpbank->getVy() ,mcpbank->getVz());
    fParticle.SetPDGcode(mcpbank->getPid());
    fGenerated.emplace_back(fParticle);
  }

    
}
//////////////////////////////////////////////////////
///Read event info from header bank (REC::EVENT)
void CLAS12::HipoToolsReader::SetEventInfo(){

  fEventInfo->fTrigBit=fEvent->head()->getTrigger();
  fEventInfo->fVTPTrigBit=fEvent->vtp()->makeVTPTriggers();
  fEventInfo->fCJSTTime=fEvent->head()->getStartTime();
  fEventInfo->fRFTime=fEvent->head()->getRFTime();
  fEventInfo->fBeamHel=fEvent->head()->getHelicity();
  fEventInfo->fNEvent=fEvent->head()->getEventNumber();

  
}
//////////////////////////////////////////////////////
///Read run info from header bank (REC::EVENT)
void CLAS12::HipoToolsReader::SetStartRunInfo(){
  cout<<fEvent->head()->getType()<<" "<<fAddGenerated<<endl;
  fRunInfo->fNRun=fEvent->head()->getRunNumber();
  if(fAddGenerated)fRunInfo->fType=(1);
  else fRunInfo->fType=(0);

  fRunEnd=kFALSE;
  
}
//////////////////////////////////////////////////////
///store the accumulated charge
void CLAS12::HipoToolsReader::SetEndRunInfo(){

  fRunInfo->fNRun=fTotCharge;//at some point need to accumulate charge!
  fRunEnd=kTRUE;
  
}
