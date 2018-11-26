#include <TROOT.h>
#include <TSystem.h>
#include "RootBeerUtil.h"	//gets everything for RootBeer scheme
#include "TDST.h"
#include "THSCLASg8.h"
#include "particleDEF.h"

#include "extra_packages/eloss_rb/eLoss.h"              //For energy loss corrections

// //for PM momentum and enrgy loss corrections

THSCLASg8::THSCLASg8() : THSRootBeer("EPIC:EVNT:ECPB:SCPB:TAGR:TGBI:DCPB:STPB:MCTK:MCVX") {
  //for PM momentum and enrgy loss corrections
  
  fEventInfo=new HS::EventInfo();
  fBaseEventInfo=fEventInfo;
}

Bool_t THSCLASg8::Init(TString filename,TString name){
  THSRootBeer::Init(filename,name);
  //Load fake MC run number
  if(fAddGenerated){
    fRun_number = TString("054044").Atoi();
    fRunInfo->fType=1;
   // LoadMCCor("/home/dglazier/Dropbox/g13Sim/MCCor/totalSept16.root");
  }
   //initialise eloss
  initELoss(0.0,0.0,-20.0,-24.06);

  //Get run number from filename, overwrite THSRootBeer which doesn't expect a .dat		       	
  TString G8=gSystem->Getenv("G8");	
  TString tsinFile(filename);
  fRun_number=TString(tsinFile(tsinFile.Index(".root")-10,10)).Atoi();
  fRunInfo->fNRun=fRun_number;
  cout<<"Analysing run "<<fRun_number<<endl;
  sprintf(edgeTable,"%s/poltabs/run_%d_pol_edges.dat",G8.Data(),fRun_number);
  if(fpolTableN[0]==0&&fpolTableN[1]==0)LoadPolarisations();
  LoadEdgeTable(edgeTable);

  return kTRUE;
}
Bool_t THSCLASg8::ReadEvent(Long64_t entry){
  if(!RBEvent()) return kFALSE;

  if(EPIC_NS){
    //EPICSEvent();
    return kTRUE;//not saving this event just getting epics info	
  }
  if(EVNT_NH>0){
    Double_t vl = 29.9792458;
    Double_t  starttime=SCPB[EVNT[0].SCstat-1].Time-(SCPB[EVNT[0].SCstat-1].Path)/vl/EVNT[0].Betta;//OR THIS COULD BE FROM THE HEVT STT
    if(!fIsSim)fEventInfo->fCJSTTime=starttime;
    //make particles for this event
    MakeDetected();
    //get tagged photons for this event
    MakeBeam(-20,200);
    //Any mc tracks
    if(fAddGenerated)MakeTruth();
  }
  return kTRUE;
  
}
 void THSCLASg8::MakeDetected(){
  
   for(Int_t ip=0;ip<EVNT_NH;ip++){
     if((EVNT[ip].DCstat == 0)||((EVNT[ip].ECstat == 0)&&(EVNT[ip].SCstat == 0))) { continue;}
     if(EVNT[ip].Status == 0) { continue;}
     //recalcualte the mass2 for this event
     if(EVNT[ip].Betta==0) continue; //need to chack effect of this

     MakeParticle(ip);
  }
 
}
void THSCLASg8::MakeParticle(Int_t ip){
 
  HS::THSParticle hsp;
  hsp.SetPDGcode(EVNT[ip].Charge *1E4);
  hsp.SetVertex(EVNT[ip].X,EVNT[ip].Y,EVNT[ip].Z);
  //set the intitial Lorentz Vector
  hsp.SetXYZM(EVNT[ip].Pmom*EVNT[ip].Cx,
		 EVNT[ip].Pmom*EVNT[ip].cy,
		 EVNT[ip].Pmom*EVNT[ip].cz,0);
  //set the measured mass
  hsp.SetMeasMass(sqrt((1/EVNT[ip].Betta/EVNT[ip].Betta-1)*EVNT[ip].Pmom*EVNT[ip].Pmom));
 //Now vertex time caclulation taken from Neil's work

  if(EVNT[ip].SCstat-1 >=0 ){
    hsp.SetTime(SCPB[EVNT[ip].SCstat-1].Time);//-0.667
    hsp.SetPath(SCPB[EVNT[ip].SCstat-1].Path/100);
    hsp.SetDeltaE(SCPB[EVNT[ip].SCstat-1].Edep);
  }
  if(EVNT[ip].ECstat-1 >=0 ){
    hsp.SetEdep(ECPB[EVNT[ip].ECstat-1].Etot);
    hsp.SetPreE(ECPB[EVNT[ip].ECstat-1].Ein);
    if(EVNT[ip].SCstat-1 < 0){
      hsp.SetTime(ECPB[EVNT[ip].ECstat-1].Time);//-0.667
      hsp.SetPath(ECPB[EVNT[ip].ECstat-1].Path/100);
    }	
  }
  
  Int_t sector = floor(double(DCPB[EVNT[ip].DCstat-1].ScTr) / 100.);  //from daria;s Particle.h
  TLorentzVector P4hyp0=hsp.GetTLorentzVector();
  TLorentzVector P4hyp=hsp.GetTLorentzVector();
  // reference run number, PDG ID, sector of particle, four-vector
  if(EVNT[ip].Charge){
    hsp.SetHypPPi(eLoss(&P4hyp,PI_CHARGED_MASS,hsp.GetVertex3(),ELOSS_TARG_LH2,ELOSS_CELL_g8b)->P());
    //Corrected momentum if proton
    hsp.SetHypPNuc(eLoss(&P4hyp,PROTON_MASS,hsp.GetVertex3(),ELOSS_TARG_LH2,ELOSS_CELL_g8b)->P());
    //Corrected momentum if kaon
    hsp.SetHypPK(eLoss(&P4hyp,KAON_CHARGED_MASS,hsp.GetVertex3(),ELOSS_TARG_LH2,ELOSS_CELL_g8b)->P());
    //Corrected momentum if electron	
    hsp.SetHypPElGam(eLoss(&P4hyp,ELECTRON_MASS,hsp.GetVertex3(),ELOSS_TARG_LH2,ELOSS_CELL_g8b)->P());
  }
  else{ //neutron or gamma
    
    
  }		

    hsp.SetDetector(sector);

    fParticles.push_back(hsp);
 
}
Bool_t THSCLASg8::MakeBeam(Float_t Tmid,Float_t Tcut){
  // cout<<"tagger "<< TAGR_NH<<endl;
 //Find a photon within a Tcut window of Tmid  
  //and throw away events with more than one photon
  if(!TAGR_NH) return kFALSE;
  
  Double_t Egamma=0;
  HS::THSParticle* fHSgamma=0;
  for(Int_t im=0;im<TAGR_NH;im++) {
  if((TAGR[im].TPHO)<40&&(TAGR[im].TPHO)>0){
      if((TAGR[im].STAT!=15)&&(TAGR[im].STAT!=7)) continue; //check good photon 	
      HS::THSParticle hsp(-22);
      Egamma=TAGR[im].ERG;
      hsp.SetXYZT(0,0,Egamma,Egamma);
      hsp.SetTime(TAGR[im].TPHO);//TPHO=TRF+zcentre/c
      hsp.SetPath(0); //already at centre
      hsp.SetDetector(-1);
      //LinPol
      // if (fCurrentPlane == 0) hsp.SetVertex(GetLinPol(0, fCurrentEdge, Egamma*1000., 8, 0.2, 0.3),0,0);
      // else if (fCurrentPlane == 1) hsp.SetVertex(0,GetLinPol(1, fCurrentEdge, Egamma*1000., 8, 0.2, 0.3),0);
      // else  fHSgamma->SetVertex(0,0,0);
       //LinPol
      if(fEgSetting){
      GetEdge(HEAD[0].NEVENT); //get the current edge position
      if (fCurrentPlane == 0) hsp.SetVertex(GetPol(im),0,0);
      else if (fCurrentPlane == 1) hsp.SetVertex(0,GetPol(im),0);
     //cout<<" B "<<hsp.Vertex().X()<<" "<<hsp.Vertex().Y()<<" "<<hsp.Vertex().Z()<<endl;
      }
      fParticles.push_back(hsp);	
    }
  }
 
  return kTRUE; 
}
void THSCLASg8::MakeTruth(){
   for(Int_t ip=0;ip<MCTK_NH[0];ip++){//sort pi-
    MakeTruthParticle(ip);
  } 
}
void THSCLASg8::MakeTruthParticle(Int_t ip){
 
  HS::THSParticle hsp;	
  hsp.SetPDGcode(MCTK[0][ip].id);
  hsp.SetXYZM(MCTK[0][ip].cx*MCTK[0][ip].pmom,MCTK[0][ip].cy*MCTK[0][ip].pmom,MCTK[0][ip].cz*MCTK[0][ip].pmom,MCTK[0][ip].mass);
  hsp.SetVertex(MCVX[ip].x,MCVX[ip].y,MCVX[ip].z);
  fGenerated.push_back(hsp);
}
Int_t THSCLASg8::EPICSEvent(){
  //int nEpicEvent=0;               //Counter for EPICs events
  //  int current_plane=0;            //Stor value of coherent plane
  float plane;
  float epics;
 				         //for getting epics values
  Int_t currentRadiator=UNKNOWN;    	// current rad, plane - init these to UNKNOWN
  fCurrentPlane=UNKNOWN;

  // getEpics(TString("coh_plane").Data(),&plane);
   getEpics("coh_plane",&plane);
  
  getEpics("coh_radiator", &epics);	    	     //Get the radiator
  currentRadiator=(int)epics;	
  //cout<<"epics rad "<<currentRadiator<<endl;
  if((int)currentRadiator==AMORPHOUS){	     //If amorph, set plane to amo
    fCurrentPlane=AMO;
    //LinPol->SetXYZ(0,0,0);
    return 0;
  }
  else if(currentRadiator==DIAMOND){	   	//If diamond, read plane from epics
    getEpics("coh_plane",&epics);
    fCurrentPlane=(int)epics;
    getEpics("coh_edge",&fCurrentEdge);
    cout<<"epics diamond "<<fCurrentEdge<<" "<<fCurrentPlane<<endl;
    return 0;
  }	
  
  else return -1;
}

