#include "Data.h"

namespace HS{
  namespace FIT{

  

    DataEvents::DataEvents(Setup &setup,TString tname,strings_t files) :
      fSetup(setup),fTreeName(tname),fFileNames(files),
      fFiledTrees(files.size())
    {

    }
    dset_uptr DataEvents::Get(const UInt_t iset) {
     cout<<" RooAbsData& DataEvents::Get "<<" "<<fFileNames[iset]<<" "<<fTreeName<<endl;
     fSetup.DataVars().Print();
     fFiledTrees[iset]=FiledTree::Read(fTreeName,fFileNames[iset]); //will be delted at end of function
     auto ds=dset_uptr(new  RooDataSet("DataEvents","DataEvents",
		       fFiledTrees[iset]->Tree().get(),fSetup.DataVars(),
					      fSetup.Cut()));
          
     return std::move(ds); 
    }
   
  }//namespace FIT
}//namespace HS
