////////////////////////////////////////////////////////////////
///
///Class:               ToyManager
///Description:
///           

#pragma once

#include "FitManager.h"
#include "Setup.h"
#include "Weights.h"
 
namespace HS{
  namespace FIT{

    using tree_uptr =std::unique_ptr<TTree>;
    using strings_t = std::vector<TString>;

    class ToyManager  : public FitManager{
      
    public:
      ToyManager()=default;
    ToyManager(Int_t n):fNToys(n){};
      ToyManager(const ToyManager&)=default;
    ToyManager(Int_t n,const FitManager& fm):fNToys(n), FitManager(fm){};
      ToyManager(ToyManager&&)=default;
      virtual ~ToyManager()=default;
      ToyManager& operator=(const ToyManager& other) = default;
      ToyManager& operator=(ToyManager&& other) = default;
      
      void Run() override;
      void SaveResults() override;
      Int_t GetN() override {return fNToys;}
      TString GetCurrTitle() override {return Form("Toy%d",GetFiti());}
      TString GetDataTreeName() override{return "ToyData";}
      strings_t GetDataFileNames() override{return fToyFileNames;}

      Int_t GetDataBin(Int_t ii) override{
	if(fNToys>0)
	  return (int)std::round(ii/fNToys);
	return ii;
      }
      strings_t GetToyFileNames(){return fToyFileNames;}
      
      void  Generate();

      std::shared_ptr<FitManager> Fitter();
 
      static std::shared_ptr<ToyManager> GetFromFit(Int_t N,TString filename,TString result="");
      static std::shared_ptr<ToyManager> GetFromFit(Int_t N,FitManager& fit,TString result="");
      static std::shared_ptr<ToyManager> GetFromFit(Int_t N,std::shared_ptr<FitManager> fit,TString result="");

      void Summarise();
      void PreRun() override;

      static const TString InitialParsName(){return "InitialParameters";}

    protected:
    
    private:
      RooDataSet* fGenData=nullptr;//!
     strings_t fToyFileNames;
 
     Int_t fNToys=1;
      
      ClassDefOverride(HS::FIT::ToyManager,1);
    };
    
  }//namespace FIT
}//namespace HS

