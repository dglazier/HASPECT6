#ifndef HS_BINS_h
#define HS_BINS_h
#include <TAxis.h>
#include <TObjArray.h>
#include <TObject.h>
#include <TEntryList.h>
#include <TTree.h>
#include <TFile.h>
#include <TString.h>
#include "TVectorT.h"
#include "TLeaf.h"
#include <vector>
#include <iostream>

namespace HS{
  using VecString_t= std::vector<TString>;
  using VecAxis_t=std::vector<TAxis>;

  class BinTree;

  using std::vector;
 
  class Bins : public TNamed{

 
  protected:
    
    VecString_t fBinNames;//names of individual bins
    VecString_t fFileNames;//names of individual files
    VecAxis_t fVarAxis;//bin limits for variables
    vector<VecString_t> fPartName; //vector containing name part for each axis
    TFile* fFile=nullptr;//! file for writing lists to disc in case they get large
    Int_t fNbins=0;//number of bins
    Int_t fNaxis=0;//number of axis
    Int_t fBin=0;//number of axis

    Int_t fMaxEntries=1E9;
    Int_t fMAXFILES=490;
    TString fOutDir="./";
    TString fDataName="Data";
    const TString fBinnedTreeName="BinnedTree";

    vector<BinTree*> fTrees;//!
  
  public:
  Bins() : fNaxis(0),fNbins(0) {};
    Bins(TString name,TString filename);
    Bins(const Bins& other, const char* name=0);
 
    Bins(TString name);
    virtual ~Bins();

    virtual TObject* Clone(const char* newname="") const { return new Bins(*this,newname); }

    void AddAxis(TString name,Int_t nbins,Double_t min,Double_t max);
    void AddAxis(TString name,Int_t nbins,Double_t* xbins);
    void IterateAxis(Int_t iA,TString binName);
    VecString_t GetBinNames(){return fBinNames;}
    const VecString_t GetFileNames() const {return fFileNames;}
    VecAxis_t GetVarAxis(){return fVarAxis;}
    Int_t GetAxisi(TString aname){for(Int_t ia=0;ia<fNaxis;ia++) if(fVarAxis[ia].GetName()==aname) return ia; return -1;};
    TAxis GetAxis(Int_t ia){return fVarAxis[ia];}
    TString GetBinName(Int_t i){if(i<fNbins) return fBinNames[i];else return "";};
    TString GetPartName(Int_t ia,Int_t ib){return fPartName[ia][ib];}
    Int_t GetParti(Int_t ia,TString name){for(Int_t ib=0;ib<fVarAxis[ia].GetNbins();ib++){if(name==fPartName[ia][ib]) return ib;} return 0;} //find the bin index for a binpart name
    void InitialiseBins();
    void Save(TString filename);
    void RunBinTree(TTree* tree);
    void RunBinTree(TTree* tree,Int_t BMin,Int_t BMax);
    // void MakeBinTree(TTree* tree,TString name,TString filename){InitialiseBinTree(name,filename);RunBinTree(tree);Save();}
    //TTree* GetBinTree(){return fBinTree;}
    // TTree* GetBinnedTree(TTree* tree,Int_t bin);
    Int_t GetN(){return fNbins;}
    Int_t GetNAxis(){return fNaxis;}
    void PrintAxis();
    Int_t FindBin(TVectorD vals);
    Int_t FindBin(Double_t v0);
    Int_t FindBin(Double_t v0,Double_t v1);
    Int_t FindBin(Double_t v0,Double_t v1,Double_t v2);
    Int_t FindBin(Double_t v0,Double_t v1,Double_t v2,Double_t v3,Double_t v4=0,Double_t v5=0);

    void SetMaxEntries(Long64_t ent){fMaxEntries=ent;}
    void SetMaxFiles(Long64_t ent){fMAXFILES=ent;}
    void SetOutDir(TString name) {fOutDir=name;}
    void SetDataName(TString name) {fDataName=name;}
    const TString GetBinnedTreeName(){return fBinnedTreeName;}

    ClassDef(Bins, 1);  // Writeable bins class
  };//Bins

  class BinTree {
   
  public:
    BinTree() =default;
    BinTree(Int_t nbins,TString name,TTree* tree0);
    virtual  ~BinTree();
    void Reset();
    void Save();
    Int_t ReadEvent(){
      return fTree->Fill();
    }
    TTree* GetTree(){return fTree;}
    Long64_t GetEntries(){return fTree->GetEntries();}
    TString GetFileName(){return fFile->GetName();}
    TFile* GetFile(){return fFile;}

  private:

    TTree* fTree=nullptr;
    TFile* fFile=nullptr;
    TString fName;
 
  };//class BinTree

}//namespace HS

#endif //ifdef THSBINS

