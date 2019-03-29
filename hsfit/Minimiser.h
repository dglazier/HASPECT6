////////////////////////////////////////////////////////////////
///
///Class:               Minimiser
///Description:
///           


#pragma once

#include "Setup.h"
#include <RooAbsData.h>
#include <RooFitResult.h>
#include <TNamed.h>
#include <TFile.h>

namespace HS{
  namespace FIT{

    using file_uptr=std::unique_ptr<TFile> ;

    
    class Minimiser : public TNamed {
      
    public:
      Minimiser()=default;
      Minimiser(const Minimiser&)=default;
      Minimiser(Minimiser&&)=default;
      virtual ~Minimiser()=default;
      Minimiser& operator=(const Minimiser& other)=default;
      Minimiser& operator=(Minimiser&& other) = default;

      virtual void Run(Setup &setup,RooAbsData &fitdata)=0;

      //return file in case you want to save anything else
      virtual file_uptr SaveInfo()=0;
       
    protected:
      Setup *fSetup=nullptr; //!not owned by minimiser
      RooAbsData* fData=nullptr; //!not owned by minimiser

    
    private:

 
      ClassDef(HS::FIT::Minimiser,1);
      
    };//class Minimiser
    
    
    class Minuit  : public Minimiser {
      
    public:

      Minuit(UInt_t nrefits=0) ;
      Minuit(const Minuit&)=default;
      Minuit(Minuit&&)=default;
      virtual ~Minuit()=default;
      Minuit& operator=(const Minuit& other)=default;
      Minuit& operator=(Minuit&& other) = default;  

      void Run(Setup &setup,RooAbsData &fitdata) override;
      
      virtual void FitTo() {
	fResult=fSetup->Model()->fitTo(*fData,fSetup->FitOptions());
      };

      file_uptr SaveInfo() override;

    protected :
      void StoreLikelihood(vector<Double_t> &likelies);

      RooFitResult* fResult=nullptr;//! dont write
       
      UInt_t fNRefits=0;
      
      ClassDefOverride(HS::FIT::Minuit,1);
      
     };

    class Minuit2  : public Minuit {
      
    public:

      Minuit2(UInt_t nrefits=0);
      Minuit2(const Minuit2&)=default;
      Minuit2(Minuit2&&)=default;
      virtual ~Minuit2()=default;
      Minuit2& operator=(const Minuit2& other)=default;
      Minuit2& operator=(Minuit2&& other) = default;  

      void FitTo() final {
	auto fitOptions=fSetup->FitOptions();
	fitOptions.Add((RooCmdArg*)RooFit::Minimizer("Minuit2").Clone());
	fResult=fSetup->Model()->fitTo(*fData,fitOptions);
      };
      
   
      ClassDefOverride(HS::FIT::Minuit2,1);
      
     };

    using minimiser_uptr = std::unique_ptr<Minimiser>;

  }//namespace FIT
}//namespace HS

