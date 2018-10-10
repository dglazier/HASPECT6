/**
	\class THSParticle

	Class responsible for handling event particle information.
	THSDataManager uses a vector<THSParticle> as it main data.
	Data members are used to hold information from different detectors
	while functions provide additional derived information.

	For performance reasons this class utilises the TMath Gen Vector
	(https://root.cern.ch/doc/v608/Vector.html) 
	rather than the more common TLorentzVector. This halves
	the disk space as it is saved as float in file as well as being
	somewhat faster.

	As well as measured 4-vectors and vertices, in the case of simulated 
	events THSParticle can also keep the truth (generated values).
	This can supply resolution information as well as being of use
	in ToyMC type studies.

	Example of caluclating a missing mass

	    HSLorentzVector miss=fBeam+fTarget-fElectron.P4()-fProton.P4()-fPip.P4()-fPim.P4();

	Here fBeam, fTarget are HSLorentzVectors, while fElectron, fProton, 
	fPip and fPim are THSParticles which are having their 
	4-vectors accessed via P4()
*/



//--Author      DI Glazier 23/03/2018
//--Rev
//--Update
//--Description
//HASPECT Event Reconstruction
//THSParticle
//Optimsed Persistant Data structure
//Contains reconstructed information required for data analysis

#include <iostream>
#include "THSParticle.h"

ClassImp(THSParticle);

// THSParticle::THSParticle() {
// }
THSParticle::THSParticle(int code) {
  SetPDGcode(code);

}
THSParticle::THSParticle(TString pdgname){
  SetPDGcode(TDatabasePDG::Instance()->GetParticle(pdgname)->PdgCode());
}
void THSParticle::Print(Option_t *) const{
  cout<<"Printing THSParticle of type "<<TDatabasePDG::Instance()->GetParticle(fPDGCode)->GetName()<<endl;
  // fP4.Print("");
  //fVertex.Print("");
}
void THSParticle::CopyParticle(THSParticle* part,Bool_t andPDG){
  SetP4(part->P4());
  SetVertex(part->Vertex());
  SetMeasMass(part->MeasMass());
  SetTime(part->Time());
  SetPath(part->Path());
  SetDoca(part->Doca());
  SetEdep(part->Edep());
  SetDeltaE(part->DeltaE());
  SetPreE(part->PreE());
  SetTrChi2(part->TrChi2());
  SetStatus(part->Status());
  if(andPDG) SetPDGcode(part->PDG());
  SetDetector(part->Detector());
}
void THSParticle::Add(THSParticle* hsp1, THSParticle* hsp2,Int_t pdg){
  //  SetVertex(hsp1->Vertex()+hsp2->Vertex()); //average vertex
  SetP4(hsp1->P4()+hsp2->P4());
  SetTime((hsp1->Time()+hsp2->Time())/2);//average time
  SetPDGcode(pdg);
  if(pdg){
    SetMeasMass(fP4.M());
    TakePDGMass();
  }
  // TVector3 vertex;
  // Double_t D=0;
  // fDoca=Calc_dtfDOCA(hsp1->Vertex(),hsp1->P4().Vect().Unit(),hsp2->Vertex(),hsp2->P4().Vect().Unit(),&vertex);
  // SetVertex(vertex);
  // //Truth Particle
  // if(hsp1->TruthP4p()->E()||hsp2->TruthP4p()->E()){
  //   Calc_dtfDOCA(*hsp1->TruthVer(),hsp1->TruthP4().Vect().Unit(),*hsp2->TruthVer(),hsp2->TruthP4().Vect().Unit(),&vertex);
  //   SetTruth(*hsp1->TruthP4p()+*hsp2->TruthP4p(),
  // 	     vertex,pdg);
  //   // if(pdg){
  //   //   SetMeasMass(fP4.M());
  //   //   TakePDGMass();
  //   // }
  // }
}	

// Double_t THSParticle::Calc_dtfDOCA( TVector3 locVertex1, TVector3 locUnitDir1, TVector3 locVertex2, TVector3 locUnitDir2, TVector3 *result){
//   //locVertex1= vertex position of track 1
//   //locUnitDir1 = unit veocity vector of track 1
//   //similar for 2 and result is calculated by this function
//   //Call function to calculate position of nearest approach for each track
//   //take the average position as the resulting vertex
//   //take the difference in position as the DOCA
//   TVector3 locInterDOCA1;
//   TVector3 locInterDOCA2; //The positions for each track
//   Calc_dtfInterDOCA(locUnitDir1, locUnitDir2, locVertex1, locVertex2, &locInterDOCA1, &locInterDOCA2);
//   *result=0.5*(locInterDOCA1+locInterDOCA2); //the resulting vertex
//   return (locInterDOCA1 - locInterDOCA2).Mag(); //the DOCA
// }

// void THSParticle::Calc_dtfInterDOCA( TVector3 locUnitDir1, TVector3 locUnitDir2, TVector3 locVertex1,  TVector3 locVertex2, TVector3 *locInterDOCA1, TVector3 *locInterDOCA2){
//   //originated from code by Jörn Langheinrich
//   //you can use this function to find the DOCA to a fixed point by calling this function with locUnitDir1 and 2 parallel, and the fixed vertex as locVertex2
//   double locUnitDot = locUnitDir1*locUnitDir2;
//   double locDenominator = locUnitDot*locUnitDot - 1.0; /// scalar product of directions
//   double locDistVertToInterDOCA1 = 0.0, locDistVertToInterDOCA2 = 0.0; //distance from vertex to DOCA point

//   if(fabs(locDenominator) < 1.0E-15) //parallel
//     locDistVertToInterDOCA1 = (locVertex2 - locVertex1)*(locUnitDir2)/locUnitDot; //the opposite
//   else{
//     double locA = (locVertex1 - locVertex2)*(locUnitDir1);
//     double locB = (locVertex1 - locVertex2)*(locUnitDir2);
//     locDistVertToInterDOCA1 = (locA - locUnitDot*locB)/locDenominator;
//     locDistVertToInterDOCA2 = (locUnitDot*locA - locB)/locDenominator;
//   }
//   *locInterDOCA1 = locVertex1 + locDistVertToInterDOCA1*(locUnitDir1); //intersection point between DOCA line and Kid 1
//   *locInterDOCA2 = locVertex2 + locDistVertToInterDOCA2*(locUnitDir2); //intersection point between DOCA line and Kid 2
// }

