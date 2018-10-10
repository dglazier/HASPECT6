#ifndef HS_CLASSKELETON_h
#define HS_CLASSKELETON_h

#include "FSSkeleton.h"
#include <TString.h>
#include <TObjArray.h>

namespace HS{
  
  class CLASSkeleton : public FSSkeleton  {
    
    
  public :
    
    CLASSkeleton()=default;
    virtual ~CLASSkeleton()=default;
    
  public :
    
    //  void MakeCode() override;


  protected:

    //For derived classes to add additional functionality
    void DeclareExtras() override { DeclareCLAS();}
    void DefineExtras() override {DefineCLAS();};

    void CreateTopoFuncs() override;
    void DefineCLAS();
    void DeclareCLAS();

  };
}//namespace HS

#endif 
