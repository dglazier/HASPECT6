#include <TSystem.h>
#include <TBenchmark.h>
#include <TRandom.h>
#include <TMath.h>
#include <Math/SpecFunc.h>
#include <iostream>
#include <complex>
// ***************************************************
long int factorial(int n)
{
  if(n > 1)
    return n * factorial(n - 1);
  else
    return 1;
}
// *********************************************************************************
double wignerD(int J, int M1, int M2, double theta){
  /*
   *  compute the Wigner D^j_{M1,M2}(theta)
   *  using the summation formula by Wigner
   */
  
  // USE THE PHYSICS CONVENTION!!!
  M1 = -M1; M2 = -M2;
  
  double wd = 0.0;
  double res = 0.0, half = 0.0;
  int lb = 0;  	// lower bound for s
  int ub = J+M2;	// upper bound for s
  if(M2-M1>0) lb = M2-M1;
  if(J-M1<J+M2) ub = J-M1;
  
  wd = factorial(J+M1)*factorial(J-M1)*factorial(J+M2)*factorial(J-M2);
  wd = sqrt(wd);
  //return wd;
  for(int s = lb ; s<=ub ; s++){
    half = pow(cos(theta/2), 2*J+M2-M1-2*s)*pow(sin(theta/2), M1-M2+2*s) ;
    res = res + half*pow(-1,s)/( factorial(J+M2-s)*factorial(s)*factorial(M1-M2+s)*factorial(J-M1-s) );
  }
  wd = wd*res;
  return wd;
}

std::complex <double> Ylm(int L, int M, double theta, double phi){
  std::complex <double> ui (0,1);
  double m = M;
  return sqrt( (2*L+1)/(4.0*M_PI) ) * wignerD(L, M, 0, theta) * exp(ui*phi*m);
}
vector<vector<Double_t>> fevalN;

Double_t evalN(Int_t _L,Int_t _M) {
  return sqrt( double(2*_L+1)/(4*TMath::Pi())*TMath::Factorial(_L-(_M))/TMath::Factorial(_L+(_M)) );
}

Double_t evalRealSphHarmonic(Double_t _Z,Double_t _Phi,Int_t _L,Int_t _M) {
  Double_t val=1;
  if(_M%2==1)val*=-1;
  return val*=fevalN[_L-1][_M-1]*ROOT::Math::assoc_legendre(_L,(_M),_Z)*cos(_M*_Phi);//I think evalN is done in assoc_legendre
}
Double_t evalImSphHarmonic(Double_t _Z,Double_t _Phi,Int_t _L,Int_t _M) {
  Double_t val=1;
  if(_M%2==1)val*=-1;
  return val*=fevalN[_L-1][_M-1]*ROOT::Math::assoc_legendre(_L,(_M),_Z)*sin(_M*_Phi);//I think evalN is done in assoc_legendre
}
std::complex<double>  evalSphHarmonic(Double_t _Z,Double_t _Phi,Int_t _L,Int_t _M) {
  Double_t val=fevalN[_L-1][_M-1]*ROOT::Math::assoc_legendre(_L,(_M),_Z);
  if(_M%2==1)val*=-1;
  std::complex <double> ui (val*cos(_M*_Phi),val*sin(_M*_Phi));
  return ui;
}

