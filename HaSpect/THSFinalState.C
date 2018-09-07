/**
	\class THSFinalState
	
	Class to control particlular analysis.
	The main task is to take detected particles and
	convert them into information needed for subsequent
	fitting of observables, e.g LorentzVectors for AmpTools
	Double_ts for RooFit

	Users need to create their own specific final state class.
	It should operate on 3 classes of data:
	real, mc rec, mc gen.
	Input should be via a THSDataManager interface
	or if standard root format (i.e. ouput from THSDataManager)
	you may set  particles, eventinfo and runinfo directly.

	A sub event is created for each read event and valid combinations 
	of detected particles. (i.e. it creates multiple events for each event
        that is read, each sub event is given a unique ID UID in the 
	output tree)
	An event is read if it has detected particles that may constitute a 
	the predefined particle topologies for this final state. This is done 
	via the AddTopology function

	    AddTopology("pi+:pi-:gamma:gamma:proton:e-",
                 bind(&THSep_omegap::Init_Iter0, this),
                 bind(&THSep_omegap::Topo_0, this),
                 PID,INCLUSIVE);

	Access to the detected particles in the topology is then given 
	by the AddParticle function

	    AddParticle(&fElectron,kTRUE,4);
	    AddParticle(&fProton,kTRUE,3);
	    AddParticle(&fPip,kTRUE,0);
	    AddParticle(&fGamma1,kTRUE,-1);
	    AddParticle(&fGamma2,kTRUE,-1);
	    ...

	What constitutes a valid combination
	is managed by the class THSParticleIter, which also
	fills the particles for each combitorial. If there
	are particles which decay in a short time scale
	(e.g. pi0, omega,...; not Delta, excited states,..)
	Then they should be decalred via the ConfigParent function
	to make sure the correct combitorials are made

	    AddParticle(&fPi0,kTRUE,2);
	    ConfigParent(&fPi0,&fGamma1);
	    ConfigParent(&fPi0,&fGamma2);

	In general the user will just have to define there own 
	Topo_0(),Topo_1(),.. function for each topology they declared.
	These functions should contain calculations specific to that topology
	
	Also the function Kinematics() should be defined for calculations 
	common to all topologies.
	
	Finally FinalStateOutTree(TTree* tree) should define all the branches
	for the output tree. Additional variables given as branches should
	be data members of the THSFinalState or users class.
	
             tree->Branch("MissMass",&fMissMass,"MissMass/D");


	@example THSFinalTemp.C
*/



#include "THSFinalState.h"
#include "THSTopology.h"
#include "THSDataManager.h"
#include "THSLundReader.h"

THSFinalState::THSFinalState(){
  
  fMapPDGtoParticle[2212]=&fVecProtons;
  fMapPDGtoParticle[-2212]=&fVecAntiProtons;
  fMapPDGtoParticle[2112]=&fVecNeutrons;
  fMapPDGtoParticle[211]=&fVecPiPs;
  fMapPDGtoParticle[-211]=&fVecPiMs;
  fMapPDGtoParticle[111]=&fVecPi0s;
  fMapPDGtoParticle[321]=&fVecKPs;
  fMapPDGtoParticle[-321]=&fVecKMs;
  fMapPDGtoParticle[11]=&fVecEls;
  fMapPDGtoParticle[-11]=&fVecPos;
  fMapPDGtoParticle[22]=&fVecGams;
  fMapPDGtoParticle[-22]=&fVecBeams;
  fMapPDGtoParticle[1E4]=&fVecPlus;
  fMapPDGtoParticle[-1E4]=&fVecMinus;
  fMapPDGtoParticle[0]=&fVec0;

}
////////////////////////////////////////////////////////////////////////
///Add a new topology
///requires particle string defining particles to be detected
/// a function intialising the particle iterator
/// a function defining the specific behaviour for this topology
/// a string if want to use charge as identiification
/// a tring if want to look for inclusive topologies
void THSFinalState::AddTopology(TString topo,FinalState::VoidFuncs funcI,
				FinalState::VoidFuncs funcE,TString chPID,TString incl){
  fCurrTopo=new THSTopology(topo,funcE,chPID,incl);
  fCurrTopo->SetID(fNTopo++);
  
  fTopos.push_back(fCurrTopo);
  fCurrIter=nullptr;
  funcI();//call the assigned particle iterator initialiser
  fCurrIter->ConfigureIters();

  if(!fCurrIter)cout<<"THSFinalState::AddTopology warning no Init_Iter working for topology "<<topo<<endl;
 }
