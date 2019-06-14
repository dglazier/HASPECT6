
#include "Riostream.h" 

#include "RooComponentsPDF.h" 
#include "RooAbsReal.h" 
#include "RooAbsArg.h" 
#include "RooAbsCategory.h" 
#include <math.h> 
#include "TMath.h" 

namespace HS{
  namespace FIT{
    RooComponentsPDF::RooComponentsPDF(const char *name, const char *title,Double_t base,const RooArgList& obsList,const vector<RooArgList> compList,RooAbsReal& _Phi) :  HS::FIT::RooHSEventsPDF(name,title), fBaseLine(base)
      
    {

      fNObs=obsList.getSize();
      for(UInt_t i=0;i<fNObs;i++){
	unique_ptr<RooRealProxy> temp{new RooRealProxy(obsList[i].GetName(),obsList[i].GetName(),this,static_cast<RooAbsReal&>(obsList[i]))};
	fActualObs.add((RooAbsReal&)obsList[i]);
	fObservables.push_back(std::move(temp));
      }

      fNComps=compList.size();
      //Arrange the components into a std::vec in order
      //This seems to speed up calcuations
      for(auto& comp: compList){
	vecUPtrReal vterms;
	for(Int_t i=0;i<comp.getSize();i++){
	  //add this component term to the list of all components
	  fActualComps.add(static_cast<RooAbsReal&>(comp[i]));
	  //now create a proxy with it
	  unique_ptr<RooRealProxy> temp{new RooRealProxy(comp[i].GetName(),comp[i].GetName(),this,static_cast<RooAbsReal&>(comp[i]))};
	  vterms.push_back(std::move(temp));
	}
	fComponents.push_back(std::move(vterms));
      }
      MakeSets();

      for(UInt_t i=0;i<fNObs;i++)
	fObservables[i]->SetName(obsList[i].GetName());

      initIntegrator();

    }

    RooComponentsPDF::RooComponentsPDF(const RooComponentsPDF& other, const char* name) :
      HS::FIT::RooHSEventsPDF(other,name),
      fBaseLine(other.fBaseLine),
      fActualComps("AllComponents",this,other.fActualComps),
      fActualObs("AllObservables",this,other.fActualObs)
    {
      Int_t counter=0;
      
      for(UInt_t i=0;i<other.fObservables.size();i++){
	unique_ptr<RooRealProxy> temp{new RooRealProxy(other.fObservables[i]->GetName(),this,*(other.fObservables[i]))};
	fObservables.push_back(std::move(temp));
      }
      
      for(auto& comp: other.fComponents){
	vecUPtrReal vterms;
	for(UInt_t i=0;i<comp.size();i++){
	  unique_ptr<RooRealProxy> temp{new RooRealProxy(comp[i]->GetName(),this,*(comp[i]))};
	  vterms.push_back(std::move(temp));
	}
	fComponents.push_back(std::move(vterms));
      }

      fNObs=other.fNObs;
      fNComps=other.fNComps;
      
      MakeSets();
      for(UInt_t i=0;i<fNObs;i++)
      	fObservables[i]->SetName(other.fObservables[i]->GetName());

      
      initIntegrator();

      //get the original cached integrals      
      fCacheCompDepIntegral=other.fCacheCompDepIntegral;

    } 
    void RooComponentsPDF::MakeSets(){

      for(auto &obs: fObservables){
      	fProxSet.push_back(obs.get());
	//for linking tree events to integral calculation
	fIntegrateObs.push_back(dynamic_cast<RooRealVar*>(fIntegrateSet.addClone(obs->arg())));
      }
      
      for(auto &comp: fComponents)
	for(auto &term: comp){
	  fParSet.push_back(term.get()); //par set just used to check change
	  //get the RooRealVar for this Proxy term
	  auto  argTerm=fActualComps.find(term->GetName());
	  //get its variables, if any
	  auto vars=argTerm->getVariables();
	  TIter iter=vars->createIterator();
	  while(RooAbsArg* arg=dynamic_cast<RooAbsArg*>(iter())){
	    //if new variable and not observable
	    //include it as parameter
	    //auto *rarg=dynamic_cast<RooRealVar*>(arg);	    
	    if(!fActualObs.contains(*arg)&&!fParameters.contains(*arg)){
	      fParameters.add(*arg);
	      //fParSet.push_back(); //par set just used to check change
	    }
	    //	    if(!fActualObs.contains(*arg)&&!fParameters.contains(*arg))fParameters.add(dynamic_cast<RooRealVar*>(arg));
	  }
	}
      InitSets();
    }



