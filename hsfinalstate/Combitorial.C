/**
	\class Combitorial
	
	Class to handle general iterations these can be :
	Permuations (==std::next_permuation)
	Rotations (==std::rotate)
	Selections (Combinations) (= Lexographic algorithm define here)
	
*/

#include "Combitorial.h"

using namespace HS;

void Combitorial::MakeCombinations(Int_t n,Int_t p,Int_t nidentical){

  //This is an important bit the formula for the number of combinations
  //= n!/(p!)/(n-p)!/N where N is the number of identical selections to be made
  
  Int_t nCombi=TMath::Factorial(n)/TMath::Factorial(p)/TMath::Factorial(n-p)/nidentical;
  
  fCombinations.resize(nCombi);
  fElems.resize(n);
  
  vector<int> combi_vals(p);
  
  for(Int_t i=0;i<n;i++)
    fElems[i]=i;
 

  for(Int_t ii=1;ii<=nCombi;ii++) {//lexographic needs to start at 1
    combi_vals.clear();
    
    //get indices for combination of p elements
    vector<int> combi=Single_Combination(fElems,n,p,ii);
    //for (int iv = 0; iv < combi.size(); ++iv) {combi_vals.push_back(elems[combi[iv]-1]);}
    fCombinations[ii-1].resize(p);
    //Add this combination to fCombinations
    for (int iv = 0; iv < p; ++iv)
      fCombinations[ii-1][iv]=fElems[combi[iv]-1];
  }
}

void Combitorial::PrintCombinations(){
  cout <<"Combitorial::PrintCombinations()"<<endl;
  for(UInt_t i=0;i<fCombinations.size();++i){
    for(UInt_t j=0;j<fCombinations[i].size();++j)
      cout<<fCombinations[i][j]<<" ";
    cout<<endl;
  }

}
//////////////////////////////////////////////////////////////
/// [combination c n p x]
/// get the [x]th lexicographically ordered set of [p] elements in [n]
/// output is in [c], and should be sizeof(int)*[p] */
/// "Algorithm 515: Generation of a Vector from the Lexicographical Index"; Buckles, B. P., and Lybanon, M. ACM Transactions on Mathematical Software, Vol. 3, No. 2, June 1977.
vector<Int_t> Combitorial::Single_Combination(vector<Int_t> c,Int_t n,Int_t p, Int_t x){
   Int_t i,k = 0;
    Int_t r = 0;
    for(i=0;i<p-1;i++){
        c[i] = (i != 0) ? c[i-1] : 0;
        do {
            c[i]++;
	    if(n<c[i])break;
	    r = TMath::Binomial(n-c[i],p-(i+1));
            k = k + r;
        } while(k < x);
        k = k - r;
    }
    if(p>1)
      c[p-1] = c[p-2] + x - k;
    else //picking 1, selection=index
      c[p-1] = x;
    
    vector<Int_t> result(c.begin(),c.begin()+p);
    return result;
}


////////////////////////////////////////////////////////
void Combitorial::PrintVectorInt(vector<Int_t> vec){
  cout<<"Printing vector<Int_t> "<<endl;
  for(UInt_t i=0;i<vec.size();i++)
    cout<<vec[i]<<" ";
  cout<<endl;
  
}

