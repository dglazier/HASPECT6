#include "BootStrapper.h"
#include "FiledTree.h"
#include "Bins.h"
#include <TEntryList.h> 
#include <TSystem.h> 
#include <TBranch.h> 
#include <algorithm> 

namespace HS{
  namespace FIT{



    BootStrapper::BootStrapper(Int_t N): fNBoots(N) {

    }
  
    //////////////////////////////////////////////////
    ////Split the data into subsets for bootstrapping
    void BootStrapper::DivideData(TString tname,TString fname){

      DivideData(FiledTree::Read(tname,fname)->Tree().get());
      
    }
   void BootStrapper::DivideData(TTree* tree){
      
      Long64_t Nentries=tree->GetEntries();
      cout<<"Boot strap "<<tree<<" "<<Nentries<<endl;
      
      //create random entry order
      vector<Long64_t> vrandom(Nentries);

      for(Long64_t ir=0;ir<Nentries;ir++)
	vrandom[ir]=ir;
      
      std::random_shuffle(vrandom.begin(),vrandom.end());

      Int_t iTree=0;
      TBranch* iBranch=tree->Branch("Boot",&iTree);
      for(Long64_t ir=0;ir<Nentries;ir++){
	iTree=vrandom[ir]%fNBoots;
	iBranch->Fill();
      }
      TString newFileName=tree->GetDirectory()->GetName();
      //     newFileName.ReplaceAll(".root",Form("Boot%d.root",i));
      HS::Bins bins;
      bins.AddAxis("Boot",fNBoots,0,fNBoots);
      bins.SetOutDir(gSystem->DirName(newFileName));
      bins.SetDataName("Data");
      bins.RunBinTree(tree);
      auto addFileNames=bins.GetFileNames();
      fFileNames.insert(fFileNames.end(), addFileNames.begin(), addFileNames.end());
    }
   //  void BootStrapper::DivideData(TTree* tree){
      
   //    Long64_t Nentries=tree->GetEntries();
   //    cout<<"Boot strap "<<tree<<" "<<Nentries<<endl;
      
   //    //create random entry order
   //    vector<Long64_t> vrandom(Nentries);
   //    for(Long64_t ir=0;ir<Nentries;ir++)
   // 	vrandom[ir]=ir;
   //    std::random_shuffle(vrandom.begin(),vrandom.end());

   //    Long64_t EvPerBoot = Nentries/fNBoots;
   //    Int_t Nextra =  Nentries%fNBoots;
      
   //    for(Int_t i=0 ;i < fNBoots ; i++){
   // 	cout<<"loop "<<fNBoots <<" "<<endl;
   // 	auto first = vrandom.begin() + i*EvPerBoot;
   // 	auto last = vrandom.begin() + (i+1)*EvPerBoot;
   // 	vector<Long64_t> newVec(first, last);


   // 	std::unique_ptr<TEntryList> elist(new TEntryList(Form("%d",i),Form("%d",i)));

   // 	for(auto& entry: newVec)
   // 	  elist->Enter(entry);
 
   // 	tree->SetEntryList(elist.get());

   // 	TString newFileName=tree->GetDirectory()->GetName();
   // 	newFileName.ReplaceAll(".root",Form("Boot%d.root",i));
   // 	FiledTree::RecreateCopyFull(tree,newFileName);
   // 	fFileNames.push_back(newFileName);
	
   // 	//auto bootTree=std::unique_ptr<TTree>(tree->CopyTree(""));
   // 	tree->SetEntryList(nullptr);
	
   //    }
   //  }
   // void BootStrapper::DivideData(TTree* tree){
      
   //    Long64_t Nentries=tree->GetEntries();
   //    cout<<"Boot strap "<<tree<<" "<<Nentries<<endl;
      
   //    //create random entry order
   //    vector<Long64_t> vrandom(Nentries);
   //    for(Long64_t ir=0;ir<Nentries;ir++)
   // 	vrandom[ir]=ir;
   //    std::random_shuffle(vrandom.begin(),vrandom.end());

   //    Long64_t EvPerBoot = Nentries/fNBoots;
   //    Int_t Nextra =  Nentries%fNBoots;
      
   //    for(Int_t i=0 ;i < fNBoots ; i++){
   // 	cout<<"loop "<<fNBoots <<" "<<endl;
   // 	auto first = vrandom.begin() + i*EvPerBoot;
   // 	auto last = vrandom.begin() + (i+1)*EvPerBoot;
   // 	vector<Long64_t> newVec(first, last);


   // 	std::unique_ptr<TEntryList> elist(new TEntryList(Form("%d",i),Form("%d",i)));

   // 	for(auto& entry: newVec)
   // 	  elist->Enter(entry);
 
   // 	tree->SetEntryList(elist.get());

   // 	TString newFileName=tree->GetDirectory()->GetName();
   // 	newFileName.ReplaceAll(".root",Form("Boot%d.root",i));
   // 	FiledTree::RecreateCopyFull(tree,newFileName);
   // 	fFileNames.push_back(newFileName);
	
   // 	//auto bootTree=std::unique_ptr<TTree>(tree->CopyTree(""));
   // 	tree->SetEntryList(nullptr);
	
   //    }
   //  }
  }
}
