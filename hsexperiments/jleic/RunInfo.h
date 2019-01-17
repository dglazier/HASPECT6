//Information required 1 time per run
#ifndef HS_JLEIC_RUNINFO_h
#define HS_JLEIC_RUNINFO_h

#include "BaseRunInfo.h"
#include <TTree.h>

namespace HS{
     class RunInfo : public BaseRunInfo{
      
    public :
      RunInfo()=default;
      virtual ~RunInfo()=default;
      
      void LoadTree(TString filename) final;
      
    public:
       
      Int_t fNRun=0;//Run Number
      Short_t fType=0;//Event Type (Data 0  or MC 1)
      
      
    };
 }//namespace HS
#endif //
  
