////////////////////////////////////////////////////////////////
///
///Class:               PlotResults
///Description:
///           

#ifndef HS_FIT_PLOTRESULTS_h
#define HS_FIT_PLOTRESULTS_h

#include "Setup.h"
#include <RooDataSet.h>
#include <RooHist.h>
#include <TList.h>

namespace HS{
  namespace FIT{

    using roohist_uptr=std::unique_ptr<RooHist>;
    
    class PlotResults  {
      
    public:
      PlotResults(Setup *setup,RooDataSet& data);
      PlotResults()=default;
      PlotResults(const PlotResults&)=default;
      PlotResults(PlotResults&&)=default;
      virtual ~PlotResults()=default;
      PlotResults& operator=(const PlotResults& other)=default;
      PlotResults& operator=(PlotResults&& other) = default;
      
    protected:
      
    private:

      std::unique_ptr<TList> fCanvases{new TList()};
      std::vector<roohist_uptr> fRooHists;
    };
    
  }//namespace FIT
}//namespace HS

#endif
