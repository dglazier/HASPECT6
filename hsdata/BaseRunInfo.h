//Base class
//Experiemnt should derive their own derived type
//In particular LoadTree must be defined (see example in BaseRunInfo.C)
//Information required 1 time per run
#ifndef HS_BASERUNINFO_h
#define HS_BASERUNINFO_h

#include <TTree.h>

namespace HS{
  class BaseRunInfo{
    
  public :
    BaseRunInfo()=default;
    virtual ~BaseRunInfo()=default;
    
  public:

    //Class to initialse RunInfo from saved file
    virtual void LoadTree(TString filename)=0;
    
  };
}//namespace HS
#endif //
  
