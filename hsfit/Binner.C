#include "Binner.h"
#include "FiledTree.h"
#include <algorithm> 

namespace HS{
  namespace FIT{
    
    Binner::Binner(Setup &setup):fBins("HSBins") {
      LoadSetup(setup);
    }
    
    void Binner::LoadSetup(Setup &setup) {
      fIsSetup=kTRUE;
      
      fBins.SetName("HSBins");
      
      fOutDir=setup.GetOutDir();
      
      //   auto vars=setup.FitVars();
      
      for(auto& var : setup.FitVars()){
       	fVarNames.push_back(var->GetName());
      }
      for(auto& cat : setup.FitCats()){
       	fVarNames.push_back(cat->GetName());
      }
      
      fVarNames.push_back(setup.GetIDBranchName());
    }

    // void  Binner::LoadAuxVar(TString vname){
    //   fVarNames.push_back(vname);
    // }
    void  Binner::LoadBinVar(TString opt,Int_t nbins,Double_t min,Double_t max){
      fBins.AddAxis(opt,nbins,min,max);     
    }
    void  Binner::LoadBinVar(TString opt,Int_t nbins,Double_t* xbins){
      fBins.AddAxis(opt,nbins,xbins);     
    }

    void Binner::ReloadData(TString fname,TString name){
      HS::Bins bins("HSBins",Form("%s/%sBinsConfig.root",fOutDir.Data(),name.Data()));
      //fBins=bins;
      fNameToFiles[name]=bins.GetFileNames();
      fNameToTree[name]=bins.GetBinnedTreeName();
      fBinNames=bins.GetBinNames();
      
      }
      void Binner::SplitData(TString tname,TString fname,TString name){
	if(fBins.GetNAxis()==0){ //no splits required
	  fNameToFiles[name]={{fname}};
	  fNameToTree[name]=tname;
	  fBinNames={{""}};
	  return;
	}
	if(!fIsSetup) {
	  cout<<"Binner::SplitData ERROR not setup yet!"<<endl;
	  exit(0);
	}
	auto filetree=FiledTree::Read(tname,fname);
	SplitData(filetree->Tree().get(), name);
    }

    void Binner::SplitData(TTree* tree,TString name){
      //turn off all branches we do not require to save space and memory
      tree->SetBranchStatus("*",0);
      
      for(auto &vname : fVarNames) {//only copy variable branches for speed
	tree->SetBranchStatus(vname,1);
      }
      tree->Print();
      cout<<fOutDir<<" "<<name<<" "<<endl;
      //now split the tree into bins and save in subdirs of fOutDir
      fBins.SetOutDir(fOutDir);
      fBins.SetDataName(name);
      fBins.RunBinTree(tree);
      fBins.Save(fOutDir+name+"BinsConfig.root");
      fNameToFiles[name]=fBins.GetFileNames();
      fNameToTree[name]=tree->GetName();
      fBinNames=fBins.GetBinNames();
  }

  
  }//namepsace FIT
}//namespace HS
