#pragma once

#include <RooAbsReal.h>
#include <RooRealProxy.h>

namespace HS{
  namespace FIT{
    
    class RooHSComplexSumSqdTerm : public RooAbsReal {
      
      
    public:
      
      RooHSComplexSumSqdTerm() =default;
      virtual ~RooHSComplexSumSqdTerm() =default;
      // 
      RooHSComplexSumSqdTerm(const char *name, const char *title, RooAbsReal& c1re, RooAbsReal& c1im, RooAbsReal& c2re, RooAbsReal& c2im,Double_t factor=1,Int_t sign=1);
      //RooHSComplexSumSqdTerm(const char *name, const char *title, RooAbsReal& c1re, RooAbsReal& c2re,Double_t factor=1,Short_t sign=1);
      
      RooHSComplexSumSqdTerm(const RooHSComplexSumSqdTerm& other, const char* name = 0);
      TObject* clone(const char* newname) const override{ return new RooHSComplexSumSqdTerm(*this, newname); }

      
	protected:
      Double_t evaluate() const final{
	//	if(_sign<0)cout<<GetName()<<" "<<_reC1.arg().GetName()<<" "<<_reC1<<" "<<_reC2.arg().GetName()<<" "<<_reC2<<" "<<_imC1.arg().GetName()<<" "<<  _imC1<<" "<<_imC2.arg().GetName()<<" "<<_imC2<<endl;
		//	if(_sign<0)cout<<GetName()<<" "<<(_reC1*_reC2 + _imC1*_imC2)<<endl;
	return (_reC1*_reC2 + _sign*_imC1*_imC2)*_factor; }
      
    private:
      RooRealProxy _reC1;
      RooRealProxy _imC1;
      RooRealProxy _reC2;
      RooRealProxy _imC2;
      Double_t _factor=1;
      Short_t _sign=1;
      
    };
    
  }
}