//////////////////////////////////////////////////////////////////
///Used to configure iterators and generated particles
void THSFinalState::AddParticle(THSParticle* part,Bool_t AddToFinal,Int_t genID){
  THSParticleConfig* pc=new THSParticleConfig(part,genID);
  fConfigs.push_back(pc);
  if(AddToFinal) fFinal.push_back(part);
}
/////////////////////////////////////////////////////////////////////
///Add a child particle to the THSParticleConfig of parent
void THSFinalState::ConfigParent(THSParticle* parent,THSParticle* child){
  UInt_t i=0;
  THSParticleConfig* parentConfig=nullptr;
  for(i=0;i<fConfigs.size();i++){
    if(fConfigs[i]->Particle()==parent){
      parentConfig=fConfigs[i];
      parentConfig->AddChild(child);
    }
  }
  if(!parentConfig)cout<<"WARNING THSFinalState::ConfigParent parent not found, has it been configured yet?"<<endl;
  for(i=0;i<fConfigs.size();i++)
    if(fConfigs[i]->Particle()==child)
      fConfigs[i]->SetParent(parentConfig);

  if(i!=fConfigs.size())cout<<"WARNING THSFinalState::ConfigParent child not found, has it been configured yet? "<<i<<" "<<fConfigs.size()<<endl;

  
}

/////////////////////////////////////////////////////////////////////////
///Initialse topologies and anything else before analysis starts
void THSFinalState::InitFS(){
  for(UInt_t i0=0;i0<fTopos.size()-1;i0++)
    for(UInt_t i1=i0+1;i1<fTopos.size();i1++)
      if(fTopos[i0]->CheckExclusiveTopo(fTopos[i1]->Definition())){
	fTopos[i0]->SetAlternative(fTopos[i1]);
	break;
      }

  for(UInt_t i=0;i<fTopos.size();i++)
    fTopos[i]->Print(fPrintVerbose);

  map< Int_t , vector< THSParticle* >* >::iterator itmap;
  for (itmap = fMapPDGtoParticle.begin(); itmap != fMapPDGtoParticle.end(); itmap++)
    {
      //      itmap->second->resize(fMaxPart);
      for(UInt_t i=0;i<fMaxPart;i++)
	itmap->second->push_back(new THSParticle());
    }  
}
/////////////////////////////////////////////////////////////////////
///Note particles with TruthOnly are reserved for undetected particles
///which may be kept in simulated data, but shouldn't be included
///in final state check
Bool_t THSFinalState::CheckForATopology(){
  if(fIsGenerated) return kFALSE;

  fThisTopo.clear();
  fThisTopo.reserve(frDetPIDs->size());
  //Assume all topologies have the same particle ID scheme
  //So here just use the first one
  for(UInt_t ip=0;ip<frDetPIDs->size();ip++){
    fThisTopo.emplace_back(fTopos[0]->ParticleID(frDetPIDs->at(ip)));
  }
  // cout<<frDetPIDs->size()<<endl;
  std::sort(fThisTopo.begin(),fThisTopo.begin()+fThisTopo.size());
  // cout<<"ThisTopology ";
  // for(UInt_t i=0;i<fThisTopo.size();i++)
  //   cout<<fThisTopo[i]<<" ";
  // cout<<endl;
  //now check to see if this topology matches any of our predefines one
  for(Int_t ito=0;ito<(Int_t)fTopos.size();ito++){
    if(fTopos[ito]->CheckTopo(&fThisTopo)){
      fTopoID=ito; //start FindTopology here
      return kTRUE;
    }
  }
  //  cout<<"No Check "<<endl;
  return kFALSE;
}
/////////////////////////////////////////////////////////////////////
///Note particles with TruthOnly are reserved for undetected particles
///which may be kept in simulated data, but shouldn't be included
///in final state check
THSTopology* THSFinalState::FindTopology(){
  if(fIsGenerated) return nullptr;
  if(fTopoID==(Int_t)fTopos.size()-1) return nullptr;
  // if(IsPermutating()) return fCurrTopo;//Topology hasn't changed  with permutation
  if(IsPermutating()) return fCurrTopo;//Topology hasn't changed  with permutation
  // fClock.Start();//////////////////////////Timing
  if(fTopoID==-1){//only fill fThisTopo first time
    fThisTopo.clear();
    //    fThisTopo.reserve(frDetParts->size());
    //Assume all topologies have the same particle ID scheme
    //So here just use the first one
    for(UInt_t ip=0;ip<frDetParts->size();ip++){
      THSParticle* part=&(frDetParts->at(ip));
      if(!CheckParticle(part)) continue; //is this a good track?
      // fThisTopo.emplace_back(fTopos[0]->ParticleID(part->PDG()));
      Int_t pid=fTopos[0]->ParticleID(part->PDG());
      fThisTopo.push_back(pid);
    }
  }
  
  std::sort(fThisTopo.begin(),fThisTopo.begin()+fThisTopo.size());
  // cout<<"ThisTopology "<<frDetParts->size()<<" = ";
  // for(UInt_t i=0;i<fThisTopo.size();i++)
  //   cout<<fThisTopo[i]<<" ";
  // cout<<endl;
  //now check to see if this topology matches any of our predefines ones
  fCurrTopo=nullptr;
  if(fTopoID!=-1) {fNTried++;}
  for(;fTopoID<(Int_t)fTopos.size()-1;){
    fTopoID++;
    if(fTopos[fTopoID]->CheckTopo(&fThisTopo)){
      fCurrTopo=fTopos[fTopoID];
      break;
    }
  }
  //fCurrTopo=fTopos[0];
  fNParts=fThisTopo.size();
  return fCurrTopo;
}


