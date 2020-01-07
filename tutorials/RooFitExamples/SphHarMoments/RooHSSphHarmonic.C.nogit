

#include "RooHSSphHarmonic.h"

#include "TError.h"

namespace HS{
  namespace FIT{

    ////////////////////////////////////////////////////////////////////////////////


 
    RooHSSphHarmonic::RooHSSphHarmonic(const char* name, const char* title, RooAbsReal& ctheta, RooAbsReal& phi, int l, int m,Double_t factor)
      : RooHSComplex(name, title)
      , _ctheta("ctheta", "ctheta", this, ctheta)
      , _phi("phi", "phi", this, phi)
      , _L(l),_M(m)
    {
      //Below is handled in ROOT::Math::assoc_legendre
      if(m>0&&m%2==1)_MFactor=-1;
      else _MFactor =1;

     
      _absM=TMath::Abs(m);
      
      //Note factor allows different scaling for each moment
      //e.g. case tau when M=0, in eqn a15a,b  https://arxiv.org/pdf/1906.04841.pdf

      //case M>0
      _N=_MFactor*TMath::Sqrt(Double_t(2*_L+1)/(4*TMath::Pi())*TMath::Factorial(_L-(_absM))/TMath::Factorial(_L+(_absM)) )*factor;
      //_N=_MFactor*Double_t(2*_L+1)/(4*TMath::Pi())*TMath::Sqrt(TMath::Factorial(_L-(_absM))/TMath::Factorial(_L+(_absM)) )*factor;
    
      //case M<0 //Note not handled by ROOT::Math::assoc_legendre!
      //if(_M<0){  //P^-M_L=(-1)^M*(L-M)!/(L+M)!P^M_L
	//	_N=_N*(TMath::Factorial(_L-(_absM))/TMath::Factorial(_L+(_absM)));
	//_N=_N*(TMath::Factorial(_L-(_M))/TMath::Factorial(_L+(_M)));
	//if(_absM%2==1) //(-1)^M for M<0
	    // _N*=-1;
       // }
  
    }




    ////////////////////////////////////////////////////////////////////////////////

    RooHSSphHarmonic::RooHSSphHarmonic(const RooHSSphHarmonic& other, const char* name)
      : RooHSComplex(other, name),
	_ctheta("ctheta", this, other._ctheta),
	_phi("phi", this, other._phi),
	_absM(other._absM),
	_L(other._L), _M(other._M)
    {
      // if(_M%2==1)_MFactor=-1;
      //else _MFactor =1;
      //_MFactor =1;
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

    RooHSSphHarmonicIm::RooHSSphHarmonicIm(const char *name, const char *title, RooAbsReal& ctheta, RooAbsReal& phi, RooAbsReal& sphHar,Int_t conj)
      :  RooAbsReal(name, title),
	 _ctheta("CosTheta","CosTheta",this,ctheta),
	 _phi("Phi","Phi",this,phi),
	 _mag("Mag","Mag",this,sphHar),
	 _conj(conj)
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
	_M(other._M),
	_conj(other._conj)
    {
   
    }
  }
}
