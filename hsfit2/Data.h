////////////////////////////////////////////////////////////////
///
///Class:               Data
///Description:
///           

#ifndef HS_FIT_DATA_h
#define HS_FIT_DATA_h

#include "Setup.h"
#include "FiledTree.h"
#include <RooAbsData.h>
#include <RooDataSet.h>
#include <RooDataHist.h>
#include <TString.h>

namespace HS{
  namespace FIT{

    using strings_t = std::vector<TString>;
    
    class FitData  {
      
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
      TString FileName(UInt_t ii){return fFileNames[ii];}
      TString ParentName(){return fParentName;}
      TString ParentTreeName(){return fTreeName;}
      void SetParentName(TString name){fParentName=name;}
      void SetParentTreeName(TString name){fParentTreeName=name;}
      
      void Clear(UInt_t ii) {fFiledTrees[ii].reset();}
      
    protected:
      
    private:
 
      HS::FIT::Setup &fSetup;
      strings_t fFileNames;
      TString fTreeName;
      TString fParentName;
      TString fParentTreeName;
      
      filedtrees_t fFiledTrees;
      
    };
    
  }//namespace FIT
}//namespace HS

#endif
