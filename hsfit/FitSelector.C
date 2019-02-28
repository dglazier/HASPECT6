#define FitSelector_cxx
// The class definition in FitSelector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("FitSelector.C")
// root> T->Process("FitSelector.C","some options")
// root> T->Process("FitSelector.C+")
//


#include "FitSelector.h"
#include "FitManager.h"
#include <TH2.h>
#include <TStyle.h>
#include <chrono>
#include <thread>
#include <iostream>

// #include "Data.h"
// #include "Binner.h"
// #include "Setup.h"
// #include "FiledTree.h"
namespace HS{
  namespace FIT{
    void FitSelector::Begin(TTree * /*tree*/)
    {
      // The Begin() function is called at the start of the query.
      // When running with PROOF Begin() is only called on the client.
      // The tree argument is deprecated (on PROOF 0 is passed).

      TString option = GetOption();

      // HS::FIT::Setup RF;
      // RF.SetOutDir("/work/Dropbox/HaSpect/dev/HASPECT6/hsfit2/out/");
      // ///////////////////////////////Load Variables
      // RF.LoadVariable("Mmiss[0,10]");//should be same name as variable in tree  
      // RF.SetIDBranchName("fgID");
      // ////////////////////////////Make Bins
      // HS::FIT::Binner bins(RF);
      // bins.LoadBinVar("Eg",4,3,4);
      // bins.MakeTrees(HS::FiledTree::Read("MyModel","/work/Dropbox/HaSpect/dev/HASPECT6/hsfit2/Data.root")->Tree().get(), "BD");
      
      // auto flist = new TList();
      // flist->SetName("HSFitFiles");
      // for(auto &st : bins.FileNames())
      //   flist->Add(new TNamed(st.Data(),""));

      //cout<<"saving to "<<fFitManager->SetUp().GetOutDir()<<endl;
      // fFitManager->WriteThis();
      //cout<<"done saving "<<endl;
      //      fFitManager.SaveBins();
      
      if(!fInput) fInput=new TList();
      TNamed *outdir=new TNamed("HSOUTDIR",fFitManager->SetUp().GetOutDir().Data());
      //      fFitManager.SetUp().SetName("HSFitSetup");
      //     auto* setup = &fFitManager.SetUp();
 // auto *setup=new Setup(fFitManager.SetUp());
      // setup->SetName("HSFitSetup");
      fInput->Add(outdir);
      //fFitManager->SetName("HSFit");
      //fInput->Add(fFitManager);
     
    }

    void FitSelector::SlaveBegin(TTree * /*tree*/)
    {
      // The SlaveBegin() function is called after the Begin() function.
      // When running with PROOF SlaveBegin() is called on each slave server.
      // The tree argument is deprecated (on PROOF 0 is passed).

      TString option = GetOption();
      fInput->Print();
      auto outdir=dynamic_cast<TNamed*>(fInput->FindObject("HSOUTDIR"));
      TString outdirstr=TString(outdir->GetTitle());
      if(outdirstr!=TString("")||!outdirstr.EndsWith("/"))
	//	outdirstr.Append('/');
	fFitfile=TFile::Open(outdirstr+"HSFit.root");
      fFitManager=dynamic_cast<FitManager*>( fFitfile->Get("HSFit") );
      // fFitManager->Data().LoadSetup(&fFitManager->SetUp());
      // auto* setup = dynamic_cast<Setup*>(fInput->FindObject("HSFitSetup"));
	// fFitfile=TFile::Open(outdirstr+"HSFitDump.root","recreate");
	//fFitManager=dynamic_cast<FitManager*>( fInput->FindObject("HSFit") );
      fFitManager->Data().LoadSetup(&fFitManager->SetUp());
     cout<<"FitSelector::SlaveBegin( "<<fFitManager->SetUp().GetOutDir()<<endl;
      // fFitManager.CopySetup(fInput->FindObject("HSFitSetup"));
      
      //    auto onames=dynamic_cast<TList*>( fInput->FindObject("HSFitFiles"));
      //    for(Int_t i=0;i<onames->GetEntries();i++)
      //      fFitFileNames.push_back(onames->At(i)->GetName());
      //
    }

    Bool_t FitSelector::Process(Long64_t entry)
    {
      // The Process() function is called for each entry in the tree (or possibly
      // keyed object in the case of PROOF) to be processed. The entry argument
      // specifies which entry in the currently loaded tree is to be processed.
      // When processing keyed objects with PROOF, the object is already loaded
      // and is available via the fObject pointer.
      //
      // This function should contain the \"body\" of the analysis. It can contain
      // simple or elaborate selection criteria, run algorithms on the data
      // of the event and typically fill histograms.
      //
      // The processing can be stopped by calling Abort().
      //
      // Use fStatus to set the return value of TTree::Process().
      //
      // The return value is currently not used.
      std::cout<<"Wntry "<<entry<<std::endl;
      std::cout<<"Out dir  "<<fFitManager->SetUp().GetOutDir()<<std::endl;
      
      fFitManager->RunOne(entry);

  
      // fReader.SetEntry(entry);
      // cout<<fFitFileNames[*bindex]<<endl;
      // std::this_thread::sleep_for(std::chrono::seconds(2));
      // HS::FIT::Setup RF;
      // RF.SetOutDir("/work/Dropbox/HaSpect/dev/HASPECT6/hsfit2/out/");
      // ///////////////////////////////Load Variables
      // RF.LoadVariable("Mmiss[0,10]");//should be same name as variable in tree  
      // RF.SetIDBranchName("fgID");
   
      // /////////////////////////////Make Model Signal
      // RF.Factory("Gaussian::Signal( Mmiss, SIMm[6,4,7], SIMw[0.2,0.0001,3] )");
      // RF.LoadSpeciesPDF("Signal",1);
   
   
      // ////////////////////////////////Additional background
      // RF.Factory("Chebychev::BG(Mmiss,{a0[-0.1,-1,1],a1[0.1,-1,1]})");
      // RF.LoadSpeciesPDF("BG",1);

      // RF.TotalPDF();

      // HS::FIT::DataEvents dataset(RF,"BinnedTree",{fFitFileNames[*bindex]});
      // RF.Model()->fitTo(dataset.Get());
      // dataset.Clear();
 
      return kTRUE;
    }

    void FitSelector::SlaveTerminate()
    {
      // The SlaveTerminate() function is called after all entries or objects
      // have been processed. When running with PROOF SlaveTerminate() is called
      // on each slave server.
      delete fFitfile;
      
    }

    void FitSelector::Terminate()
    {
      // The Terminate() function is the last function to be called during
      // a query. It always runs on the client, it can be used to present
      // the results graphically or save the results to file.

    }
    void FitSelector::Init(TTree *tree)
    {
      // The Init() function is called when the selector needs to initialize
      // a new tree or chain. Typically here the reader is initialized.
      // It is normally not necessary to make changes to the generated
      // code, but the routine can be extended by the user if needed.
      // Init() will be called many times when running on PROOF
      // (once per file to be processed).

      // fReader.SetTree(tree);
    }

    Bool_t FitSelector::Notify()
    {
      // The Notify() function is called when a new file is opened. This
      // can be either for a new TTree in a TChain or when when a new TTree
      // is started when using PROOF. It is normally not necessary to make changes
      // to the generated code, but the routine can be extended by the
      // user if needed. The return value is currently not used.

      return kTRUE;
    }

  }
}
