/**
	\class Cuts
	Persistant cuts base class for use with THSFinalState.
	Given a THSParticle it will return true of false 
	depending on whether the particle meets the predefined cuts

	An instance of Cuts is a data mamber of THSFinalState, fCuts
	In principle more sophisticated classes can be created 
	inheriting from this (see for example THSCLAS12DeltaTime)
	and used in THSFinalState to make cuts on a set of THSParticles.
	
	Currently defaults to time cuts on each particle

	    fCuts.SetTimeCut(5) ; //set a 5 ns time cut

	    if(fCuts.ParticleCut(&particle)) ... ; //did particle pass the cut?
    

	So if you wanted to make momentum dependent cuts or cuts on 
	measured mass you could create your own Cuts derived class.
*/

#include "Cuts.h"

