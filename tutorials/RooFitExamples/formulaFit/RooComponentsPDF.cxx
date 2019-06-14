
#include "Riostream.h" 

#include "RooComponentsPDF.h" 
#include "RooAbsReal.h" 
#include "RooAbsCategory.h" 
#include <math.h> 
#include "TMath.h" 

RooComponentsPDF::RooComponentsPDF(const char *name, const char *title,const RooArgList& obsList,const vector<RooArgList> compList) :  HS::FIT::RooHSEventsPDF(name,title)
 {

   fNObs=obsList.getSize();
   cout<<"RooComps "<<fNObs<<endl;
   
   for(Int_t i=0;i<fNObs;i++)
     fObservables.push_back(new RooRealProxy(obsList[i].GetName(),obsList[i].GetName(),this,static_cast<RooAbsReal&>(obsList[i])));

   fNComps=compList.size();
  cout<<"RooComps comps "<<fNComps<<endl;
    for(auto& comp: compList){
     vecReal vterms;
     for(Int_t i=0;i<comp.getSize();i++){
       //add this component term to the list of all components
       fActualComps.add(static_cast<RooAbsReal&>(comp[i]));
       //now create a proxy with it 
       vterms.push_back(new RooRealProxy(comp[i].GetName(),comp[i].GetName(),this,(RooAbsReal&)fActualComps[fActualComps.getSize()-1]));
     }
     fComponents.push_back(std::move(vterms));
   }
   MakeSets();

   for(Int_t i=0;i<fNObs;i++)
     fObservables[i]->SetName(obsList[i].GetName());
 } 


 RooComponentsPDF::RooComponentsPDF(const RooComponentsPDF& other, const char* name) :
   fActualComps("AllComponents","List of components",this),
    HS::FIT::RooHSEventsPDF(other,name)
 { 
   fComponents=other.fComponents;
   fObservables=other.fObservables;

   fNObs=other.fNObs;
   fNComps=other.fNComps;
   
   MakeSets();
   for(Int_t i=0;i<fNObs;i++)
     fObservables[i]->SetName(other.fObservables[i]->GetName());
 
 } 
void RooComponentsPDF::MakeSets(){

  for(auto *obs: fObservables)
    fProxSet.push_back(obs);
  for(auto &comp: fComponents)
    for(auto *term: comp)
      fParSet.push_back(term);
  
   InitSets();
}



 Double_t RooComponentsPDF::evaluate() const 
 {
   Double_t NComponents=fComponents.size();
   Double_t val=0;
   for(auto &comp: fComponents){
     Double_t product=1;
     for(auto *term: comp){
       product*= *term; //take the product of all the terms for this component
     }
     val+=product; //add them to total
   }
   return val;
 } 

Double_t RooComponentsPDF::evaluateMC(const vector<Float_t> *vars,const  vector<Int_t> *cats) const {
// ENTER IDENTICAL EXPRESSION TO evaluate() IN TERMS OF MC VARIABLE ARGUMENTS HERE
  return 1;
	    
}


