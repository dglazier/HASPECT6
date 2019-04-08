////////////////////////////////////////////////////////////////
///
///Class:               RooMcmc
///Description:
///           


#pragma once


#include "Minimiser.h"
#include <RooAbsData.h>
#include <TTree.h>
#include <RooStats/ModelConfig.h>
#include <RooStats/MarkovChain.h>
#include <RooStats/ProposalFunction.h>
#include <RooFitResult.h>

namespace HS{
  namespace FIT{

    class RooMcmc  : public Minimiser {
      
    public:

    RooMcmc(Int_t Niter=100,Int_t Nburn=10, Float_t norm=0.1): fNumIters(Niter),fNumBurnInSteps(Nburn),fNorm(norm){
	SetNameTitle("HSRooMcmc","RooMcmc minimiser");
      }
      RooMcmc(const RooMcmc&)=default;
      RooMcmc(RooMcmc&&)=default;
      virtual ~RooMcmc();
      RooMcmc& operator=(const RooMcmc& other)=default;
      RooMcmc& operator=(RooMcmc&& other) = default;  

      void Run(Setup &setup,RooAbsData &fitdata) override;

      void FitTo();
      
      file_uptr SaveInfo() override;
      void AddFormulaToMCMCTree();
      
      void MakeChain();
      TTree* GetTree(){return fTreeMCMC;}
      Double_t SumWeights();
      Double_t SumWeights2();
      
      void NoWeightCorrection(){fCorrectForWeights=kFALSE;}
      
      void Result();
      Double_t NLL(){return fChain->NLL();}



      //MCMCCalculator

      void SetModel(RooStats::ModelConfig *model);

      /// Set the DataSet if not already there
      void SetData(RooAbsData& data) { fData = &data; }

      /// Set the Pdf if not already there
      void SetPdf(RooAbsPdf& pdf) { fPdf = &pdf; }

      /// Set the Prior Pdf if not already there
      void SetPriorPdf(RooAbsPdf& pdf) { fPriorPdf = &pdf; }

      /// specify the parameters of interest in the interval
      void SetParameters(const RooArgSet& set) { fPOI.removeAll(); fPOI.add(set); }

      /// specify the parameters to store in the Markov chain
      /// By default all the parameters are stored
      void SetChainParameters(const RooArgSet & set) { fChainParams.removeAll(); fChainParams.add(set); }

      /// specify the nuisance parameters (eg. the rest of the parameters)
      void SetNuisanceParameters(const RooArgSet& set) {fNuisParams.removeAll(); fNuisParams.add(set);}

      /// set the conditional observables which will be used when creating the NLL
      /// so the pdf's will not be normalized on the conditional observables when computing the NLL
      void SetConditionalObservables(const RooArgSet& set) {fConditionalObs.removeAll(); fConditionalObs.add(set);}

      /// set the global observables which will be used when creating the NLL
      /// so the constraint pdf's will be normalized correctly on the global observables when computing the NLL
      void SetGlobalObservables(const RooArgSet& set) {fGlobalObs.removeAll(); fGlobalObs.add(set);}

      /// set the proposal function for suggesting new points for the MCMC
      void SetProposalFunction(RooStats::ProposalFunction& proposalFunction)
      { fPropFunc = &proposalFunction; }

      /// set the number of iterations to run the metropolis algorithm
      void SetNumIters(Int_t numIters)
      { fNumIters = numIters; }

      /// set the number of steps in the chain to discard as burn-in,
      /// starting from the first
      void SetNumBurnInSteps(Int_t numBurnInSteps)
      { fNumBurnInSteps = numBurnInSteps; }

      void SetupBasicUsage();
      void SetKeepStart(Bool_t keep=kTRUE){fKeepStart=keep;}
      
    protected :
  
      RooStats::MarkovChain* fChain =nullptr; //!
      RooDataSet* fChainData=nullptr;//!
      TTree* fTreeMCMC=nullptr;//!
      Bool_t fCorrectForWeights=kTRUE;
      RooArgSet* fParams=nullptr;//!

