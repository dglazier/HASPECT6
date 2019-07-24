#pragma once

#include "RooAbsPdf.h"
#include "RooHSEventsPDF.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooRealVar.h"
#include "RooCategory.h"
#include "RooAbsCategory.h"
#include "RooFormulaVar.h"
#include <vector>
 
namespace HS{
  namespace FIT{
 
    class RooComponentsPDF : public HS::FIT::RooHSEventsPDF {
     
      using vecUPtrReal = std::vector<unique_ptr<RooRealProxy>>;
      using vecUPtrCat = std::vector<unique_ptr<RooCategoryProxy>>;
      using vecComponents = std::vector<vecUPtrReal>;
 
    public:
      RooComponentsPDF() {} ; 
      RooComponentsPDF(const char *name, const char *title,Double_t base,const RooArgList& obsList,const vector<RooArgList> compList);
      RooComponentsPDF(const RooComponentsPDF& other, const char* name=0) ;
      TObject* clone(const char* newname) const override { return new RooComponentsPDF(*this,newname); }
      inline virtual ~RooComponentsPDF()=default;

      
      Double_t analyticalIntegral(Int_t code,const char* rangeName) const override;

      Bool_t SetEvTree(TTree* tree,TString cut,Long64_t ngen=0) override;
      void HistIntegrals(const char* rangeName) const override;
      void CalcWeightedBaseLine(const char* rangeName) const;

    protected:
  
      Double_t evaluateData() const override ;
      Double_t evaluateMC(const vector<Float_t> *vars,const  vector<Int_t> *cats) const override;
      void MakeSets();
      void RecalcComponentIntegrals(Int_t code,const char* rangeName) const;
      Double_t componentIntegral(Int_t icomp) const;
      void initIntegrator() override;
 
    private:

      RooListProxy fActualObs;
      RooListProxy fActualCats;
      RooListProxy fActualComps;
      
      vecComponents fComponents;
      vecUPtrReal fObservables;
      vecUPtrCat fCategories;

      vector<vector<RooRealProxy*>> fDependentTermProxy;
      vector<vector<RooRealVar*>> fDependentTermParams;
      vector<vector<RooRealProxy*>> fIndependentTermProxy;

      
      vector<RooRealVar*> fIntegrateObs;
      vector<RooCategory*> fIntegrateCats;
      RooArgSet fIntegrateSet;
      
      mutable vector<Double_t> fCacheCompDepIntegral;
      mutable vector<vector<Double_t>> fPrevParVals;
      mutable vector<UInt_t> fRecalcComponent;
      
      RooArgSet fParameters;
 
      Double_t fBaseLine=0;
      mutable Double_t fWeightedBaseLine=0;
      UInt_t fNObs=0;
      UInt_t fNCats=0;
      UInt_t fNComps=0;
      ClassDefOverride(RooComponentsPDF,1);
    };

    template<typename T, typename A>
      bool vecContains( T arg, std::vector<T,A> const& vec ) {
      if(std::find(vec.begin(),vec.end(),arg) == vec.end())
	return false;
      return true;
    }


  }
}
