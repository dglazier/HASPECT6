
#ifndef K2_h
#define K2_h

#include "FinalState.h"
#include "THSParticle.h"
#include "CLASTrigger.h"
//#include "TreeData.h"
#include "TreeDataK2.h"
#include <vector>

class TreeDataK2;

class K2 : public HS::FinalState{

 public :
  K2(TString pid="NONE",TString inc="ALL");
  virtual ~K2()=default;



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
  HS::CLASTrigger fTrigger;//For CLAS trigger info

  //Initial state
  HS::HSLorentzVector fTarget=HS::HSLorentzVector(0,0,0,0.938272);

  //Final Particles Detected
  HS::THSParticle fBeam=HS::THSParticle(-22);
  HS::THSParticle fProton=HS::THSParticle("proton");
  HS::THSParticle fKp=HS::THSParticle("K+");
  HS::THSParticle fKm=HS::THSParticle("K-");
 
  //Final Parents
 
  //Tree Output Data
  TreeDataK2 TD;

 
  //Topology Configuration options
  TString fPID={"NONE"}; //NONE=>No PIDs 
  TString  fINCLUSIVE={"ALL"}; //ALL=> any number of all particle types


};

#endif //ifdef K2
