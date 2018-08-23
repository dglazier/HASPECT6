/**
	\class THSHipoReader
	
	Class to create THSParticle from hipo banks.
	
	Inherits from THSDataManager (see comments there).

	Mainly uses REC::Particle bank with associated REC:: detectors.

	This class uses the stand-alone THipo library to interface
	to the values in the banks

*/
#include <sstream>
#include <string>
#include "THSHipoReader.h"
#include <TSystem.h>

THSHipoReader::THSHipoReader(){
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
Bool_t THSHipoReader::Init(TString filename,TString name){
  fCurFileName=gSystem->BaseName(filename);
  cout<<"THSHipoReader::Init "<<fCurFileName<<endl;
  fHipo->InitFile(filename);
  //File opened can now configure banks
  if(!fPBank){
    Info("THSHipoReader","Opened file");
    fHipo->ConfigOnlyBank("REC::Particle");
    fHipo->ConfigOnlyBank("REC::Scintillator");
    fHipo->ConfigOnlyBank("REC::Calorimeter");
    fHipo->ConfigOnlyBank("REC::Cherenkov");
    fHipo->ConfigOnlyBank("REC::ForwardTagger");
    fHipo->ConfigOnlyBank("REC::Event");
    //fHipo->ConfigOnlyBank("TimeBasedTrkg::TBTracks");
    //fHipo->ConfigOnlyBank("CVTRec::Tracks");
    fHipo->ConfigOnlyBank("REC::Track");
    //fHipo->ConfigOnlyBank("FTCAL::clusters");//needed for FT time
    if(fAddGenerated&&!fMCBank){
      fHipo->ConfigOnlyBank("MC::Particle");
    }
    fHipo->ConfigBanks();
    
    //fHipo->ConfigOnlyBank("CVTRec::Tracks");
    //Get the necessary items from Particle Bank
    fPBank=fHipo->GetBank("REC::Particle");
    fPx=dynamic_cast<THipoItemF*>(fPBank->GetItem("px"));
    fPy=dynamic_cast<THipoItemF*>(fPBank->GetItem("py"));
    fPz=dynamic_cast<THipoItemF*>(fPBank->GetItem("pz"));
    fVx=dynamic_cast<THipoItemF*>(fPBank->GetItem("vx"));
    fVy=dynamic_cast<THipoItemF*>(fPBank->GetItem("vy"));
    fVz=dynamic_cast<THipoItemF*>(fPBank->GetItem("vz"));
    fPid=dynamic_cast<THipoItemI*>(fPBank->GetItem("pid"));
    fBeta=dynamic_cast<THipoItemF*>(fPBank->GetItem("beta"));
    fCharge=dynamic_cast<THipoItemB*>(fPBank->GetItem("charge"));
    fStatus=dynamic_cast<THipoItemS*>(fPBank->GetItem("status"));

    //Get the necessary items from REC::Scintillator Bank
    fSBank=fHipo->GetBank("REC::Scintillator");
    fSPindex=dynamic_cast<THipoItemS*>(fSBank->GetItem("pindex"));
    fSTime=dynamic_cast<THipoItemF*>(fSBank->GetItem("time"));
    fSSector=dynamic_cast<THipoItemB*>(fSBank->GetItem("sector"));
    fSEnergy=dynamic_cast<THipoItemF*>(fSBank->GetItem("energy"));
    fSPath=dynamic_cast<THipoItemF*>(fSBank->GetItem("path"));
    fSDet=dynamic_cast<THipoItemB*>(fSBank->GetItem("detector"));
    fSLayer=dynamic_cast<THipoItemB*>(fSBank->GetItem("layer"));
    //Get the necessary items from REC::Calorimeter Bank
    fCalBank=fHipo->GetBank("REC::Calorimeter");
    fCalPindex=dynamic_cast<THipoItemS*>(fCalBank->GetItem("pindex"));
    fCalEnergy=dynamic_cast<THipoItemF*>(fCalBank->GetItem("energy"));
    fCalTime=dynamic_cast<THipoItemF*>(fCalBank->GetItem("time"));
    fCalPath=dynamic_cast<THipoItemF*>(fCalBank->GetItem("path"));
    fCalLayer=dynamic_cast<THipoItemB*>(fCalBank->GetItem("layer"));
     //Get the necessary items from REC::Cherenkov Bank
    fChBank=fHipo->GetBank("REC::Cherenkov");
    fChPindex=dynamic_cast<THipoItemS*>(fChBank->GetItem("pindex"));
    fChEnergy=dynamic_cast<THipoItemF*>(fChBank->GetItem("nphe"));
    fChDetector=dynamic_cast<THipoItemB*>(fChBank->GetItem("detector"));
    //Get the necessary items from REC::FT Bank
    fFTBank=fHipo->GetBank("REC::ForwardTagger");
    fFTPindex=dynamic_cast<THipoItemS*>(fFTBank->GetItem("pindex"));
    fFTTime=dynamic_cast<THipoItemF*>(fFTBank->GetItem("time"));
    fFTEnergy=dynamic_cast<THipoItemF*>(fFTBank->GetItem("energy"));
    fFTPath=dynamic_cast<THipoItemF*>(fFTBank->GetItem("path"));
    fFTDet=dynamic_cast<THipoItemB*>(fFTBank->GetItem("detector"));
    fFTX=dynamic_cast<THipoItemF*>(fFTBank->GetItem("x"));
    fFTY=dynamic_cast<THipoItemF*>(fFTBank->GetItem("y"));
    fFTZ=dynamic_cast<THipoItemF*>(fFTBank->GetItem("z"));
  
    fTrBank=fHipo->GetBank("REC::Track");
    fTrPindex=dynamic_cast<THipoItemS*>(fTrBank->GetItem("pindex"));
    fTrIndex=dynamic_cast<THipoItemS*>(fTrBank->GetItem("index"));
    fTrDet=dynamic_cast<THipoItemB*>(fTrBank->GetItem("detector"));
    fTrq=dynamic_cast<THipoItemB*>(fTrBank->GetItem("q"));
    fTrNDF=dynamic_cast<THipoItemS*>(fTrBank->GetItem("NDF"));
    fTrChi2=dynamic_cast<THipoItemF*>(fTrBank->GetItem("chi2"));
 
    //    fTBTrBank=fHipo->GetBank("TimeBasedTrkg::TBTracks");
    //fTBTrNDF=dynamic_cast<THipoItemS*>(fTBTrBank->GetItem("ndf"));
    //fTBTrChi2=dynamic_cast<THipoItemF*>(fTBTrBank->GetItem("chi2"));
    //fCVTrBank=fHipo->GetBank("CVTRec::Tracks");
    //fCVTrNDF=dynamic_cast<THipoItemS*>(fCVTrBank->GetItem("ndf"));
    //fCVTrChi2=dynamic_cast<THipoItemF*>(fCVTrBank->GetItem("chi2"));
  
    fEvBank=fHipo->GetBank("REC::Event");
    fRecEvSTTime=dynamic_cast<THipoItemF*>(fEvBank->GetItem("STTime"));

    //    fFTCALClustBank=fHipo->GetBank("FTCAL::clusters");
    //fFTCALClust_t=dynamic_cast<THipoItemF*>(fFTCALClustBank->GetItem("time"));

    if(fAddGenerated&&!fMCBank){
      fMCBank=fHipo->GetBank("MC::Particle");
      fMCPx=dynamic_cast<THipoItemF*>(fMCBank->GetItem("px"));
      fMCPy=dynamic_cast<THipoItemF*>(fMCBank->GetItem("py"));
      fMCPz=dynamic_cast<THipoItemF*>(fMCBank->GetItem("pz"));
      fMCVx=dynamic_cast<THipoItemF*>(fMCBank->GetItem("vx"));
      fMCVy=dynamic_cast<THipoItemF*>(fMCBank->GetItem("vy"));
      fMCVz=dynamic_cast<THipoItemF*>(fMCBank->GetItem("vz"));
      fMCPid=dynamic_cast<THipoItemI*>(fMCBank->GetItem("pid"));
      fReadGenerated=new vector<THSParticle>;
    }
  }
  return kTRUE;
}
////////////////////////////////////////////////////////
//nothing to do for hipo files (I think)
void THSHipoReader::CloseReadTree(){
  //noting to do for hipo files (I think)
}

//////////////////////////////////////////////////////////////
///Make output files, generally 1 for each input file
///Calling SetCombine files allows all input files to be written to 1 output
///Watch file sizes though!
void THSHipoReader::InitOutput(TString filename){
  //CLAS file names ~ out_clas_003311.evio.3.hipo ~out_clas_RUNNO.evio.FILENO.hipo
  //Want the option to write all files into 1 run output file
  //Write all input events on 1 go

  //Initialise
  Int_t run_number=GetRunNumber(filename);
  if(!fCombineFiles) //only merge files if fCombineFiles=kTRUE
    THSDataManager::InitOutput(filename);
  else if(run_number!=fRunNumber){
    TString basen=gSystem->BaseName(filename);
    TString runname(basen(0,16));//out_clas_NNNNNN.
    runname.Append("root");
    runname.Prepend(TString(gSystem->DirName(filename))+"/");
    cout<<"THSHipoReader::WriteParticles Actually write to "<<runname<<endl;
    THSDataManager::InitOutput(runname);
    fRunNumber=run_number;
  }

}
///////////////////////////////////////////////////////////////
///Close output root file after each input hipo file
///If SetCombineFiles set, merge all files into 1
void THSHipoReader::CloseOutput(){
  if(!fCombineFiles){ //only merge files if fCombineFiles=kTRUE
    THSDataManager::CloseOutput();
    return;
  }
  else if(fChainFileN+1<fChainFiles->GetEntries()){
    TString nextfname=fChainFiles->At(fChainFileN+1)->GetTitle();
    if(GetRunNumber(nextfname)!=fRunNumber)//if same run number keep same output open
      THSDataManager::CloseOutput();
  }
  else
    THSDataManager::CloseOutput();//last file
}
//////////////////////////////////////////////////////////////
///Get run number from file name for purposes of combining files
///This could be got from the banks (it is written in RunInfo)
Int_t THSHipoReader::GetRunNumber(TString filen){
  TString base(gSystem->BaseName(filen));
  TString sNum0(base(base.First("0"),6));
  return sNum0.Atoi();
}
/////////////////////////////////////////////////////////////////
///The important function.
/// Read the event from THipo.
/// Get values from THipo and but into THSParticle class.
/// Called once per hipo event.
Bool_t THSHipoReader::ReadEvent(Long64_t entry){
  //if entry ==-2 we have been called from a derived class who has
  //already got the event
  if(entry!=-2){
    if(!fHipo->NextEvent()) {//end of 1 file
      if(fChainFiles){
	if(!NextChainFile())//check if another file and initilaise
	  return kFALSE; //end of all files
	else fHipo->NextEvent(); //first event of new file
      }
      else return kFALSE; //Only analysing 1 file
    }
    fEntry++;
  }
  
  if(fEntry%100000==0) cout<<fEntry<<endl;
  fParticles.clear();//reset fParticles
  fGenerated.clear();//reset fParticles
  fPIDs.clear();//reset pid values
  if(fAddGenerated) fGenerated.clear();//reset fGenerated
  if(fAddGenerated&&fMCBank){//First read generated event
    UInt_t NGen=fMCBank->GetEntries();
    Int_t ip=0;
    fGenerated.reserve(NGen);
    while(fMCBank->NextEntry()){
      THSParticle particle;
      particle.SetXYZM(fMCPx->Val(),fMCPy->Val(),fMCPz->Val(),0);
      particle.SetVertex(fMCVx->Val(),fMCVy->Val(),fMCVz->Val());
      particle.SetPDGcode(fMCPid->Val());
      particle.TakePDGMass();
      fGenerated.emplace_back(particle);
    }
    
  }
  //eventbuilder particle bank
  if(fEvBank) fEvBank->NextEntry();
  
  if(fPBank){ //Filling reconstructed fParticles
    UInt_t Nin=fPBank->GetEntries();
     Int_t ip=0;
    fParticles.reserve(Nin);
    fPIDs.reserve(Nin);
    while(fPBank->NextEntry()){
      THSParticle particle;
      // particle.Clear();
      particle.SetXYZM(fPx->Val(),fPy->Val(),fPz->Val(),0);
      particle.SetVertex(fVx->Val(),fVy->Val(),fVz->Val());
      //if(fBeta->Val())particle->SetMeasMass(particle->P4p()->Rho()/fBeta->Val());
      particle.SetStatus(fStatus->Val());      
      if(!fPid->Val()) particle.SetPDGcode(fCharge->Val()*1E4); //unknown
      else  particle.SetPDGcode(fPid->Val());
       
      //Now look for the associated detector info
      //we must match the detector pindex to the index of this particle entry
      //  cout<<"Done particle "<<endl;
      Int_t nscint=0;
      Double_t deltaE=0;

      Int_t PEntry=fPBank->GetEntry();
      //Scintillators
      while(fSPindex->FindEntry(PEntry)){
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
	  //	  if(particle.Time()==0){ //use FD layer 2 if exists
	  //Just take CTOF hit, i.e. replace CND 
	  particle.SetTime(fSTime->Val());
	  particle.SetPath(fSPath->Val()/100);
	  deltaE+=fSEnergy->Val();
	  particle.SetDetector(10000);
	}
	else  if(fSDet->Val()==3) {//CD-Neutron
	  if(particle.Time()==0){ //use FD layer 2 if exists
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
	// Int_t dett=fTrDet->Val();
	// Int_t qq=fTrq->Val();
	// Int_t chargee=fCharge->Val();
	// if(dett==5){//CVT
	//   fCVTrBank->SetEntry(fTrIndex->Val());
	//   particle.SetTrChi2(fCVTrChi2->Val()/fCVTrNDF->Val());
	// }
	// else if(dett==6){//DC
	//   fTBTrBank->SetEntry(fTrIndex->Val());
	//   particle.SetTrChi2(fTBTrChi2->Val()/fTBTrNDF->Val());
	// }
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
      fPIDs.emplace_back(particle.PDG());
      fParticles.emplace_back(particle);
   
    }
  }
  return kTRUE;
  
}
