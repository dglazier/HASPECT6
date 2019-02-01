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
#include "RooMinimizer.h"
#include "RooMinuit.h"
#include "RooAbsData.h"

namespace HS{
  namespace FIT{

  
    using dataevs_ptr=std::shared_ptr<HS::FIT::DataEvents>;
    using strings_t = std::vector<TString>;
    using plotresult_uptr=std::unique_ptr<PlotResults>;
    
    
    class FitManager  {
      
    public:
      FitManager()=default;
      FitManager(const FitManager&)=default;
      FitManager(FitManager&&)=default;
      virtual ~FitManager()=default;
      FitManager& operator=(const FitManager& other)=default;
      FitManager& operator=(FitManager&& other) = default;

      Setup &SetUp() {return fSetup;};
      const Setup &ConstSetUp() {return fSetup;};
      
      Binner &Bins(){
	if(!fBinner.IsSetup())
	  fBinner.LoadSetup(fSetup);
	return fBinner;
      }

      virtual void Run(UInt_t ifit=0);
      virtual void RunAll();
      virtual void Clear(UInt_t ifit){
	fData->Clear(ifit);
	fFiledTrees.clear();
	fCurrSetup.reset();
	fCurrDataSet.reset();
      }
      
      void LoadData(TString tname,TString fname,TString name="Data"){
	fBinner.SplitData(tname,fname,name);
	LoadData(fBinner.TreeName(name),fBinner.FileNames(name));
	fData->SetParentName(fname);
 	fData->SetParentTreeName(tname);
      }
      void ReloadData(TString fname,TString name="Data"){
	fBinner.ReloadData(fname,name);
  	LoadData(fBinner.TreeName(name),fBinner.FileNames(name));
 	fData->SetParentName(fname);
 	fData->SetParentTreeName(fBinner.TreeName(name));
     }
      
      void LoadSimulated(TString tname,TString fname,TString name){
	fBinner.SplitData(tname,fname,name);
      }
      void ReloadSimulated(TString fname,TString name){
	fBinner.ReloadData(fname,name);
      }

      dataevs_ptr& Data() {return fData;}
      

      void FillEventsPDFs(UInt_t idata);
      void PlotDataModel(){
	fPlots.push_back(std::move(plotresult_uptr{new PlotResults(fCurrSetup.get(),fCurrDataSet.get())}));
      }

    protected:
      std::unique_ptr<Setup> fCurrSetup;
      std::unique_ptr<RooDataSet> fCurrDataSet;
      
       void LoadData(TString tname,strings_t fname){
	fData.reset(new DataEvents(fSetup,tname,fname));
      }

    private:
      
      Setup fSetup;
      
  
      dataevs_ptr fData;

 
      std::vector<HS::filed_uptr> fFiledTrees;
      std::vector<plotresult_uptr> fPlots;
      
      Binner fBinner;
     };

  }//namespace FIT
}//namespace HS

#endif
