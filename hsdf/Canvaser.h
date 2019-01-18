////////////////////////////////////////////////////////////////
///
///Class:               Canvaser
///Description:
///            A class to draw histograms from file to canvas

#ifndef HS_CANVASER_h
#define HS_CANVASER_h


#include <TString.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TDirectory.h>
#include <TH1.h>
#include <vector>
#include <map>

namespace HS{
  using hist_uptr = std::unique_ptr<TH1>;
  using can_uptr = std::unique_ptr<TCanvas>;
  using strings_t = std::vector<TString>;
  using cans_t =std::vector<can_uptr>;
  using hists_t =std::vector<hist_uptr>;
 
  class Canvaser {


  public:
    Canvaser(TString fname);
    virtual ~Canvaser()=default;
    
    void AddCuts(strings_t cuts){fCuts=cuts;}
    void AddSplits(strings_t splits){fSplits=splits;}

    void DrawHist(TString hname,TString opt);
    void DrawHist(hist_uptr hist,TPad* pad,TString opt);
    
    void DrawDirectory(TString dname,Int_t nx, Int_t ny);
    void DrawAllDirectories(Int_t nx, Int_t ny);
    void  DrawNextDir(TDirectory* dir,TString fullname="");
    TString GetFullDirTitle(TDirectory* dir);
  private :
    unique_ptr<TFile> fFile;

    strings_t fCuts;
    strings_t fSplits;

    cans_t fCanvases;
    hists_t fDrawnHists;

    Int_t fNX=1;
    Int_t fNY=1;
    
  }; //class Canvaser

  

}//namespace HS

#endif