///////////////////////////////////////////////////////////////////
///Read in the particles from this input event and
///Get the first combination from the particle iterator
void THSFinalState::InitParticles(){
  if(fIsPermutating0==kTRUE) return;//already Inited
  InitDetParts();
  if(!fCurrTopo) return;//if reached fMaxPart
  // //Get first combination
  FirstParticles();
}
//////////////////////////
///Check Npart limits, to get rid of events were there are too many
///particles,
void THSFinalState::CheckParticles(){
  
  map< Int_t , vector< THSParticle* >* >::iterator itmap;
  for (itmap = fMapPDGtoParticle.begin(); itmap != fMapPDGtoParticle.end(); itmap++)
    {
      if(itmap->second->size()>fMaxPart) {fCurrTopo=nullptr;return;}
    }  
 
}

///////////////////////////////////////////////////////////////////
///Read in the particles from this input event
///Place detected particles in array associated with their pdg type
///Loop over detected particles
void THSFinalState::InitDetParts(){
  //parts->clear();

  //Clear all particle vectors
  map< Int_t , vector< THSParticle* >* >::iterator itmap;
  for (itmap = fMapPDGtoParticle.begin(); itmap != fMapPDGtoParticle.end(); itmap++)
    {
      itmap->second->clear();
    }
  
  for(UInt_t ip=0;ip<frDetParts->size();ip++){
    THSParticle* part=&(frDetParts->at(ip));
    if(!CheckParticle(part)) continue;
    //Find the particle vector given by this topology
    vector<THSParticle*> *vecParts=fMapPDGtoParticle[fCurrTopo->ParticleID(part->PDG())];
    vecParts->push_back(part);
    if(vecParts->size()==fMaxPart) {fCurrTopo=nullptr; return;}
    //  cout<<vecParts->size()<<" "<<ip<<" "<<fCurrTopo->ParticleID(part->PDG())<<endl;
  }
  
}
/////////////////////////////////////////////////////////////
///Check if this particle should be considered for the event
//or do we thinnk it is junk
Bool_t THSFinalState::CheckParticle(THSParticle* part){
  return kTRUE;
}
//////////////////////////////////////////////////////////////
///Read in the particles from this input event
///assign them in vectors corrsponing to their charge
// void THSFinalState::InitDetPartsCharge(){
//   //fVecPlus.clear();
//   //fVecMinus.clear();
//   //fVec0.clear();
//   vector<vector<THSParticle*> *> chargeVec={&fVecMinus,&fVec0,&fVecPlus};
//   vector<Int_t > Nparts={0,0,0};
//   for(UInt_t ip=0;ip<fNParts;ip++){
//     //cout<<frDetParts->at(ip).PDG()<<endl;
//     //    THSParticle* part=&(frDetParts->at(ip));
//     //chargeVec[frDetParts->at(ip).Charge()+1]->push_back(frDetParts->at(ip));
//     UInt_t index=frDetParts->at(ip).Charge()+1;
//     // cout<<chargeVec[index]->at(Nparts[index])<<endl;
//     if(Nparts[index]==fMaxPart) {fCurrTopo=nullptr; return;}
//     chargeVec[index]->at(Nparts[index]++)->CopyParticle(&frDetParts->at(ip),kTRUE);
//    }
//  }
//////////////////////////////////////////////////////////////
//Read in the particles from this input event
//assign them in vectors corrsponing to their charge
void THSFinalState::InitDetPartsCharge(){
  fVecPlus.clear();
  fVecMinus.clear();
  fVec0.clear();
  vector<vector<THSParticle*> *> chargeVec={&fVecMinus,&fVec0,&fVecPlus};
  
  for(UInt_t ip=0;ip<fNParts;ip++){
    THSParticle* part=&(frDetParts->at(ip));
    chargeVec[part->Charge()+1]->push_back(part);
  }
}

