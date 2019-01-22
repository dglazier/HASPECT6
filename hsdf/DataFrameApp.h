////////////////////////////////////////////////////////////////
///
///Class:               DataFrameApp
///Description:
///            A class to make histograms from a Tree
///            via RDataFrame
///            Includes splitting and cutting data

#ifndef HS_DF_DATAFRAMEAPP_h
#define HS_DF_DATAFRAMEAPP_h


#include <TString.h>
#include <TAxis.h>
#include <TFile.h>
#include <TDirectory.h>
#include <ROOT/RDataFrame.hxx>
#include <vector>
#include <map>

namespace HS{
  namespace DF{
    using dframe_ptr = std::shared_ptr<ROOT::RDataFrame>;
    ///////////////////////////////////////////////////////////
    class DataFrameApp {
    
    public:
    DataFrameApp(TString tname,TString fname) :
      fDFrame(new ROOT::RDataFrame(tname.Data(),fname.Data(),{"BeamP","MissMass"})),
	fTreeName(tname),fFileName(fname) {}
    
      DataFrameApp()=default;
      DataFrameApp(const DataFrameApp&)=default;
      DataFrameApp(DataFrameApp&&)=default;
      virtual ~DataFrameApp()=default;
    
      dframe_ptr DFrame(){return fDFrame;}

      TString TreeName() {return fTreeName;}
      TString FileName() {return fFileName;}

      Bool_t CheckForColumn(TString cname){
	auto cs=fDFrame->GetColumnNames();
	return std::count(cs.begin(),cs.end(),cname.Data())!=0;
      }

    private :
    
      dframe_ptr fDFrame;
      TString fTreeName;
      TString fFileName;

    };//class DataFrameApp
    /////////////////////////////////////////////////////////////
    using strings_t = std::vector<TString>;
    using axes_t =std::vector<TAxis>;
  
    using filter_t =   ROOT::RDF::RInterface<ROOT::Detail::RDF::RJittedFilter, void > ;
    using filters_t = std::vector< filter_t>;
    using mfilters_t = std::map< TString,filter_t>;
    
    /////////////////////////////////////////////////////////////////////
    class Splitter : public DataFrameApp{

    public:
    Splitter(TString tname,TString fname) :
      DataFrameApp(tname,fname) {}
      
      Splitter()=default;
      Splitter(const Splitter&)=default;
      Splitter(Splitter&&)=default;
      virtual ~Splitter()=default;
    

      void AddAxis(TString name,Int_t nbins,Double_t min,Double_t max);
      void AddAxis(TString name,Int_t nbins,Double_t* xbins);
      axes_t GetSplitAxis() const {return fSplitAxis;}
      Int_t GetAxisi(TString aname) const;
      TAxis GetAxis(Int_t ia) const{return fSplitAxis[ia];}
      TAxis GetAxis(TString aname) const{return fSplitAxis[GetAxisi(aname)];}
      Int_t GetN(){return fN;}
      Int_t GetNAxis(){return fNaxis;}
      
      void Split();
      void ApplySingleSplits();
      void ApplyFullSplits();

      //strings_t SingleSplitNames(){return fSingleSplitNames;}
      
      void PrintRanges();
      void PrintSplitNames();
      void PrintSplitRangesFull();
      void PrintSingleSplitNames();

      void TakeSplitterMembers(const Splitter& s);
      
     protected:
      Bool_t fAreSingleSplits=kFALSE;
      Bool_t fAreFullSplits=kFALSE;
      
      Bool_t fDoneSplit=kFALSE;
      strings_t fSplitNamesFull;//names of individual splits
      strings_t fSplitRangesFull;//names of individual splits
      vector<strings_t> fSingleSplitNames; //vector containing name part for each axis
      vector<strings_t> fSingleSplitRanges; //vector containing ranges for each axis bin
 
      shared_ptr<mfilters_t> fDFSingleSplits;
 
    private :
    
      void IterateAxis(Int_t iA,TString splitName,TString rangeName);

      axes_t fSplitAxis;
      
      Int_t fNaxis=0;
      Int_t fN=0; //Total number of lowest level splits
  
   
    }; //class Splitter
    
