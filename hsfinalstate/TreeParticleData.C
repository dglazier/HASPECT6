#include "TreeParticleData.h"
#include <TROOT.h>
#include <TSystem.h>
#include <algorithm>


///////////////////////////////////////////////////////////
/// called each event to get values from the THSParticles
void HS::TreeParticleData::FillVars() {
  for(auto& pdata : fPData){//loop over particles
    pdata.FillData();
  }
}

//////////////////////////////////////////////////////////
///Set TTree branches for variables necessary for MVA
void HS::TreeParticleData::SetBranches() {
  auto tree=fTree->Tree();  
  if (!tree) {
        std::cout<<"ERROR : Base tree not found..."<<std::endl;
        std::cout<<"      : exiting..."                <<std::endl;
        exit(1);
    }

  std::cout<<"HS::TreeParticleData::SetBranches() Setting branches..."<<std::endl;

  //loop over particles
  Int_t ip=0;
   for(auto& pdata : fPData){
     auto vars=fPVars[ip++];

    //make requested branches
    pdata.SetBranches(vars);
    pdata.Branches(tree);
    
  }
  
   // tree->Print();
   AddSigBck(); //Add branches for signal and background weights
   tree->Branch("UID",&fUID,"UID/L");
}
//////////////////////////////////////////////////////////////////////////
///Add signal and background flags (for HSMVA)
void HS::TreeParticleData::AddSigBck(){
  fTree->Tree()->Branch("Signal",&fSigWeight,"Sig/F");
  fNSig=0;	
  fTree->Tree()->Branch("Background",&fBckWeight,"Bck/F");
  fNBck=0;	
  
}
/////////////////////////////////////////////////////////////////////////
/// Add a particle belonging to this TreeParticleData topology
void HS::TreeParticleData::AddParticle(TString name, THSParticle *part, vecNames variables){
  std::cout<<"TreeParticleData:: Adding "<<name<<std::endl;
  // fill vector of pointers
  fPData.push_back( ParticleData(name,part) );
  //Add particle name to variables so = BranchName
  for(auto &v : variables){
    v.Prepend(name);
  }
  fPVars.push_back( variables);
}
void HS::TreeParticleData::AddFinal(){
  if(fFinalState->GetTreeData())
    fFinalState->GetTreeData()->Branches(fTree->Tree());
}
