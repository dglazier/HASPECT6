#ifndef HS_COMBITORIAL_h
#define HS_COMBITORIAL_h
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <TMath.h>

namespace HS{

  class Combitorial{
    
  public :
    Combitorial(){};
    virtual ~ Combitorial(){};
    
  private:
    
    vector<vector<int>> fCombinations; //a list of combinations
    vector<vector<vector<int > > > fAllCombinations; //a list of all combinations
    std::vector<Int_t > fElems; //used to find selected combination
    
    
  protected:
    UInt_t fType=0;
    UInt_t fNiter=0; //counter for iterations
    Int_t fSize=-1;  //size of the particle vector
    Bool_t fIsFinished=kFALSE;
  public:
    
    Int_t GetType(){return fType;}
    Int_t Niter(){return fNiter;}
    void ResetNiter(){fNiter=0;fIsFinished=kFALSE;}
    
    Bool_t IsFinished(){if(!fIsFinished) return kFALSE;else {fNiter=0;fIsFinished=kFALSE;return kTRUE;}} //flag when finished iterating and reset when termination reached
    Bool_t WhatIsFinished(){return fIsFinished;}
    
    //Utility functions
    std::vector<int> VectorIntDiff( const std::vector<int>& full, const std::vector<int>& part );
    
    template<class T> std::vector<T*> SubSet(std::vector<T*> *vec,Int_t entries,Int_t starti=0);
    
    template<class T> std::vector<T*> SubSet(std::vector<T*> *vec,vector<int> items);
    void PrintVectorInt(vector<Int_t> vec);
    
    //Combination algorithm functions
    vector<Int_t> Single_Combination(vector<Int_t> c,Int_t n,Int_t p, Int_t x);
    void MakeCombinations(Int_t n,Int_t p,Int_t nidentical);
    void PrintCombinations();
    void ResetCombi(){ fCombinations.clear();}
    
    //Combitorial behaviour functions
    template<class T> std::vector<T*> Next(std::vector<T*> *vec,Int_t a=0,Int_t b=1);
    
    template<class T> std::vector<T*> Permutation(std::vector<T*> *vec);
    
    template<class T> std::vector<T*> Rotation(std::vector<T*> *vec);
    
    template<class T> std::vector<T*> Selection(std::vector<T*> *vec,Int_t p,Int_t nidentical=1);
    
    template<class T> std::vector<T*> Remainder(std::vector<T*> *vec);
    
    
    //Combitorial behaviour functions for objects
    template<class T> std::vector<T> Next(std::vector<T> *vec,Int_t a=0,Int_t b=1);
    
    template<class T> std::vector<T> Permutation(std::vector<T> *vec);
    
    template<class T> std::vector<T> Rotation(std::vector<T> *vec);
    
    template<class T> std::vector<T> Selection(std::vector<T> *vec,Int_t p,Int_t nidentical=1);
    
    template<class T> std::vector<T> Remainder(std::vector<T> *vec);
    
    template<class T> std::vector<T> SubSet(std::vector<T> *vec,Int_t entries,Int_t starti=0);
    
    template<class T> std::vector<T> SubSet(std::vector<T> *vec,vector<int> items);
    
  };
  
  
  class THSPermutation : public Combitorial{
    
  public :
    THSPermutation(){fType=1;};
    virtual ~THSPermutation(){};
    
  private:
    
  public:
    
  };
  class THSRotation : public Combitorial{

  public :
    THSRotation(){fType=3;};
    virtual ~THSRotation(){};
    
  private:
    
  public:
    
  };
  class THSSelection : public Combitorial{
    
  public :
    THSSelection(){fType=2;};
    virtual ~THSSelection(){};
    
  private:
    
  public:
    
  };
  //Note functions with Templated classes must be defined in the .h file
  //Who knew?
  
  /////////////////////////////////////////////////
  ///Function to control behviour depending on which type of iteration
  ///Is desired. To get the different behviour users must create and object
  ///of the appropriate type: THSPermuation;THSRotation;THSSelection
  template<class T> std::vector<T*> Combitorial::Next(std::vector<T*> *vec,Int_t a,Int_t b){
    if(fType==2)   return Selection(vec,a,b);
    else if(fType==1)   return Permutation(vec);
    else if(fType==3)   return Rotation(vec);
    else fIsFinished=kTRUE;
    return *vec;
  }
  template<class T> std::vector<T> Combitorial::Next(std::vector<T> *vec,Int_t a,Int_t b){
    if(fType==2)   return Selection(vec,a,b);
    else if(fType==1)   return Permutation(vec);
    else if(fType==3)   return Rotation(vec);
    else fIsFinished=kTRUE;
    return *vec;
  }
  
