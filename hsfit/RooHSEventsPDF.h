#ifndef ROOHSEVENTSPDF
#define ROOHSEVENTSPDF

#include "RooAbsPdf.h"
#include "RooArgSet.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "Weights.h" 
#include "TTree.h" 
#include "TH1F.h" 
#include "TVector.h" 
#include "TChain.h" 
#include "TEntryList.h"
#include "TDirectory.h"
#include <vector>
#include <map>


namespace HS{
  namespace FIT{
    
    Bool_t RooHSEventsPDF_IsPlotting=kFALSE;

    
    class RooHSEventsPDF : public RooAbsPdf {
    public:
    RooHSEventsPDF(const char *name, const char *title):
      RooAbsPdf(name,title){};
      
      RooHSEventsPDF(const RooHSEventsPDF& other, const char* name=0);
      
      //virtual TObject* clone(const char* newname) const { return new RooHSEventsPDF(*this,newname); }

      RooHSEventsPDF(){}; 
      virtual ~RooHSEventsPDF();
  
    protected:
      RooHSEventsPDF* fParent=nullptr;//!
      TTree* fEvTree=nullptr;//!
      TEntryList* fEntryList=nullptr;//!
      HS::Weights* fWeights=nullptr;//!  //weights for event generator
      HS::Weights* fInWeights=nullptr; //weights for shaping the events tree
      Double_t fConstInt=1;
      Int_t fLastLength;
      Float_t *fLast=nullptr; //[fLastLength]
      mutable vector<TH1F> fHistIntegrals;
      vector<Float_t> fEvWeights; //read in weights saved in vector
      vector<Float_t> fvecReal;
      vector<Float_t> fvecRealGen;
      vector<Int_t> fvecCat;
      vector<Int_t> fvecCatGen;
      vector<Int_t> fGotGenVar; //for generating events
      vector<Int_t> fGotGenCat; //for generating events
      Long64_t fNInt=-1;
      Long64_t fNMCGen=0; //Number of generated MC events
      Long64_t fNTreeEntries=0;
      Long64_t fIntRangeLow=0;
      Long64_t fIntRangeHigh=0;
      mutable Long64_t fTreeEntry=0;
      Int_t fNRanges=1;
      Int_t fCheckInt=0;
      Int_t fNpars=0;
      Int_t fNvars=0;
      Int_t fNcats=0;
      Bool_t fBranchStatus=kTRUE;
      Bool_t fIsIntegrating=kFALSE;
      Bool_t fIsClone=kFALSE;
      Bool_t fForceConstInt=kFALSE;
      Bool_t fForceNumInt=kFALSE;
      Bool_t fUseWeightsGen=kFALSE;
      Bool_t fUseEvWeights=kFALSE;
      Bool_t fIsValid=kTRUE;

      HS::WeightsConfig fWgtsConf;
      //      TString fWgtSpecies;
      //TString fWgtsFile;
      //TString fWgtsName;
      
      TString fCut; //cut for applying to event tree
      TString fInWeightCut; //additional cut for applying to event tree
 
      vector< RooArgSet* > fVarSet;//set of variables for which integral defined
      vector< RooRealProxy* > fProxSet; //double observbles
      vector< RooCategoryProxy* > fCatSet; //int observbles
      vector< RooRealProxy* > fParSet;
      vector<Bool_t> fIsCat;
  
      void InitSets();
      RooArgSet VarSet(Int_t iset) const;
    
      Double_t fMaxValue=0; //max value of function for accept/reject
      Long64_t fGeni=0; //index for tree generation
      TString fgenStr="gen";
      mutable Int_t fIntCounter=0;
      Bool_t fIsPlotting=kFALSE;
      
      void LoadInWeights();
      virtual void HistIntegrals(const char* rangeName) const;
      void SetLowHighVals(Long64_t& ilow,Long64_t& ihigh) const;

      virtual  Double_t evaluateData() const {return 0;}
      virtual void initIntegrator();

    public:
 
      Int_t getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars,const char* rangeName) const override;
      Double_t analyticalIntegral(Int_t code,const char* rangeName) const override;

      void generateEvent(Int_t code) override;
      Int_t getGenerator(const RooArgSet& directVars, RooArgSet &generateVars, Bool_t staticInitOK) const override;
      void initGenerator(Int_t code) override;
   
