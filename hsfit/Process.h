////////////////////////////////////////////////////////////////
///
///Class:               Process
///Description:
///           
#pragma once

#include "FitManager.h"
#include "FitSelector.h"
#include "TProof.h"


namespace HS{
  namespace FIT{
    namespace PROCESS{

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
	  
	  FitSelector selector;
	  selector.SetFitManager(fm);
	  proof->Process(&selector,fm->Data().GetN());
 	}
	
      }; //class Proof
   
    }
  }
}
