////////////////////////////////////////////////////////////////
///
///Class:               Process
///Description:
///           
#pragma once

#include "FitManager.h"
#include "FitSelector.h"
#include "TProof.h"
#include "TString.h"
#include <vector>
#include <algorithm>

namespace HS{
  namespace FIT{
    namespace PROCESS{
      
      std::vector<TString> gCompilesList;

      class Here  {

      public :
      
   
	static void Go(std::shared_ptr<FitManager> fm){
	  Go(fm.get());
	}
	static void Go(FitManager* fm){
	  if(!fm) return;
	  fm->RunAll();
 	
	};
	static void One(std::shared_ptr<FitManager> fm,Int_t ifit){
	  One(fm.get(),ifit);
	}
	static void One(FitManager* fm,Int_t ifit){
	  if(!fm) return;
	  fm->RunOne(ifit);
	
	};
  
      }; //class Here


      class Proof  {

      public :
      
	static void Go(std::shared_ptr<FitManager> fm,Int_t N){
	  Go(fm.get(),N);
	}
	
	static void Go(FitManager* fm,Int_t N){
	  if(!fm) return;
	  fm->WriteThis();
	  if(!gProof){
	    TProof*  proof = TProof::Open("://lite");
	    gROOT->ProcessLine(Form(".x LoadFitProof.C+(%d)",N));
	  
	  for(auto& macro : gCompilesList)
	    proof->Load(Form("%s++",macro.Data()),kTRUE);
	  }
	  
	  FitSelector selector;
	  selector.SetFitManager(fm);
	  gProof->Process(&selector,fm->GetN());
 	}
	
      }; //class Proof


     class Farm  {

      public :
      
       static void Go(std::shared_ptr<FitManager> fm,Int_t Njobs,Bool_t toFarm){
	 Go(fm.get(),toFarm);
	}
	
       static void Go(FitManager* fm,Bool_t toFarm);
	
      }; //class Proof


      class Loader {

      public :
	static void Compile(TString macro){
	  gROOT->ProcessLine(Form(".L %s+",macro.Data()));
	  if(!std::count(gCompilesList.begin(),gCompilesList.end(),macro))gCompilesList.push_back(macro);
	}
	static void Compile(std::vector<TString> macList){
	  for(auto& macro : macList){
	    Compile(macro);
	  }
	}
	static void CompileHere(TList*  macList){
	  for(Int_t i=0;i<macList->GetEntries();i++){
	    TString macro = macList->At(i)->GetName();
	    std::cout<<"Will load "<<macro<<std::endl;
	    gSystem->Exec(Form("cp %s .",macro.Data()));
	    TString hfile=macro;
	    hfile.ReplaceAll(".C",".h");
	    hfile.ReplaceAll(".cxx",".h");
	    gSystem->Exec(Form("cp %s .",hfile.Data()));
	    Compile(gSystem->BaseName(macro));
	  }
	}
	///	std::vector<TString> GetCompiled(){return gCompilesList;};
	
      private :
	
	
      };
    }
  }
}
