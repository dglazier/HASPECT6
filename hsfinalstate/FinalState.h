
#ifndef HS_FINALSTATE_h
#define HS_FINALSTATE_h

#include <TString.h>
//#include <TNamed.h>
#include <TTree.h>
#include <TStopwatch.h>
#include <vector>
#include <functional>
#include <map>
#include <climits>


#include "THSParticle.h"
#include "ParticleIter.h"
#include "HSKinematics.h"
#include "BaseRunInfo.h"
#include "BaseEventInfo.h"
#include "TopoActionManager.h"

    

namespace HS{

  class Topology;
  class ParticleConfig;
  class Kinematics;
  class DataManager;
  
  //Typedef for pointer to function
  //used to link a derived class function with using its data members
  //To a function call in AddTopology and link to a call in Topology 
    using VoidFuncs= std::function<void()>;

    class FinalState{

      using vecTopologies = vector<Topology* >;

    public :
      FinalState();
      virtual ~FinalState()=default;

      //virtual void GetEvent(Long64_t uid){}//interface to different readers
      virtual Bool_t WorkOnEvent();
      virtual void FinaliseEvent(){fCurrTopo=nullptr;};
      virtual void InitEvent(){fGotCorrectOne=kFALSE;  fNPerm=0; fTopoID=-1;fNTried=0;};
      virtual void InitFS();
      virtual void FileStart(){};

      void InitGenerated();
      void InitDetected();
  //  virtual void Kinematics(){return;};
      virtual void Kinematics()=0;
      virtual void UserPostTopo()=0;
      void SetDetParts(vector<THSParticle> * dpp){frDetParts=dpp;}
      //void SetDetPIDs(vector<Short_t> * dpp){frDetPIDs=dpp;}
      void SetGenParts(vector<THSParticle> * dpp){frGenParts=dpp;}
      //void SetEventInfo(shared_ptr<EventInfo> in) {fEventInfo=in;}
      //void SetRunInfo(shared_ptr<RunInfo> in) {fRunInfo=in;}
      void SetEventInfo(BaseEventInfo* in) {fEventInfo=in;}
      void SetRunInfo(BaseRunInfo* in) {fRunInfo=in;}
  
      void AddTopology(TString topo,VoidFuncs funcI,VoidFuncs funcE,TString chPID="",TString incl="");
      void AddNamesTopology(TString names,VoidFuncs funcI,VoidFuncs funcE,TString chPID="",TString incl="");
      
      Topology* FindTopology(); //For current event
      //Bool_t CheckForATopology();
      virtual  Bool_t CheckParticle(THSParticle* part);
    
      void AddParticle(THSParticle* part,Bool_t AddToFinal,Int_t genID);
      void AddParticle(TString name,THSParticle* part,Bool_t AddToFinal,Int_t genID);
      void ConfigParent(THSParticle* parent,THSParticle* child);
      vector<ParticleConfig* > HowManyParticles(Int_t pdg);
      THSParticle* GetParticle(TString name);
      const vecTopologies* GetTopologies(){return &fTopos;}
  
      //void SetPermutate(Bool_t tryp){fTryPerm=tryp;} //Turn on permuations
      void SetInclusive(TString parts="");
      void SetMaxParticles(UInt_t max){fMaxPart=max;}
      void SetGenerated(Bool_t gen=kTRUE){fIsGenerated=gen;}
      void SetUseChargePID(Bool_t gen=kTRUE){fUseChargePID=gen;}

      void SetDataManager(shared_ptr<DataManager> dm);

      void RegisterPostWorkAction(TopoActionManager* tam){fPostWorkAction.push_back(tam);}
      void RegisterPostTopoAction(TopoActionManager* tam){fPostTopoAction.push_back(tam);}

      void Finish();
      Bool_t IsGoodEvent(){return fGoodEvent;}
      Bool_t IsPermutating(){ return fTryPerm*(fIsPermutating0+fIsPermutating1);}

      void ProcessEvent();
      Bool_t FSProcess();
      virtual void UserProcess();
      virtual void ProcessData(const Long64_t Nev=-1);
      void FSGenProcess();
      
      virtual void MatchWithGen(THSParticle* part);  
      virtual Bool_t IsCorrectTruth(THSParticle *part);
      virtual void FinalStateOutTree(TTree* tree){tree->Branch("Final",&fFinal);};
      virtual void CheckTruth();
      void SetAccurateTruth(Float_t ang){fAccurateTruth=TMath::DegToRad()*ang;};
      void SetVerbose(Int_t ver){fPrintVerbose=ver;}
      void CheckCombi(){fCheckCombi=kTRUE;}
      Bool_t IsCorrect(){return fCorrect;}
      TTree* FinalTree(){return fFinalTree;}

