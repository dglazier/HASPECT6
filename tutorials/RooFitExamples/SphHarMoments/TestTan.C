#include <TMath.h>
#include <TRandom.h>
#include <TBenchmark.h>
#include <iostream>

Double_t mySin(Double_t val) {
  return (1-val*val);
}

void TestTan(){

  Long64_t N=1E8;
  
  Double_t sum=0;
  Double_t temp=0;
  
  vector<Double_t> vals;  
  for(Long64_t i=0;i<N;i++){
    //vals.push_back(1);
    vals.push_back(gRandom->Uniform(0,1));
  }

  
  gBenchmark->Start("TMath::Tan");
  for(Long64_t i=0;i<N;i++){
    //Double_t temp=(vals[i]);
    temp=cos(vals[i]);
    sum*=temp;
    //sum+= sqrt(1-cos(vals[i])*cos(vals[i]) );
    //sum*= sqrt(1-temp*temp);
    sum*= sqrt(mySin(temp));
  }
  gBenchmark->Stop("TMath::Tan");
  gBenchmark->Print("TMath::Tan");
  std::cout<<"Sum "<<sum<<std::endl;
  sum=0;
  gBenchmark->Start("Sin");
  for(Long64_t i=0;i<N;i++){
   temp=(vals[i]);
    sum*=cos(temp);
    sum*=sin(temp);
  }
  gBenchmark->Stop("Sin");
  gBenchmark->Print("Sin");
  std::cout<<"Sum "<<sum<<std::endl;
}
