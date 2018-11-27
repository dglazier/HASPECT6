/**
	\class HipoToolsReader
	
	Class to create THSParticle from hipo banks.
	
	Inherits from THSDataManager (see comments there).

	Mainly uses REC::Particle bank with associated REC:: detectors.

	This class uses the stand-alone THipo library to interface
	to the values in the banks

*/
#include <sstream>
#include <string>
#include "HipoToolsReader.h"
#include <TSystem.h>

using namespace HS;

CLAS12::HipoToolsReader::HipoToolsReader(){
  //create CLAS12 data structures
  //and pass to HS::DataManager
  fEventInfo=new CLAS12::EventInfo();
  fBaseEventInfo=fEventInfo;
  
  fRunInfo=new CLAS12::RunInfo();
  fBaseRunInfo=fRunInfo;

  fHipo = new THipo();
  fHipo->SetIsVector(kFALSE);
  //Make vectors to hold pointers to THSParticles
  //These are just used for speed, new THSParticles
  //will be added when required by that event.
  //In the end this vector will contain max number of particles
  //from all the events
  fReadParticles=new vector<THSParticle>;
  
 
}
////////////////////////////////////////////////////////////
/// Initialise banks and items
Bool_t CLAS12::HipoToolsReader::Init(TString filename,TString name){
  fCurFileName=gSystem->BaseName(filename);

  //open new hipo file
  reader.open(filename);

  fEvParticles=fEvent.getParticles();
  
  return kTRUE;
}
////////////////////////////////////////////////////////
//nothing to do for hipo files (I think)
void CLAS12::HipoToolsReader::CloseReadTree(){
  //noting to do for hipo files (I think)
}

