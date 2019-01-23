
#ifndef Process_h
#define Process_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include "THSOutput.h"
#include "THS2Pi.h"

// Header file for the classes stored in the TTree if any.
#include <vector>

class Process : public TSelector, public THSOutput, public THS2Pi {
public :
   TTree          *fChain=nullptr;   //!pointer to the analyzed TTree or TChain

  //data members for new branches
   //you must define how they are processed for each event and set to 0 in constructor
   //e.g.   TLorentzVector  *fp1;
// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<THSParticle> *Particles=nullptr;
   vector<THSParticle> *Generated=nullptr;
   vector<short>   *PIDs=nullptr;
   THSEventInfo    *EventInfo=nullptr;

   // List of branches
   TBranch        *b_Particles=nullptr;   //!
   TBranch        *b_Generated=nullptr;   //!
   TBranch        *b_PIDs=nullptr;   //!
   TBranch        *b_EventInfo=nullptr;   //!

   Process(TTree * /*tree*/ =0){};
   virtual ~Process() {/*//SafeDelete(fp1);//If we add pointer ro classmust delete it*/  }
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
   //Additional final state analysis function
   virtual void UserProcess();
   virtual void    Terminate();
//Add THSHisto functions
   virtual void HistogramList(TString sLabel);
   virtual void FillHistograms(TString sCut);

   ClassDef(Process,0);
};

#endif

#ifdef Process_cxx
void Process::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Particles = 0;
   Generated = 0;
   PIDs = 0;
   EventInfo = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(0);
   
   //Set main particles branch, this should always exist
   if(fChain->GetBranch("Particles"))fChain->SetBranchAddress("Particles", &Particles, &b_Particles);
   THSFinalState::SetDetParts(Particles);
   
   //Set PIDS branch, can be used to check event topology before reading whole event
   if(fChain->GetBranch("PIDs"))fChain->SetBranchAddress("PIDs", &PIDs, &b_PIDs);
   THSFinalState::SetDetPIDs(PIDs);
   
   //Set EventInfo, once per event information
   if(fChain->GetBranch("EventInfo"))fChain->SetBranchAddress("EventInfo", &EventInfo, &b_EventInfo);
   THSFinalState::SetEventInfo(EventInfo);
   
   //For Simulated data get the generated truth values
   if(fChain->GetBranch("Generated"))fChain->SetBranchAddress("Generated", &Generated, &b_Generated);
   if(b_Generated)THSFinalState::SetGenParts(Generated);
   
   //The once per run info is stored in a different tree
   //This can be loaded by the classs itself
   if(!fRunInfo) fRunInfo=new THSRunInfo();
   fRunInfo->LoadTree(fChain->GetDirectory()->GetName());
   
   //Call FinalState initialisation
   FileStart();
   
   return ;
}

Bool_t Process::Notify()
{
   THSOutput::HSNotify(fChain);
  THSOutput::InitOutTree();
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef Process_cxx
