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
      
   
	static void Go(FitManager* fm){
	  if(!fm) return;
	  fm->RunAll();
 	
	};
	static void One(FitManager* fm,Int_t ifit){
	  if(!fm) return;
	  fm->RunOne(ifit);
	
	};
  
      }; //class Here


      class Proof  {

      public :
      
	static void Go(FitManager* fm,Int_t N){
	  if(!fm) return;
	  fm->WriteThis();
	  auto  proof = TProof::Open("://lite");
	  gROOT->ProcessLine(Form(".x LoadFitProof.C+(%d)",N));
	  for(auto& macro : gCompilesList) 
	    proof->Load(Form("%s+",macro.Data()));
	  
	  FitSelector selector;
	  selector.SetFitManager(fm);
	  proof->Process(&selector,fm->Data().GetN());
 	}
	
      }; //class Proof


      class Loader {

      public :
	static void Compile(TString macro){
	  gROOT->ProcessLine(Form(".L %s+",macro.Data()));
	  if(!std::count(gCompilesList.begin(),gCompilesList.end(),macro))gCompilesList.push_back(macro);
	}

	std::vector<TString> GetCompiled(){return gCompilesList;};
	
      private :
	
	
      };
    }
  }
}
