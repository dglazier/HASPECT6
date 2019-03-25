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
    void  DataEvents::LoadWeights(TString wname,TString fname){
      fInWeights.reset(new HS::Weights());
      fInWeights->LoadSaved(fname,"HSsWeights");
      fInWeights->PrintWeight();
      fInWeightName=wname.Data();
      cout<<"  DataEvents::LoadWeights using "<<fInWeightName<<" weights "<<endl;
    }
 
    dset_uptr DataEvents::Get(const UInt_t iset) {
      cout<<" RooAbsData& DataEvents::Get "<<" "<<fFileNames[iset]<<" "<<fTreeName<<" "<<fSetup<<" with weights ? "<<fInWeightName<<endl;
     fSetup->DataVars().Print();
     fFiledTrees[iset]=FiledTree::Read(fTreeName,fFileNames[iset]); //will be delted at end of function
  
     auto rawtree= fFiledTrees[iset]->Tree().get() ;
     auto vars = fSetup->DataVars();
     
     if(fInWeights.get()){//if weights add branches and vars
       rawtree=rawtree->CloneTree();//read tree into memory
       rawtree->SetDirectory(0);
       fInWeights->AddToTree(rawtree);
       fWeightVar.reset(new RooRealVar(fInWeightName,fInWeightName,0));
       vars.add(*fWeightVar.get());
     }
     rawtree->Print();
     auto ds=dset_uptr(new  RooDataSet("DataEvents","DataEvents",
				       rawtree,vars,
				       fSetup->Cut(),fInWeightName));
     if(fInWeights.get())
       delete rawtree;
     
     ds->Print();
     return std::move(ds); 
    }
   
  }//namespace FIT
}//namespace HS
