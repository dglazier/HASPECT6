#include "RooHSComplexSumSqdTerm.h"

namespace HS{
  namespace FIT{

    ////////////////////////////////////////////////////////////////////////////////

    RooHSComplexSumSqdTerm::RooHSComplexSumSqdTerm(const char *name, const char *title, RooAbsReal& c1re, RooAbsReal& c1im, RooAbsReal& c2re, RooAbsReal& c2im,Double_t factor,Int_t sign): RooAbsReal(name, title),_reC1("reC1","reC1",this,c1re),
																						 _imC1("imC1","imC1",this,c1im),
																						 _reC2("reC2","reC2",this,c2re),
																						 _imC2("imC2","imC2",this,c2im),
																							      _factor(factor),
																							      _sign(sign)

    {

    }
    // RooHSComplexSumSqdTerm::RooHSComplexSumSqdTerm(const char *name, const char *title, RooAbsReal& c1re,RooAbsReal& c2re,Double_t factor,Short_t sign): RooAbsReal(name, title),_reC1("reC1","reC1",this,c1re), _reC2("reC2","reC2",this,c2re),_factor(factor),_sign(sign)

    // {

    // }
    RooHSComplexSumSqdTerm::RooHSComplexSumSqdTerm(const RooHSComplexSumSqdTerm& other, const char* name): RooAbsReal(other,name),
													   _reC1("reC1", this, other._reC1),
													   _imC1("imC1", this, other._imC1),
													   _reC2("reC2", this, other._reC2),
													   _imC2("imC2", this, other._imC2),
													   _factor(other._factor),
													   _sign(other._sign)
    {
    
    }
    

    
  }
}

      
