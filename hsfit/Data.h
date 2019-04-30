////////////////////////////////////////////////////////////////
///
///Class:               Data
///Description:
///           

#ifndef HS_FIT_DATA_h
#define HS_FIT_DATA_h

#include "Setup.h"
#include "BootStrapper.h"
#include "FiledTree.h"
#include "Weights.h"
#include <RooAbsData.h>
#include <RooDataSet.h>
#include <RooDataHist.h>
#include <TString.h>
#include <TObject.h>
#include <TObjString.h>


namespace HS{
  namespace FIT{

    using strings_t = std::vector<TString>;
    using weights_uptr = std::unique_ptr<HS::Weights>;
    
    class FitData : public TObject {
      
    public:
      FitData()=default;
      FitData(const FitData&)=default;
      FitData(FitData&&)=default;
      virtual ~FitData()=default;
      FitData& operator=(const FitData& other)=default;
      FitData& operator=(FitData&& other) = default;

      //virtual RooAbsData& Get() = 0;
    protected:
      
    private:
      //RooAbsData fData; //dataset to be fitted

      ClassDef(HS::FIT::FitData,1);
      
    };//class FitData
    
    //////////////////////////////////////////////////
    using dset_uptr = std::unique_ptr<RooDataSet>;
    using roodsets_t = std::vector<RooDataSet*>;
    using filedtrees_t = std::vector<std::unique_ptr<HS::FiledTree>>;
    
    class DataEvents  : public FitData {
      
    public:
      DataEvents(Setup &setup,TString tname,strings_t files);

      DataEvents()=default;
      DataEvents(const DataEvents&)=default;
      DataEvents(DataEvents&&)=default;
      virtual ~DataEvents()=default;
      DataEvents& operator=(const DataEvents& other)=default;
      DataEvents& operator=(DataEvents&& other) = default;

      UInt_t GetN() const {return fFiledTrees.size();}
      // RooAbsData& Get() final {return *(Get(0));}
      dset_uptr Get(const UInt_t iset);
      // RooDataSet* Get(UInt_t iset,Setup& setup) const;
      TTree* GetTree(UInt_t ii){return fFiledTrees[ii]->Tree().get();}
      strings_t FileNames() const {return fFileNames;}
      TString FileName(UInt_t ii)const {return fFileNames[ii];}
      TString ParentName() const {return fParentName;}
      TString ParentTreeName() const {return fTreeName;}
      void SetParentName(TString name) {fParentName=name;}
      void SetParentTreeName(TString name) {fParentTreeName=name;}

      void Load(Setup &setup,TString tname,strings_t files);
      void LoadSetup(Setup *setup){fSetup=setup;}
      void LoadBootStrap(TString tname,strings_t files);
      void Reset(UInt_t ii) {fFiledTrees[ii].reset();}
      
      void BootStrap(Int_t N){
	fNBoots=N;
	fBootStrap.reset(new BootStrapper(N));
      }
      void Toys(Int_t N){fNToys=N;}
      
      Int_t GetDataBin(Int_t ii){
	if(fNBoots>0&&!fBootStrap.get())
	  BootStrap(fNBoots);//.recreate bootstrapper
	if(fBootStrap.get())
	  return fBootStrap->GetGroup(ii);
	else if(fNToys>0) //only toys if no bootstrap
	  return (int)std::round(ii/fNToys);
	//no boots or toys
	return ii;
      }
      TString GetItemName(Int_t ii);
      void LoadWeights(TString wname,TString fname,TString wobj="HSsWeights");
      
    protected:
      
    private:
 
      HS::FIT::Setup *fSetup=nullptr;//!
      strings_t fFileNames;
      TString fTreeName;
      TString fParentName;
      TString fParentTreeName;
      TString fInWeightName;
      TString fInWeightFile;
      TString fInWeightObjName;
      

      filedtrees_t fFiledTrees;
      std::unique_ptr<BootStrapper> fBootStrap;//!;

      Int_t fNBoots=-1;
      Int_t fNToys=-1;
      
      weights_uptr fInWeights;//!
      
      unique_ptr<RooRealVar> fWeightVar;//!
      
      ClassDef(HS::FIT::DataEvents,1);
     };
    
  }//namespace FIT
}//namespace HS

#endif