double ATwignerDSmall( double aj, double am, double an, double beta ){
  
	// Calculates the beta-term
	//                         d j mn (beta)
	// in the matrix element of the finite rotation operator
	// (Wigner's D-function), according to formula 4.3.1(3) in
	// D.A. Varshalovich, A.N. Moskalev, and V.K. Khersonskii,
	// Quantum Theory of Angular Momentum, World Scientific,
	// Singapore 1988.
	// CERNLIB DDJMNB function translated from Fortran to C++ by Rene Brun
  
	double f = 8.72664625997164788e-3;    
  
  double fcl[51] = { 0 , 0 ,
		6.93147180559945309e-1 ,1.79175946922805500e00,
		3.17805383034794562e00 ,4.78749174278204599e00,
		6.57925121201010100e00 ,8.52516136106541430e00,
		1.06046029027452502e01 ,1.28018274800814696e01,
		1.51044125730755153e01 ,1.75023078458738858e01,
		1.99872144956618861e01 ,2.25521638531234229e01,
		2.51912211827386815e01 ,2.78992713838408916e01,
		3.06718601060806728e01 ,3.35050734501368889e01,
		3.63954452080330536e01 ,3.93398841871994940e01,
		4.23356164607534850e01 ,4.53801388984769080e01,
		4.84711813518352239e01 ,5.16066755677643736e01,
		5.47847293981123192e01 ,5.80036052229805199e01,
		6.12617017610020020e01 ,6.45575386270063311e01,
		6.78897431371815350e01 ,7.12570389671680090e01,
		7.46582363488301644e01 ,7.80922235533153106e01,
		8.15579594561150372e01 ,8.50544670175815174e01,
		8.85808275421976788e01 ,9.21361756036870925e01,
		9.57196945421432025e01 ,9.93306124547874269e01,
		1.02968198614513813e02 ,1.06631760260643459e02,
		1.10320639714757395e02 ,1.14034211781461703e02,
		1.17771881399745072e02 ,1.21533081515438634e02,
		1.25317271149356895e02 ,1.29123933639127215e02,
		1.32952575035616310e02 ,1.36802722637326368e02,
		1.40673923648234259e02 ,1.44565743946344886e02,
		1.48477766951773032e02};
	
	int jpm = int(aj+am);
	int jpn = int(aj+an);
	int jmm = int(aj-am);	
	
	int jmn = int(aj-an);
	int mpn = int(am+an);
	
	double r = 0;
	if (beta == 0) 
	{
		if (jpm == jpn) r = 1;
  } 
	else if (beta == 180) 
	{
		if (jpm == jmn) 
		{
			r = 1;
			if ( (jpm > 0 ? jpm : -jpm ) % 2 == 1 ) r = -1;
		}
  } 
	else if (beta == 360)
	{
		if (jpm == jpn)
		{
			r = 1;
      if ( (jpm > 0 ? jpm : -jpm ) % 2 == 1 ) r = -1;
		}
  } 
	else
	{
		double b  = f*beta;
		double s  = log(sin(b));
		double c  = log(fabs(cos(b)));
		double rt = 0.5*(fcl[jpm]+fcl[jmm]+fcl[jpn]+fcl[jmn]);
		int k0    = ( 0 > mpn ? 0 : mpn ); //max( 0 , mpn )
		int kq    = k0+jpm;
		if (beta > 180) kq += mpn;
		double q  = 1;
		if (kq%2 == 1) q = -1;
		kq = k0+k0;
		double cx = kq-mpn;
		double sx = jpm+jpn-kq;
		for( int k = k0 ; k <= ( jpm < jpn ? jpm : jpn ); k++ ) 
		{
			r  += q*exp(rt-fcl[k]-fcl[jpm-k]-fcl[jpn-k]-fcl[k-mpn]+ cx*c+sx*s);
			cx += 2;
			sx -= 2;
			q   = -q;
		}
	}
  
	return r;
}


complex< double > ATwignerD( int l, int m, int n, 
                           double cosTheta, double phi ){

  double dtheta = acos( cosTheta ) * 180.0 / TMath::Pi();
	
    double dpart = ATwignerDSmall( l, m, n, dtheta );

    return complex< double >( cos( -1.0 * m * phi ) * dpart, 
							sin( -1.0 * m * phi ) * dpart );
	
}

complex< double > ATwignerD_1( int l, int m, int n, 
                           double theta, double phi ){

    double dtheta = theta;
	
    double dpart = ATwignerDSmall( l, m, n, dtheta );

    return complex< double >( cos( -1.0 * m * phi ) * dpart, 
							sin( -1.0 * m * phi ) * dpart );
	
}

