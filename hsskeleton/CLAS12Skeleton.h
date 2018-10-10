#ifndef HS_CLAS12SKELETON_h
#define HS_CLAS12SKELETON_h

#include "FSSkeleton.h"
#include <TString.h>
#include <TObjArray.h>

namespace HS{
  
  class CLAS12Skeleton : public FSSkeleton  {
    
    
  public :
    
    CLAS12Skeleton()=default;
    virtual ~CLAS12Skeleton()=default;
    
  public :
    
    //  void MakeCode() override;


  protected:

    //For derived classes to add additional functionality
    void DeclareExtras() override { DeclareCLAS12();}
    void DefineExtras() override {DefineCLAS12();};

    void CreateRunMacros() override;
    void CreateTopoFuncs() override;
    void DefineCLAS12();
    void DeclareCLAS12();

  };
}//namespace HS

#endif 
