////////////////////////////////////////////////////////////////
///
///Class:               sPlot
///Description:
///           

#ifndef HS_FIT_SPLOT_h
#define HS_FIT_SPLOT_h

#include "FitManager.h"
#include "Setup.h"
#include "Weights.h"
#include <RooStats/SPlot.h>
 
namespace HS{
  namespace FIT{

    using splot_uptr = std::unique_ptr<RooStats::SPlot>;
    using weights_ptr =std::shared_ptr<HS::Weights>;
    using weights_uptr =std::unique_ptr<HS::Weights>;
    
    class sPlot  : public FitManager{
      
    public:
      sPlot()=default;
      sPlot(const sPlot&)=default;
      sPlot(sPlot&&)=default;
      virtual ~sPlot()=default;
      sPlot& operator=(const sPlot& other) = default;
      sPlot& operator=(sPlot&& other) = default;
      
      void Run(UInt_t ifit=0) override;
 
      void Clear(UInt_t ifit) override{
	FitManager::Clear(ifit);
        fSPlot.reset();
	 // fWeights->Save();//don't save if single bin so we can dr
	fWeights.reset();
       }

      void CreateWeights();
      void ExportWeights();
      weights_uptr MergeWeights();
      filed_uptr WeightedTree(TString wname);
    protected:
      
    private:
      splot_uptr fSPlot; //sPlot object
      weights_ptr fWeights;
      
    };
    
  }//namespace FIT
}//namespace HS

#endif