    /////////////////////////////////////////////////////////////////////////
    
    class TreeSplitter  : public Splitter{
    
    public:
    
    TreeSplitter(TString tname,TString fname) :
     Splitter(tname,fname) {}
    
      TreeSplitter()=default;
      TreeSplitter(const TreeSplitter&)=default;
      TreeSplitter(TreeSplitter&&)=default;
      virtual ~TreeSplitter()=default;

      void SaveTrees(TString basedir);
      
    }; //TreeSplitter
      /////////////////////////////////////////////////////////////     

      using histo1D_t = ROOT::RDF::RResultPtr<TH1D>;
      using histo1Ds_t= std::vector<histo1D_t>;
      using histo2D_t = ROOT::RDF::RResultPtr<TH2D>;
      using histo2Ds_t= std::vector<histo2D_t>;
      using mhisto1Ds_t= std::map<TString,histo1D_t>;
      using mhisto2Ds_t= std::map<TString,histo2D_t>;
       
      class HistMaker  : public Splitter{

    public:
    
    HistMaker(TString tname,TString fname) :
      Splitter(tname,fname) {}
      HistMaker(TString tname,TString fname,TString out) :
      Splitter(tname,fname),fOutFile(new TFile(out,"recreate")) {}
    
      HistMaker()=default;
      HistMaker(const HistMaker&)=default;
      HistMaker(HistMaker&&)=default;
      virtual ~HistMaker()=default;
    
      using hm_uptr = std::unique_ptr<HistMaker>;
      hm_uptr CloneWithNewFile(TString infname,TString outfname,TString tname="",std::vector<std::pair<TString,TString>> cuts={});
      
      void Histo2D(TString vnameX,TString vnameY,
		   TString htitle,Int_t NbinsX,
		   Double_t lowX, Double_t highX,
		   Int_t NbinsY,Double_t lowY, Double_t highY);
      
      void Histo1D(TString vname,TString htitle,
		   Int_t Nbins,Double_t low, Double_t high);
     
      void PrintHist1DNames();
      void PrintCuts();
      void DrawHist1D(TString name){(*fDFHistos1D)[name]->DrawCopy();}
      void DrawHist2D(TString name){(*fDFHistos2D)[name]->DrawCopy();}
      void AddCut(TString cutname,TString cut){
	fCutSpecs.push_back(std::make_pair(cutname,cut));
	fCutNames.push_back(cutname);
	if(fOutFile) fOutFile->mkdir(cutname);}

      //strings_t CutNames(){return fCutNames;}
      
      void ConfigureFileDirs();
      void MakeSplitDirs(Int_t iA,TDirectory* curDir);
      TDirectory* FindDirectory(TString name);

      void SaveHists();
      private:

    
      unique_ptr<mhisto1Ds_t> fDFHistos1D;
      unique_ptr<mhisto2Ds_t> fDFHistos2D;
      std::vector<TH1S> fHistTemplates1D;
      std::vector<TH2S> fHistTemplates2D;
      
      std::vector<std::pair<TString,TString>> fCutSpecs;
      
      unique_ptr<TFile> fOutFile;
      strings_t fCutNames;
      
      Bool_t fConfigFileDirsDone=kFALSE;

      ClassDef(HistMaker,1);
      
    };//class HistMaker
      using hm_uptr = std::unique_ptr<HistMaker>;
 
      /* using hms_t std::vector<HistMaker>; */

      /* class MultiFileHists : public HistMaker{ */

      /* public: */
      /* 	MultiFileHists(strings_t files,TString dir); */
      /* 	MultiFileHists(TString file,TString dir); */

      /* 	void Spawn(); */
	
      /* private: */
      /* 	hms_t fHistMakers; */
      /* };//class MultFileHist */
      
      /* //helper functions */
      
      /* //filter vectors via a lambda function */

      template <typename Cont, typename Pred>
      	Cont container_filter(const Cont &container, Pred predicate){
      	Cont result;
      	std::copy_if(container.begin(),container.end(),std::back_inserter(result), predicate);
      	return std::move(result);
      }
      
  }//namespace DF
}//namespace HS
      
#endif
