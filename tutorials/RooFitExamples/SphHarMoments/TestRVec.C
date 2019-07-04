#include <TMath.h>
#include <Math/SpecFunc.h>
#include <TRandom.h>
#include <TROOT.h>
#include <TBenchmark.h>
#include <ROOT/RVec.hxx>

using namespace ROOT::VecOps;

vector<Double_t> fMoms;
RVec<Double_t> rfMoms;
RVec<Int_t> rM;
RVec<Int_t> rL;

Int_t Lmax=5;
Int_t Mmax=2;

inline Double_t evalN(Int_t _L,Int_t _M) {
  Double_t n = sqrt( double(2*_L+1)/(4*TMath::Pi())*TMath::Factorial(_L-(_M))/TMath::Factorial(_L+(_M)) );
  return n;
}
inline RVec<Double_t> revalN() {
  const Int_t size=rL.size();

  RVec<Double_t> n(size);
  for(Int_t i=0;i<size;i++)
    n[i]= sqrt( double(2*rL[i]+1)/(4*TMath::Pi())*TMath::Factorial(rL[i]-(rM[i]))/TMath::Factorial(rL[i]+rM[i]) );
  return n;
}


inline Double_t evalLegendre(Double_t _Z,Int_t _L,Int_t _M){
 
  //#ifdef R__HAS_MATHMORE
  //  Double_t r = 1;
  //Double_t ctheta = std::max(-1., std::min((double)_Z, +1.));
  return ROOT::Math::assoc_legendre(_L,(_M),_Z);

}
inline RVec<Double_t> revalLegendre(Double_t _Z){
 
  //#ifdef R__HAS_MATHMORE
  //  Double_t r = 1;
  //Double_t ctheta = std::max(-1., std::min((double)_Z, +1.));
 const  Int_t size=rL.size();
  RVec<Double_t> vals(size);
  for(Int_t i=0;i<size;i++)
    vals[i]= ROOT::Math::assoc_legendre(rL[i],rM[i],_Z);
  return vals;
}
inline Double_t evalRealSphHarmonic(Double_t _Z,Double_t _Phi,Int_t _L,Int_t _M) {
  // Double_t val =evalLegendre(_Z,_L,_M);//I think evalN is done in assoc_legendre
  Double_t val =evalN(_L,_M)*evalLegendre(_Z,_L,_M);//I think evalN is done in assoc_legendre
  //  Double_t val= cos(_Phi);
  if(_M!=0) val *= cos(_M*_Phi) ;
  
  return val;
}
inline RVec<Double_t> revalRealSphHarmonic(Double_t _Z,Double_t _Phi) {
  // Double_t val =evalLegendre(_Z,_L,_M);//I think evalN is done in assoc_legendre
  auto val =revalN()*revalLegendre(_Z);//I think evalN is done in assoc_legendre
  //  Double_t val= cos(_Phi);
  //if(rM!=0) val *= cos(rM*_Phi) ;
  
  return val;
}


  
Double_t Eval(Double_t Z,Double_t Phi){
  
  
  Double_t val=0;
  Int_t iY=0;
  for(Int_t iL=0;iL<=Lmax;iL++)
    for(Int_t iM=0;iM<=iL;iM++){
      if(iM>Mmax) continue;
      //Double_t YLM=fMoms[iY++];
      //  cout<<"L M "<<iL<<" "<<iM<<" "<<YLM<<" "<<evalRealSphHarmonic(Z,Phi,iL,iM)<<endl;
      val+= fMoms[iY++]*evalRealSphHarmonic(Z,Phi,iL,iM);
      //val+=YLM;
    }
  
  return val;
  
}
Double_t rEval(Double_t Z,Double_t Phi){
  
  
      auto val= rfMoms*revalRealSphHarmonic(Z,Phi);
   
      return Sum(val);
  
}

void TestRVec(){

  vector<Int_t> vL;
  vector<Int_t> vM;
  for(Int_t iL=0;iL<=Lmax;iL++)
    for(Int_t iM=0;iM<=iL;iM++){
      fMoms.push_back(1);
      vM.push_back(iM);
      vL.push_back(iL);
    }
  rfMoms= RVec<Double_t> (fMoms.data(), fMoms.size());
  rL=RVec<Int_t>(vL.data(),vL.size());
  rM=RVec<Int_t>(vM.data(),vM.size());
		 
  cout<<"MADE RVEC"<<endl;
  vector<Double_t> Z;
  vector<Double_t> Phi;
  
  for(Int_t i=0;i<1E7;i++){
    Z.push_back(gRandom->Uniform(-1,1));
    Phi.push_back(gRandom->Uniform(-3,3));
  }
  gBenchmark->Start("Standard");
  //  #pragma novector
  #pragma ivdep
  for(Int_t i=0;i<1E7;i++){
    Eval(Z[i],Phi[i]);
    //Z[i]+=1;
    //  Phi[i]-=1;
  }
  gBenchmark->Stop("Standard");
  gBenchmark->Print("Standard");

  
  RVec<Double_t> rZ(Z.data(), Z.size());
  RVec<Double_t> rPhi(Phi.data(), Phi.size());
  ROOT::EnableImplicitMT();
   gBenchmark->Start("RVec");
  for(Int_t i=0;i<1E7;++i){
    Eval(rZ[i],rPhi[i]);
    // rZ[i]+=1;
    // rPhi[i]-=1;
  }
  gBenchmark->Stop("RVec");
  gBenchmark->Print("RVec");

  gBenchmark->Start("RVecNoLoop");
   for(Int_t i=0;i<1E7;++i){
    rEval(rZ[i],rPhi[i]);
    // rZ[i]+=1;
    // rPhi[i]-=1;
  }

  gBenchmark->Stop("RVecNoLoop");
  gBenchmark->Print("RVecNoLoop");

}

