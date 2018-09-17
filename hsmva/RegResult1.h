#ifndef HSMVA_REGRESULT1_h
#define HSMVA_REGRESULT1_h

#include "ResultInterface.h"

namespace HSMVA{

  class RegResult1 : public ResultInterface{

  public :

    RegResult1()=default;
    RegResult1(TString name,TString varlist,TString methodname,TString weightfile);
    RegResult1(TString trainpath,TString methodname):ResultInterface(trainpath,methodname){};
    RegResult1(TString name):ResultInterface(name){};
    virtual ~RegResult1()=default;


    using ResultInterface::Eval;
    Float_t Eval() override;
 
    void AddDToTree(TString filename,TString treename,TString target);

  private :


  protected:   
    ClassDefOverride(RegResult1,1);  // General single value regression result
  };

} //namespace HSMVA

inline Float_t HSMVA::RegResult1::Eval(){
  Float_t result=Method()->GetRegressionValues()[0];
  return result;
}
#endif //REGRESULT1_h
