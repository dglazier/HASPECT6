#include "Manager.h"

namespace HS{
  namespace FIT{
    void Manager::Run(UInt_t ifit){
      
      fSetup.Model()->fitTo(*fData.Get(ifit));
      fData.Clear(ifit);
      
    }
    void Manager::RunAll(){
      
      for(UInt_t i=0;i<fData.GetN();i++){
	Run(i);
      }
      
    }

  }//namespace FIT
}//namespace HS
