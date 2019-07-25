

#include "RooHSSphHarmonic.h"

#include "TError.h"

namespace HS{
  namespace FIT{

    ////////////////////////////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////////////////////////////

  
    ////////////////////////////////////////////////////////////////////////////////
    ///TODO: for now, we assume that ctheta has a range [-1,1]
    /// should map the ctheta range onto this interval, and adjust integrals...

    RooHSSphHarmonic::RooHSSphHarmonic(const char* name, const char* title, RooAbsReal& ctheta, int l, int m,Double_t factor)
      : RooAbsReal(name, title)
      , _ctheta("ctheta", "ctheta", this, ctheta)
      , _L(l),_M(m)
    {
      if(_M%2==1)_MFactor=-1;
      else _MFactor =1;
      //Note factor allows different scaling for each moment
      //e.g. case tau when M=0, in eqn a15a,b  https://arxiv.org/pdf/1906.04841.pdf
      _N=_MFactor*TMath::Sqrt(Double_t(2*_L+1)/(4*TMath::Pi())*TMath::Factorial(_L-(_M))/TMath::Factorial(_L+(_M)) )*factor;

    }




    ////////////////////////////////////////////////////////////////////////////////

    RooHSSphHarmonic::RooHSSphHarmonic(const RooHSSphHarmonic& other, const char* name)
      : RooAbsReal(other, name),
	_ctheta("ctheta", this, other._ctheta),
	_L(other._L), _M(other._M)
    {
      if(_M%2==1)_MFactor=-1;
      else _MFactor =1;
 
      _N=other._N;
    }
    

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////

    RooHSSphHarmonicRe::RooHSSphHarmonicRe(const char *name, const char *title, RooAbsReal& ctheta, RooAbsReal& phi, RooAbsReal& sphHar )
      :  RooAbsReal(name, title),
	 _ctheta("CosTheta","CosTheta",this,ctheta),
	 _phi("Phi","Phi",this,phi),
	 _mag("Mag","Mag",this,sphHar)
    {
      auto mag=dynamic_cast<RooHSSphHarmonic*>(&sphHar);
      _M=mag->M();
    }
    ////////////////////////////////////////////////////////////////////////////////
    RooHSSphHarmonicRe::RooHSSphHarmonicRe(const RooHSSphHarmonicRe& other, const char* name)
      : RooAbsReal(other, name),
	_ctheta("CosTheta", this, other._ctheta),
	_phi("Phi", this, other._phi),
	_mag("Mag", this, other._mag),
	_M(other._M)
    {
   
    }
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////

    RooHSSphHarmonicIm::RooHSSphHarmonicIm(const char *name, const char *title, RooAbsReal& ctheta, RooAbsReal& phi, RooAbsReal& sphHar )
      :  RooAbsReal(name, title),
	 _ctheta("CosTheta","CosTheta",this,ctheta),
	 _phi("Phi","Phi",this,phi),
	 _mag("Mag","Mag",this,sphHar)
    {
      auto mag=dynamic_cast<RooHSSphHarmonic*>(&sphHar);
      _M=mag->M();
    }
    ////////////////////////////////////////////////////////////////////////////////
    RooHSSphHarmonicIm::RooHSSphHarmonicIm(const RooHSSphHarmonicIm& other, const char* name)
      : RooAbsReal(other, name),
	_ctheta("CosTheta", this, other._ctheta),
	_phi("Phi", this, other._phi),
	_mag("Mag", this, other._mag),
	_M(other._M)
    {
   
    }
  }
}