void THSCLASg8::LoadPolarisations(){
  cout<<"THSCLASg8::LoadPolarisations() "<<fEgSetting<<endl;
  // Polarization
  // Settings based on commandline argument (EgSetting) for energy setting...
  //These need to be changed for each coherent peak position
  //Eg low should be coh peak - 0.4
  //Eg High should be coh peak + 0.05
  //	add links to updated polarization tables here...
  //char *paraPolTable=nullptr;
  //char *perpPolTable=nullptr;

  TString paraPolTable;
  TString perpPolTable;
  
  switch(fEgSetting){
  case 1300:
      //EgLow = 0.9;
      //EgHigh = 1.35;
      //meanPolFileName="/home/clasg8/rootbeer2.1/poltabs/manual_1.3_runs_meanpol.dat";
      paraPolTable="/home/clasg8/rootbeer2.1/poltabs/PolTables_1.3_Manual_PARA.dat";
      perpPolTable="/home/clasg8/rootbeer2.1/poltabs/PolTables_1.3_Manual_PERP.dat";
      
      break;
  case 1500:
      //EgLow = 1.1;
      //EgHigh = 1.55;
      //meanPolFileName="/home/clasg8/rootbeer2.1/poltabs/total_1.5_runs_meanpol.dat";
      paraPolTable="/home/clasg8/rootbeer2.1/poltabs/PolTables_1.5_Manual_PARA.dat";
      perpPolTable="/home/clasg8/rootbeer2.1/poltabs/PolTables_1.5_Manual_PERP.dat";
      break;
  case 1700: //manual
      //EgLow = 1.3;
      //EgHigh = 1.75;
      //meanPolFileName="/home/clasg8/rootbeer2.1/poltabs/total_1.7_runs_meanpol.dat";
      paraPolTable="/home/clasg8/rootbeer2.1/poltabs/PolTables_1.7_Manual_PARA.dat";
      perpPolTable="/home/clasg8/rootbeer2.1/poltabs/PolTables_1.7_Manual_PERP.dat";
      break;
  case 1701: //auto
      //EgLow = 1.3;
      //EgHigh = 1.75;
      //meanPolFileName="/home/clasg8/rootbeer2.1/poltabs/total_1.7_runs_meanpol.dat";
      paraPolTable="/home/clasg8/rootbeer2.1/poltabs/PolTables_1.7_Auto_PARA.dat";
      perpPolTable="/home/clasg8/rootbeer2.1/poltabs/PolTables_1.7_Auto_PERP.dat";
      currentMode=SWAP;
      break;
  case 1900:
      //EgLow = 1.5;
      //EgHigh = 1.95;
      //meanPolFileName="/home/clasg8/rootbeer2.1/poltabs/auto_1.9_runs_meanpol.dat";
      paraPolTable="/home/clasg8/rootbeer2.1/poltabs/PolTables_1.9_Auto_PARA.dat";
      perpPolTable="/home/clasg8/rootbeer2.1/poltabs/PolTables_1.9_Auto_PERP.dat";
      currentMode=SWAP;
      break;
  case 2100:
      //EgLow = 1.7;
      //EgHigh = 2.15;
      //meanPolFileName="/home/clasg8/rootbeer2.1/poltabs/manual_2.1_runs_meanpol.dat";
      paraPolTable="/home/clasg8/rootbeer2.1/poltabs/PolTables_2.1_Manual_PARA.dat";
      perpPolTable="/home/clasg8/rootbeer2.1/poltabs/PolTables_2.1_Manual_PERP.dat";
      break;
  default:
      //EgLow = 0.0;
      //EgHigh = 0.0;
      cerr << "Fatal Error: Unknown value on energy_setting " <<  fEgSetting << endl;

      break;
  }  

  // Load the polarization tables
  LoadPolTable(PARA,paraPolTable.Data() );
  LoadPolTable(PERP,perpPolTable.Data() );
  //  if((LoadPolTable(PARA,paraPolTable.Data() ))!=0) return;
  //if((LoadPolTable(PERP,perpPolTable.Data() ))!=0) return;
}
Double_t THSCLASg8::polFix0(Double_t xE, Int_t plane, Int_t parSet){
  Double_t ldPar[6][2][2]={
    //For 1.3 Manual: (PARA0,PARA1, PERP0,PERP1)
    1.004337,  -.4986358E-02, 1.009058,  -.5687501E-02,
  //For 1.5 Manual:
    1.012704,  -.3850369E-02, 1.002215,  -.2256782E-02,
    //For 1.7 Manual:
    0.9888860, -.2256782E-02, 0.9924032, -.3019766E-02,
    //For 2.1 Manual:
    1.004469,  -.2188895E-01, 1.067167,  -.1876592E-01,
    //For 1.7 Auto:
  0.9844326, 0.7438295E-03, 1.032343,  -.1255454E-01,
    //For 1.9 Auto:
    1.008734,  -.1557868E-02, 0.9865551,  0.2070320E-02,
  }; 
  Double_t diffFix = 0.135;
  Double_t width = 0.2;
  Double_t yVal=0.0;
  Double_t tmpFun=1.0;
  Int_t region=-1;
  Double_t pF=-1.0;
  
  region=(int)(8.0*(xE)/width); //region 0-8
  
  yVal = (1.0/0.025)*xE-0.5;
  
  tmpFun = 1.0;
  if(region>=1){
    for(int r=1;r<=region;r++){
      tmpFun = tmpFun*(ldPar[parSet][plane][0] + ldPar[parSet][plane][1]*yVal);
      yVal = yVal - 1.0;
    }
  }
  pF = tmpFun;
  if (tmpFun==0.0) pF = 1.0;
  return pF;
}
// Polarization