//////////////////////////////////////////////////////////////////
///Process one event from the input tree
void THSFinalState::ProcessEvent(){
  //Process one input event
   InitEvent();
  if(frDetParts)fNDet=frDetParts->size();
  Int_t ntopo=0;
  while(FindTopology()){ //Find all valid topologies
    //Init particle vectors, this should only be done once for each event
    //Not for each permuation
    InitDetected();//make all final state particles missing
    InitParticles();
    if(fCurrTopo) //in case >MaxParticle
      while(FSProcess()); //Process all combitorials
  }
  if(fIsGenerated) FSProcess(); //If only analysing generated events
  
  FinaliseEvent();
 }
Bool_t THSFinalState::FSProcess(){
 
  if(fCheckCombi) CheckCombitorial();

  WorkOnEvent();
  
  if(IsGoodEvent()){
    UserProcess(); 
  }
  //Clear added particles
  for(UInt_t ic=0;ic<fConfigs.size();ic++){
    fConfigs[ic]->Particle()->MinorClear();
    fConfigs[ic]->Particle()->SetDetector(fMISSING);
  }
  if(fTryPerm)
    PermutateParticles();
  if(IsPermutating()){
    return kTRUE;
  }
  return kFALSE;
}

void THSFinalState::UserProcess(){
  if(fFinalTree) fFinalTree->Fill(); //fill for first combination
  fUID++;
  
}

Bool_t THSFinalState::WorkOnEvent(){
  //Should this event be saved?
  THSFinalState::fGoodEvent=kTRUE;
  THSFinalState::fCorrect=0; //Correct permutation? used for simulation only
  //If generated MC events
  InitGenerated();
  if(!fIsGenerated){
    //Look for reconstructed events
    //if reconstructed Find the detected particles in this event
    //Found a topology execute its Topo function
    fCurrTopo->Exec();
   }
  
  //Calc kinematics
  Kinematics();
  
  //Check if assigned vectors agree with true generated
  //Simulation only
  CheckTruth();

  if(fIsGenerated) return kTRUE; //Generated only 1 permutation
  return kTRUE;
}
void THSFinalState::Finish(){
}
//////////////////////////////////////////////////////////////
///returns true if another valid permuation to be tried \n
///returns false when time to move on \n
///Check through particle types,
///if more than 1 of a type permutate through all combinations
Bool_t THSFinalState::PermutateParticles(){
  if(fIsGenerated) return kFALSE; //Truth generated analysis
  if(!fCurrTopo) return kFALSE; //no valid topology
  fNPerm++;
  if(fIsPermutating1) return kTRUE; //so user can do their own permutation
  fIsPermutating0=kTRUE; //Will be set to false when event over
  THSParticleIter* piter=fCurrTopo->Iter();
  if(piter->NextCombitorial()){piter->SortEvent();return kTRUE;}
  else piter->SortEvent();
  fIsPermutating0=kFALSE;
  return kFALSE; 
}
void THSFinalState::FirstParticles(){
  if(fIsGenerated) return; //Truth generated analysis
  fNPerm++;
  THSParticleIter* piter=fCurrTopo->Iter();
  piter->GotoStart();
  piter->NextCombitorial();
  piter->SortEvent();
  fIsPermutating0=kFALSE;//no other combination
  return; 
}

///////////////////////////////////////////////////////
///Loop through generated and record momentum distance
void THSFinalState::MatchWithGen(THSParticle *part){
  UInt_t match=0;
  Double_t mindist=1E10;
  for(UInt_t ip=0;ip<frGenParts->size();ip++){
    THSParticle* gen=&frGenParts->at(ip);
    Double_t dist=part->p3Distance(gen->P4p()->Vect());
    if(dist<mindist){
      mindist=dist;
      match=ip;
    }
  }
  part->SetTruth(frGenParts->at(match).P4(),frGenParts->at(match).Vertex(),frGenParts->at(match).PDG());
}

//////////////////////////////////////////////////////////////////////
///Loop through generated and record momentum distance 
///if the nearest generated track is the same as the TRUTH return true
Bool_t THSFinalState::IsCorrectTruth(THSParticle *part){
  if(!frGenParts) return kFALSE;
  if(!frGenParts->size())return kFALSE;
  UInt_t match=0;
  Double_t mindist=1E10;
  for(UInt_t ip=0;ip<frGenParts->size();ip++){
    THSParticle* gen=&frGenParts->at(ip);
    Double_t dist=part->p3Distance(gen->P4p()->Vect());
    if(dist<mindist){
      mindist=dist;
      match=ip;
    }
  }

  if(part->TruthP4()==frGenParts->at(match).P4()&&part->TruthPDG()==frGenParts->at(match).PDG()){
    Double_t resangle=part->ResAngle();
      // fCurResAngle+=resangle;
    if(fAccurateTruth){//if given an accurate angle use it 
      if(resangle<fAccurateTruth)
	return kTRUE;
      else return kFALSE;
    }
    return kTRUE;
  }
  return kFALSE;
}