std::complex< double > ATwignerD( int l, int m, int n, 
			    double cosTheta, double phi1, double phi2 ){
	
  double dtheta = acos( cosTheta ) * 180.0 / TMath::Pi();
	
    double dpart = ATwignerDSmall( l, m, n, dtheta );

    return complex< double >( cos( -1.0*m*phi1 + -1.0*n*phi2 ) * dpart, 
			                                 sin( -1.0*m*phi1 + -1.0*n*phi2 ) * dpart );
	
}

std::complex< double > ATY( int l, int m, double cosTheta, double phi ){
  
  return ( (double)sqrt( (2*l+1) / (4*TMath::Pi()) ) ) * 
          conj( ATwignerD( l, m, 0, cosTheta, phi ) );
}
void TestFunctionSpeed(){

  Int_t L=2;
  Int_t M=1;
  fevalN.resize(L);
  fevalN[L-1].resize(M);
  
  fevalN[L-1][M-1]=evalN(L,M);
  
  std::cout<<Ylm(L,M,acos(0.5),0.5)<<" "<<Ylm(L,M,acos(0.8),0.5)<<" "<<Ylm(L,M,acos(-0.6),0.5)<<std::endl;;
  std::cout<<ATY(L,M,0.5,0.5)<<" "<<ATY(L,M,0.8,0.5)<<" "<<ATY(L,M,-0.6,0.5)<<std::endl;;
  std::cout<<evalRealSphHarmonic(0.5,0.5,L,M)<<" "<<evalRealSphHarmonic(0.8,0.5,L,M)<<" "<<evalRealSphHarmonic(-0.6,0.5,L,M)<<std::endl;
  std::cout<<evalSphHarmonic(0.5,0.5,L,M)<<" "<<evalSphHarmonic(0.8,0.5,L,M)<<" "<<evalSphHarmonic(-0.6,0.5,L,M)<<std::endl;

  const Long64_t NEvents=1E7;
  vector<Double_t> Theta(NEvents);
  vector<Double_t> CosTheta(NEvents);
  vector<Double_t> Phi(NEvents);
  Double_t th=0;
  for(Int_t i=0;i<NEvents;i++){
    th=gRandom->Uniform(0,TMath::Pi());
    Theta[i]=th;
    CosTheta[i]=(cos(th));
    Phi[i]=(gRandom->Uniform(-TMath::Pi(),TMath::Pi()));
  }
  gBenchmark->Start("Vincent");
  Double_t sum=0;
  for(Int_t i=0;i<NEvents;i++){
    sum+=Ylm(L,M,Theta[i],Phi[i]).real();
  }
 
  gBenchmark->Stop("Vincent");
  gBenchmark->Print("Vincent");
  cout<<sum<<endl; 

  gBenchmark->Start("Roo");
  sum=0;
  for(Int_t i=0;i<NEvents;i++){
    // cout<<Theta[i]<<" "<<CosTheta[i]<<" "<<evalRealSphHarmonic(CosTheta[i],Phi[i],L,M)<<endl;
    sum+=evalRealSphHarmonic(CosTheta[i],Phi[i],L,M);
  }
 
  gBenchmark->Stop("Roo");
  gBenchmark->Print("Roo");
  cout<<sum<<endl; 

  gBenchmark->Start("RooComplex");
  sum=0;
  for(Int_t i=0;i<NEvents;i++){
    // cout<<Theta[i]<<" "<<CosTheta[i]<<" "<<evalRealSphHarmonic(CosTheta[i],Phi[i],L,M)<<endl;
    sum+=evalSphHarmonic(CosTheta[i],Phi[i],L,M).real();
  }
 
  gBenchmark->Stop("RooComplex");
  gBenchmark->Print("RooComplex");
  cout<<sum<<endl; 

  gBenchmark->Start("AT");
  sum=0;
  for(Int_t i=0;i<NEvents;i++){
    // cout<<Theta[i]<<" "<<CosTheta[i]<<" "<<evalRealSphHarmonic(CosTheta[i],Phi[i],L,M)<<endl;
    sum+=ATY(L,M,CosTheta[i],Phi[i]).real();
  }
 
  gBenchmark->Stop("AT");
  gBenchmark->Print("AT");
  cout<<sum<<endl; 

}


  
