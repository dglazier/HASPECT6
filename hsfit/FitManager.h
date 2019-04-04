////////////////////////////////////////////////////////////////
///
///Class:               FitManager
///Description:
///           

#pragma once

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
      FitManager(const FitManager& other);
      FitManager(FitManager&&)=default;
      virtual ~FitManager()=default;
      FitManager& operator=(const FitManager& other);
      FitManager& operator=(FitManager&& other) = default;

      Setup *PointerSetUp() {return &fSetup;};
      Setup &SetUp() {return fSetup;};
      const Setup &ConstSetUp() {return fSetup;};

      //Not the default name and title are given by the bin and bootstrap
      //combination, Data GetGroup and GetItemName are BootStrap related
      //Default name= binname
      virtual TString GetCurrName(){return Bins().BinName(GetDataBin(fFiti));}
      //Default title data item (bootstrap number)
      virtual TString GetCurrTitle(){return Data().GetItemName(fFiti);}
      virtual Int_t GetDataBin(Int_t ii){ return Data().GetDataBin(ii);}
      virtual TString GetDataTreeName() {return fData.ParentTreeName();}
      virtual  strings_t GetDataFileNames() {cout<<"   yep "<<endl;return fData.FileNames();}
      
      void CopySetup(TObject* obj){fSetup=*(dynamic_cast<Setup*>(obj));}
      void CopyBinner(const Binner* obj){fBinner=*obj;}
      void SaveSetup();
      void CreateCurrSetup();
      void LoadSetup(TString dir);

      virtual void WriteThis();
      virtual void PreRun(){WriteThis();}
      
      Binner &Bins(){
	if(!fBinner.IsSetup())
	  fBinner.LoadSetup(fSetup);
	return fBinner;
      }
      const Binner *PointerBinner() const{return &fBinner;};

      virtual Int_t GetN(){return fData.GetN();}
      virtual Int_t GetFiti(){return fFiti;}
      
      virtual void Run();
      virtual void RunAll();
      virtual void RunOne(Int_t ifit);
      virtual void FitTo();
      
      virtual void Reset(){
	//	fData.Reset(fFiti);
	fFiledTrees.clear();
	fCurrSetup.reset();
	fCurrDataSet.reset();
      }
      
     
      void LoadData(TString tname,strings_t fnames){
	 fData.Load(fSetup,tname,fnames);
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
      TString GetMinimiserType() const {return fMinimiserType;}
      //    Minimiser* GetMinimiser() const {return fMinimiser;}
      
      void FillEventsPDFs();
      void PlotDataModel(){
	fPlots.push_back(std::move(plotresult_uptr{new PlotResults(fCurrSetup.get(),fCurrDataSet.get())}));
      }
      void RedirectOutput(TString log="");
      void SetRedirectOutput(){fRedirect=kTRUE;}
      
     protected:
      std::unique_ptr<Setup> fCurrSetup={}; //!
      std::unique_ptr<RooDataSet> fCurrDataSet={}; //!
      
      virtual void SaveResults();
       
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

      UInt_t fFiti=0;
      
      ClassDef(HS::FIT::FitManager,1);
     };

  }//namespace FIT
}//namespace HS

