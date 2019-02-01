#ifndef HS_WEIGHTS_h
#define HS_WEIGHTS_h

#include <TTree.h>
#include <TNamed.h>
#include <TList.h>
#include <TVectorD.h>
#include <ROOT/RDataFrame.hxx>
#include <map>
#include <iostream>
#include "FiledTree.h"
 

namespace HS{
  using  StrIntMap_t = map<TString, Int_t >;
  //using DFdef_t =   ROOT::RDF::RInterface<ROOT::Detail::RDF::RLoopManager, void > ;
  using DF_uptr=std::unique_ptr<ROOT::RDataFrame>;
 
  class Weights : public TNamed{
    
  public:
    Weights() =default;
    Weights(TString name);
    ~Weights();
    
    TTree* GetIDTree(){return fIDTree;};
    void SetIDTree(TTree* tree){fIDTree=tree;}
    TTree* GetTree(){return fWTree;};
    void SetTree(TTree* tree){fWTree=tree;}
    void FillWeights(Long64_t ev,TVectorD wgt){ fID=ev; fWVals=wgt; fWTree->Fill();fIDTree->Fill();fN++;}
    void FillWeight(Long64_t ev,Double_t wgt){if(GetNSpecies()==1){ fID=ev; fWVals[0]=wgt; fWTree->Fill();fIDTree->Fill();fN++;}}//Special case of single species!!!!
    
    void GetEntry(Long64_t ent){fWTree->GetEntry(ent);fIDTree->GetEntry(ent);}; 
    Bool_t GetEntryFast(Long64_t id); //use id branch with sorted tree
    Bool_t GetEntrySlow(Long64_t id); //use id branch
    Bool_t GetEntryBinarySearch(Long64_t id); //use binary search to give faster entrys when used by unsorted trees
    Double_t GetWeight(TString spe){if(fSpecies.count(spe))return GetWeight(fSpecies[spe]);return 1;}
    Double_t GetWeight(Int_t ispe){
      if(fGotEntry)
	return fWVals[ispe];
      else return 0; //entry for id not found
    }
    Long64_t GetID(){return fID;}
    Long64_t* GetIDi(){return fIDi;};
    void SetCurrEntry(Long64_t ent){fCurrEntry=ent;}
    Bool_t GotEntry(){return fGotEntry;}
    Bool_t IsSorted(){return fIsSorted;}
    Long64_t GetCurrEntry(){return fCurrEntry;}
    Long64_t Size(){if(!fWTree) return 0;return fWTree->GetEntries();}
    void Add(Weights* wm);
    // void Multiply(Weights* other,TString species);
    void SetSpecies(TString name);
    Int_t GetNSpecies(){return fSpecies.size();}
    StrIntMap_t GetSpecies(){return fSpecies;}
    StrIntMap_t* GetSpeciesp(){return &fSpecies;}
    TString GetSpeciesName(UInt_t isp);
    void SetSpecies(StrIntMap_t species){fSpecies=species;};
    Int_t GetSpeciesID(TString name){if(fSpecies.count(name))return fSpecies[name]; else {cout<<"Weights:: GetSpeciesID species not found in "<<GetName()<<" species= "<<name<<endl;return -1;}}
    TString GetIDName(){return fIDName;}
    void SetIDName(TString name){fIDName=name;}
    
    TList* GetWeightList(){return fWeightList;}
    void PrintWeight();
    Long64_t Merge(TString tempName,TString outName="",TString wmName="WeightMap");
    void SortWeights();
    void BuildIndex();
    void SetFile(TString filename);
    void Save();
    void LoadSaved(TString fname,TString wname);
    void WeightBySelection(TTree* tree,TCut cut,Double_t wgt);
    void WeightBySelection(TTree* tree,TCut cut,TString wgt);
    
    filed_uptr DFAddToTree(TString wname,TString outfname,TString tname,TString infname);
  private:
    TTree *fWTree=nullptr;  //! not saved tree of weights, branchname = species
    TTree *fIDTree=nullptr;  //! not saved tree of ids, branchname = species
    TList* fWeightList=nullptr; //list of weight bins which have been merged to make this
    TFile* fFile=nullptr;
    TVectorD fWVals;
    Long64_t fID;
    Long64_t fCurrEntry;
    Long64_t fN;
    Long64_t *fIDi=nullptr;//!
    Long64_t *fIDv=nullptr;//!
    StrIntMap_t fSpecies;//names of species with index in map
    TString fIDName="UID"; //name of tree branch with event ID
    Bool_t fGotEntry;
    Bool_t fIsSorted;
    
    ClassDef(Weights, 1);  // Writeble Weight map  class
  };
}//namespace HS
#endif //ifdef Weights
  
