#include "HSMetropolisHastings.h"
#include "RooStats/RooStatsUtils.h"
#include <RooStats/MarkovChain.h>

namespace HS{
  namespace FIT{
    
    RooStats::MarkovChain* HSMetropolisHastings::ConstructChain()
    {
      if (fParameters.getSize() == 0 || !fPropFunc || !fFunction) {
	coutE(Eval) << "Critical members unintialized: parameters, proposal " <<
	  " function, or (log) likelihood function" << endl;
	return NULL;
      }
      if (fSign == kSignUnset || fType == kTypeUnset) {
	coutE(Eval) << "Please set type and sign of your function using "
		    << "MetropolisHastings::SetType() and MetropolisHastings::SetSign()" <<
	  endl;
	return NULL;
      }

      if (fChainParams.getSize() == 0) fChainParams.add(fParameters);
     
      RooArgSet x;
      RooArgSet xPrime;
      x.addClone(fParameters);
      if(fRandomiseStart)RooStats::RandomizeCollection(x);
      xPrime.addClone(fParameters);
      RooStats::RandomizeCollection(xPrime);

      
      RooStats::MarkovChain* chain = new RooStats::MarkovChain();
      // only the POI will be added to the chain
      chain->SetParameters(fChainParams);

      Int_t weight = 0;
      Double_t xL = 0.0, xPrimeL = 0.0, a = 0.0;

      // ibucur: i think the user should have the possibility to display all the message
      //    levels should they want to; maybe a setPrintLevel would be appropriate
      //    (maybe for the other classes that use this approach as well)?
      RooFit::MsgLevel oldMsgLevel = RooMsgService::instance().globalKillBelow();
      RooMsgService::instance().setGlobalKillBelow(RooFit::PROGRESS);

      // We will need to check if log-likelihood evaluation left an error status.
      // Now using faster eval error logging with CountErrors.
      if (fType == kLog) {
	RooAbsReal::setEvalErrorLoggingMode(RooAbsReal::CountErrors);
	//N.B: need to clear the count in case of previous errors !
	// the clear needs also to be done after calling setEvalErrorLoggingMode
	RooAbsReal::clearEvalErrorLog();
      }

      bool hadEvalError = true;

      Int_t i = 0;
      // get a good starting point for x
      // for fType == kLog, this means that fFunction->getVal() did not cause
      // an eval error
      // for fType == kRegular this means fFunction->getVal() != 0
      //
      // kbelasco: i < 1000 is sort of arbitrary, but way higher than the number of
      // steps we should have to take for any reasonable (log) likelihood function
      //while (i < 1000 && hadEvalError ) {
      while (i < 1000 && hadEvalError && fRandomiseStart) {
	RooStats::RandomizeCollection(x);
	RooStats::SetParameters(&x, &fParameters);
	xL = fFunction->getVal();

	if (fType == kLog) {
	  if (RooAbsReal::numEvalErrors() > 0) {
            RooAbsReal::clearEvalErrorLog();
            hadEvalError = true;
	  } else
            hadEvalError = false;
	} else if (fType == kRegular) {
	  if (xL == 0.0)
            hadEvalError = true;
	  else
            hadEvalError = false;
	} else
	  // for now the only 2 types are kLog and kRegular (won't get here)
	  hadEvalError = false;
	++i;
      }

      if(hadEvalError&&fRandomiseStart) {
	coutE(Eval) << "Problem finding a good starting point in " <<
	  "MetropolisHastings::ConstructChain() " << endl;
      }

 
      ooccoutP((TObject *)0, Generation) << "Metropolis-Hastings progress: ";

      // do main loop
      //for (i = 0; i < fNumIters; i++) {
      int icount=0;
      int totcount=0;
      int havePrinted=0;
      while (icount <fNumIters) {
	totcount++;
	// reset error handling flag
	hadEvalError = false;

	// print a dot every 1% of the chain construction
	if (icount%100 == 0&&havePrinted==0){ ooccoutP((TObject*)0, Generation) << "_"<<icount<<"/"<<fNumIters; havePrinted=1;}
	if (icount%100 == 1) havePrinted=0;
	
	fPropFunc->Propose(xPrime, x);


	RooStats::SetParameters(&xPrime, &fParameters);
	xPrimeL = fFunction->getVal();


	// check if log-likelihood for xprime had an error status
	if (wasEvalErrors() && fType == kLog) {
	  xPrimeL = RooNumber::infinity();
	  hadEvalError = true;
	}

	// why evaluate the last point again, can't we cache it?
	// kbelasco: commenting out lines below to add/test caching support
	//RooStats::SetParameters(&x, &fParameters);
	//xL = fFunction->getVal();


	if (fType == kLog) {
	  if (fSign == kPositive)
            a = xL - xPrimeL;
	  else
            a = xPrimeL - xL;
	}
	else
	  a = xPrimeL / xL;
	//a = xL / xPrimeL;


	if (!hadEvalError && !fPropFunc->IsSymmetric(xPrime, x)) {
	  Double_t xPrimePD = fPropFunc->GetProposalDensity(xPrime, x);
	  Double_t xPD      = fPropFunc->GetProposalDensity(x, xPrime);
	  if (fType == kRegular)
            a *= xPD / xPrimePD;
	  else
            a += TMath::Log(xPrimePD) - TMath::Log(xPD);
	}
	

	if (!hadEvalError && ShouldTakeStep(a)) {
	  // go to the proposed point xPrime

	  // add the current point with the current weight
	  if (weight != 0.0)
            chain->Add(x, CalcNLL(xL), (Double_t)weight);

	  // reset the weight and go to xPrime
	  weight = 1;
	  RooStats::SetParameters(&xPrime, &x);
	  xL = xPrimeL;
	  icount++;
	} else {
	  // stay at the current point
	  weight++;
	}
      }

      // make sure to add the last point
      if (weight != 0.0)
	chain->Add(x, CalcNLL(xL), (Double_t)weight);
      ooccoutP((TObject *)0, Generation) << endl;

      RooMsgService::instance().setGlobalKillBelow(oldMsgLevel);

      Int_t numAccepted = chain->Size();
      coutI(Eval) << "Proposal acceptance rate: " <<
	((float)icount)/totcount * 100 << "%" << endl;
      coutI(Eval) << "Number of steps in chain: " << numAccepted << endl;
      return chain;
    }


    Bool_t HSMetropolisHastings::wasEvalErrors(){
      if(RooAbsReal::numEvalErrors()){
	RooAbsReal::clearEvalErrorLog();
	return kTRUE;
      }
	
      // Int_t i=0;
      // RooRealVar* var=nullptr;
      // while((var=fFunction->getParameter(i++)))
      // 	if(par->numEvalErrors())
      // 	  return kTRUE;
      return kFALSE;
	    
    }
  }//namespace FIT

}//namespace HS
