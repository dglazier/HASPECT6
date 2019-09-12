#pragma once

#include <RooAbsReal.h>
#include <TString.h>

namespace HS{
  namespace FIT{
    
    class RooHSComplex : public RooAbsReal {
      
      
    public:
      RooHSComplex()=default;
      
      RooHSComplex(const char* name, const char* title):RooAbsReal(name, title){};
    RooHSComplex(const RooHSComplex& other, const char* name = 0):RooAbsReal(other, name){};

      virtual ~RooHSComplex() =default;

     //Workspace Factory strings for real and imaginery part
      //Name Convention Re+"name", Im+"name" required for parsers
       virtual TString FactoryReal() const  = 0;
       virtual TString FactoryImag() const  = 0;
       virtual TString FactoryImagConj() const  = 0;
      
       ClassDefOverride(HS::FIT::RooHSComplex,1);
    };
    
  }
}
