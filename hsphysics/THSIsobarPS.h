//--Author      DI Glazier 20/05/2016
//--Rev
//--Update
//--Description
//HASPECT Event Reconstruction
//THSIsobarPS
//Class to perform general Longitudinal Phasespace Analysis

#ifndef THSIsobarPS_h
#define THSIsobarPS_h
#include <TLorentzVector.h>
#include <TString.h>
#include <vector>
#include <iostream>
#include <algorithm>

class THSIsobarPS {
 protected :
  UInt_t fSector; //which longitudnal region is this event in
  UInt_t fNSector; //number of  longitudnal regions
  Double_t fCosTh; //Cos centre of mass angle
  Double_t fCosHel; //Cos centre of mass angle
  Double_t fOmega;
 public :
  THSIsobarPS(){};
  THSIsobarPS(Int_t Np);
  virtual ~THSIsobarPS(){};
  
  Bool_t IsIsobar(TLorentzVector z0,TLorentzVector d1,TLorentzVector d2,TLorentzVector fixCM=TLorentzVector());
  Double_t breakupMomentum( double mass0, double mass1, double mass2 );
  Double_t BetaPM(double p0, double m0);
  Double_t GetOmega(){return fOmega;}
  Double_t GetCosTh(){return fCosTh;};
  Double_t GetCosHel(){return fCosHel;};
  Int_t GetSector(){return fSector;};
  Int_t GetNSector(){return fNSector;};
};

#endif
