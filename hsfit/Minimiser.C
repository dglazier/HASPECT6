#include "Minimiser.h"
#include <RooStats/RooStatsUtils.h>
#include <RooDataSet.h>

namespace HS{
  namespace FIT{
    
    Minuit::Minuit(UInt_t nrefits) : fNRefits(nrefits) {
      SetNameTitle("HSMinuit","Minuit minimiser");
    }
 
    void Minuit::Run(Setup &setup,RooAbsData &fitdata){
      fSetup=&setup;
      fData=&fitdata;
      
      //original fit using intial parameters
      FitTo();
      if(!fNRefits){ //One fit is enough...
	fResult->Print();
	return;
      }  
      //Perform many fits with differnt initial parameters
      UInt_t nrefit = 0;
      fSetup->SaveSnapShot(Form("Refit_%d",nrefit)); //original
      vector<Double_t> likelies;

      using result_uptr=std::unique_ptr<RooFitResult>;
	
      vector<result_uptr> results;

      //save original likelihood and results
      StoreLikelihood(likelies);
      results.push_back(result_uptr{dynamic_cast<RooFitResult*>(fResult->clone())});

      //loop over refits
      while(nrefit++<fNRefits){
	fSetup->RandomisePars();
	 
	FitTo();
	  
	fSetup->SaveSnapShot(Form("Refit_%d",nrefit));

	StoreLikelihood(likelies);
	results.push_back(result_uptr{dynamic_cast<RooFitResult*>(fResult->clone())});
      }
	
      //Find the best fit result and save it
      Int_t best=std::distance(likelies.begin(), std::min_element(likelies.begin(), likelies.end()));
	
      cout<<"Minuit::FitTo() best fit likelihood "<<likelies[best]<<" from fit "<<best<<" all likelihoods "<<endl;

      for(auto& lh:likelies)
	cout<<lh<<" ";
      cout<<endl;

      fSetup->LoadSnapShot(Form("Refit_%d",best));
      fResult=dynamic_cast<RooFitResult*>(results[best]->clone());    
      fResult->Print();
      return;
    }
    ////////////////////////////////////////////////////////////////
    file_uptr Minuit::SaveInfo(){
      
      TString fileName=fSetup->GetOutDir()+fSetup->GetName()+"/Results"+fSetup->GetTitle()+GetName()+".root";
      file_uptr file(TFile::Open(fileName,"recreate"));
      
       fSetup->Parameters().Print();
      fSetup->Yields().Print();
      //save paramters and chi2s in  dataset (for easy merging)
      RooArgSet saveArgs(fSetup->Parameters());
      saveArgs.add(fSetup->Yields());
     
      RooRealVar Nllval("NLL","NLL",fResult->minNll());
      saveArgs.add(Nllval);
	
      RooDataSet saveDS(TString(GetName())+"Results",TString(GetName())+"Results",saveArgs);
      saveDS.add(saveArgs);
      saveDS.Write();
      TTree* treeDS=RooStats::GetAsTTree("ResultsTree","ResultsTree",saveDS);
      treeDS->Write();
      fResult->Write("MinuitResult");

      return std::move(file);
 
    }

    void Minuit::StoreLikelihood(vector<Double_t> &likelies){
      if(!fResult) return;
      Bool_t nan=TMath::IsNaN(fResult->minNll());
      //check covariance OK or externally provide (SumW2Error) =-1
      Bool_t edm=(fResult->covQual()>1)||(fResult->covQual()==-1);
      Bool_t fail=(fResult->minNll()!=-1e+30);
      if((!nan)&&edm&&fail)likelies.push_back(fResult->minNll());
      else likelies.push_back(1E300);
    }
    
    //////////////////////////////////////////////////////////////
    Minuit2::Minuit2(UInt_t nrefits) : Minuit(nrefits) {
      SetNameTitle("HSMinuit2","Minuit2 minimiser");
    }

    
  }

}
