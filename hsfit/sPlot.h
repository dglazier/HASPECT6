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
    using tree_uptr =std::unique_ptr<TTree>;
    
    class sPlot  : public FitManager{
      
    public:
      sPlot()=default;
      sPlot(const sPlot&)=default;
      sPlot(sPlot&&)=default;
      virtual ~sPlot()=default;
      sPlot& operator=(const sPlot& other) = default;
      sPlot& operator=(sPlot&& other) = default;
      
      void Run(UInt_t ifit=0) override;
 
      void Reset(UInt_t ifit) override{
	FitManager::Reset(ifit);
        fSPlot.reset();
	//	fWeights->PrintWeight();
	fWeights.reset();
       }

      void CreateWeights();
      void ExportWeights();
      weights_uptr MergeWeights();
      void DrawWeighted(TString var,TString wname,TString cut="1",TString opt="");

      void WriteThis() override;
    protected:
      void WeightedTree();
    
    private:
      splot_uptr fSPlot; //!sPlot object
      weights_ptr fWeights;//!
      tree_uptr fWeightedTree;//!

      ClassDefOverride(HS::FIT::sPlot,1);
    };
    
  }//namespace FIT
}//namespace HS

#endif