      //require an evaluateMC class to return same as evaluate but with
      //variables from fEvTree, it would be nicer to just use evaluate
      //but use of RooProxy variables complicates it
      virtual Double_t evaluateMC(const vector<Float_t> *vars,const  vector<Int_t> *cats) const {return 0.;};

      //Users may override this evaluate or define evaluateData()
      //This allows for correct acceptance correction for 1D plotting
      Double_t evaluate() const override{
	if(!HS::FIT::RooHSEventsPDF_IsPlotting)return evaluateData();
	if(fHistIntegrals.size()!=0){
	  if(fProxSet.size()==1)
	    return fHistIntegrals[0].Interpolate(*fProxSet[0]); 
	}
	return evaluateData();
      }
       
      
      Bool_t CheckChange() const; //Have any fit parameters changed since last integral?
      Bool_t CheckRange(const char* rangeName) const; //only integrate EvTree over specifed variable range

      void SetNInt(Long64_t n){fNInt=n;}
      // virtual Bool_t SetEvTree(TChain* tree,TString cut,Long64_t ngen=0);
      virtual Bool_t SetEvTree(TTree* tree,TString cut,Long64_t ngen=0);
      /* void SetInWeights(TString species, TString weightfile,TString wobj){ */
      /* 	fWgtsConf.reset(new HS::WeightsConfig(species,weightfile,wobj)); */
      /* } */
      void SetInWeights(HS::WeightsConfig& wcon){
	fWgtsConf.Copy(wcon);
      }
      void SetInWeights(TString wst){
	if(wst==TString()) return;
	if(!wst.Contains(",")){
	  fInWeightCut=wst;
	  return;
	}
	HS::WeightsConfig wcon(wst);
	fWgtsConf.Copy(wcon);
      }
      void SetNMCGen(Long64_t N){fNMCGen=N;}
      TTree* GetEvTree(){return fEvTree;};
      //TVectorD GetMCVar(){return fMCVar;}
      TTree* GetGenTree(){fEvTree->SetEntryList(fEntryList);TTree* tree=fEvTree->CopyTree("");fEvTree->SetEntryList(0);return tree;};//whoever gets should delete
      TEntryList* GetEntryList(){return fEntryList;}
      void SetEntryList(TEntryList* elist){fEntryList=dynamic_cast<TEntryList*>(elist->Clone());}
      void SetWeights(HS::Weights *wgts){fWeights=wgts;}
      void SetUseWeightsGen(Bool_t use=kTRUE){fUseWeightsGen=use;}
      Bool_t UseWeightsGen(){return fUseWeightsGen;}
      HS::Weights* GetWeights(){return fWeights;}
      void SetGeni(Long64_t gi){fGeni=gi;if(fParent)fParent->SetGeni(gi);};
      Long64_t GetGeni(){return fGeni;}
      
      void SetConstInt(Bool_t force=kTRUE){fForceConstInt=force;}
      void SetNumInt(Bool_t force=kTRUE){fForceNumInt=force;}
      void  CheckIntegralParDep(Int_t Ntests);
      void ResetTree();
      Double_t GetIntegralWeight(Long64_t iw) const {if(!fUseEvWeights) return 1; return fEvWeights[iw];} ;
      Bool_t AddProtoData(const RooDataSet* data);
      void SetCut(TString cut){fCut=cut;};
      TString GetCut(){return fCut;}
      Double_t GetMaxValue(){return fMaxValue;}
      void SetMaxValue(Double_t val){fMaxValue=val;}
      void SetIntRange(Long64_t low,Long64_t high){fIntRangeLow=low;fIntRangeHigh=high;}
      Long64_t GetIntRangeLow() const {return fIntRangeLow;}
      Long64_t GetIntRangeHigh() const {return fIntRangeHigh;}
      void SetNRanges(Int_t nr){fNRanges=nr;}
      void SetNextRange(Int_t ir);
      RooHSEventsPDF* GetParent(){return fParent;}
      Bool_t IsValid(){return fIsValid;}
      void Plotting(Bool_t plotting=kTRUE){fIsPlotting=plotting;}
      void SetHistIntegrals(vector<TH1F> &hists){fHistIntegrals=hists;}
      ClassDefOverride(RooHSEventsPDF,1); // Yor description goes here...
    };//Class RooHSEventsPDF
  } //namespace FIT
}//namespace HS
#endif

