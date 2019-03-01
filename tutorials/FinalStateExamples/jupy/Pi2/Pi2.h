
#ifndef PI2_h
#define PI2_h

#include "FinalState.h"
#include "THSParticle.h"
#include "CLAS12Trigger.h"
#include "CLAS12DeltaTime.h"
#include "TreeDataPi2.h"
#include <vector>

class TreeDataPi2;

class Pi2 : public HS::FinalState{

 public :
  Pi2(TString pid="NONE",TString inc="ALL");
  virtual ~Pi2()=default;



  void FileStart() final;
  Bool_t  CheckParticle(HS::THSParticle* part) final;
  void FinalStateOutTree(HS::ttree_ptr tree) final;
  void Kinematics() final;
  void UserPostTopo() final;
  
  //Init functions
  void Init_Iter0();
  void Init_Iter1();
  void Init_Iter2();
  void Init_Iter3();
   //Topology action functions
  void Topo_0();
  void Topo_1();
  void Topo_2();
  void Topo_3();

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
  HS::CLAS12::CLAS12Trigger fTrigger;//For CLAS12 trigger info
  HS::CLAS12::CLAS12DeltaTime fCuts; //For particle cuts

  //Initial state
  HS::HSLorentzVector fBeam=HS::HSLorentzVector(0,0,10.6,10.6);
  HS::HSLorentzVector fTarget=HS::HSLorentzVector(0,0,0,0.938272);

  //Final Particles Detected
  HS::THSParticle fElectron=HS::THSParticle("e-");
  HS::THSParticle fProton=HS::THSParticle("proton");
  HS::THSParticle fPip=HS::THSParticle("pi+");
  HS::THSParticle fPim=HS::THSParticle("pi-");
 
  //Final Parents
 
  //Tree Output Data
  TreeDataPi2 TD;

 
  //Topology Configuration options
  TString fPID={"NONE"}; //NONE=>No PIDs 
  TString  fINCLUSIVE={"ALL"}; //ALL=> any number of all particle types


};

#endif //ifdef Pi2
