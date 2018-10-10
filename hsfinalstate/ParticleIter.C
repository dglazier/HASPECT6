/**
	\class ParticleIter
	
	Class to loop over THSParticle vectors
	Permuation, Rotation or Combination (Selection) done
	via THSCombinitorial class
	This class contains a pointer to another ParticleIter
	to allow for recursive combinations.
	This class is used to control the permutating of particles
	in THSFinalState
*/

#include "ParticleIter.h"

using namespace HS;

//////////////////////////////////////////////////////////////////////////
///Get the next combination of the iterator
///Returns kFALSE when all possible combinations have been given
///Returns kTRUE when still more combinations to go
///The new ordering can be accessed via NextParticle()
///Or if event particles have been set they can be updated
///by a call to SortEvent();

Bool_t ParticleIter::NextCombitorial(){
  // Print();
  // if(fEvParts.size()>0)fEvParts[0]->PDG();
  // cout<<fAllParticles->size()<<" "<<fNSel<<endl;
  //  if(!fUseCombi) return kFALSE;
  //Make sure Iterator fully configured
  if((fSelIter||fRemIter)&&(!fInnerIter))ConfigureIters();
  
  //Look for inner iterators after we have made the first
  //combitorial of this one
  if(!fDoneSelRem){ //First combination
    if(fInnerIter) //recursively go through all linked iterators
      if(fInnerIter->NextCombitorial())
	return kTRUE;
    //no further inner combinations to go
    fDoneSelRem=kTRUE;
  }
  //else get the next combitorial for this iterator
  //Check if all combinatioon already tried
  if(fCombi.IsFinished()){return kFALSE;}
  //If more to go get the next one
  //  fSelected=fCombi.Next(&fAllParticles,fNSel,fNIdentical);
  vector<THSParticle*>  vec_combi=*fAllParticles;
  // for(Int_t ii=0;ii<fAllParticles->size();ii++)
  //   cout<<"iter "<<fAllParticles->at(ii)->PDG()<<" "<<fCombi.Niter()<<endl;
  
  if(fCombi.GetType()==2){ //for selections with more requested than in allparticles, add extra particles (with zero energy etc)
    while(vec_combi.size()<UInt_t(fNSel)){
      vec_combi.push_back(fExtraParticle);
    }	
    fSelected=fCombi.Next(&vec_combi,fNSel,fNIdentical);
  }	
  //cout<<fSelected.size()<<endl;
  else fSelected=fCombi.Next(fAllParticles,fNSel,fNIdentical);
  //update selected and remaining particles
  if(fRemIter){
    if(fCombi.GetType()==2) fRemainder=fCombi.Remainder(&vec_combi);
    else fRemainder=fCombi.Remainder(fAllParticles);
    fRemIter->SetParticles(&fRemainder);
  }
  if(fSelIter){
    fSelIter->SetParticles(&fSelected);
  }
  fDoneSelRem=kFALSE;
  //get the first combination of inner iterators
  if(fInnerIter) fInnerIter->NextCombitorial();
  
  return kTRUE;  
  
}
//////////////////////////////////////////////////////////////////////////
///Set the order that the selected and remaining iterators will be called
///First Add selected then Remaining recursively
void ParticleIter::ConfigureIters(){
  if(fIsConfigured) return;
  fIsConfigured=kTRUE;
  //cout<<"Configure "<<fSelIter<<" "<<fRemIter<<" "<<fInnerIter<<endl;
  if(fSelIter){
    SetNextInnerIter(fSelIter);
    if(fRemIter){
      SetNextInnerIter(fRemIter);
    }
  }
  else if(fRemIter){	
    SetNextInnerIter(fRemIter);
  }
  // cout<<"Going to cinfig "<<fInnerIter<<endl;
  if(fInnerIter) fInnerIter->ConfigureIters();
}
//////////////////////////////////////////////////////////////////////////
///Add _iter to the end of the current iterator sequence
void ParticleIter::SetNextInnerIter(ParticleIter *_iter){
  //  cout<<"Add inner "<<fInnerIter<<" "<<_iter<<" "<<fSelIter<< " "<<fRemIter<<endl;
  if(fInnerIter) //If inner already exists move on inside it to look for next space
    fInnerIter->SetNextInnerIter(_iter);
  else
    fInnerIter=_iter;
}
////////////////////////////////////////////////////////////////////////
///In case all particle vector changes size need to redo selection map
// ResetSelection(){
//   if(fInnerIter)
//     fInnerIter->ResetSelection();
//   else
//     if(fCombi.GetType()==2) fCombi.ResetCombi();
// }

//////////////////////////////////////////////////////////////////////////
///Get the next particle in the current combination
///Returns a pointer to the next THSParticle
///If all particles done return null

THSParticle* ParticleIter::NextParticle(){
  
  THSParticle* particle=nullptr;
  if(fInnerIter) {
    if(fParti==0){
      particle=fInnerIter->NextParticle();
      if(particle) return particle;
      else if(fParti<fEvParts.size())
      	return fEvParts[fParti++];
    }	
    else if(fParti<fEvParts.size())
      return fEvParts[fParti++];
    
    fParti=0;
    return nullptr;
  }
  else if(fParti<fEvParts.size())
    return fEvParts[fParti++];
  
  fParti=0;
  return nullptr;
  
 
}

//////////////////////////////////////////////////////////////////////////
///Automates the recursive selection of Y identical particle types  X times
///e.g. select 3pi0 from 6 photons
///== select 3 from 6; select 2 from remaining 4; use remaining 2
///example usage : piterator.SelectXofY(3,2);
///An additional level of combinations sel_iter can be given and will be
///performed on all Y selections
/// i.e.can add a permutation to the X selections
///example usage : piterator.SelectXofY(3,2, new THSPermutation());

