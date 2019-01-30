#include "Data.h"

namespace HS{
  namespace FIT{

    // DataEvents::DataEvents(TTree* tree,const RooArgSet &vars,
    // 			   const char *selExpr, const char* wgtVarName) :
    //   fData(new RooDataSet("DataEvents","DataEvents",
    // 			   tree,vars,selExpr,wgtVarName)) {
      
    // }
    
    // DataEvents::DataEvents(TString tname,TString fname,const RooArgSet &vars,
    // 	       const char *selExpr, const char* wgtVarName) :
    //   fFiledTree(FiledTree::Read(tname,fname)),
    //   fData(new RooDataSet("DataEvents","DataEvents",
    // 			   fFiledTree->Tree().get(),vars,
    // 			   selExpr,wgtVarName)) {
      
    // }

    DataEvents::DataEvents(Setup &setup,TString tname,strings_t files) :
      fSetup(setup),fTreeName(tname),fFileNames(files),
      fDSets(files.size()),fFiledTrees(files.size())
    {

    }
    RooDataSet* DataEvents::Get(UInt_t iset) {
      cout<<" DataEvents::Get "<<iset <<" "<<fDSets.size()<<endl;
      if(fDSets[iset])
	return fDSets[iset];
      
      cout<<" RooAbsData& DataEvents::Get "<<fDSets.size()<<" "<<fFileNames[iset]<<" "<<fTreeName<<endl;
      fSetup.Vars().Print();
      fFiledTrees[iset]=FiledTree::Read(fTreeName,fFileNames[iset]); //will be delted at end of function
      fDSets[iset]=new  RooDataSet("DataEvents","DataEvents",
      			fFiledTrees[iset]->Tree().get(),fSetup.Vars(),
      			fSetup.Cut());
      cout<<fSetup.Cut()<<endl;

      // auto tempTree=fFiledTrees[iset]->Tree().get()->CopyTree(fSetup.Cut());
      // fDSets[iset]=new RooDataSet("DataEvents","DataEvents",fSetup.Vars(),RooFit::Import(*tempTree));
      // delete tempTree;

      //fDSets[iset]->Print();
      return fDSets[iset];
    }
    // RooDataSet* DataEvents::Get(UInt_t iset,Setup& setup) const{
    //   if(fDSets[iset])
    // 	return fDSets[iset];
      
    //   cout<<" RooAbsData& DataEvents::Get "<<fDSets.size()<<" "<<fFileNames[iset]<<" "<<fTreeName<<endl;
    //   setup.Vars().Print();
    //   fFiledTrees[iset]=FiledTree::Read(fTreeName,fFileNames[iset]); //will be delted at end of function
    //   // fDSets[iset]=new  RooDataSet("DataEvents","DataEvents",
    //   // 			fFiledTrees[iset]->Tree().get(),fSetup.Vars(),
    //   // 			fSetup.Cut());
    //   cout<<setup.Cut()<<endl;
    //   auto tempTree=fFiledTrees[iset]->Tree().get()->CopyTree(fSetup.Cut());
    //   fDSets[iset]=new RooDataSet("DataEvents","DataEvents",setup.Vars(),RooFit::Import(*tempTree));
    //   delete tempTree;
    //   //fDSets[iset]->Print();
    //   return fDSets[iset];
    // }
    
  }//namespace FIT
}//namespace HS
