////////////////////////////////////////////////////////////////
///
///Class:               sPlot
///Description:
///           

#ifndef HS_FIT_SPLOT_h
#define HS_FIT_SPLOT_h

#include "FitManager.h"
#include "Setup.h"
#include <RooStats/SPlot.h>
 
namespace HS{
  namespace FIT{

    using splot_uptr = unique_ptr<RooStats::SPlot>;
    
    class sPlot  : public FitManager{
      
    public:
      sPlot()=default;
      sPlot(const sPlot&)=default;
      sPlot(sPlot&&)=default;
      virtual ~sPlot()=default;
      sPlot& operator=(const sPlot& other) = default;
      sPlot& operator=(sPlot&& other) = default;
      
      void Run(UInt_t ifit=0) override;
 
      
    protected:
      
    private:
      splot_uptr fSPlot; //sPlot object

    };
    
  }//namespace FIT
}//namespace HS

#endif
