//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Nov  6 21:22:18 2018 by ROOT version 6.14/04
// from TTree tt/A FiledTree
// found on file: testmvamlpinc2.root
//////////////////////////////////////////////////////////

#ifndef branch_h
#define branch_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include "TreeDataK2.h"



class branch : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Int_t> Topo = {fReader, "Topo"};
   TTreeReaderValue<Int_t> Correct = {fReader, "Correct"};
   TTreeReaderValue<Int_t> NPerm = {fReader, "NPerm"};
   TTreeReaderValue<Int_t> NDet = {fReader, "NDet"};
   TTreeReaderValue<unsigned int> fUniqueID = {fReader, "fUniqueID"};
   TTreeReaderValue<unsigned int> fBits = {fReader, "fBits"};
   TTreeReaderValue<Double_t> MissMass = {fReader, "MissMass"};
   TTreeReaderValue<Double_t> MissMass2 = {fReader, "MissMass2"};
   TTreeReaderValue<Double_t> MesonMass = {fReader, "MesonMass"};
   TTreeReaderValue<Double_t> HyperonMass = {fReader, "HyperonMass"};
   TTreeReaderValue<Double_t> MesonCosTh = {fReader, "MesonCosTh"};
   TTreeReaderValue<Double_t> MesonPhi = {fReader, "MesonPhi"};
   TTreeReaderValue<Double_t> HyperonCosTh = {fReader, "HyperonCosTh"};
   TTreeReaderValue<Double_t> HyperonPhi = {fReader, "HyperonPhi"};
   TTreeReaderValue<Double_t> Eg = {fReader, "Eg"};
   TTreeReaderValue<Double_t> t = {fReader, "t"};
   TTreeReaderValue<Double_t> HelCosTh = {fReader, "HelCosTh"};
   TTreeReaderValue<Double_t> HelPhi = {fReader, "HelPhi"};
   TTreeReaderValue<Double_t> ProtP = {fReader, "ProtP"};
   TTreeReaderValue<Double_t> ProtTh = {fReader, "ProtTh"};
   TTreeReaderValue<Double_t> ProtTime = {fReader, "ProtTime"};
   TTreeReaderValue<Double_t> KpP = {fReader, "KpP"};
   TTreeReaderValue<Double_t> KpTh = {fReader, "KpTh"};
   TTreeReaderValue<Double_t> KpTime = {fReader, "KpTime"};
   TTreeReaderValue<Double_t> KmP = {fReader, "KmP"};
   TTreeReaderValue<Double_t> KmTh = {fReader, "KmTh"};
   TTreeReaderValue<Double_t> KmTime = {fReader, "KmTime"};
   TTreeReaderValue<Double_t> BeamTime = {fReader, "BeamTime"};
   TTreeReaderValue<Double_t> Pol = {fReader, "Pol"};
   TTreeReaderValue<Int_t> PolState = {fReader, "PolState"};
   TTreeReaderValue<Float_t> MLP = {fReader, "MLP"};
   TTreeReaderValue<Double_t> UID = {fReader, "UID"};


   branch(TTree * /*tree*/ =0) { }
   virtual ~branch() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(branch,0);

};

#endif

#ifdef branch_cxx
void branch::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t branch::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef branch_cxx