    Double_t RooComponentsPDF::evaluateData() const 
    {
      //   if(fComponents[0][0].get()->arg().isValueDirty()||fComponents[0][1].get()->arg().isValueDirty()) cout<<"EVALMC "<<fComponents[0][0].get()->arg().isValueDirty()<<" "<<fComponents[0][1].get()->arg().isValueDirty()<<endl;;
      Double_t val=fBaseLine;
      for(auto &comp: fComponents){
	Double_t product=1;
	for(auto &term: comp){
	  product*= *term.get(); //take the product of all the terms for this component
	}
	val+=product; //add them to total
      }
      return val;
    }

    void RooComponentsPDF::HistIntegrals(const char* rangeName) const{
   //point the terms to the integral events rather than data events
      for(UInt_t icomp=0;icomp<fNComps;icomp++){
	for(const auto &term:fDependentTermProxy[icomp]){
	  auto unconstTerm=const_cast<RooAbsReal*>(&term->arg());
	  unconstTerm->recursiveRedirectServers(fIntegrateSet);
	}
      }
      RooHSEventsPDF::HistIntegrals(rangeName);

      //point the terms back to the data events rather than integral events
      for(UInt_t icomp=0;icomp<fNComps;icomp++){
	for(const auto &term:fDependentTermProxy[icomp]){
	  auto unconstTerm=const_cast<RooAbsReal*>(&term->arg());
	  unconstTerm->recursiveRedirectServers(fActualObs);
	}
      }

    }
    Double_t RooComponentsPDF::evaluateMC(const vector<Float_t> *vars,const  vector<Int_t> *cats) const
    {
      //read in observable value for this event
      for(Int_t ii=0;ii<fNvars;ii++)
	fIntegrateObs[ii]->setVal(fvecReal[fTreeEntry*fNvars+ii]);

      return evaluateData();
    }
  

