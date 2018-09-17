#ifndef HSMVA_RESULTSIGNALID_h
#define HSMVA_RESULTSIGNALID_h

#include "ResultInterface.h"

namespace HSMVA{

  class ResultSignalID : public ResultInterface{

  public :

    ResultSignalID()=default;
    ResultSignalID(TString name,TString varlist,TString methodname,TString weightfile);
    ResultSignalID(TString trainpath,TString methodname):ResultInterface(trainpath,methodname){};
    ResultSignalID(TString name):ResultInterface(name){};
    virtual ~ResultSignalID()=default;


    using ResultInterface::Eval;
    Float_t Eval() override;
 
  private :

 
  protected:   
    ClassDefOverride(ResultSignalID,1);  // General classification result
  };

} //namespace HSMVA

inline Float_t HSMVA::ResultSignalID::Eval(){
  Float_t result=Method()->GetMvaValue();
  return result;
}
#endif //HSMVA_CLASSRESULT_h
