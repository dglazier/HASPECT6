//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jan 25 13:34:24 2019 by ROOT version 6.14/04
// from TTree bins/A FiledTree
// found on file: BinIndices.root
//////////////////////////////////////////////////////////

#ifndef FitSelector_h
#define FitSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
/* #include <TTreeReader.h> */
/* #include <TTreeReaderValue.h> */
/* #include <TTreeReaderArray.h> */
#include <TString.h>
#include <vector>

// Headers needed by this particular selector
#include "FitManager.h"

namespace HS{
  namespace FIT{

    class FitManager;
    
    class FitSelector : public TSelector {
      public :
      /* TTreeReader     fReader;  //!the tree reader */
      /* TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain */

      /* // Readers to access the data (delete the ones you do not need). */
      /* TTreeReaderValue<Int_t> bindex = {fReader, "bindex"}; */


      FitSelector(TTree * /*tree*/ =0) { }
      virtual ~FitSelector() { }
      virtual Int_t   Version() const { return 2; }
      virtual void    Begin(TTree *tree);
      virtual void    SlaveBegin(TTree *tree);
      virtual void    Init(TTree *tree);
      virtual Bool_t  Notify();
      virtual Bool_t  Process(Long64_t entry);
      //virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEnqtry(entry, getall) : 0; }
      virtual void    SetOption(const char *option) { fOption = option; }
      virtual void    SetObject(TObject *obj) { fObject = obj; }
      virtual void    SetInputList(TList *input) { fInput = input; }
      virtual TList  *GetOutputList() const { return fOutput; }
      virtual void    SlaveTerminate();
      virtual void    Terminate();


      void SetFitManager(FitManager *fm){fFitManager=fm;}
    private:
      std::vector<TString> fFitFileNames;

      FitManager *fFitManager;
      TFile* fFitfile=nullptr;
      
      ClassDef(FitSelector,0);

    };
  }
}

#endif // #ifdef FitSelector_cxx
