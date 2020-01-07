{



  //  vector<Double_t> A = {4,2,8,3};
  ///vector<Double_t> B = {1,5,2,9};
  vector<std::complex<Double_t>> A = {{4,1},{4,-2},{0,8},{3,3},{3,3}};
  vector<std::complex<Double_t>> B = {{1,3},{5,4},{-4,2},{9,-9},{9,-10}};
  

  //Double indice sum Sum(L,M) A_L*B_M
  //Double_t Sum1=0;
  std::complex<Double_t> Sum1=0;
  for (Int_t L=0; L<5; L++) {
    for (Int_t M=0; M<5; M++) {
      Sum1+=A[L]*B[M];
    }
  }

  cout<<"Sum1 "<<Sum1<<endl;
  //Should be same as product of 2 sums  Sum(L,M) A_L*B_M = (Sum(L)A_L)(Sum(L)B_L)
  //  Double_t Sum2a=0;
  std::complex<Double_t> Sum2a=0;
  for (Int_t L=0; L<5; L++) {
    Sum2a+=A[L];
  }
  //  Double_t Sum2b=0;
  std::complex<Double_t> Sum2b=0;
  for (Int_t L=0; L<5; L++) {
    Sum2b+=A[L];
  }
  cout<<"Sum2 "<<Sum2a*Sum2b<<endl; //it is

  //Sum(L,M) A_L*A_M*B_L*B_M  = Sum(L,M) A_L*B_L*A_M*B_M 

   //Double indice sum (Sum(L)A_L*B_L)^2
  // Double_t Sum3=0;
  std::complex<Double_t> Sum3=0;
  Int_t N3=0;
  for (Int_t L=0; L<5; L++) {
    Sum3+=A[L]*B[L]; N3++;
   }
  cout<<"Sum3 "<<Sum3*Sum3<<" "<<N3<<endl;
  
  //Double indice sum (Sum(L,M)A_L*B_L*A_M*B_M)
  std::complex<Double_t> Sum4=0;
    //Double_t Sum4=0;
  Int_t N4=0;
  for (Int_t L=0; L<6; L++) {
    for (Int_t M=0; M<6; M++) {
      Sum4+=A[L]*std::conj(A[M])*B[L]*std::conj(B[M]); N4++;
      // cout<<A[L]*std::conj(A[M])<<" "<<B[L]*std::conj(B[M])<<endl;;
    }
  }
  cout<<"Sum4 "<<Sum4<<" "<<N4<<endl;
  
  //Double indice sum (Sum(L,M)(A_L*B_L)^2 + Sum(L1,L2<L1) A_L1*B_L1*A_L2*B_L2, Needs //N+(N-1)*N/2
  //Double_t Sum5a=0;
  //Double_t Sum5b=0;
  std::complex<Double_t> Sum5a=0;
  std::complex<Double_t> Sum5b=0;
  Int_t N5=0;
  for (Int_t L=0; L<6; L++) {
    Sum5a+=A[L]*std::conj(A[L])*B[L]*std::conj(B[L]);N5++;
  
  }
  for (Int_t L1=1; L1<6; L1++) {
    for (Int_t L2=0; L2<L1; L2++) {
      std::complex<Double_t> prod1=A[L1]*std::conj(A[L2]);//(Re_H_L1*Re_H_L2 + Im_H_L1*Im_H_L2)*
      std::complex<Double_t> prod2=B[L1]*std::conj(B[L2]);//(Re_Y_L1*Re_Y_L2 + Im_Y_L1*Im_Y_L2)
       Sum5b+=prod1*prod2;N5++;
    
       Sum5b+=std::conj(prod1)*std::conj(prod2);
   
       cout<<L1<<" "<<L2<<endl;
       //  cout<<A[L1]*std::conj(A[L2])<<" "<<B[L1]*std::conj(B[L2])<<endl;
   }
  }
  std::complex<Double_t> two(2,0);
  cout<<"Sum5 "<<Sum5a+Sum5b<<" "<<Sum5a<<" "<<Sum5b<<" "<<N5<<endl;

 
  
}
