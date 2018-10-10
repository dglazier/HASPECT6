#include "ParticleCuts.h"

using namespace HS;

Bool_t ParticleCuts::CheckCuts(){
  UInt_t np=fParticles.size();
  
//Loop over all cuts if fail 1 return false
  for(UInt_t ip=0;ip<np;ip++){ 
    if(!(fCuts[ip]->ParticleCut(fParticles[ip]))) return kFALSE;
  }
  //passed all return true	
  return kTRUE;
}