  /////////////////////////////////////////////////
  ///Function to permutate a vector containing any type of objects
  ///Returns a copy of the permuated vector
  ///but the supplied vector vec is itself permutated
  template<class T> std::vector<T*> Combitorial::Permutation(std::vector<T*> *vec){
    //if(fNiter==0){fNiter++; cout<<"Permutation "<<fIsFinished<<endl;return *vec;}
    std::next_permutation(vec->begin(),vec->end());
    fNiter++;
    if(((UInt_t)fNiter)==TMath::Factorial(vec->size()))
      fIsFinished=kTRUE;
    
    return *vec;
  }
  template<class T> std::vector<T> Combitorial::Permutation(std::vector<T> *vec){
    //if(fNiter==0){fNiter++; cout<<"Permutation "<<fIsFinished<<endl;return *vec;}
    std::next_permutation(vec->begin(),vec->end());
    fNiter++;
    if(((UInt_t)fNiter)==TMath::Factorial(vec->size()))
      fIsFinished=kTRUE;
    
    return *vec;
  }
  
  /////////////////////////////////////////////////
  ///Function to rotate a vector containing any type of objects
  ///Returns a copy of the rotated vector
  ///but the supplied vector vec is itself rotated
  template<class T> std::vector<T*> Combitorial::Rotation(std::vector<T*> *vec){
    std::rotate(vec->begin(),vec->begin()+1,vec->end());
    fNiter++;
    if(((UInt_t)fNiter)==(vec->size()))
      fIsFinished=kTRUE;
    return *vec;
  }
  
  template<class T> std::vector<T> Combitorial::Rotation(std::vector<T> *vec){
    std::rotate(vec->begin(),vec->begin()+1,vec->end());
    fNiter++;
    if(((UInt_t)fNiter)==(vec->size()))
      fIsFinished=kTRUE;
    return *vec;
  }
  
  /////////////////////////////////////////////////
  ///Function to select a subset of a vector containing any type of objects
  //This is equivalent to a combination p from N where N is the size of vec
  ///Returns a copy of the selected vector
  ///The supplied vector vec is not altered
  /* template<class T> std::vector<T*> Combitorial::Selection(std::vector<T*> *vec,Int_t p,Int_t nidentical){ */
  /*     //return next combination of p from n */
  /*   //if(fCombinations.size()==0){ */
  /*   if(((Int_t)vec->size())!=fSize){ //need to remake combination map */
  /*     cout<<"REMAKE COMBINATIONS "<<fSize<<" "<<vec->size()<<endl; */
  /*     fCombinations.clear(); */
  /*     MakeCombinations(vec->size(),p,nidentical); */
  /*   } */
  /*   fSize=vec->size(); */
  /*   std::vector<T*> newVec=SubSet(vec,fCombinations[fNiter++]); */
  /*   if(fNiter==fCombinations.size()) fIsFinished=kTRUE; */
  /*   // cout<<"Selection "<<fIsFinished<<endl; */
  /*   return newVec; */
  /* } */
  template<class T> std::vector<T*> Combitorial::Selection(std::vector<T*> *vec,Int_t p,Int_t nidentical){
    //return next combination of p from n

    if(fAllCombinations.size()<vec->size()) //need to make combination map
      fAllCombinations.resize(vec->size());

    if(fAllCombinations[vec->size()-1].size()==0){ //need to make combination map
      //store in fAllCombinations in case it comes up again
      fCombinations.clear();
      MakeCombinations(vec->size(),p,nidentical);
      fAllCombinations[vec->size()-1]=fCombinations;
    }
    vector<vector<int>> *Combip=&(fAllCombinations[vec->size()-1]);
    
    
    //  fSize=vec->size();
    std::vector<T*> newVec=SubSet(vec,Combip->at(fNiter++));
    //std::vector<T*> newVec=SubSet(vec,p,0);
    if(fNiter==Combip->size()) fIsFinished=kTRUE;
    return newVec;
  }
  
