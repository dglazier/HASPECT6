#include <iostream>
#include <TBenchmark.h>
#include <TLorentzVector.h>
using namespace std;

class A{
public :
  A(Float_t fff){ff=fff;cout<<"make A"<<endl;}
  ~A(){cout<<"delete A "<<endl;};
  A(const A& aa){ff=aa.ff;cout<<"copy A"<<endl;}
 
  void SetF(Long64_t fff){ff=fff;}
  Float_t GetF(){return ff;}
  
  TLorentzVector *GetV(){return &fV;}
private:
  Float_t ff=10;
  TLorentzVector fV;
};

class B{
public:
  B(Float_t fff):fA(fff){cout<<"make B"<<endl;}
  ~B(){cout<<"delete B"<<endl;}
  A& GetA(){return fA;}
  A GetAVal(){return fA;}
  A* GetARaw(){return fAraw;}
  //  shared_ptr<A> GetShared(){return fAsh;}
  //unique_ptr<A> GetUnique(){return std::move(fAsh);}
private:
  A fA;
  A* fAraw=new A(0);
  // shared_ptr<A> fAsh={shared_ptr<A>(new A(1))};
  // unique_ptr<A> fAu={unique_ptr<A> (new A(2))};
};

void PassA(A& a){
  cout<<a.GetF()<<endl;
}
// void Test(){
//   gBenchmark->Start("ref");
//   B bb;
//   for(Long64_t i=0;i<1E5;i++){
//     cout<<i<<endl;
//     auto aa=bb.GetA();
//     aa.SetF(i);
//   }
//   gBenchmark->Stop("ref");
//   gBenchmark->Print("ref");

//   gBenchmark->Start("val");
 
//   for(Long64_t i=0;i<1E12;i++){
//     auto aa=bb.GetAVal();
//     aa.SetF(i);
//   }
//   gBenchmark->Stop("val");
//   gBenchmark->Print("val");
// }
