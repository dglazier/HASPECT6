/**
	\class CLAS12DeltaTime
	A derived class of THSCuts used to apply timing cuts to 
	a given THSParticle.

	This can be configured (i.e. cut width for each detector) via constuctor
	
	    CLAS12DeltaTime elCut(2,2,0,0); //FT<2, FD<2, No CD, No CAL only

	to see if a particle passes a cut supply the address of a THSParticle
	
	    elCut.ParticleCut(&fElectron); //Is fElectron an electron?

    


*/
#include "CLAS12DeltaTime.h"

