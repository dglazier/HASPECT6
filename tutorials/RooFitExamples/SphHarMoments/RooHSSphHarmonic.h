#ifndef ROO_REALSPHHARMONIC
#define ROO_REALSPHHARMONIC

#include <RooAbsReal.h>
#include <RooRealProxy.h>
#include <Math/SpecFunc.h>
#include <TMath.h>

namespace HS{
  namespace FIT{


    
    class RooHSSphHarmonic : public RooAbsReal {
    public:
      RooHSSphHarmonic() =default;
      // a Real part of Spherical Harmonic, Y_l^m(costTh,Phi)
      RooHSSphHarmonic(const char *name, const char *title, RooAbsReal& ctheta, int l, int m=0,Double_t factor=1);

      RooHSSphHarmonic(const RooHSSphHarmonic& other, const char* name = 0);
      TObject* clone(const char* newname) const override{ return new RooHSSphHarmonic(*this, newname); }
      virtual ~RooHSSphHarmonic() =default;


      Int_t L() const{return _L;}
      Int_t M() const{return _M;}
    protected:
      //return magnitude of Spherical Harmonic Moment
      Double_t evaluate() const final;
      Bool_t CheckClean() const;
    private: // allow RooSpHarmonic access...
      RooRealProxy _ctheta;
      Double_t _N=0;
      mutable Double_t _lastCTheta=1E10;
      mutable Double_t _lastVal=0;
      Int_t _L=0;
      Int_t _M=0;
      Short_t _MFactor=0;

      
      ClassDefOverride(HS::FIT::RooHSSphHarmonic,1);
    };
    ////////////////////////////////////////////////////////////////////////////////
    
    inline Double_t RooHSSphHarmonic::evaluate() const
    {
      if(CheckClean()) return _lastVal;
 
      return _lastVal=_N*ROOT::Math::assoc_legendre(_L,(_M),_lastCTheta);
    }
    ////////////////////////////////////////////////////////////////////////////////
    
    inline Bool_t RooHSSphHarmonic::CheckClean() const
    {
      Double_t cth=_ctheta;
      if(cth==_lastCTheta ) return kTRUE;
      _lastCTheta=cth;
      return kFALSE;
 
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////
    class RooHSSphHarmonicIm : public RooAbsReal {
    public:
      RooHSSphHarmonicIm() =default;
      // a Imaginery part of Spherical Harmonic, Y_l^m(costTh,Phi)
      RooHSSphHarmonicIm(const char *name, const char *title, RooAbsReal& ctheta, RooAbsReal& phi, RooAbsReal& sphHar );

      RooHSSphHarmonicIm(const RooHSSphHarmonicIm& other, const char* name = 0);
      TObject* clone(const char* newname) const override { return new RooHSSphHarmonicIm(*this, newname); }
      virtual ~RooHSSphHarmonicIm()=default;

    protected:
      Double_t evaluate() const final;
      Bool_t CheckClean() const;
      
    private:

      RooRealProxy _ctheta;
      RooRealProxy _phi;
      RooRealProxy _mag;
      mutable Double_t _lastCTheta=-1E10;
      mutable Double_t _lastPhi=-1E10;
      mutable Double_t _lastVal=0;
      Int_t _M=0;
 
      ClassDefOverride(HS::FIT::RooHSSphHarmonicIm,1);
    };
    ////////////////////////////////////////////////////////////////////////////////
    Double_t RooHSSphHarmonicIm::evaluate() const{
      if(!_M)return 0; //M=0 =>real
      if(CheckClean()) return _lastVal;
     
      Double_t angle=_M*_lastPhi; 
      return _mag*TMath::Sin(angle);
    }
   ////////////////////////////////////////////////////////////////////////////////
    
    inline Bool_t RooHSSphHarmonicIm::CheckClean() const
    {
      Double_t cth=_ctheta;
      Double_t ph=_phi;
      if(cth==_lastCTheta&&ph==_lastPhi ) return kTRUE;
      _lastCTheta=cth;
      _lastPhi=ph;
      return kFALSE;
 
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////
    class RooHSSphHarmonicRe : public RooAbsReal {
    public:
      RooHSSphHarmonicRe() =default;
      // a Imaginery part of Spherical Harmonic, Y_l^m(costTh,Phi)
      RooHSSphHarmonicRe(const char *name, const char *title, RooAbsReal& ctheta, RooAbsReal& phi, RooAbsReal& sphHar );

      RooHSSphHarmonicRe(const RooHSSphHarmonicRe& other, const char* name = 0);
      TObject* clone(const char* newname) const override { return new RooHSSphHarmonicRe(*this, newname); }
      virtual ~RooHSSphHarmonicRe() =default;

    protected:
      Double_t evaluate() const final;
      Bool_t CheckClean() const;
    private:

      RooRealProxy _ctheta;
      RooRealProxy _phi;
      RooRealProxy _mag;
      mutable Double_t _lastCTheta=-1E10;
      mutable Double_t _lastPhi=-1E10;
      mutable Double_t _lastVal=0;
      Int_t _M=0;
 
      ClassDefOverride(HS::FIT::RooHSSphHarmonicRe,1);
    };
    ////////////////////////////////////////////////////////////////////////////////
    Double_t RooHSSphHarmonicRe::evaluate() const{
      if(CheckClean()) return _lastVal;
      
      Double_t angle=_M*_lastPhi; 
      return _mag*TMath::Cos(angle);
    }
    ////////////////////////////////////////////////////////////////////////////////
    
    inline Bool_t RooHSSphHarmonicRe::CheckClean() const
    {
      Double_t cth=_ctheta;
      Double_t ph=_phi;
      if(cth==_lastCTheta&&ph==_lastPhi ) return kTRUE;
      _lastCTheta=cth;
      _lastPhi=ph;
      return kFALSE;
      
    }
    
  }
}
#endif
