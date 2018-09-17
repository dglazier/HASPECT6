#ifndef HSMVA_RESULTREG1_h
#define HSMVA_RESULTREG1_h

#include "ResultInterface.h"

namespace HSMVA{

  class ResultReg1 : public ResultInterface{

  public :

    ResultReg1()=default;
    ResultReg1(TString name,TString varlist,TString methodname,TString weightfile);
    ResultReg1(TString trainpath,TString methodname):ResultInterface(trainpath,methodname){};
    ResultReg1(TString name):ResultInterface(name){};
    virtual ~ResultReg1()=default;


    using ResultInterface::Eval;
    Float_t Eval() override;
 
    void AddDToTree(TString filename,TString treename,TString target);

  private :


  protected:   
    ClassDefOverride(ResultReg1,1);  // General single value regression result
  };

} //namespace HSMVA

inline Float_t HSMVA::ResultReg1::Eval(){
  Float_t result=Method()->GetRegressionValues()[0];
  return result;
}
#endif //REGRESULT1_h
