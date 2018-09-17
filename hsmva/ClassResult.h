#ifndef HSMVA_CLASSRESULT1_h
#define HSMVA_CLASSRESULT1_h

#include "ResultInterface.h"

namespace HSMVA{

  class ClassResult : public ResultInterface{

  public :

    ClassResult()=default;
    ClassResult(TString name,TString varlist,TString methodname,TString weightfile);
    ClassResult(TString trainpath,TString methodname):ResultInterface(trainpath,methodname){};
    ClassResult(TString name):ResultInterface(name){};
    virtual ~ClassResult()=default;


    using ResultInterface::Eval;
    Float_t Eval() override;
 
  private :

 
  protected:   
    ClassDefOverride(ClassResult,1);  // General classification result
  };

} //namespace HSMVA

inline Float_t HSMVA::ClassResult::Eval(){
  Float_t result=Method()->GetMvaValue();
  return result;
}
#endif //HSMVA_CLASSRESULT_h
