#ifndef HS_SPLOT_h
#define HS_SPLOT_h

#include "HSRooFit.h"
#include <RooStats/SPlot.h>

namespace HS{
  namespace FIT{
    
    class HSsPlot : public HSRooFit {
      
    protected:
      RooStats::SPlot* fSPlot=nullptr; //!  //sPlot object
      HS::Weights* fWeights=nullptr; //! new weights calcualted in this fit
      Double_t fSRange[2];
      Bool_t fSaveWeights=kTRUE;
    public:
      HSsPlot() ;//default constructor, must not allocate memory!!!
      HSsPlot(TString name);
      HSsPlot(TString name,RooWorkspace *ws);
      HSsPlot(HSsPlot* rf) ;
      virtual ~HSsPlot();


      HS::Weights* GetWeights(){return fWeights;}
      RooWorkspace* GetWorkSpace(){return fWS;}
      //virtual Bool_t  InitialiseFit();
      //sPlot functions
      void sPlot();
      void SetSPlotRange(Double_t min,Double_t max){fSRange[0]=min,fSRange[1]=max;};
      void MergeModelSpecies();
      void SetSingleSpecies(TString ssp){fSingleSp=ssp;};
      void SetIDBranchName(TString str){
	fIDBranchName=str;
	fID=dynamic_cast<RooRealVar*>((fWS->factory(str+"[0,9.99999999999999e14]")));
	fWS->defineSet("ID",RooArgSet(*fID));
      }
      Double_t GetSWeight(Long64_t event,TString species);
      void ExportWeights(TString wmname="WeightMap");
      void ExportWeights1(TString wmname="WeightMap");
      void ExportTreeWeights(TString wmname="WeightMap");
      void ExportWeightsToFile(TString filename);
      void AddWeightMap(HS::Weights* Wts);
      void DrawTreeVar(TString VarName,Int_t nbins,Double_t hmin,Double_t hmax);
      // void CorrelationWithVars(TString VarName);
      void AddSubWeights();
      HSRooFit* CreateSubFitBins(TTree* ctree,TString rfname,Bool_t CopyTree) override;
      void SaveHists(TString filename);
      // virtual void RunWeights(Int_t Nfits=1);
      // virtual void RunSingleWeights(Int_t Nfits);
      void SetWeights(HS::Weights* wts){fWeights=wts;}
      void DeleteWeights(){if(fWeights)delete fWeights;fWeights=nullptr;};
      void RunAFit(Int_t Nfits) override;
      void FitSavedBins(Int_t Nfits,Bool_t cleanup=kTRUE) override;
      void FitBatchBin(Int_t Nfits, TString DataFileName) override;
      void DefaultFitOptions() override;
      
      void SetSaveWeights(Bool_t save=kTRUE){fSaveWeights=save;}
  
      ClassDefOverride(HSsPlot, 1);  // RooFit interface fit class, 

    };//class HSsPlot
  }//namespace FIT
}//namespace HS

#endif //ifdef THSROOFIT