    protected :
      
      //     DataManager* fData=nullptr;
      shared_ptr<DataManager> fData;
      //Run and event info
      BaseEventInfo* fEventInfo=nullptr;
      BaseRunInfo* fRunInfo=nullptr;
      
      vector<TopoActionManager*> fPostWorkAction;
      vector<TopoActionManager*> fPostTopoAction;

      Topology *fCurrTopo=nullptr;
      vecTopologies fTopos; //vector of topologies
      Int_t fTopoID=0; //Topo ID for this event
      Int_t fNTopo=0; //Number of added topologies
      
      ParticleIter* fCurrIter=nullptr;
      
      vector<Short_t> fThisTopo; //topology for this event
      vector<Int_t> fIncParts; //particle allowed to be inclusive
      //Int_t fCurrTopo=-1;
      Int_t fCheckTopo=0;
      UInt_t fMaxPart=500;//limit the number of particles allowed in event
      UInt_t fNParts=0; //Number of particles detected
      UInt_t fNGen=0; //Number of generated particles
      Int_t fNDet=0;
      Int_t fNTried=0;
      const Short_t fMISSING=-9999;
      Bool_t fGoodEvent = kTRUE;
      Long64_t fNUsedReadEvent=0; //Number of read events with at least 1 GoodEvent
      //Special behaviour for generated MC events
      Bool_t fIsGenerated=kFALSE;
      
      //For simulated events flag with correct permutation
      Int_t fCorrect=kTRUE;
      Bool_t fGotCorrectOne=kFALSE;
      //Flag to do PID by charge not given pdg code
      Bool_t fUseChargePID=kFALSE;
      Bool_t fIsInclusive=kFALSE;
      
      Int_t fPrintVerbose=0;
      //Combitorial
      Bool_t IsMissing(THSParticle* part){if(part->Detector()==fMISSING){return kTRUE;}return kFALSE;}
      //  Bool_t IsMissing(THSParticle* part){if(part->P4p()->Theta()==0){return kTRUE;}return kFALSE;}
      Bool_t fTryPerm=kTRUE;
      Bool_t fCheckCombi=kFALSE;
      Int_t fNPerm=0;
      void InitParticles(); //Allocate particles to vector for this event
      void InitDetParts(); //Fill vector based on pdg
      void InitDetPartsCharge(); //Fill vector based on charge
      Bool_t PermutateParticles(); //Permutate particles in vectors
      void FirstParticles(); //first particles in vectors
      void CheckParticles();
      void CheckCombitorial();
      vector<ParticleConfig*> fConfigs;
      
      vector<THSParticle*> fVecProtons;
      vector<THSParticle*> fVecAntiProtons;
      vector<THSParticle*> fVecNeutrons;
      vector<THSParticle*> fVecPiPs;
      vector<THSParticle*> fVecPiMs;
      vector<THSParticle*> fVecKPs;
      vector<THSParticle*> fVecKMs;
      vector<THSParticle*> fVecEls;
      vector<THSParticle*> fVecPos;
      vector<THSParticle*> fVecPi0s;
      vector<THSParticle*> fVecGams;
      vector<THSParticle*> fVecPlus;
      vector<THSParticle*> fVecMinus;
      vector<THSParticle*> fVec0;
      vector<THSParticle*> fVecBeams;
      vector<Int_t> fDetTypes;
      
      
      Int_t fIterLevel=0;
      
      
      map< Int_t , vector< THSParticle* >* > fMapPDGtoParticle;
      
      Bool_t fIsPermutating0=kFALSE;
      Bool_t fIsPermutating1=kFALSE;
      
      TTree* fFinalTree=nullptr;
      
      //Kinematics calculator
      HSKinematics fKine;
      
      //Unique event ID
      Double_t fUID=0;
      
      //Detected Particles
      vector<THSParticle >* frDetParts=nullptr;
      vector<THSParticle >* frGenParts=nullptr;
      vector<Short_t>* frDetPIDs=nullptr;
      
      //Final Particles vector for saving in output tree
      vector<THSParticle*> fFinal;
      
      std::vector<VoidFuncs> fTopoFuncs;
      std::vector<VoidFuncs> fIterFuncs;
      
      Float_t fAccurateTruth=0; //opening angle for determining truth
      
      
    public :
      
