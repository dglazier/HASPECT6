//Information required 1 time per run
#ifndef HS_CLAS12_RUNINFO_h
#define HS_CLAS12_RUNINFO_h

#include "BaseRunInfo.h"
#include <TTree.h>

namespace HS{
  namespace CLAS12{
    class RunInfo : public BaseRunInfo{
      
    public :
      RunInfo()=default;
      virtual ~RunInfo()=default;
      
      void LoadTree(TString filename) final;
      
    public:
      Float_t fTotCharge=0; //total gated charge for run
      Float_t fMeanCurrent=0; //average current (needs attenuation factor)
      Int_t fNRun=0;//Run Number
      Short_t fType=0;//Event Type (Data 0  or MC 1)
      
      
    };
  }//namespace CLAS12
}//namespace HS
#endif //
  