Int_t THSCLASg8::LoadPolTable(int plane, const Char_t *PolTableList){
  FILE *fplist=nullptr;
  FILE *fpfile=nullptr;              //file pointers for filelist and each file therein
  Char_t lline[250];                 //for reading in lines from filelist
  Char_t fline[250];                 //for reading in lines from file
  Char_t filename[250];              //file
  Int_t  fcount=0;                   //counter for no of files read in
  Int_t  chancount=0;                //counter for no of channels read in
  Int_t  eid=0;
  Double_t edge=0.0;                 
  
  if((fplist=fopen(PolTableList,"r"))==NULL){ //open filelist
    cerr << "Error Couldn't open file: " << PolTableList << endl;
    return -1;
  }

  fpolTableN[0]=0;
  fpolTableN[1]=0;
  //for each file in the list
  while(fgets(lline,240,fplist) != NULL){
    if((lline[0] == '*')||(lline[0] == '#')) continue; //skip comments
    sscanf(lline,"%s",filename);                       //read in filename
    
    //  cout << "opening " << filename << "   " << endl;
    if((fpfile=fopen(filename,"r"))==NULL){              //open file
      cerr << "Error Couldn't open file: " << filename << endl;
      return -1;
    }	
        
    fgets(fpolFirstLines[plane][fpolTableN[plane]],240,fpfile ); //save the 1st line	
    
    //scan the bit after the last "_" in the filename to get the edge energy
    sscanf(strrchr(filename,'_')+1,"%lg",&fpolTable[plane][fcount][0][EDGE]);
    
    chancount=0;                                             //starting array at 1 for consistency with E_ID
    while((fgets(fline,240,fpfile)) != NULL){
      if((fline[0] == '*')||(fline[0] == '#')) continue;     //skip comments    
      sscanf(fline,"%d",&eid);                               //first get the E_ID	
      sscanf(fline,"%*d%lg%lg%lg%lg%lg%lg%lg%lg",
	     &fpolTable[plane][fcount][eid][ENERGY],
	     &fpolTable[plane][fcount][eid][ENH],
	     &fpolTable[plane][fcount][eid][ENHERR],
	     &fpolTable[plane][fcount][eid][ENHFIT],
	     &fpolTable[plane][fcount][eid][PFIT],
	     &fpolTable[plane][fcount][eid][PCOR],
	     &fpolTable[plane][fcount][eid][PCORERR],
	     &fpolTable[plane][fcount][eid][PSMOOTH]);
      chancount++; 
    }
    fclose(fpfile); //close the file
    if(chancount!=384){
      cerr << "Should be 384 lines in " << filename << " - only got " << chancount << endl;
      return -1;
    }
    fpolTableN[plane]++;
    
    fcount++;
  }

  fclose(fplist);

  return(0);
}