      //Particle iterator helpers
      void AutoIter();
      
      
      ParticleIter* AddSelectToSelected(ParticleIter* diter,Int_t ni,Int_t nsel,THSParticle* part0=nullptr,THSParticle* part1=nullptr,THSParticle* part2=nullptr,THSParticle* part3=nullptr,THSParticle* part4=nullptr,THSParticle* part5=nullptr,THSParticle* part6=nullptr,THSParticle* part7=nullptr,THSParticle* part8=nullptr,THSParticle* part9=nullptr);
      
      ParticleIter* AddSelectToRemainder(ParticleIter* diter,Int_t ni,Int_t nsel,THSParticle* part0,THSParticle* part1=nullptr,THSParticle* part2=nullptr,THSParticle* part3=nullptr,THSParticle* part4=nullptr,THSParticle* part5=nullptr,THSParticle* part6=nullptr,THSParticle* part7=nullptr,THSParticle* part8=nullptr,THSParticle* part9=nullptr);
  
      ParticleIter* AddSelectToRemainder(ParticleIter* diter,Int_t ni,Int_t nsel);

      ParticleIter* AddSelectXofY(Int_t ni,Int_t nsel,THSParticle* part0=nullptr,THSParticle* part1=nullptr,THSParticle* part2=nullptr,THSParticle* part3=nullptr,THSParticle* part4=nullptr,THSParticle* part5=nullptr,THSParticle* part6=nullptr,THSParticle* part7=nullptr,THSParticle* part8=nullptr,THSParticle* part9=nullptr);
      ParticleIter* AddSelectToSelected(ParticleIter* diter,Int_t ni,Int_t nsel,vector<THSParticle*> *parts);
      ParticleIter* AddSelectXofY(Int_t ni,Int_t nsel,vector<THSParticle*> *parts);
      
      ParticleIter* AddPermutateToSelected(ParticleIter* diter,THSParticle* part0=nullptr,THSParticle* part1=nullptr,THSParticle* part2=nullptr,THSParticle* part3=nullptr,THSParticle* part4=nullptr,THSParticle* part5=nullptr,THSParticle* part6=nullptr,THSParticle* part7=nullptr,THSParticle* part8=nullptr,THSParticle* part9=nullptr);

      ParticleIter* AddPermutateToRemainder(ParticleIter* diter,THSParticle* part0=nullptr,THSParticle* part1=nullptr,THSParticle* part2=nullptr,THSParticle* part3=nullptr,THSParticle* part4=nullptr,THSParticle* part5=nullptr,THSParticle* part6=nullptr,THSParticle* part7=nullptr,THSParticle* part8=nullptr,THSParticle* part9=nullptr);

      ParticleIter* AddPermutate(THSParticle* part0=nullptr,THSParticle* part1=nullptr,THSParticle* part2=nullptr,THSParticle* part3=nullptr,THSParticle* part4=nullptr,THSParticle* part5=nullptr,THSParticle* part6=nullptr,THSParticle* part7=nullptr,THSParticle* part8=nullptr,THSParticle* part9=nullptr);
  
      ParticleIter* CreateParticleIter(vector<THSParticle*> *parts,Int_t Nsel);
  
      
    };

    ///////////////////////////////////////////////////////
    ///Utility class for handling THSParticles
    class ParticleConfig{
    public:
      ParticleConfig(){}
      ParticleConfig(THSParticle* part,Int_t genID){
	fParticle=part;fGeni=genID;
      }
      ParticleConfig(TString name,THSParticle* part,Int_t genID){
	fName=name;fParticle=part;fGeni=genID;
      }
      
      virtual ~ParticleConfig(){}
      THSParticle* Particle(){return fParticle;}
      
      vector<THSParticle* >  Children(Int_t pdg);
      void AddChild(THSParticle* child){fChildren.push_back(child);}
      
      ParticleConfig* Parent(){return fParent;}
      void SetParent(ParticleConfig* parent){fParent=parent;}
      
      void SetParticleVal(THSParticle* part){
	fParticle->SetP4(part->P4p());
	fParticle->SetPDGcode(part->PDG());
	fParticle->SetVertex(part->Vertex());
      }
      UInt_t GetNChild(){return fChildren.size();};
      Int_t PDG(){return fParticle->PDG();}
      Int_t GenID(){return fGeni;}
      TString GetName(){return fName;}
      
    private:
      TString fName;
      THSParticle* fParticle=nullptr;
      ParticleConfig* fParent=nullptr;
      vector<THSParticle*> fChildren;
      
      Int_t fGeni=-1; //index in generated events if has one
      
    };
}//namespace HS

#endif //ifdef THSFINALSTATE
