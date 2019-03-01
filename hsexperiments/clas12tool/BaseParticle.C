/**
	\class BaseParticle

	Class responsible for handling event particle information.
	Applications dirive there own THSParticle class form this
	THSDataManager uses a vector<THSParticle> as it main data.
	Data members are used to hold information from different detectors
	while functions provide additional derived information.

	For performance reasons this class utilises the TMath Gen Vector
	(https://root.cern.ch/doc/v608/Vector.html) 
	rather than the more common TLorentzVector. This halves
	the disk space as it is saved as float in file as well as being
	somewhat faster.

	As well as measured 4-vectors and vertices, in the case of simulated 
	events BaseParticle can also keep the truth (generated values).
	This can supply resolution information as well as being of use
	in ToyMC type studies.

	Example of caluclating a missing mass

	    HSLorentzVector miss=fBeam+fTarget-fElectron.P4()-fProton.P4()-fPip.P4()-fPim.P4();

	Here fBeam, fTarget are HSLorentzVectors, while fElectron, fProton, 
	fPip and fPim are BaseParticles which are having their 
	4-vectors accessed via P4()
*/



//--Author      DI Glazier 23/03/2018
//--Rev
//--Update
//--Description
//HASPECT Event Reconstruction
//BaseParticle
//Optimsed Persistant Data structure
//Contains reconstructed information required for data analysis

#include <iostream>
#include "BaseParticle.h"

HS::BaseParticle::BaseParticle(int code) {
  if(!TDatabasePDG::Instance()->GetParticle(code))
    cout<<"BaseParticle::BaseParticle, sorry particle "<<code<<" does not exist in ROOT PDG table"<<endl;
  SetPDGcode(code);

}
HS::BaseParticle::BaseParticle(TString pdgname){
  if(!TDatabasePDG::Instance()->GetParticle(pdgname))
    cout<<"BaseParticle::BaseParticle, sorry particle "<<pdgname<<" does not exist in ROOT PDG table"<<endl;
  SetPDGcode(TDatabasePDG::Instance()->GetParticle(pdgname)->PdgCode());
}
void HS::BaseParticle::Print(Option_t *) const{
  cout<<"Printing BaseParticle of type "<<TDatabasePDG::Instance()->GetParticle(fPDGCode)->GetName()<<endl;
  // fP4.Print("");
  //fVertex.Print("");
}