Double_t THSCLASg8::GetPol(Int_t plane, Double_t edge, Int_t eid, Int_t poltype = PSMOOTH, Double_t lowThresh=0.2, Double_t highThresh=0.3){
  //get polarization based on eid and edge position
  //cout<<"Get Pol 1"<<endl; 
  Int_t eIndex=0;
  Double_t pol=-1.0;
  //cout<<plane<<" "<<edge<<" "<<eid<<" "<<poltype<<" "<<EDGE<<endl;
  //cout<<fpolTableN[plane]-1<<endl;
   //Check edge in in range of tables
  if(fpolTableN[plane]==0)return 0;
  //cout<<"check "<<edge<<" "<<fpolTable[plane][1][0][EDGE]<<" "<<fpolTable[plane][fpolTableN[plane]-1][0][EDGE]<<endl;
 if((edge<fpolTable[plane][1][0][EDGE])||(edge>fpolTable[plane][fpolTableN[plane]-1][0][EDGE])) return -1.0;
  
  //cout << "In range" << endl;

  //find index
  for(eIndex=0;eIndex<fpolTableN[plane];eIndex++){
    if(fpolTable[plane][eIndex][0][EDGE]>=edge) break;
  }
  //cout << "Index = " << eIndex << " "<<fpolTable[plane][eIndex][eid][poltype]<<endl;

  pol=fpolTable[plane][eIndex][eid][poltype];
  if((fpolTable[plane][eIndex][0][ENERGY]<edge)&&(pol<lowThresh)) pol = -1.0;
  if((fpolTable[plane][eIndex][0][ENERGY]>edge)&&(pol<highThresh)) pol = -1.0;

  return pol;
}



