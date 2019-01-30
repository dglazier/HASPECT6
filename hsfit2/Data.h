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

      virtual RooAbsData& Get() = 0;
    protected:
      
    private:
      //RooAbsData fData; //dataset to be fitted

    };//class FitData
    
    //////////////////////////////////////////////////
    using dset_ptr = std::shared_ptr<RooDataSet>;
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

      UInt_t GetN() const {return fDSets.size();}
      RooAbsData& Get() final {return *(Get(0));}
      RooDataSet* Get(UInt_t iset);
      // RooDataSet* Get(UInt_t iset,Setup& setup) const;
      TTree* GetTree(UInt_t ii){return fFiledTrees[ii]->Tree().get();}
      TString FileName(UInt_t ii){return fFileNames[ii];}
      
      void Clear(){fFiledTrees.clear();fDSets.clear();}
      void Clear(UInt_t ii) {fFiledTrees[ii].reset();delete fDSets[ii];fDSets[ii]=nullptr;}
      
    protected:
      
    private:
 
      HS::FIT::Setup &fSetup;
      strings_t fFileNames;
      TString fTreeName;
      
      filedtrees_t fFiledTrees;
      roodsets_t fDSets;
      
    };
    
  }//namespace FIT
}//namespace HS

#endif
