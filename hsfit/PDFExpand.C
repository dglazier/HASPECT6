#include "Setup.h"
#include <TString.h>
#include <TMath.h>

namespace HS{
  namespace FIT{
    namespace EXPAND{
      TString LoadRealSphHarmonic(Setup &setup,TString cth,TString phi,Int_t L,Int_t M);
      TString ExpandRealSphHarmonic(Setup &setup,TString cth,TString phi,Int_t Lmax,Int_t Mmax);
      TString ComponentsRealSphHarmonic(Setup &setup,TString name,TString cth,TString phi,Int_t Lmax,Int_t Mmax);


      TString  ExpandPolSphHarmonic(Setup &setup,TString cth,TString phi,Int_t Lmax,Int_t Mmax,Int_t set,TString part,Bool_t isEven);
      TString LoadPolSphHarmonic(Setup &setup,TString cth,TString phi,Int_t L,Int_t M,Int_t set,TString part);
      TString  ComponentsPolSphHarmonic(Setup &setup,TString name,TString cth,TString phi,TString phiPol,TString Pol,Int_t Lmax,Int_t Mmax,Bool_t isEven);
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////
      TString  ComponentsRealSphHarmonic(Setup &setup,TString name,TString cth,TString phi,Int_t Lmax,Int_t Mmax){

	TString sphharm=ExpandRealSphHarmonic(setup,cth,phi,Lmax,Mmax);
	TString expr=Form("RooComponentsPDF::%s(1,{%s,%s},=%s)",name.Data(),cth.Data(),phi.Data(),sphharm.Data());
	cout<<"ComponentsRealSphHarmonic    : "<<endl<<"          "<<expr<<endl;
	return expr;
      }
      TString  ExpandRealSphHarmonic(Setup &setup,TString cth,TString phi,Int_t Lmax,Int_t Mmax){

	TString components;
	for(Int_t iL=1;iL<=Lmax;iL++)
	  for(Int_t iM=0;iM<=iL;iM++){
	    if(iM>Mmax) continue;
	    components+=HS::FIT::EXPAND::LoadRealSphHarmonic(setup,cth,phi,iL,iM);
	  }
	components.Remove(components.Sizeof()-2);
	return components;
      }
      TString LoadRealSphHarmonic(Setup &setup,TString cth,TString phi,Int_t L,Int_t M){
	setup.LoadFunctionVar(Form("RooHSSphHarmonic::Y_%d_%d(%s,%s,%d,%d)",L,M,cth.Data(),phi.Data(),L,M));
	setup.LoadFunctionVar(Form("RooHSSphHarmonicRe::Y_%d_%d_Re(%s,%s,Y_%d_%d)",L,M,cth.Data(),phi.Data(),L,M));
	setup.LoadParameter(Form("H0_%d_%d[-1,1]",L,M));
	return Form("H0_%d_%d;Y_%d_%d:",L,M,L,M);
      }
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////
      TString  ComponentsPolSphHarmonic(Setup &setup,TString name,TString cth,TString phi,TString phiPol,TString Pol,Int_t Lmax,Int_t Mmax,Bool_t isEven=kFALSE){
	//From eqn a15a,b  https://arxiv.org/pdf/1906.04841.pdf 
	setup.LoadFormula(Form("POL_COS2PHI=@%s[]*cos(2*(@%s[]))",Pol.Data(),phiPol.Data())); //2-ves =>+ve
	setup.LoadFormula(Form("POL_SIN2PHI=-@%s[]*sin(2*(@%s[]))",Pol.Data(),phiPol.Data()));
	//I0
	TString sphharm0=ExpandPolSphHarmonic(setup,cth,phi,Lmax,Mmax,0,"Re",isEven);
	//I1
	TString sphharm1=ExpandPolSphHarmonic(setup,cth,phi,Lmax,Mmax,1,"Re",isEven);
	//I1
	TString sphharm2=ExpandPolSphHarmonic(setup,cth,phi,Lmax,Mmax,2,"Im",isEven);

	TString expr=Form("RooComponentsPDF::%s(0,{%s,%s,%s,%s},=%s:%s:%s)",name.Data(),cth.Data(),phi.Data(),phiPol.Data(),Pol.Data(),sphharm0.Data(),sphharm1.Data(),sphharm2.Data());
	cout<<"ComponentsRealSphHarmonic    : "<<endl<<"          "<<expr<<endl;
	return expr;
      }
      TString  ExpandPolSphHarmonic(Setup &setup,TString cth,TString phi,Int_t Lmax,Int_t Mmax,Int_t set,TString part,Bool_t isEven){

	TString components;
	for(Int_t iL=0;iL<=Lmax;iL++){
	  if(isEven&&iL%2==1)
	    continue;
	  for(Int_t iM=0;iM<=iL;iM++){
	    if(iM>Mmax) continue;
	    if(set==2&&iM==0) continue; //H2 =0 for M=0
	    components+=HS::FIT::EXPAND::LoadPolSphHarmonic(setup,cth,phi,iL,iM,set,part);
	  }
	}
	components.Remove(components.Sizeof()-2);//the last :
	return components;
      }
      TString LoadPolSphHarmonic(Setup &setup,TString cth,TString phi,Int_t L,Int_t M,Int_t set,TString part){
	if(set==0){
	  
	  Int_t tau=2;
	  if(M==0) tau=1;
	  setup.LoadFunctionVar(Form("RooHSSphHarmonic::Y_%d_%d(%s,%s,%d,%d,%d)",L,M,cth.Data(),phi.Data(),L,M,tau));
	}
	
	setup.LoadFunctionVar(Form("RooHSSphHarmonic%s::Y_%d_%d_%s(%s,%s,Y_%d_%d)",part.Data(),L,M,part.Data(),cth.Data(),phi.Data(),L,M));
	
	//Fix H0(0,0)==1
	if(set==0&&L==0&&M==0)
	  setup.LoadParameter(Form("H%d_%d_%d[1]",set,L,M));
	else
	  setup.LoadParameter(Form("H%d_%d_%d[-1,1]",set,L,M));
	
	//Extra sqrt(2L+1)/4pi term for Spherical Harmonic->D-wigner normalisation to be consistent with paper
	setup.LoadParameter(Form("K_%d[%E]",L,TMath::Sqrt(2*L+1.)/TMath::Sqrt(4*TMath::Pi())));	
 
	if(set==0)
	  return Form("K_%d;H%d_%d_%d;Y_%d_%d_%s:",L,set,L,M,L,M,part.Data());
	else if(set==1)
	  return Form("K_%d;H%d_%d_%d;Y_%d_%d_%s;POL_COS2PHI:",L,set,L,M,L,M,part.Data());
	else if(set==2)
	  return Form("K_%d;H%d_%d_%d;Y_%d_%d_%s;POL_SIN2PHI:",L,set,L,M,L,M,part.Data());

	return TString();
      }
    
    }
  }
}