Double_t THSCLASg8:: GetPol(Int_t plane, Double_t edge, Double_t eg, Int_t poltype = PSMOOTH, Double_t lowThresh=0.2, Double_t highThresh=0.3){
  //get polarization based on ephoton energy and edge position
  //cout<<"Get Pol 2"<<endl; 
 
  Int_t eIndex=0;
  Double_t pol=-1.0;
  Int_t eid=0;
  //cout<<"check "<<edge<<" "<<fpolTable[plane][1][0][EDGE]<<" "<<fpolTable[plane][fpolTableN[plane]-1][0][EDGE]<<endl;

  //Check edge in range of tables
  if((edge<fpolTable[plane][1][0][EDGE])||(edge>fpolTable[plane][fpolTableN[plane]-1][0][EDGE])) return -1.0;


  //find index
  for(int eIndex=0;eIndex<fpolTableN[plane];eIndex++){
    if(fpolTable[plane][eIndex][0][EDGE]>=edge) break;
  }
  //cout << "Index = " << eIndex << endl;

  //find eid
  for(eid=1;eid<=384;eid++){
    if(fpolTable[plane][eIndex][eid][ENERGY]<=eg) break;
  }
  //cout << "eid = " << eid <<endl;

  pol=fpolTable[plane][eIndex][eid][poltype];
  if((fpolTable[plane][eIndex][0][ENERGY]<edge)&&(pol<lowThresh)) pol = -1.0;
  if((fpolTable[plane][eIndex][0][ENERGY]>edge)&&(pol<highThresh)) pol = -1.0;

  return pol;
}

