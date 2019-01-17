
#ifndef FINALTEMP_h
#define FINALTEMP_h

#include "FinalState.h"
#include "THSParticle.h"
#include "TreeDataFinalTemp.h"
#include <vector>

class TreeDataFinalTemp;

class FinalTemp : public HS::FinalState{

 public :
  FinalTemp(TString pid="NONE",TString inc="ALL");
  virtual ~FinalTemp()=default;



  void FileStart() final;
  Bool_t  CheckParticle(HS::THSParticle* part) final;
  void FinalStateOutTree(HS::ttree_ptr tree) final;
  void Kinematics() final;
  void UserPostTopo() final;
  
  //Init functions

  //Topology action functions

  //Configuation Options
  //set this to which particles you want to id via pdg code alone,
  //"NONE" => only use charge info for PID
  //"ALL" => only use particle PDG() values
  //"e-:proton" => use PDG() for electrons and protons, charge for rest
  void SetPID(TString pid){fPID=pid;};
  //Set which particles you want to have any number detected
  // "ALL"=> completely inclusive
  //"e-" => inclusive of any number of e-, exact matches for others
  void SetInclusive(TString inc){fINCLUSIVE=inc;};

  HS::TreeData* GetTreeData() final{return &TD;}

  protected :

  private:

  //Initial state
  HS::HSLorentzVector fTarget=HS::HSLorentzVector(0,0,0,0.938272);

  //Final Particles Detected
 
  //Final Parents
 
  //Tree Output Data
  TreeDataFinalTemp TD;

 
  //Topology Configuration options
  TString fPID={"NONE"}; //NONE=>No PIDs 
  TString  fINCLUSIVE={"ALL"}; //ALL=> any number of all particle types


};

#endif //ifdef FinalTemp
