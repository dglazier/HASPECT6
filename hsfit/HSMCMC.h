//Derived from RooStats::MCMCCalculator

#ifndef HSMCMC_h
#define HSMCMC_h

#include "RooStats/MCMCCalculator.h"
#include "RooStats/ModelConfig.h"
#include "RooStats/MarkovChain.h"
#include "RooAbsData.h"
#include "RooMinimizer.h"
#include "TTree.h"

class RooNDKeysPdf;
class RooProduct;
class Heaviside;

namespace HS{
  namespace FIT{
    
 
    class HSMCMC : public RooStats::MCMCCalculator {
  
    public:
      /// default constructor
      HSMCMC();
      //  HSMCMC();
  
      /// Constructor for automatic configuration with basic settings and a
      /// ModelConfig.  Uses a UniformProposal, 10,000 iterations, 40 burn in
      /// steps, 50 bins for each RooRealVar, determines interval by histogram,
      /// and finds a 95% confidence interval.  Any of these basic settings can
      /// be overridden by calling one of the Set...() methods.
      HSMCMC(RooAbsData& data, const RooStats::ModelConfig& model);
  
      virtual ~HSMCMC();
  
      void MakeChain();
      TTree* GetTree(){return fTreeMCMC;}
      RooProduct* GetKeys(){return fProduct;}
      Double_t SumWeights();
      Double_t SumWeights2();

      void NoWeightCorrection(){fCorrectForWeights=kFALSE;}

      void CreateKeysPdf();
      RooFitResult *Save();
      Double_t NLL(){return fChain->NLL();}
      //TMatrixDSym* CovMatrix(){return fChainData->corrcovMatrix()};
    private:

      TTree* fTreeMCMC=nullptr;

      RooStats::MarkovChain* fChain =nullptr;
      RooDataSet* fChainData=nullptr;
      RooArgSet* fParams=nullptr;
  
      RooNDKeysPdf* fKeysPdf=nullptr; // the kernel estimation pdf
      RooProduct* fProduct=nullptr; // the (keysPdf * heaviside) product
      RooStats::Heaviside* fHeaviside=nullptr; // the Heaviside function
      RooRealVar* fCutoffVar = nullptr ;
  
      Bool_t fCorrectForWeights=kTRUE;

      // ClassDef(HSMCMC,1) // Markov Chain Monte Carlo calculator for Bayesian credible intervals
    }; //Class HSMCMC

  }//namespace FIT
}//namespace HS

#endif
