////////////////////////////////////////////////////////////////
///
///Class:               Minimiser
///Description:
///           


#pragma once

#include "RooAbsData.h"
#include "Setup.h"
#include <TNamed.h>

namespace HS{
  namespace FIT{

     
    class Minimiser : public TNamed {
      
    public:
      Minimiser()=default;
      Minimiser(const Minimiser&)=default;
      Minimiser(Minimiser&&)=default;
      virtual ~Minimiser()=default;
      Minimiser& operator=(const Minimiser& other)=default;
      Minimiser& operator=(Minimiser&& other) = default;

      virtual RooFitResult* FitTo(Setup &setup,RooAbsData &fitdata)=0;

       
    protected:
      
    
    private:

      

      ClassDef(HS::FIT::Minimiser,1);
      
    };//class Minimiser
    
    
    class Minuit  : public Minimiser {
      
    public:

      Minuit(){SetNameTitle("HSMinuit","Minuit minimiser");}
      Minuit(const Minuit&)=default;
      Minuit(Minuit&&)=default;
      virtual ~Minuit()=default;
      Minuit& operator=(const Minuit& other)=default;
      Minuit& operator=(Minuit&& other) = default;  

      RooFitResult* FitTo(Setup &setup,RooAbsData &fitdata) {
	return setup.Model()->fitTo(fitdata,setup.FitOptions());
      };
      
      ClassDef(HS::FIT::Minuit,1);
      
     };

    class Minuit2  : public Minimiser {
      
    public:

      Minuit2(){SetNameTitle("HSMinuit2","Minuit2 minimiser");}
      Minuit2(const Minuit2&)=default;
      Minuit2(Minuit2&&)=default;
      virtual ~Minuit2()=default;
      Minuit2& operator=(const Minuit2& other)=default;
      Minuit2& operator=(Minuit2&& other) = default;  

      RooFitResult* FitTo(Setup &setup,RooAbsData &fitdata) {

	auto fitOptions=setup.FitOptions();
	fitOptions.Add((RooCmdArg*)RooFit::Minimizer("Minuit2").Clone());
	return setup.Model()->fitTo(fitdata,fitOptions);
      };
      
      ClassDef(HS::FIT::Minuit2,1);
      
     };

    using minimiser_uptr = std::unique_ptr<Minimiser>;

  }//namespace FIT
}//namespace HS

