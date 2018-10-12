
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



  void FileStart() override;
  Bool_t  CheckParticle(THSParticle* part) override;
  void FinalStateOutTree(TTree* tree) override;
  void Kinematics() override;
  void UserPostTopo() override;
  
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

  protected :

  private:
  HS::CLAS12Trigger fTrigger;//For CLAS12 trigger info
  HS::CLAS12DeltaTime fCuts; //For particle cuts

  //Initial state
  HSLorentzVector fBeam=HSLorentzVector(0,0,10.6,10.6);
  HSLorentzVector fTarget=HSLorentzVector(0,0,0,0.938272);

  //Final Particles Detected
  THSParticle fElectron=THSParticle("e-");
  THSParticle fProton=THSParticle("proton");
  THSParticle fPip=THSParticle("pi+");
  THSParticle fPim=THSParticle("pi-");
 
  //Final Parents
 
  //Tree Output Data
  TreeDataPi2 TD;

 
  //Topology Configuration options
  TString fPID={"NONE"}; //NONE=>No PIDs 
  TString  fINCLUSIVE={"ALL"}; //ALL=> any number of all particle types


};

#endif //ifdef Pi2