Int_t  THSCLASg8::LoadEdgeTable(Char_t *EdgeTable){
  FILE *fpfile=nullptr;                      //file pointers for filelist and each file therein
  Char_t fline[250];                 //for reading in lines from file

  cout << "opening " << EdgeTable << "   " << endl;
  edgeEventN=0;                      //initialize the counter
  edgeIndex=0;                       //and index for current table
  lastEdgeEvent=0;                   //etc
  lastCohEdge=0.0;
  lastCohPlane=-1;
  if((fpfile=fopen(EdgeTable,"r"))==NULL){              //open file
    cerr << "Error Couldn't open file: " << EdgeTable << endl;
    return -1;
  }


   
  while((fgets(fline,240,fpfile)) != NULL){
    if((fline[0] == '*')||(fline[0] == '#')) continue;     //skip comments
    sscanf(fline,"%d%d%lg%d",        //scan in the tables
	   &edgeEventLow[edgeEventN],
	   &edgeEventHigh[edgeEventN],
	   &edgeEventEdge[edgeEventN],
	   &edgeEventPlane[edgeEventN]);
    edgeEventN++;                    //inc the counter fo the no of lines in the table
  }
  fclose(fpfile);
  return 0;
}


Int_t THSCLASg8::GetEdge(Int_t event){

  //check event no >= previous event
  
  if(event<lastEdgeEvent){
    cerr << "Warning: event (= " << event << ") is earlier than previous event (= " <<  lastEdgeEvent << ") - ignoring" << endl;
    return -1;
  }
  lastEdgeEvent=event;

  //keep going until we're in range or don't find a range 
  while((!((event >= edgeEventLow[edgeIndex])&&(event <= edgeEventHigh[edgeIndex])))&&(edgeIndex<edgeEventN)){edgeIndex++;}
  if(edgeIndex>=edgeEventN){
    //cerr << "Error: event (= " << event << ") is not in the range of this table" << endl;    
    edgeIndex=0; //reset to zero
    return -1;
  }
  fCurrentEdge = edgeEventEdge[edgeIndex];
  fCurrentPlane = edgeEventPlane[edgeIndex];
  return 0;
}

