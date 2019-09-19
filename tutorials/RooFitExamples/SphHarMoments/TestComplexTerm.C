{

  std::complex<float> A1(1.5,0);
  std::complex<float> A2(-0.5,0);
  std::complex<float> B1(3,0);
  std::complex<float> B2(1,0);
  std::complex<float> D1(0.3,0);
  std::complex<float> D2(-0.1,0);
  // std::complex<float> A1(1.5,-1);
  // std::complex<float> A2(-0.5,-0.599);
  // std::complex<float> B1(3,4);
  // std::complex<float> B2(1,2);
  // std::complex<float> D1(0.3,0.4);
  // std::complex<float> D2(-0.1,0.2);


  //Sum{AB}^2 = (A1*B1 + A2*B2)*CONJ(A1*B1 + A2*B2)
  auto T1=(A1*B1 + A2*B2);
  auto T2=std::conj(A1*B1 + A2*B2);
  cout<<(T1*T2).real()<<endl;

  ///Sum{ABD}^2 = (A1*CONJ(A1)*B1*CONJ(B1) + A1*CONJ(A1)*B1*CONJ(B1))
  auto A2T1= A1*std::conj(A1)*B1*std::conj(B1);
  A2T1+= A2*std::conj(A2)*B2*std::conj(B2);
  A2T1+= A1*std::conj(A2)*B1*std::conj(B2);
  A2T1+= A2*std::conj(A1)*B2*std::conj(B1);
  
  cout<<A2T1<<endl;

  //Sum{AB}^2 =Sum{F(Ai,Ai)F(Bi,Bi)} + 2*Sum(j<i){F(Ai,Aj)F(Bi,Bj)-G(Ai,Aj)G(Bi,Bj)}
  //F(C1,C2)=(ReC1*ReC2 + ImC1*ImC2) and G(C1,C2)=(ImC1*ReC2 - ReC1*ImC2)
  auto M1=(A1.real()*A1.real() + A1.imag()*A1.imag())*( B1.real()*B1.real() + B1.imag()*B1.imag());
  M1+= (A2.real()*A2.real() + A2.imag()*A2.imag())*( B2.real()*B2.real() + B2.imag()*B2.imag());

  auto M2 =(A1.real()*A2.real() + A1.imag()*A2.imag())*(B1.real()*B2.real() + B1.imag()*B2.imag());
  M2-=(A1.imag()*A2.real()-A1.real()*A2.imag())*(B1.imag()*B2.real()-B1.real()*B2.imag());
  
  cout<<M1+2*M2<<" "<<M1<<" "<<M2<<" "<<(A1.imag()*A2.real()-A1.real()*A2.imag())*(B1.imag()*B2.real()-B1.real()*B2.imag())<<endl;

  //Sum{ABD}^2 = (A1*B1*D1 + A2*B2*D2)*CONJ(A1*B1*D1 + A2*B2*D2)
  auto TD1=(A1*B1*D1 + A2*B2*D2);
  auto TD2=std::conj(A1*B1*D1 + A2*B2*D2);
  cout<<(TD1*TD2).real()<<endl;
  
  ///Sum{ABD}^2 = (A1*CONJ(A1)*B1*CONJ(B1)*D1*CONJ(D1) + A1*CONJ(A1)*B1*CONJ(B1)*D1*CONJ(D1))
  auto AT1= A1*std::conj(A1)*B1*std::conj(B1)*D1*std::conj(D1);
  AT1+= A2*std::conj(A2)*B2*std::conj(B2)*D2*std::conj(D2);
  AT1+= A1*std::conj(A2)*B1*std::conj(B2)*D1*std::conj(D2);
  AT1+= A1*std::conj(A2)*B1*std::conj(B2)*D1*std::conj(D2);
  // AT1+= A2*std::conj(A1)*B2*std::conj(B1)*D2*std::conj(D1);
  cout<<AT1<<endl;

  //Sum{ABD}^2 =Sum{F(Ai,Ai)F(Bi,Bi)F(D)} + 2*Sum(j<i){F(Ai,Aj)F(Bi,Bj)F(Di,Dj)-G(Ai,Aj)G(Bi,Bj)G(Di,Dj)}
  //F(C1,C2)=(ReC1*ReC2 + ImC1*ImC2) and G(C1,C2)=(ImC1*ReC2 - ReC1*ImC2)
  auto MD1=(A1.real()*A1.real() + A1.imag()*A1.imag())*( B1.real()*B1.real() + B1.imag()*B1.imag())*( D1.real()*D1.real() + D1.imag()*D1.imag());
  MD1+= (A2.real()*A2.real() + A2.imag()*A2.imag())*( B2.real()*B2.real() + B2.imag()*B2.imag())*( D2.real()*D2.real() + D2.imag()*D2.imag());

  auto MD2 =(A1.real()*A2.real() + A1.imag()*A2.imag())*(B1.real()*B2.real() + B1.imag()*B2.imag())*(D1.real()*D2.real() + D1.imag()*D2.imag());
  MD2-=(A1.imag()*A2.real()-A1.real()*A2.imag())*(B1.imag()*B2.real()-B1.real()*B2.imag())*(D1.imag()*D2.real()-D1.real()*D2.imag());
  cout<<MD1+2*MD2<<" "<<MD1<<" "<<MD2<<endl;


  auto A11=A1*std::conj(A1);
  auto A22=A2*std::conj(A2);
  auto B11=B1*std::conj(B1);
  auto B22=B2*std::conj(B2);
  auto D11=D1*std::conj(D1);
  auto D22=D2*std::conj(D2);
  auto A12=A1*std::conj(A2);
  auto A21=A2*std::conj(A1);
  auto B12=B1*std::conj(B2);
  auto B21=B2*std::conj(B1);
  auto D12=D1*std::conj(D2);
  auto D21=D2*std::conj(D1);
  auto EP1= A11*B11*D11+A22*B22*D22;
  auto EP2 = A12*B12*D12 +A21*B21*D21;
  
  cout<<EP1+EP2<<endl;
  
}
