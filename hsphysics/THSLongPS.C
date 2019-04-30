//--Author      DI Glazier 25/01/2015
//--Rev
//--Update      Peter Pauli 26/03/2018
//--Description
//-- University of Glasgow
//HASPECT Event Reconstruction
//THSLongPS

/**
 *	\class THSLongPS
 *	
 *	Class to perform general Longitudinal Phasespace Analysis
 *	
 *	
 *	Usage example: \n
 * 
 *	// create LongPS object \n
 *	THSLongPS *fLPS = new THSLongPS(3); \n
 *	// in event loop do: \n
 *	fLPS->Reset(); \n
 *	fLPS->AddParticle(Proton_P4); // add TLorentzVector \n
 *	fLPS->AddParticle(KMinus_P4); \n 
 *	fLPS->AddParticle(KPlus_P4); \n
 *	fLPS->Analyse(); \n
 *	cout << fLPS->GetSector() << endl;
*/

#include "THSLongPS.h"
#include <TLorentzRotation.h>

THSLongPS::THSLongPS(Int_t Np){
  //PARTICLE 0 SHOULD BE BARYON!
  fNpart=Np;
  fP4s.reserve(fNpart);
  fCM.SetXYZT(0,0,0,0);
  fSector=0;
  fSize=0;
  //fSectName.reserve(Nsector);
   for(Int_t i=1;i<fNpart;i++){//loop over numbers at top,bottom vertex (1->fNpart-1) must always have at least 1 on top and bottom!!
    //increment the sector number
    Int_t NT=fNpart-i; //number of particles on top 
    Int_t NB=fNpart-NT;  //number of particles on bottom
    MakeIndices(Np,NT);  //make vectors with Top and Botton particle indices
 
   }//end topologies

  cout<<"For "<<Np <<"  particles there are "<<fSector<< "valid sectors"<<endl; 
  fNSector=fSector;
  fSector=0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
///Makes all combinations of particles on top and bottom branches. \n
///Np = number of particles, Nt = number of particles top \n
///Saves in vectors fITop and fIBot,
///index of these vectors corresponds to unique Sector number. \n
///Note number of combinations choosing Nt from Np and ignoring order : \n
/// Number = Np!/(Np-Nt)!/Nt! or TMath::Factorial(N)/TMath::Factorial(N-K)/TMath::Factorial(K)
void THSLongPS::MakeIndices(Int_t Np,Int_t Nt){
  vector<Int_t> donethis;//use to reject equivalnet permutations (not ordering)
  vector<Int_t >IP(Np); //vector containing particle numbers from 0->Np
  for(Int_t i=0;i<Np;i++)IP[i]=i; 
  vector<TString> sPart(Np);
  for(Int_t isp=0;isp<Np;isp++)sPart[isp].Form("%d",isp);//A number for each particle
  
  vector<Int_t>::iterator ite = IP.begin(); 
  do{//loop over all possible combinations
    vector<Int_t> sub(&IP[0],&IP[Nt]); //make a new vector length Nt with this permutation
    std::sort(sub.begin(),sub.end()); //order the vector (ignore permutation order)
    if(!(std::find(fITop.begin(), fITop.end(), sub) != fITop.end())){
      fITop.push_back(sub); //If these particles already used for top then do not save
      vector<Int_t> subB(&IP[Nt],&IP[Np]); 
      fIBot.push_back(subB);
    fSectName.push_back("F_");
    //   sBot.Clear();
    vector<Bool_t> isFor(Np);
    for(Int_t isp=0;isp<Nt;isp++){
      fSectName[fSector]+=sPart[fITop[fSector][isp]]+"_";//make name
      isFor[fITop[fSector][isp]]=kTRUE;//make sector condition
    }
    fSectName[fSector]+="B_";
    for(Int_t isp=0;isp<Np-Nt;isp++){
      fSectName[fSector]+=sPart[fIBot[fSector][isp]]+"_";
      isFor[fIBot[fSector][isp]]=kFALSE;//make sector condition
    }
    fIsForward.push_back(isFor);
    cout<<"Sector NAme "<<fSector<<" "<<fSectName[fSector]<<endl;
     fSector++;
    }
 }while(std::next_permutation(ite,ite+Np));

 }

void THSLongPS::PrintVector(vector<Int_t> vecI){
  for(UInt_t i=0;i<vecI.size();i++)cout<<vecI[i]<<" ";
  cout<<endl;
}

void THSLongPS::PrintVector(vector<Bool_t> vecI){
  for(UInt_t i=0;i<vecI.size();i++)cout<<vecI[i]<<" ";
  cout<<endl;
}

//////////////////////////////////////////////////////////////////
///Add 4 vectors: should be done for each particle for each event. \n
///Particle 0 must be baryon.
void THSLongPS::AddParticle(TLorentzVector p4){
  if(fSize<fNpart){
    fP4s[fSize++]=p4;
    fCM+=p4;
  }
}

///////////////////////////////////////////
///Analyse in centre-of-mass helicity frame
void THSLongPS::AnalyseCMHelicity(TLorentzVector *zLV){
  TLorentzVector zVec=(*zLV);
  fCM+=zVec;
  TVector3 CMboost=-fCM.BoostVector();
  zVec.Boost(CMboost);
  TVector3 zCM=-zVec.Vect().Unit();
  TVector3 yCM=CMboost.Cross(zVec.Vect()).Unit();
  TVector3 xCM=yCM.Cross(zCM).Unit();
  fPtot=0;//total longitudinal momentum
  vector< Bool_t > whichForward(fSize); //whichForward[2]=kTRUE means particle 2 is going forward
  for(Int_t ip=0;ip<fSize;ip++){
    fP4s[ip].Boost(CMboost); //cm boost
    TVector3 p3CM(fP4s[ip].Vect().Dot(xCM),fP4s[ip].Vect().Dot(yCM),fP4s[ip].Vect().Dot(zCM));
    whichForward[ip]=p3CM.Z()>0;
    fPtot+=p3CM.Z()*p3CM.Z();
  }
  fPtot=zVec.Rho();
  fCosTh=-TMath::Cos(fCM.Angle(zVec.Vect()));
  TLorentzVector p4boost(fP4s[0]+fP4s[1]);
  p4boost.SetTheta(0);
  TVector3 boostIso=p4boost.BoostVector();

  Double_t B12=breakupMomentum((fP4s[0]+fP4s[1]).M(),fP4s[0].M(),fP4s[1].M());
  Float_t fPmin[2];
  Float_t fPmax[2];
  TLorentzVector pmin(0,0,-B12,sqrt(B12*B12+fP4s[1].M2())); //backward in helcity frame
  pmin.Boost(boostIso);//boost along helicity z axis to CM
  fPmin[1]=pmin.Z(); //minium longitudinal momentum allowed for isobar
  pmin=TLorentzVector(0,0,-B12,sqrt(B12*B12+fP4s[0].M2())); //backward in helcity frame
  pmin.Boost(boostIso);//boost along helicity z axis to CM
  fPmin[0]=pmin.Z(); //minium longitudinal momentum allowed for isobar
  
  pmin=TLorentzVector(0,0,B12,sqrt(B12*B12+fP4s[1].M2())); //backward in helcity frame
  pmin.Boost(boostIso);//boost along helicity z axis to CM
  fPmax[1]=pmin.Z(); //minium longitudinal momentum allowed for isobar
  pmin=TLorentzVector(0,0,B12,sqrt(B12*B12+fP4s[0].M2())); //backward in helcity frame
  pmin.Boost(boostIso);//boost along helicity z axis to CM
  fPmax[0]=pmin.Z(); //minium longitudinal momentum allowed for isobar

  for(fSector=0;fSector<fNSector;fSector++)
    if(fIsForward[fSector]==whichForward) break;
  
  if(fCosTh>0){
  fOmegaCut[0]=TMath::ATan2(fPmin[0],fPmax[1]);
  fOmegaCut[1]=TMath::ATan2(fPmax[0],fPmin[1]);
  }
  else{
  fOmegaCut[1]=TMath::ATan2(-fPmax[0],-fPmin[1]);
  fOmegaCut[0]=TMath::ATan2(-fPmin[0],-fPmax[1]);
  }
}

double THSLongPS::BetaPM(double p0, double m0){
  //Warning return -ve if p0<0 
 //beta =p/E
  return p0/sqrt(p0*p0+m0*m0);
}

double THSLongPS::breakupMomentum( double mass0, double mass1, double mass2 ){
   
  double q;
  
  // fabs -- correct?  consistent w/ previous E852 code
  q = sqrt( fabs(   mass0*mass0*mass0*mass0 + 
                    mass1*mass1*mass1*mass1 +
                    mass2*mass2*mass2*mass2 -
                    2.0*mass0*mass0*mass1*mass1 -
                    2.0*mass0*mass0*mass2*mass2 -
                    2.0*mass1*mass1*mass2*mass2  ) ) / (2.0 * mass0);
  
  return q;
  
}

///////////////////////////////////////////////////
///Do the kinematics and find the current sector
void THSLongPS::Analyse(){
   //Construct the CM boosts
   TVector3 CMboost=-fCM.BoostVector();
   TLorentzRotation CMRot(CMboost);
 
  //loop over particles and check if they are going forward in CM
  vector< Bool_t > whichForward(fSize); //whichForward[2]=kTRUE means particle 2 is going forward
  fPtot=0;//total longitudinal momentum
  for(Int_t ip=0;ip<fSize;ip++){
    fP4s[ip]=(CMRot*(fP4s[ip])); //cm boost
    whichForward[ip]=fP4s[ip].Z()>0;
    fPtot+=fP4s[ip].Z()*fP4s[ip].Z();
  }
  fPtot=TMath::Sqrt(fPtot);

  for(fSector=0;fSector<fNSector;fSector++)
    if(fIsForward[fSector]==whichForward) break;
  
  //Now calculate masses of Top and Bottom particles
  TLorentzVector pTop;
  for(UInt_t ip=0;ip<fITop[fSector].size();ip++) pTop+=fP4s[fITop[fSector][ip]];
  fMTop=pTop.M();
  fCosTh=pTop.CosTheta();

  TLorentzVector pBot;
  for(UInt_t ip=0;ip<fIBot[fSector].size();ip++) pBot+=fP4s[fIBot[fSector][ip]];
  fMBot=pBot.M();
}

Float_t THSLongPS::GetOmegaDG(){
  if(fSize==2) return TMath::ATan2(fP4s[0].Z(),fP4s[1].Z());
  else return 0;
}

Float_t THSLongPS::GetOmega(){

  //Omega only properly defined for 3 particles
  Float_t Omega=asin(fP4s[0].Z()/fPtot/sqrt(2./3));
 
  if(fP4s[1].Z()>0&&fP4s[2].Z()<0) Omega=TMath::Pi()-Omega;
  else if(fP4s[1].Z()<0&&fP4s[2].Z()<0&&fP4s[2].Z()<fP4s[1].Z())  Omega=TMath::Pi()-Omega;
  else if(fP4s[1].Z()>0&&fP4s[2].Z()>0&&fP4s[2].Z()<fP4s[1].Z())  Omega=TMath::Pi()-Omega;
  else if(fP4s[0].Z()<0) Omega=2*TMath::Pi()+Omega;
 
  return Omega;
}
