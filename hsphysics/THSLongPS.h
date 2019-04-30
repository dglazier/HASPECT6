//--Author      DI Glazier 25/01/2015
//--Rev
//--Update      Peter Pauli 26/03/2018
//--Description
//-- University of Glasgow
//HASPECT Event Reconstruction
//THSLongPS
//Class to perform general Longitudinal Phasespace Analysis

#ifndef THSLongPS_h
#define THSLongPS_h
#include <TLorentzVector.h>
#include <TString.h>
#include <vector>
#include <iostream>
#include <algorithm>

class THSLongPS {
 protected :
  Int_t fNpart;  //Number of particles in final state
  vector<TLorentzVector> fP4s; //vector of CM 4 vectors
  
  vector< vector<Bool_t> > fIsForward;      //Which particles are going forward
  UInt_t fSector; //which longitudnal region is this event in
  UInt_t fNSector; //number of  longitudnal regions
  vector<TString> fSectName; //vector of names corresponding to fSector
  vector< vector<Int_t> > fITop; //indices of particles in top branch for each sector
  vector< vector<Int_t> > fIBot; //indices of particles in top branch
  TLorentzVector fCM; //CM 4 vector = sum of fP4s; 
  Float_t fMTop; //Mass of particle on top branch
  Float_t fMBot; //Mass pf particles on bottom branch
  Float_t fCosTh; //Cos centre of mass angle
  Float_t fPtot;
  Int_t fSize;//number of 4 vectors loaded for this event

  Float_t fOmegaCut[2];
 public :
  THSLongPS(){};
  THSLongPS(Int_t Np);
  virtual ~THSLongPS(){};
  
  void AddParticle(TLorentzVector p4);//add 4 vectos should be done for each particle for each event
  void Reset(){fSize=0;fCM.SetXYZT(0,0,0,0);fPtot=0;}
  void Analyse(); // do the kinematics and find the current sector
  void AnalyseCMHelicity(TLorentzVector *zLV);
  double breakupMomentum( double mass0, double mass1, double mass2 );
  double BetaPM(double p0, double m0);
  TLorentzVector GetP4(Int_t ip){return fP4s[ip];}
  Float_t GetPL(Int_t ip){return fP4s[ip].Z();};
  Float_t GetPLT(){return fPtot;};
  Float_t GetOmega();
  Float_t GetOmegaDG();
  Float_t GetOmegaCut(Int_t ii){return fOmegaCut[ii];}
  Float_t GetTopMass(){return fMTop;};
  Float_t GetBotMass(){return fMBot;};
  Float_t GetCosTh(){return fCosTh;};
  Int_t GetSector(){return fSector;};
  Int_t GetNSector(){return fNSector;};
  TString GetSectName(Int_t in){return fSectName[in];}
  void MakeIndices(Int_t Np,Int_t Nt);
  void PrintVector(vector<Int_t> );
  void PrintVector(vector<Bool_t> );
};

#endif
