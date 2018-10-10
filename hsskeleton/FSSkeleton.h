#ifndef HS_FSSKELETON_h
#define HS_FSSKELETON_h

#include "Skeleton.h"
#include <TString.h>
#include <TObjArray.h>

namespace HS{
  
  class FSSkeleton : public Skeleton  {
    
    
  public :
    
    FSSkeleton()=default;
    virtual ~FSSkeleton()=default;
    
  public :
    
    void MakeCode() override;

    void SetFinalState(TString proj){fFinalName=proj;}
    void SetFinalStateTopo(TString topos){fFinalTopo=topos;fFinalTopo.ReplaceAll(" ","");};
    void SetFinalStateParts(TString finals){fFinalParts=finals;fFinalParts.ReplaceAll(" ","");};
    void SetFinalStateParents(TString finals){fFinalParents=finals;fFinalParents.ReplaceAll(" ","");};


  protected:

    //For derived classes to add additional functionality
    virtual void DeclareExtras(){};
    virtual void DefineExtras(){};

    //Code writing functions
    virtual void DeclareInit();    
    virtual void DeclareDetected();    
    virtual void DeclareParents();    
    virtual void DefineDetected();    
    virtual void DefineParents();    
    virtual void DefineTopologies();    
    virtual void DefineIterators();    
    virtual void CreateRunMacros();    
    virtual void CreateTreeData();    
    virtual void CreateTopoFuncs();    
    virtual void CreateKinematics();    

    //Loader for using classes in ROOT
    virtual void CreateLoader();

    TString fFinalName;
    TString fFinalTopo;
    TString fFinalParts;
    TString fFinalParents;
    TString fHSSKEL;
    TObjArray* fTopos=nullptr;
    TObjArray* fFinals=nullptr;
    TObjArray* fParents=nullptr;

 };
}//namespace HS

#endif 