    void RooComponentsPDF::initIntegrator()
    {
      //Each Component is arranged in terms which are
      //  Observable independent
      //        Can just use current value without looping over events
      //  Observable dependent, parameter independent
      //        Can just loop over event once and cache result
      //  Observable dependent, parameter dependenent
      //        Must loop over events whenever a parameter value changes
      //The final integral for each component is the product of these
      //three super terms
      
      cout<<"RooComponentsPDF::initIntegrator"<<endl;
      //Initiliase components cache
      //fDependentTerm.resize(fNComps);
      fDependentTermProxy.resize(fNComps);
      fDependentTermParams.resize(fNComps);
      fPrevParVals.resize(fNComps);
      fCacheCompDepIntegral.resize(fNComps);
      
      //fIndependentTerm.resize(fNComps);
      fIndependentTermProxy.resize(fNComps);
      //fParameterTerm.resize(fNComps);
      UInt_t icomp=0;
      for(auto &comp: fComponents){
	fCacheCompDepIntegral[icomp]=1;
	//fDependentTerm[icomp].resize(comp.size());
	//fDependentTermProxy[icomp].resize(comp.size());
	//fIndependentTerm[icomp].resize(comp.size());
	//fIndependentTermProxy[icomp].resize(comp.size());
	
	//fParameterTerm[icomp].resize(comp.size());
	UInt_t iterm=0;
	Double_t product=1;
	for(auto &term: comp){
	  //Identify which terms are dependent on fit observables (VarSet)
	  auto  arg=fActualComps.find(term->GetName());
	  auto deps=arg->getDependents(VarSet(0));
	  if(deps->getSize()){
	    //  fDependentTerm[icomp][iterm]=1;
	    fDependentTermProxy[icomp].push_back(term.get());
	    //Identify which terms are dependent on fit parameters (ParSet)
	    auto parDeps=arg->getDependents(fParameters);
	    if(parDeps->getSize()){
	      //fParameterTerm[icomp][iterm]=1;
	      TIter iter=parDeps->createIterator();
	      while(RooAbsArg* arg=dynamic_cast<RooAbsArg*>(iter())){
		//if new variable 
		//include it as parameter
		//		if(std::find(fDependentTermParams[icomp].begin(), fDependentTermParams[icomp].end(), arg) == vec.end()) fDependentTermParams[icomp].add(arg);
		auto *rarg=dynamic_cast<RooRealVar*>(arg);	    
		if(!(vecContains(rarg,fDependentTermParams[icomp]))){
		  fDependentTermParams[icomp].push_back(rarg);
		  Float_t initf=-1E6;
		  fPrevParVals[icomp].push_back(initf);
		}
	      }
	      //fDependentTermParams[icomp].add(fParameters);
	      // fDependentTermProxy.push_back(term);
	    }
	    else{
	      //fIndependentTermProxy.push_back(term);
	      // fParameterTerm[icomp][iterm]=0;
	    }
	    
	  }
	  else{
	    fIndependentTermProxy[icomp].push_back(term.get());
	    //fDependentTerm[icomp][iterm]=0;
	    //fParameterTerm[icomp][iterm]=0;
	  }
	  
	  iterm++;
	}
	//	cout<<"DEPENDENT TERM PARAMETERS "<<endl;
	//	for(auto &param: fDependentTermParams[icomp])
	// param->Print();
	
	icomp++;
	
      }	  
      //Identify which terms are dependent on fit observables (VarSet)
      
      //Identify which terms ONLY dependent on fit observbales
      
      //Identify which terms depend on fit parameters but not observables
    }
    
    
    
    
    
    Double_t RooComponentsPDF::analyticalIntegral(Int_t code,const char* rangeName) const
    {
      //  cout<<" RooComponentsPDF::analyticalIntegral"<<fDependentTermProxy.size()<<" "<< fIndependentTermProxy.size()<<endl;
      //  cout<<"Analystic "<<fIntCounter++<<" "<<fEvTree<<endl;
      //Check which dependent terms need recalculation
      //This will be 1) if they are dependent on parameters
      //           2) one or more of the parameters have changed
      Bool_t needRecalc=kFALSE;
      fRecalcComponent.clear();
      for(UInt_t icomp=0;icomp<fNComps;icomp++){
	//	for(UInt_t iterm=0;iterm<fComponents[icomp].size();iterm++){
	  
	  if(fDependentTermProxy[icomp].size()) {
	   
	    for(auto &var:fDependentTermProxy[icomp]){
	      if(var->arg().isValueDirty()){
		//	var->arg().printDirty();
		//cout<<"Dirty var "<<var.GetName()<<endl;
	      }
	      //else {cout<<"NotDirty"<<endl;var->arg().Print("v");}
	    }
	    UInt_t ipar=0;
	    for(auto &par:fDependentTermParams[icomp]){
	      Float_t previous=fPrevParVals[icomp][ipar];
	      Float_t pval=par->getVal();
	      if(pval!=previous){ //trigger recalc
		needRecalc=kTRUE;
	        cout<<"Dirty Par "<<par->GetName()<<" "<<par->getVal()<<endl;
		fPrevParVals[icomp][ipar]=pval;
		fRecalcComponent.push_back(icomp);
		continue;//only need one change to trigger recalc
	      }
	      else cout<<"Clean Par "<<par->GetName()<<" "<<par->getVal()<<endl;
	      //Store parameter values to check for a change
	      ipar++;
	    }
	  }
	  
      }
      ///////////////////////////////
      if(needRecalc)RecalcComponentIntegrals(code,rangeName);

      Double_t integral=fBaseLine;
      for(UInt_t icomp=0;icomp<fNComps;icomp++)
	integral+=componentIntegral(icomp);

      //cout<<"INTEGRAL "<<integral<<endl;
      //calculate total integral
      return integral;
    }