///////////////////////////////////////////////
///Check if our final vectors match with truth

void THSFinalState::CheckTruth(){
  if(fIsGenerated) return;
  //Already got one for this event
  //If we set this correct it would be double counting
  //This can happen when using inclusive topologies
  //And rotate particles that are not in the defined topology
  fCorrect=0;
  if(fGotCorrectOne) return;
  //Check if our final vectors match with truth
  fCorrect=1;
  // for(UInt_t ip=0;ip<fFinal.size();ip++)
  //   fCorrect*=IsCorrectTruth(fFinal[ip]);
  for(UInt_t ip=0;ip<fConfigs.size();ip++)
    if(fConfigs[ip]->GenID()>-1){ //only check particles assigned via ConfigParticle
      auto part=fConfigs[ip]->Particle();
      if(IsMissing(part))
	continue;
      fCorrect*=IsCorrectTruth(part);
    }
  if(fCorrect) fGotCorrectOne=kTRUE;
}
////////////////////////////////////////////////////////////////
///Read the Generated particles if assigned via ConfigParticle
void THSFinalState::InitGenerated(){
  if(!THSFinalState::frGenParts) return;
  if(THSFinalState::frGenParts->size()==0) {return;}
  for(UInt_t ip=0;ip<fConfigs.size();ip++)
    if(fConfigs[ip]->GenID()>-1){ //only check particles assigned via ConfigParti
      if(fIsGenerated)
	fConfigs[ip]->SetParticleVal(&frGenParts->at(fConfigs[ip]->GenID()));
      else
	fConfigs[ip]->Particle()->SetTruth(&frGenParts->at(fConfigs[ip]->GenID()));
    }
  
}
////////////////////////////////////////////////////////////////
///Initialise all particles as missing
void THSFinalState::InitDetected(){
  for(UInt_t i=0;i<fConfigs.size();i++)
    fConfigs[i]->Particle()->SetDetector(fMISSING);
}
//////////////////////////////////////////////////
///Interface to THSParticleIter
///Add selected iterator to previously selected particles
THSParticleIter* THSFinalState::AddSelectToSelected(THSParticleIter* diter,Int_t ni,Int_t nsel,THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6,THSParticle* part7,THSParticle* part8,THSParticle* part9){
  if(nsel*ni>diter->GetNSel()) cout<<"WARNING THSFinalState::AddSelectToSelected : trying to select more particles than exist in original iterator "<<nsel*ni<<" "<< diter->GetNSel()<<endl;
  THSParticleIter *new_iter=AddSelectXofY(ni,nsel,part0,part1,part2,part3,part4,part5,part6,part7,part8,part9);
  new_iter->SetName(new_iter->GetName()+" sel parent is "+diter->GetName());
  if(part0) new_iter->SetPDG(part0->PDG());
  diter->SetSelIter(new_iter);
  return new_iter;
}
//////////////////////////////////////////////////
///Interface to THSParticleIter
///Add selected iterator to previously selected particles
THSParticleIter* THSFinalState::AddSelectToSelected(THSParticleIter* diter,Int_t ni,Int_t nsel,vector<THSParticle*> *parts){
  if(nsel*ni>diter->GetNSel()) cout<<"WARNING THSFinalState::AddSelectToSelected : trying to select more particles than exist in original iterator "<<nsel*ni<<" "<< diter->GetNSel()<<endl;
  THSParticleIter *new_iter=AddSelectXofY(ni,nsel,parts);
  new_iter->SetName(new_iter->GetName()+" sel parent is "+diter->GetName());
  if(parts->at(0)) new_iter->SetPDG(parts->at(0)->PDG());
  diter->SetSelIter(new_iter);
  return new_iter;
}
//////////////////////////////////////////////////
///Interface to THSParticleIter
///Add selected iterator to remaining particles
THSParticleIter* THSFinalState::AddSelectToRemainder(THSParticleIter* diter,Int_t ni,Int_t nsel,THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6,THSParticle* part7,THSParticle* part8,THSParticle* part9){
  THSParticleIter *new_iter=AddSelectXofY(ni,nsel,part0,part1,part2,part3,part4,part5,part6,part7,part8,part9);
  new_iter->SetName(Form("Select: %d of %d",ni,nsel));
  new_iter->SetName(new_iter->GetName()+" rem parent is "+diter->GetName());
  if(part0) new_iter->SetPDG(part0->PDG());
  diter->SetRemIter(new_iter);
  return new_iter;
}
//////////////////////////////////////////////////
///Interface to THSParticleIter
///Add selected iterator to remaining particles
THSParticleIter* THSFinalState::AddSelectToRemainder(THSParticleIter* diter,Int_t ni,Int_t nsel){
  THSParticleIter *new_iter=new THSParticleIter();
  new_iter->SetName(Form("Select: %d of %d",ni,nsel));
  new_iter->SetName(new_iter->GetName()+" rem parent is "+diter->GetName());
  new_iter->SetCombi(THSSelection());
  new_iter->SetNSel(nsel);
  new_iter->SetNIdentical(ni);
  
  diter->SetRemIter(new_iter);
  return new_iter;
}
//////////////////////////////////////////////////
///Interface to THSParticleIter
///Add selected iterator
THSParticleIter* THSFinalState::AddSelectXofY(Int_t ni,Int_t nsel,THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6,THSParticle* part7,THSParticle* part8,THSParticle* part9){
  
  THSParticleIter *new_iter= new THSParticleIter();
  new_iter->AddEventParticles(part0,part1,part2,part3,part4,part5,part6,part7,part8,part9);
  new_iter->SelectXofY(ni,nsel);
  if(part0) new_iter->SetPDG(part0->PDG());
  return new_iter;
}
//////////////////////////////////////////////////
///Interface to THSParticleIter
///Add selected iterator
THSParticleIter* THSFinalState::AddSelectXofY(Int_t ni,Int_t nsel,vector<THSParticle*> *parts){
  
  THSParticleIter *new_iter= new THSParticleIter();
  // new_iter->SetName(Form("Select: %d of %d %d",ni,nsel,parts->at(0)->PDG()));
  new_iter->SetEventParticles(*parts);
  new_iter->SelectXofY(ni,nsel);
  if(parts->at(0)) new_iter->SetPDG(parts->at(0)->PDG());
  return new_iter;
}
//////////////////////////////////////////////////
///Interface to THSParticleIter
///Add permutate iterator to previously selected particles
THSParticleIter* THSFinalState::AddPermutateToSelected(THSParticleIter* diter,THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6,THSParticle* part7,THSParticle* part8,THSParticle* part9){ 
  THSParticleIter *new_iter=AddPermutate(part0,part1,part2,part3,part4,part5,part6,part7,part8,part9);
  diter->SetSelIter(new_iter);
  return new_iter;
}
/////////////////////////////////////////////////////////////////
///Interface to THSParticleIter
///Add permutate iterator to remaining particles
THSParticleIter* THSFinalState::AddPermutateToRemainder(THSParticleIter* diter,THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6,THSParticle* part7,THSParticle* part8,THSParticle* part9){
  THSParticleIter *new_iter=AddPermutate(part0,part1,part2,part3,part4,part5,part6,part7,part8,part9);
  diter->SetRemIter(new_iter);
  return new_iter;
}
/////////////////////////////////////////////////////////////////
///Interface to THSParticleIter
///Add selected iterator 
THSParticleIter* THSFinalState::AddPermutate(THSParticle* part0,THSParticle* part1,THSParticle* part2,THSParticle* part3,THSParticle* part4,THSParticle* part5,THSParticle* part6,THSParticle* part7,THSParticle* part8,THSParticle* part9){
  
  THSParticleIter *new_iter= new THSParticleIter();
  new_iter->SetCombi(THSPermutation());
  new_iter->AddEventParticles(part0,part1,part2,part3,part4,part5,part6,part7,part8,part9);
  return new_iter;
}
////////////////////////////////////////////////////////////////
///Interface to THSParticleIter
///Create particle iterator for a particticular species
///Given by the particle vector parts (e.g. fVecMinus)
THSParticleIter* THSFinalState::CreateParticleIter(vector<THSParticle*> *parts,Int_t Nsel){
  THSParticleIter *diter=nullptr;
  if(!fCurrIter){
    diter=fCurrTopo->Iter();
    fCurrIter=diter;
  }
  else{
    diter= new THSParticleIter();
    fCurrIter->SetNextInnerIter(diter);
  }
  
  diter->SetCombi(THSSelection());
  diter->SetParticles(parts);
  diter->SetNSel(Nsel);
  
  return diter;
}
//////////////////////////////////////////////////////////////////
///Automatically generate iterator based on topology and particle configs
void THSFinalState::AutoIter(){
  //Topo definition will be list of PDG values expect for particles
  //specified by charge, where the charge will be given instead
  vector<Short_t >* thisTopo = fCurrTopo->Definition();
  vector<Short_t >* trueTopo = fCurrTopo->True(); //always PDG values

  cout<<" WARNING running THSFinalState::AutoIter() you  should check the topology print output and make sure the displayed iterator is waht you want .."<<endl;
  
  for(UInt_t ip=0;ip<thisTopo->size();){
    //Loop over all the declared particles in the topology
    //group like particles according to their particle ID (PDG or charge)
    Short_t pid=thisTopo->at(ip);
    Short_t N_pid=std::count (thisTopo->begin(), thisTopo->end(), pid);
    if(N_pid==0){ip++;continue;}
    ip+=N_pid;
    
    THSParticleIter* diter0=CreateParticleIter((fMapPDGtoParticle[pid]),N_pid);
    diter0->SetName(Form("PITER:%d",pid));
    diter0->SetPDG(pid);
    
    //Look for which particle can belong to this particle ID
    //(==which pdg have this charge)
    //if particle ID is the PDG value there will only be 1 type
    
    vector<vector<THSParticleConfig*>> subConfigs;
    Int_t ntype=0;
    Int_t Nconfig_pid=0;
    vector<Short_t> types;
    //cout<<"Look through configs "<<fConfigs.size()<<endl;
    for(UInt_t jp=0;jp<fConfigs.size();jp++){
      if(fConfigs[jp]->GetNChild())continue; //not a detected particle
      //make sure this particle is in the true topology
      if(std::count(trueTopo->begin(),trueTopo->end(),fConfigs[jp]->PDG())==0) continue;
      //found a particle with this particle identification
      //cout<<pid<<" "<<fConfigs[jp]->PDG()<<" "<<fCurrTopo->ParticleID(fConfigs[jp]->PDG())<<endl;
      if(fCurrTopo->ParticleID(fConfigs[jp]->PDG())==pid){
	Nconfig_pid++;
	cout<<"Check NConfit_pid "<< Nconfig_pid<<endl;
	if(std::count(types.begin(),types.end(),fConfigs[jp]->PDG())==0){
	  //Found a new PDG type
	  cout<<"new type "<<fConfigs[jp]->PDG()<<endl;
	  ntype++;
	  types.push_back(fConfigs[jp]->PDG());
	  vector<THSParticleConfig* > new_one;
	  new_one.push_back(fConfigs[jp]);
	  subConfigs.push_back(new_one);
	}
	else{//same type
	  subConfigs[ntype-1].push_back(fConfigs[jp]);
	}
      }
    }
    //   subEvents contains final state particles with same topology ID
    //   each element contains a vector of different actual PDG particles 
    //   Now need to loop over subEvnts and select them from diter
    for(Int_t it=0;it<ntype;it++){
      Int_t typePDG=subConfigs[it][0]->PDG();
      Int_t NtruePDG=fCurrTopo->HowManyTrue(typePDG);//number of this pdg in curr topo
      //Look for particles of this type which may have parents
      //And first select those
      Bool_t NotEnough=kFALSE;
      for(UInt_t ic=0;ic<subConfigs[it].size();){
       	THSParticleConfig* parent=nullptr;
      	THSParticleConfig* child = subConfigs[it][ic];
       	if((parent=child->Parent())){
	  //get children from this parent with same PDG
      	  vector<THSParticle* > child_pdg=parent->Children(child->PDG());
	  N_pid-=child_pdg.size();
	  Nconfig_pid-=child_pdg.size();
 	  //Now look to see if there are identical particle of this parent type
	  //We do not want to double count these
	  vector<THSParticleConfig* > all_parents=HowManyParticles(parent->PDG());
	  //cout<<"Parents "<<all_parents.size()<<" "<<child->PDG()<<" "<<child_pdg.size()<<endl;
	  Int_t NUsedParents=1;
	  for(UInt_t io=0;io<all_parents.size();io++){
	    if(all_parents[io]==parent)continue; //don't count this one again
	    if(all_parents[io]->Parent()||parent->Parent())continue; //Has a parent so should not include here as it is not identical
	    vector<THSParticle* > child_other=all_parents[io]->Children(child->PDG());
	    //   if(child_pdg.size()+child_other.size()>N_pid)//not enough for all parents
	    if(N_pid==0)//not enough for all parents
	      {
		cout<<"WARNING AutoIter Not enough "<<child->PDG()<<" detected particles for all parents "<<parent->PDG()<<endl;
		NotEnough=kTRUE;
		break;
	      }
	    for(UInt_t ioc=0;ioc<child_other.size();ioc++){
	      
	      if(child_pdg.size()<fCurrTopo->HowManyTrue(typePDG)){
		child_pdg.push_back(child_other[ioc]);
		N_pid--; //number of this pid left in topo
		Nconfig_pid--; //number of configured particles left
		if(N_pid==0) break;
		if(Nconfig_pid==0) break;
		NtruePDG--;  //number of this pdg left in curr topo
	      }	
	    }
	    NUsedParents++;
	  }
	  Int_t NtheseChild=child_pdg.size();
	  ic+=NtheseChild;
	  //remove the children from the subconfigs
	  for(UInt_t isp=0;isp<subConfigs[it].size();){
	    for(UInt_t ich=0;ich<child_pdg.size();ich++){
	      if(child_pdg[ich]==subConfigs[it][isp]->Particle()){
		subConfigs[it].erase(subConfigs[it].begin()+isp);
		break;
	      }
	      if(ich==child_pdg.size()-1)isp++; //didn't find one, ove to next one
	    }
	    //Don't incerement isp in case we removed one, this will move on to the next one
	  }
	  
	  THSParticleIter* diter_s=AddSelectToSelected(diter0,NUsedParents,NtheseChild/NUsedParents,&child_pdg);
	    
	  // Nconfig_pid-=NtheseChild;
	  // N_pid-=NtheseChild;
	  if(Nconfig_pid==0) break; //selected everything already
	  
	  if(NotEnough){
	    if(N_pid>0){
	      //might be the odd one or two left
	      THSParticleIter* diter_r=AddSelectToRemainder(diter_s,1,N_pid);
	      diter0=diter_r;
	      NotEnough=kFALSE;
	    }
	    else break;
	  }
	  // else {
	  if(N_pid>0){
	    THSParticleIter* diter_r=AddSelectToRemainder(diter_s,1,Nconfig_pid);
	    diter0=diter_r;
	  }
	  
	  
      	}
      	ic++;
	//continue;
      }
      
      if(NotEnough) break;
      if(Nconfig_pid==0) break; //selected everything already
      if(N_pid==0) break; //selected everything already
      //Once all particle with parents have been selected, select the remainder
      vector<THSParticle* > evtparts;
      for(UInt_t isp=0;isp<subConfigs[it].size();isp++){
	if(evtparts.size()<fCurrTopo->HowManyTrue(typePDG)){
	  evtparts.push_back(subConfigs[it][isp]->Particle());
	  N_pid--; //number of this pid left in topo
	  Nconfig_pid--; //number of configured particles left
	  if(N_pid==0) break;
	  if(Nconfig_pid==0) break;
	  NtruePDG--;  //number of this pdg left in curr topo
	}
      }
      // if(NtruePDG==0) continue;
      if(evtparts.size()==0)continue;
      //cout<<"n selct "<<evtparts.size()<<endl;
      THSParticleIter* diter_s=AddSelectToSelected(diter0,1,evtparts.size(),&evtparts);
      
      // Nconfig_pid-=evtparts.size();
      // N_pid-=evtparts.size();
      if(Nconfig_pid==0) break; //selected everything already
      if(N_pid==0) break; //selected everything already
      //pass the remainder on for selection
      THSParticleIter* diter_r=AddSelectToRemainder(diter_s,1,Nconfig_pid);
      diter0=diter_r;
      
    }
    
  }
}
//////////////////////////////////////////////////////////////
///Set and get particles from datamanager class
void THSFinalState::SetDataManager(THSDataManager* dm){
  fData=dm;
  SetDetParts(dm->GetParticles());
  SetGenParts(dm->GetGenerated());
  SetDetPIDs(dm->GetPIDs());

  SetEventInfo(dm->GetEventInfo());
  SetRunInfo(dm->GetRunInfo());

  if(dynamic_cast<THSLundReader*>(dm)){//LUND reader=>only Generated
    SetGenerated();
  }
  if(fIsGenerated)
    fData->SetWriteGenBranch("Generated");
  
  // fData->SetFinalState(this);
  FileStart();
}
//////////////////////////////////////////////////////////////
///Print permuations to screen for debugging
void THSFinalState::CheckCombitorial(){
  cout<<endl<<fUID<<" Printing Perm "<<fNPerm<<" of topology "<<fTopoID<<endl;
  for(UInt_t i=0;i<fConfigs.size();i++){
    THSParticle *part=fConfigs[i]->Particle();
    if(IsMissing(part))continue;
    cout<<" PDG("<<part->PDG()<<")Th("<<part->P4p()->Theta()<<")E( "<<part->P4p()->E()<<")  ";
  }
  cout<<endl;
}


/////////////////////////////////////////////////////////////
///Return configured particles with this pdg
///used to work out how many identical particles to iterate over
vector<THSParticleConfig* > THSFinalState::HowManyParticles(Int_t pdg){
  Int_t np=0;
  vector<THSParticleConfig* > configs;
  for(UInt_t i=0;i<fConfigs.size();i++){
    if(fConfigs[i]->PDG()==pdg) configs.push_back(fConfigs[i]);
  }
  return configs;
}
vector<THSParticle* >  THSParticleConfig::Children(Int_t pdg){
  vector<THSParticle*> children;
  for(UInt_t i=0;i<fChildren.size();i++)
    if(fChildren[i]->PDG()==pdg)
      children.push_back(fChildren[i]);
  return children;
}
