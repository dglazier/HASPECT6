#include "Data.h"

namespace HS{
  namespace FIT{

  

    DataEvents::DataEvents(Setup &setup,TString tname,strings_t files) :
      fSetup(&setup),fTreeName(tname),fFileNames(files),
      fFiledTrees(files.size())
    {
	return;

    }
     void DataEvents::Load(Setup &setup,TString tname,strings_t files)
    {
      fSetup=&setup;
      cout<<"DataEvents::Load "<<tname<<" "<<files.size()<<endl;
      //check if bootstrapping
      if(fBootStrap.get()){
	LoadBootStrap(tname,files);
	return;
      }
      //just load give files
      fTreeName=tname;
      fFileNames=files;
      fFiledTrees.resize(files.size());
 
    }
    
    void DataEvents::LoadBootStrap(TString tname,strings_t files)
    {
      cout<<"DataEvents::LoadBootStrap("<<tname <<" "<<files.size()<<endl;
      fBootStrap->SetOutDir(fSetup->GetOutDir());
      fFileNames.clear();
      //Loop over all the filenames (e.g different bins) and split the data
      for(auto &filename : files){
	fBootStrap->DivideData(tname,filename);
	auto newFiles=fBootStrap->GetFileNames();
	fFileNames.insert( fFileNames.end(), newFiles.begin(), newFiles.end() );
      }
      fTreeName=tname;
      fFiledTrees.resize(fFileNames.size());
 
    }
    
    dset_uptr DataEvents::Get(const UInt_t iset) {
      cout<<" RooAbsData& DataEvents::Get "<<" "<<fFileNames[iset]<<" "<<fTreeName<<" "<<fSetup<<endl;
     fSetup->DataVars().Print();
     fFiledTrees[iset]=FiledTree::Read(fTreeName,fFileNames[iset]); //will be delted at end of function
     fFiledTrees[iset]->Tree()->Print();
     auto ds=dset_uptr(new  RooDataSet("DataEvents","DataEvents",
		       fFiledTrees[iset]->Tree().get(),fSetup->DataVars(),
					      fSetup->Cut()));
          
     return std::move(ds); 
    }
   
  }//namespace FIT
}//namespace HS