  template<class T> std::vector<T> Combitorial::Selection(std::vector<T> *vec,Int_t p,Int_t nidentical){
    //return next combination of p from n
    if(fAllCombinations.size()<vec->size()) //need to make combination map
      fAllCombinations.resize(vec->size());
    if(fAllCombinations[vec->size()-1].size()==0){ //need to make combination map
      //store in fAllCombinations in case it comes up again
      fCombinations.clear();
      MakeCombinations(vec->size(),p,nidentical);
      fAllCombinations[vec->size()-1]=fCombinations;
    }
    vector<vector<int>> *Combip=&(fAllCombinations[vec->size()-1]);
    
    
    //  fSize=vec->size();
    std::vector<T> newVec=SubSet(vec,Combip->at(fNiter++));
    if(fNiter==Combip->size()) fIsFinished=kTRUE;
    return newVec;
  }
  
  /////////////////////////////////////////////////
  ///Function to return the unselected elements from Selection
  ///Returns a copy of the selected vector
  ///The supplied vector vec is not altered
  template<class T> std::vector<T*> Combitorial::Remainder(std::vector<T*> *vec){
    //Must be called after Selection
    if(fType!=2) return SubSet(vec,0); //a vector with 0 entries, when not THSSelecton
    std::vector<int> diff=VectorIntDiff(fElems,fCombinations[fNiter-1]);
    return SubSet(vec,diff);
  }
  template<class T> std::vector<T> Combitorial::Remainder(std::vector<T> *vec){
    //Must be called after Selection
    if(fType!=2) return SubSet(vec,0); //a vector with 0 entries, when not THSSelecton
    std::vector<int> diff=VectorIntDiff(fElems,fCombinations[fNiter-1]);
    return SubSet(vec,diff);
  }
  ////////////////////////////////////////////////
  ///Function to return the different entries between 2 vector<int> s
  std::vector<int> Combitorial::VectorIntDiff( const std::vector<int>& full, const std::vector<int>& part )
    {
      std::set<int> s_full( full.begin(), full.end() );
      std::set<int> s_part( part.begin(), part.end() );
      std::vector<int> result;
      
      std::set_difference( s_full.begin(), s_full.end(), s_part.begin(), s_part.end(),std::back_inserter( result ) );
      
      return result;
    }
  
  //////////////////////////////////////////////////
  ///Function to truncate a vector at element = entries
  template<class T> std::vector<T*> Combitorial::SubSet(std::vector<T*> *vec,Int_t entries,Int_t starti){
    if(UInt_t(starti+entries)>vec->size()) cout<<"Warning Combitorial::SubSet last entry is > size of vec "<<vec->size()<<" < "<<starti+entries<<endl;
    typename std::vector<T*>::const_iterator first = vec->begin()+starti;
    typename std::vector<T*>::const_iterator last = vec->begin() + starti+entries;
    typename std::vector<T*> newVec(first, last);
    return newVec;
  }
  template<class T> std::vector<T> Combitorial::SubSet(std::vector<T> *vec,Int_t entries,Int_t starti){
    if(UInt_t(starti+entries)>vec->size()) cout<<"Warning Combitorial::SubSet last entry is > size of vec "<<vec->size()<<" < "<<starti+entries<<endl;
    typename std::vector<T>::const_iterator first = vec->begin()+starti;
    typename std::vector<T>::const_iterator last = vec->begin() + starti+entries;
    typename std::vector<T> newVec(first, last);
    return newVec;
  }
  
  ///////////////////////////////////////////////////
  ///Function to select out elements of a vector with indices given in items
  template<class T> std::vector<T*> Combitorial::SubSet(std::vector<T*> *vec,vector<int> items){
    typename std::vector<T*> newVec(items.size());
    for(UInt_t i=0;i<items.size();i++)
      newVec[i]=vec->at(items[i]);
    return newVec;
  }
  template<class T> std::vector<T> Combitorial::SubSet(std::vector<T> *vec,vector<int> items){
    typename std::vector<T> newVec(items.size());
    for(UInt_t i=0;i<items.size();i++)
      newVec[i]=vec->at(items[i]);
    return newVec;
  }
}//namespace HS
#endif //ifdef THSCOMBITORIAL