Double_t THSCLASg8::mikeTest(Double_t pol, Double_t egamma, Double_t cohEdge, Int_t Plane, Int_t setting){
  //where pol is from lookup tables
  //egamma = photon energy in MeV
  //cohEdge = current coherent edge pos
  //plane = PARA (0), PERP (1)
  //setting = 1300,1500,1700,1701,1900,2100  (1701 = 1700 auto)

  Int_t paramSet=-1;
  Double_t eDiff=0.0;
  Double_t pF=1.0;
  Double_t norm=0.0;
  Double_t diffFix = 0.135;
  Double_t width = 0.2;

  eDiff=(cohEdge-egamma)/1000.0;
  if((eDiff>width)||(eDiff<0.0)) return -1; //return if outwith width

  //get the param set from the setting

  switch(setting){
  case 1300:
    paramSet=0;
    break;
  case 1500:
    paramSet=1;
    break;
  case 1700:
    paramSet=2;
    break;
  case 2100:
    paramSet=3;
    break;
  case 1701:
    paramSet=4;
    break;
  case 1900:
    paramSet=5;
    break;
  default:
    cerr << "Fatal Error: Unknown value on energy_setting " <<  setting << endl;
    return -1.0;
    break;
  }
  
  
  pF=polFix0(eDiff,Plane,paramSet);
  norm=polFix0(diffFix,Plane,paramSet);
  pF /= norm;
  if (pF>0.0) pF=pol/pF;
  else pF=pol;
  
  return pF;
}
Float_t THSCLASg8::GetPol(Int_t iphot){
  Float_t polDegree=0;
  Double_t polLeft=0.0; //Ken2 may alread be set like this - not sure
  Double_t polRight=0.0; //Ken2
  Double_t ELeft=200.0;
  Double_t ERight=0.0;

  //Extract the photon polarization information
  //Nothing in the photon pol stops the event going into the tree for likelihood, or other analysis.
  //However, if the photon pol does not meet the following criteria it is flagged as 99.9.
  //To fill histograms like phi distribs, where they will be fitted later, and mean polarizations used, 
    
  if(((fCurrentPlane==PARA)||(fCurrentPlane==PERP))&&
     ((fCurrentEdge>0.0)&&(1000.0*TAGR[iphot].ERG >fCurrentEdge-ELeft)&&(1000.0*TAGR[iphot].ERG<fCurrentEdge+ERight))){       
    //	polDegree=GetPol(fCurrentPlane,fCurrentEdge,(int)((TAGR[bestPhoton].E_id+0.5)/2.0),PSMOOTH,0.2,0.3);
    polDegree=GetPol(fCurrentPlane,fCurrentEdge,(int)((TAGR[iphot].E_id+1.0)/2.0));
    //polDegreeOrig=GetPol(fCurrentPlane,fCurrentEdge,(int)((TAGR[iphot].E_id+1.0)/2.0));      
      
    //Now use Mikes correction (but not for 2.1)
    if (fEgSetting!=2100) {
      polDegree=mikeTest(polDegree,1000.0*TAGR[iphot].ERG,fCurrentEdge,fCurrentPlane,fEgSetting);  //Ken2
    }
  }
  //cout<<"pol "<<1000.0*TAGR[iphot].ERG<<" "<<polDegree<<endl;
  return polDegree;
}
