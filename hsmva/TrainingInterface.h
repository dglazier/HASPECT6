#ifndef HSMVA_TRAININGINTERFACE_h
#define HSMVA_TRAININGINTERFACE_h

#include <TNamed.h>
#include "TMVA/Tools.h"
#include "TMVA/Types.h"
#include "TMVA/DataLoader.h"
#include "TMVA/MethodBase.h"
#include "MethConf.h"

namespace HSMVA{
  
  class TrainingInterface : public TNamed{

  public :
    
    TrainingInterface()=default;
    TrainingInterface(TString name,TString opt);
    virtual ~TrainingInterface();
  
    void LoadTreeVars(TTree* tree,Double_t weight=1);
    void SetNTrainTest(Long64_t ntr,Long64_t nte){fNTrain=ntr;fNTest=nte;}
    void SetCut(TCut cut){fCut=cut;}
    void IgnoreBranches(TString name);
    void OnlyTheseBranches(TTree* tree,TString v0);
    
    virtual void PrepareTrees()=0;
    virtual void Gui() = 0;
    
    void DoTraining();
    
    TMVA::Factory *Factory(){return fFactory.get();}
    TMVA::DataLoader *DataLoader(){return fDataLoader.get();}

    void BookMethod(TMVA::Types::EMVA type,TString name,TString params){
      Factory()->BookMethod(DataLoader(),type,name,params);}
    void BookMethod(MethConf meth){
      Factory()->BookMethod(DataLoader(),meth.fType,meth.fName,meth.fParams);};

    TString GetOutFileName(){return fOutFileName;}
    void SetOutDir(TString dir){fOutDir =dir;}
    TString GetOutDir(){if(fOutDir!=TString("")) return fOutDir+"/";return "";}
    
  protected:
  
    Bool_t AreVarsLoaded(){if(fLoaded) return kTRUE;return kFALSE;}
    TCut GetCut(){return fCut;}

    Int_t NTrain(){return fNTrain;}
    Int_t NTest(){return fNTest;}
    
  private :
    unique_ptr<TMVA::Factory> fFactory;
    unique_ptr<TMVA::DataLoader> fDataLoader;

    vector<TString> fIgnoreBranches;
    
    TFile* fOutputFile=nullptr;
    
    Long64_t fNTrain=1000;
    Long64_t fNTest=1000;
    
    Int_t fLoaded=0; //Not 0 when LoadTreeVars has been called
    TCut fCut="";    //Currently only 1 cut on tree allowed vis SetCut!
    TString fOutFileName="Training.root";
    TString fOutDir="";//move output directory to here
    
    ClassDef(TrainingInterface,1);  // Virtual base class for all HSMVA training
 
  }; //

} //namespace HSMVA

#endif //HSMVA_TRAININGINTERFACE_h
