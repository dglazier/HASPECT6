#include <TBenchmark.h>
#include <TFormula.h>
#include <iostream>

void Speed(){
  TFormula FF("FF","sqrt([0]*2*x)",true,true);
  FF.SetParameter(0,1e-4);

  Long64_t NN=1E9;
  Double_t val=0;
  Double_t sum=0;
  gBenchmark->Start("formula");
  for(Long64_t n=0;n<NN;n++){
    // val=(FF.Eval(n));
    val=(FF.Eval(n))*2;
    sum+=val;
  }
  std::cout<<sum<<std::endl;

  gBenchmark->Stop("formula");
  gBenchmark->Print("formula");

  gBenchmark->Start("standard");
  val=0;
  sum=0;
  // for(Long64_t n=0;n<NN;n++){
  Long64_t n=0;
  while(n++!=NN){
    val=(sqrt(1E-4*2*n));
    val=(sqrt(1E-4*2*n))*2;
    sum+=val;
  }

  std::cout<<sum<<std::endl;
  gBenchmark->Stop("standard");
  gBenchmark->Print("standard");

}
