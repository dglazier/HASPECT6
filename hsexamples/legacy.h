//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Nov  6 21:26:36 2018 by ROOT version 6.14/04
// from TTree tt/A FiledTree
// found on file: testmvamlpinc2.root
//////////////////////////////////////////////////////////

#ifndef legacy_h
#define legacy_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include "TreeDataK2.h"
#include "TObject.h"

class legacy : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           Topo;
   Int_t           Correct;
   Int_t           NPerm;
   Int_t           NDet;
 //TreeDataK2      *TreeDataK2;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   Double_t        MissMass;
   Double_t        MissMass2;
   Double_t        MesonMass;
   Double_t        HyperonMass;
   Double_t        MesonCosTh;
   Double_t        MesonPhi;
   Double_t        HyperonCosTh;
   Double_t        HyperonPhi;
   Double_t        Eg;
   Double_t        t;
   Double_t        HelCosTh;
   Double_t        HelPhi;
   Double_t        ProtP;
   Double_t        ProtTh;
   Double_t        ProtTime;
   Double_t        KpP;
   Double_t        KpTh;
   Double_t        KpTime;
   Double_t        KmP;
   Double_t        KmTh;
   Double_t        KmTime;
   Double_t        BeamTime;
   Double_t        Pol;
   Int_t           PolState;
   Float_t         MLP;
   Double_t        UID;

   // List of branches
   TBranch        *b_Topo;   //!
   TBranch        *b_Correct;   //!
   TBranch        *b_NPerm;   //!
   TBranch        *b_NDet;   //!
   TBranch        *b_TreeDataK2_fUniqueID;   //!
   TBranch        *b_TreeDataK2_fBits;   //!
   TBranch        *b_TreeDataK2_MissMass;   //!
   TBranch        *b_TreeDataK2_MissMass2;   //!
   TBranch        *b_TreeDataK2_MesonMass;   //!
   TBranch        *b_TreeDataK2_HyperonMass;   //!
   TBranch        *b_TreeDataK2_MesonCosTh;   //!
   TBranch        *b_TreeDataK2_MesonPhi;   //!
   TBranch        *b_TreeDataK2_HyperonCosTh;   //!
   TBranch        *b_TreeDataK2_HyperonPhi;   //!
   TBranch        *b_TreeDataK2_Eg;   //!
   TBranch        *b_TreeDataK2_t;   //!
   TBranch        *b_TreeDataK2_HelCosTh;   //!
   TBranch        *b_TreeDataK2_HelPhi;   //!
   TBranch        *b_TreeDataK2_ProtP;   //!
   TBranch        *b_TreeDataK2_ProtTh;   //!
   TBranch        *b_TreeDataK2_ProtTime;   //!
   TBranch        *b_TreeDataK2_KpP;   //!
   TBranch        *b_TreeDataK2_KpTh;   //!
   TBranch        *b_TreeDataK2_KpTime;   //!
   TBranch        *b_TreeDataK2_KmP;   //!
   TBranch        *b_TreeDataK2_KmTh;   //!
   TBranch        *b_TreeDataK2_KmTime;   //!
   TBranch        *b_TreeDataK2_BeamTime;   //!
   TBranch        *b_TreeDataK2_Pol;   //!
   TBranch        *b_TreeDataK2_PolState;   //!
   TBranch        *b_MLP;   //!
   TBranch        *b_UID;   //!

   legacy(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~legacy() { }
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

   ClassDef(legacy,0);
};

#endif

#ifdef legacy_cxx
void legacy::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Topo", &Topo, &b_Topo);
   fChain->SetBranchAddress("Correct", &Correct, &b_Correct);
   fChain->SetBranchAddress("NPerm", &NPerm, &b_NPerm);
   fChain->SetBranchAddress("NDet", &NDet, &b_NDet);
   fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_TreeDataK2_fUniqueID);
   fChain->SetBranchAddress("fBits", &fBits, &b_TreeDataK2_fBits);
   fChain->SetBranchAddress("MissMass", &MissMass, &b_TreeDataK2_MissMass);
   fChain->SetBranchAddress("MissMass2", &MissMass2, &b_TreeDataK2_MissMass2);
   fChain->SetBranchAddress("MesonMass", &MesonMass, &b_TreeDataK2_MesonMass);
   fChain->SetBranchAddress("HyperonMass", &HyperonMass, &b_TreeDataK2_HyperonMass);
   fChain->SetBranchAddress("MesonCosTh", &MesonCosTh, &b_TreeDataK2_MesonCosTh);
   fChain->SetBranchAddress("MesonPhi", &MesonPhi, &b_TreeDataK2_MesonPhi);
   fChain->SetBranchAddress("HyperonCosTh", &HyperonCosTh, &b_TreeDataK2_HyperonCosTh);
   fChain->SetBranchAddress("HyperonPhi", &HyperonPhi, &b_TreeDataK2_HyperonPhi);
   fChain->SetBranchAddress("Eg", &Eg, &b_TreeDataK2_Eg);
   fChain->SetBranchAddress("t", &t, &b_TreeDataK2_t);
   fChain->SetBranchAddress("HelCosTh", &HelCosTh, &b_TreeDataK2_HelCosTh);
   fChain->SetBranchAddress("HelPhi", &HelPhi, &b_TreeDataK2_HelPhi);
   fChain->SetBranchAddress("ProtP", &ProtP, &b_TreeDataK2_ProtP);
   fChain->SetBranchAddress("ProtTh", &ProtTh, &b_TreeDataK2_ProtTh);
   fChain->SetBranchAddress("ProtTime", &ProtTime, &b_TreeDataK2_ProtTime);
   fChain->SetBranchAddress("KpP", &KpP, &b_TreeDataK2_KpP);
   fChain->SetBranchAddress("KpTh", &KpTh, &b_TreeDataK2_KpTh);
   fChain->SetBranchAddress("KpTime", &KpTime, &b_TreeDataK2_KpTime);
   fChain->SetBranchAddress("KmP", &KmP, &b_TreeDataK2_KmP);
   fChain->SetBranchAddress("KmTh", &KmTh, &b_TreeDataK2_KmTh);
   fChain->SetBranchAddress("KmTime", &KmTime, &b_TreeDataK2_KmTime);
   fChain->SetBranchAddress("BeamTime", &BeamTime, &b_TreeDataK2_BeamTime);
   fChain->SetBranchAddress("Pol", &Pol, &b_TreeDataK2_Pol);
   fChain->SetBranchAddress("PolState", &PolState, &b_TreeDataK2_PolState);
   fChain->SetBranchAddress("MLP", &MLP, &b_MLP);
   fChain->SetBranchAddress("UID", &UID, &b_UID);
}

Bool_t legacy::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef legacy_cxx
