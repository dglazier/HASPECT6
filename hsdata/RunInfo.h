//Information required 1 time per run
#ifndef HS_RUNINFO_h
#define HS_RUNINFO_h

#include <TTree.h>

namespace HS{
  class RunInfo{
    
  public :
    RunInfo()=default;
    virtual ~RunInfo()=default;
    
  protected :
    // TTree* fTree=nullptr; //! Tree containg this RunInfo class
    Float_t fTotCharge=0; //total gated charge for run
    Float_t fMeanCurrent=0; //average current (needs attenuation factor)
    Int_t fNRun=0;//Run Number
    Short_t fType=0;//Event Type (Data 0  or MC 1)
    
    
  public:
    Int_t NRun(){return fNRun;}
    void SetNRun(Int_t st){fNRun=st;}
    Short_t Type(){return fType;}
    void SetType(Short_t st){fType=st;}
    Float_t TotalCharge(){return fTotCharge;}
    void SetTotalCharge(Float_t st){fTotCharge=st;}
    void SetMeanCurrent(Float_t st){fMeanCurrent=st;}
    Float_t MeanCurrent(){return fMeanCurrent;}
    
    void LoadTree(TString filename);
    
  };
}//namespace HS
#endif //
  
