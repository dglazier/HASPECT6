////////////////////////////////////////////////////////////////
///
///Class:               HSMetropolisHastings
///Description:
///           

#pragma once

#include <RooStats/MetropolisHastings.h>

namespace HS{
  namespace FIT{

    
    class HSMetropolisHastings : public RooStats::MetropolisHastings {
      
    public:
      HSMetropolisHastings()=default;
      HSMetropolisHastings(const HSMetropolisHastings&)=default;
      HSMetropolisHastings(HSMetropolisHastings&&)=default;
      virtual ~HSMetropolisHastings()=default;
      HSMetropolisHastings& operator=(const HSMetropolisHastings& other)=default;
      HSMetropolisHastings& operator=(HSMetropolisHastings&& other) = default;

      void SetKeepStart(){fRandomiseStart=kFALSE;}

      RooStats::MarkovChain* ConstructChain() override;
    protected:
      Bool_t wasEvalErrors();
    private:
      Bool_t fRandomiseStart=kTRUE;
      
     };
    
  }//namespace FIT
}//namespace HS