void ParticleIter::SelectXofY(Int_t _X, Int_t _Y, Combitorial* sel_iter){
  //recursively create iterators
  if(fEvParts.size()!=UInt_t(_X*_Y)) cout<<"Warning ParticleIter::SelectXofY not sufficeint Event Particles Set "<<fEvParts.size()<<" when we need "<<_X*_Y<<endl;
  if(fEvParts[0])fPDG=fEvParts[0]->PDG();
  SetCombi(THSSelection());
  SetNSel(_Y);
  SetNIdentical(_X);
  SetName(TString(Form("Select: %d of %d of type %d ",fNIdentical,fNSel,fEvParts[0]->PDG())) + TString(" after ")+GetName());

  //Now sort the event particles
  //Take the first _Y for those selected here
  //if(fEvParts.size()<_Y) cout<<"Warning ParticleIter::SelectXofY insufficient particles in Event Particles to cover "<<endl;
  vector<THSParticle*>  selParts=fCombi.SubSet(&fEvParts,_Y);
  vector<THSParticle*>  remParts=fCombi.SubSet(&fEvParts,fEvParts.size()-_Y,_Y);
  
  fEvParts=selParts;
  
  if(sel_iter){
    fSelIter=new ParticleIter();
    fSelIter->SetEventParticles(selParts);
    fSelIter->SetCombi(*sel_iter);
    fSelIter->SetPDG(fPDG);
  }
  if(_X>1){
    fRemIter=new ParticleIter();
    fRemIter->SetEventParticles(remParts);
    fRemIter->SelectXofY(_X-1,_Y,sel_iter);
    fRemIter->SetPDG(fPDG);
  }
}
//////////////////////////////////////////////////////////////////////////
///If event particles have been given assign copy a HSParticle
///to them in the current combination order
///The particles have to have been assigned to the correct iterator
void ParticleIter::SortEvent(){
  // cout<<"sort "<<fAllParticles<<" "<<fUseCombi<<" "<<fAllParticles->size()<<" "<<fEvParts.size()<<" "<<fSelected.size()<<" "<<fCombi.GetType()<<endl;
  if(fUseCombi){
    if(fInnerIter){
      fInnerIter->SortEvent();
    }
    //else{
    for(UInt_t isel=0;isel<fEvParts.size();isel++){
      //if(isel>=fSelected.size())cout<<" ParticleIter::SortEvent() Warning too many particles "<<isel<<" "<<fEvParts.size()<<endl;
      if(isel<fSelected.size()){
	fEvParts[isel]->CopyParticle(fSelected[isel],kFALSE);
	fEvParts[isel]->TakePDGMass();
      }
      else{
	fEvParts[isel]->P4p()->SetXYZT(0,0,0,0);
      }
    }
    
  }
  
  else{ //No combitorial just take all particles as given
    // cout<<"Sorting "<<fEvParts.size()<<" "<<fAllParticles->size()<<endl;
    for(UInt_t iall=0;iall<fAllParticles->size();iall++){
      if(iall>=fAllParticles->size())cout<<" ParticleIter::SortEvent() Warning too may particles in AllParticles "<<iall<<" "<<fEvParts.size()<<endl;
      // fEvParts[iall]->CopyParticle(fAllParticles[iall],kFALSE);
      // fEvParts[iall]->TakePDGMass();
      if(iall>=fEvParts.size())cout<<" ParticleIter::SortEvent() Warning too may particles in EvParticles "<<iall<<" "<<fEvParts.size()<<endl;
      //  cout<<iall<<" "<<fEvParts[iall]<<" "<<fAllParticles->at(iall)<<endl;
      fEvParts[iall]->CopyParticle(fAllParticles->at(iall),kFALSE);
      fEvParts[iall]->TakePDGMass();
    }
  }
}
////////////////////////////////////////////////////////////////////
///Set up to 10 event particle with 1 function call
///If you need more just call it again
void ParticleIter::AddEventParticles(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6,THSParticle* part7,THSParticle* part8,THSParticle* part9){
  if(part0) AddEventParticle(part0);
  if(part1) AddEventParticle(part1);
  if(part2) AddEventParticle(part2);
  if(part3) AddEventParticle(part3);
  if(part4) AddEventParticle(part4);
  if(part5) AddEventParticle(part5);
  if(part6) AddEventParticle(part6);
  if(part7) AddEventParticle(part7);
  if(part8) AddEventParticle(part8);
  if(part9) AddEventParticle(part9);

}

void ParticleIter::Print(Int_t verbose){
  if (verbose==1&&fEvParts.size()==0) {if(fInnerIter) fInnerIter->Print(verbose); return;}

  cout<<" ParticleIter::Print() "<<endl;
  if(verbose>1) cout<<GetName()<<endl;
  cout<<"     Type : "<<fCombi.GetType()<<" number chosen "<<fNSel*fNIdentical<<" of id  "<<fPDG<<" and number used here = "<<fEvParts.size()<<endl;
  if(verbose==0&&fCombi.GetType()==2)cout<<"     NSel "<<fNSel<<" Nidentical "<<fNIdentical<<" SelIter "<<(fSelIter!=nullptr)<<" RemIter "<<(fRemIter!=nullptr)<<endl; 
  if(fInnerIter) fInnerIter->Print(verbose);
  else cout<<endl;
    
}