//////////////////////////////////////////////////////////////
///Make output files, generally 1 for each input file
///Calling SetCombine files allows all input files to be written to 1 output
///Watch file sizes though!
void CLAS12::HipoToolsReader::InitOutput(TString filename){
  //CLAS file names ~ out_clas_003311.evio.3.hipo ~out_clas_RUNNO.evio.FILENO.hipo
  //Want the option to write all files into 1 run output file
  //Write all input events on 1 go

  //Initialise
  Int_t run_number=GetRunNumber(filename);
  if(!fCombineFiles) //only merge files if fCombineFiles=kTRUE
    DataManager::InitOutput(filename);
  else if(run_number!=fRunNumber){
    TString basen=gSystem->BaseName(filename);
    TString runname(basen(0,16));//out_clas_NNNNNN.
    runname.Append("root");
    runname.Prepend(TString(gSystem->DirName(filename))+"/");
    cout<<"HipoToolsReader::WriteParticles Actually write to "<<runname<<endl;
    DataManager::InitOutput(runname);
    fRunNumber=run_number;
  }

}
///////////////////////////////////////////////////////////////
///Close output root file after each input hipo file
///If SetCombineFiles set, merge all files into 1
void  CLAS12::HipoToolsReader::CloseOutput(){
  if(!fCombineFiles){ //only merge files if fCombineFiles=kTRUE
    DataManager::CloseOutput();
    return;
  }
  else if(fChainFileN+1<fChainFiles->GetEntries()){
    TString nextfname=fChainFiles->At(fChainFileN+1)->GetTitle();
    if(GetRunNumber(nextfname)!=fRunNumber)//if same run number keep same output open
      DataManager::CloseOutput();
  }
  else
    DataManager::CloseOutput();//last file
}
//////////////////////////////////////////////////////////////
///Get run number from file name for purposes of combining files
///This could be got from the banks (it is written in RunInfo)
Int_t  CLAS12::HipoToolsReader::GetRunNumber(TString filen){
  TString base(gSystem->BaseName(filen));
  TString sNum0(base(base.First("0"),6));
  return sNum0.Atoi();
}
/////////////////////////////////////////////////////////////////
///The important function.
/// Read the event from THipo.
/// Get values from THipo and but into THSParticle class.
/// Called once per hipo event.
Bool_t CLAS12::HipoToolsReader::ReadEvent(Long64_t entry){
  //if entry ==-2 we have been called from a derived class who has
  //already got the event
  fEvent.reset();
  
  if(entry!=-2){ 
    if(!reader.next()) {//end of 1 file
      if(fChainFiles){
	if(!NextChainFile())//check if another file and initilaise
	  return kFALSE; //end of all files
	else hipo.next(); //first event of new file
      }
      else return kFALSE; //Only analysing 1 file
    }
    fEntry++;
  }
  
  if(fEntry%100000==0) cout<<fEntry<<endl;
  fParticles.clear();//reset fParticles
  fGenerated.clear();//reset fParticles
  //fPIDs.clear();//reset pid values
  if(fAddGenerated) fGenerated.clear();//reset fGenerated
  
  

  fParticles.reserve(fEvent.getNParticles());
  //fPIDs.reserve(Nin);
  while(fEvent.next_particle()){
    
    THSParticle particle;
    
    particle.SetXYZM(fEvParticle.getPx() ,fEvParticle.getPy() ,fEvParticle.getPz() ,0);
    particle.SetVertex(fEvParticle.getVx() ,fEvParticle.getVy() ,fEvParticle.getVz());
    particle.SetStatus(fEvParticle.getStatus());
    
    if(!fEvParticle.getPid()) particle.SetPDGcode(fEvParticle.getCharge()*1E4); //unknown
    else  particle.SetPDGcode(fEvParticle.getPid());
       
  
    if(psector) particle.SetDetector(1000*psector);

	//Do something if find a particular detector
	if(fSDet->Val()==12){//FD-TOF
	  if(particle.Time()==0||(fSLayer->Val()==2)){ //use FD layer 2 if exists
	    particle.SetTime(fSTime->Val());
	    particle.SetPath(fSPath->Val()/100);
	  }
	  deltaE+=fSEnergy->Val();
	  particle.SetDetector(1000*fSSector->Val());
	}
	else  if(fSDet->Val()==4) {//CD-TOF
	  //Just take CTOF hit, i.e. replace CND 
	  particle.SetTime(fSTime->Val());
	  particle.SetPath(fSPath->Val()/100);
	  deltaE+=fSEnergy->Val();
	  particle.SetDetector(10000);
	}
	else  if(fSDet->Val()==3) {//CD-Neutron
	  if(particle.Time()==0){
	    particle.SetTime(fSTime->Val());
	    particle.SetPath(fSPath->Val()/100);
	  }
	  deltaE+=fSEnergy->Val();
	  particle.SetEdep(fSEnergy->Val()); //use edep for CND energy
	  particle.SetDetector(10000);
	}
	nscint++;
      }
      particle.SetDeltaE(deltaE/nscint); //FD:sum of layers,CD:sum of CTOF/CND
 
      //Calorimeters
      while(fCalPindex->FindEntry(PEntry)){
	//Do something if find a particular detector
	particle.SetEdep(fCalEnergy->Val()+particle.Edep());//sum Energy
	if(fCalLayer->Val()==1)	{
	  particle.SetPreE(fCalEnergy->Val()); //PCAL
	
	  if(particle.Time()==0){//no scintillator time
	    particle.SetTime(fCalTime->Val());
	    particle.SetPath(fCalPath->Val()/100);
	  }
	}
	particle.SetDetector(particle.Detector()+100);
      }
      //Cerenkov
      while(fChPindex->FindEntry(PEntry)){
	//Do something if find a particular detector
	//particle.AddEdep(fChEnergy->Val());
	particle.SetDetector(particle.Detector()+fChDetector->Val());
	if(fChDetector->Val()==15) particle.SetNPhot(particle.NPhot()+fChEnergy->Val());
	if(fChDetector->Val()==16) particle.SetNPhot(particle.NPhot()+1E4*fChEnergy->Val());
      }
      
      //Trackers	
      while(fTrPindex->FindEntry(PEntry)){
	particle.SetTrChi2(fTrChi2->Val()/fTrNDF->Val());
      }
  	
      while(fFTPindex->FindEntry(PEntry)){
	if(fFTDet->Val()==10){//FTCAL
	  particle.SetEdep(fFTEnergy->Val());
	  particle.SetTime(fFTTime->Val());
	  Double_t ftx=fFTX->Val();
	  Double_t fty=fFTY->Val();
	  Double_t ftz=fFTZ->Val();
	  particle.SetPath(sqrt(ftx*ftx+fty*fty+ftz*ftz)/100);
	  //	  particle.SetPath(fFTPath->Val()/100);
	}
	if(fFTDet->Val()==11){//FTHODO
	  particle.SetDeltaE(fFTEnergy->Val());
	}
	// fFTCALClustBank->SetEntry(fFTBank->GetEntry());
	// particle.SetTime(fFTCALClust_t->Val()); //This is currently HODO time
	// particle.SetDeltaE(fFTEnergy->Val());
	// particle.SetPath(fFTPath->Val()/100); //Note as of 5.4.0 units will change, need to remove /100
	particle.SetDetector(-1000);
	particle.SetPDGcode(fCharge->Val()*1E4);
	
      }
      //fPIDs.emplace_back(particle.PDG());
      fParticles.emplace_back(std::move(particle));
   
    }
  }
  return kTRUE;
  
}
