////////////////////////////////////////////////////////////////
///
///Class:               FitManager
///Description:
///           

#ifndef HS_FIT_FITMANAGER_h
#define HS_FIT_FITMANAGER_h

#include "Setup.h"
#include "PlotResults.h"
#include "Data.h"
#include "Binner.h"
#include "Minimiser.h"
#include "TNamed.h"
#include "RooMinimizer.h"
#include "RooMinuit.h"
#include "RooAbsData.h"
#include "RooFitResult.h"


namespace HS{
  namespace FIT{

    using dataevs_ptr=std::shared_ptr<HS::FIT::DataEvents>;
    using strings_t = std::vector<TString>;
    using plotresult_uptr=std::unique_ptr<PlotResults>;
    
    
    class FitManager  : public TNamed{
      
    public:
      FitManager()=default;
      FitManager(const FitManager&)=default;
      FitManager(FitManager&&)=default;
      virtual ~FitManager()=default;
      FitManager& operator=(const FitManager& other);
      FitManager& operator=(FitManager&& other) = default;

      Setup &SetUp() {return fSetup;};
      const Setup &ConstSetUp() {return fSetup;};

      void CopySetup(TObject* obj){fSetup=*(dynamic_cast<Setup*>(obj));}
      void SaveSetup();
      void LoadSetup(TString dir);
      virtual void WriteThis();
      
      Binner &Bins(){
	if(!fBinner.IsSetup())
	  fBinner.LoadSetup(fSetup);
	return fBinner;
      }

      virtual void Run(UInt_t ifit=0);
      virtual void RunAll();
      virtual void RunOne(Int_t ifit);
      virtual void FitTo();
      
      virtual void Reset(UInt_t ifit){
	fData.Reset(ifit);
	fFiledTrees.clear();
	fCurrSetup.reset();
	fCurrDataSet.reset();
      }
      
     
      void LoadData(TString tname,TString fname,TString name="Data"){
	fBinner.SplitData(tname,fname,name);
	LoadData(fBinner.TreeName(name),fBinner.FileNames(name));
	fData.SetParentName(fname);
 	fData.SetParentTreeName(tname);
      }
      void ReloadData(TString fname,TString name="Data"){
	fBinner.ReloadData(fname,name);
  	LoadData(fBinner.TreeName(name),fBinner.FileNames(name));
 	fData.SetParentName(fname);
 	fData.SetParentTreeName(fBinner.TreeName(name));
     }
      void ReloadData(TString tname,TString fname,TString name){
	ReloadData(fname,name);
      }
      
      void LoadSimulated(TString tname,TString fname,TString name){
	fBinner.SplitData(tname,fname,name);
      }
      void ReloadSimulated(TString fname,TString name){
	fBinner.ReloadData(fname,name);
      }
      void ReloadSimulated(TString tname,TString fname,TString name){
	fBinner.ReloadData(fname,name);
      }

      // dataevs_ptr& Data() {return fData;}
      DataEvents& Data() {return fData;}
      
      void SetMinimiser(Minimiser* mi){
	fMinimiser.reset(std::move(mi));
	SetMinimiserType(fMinimiser->GetName());
      }
      void SetMinimiserType(TString mtype){fMinimiserType=mtype;}
      TString GetMinimiserType(){return fMinimiserType;}
      
      void FillEventsPDFs(UInt_t idata);
      void PlotDataModel(){
	fPlots.push_back(std::move(plotresult_uptr{new PlotResults(fCurrSetup.get(),fCurrDataSet.get())}));
      }
      void RedirectOutput(TString log="");
      void SetRedirectOutput(){fRedirect=kTRUE;}
      
     protected:
      std::unique_ptr<Setup> fCurrSetup; //!
      std::unique_ptr<RooDataSet> fCurrDataSet; //!
      
       void LoadData(TString tname,strings_t fnames){
	 fData.Load(fSetup,tname,fnames);
      }
       void SaveResults();
       
    private:
      
      Setup fSetup;
      
      DataEvents fData;
      
      Binner fBinner;

      minimiser_uptr fMinimiser; //!
      TString fMinimiserType;
      
      std::vector<HS::filed_uptr> fFiledTrees;//!
      std::vector<plotresult_uptr> fPlots;//!
      RooFitResult* fResult=nullptr;//!


  
      Bool_t fRedirect=kFALSE;
      
      ClassDef(HS::FIT::FitManager,1);
     };

  }//namespace FIT
}//namespace HS

#endif
