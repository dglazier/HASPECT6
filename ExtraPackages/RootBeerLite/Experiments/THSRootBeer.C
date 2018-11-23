#include "RootBeerUtil.h"	//gets everything for RootBeer scheme
#include "TDST.h"
//#include "RootBeerUtil.h"	//gets everything for RootBeer scheme
//#include "TDST.h"
#include "THSRootBeer.h"

//gSystem->Load("/home/claslib/builds/G8G9/slib/Linux64RHFC21/libDecayUtils"); //for PM momentum and enrgy loss corrections

THSRootBeer::THSRootBeer(TString banks){
  fMyBanks=banks;
 }
Bool_t THSRootBeer::Init(TString filename,TString name){
  //clear up any pervious instance
  if(fRootBeer) {delete fRootBeer;fRootBeer=nullptr;}

  fRootBeer=createBeerObject(const_cast<char*>(filename.Data()));
  if(!fRootBeer) return kFALSE;
  // switch on the banks required
  TObjArray *banks=fMyBanks.Tokenize(":");
  for(Int_t ib=0;ib<banks->GetEntries();ib++)
    fRootBeer->SetBankStatus(banks->At(ib)->GetName(),ON);
  // start the server running
  fRootBeer->StartServer(); 
  // list the banks which will be served
  fRootBeer->ListServedBanks();

  fRunInfo=new HS::RunInfo();
  fBaseRunInfo=fRunInfo;
	
  //Get run number from filename		       	
  TString tsinFile(filename);
  fRun_number=TString(tsinFile(tsinFile.Index(".root")-6,6)).Atoi();
  fRunInfo->fNRun=fRun_number;
  if(fIsSim) fRunInfo->fType=1;
  else  fRunInfo->fType=0;
  return kTRUE;

}
void THSRootBeer::CloseReadTree(){
  if(fRootBeer) {delete fRootBeer;fRootBeer=nullptr;}

}
Bool_t THSRootBeer::RBEvent(Long64_t entry){
  Long64_t RBentry = fRootBeer->GetEvent();// get next event
  //cout<<fEntry<<endl;
  if(RBentry<0){
    if	(fChainFiles){
      if(!NextChainFile())//check if another file and initilaise
	return kFALSE; //end of all files
      else fRootBeer->GetEvent(); //first event of new file
    }
    else  return kFALSE;
  }
  fEntry++;
  fParticles.clear();
  fGenerated.clear();
  return kTRUE;
}
Bool_t THSRootBeer::ReadEvent(Long64_t entry){
  if(!RBEvent()) return kFALSE;

  MakeDetected();
  
  return kTRUE;
  
}
 void THSRootBeer::MakeDetected(){
  
   for(Int_t ip=0;ip<EVNT_NH;ip++){
     if((EVNT[ip].DCstat == 0)||((EVNT[ip].ECstat == 0)&&(EVNT[ip].SCstat == 0))) { continue;}
     if(EVNT[ip].Status == 0) { continue;}
     //recalcualte the mass2 for this event
     if(EVNT[ip].Betta==0) continue;//need to chack effect of this

     MakeParticle(ip);
  }
 
}
void THSRootBeer::MakeParticle(Int_t ip){
  HS::THSParticle hsp;
    //set the vertex
  hsp.SetPDGcode(EVNT[ip].ID);
  hsp.SetVertex(EVNT[ip].X,EVNT[ip].Y,EVNT[ip].Z);
  //set the intitial Lorentz Vector
  hsp.SetXYZM(EVNT[ip].Pmom*EVNT[ip].Cx,
		 EVNT[ip].Pmom*EVNT[ip].cy,
		 EVNT[ip].Pmom*EVNT[ip].cz,0);
  //set the measured mass
  hsp.SetMeasMass(sqrt((1/EVNT[ip].Betta/EVNT[ip].Betta-1)*EVNT[ip].Pmom*EVNT[ip].Pmom));
 //Now vertex time caclulation taken from Neil's work
  Double_t vl = 29.9792458;
  // hsp.SetTime((SCPB[EVNT[ip].SCstat-1].Time)-((SCPB[EVNT[ip].SCstat-1].Path)/(vl*hsp->P4().Beta())));//-0.667
  hsp.SetTime((SCPB[EVNT[ip].SCstat-1].Time));//-0.667
  hsp.SetPath((SCPB[EVNT[ip].SCstat-1].Path));

  fParticles.push_back(hsp);
 }

