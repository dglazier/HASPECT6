#include "HSSequentialProposal.h"
#include <iostream>
#include <memory>
#include <TIterator.h>
#include <RooRandom.h>
#include <RooStats/RooStatsUtils.h>
 
namespace HS{
  namespace FIT{


    // Populate xPrime with a new proposed point
    void HSSequentialProposal::Propose(RooArgSet& xPrime, RooArgSet& x )
    {
      RooStats::SetParameters(&x, &xPrime);
      RooLinkedListIter it(xPrime.iterator());
      RooRealVar* var;
      int n = xPrime.getSize();
      int j = int( floor(RooRandom::uniform()*n) );
      for (int i = 0; (var = (RooRealVar*)it.Next()) != NULL; ++i) {
        if (i == j) {
          double val = var->getVal(), max = var->getMax(), min = var->getMin(), len = max - min;
          val += RooRandom::gaussian() * len * fDivisor;
          while (val > max) val -= len;
          while (val < min) val += len;
          var->setVal(val);
          //std::cout << "Proposing a step along " << var->GetName() << std::endl;
        }
      }
    }
  
    Bool_t HSSequentialProposal::IsSymmetric(RooArgSet& , RooArgSet& ) {
      return true;
    }
  
    // Return the probability of proposing the point x1 given the starting
    // point x2
    Double_t HSSequentialProposal::GetProposalDensity(RooArgSet& ,
						    RooArgSet& )
    {
      return 1.0; // should not be needed
    }
  
  }
}