      Bool_t fKeepStart=kFALSE; //randomise starting values
      
      //MCMCCalculator
      RooStats::ModelConfig *fModelConfig=nullptr;
      
      RooArgSet   fPOI;        //! parameters of interest for interval
      RooArgSet   fNuisParams; //! nuisance parameters for interval (not really used)
      RooArgSet   fChainParams; //! parameters to store in the chain (if not specified they are all of them )
      RooArgSet   fConditionalObs; //! conditional observables
      RooArgSet   fGlobalObs;     //! global observables
      RooStats::ProposalFunction* fPropFunc; //! Proposal function for MCMC integration
      RooAbsPdf * fPdf=nullptr;        //! pointer to common PDF (owned by the workspace)
      RooAbsPdf * fPriorPdf=nullptr;   //! pointer to prior  PDF (owned by the workspace)
      //RooAbsData * fData=nullptr;     //! pointer to the data (owned by the workspace)
      Int_t fNumIters; // number of iterations to run metropolis algorithm
      Int_t fNumBurnInSteps; // number of iterations to discard as burn-in, starting from the first
      Int_t fNumBins; // set the number of bins to create for each
      Int_t fWarmup; //ignore these events
      Float_t fNorm=1;
      ClassDefOverride(HS::FIT::RooMcmc,1);
      
     };

    class RooMcmcSeq  : public RooMcmc {
      
    public:

    RooMcmcSeq(Int_t Niter=100,Int_t Nburn=10, Float_t norm=0.1):RooMcmc(Niter,Nburn,norm){
	SetNameTitle("HSRooMcmcSeq","RooMcmcSeq minimiser");
      }
      RooMcmcSeq(const RooMcmcSeq&)=default;
      RooMcmcSeq(RooMcmcSeq&&)=default;
      virtual ~RooMcmcSeq()=default;
      RooMcmcSeq& operator=(const RooMcmcSeq& other)=default;
      RooMcmcSeq& operator=(RooMcmcSeq&& other) = default;  

      void Run(Setup &setup,RooAbsData &fitdata) override;

      ClassDefOverride(HS::FIT::RooMcmcSeq,1);
   };
     class RooMcmcUniform2Seq  : public RooMcmc {
      
    public:

     RooMcmcUniform2Seq(Int_t Niter=100,Int_t Nburn=10, Float_t norm=0.1): RooMcmc(Niter,Nburn,norm){
	SetNameTitle("HSRooMcmcUniform2Seq","RooMcmcUniform2Seq minimiser");
      }
      RooMcmcUniform2Seq(const RooMcmcUniform2Seq&)=default;
      RooMcmcUniform2Seq(RooMcmcUniform2Seq&&)=default;
      virtual ~RooMcmcUniform2Seq()=default;
      RooMcmcUniform2Seq& operator=(const RooMcmcUniform2Seq& other)=default;
      RooMcmcUniform2Seq& operator=(RooMcmcUniform2Seq&& other) = default;  

      void Run(Setup &setup,RooAbsData &fitdata) override;

      ClassDefOverride(HS::FIT::RooMcmcUniform2Seq,1);
     };
 
    class RooMcmcGaus  : public RooMcmc {
      
    public:

      RooMcmcGaus(Int_t Niter=100,Int_t Nburn=10, Float_t norm=0.1): RooMcmc(Niter,Nburn,norm){
	SetNameTitle("HSRooMcmcGaus","RooMcmcGaus minimiser");
      }
      RooMcmcGaus(const RooMcmcGaus&)=default;
      RooMcmcGaus(RooMcmcGaus&&)=default;
      virtual ~RooMcmcGaus()=default;
      RooMcmcGaus& operator=(const RooMcmcGaus& other)=default;
      RooMcmcGaus& operator=(RooMcmcGaus&& other) = default;  

      void Run(Setup &setup,RooAbsData &fitdata) override;

      ClassDefOverride(HS::FIT::RooMcmcGaus,1);

    };
 
  }//namespace FIT
}//namespace HS