    void RooComponentsPDF::RecalcComponentIntegrals(Int_t code,const char* rangeName) const{
      Long64_t ilow,ihigh=0;
      // if(fParent){
      // 	ilow=fParent->GetIntRangeLow();
      // 	ihigh=fParent->GetIntRangeHigh();
      // }
      // else{
      // 	ilow=GetIntRangeLow();
      // 	ihigh=GetIntRangeHigh();
      // }
      
      // if(ihigh==0&&fNInt>-1) ihigh=fNInt;
      // else if(ihigh==0) ihigh=fNTreeEntries; 
      
      // if(ihigh>fNTreeEntries) ihigh=fNTreeEntries;
      SetLowHighVals(ilow,ihigh);
      cout<<"RooComponentsPDF::RecalcComponentIntegrals "<<ilow<<" "<<ihigh<<endl;
      //point the terms to the integral events rather than data events
      for(const auto& icomp:fRecalcComponent){
	for(const auto &term:fDependentTermProxy[icomp]){
	  auto unconstTerm=const_cast<RooAbsReal*>(&term->arg());
	  unconstTerm->recursiveRedirectServers(fIntegrateSet);
	}
      }

      //Loop over events and recalcaulte partial integrals
      //that depend on parameters that have changed
   
      for(Long64_t ie=ilow;ie<ihigh;ie++){
	fTreeEntry=ie;
	if(!CheckRange(TString(rangeName).Data())) continue;

	//read in observable value for this event
	for(Int_t ii=0;ii<fNvars;ii++)
	  fIntegrateObs[ii]->setVal(fvecReal[fTreeEntry*fNvars+ii]);

	//calculate the partial integrals
	for(const auto& icomp:fRecalcComponent){
	  Double_t product=1;
	  for(const auto &term:fDependentTermProxy[icomp]){
	    product*= *term;
	  }
	  fCacheCompDepIntegral[icomp]+=product;
	}
      }
      //Normalise to number of events
      for(const auto& icomp:fRecalcComponent){
	fCacheCompDepIntegral[icomp]=fCacheCompDepIntegral[icomp]/(ihigh-ilow);
	//cout<<"RECALCULATED "<<icomp <<" "<<fCacheCompDepIntegral[icomp]<<endl;
      }
     //point the terms back to the data events rather than integral events
      for(const auto& icomp:fRecalcComponent){
	for(const auto &term:fDependentTermProxy[icomp]){
	  auto unconstTerm=const_cast<RooAbsReal*>(&term->arg());
	  unconstTerm->recursiveRedirectServers(fActualObs);
	}
      }

      
    }
    Double_t RooComponentsPDF::componentIntegral(Int_t icomp) const{
      //calculate integral of this component
      //First take product of terms independent of observables;
      Double_t product=1;
      // cout<<"RooComponentsPDF::componentIntegral "<<icomp<<" "<<fCacheCompDepIntegral[icomp]<<endl;
      product*=fCacheCompDepIntegral[icomp];
      for(auto& term:fIndependentTermProxy[icomp]){
    	product*= *term;
      }
      //      Now take product with observable dependent parts
      // for(auto& compIntegral:fCacheCompDepIntegral){
      // 	product*=compIntegral;
      // }
      // cout<<"RooComponentsPDF::componentIntegral product "<<product<<endl;
      return product; 
    }

    Bool_t RooComponentsPDF::SetEvTree(TTree* tree,TString cut,Long64_t ngen){
      auto val = RooHSEventsPDF::SetEvTree(tree,cut,ngen);

      //Caclulate current value of component integrals
      for(UInt_t icomp=0;icomp<fNComps;icomp++)
	fRecalcComponent.push_back(icomp);
      RecalcComponentIntegrals(0,"");
      return val;
    }
  }
}
