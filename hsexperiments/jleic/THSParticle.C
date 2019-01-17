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

HS::THSParticle::THSParticle(int code) {
  if(!TDatabasePDG::Instance()->GetParticle(code))
    cout<<"THSParticle::THSParticle, sorry particle "<<code<<" does not exist in ROOT PDG table"<<endl;
  SetPDGcode(code);

}
HS::THSParticle::THSParticle(TString pdgname){
  if(!TDatabasePDG::Instance()->GetParticle(pdgname))
    cout<<"THSParticle::THSParticle, sorry particle "<<pdgname<<" does not exist in ROOT PDG table"<<endl;
  SetPDGcode(TDatabasePDG::Instance()->GetParticle(pdgname)->PdgCode());
}
void HS::THSParticle::Print(Option_t *) const{
  cout<<"Printing THSParticle of type "<<TDatabasePDG::Instance()->GetParticle(fPDGCode)->GetName()<<endl;
  // fP4.Print("");
  //fVertex.Print("");
}
void HS::THSParticle::CopyParticle(THSParticle* part,Bool_t andPDG){
  SetP4(part->P4());
  SetVertex(part->Vertex());
  SetMeasMass(part->MeasMass());
  if(andPDG) SetPDGcode(part->PDG());
 }
void HS::THSParticle::Add(THSParticle* hsp1, THSParticle* hsp2,Int_t pdg){
  //  SetVertex(hsp1->Vertex()+hsp2->Vertex()); //average vertex
  SetP4(hsp1->P4()+hsp2->P4());
  SetPDGcode(pdg);
  if(pdg){
    SetMeasMass(fP4.M());
    TakePDGMass();
  }
 
}	
