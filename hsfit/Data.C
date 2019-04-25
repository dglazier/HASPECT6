#include "Data.h"

namespace HS{
  namespace FIT{

  

    DataEvents::DataEvents(Setup &setup,TString tname,strings_t files) :
      fSetup(&setup),fTreeName(tname),fFileNames(files),
      fFiledTrees(files.size())
    {
	return;

    }
    TString DataEvents::GetItemName(Int_t ii){
      TString itemName;
      
      if(fNBoots>0&&!fBootStrap.get())
	BootStrap(fNBoots);//.recreate bootstrapper
      
      
      if(fBootStrap.get())
	itemName+=Form("Boot%d",fBootStrap->GetBootID(ii));
      
      else if(fNToys>0) //only toys if no bootstrap
	itemName+=Form("Toy%d",(Int_t) ii%fNToys);
      
      return itemName;
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
      }
      auto newFiles=fBootStrap->GetFileNames();
      fFileNames.insert( fFileNames.end(), newFiles.begin(), newFiles.end() );
      fTreeName=tname;
      fFiledTrees.resize(fFileNames.size());
    }
    void  DataEvents::LoadWeights(TString wname,TString fname){
      fInWeights.reset(new HS::Weights());
      fInWeights->LoadSaved(fname,"HSsWeights");
      fInWeights->PrintWeight();
      fInWeightName=wname.Data();
      fInWeightFile=fname.Data();
      cout<<"  DataEvents::LoadWeights using "<<fInWeightName<<" weights "<<endl;
    }
 
    dset_uptr DataEvents::Get(const UInt_t iset) {
      cout<<"cehck "<<fInWeightName<<" "<<fInWeightFile<<" "<<fFileNames.size()<<endl;
      cout<<" RooAbsData& DataEvents::Get "<<" "<<fFileNames[iset]<<" tree "<<fTreeName<<" weights "<<fInWeights.get()<<" "<<fInWeightName<<endl;
      fSetup->DataVars().Print();

      fFiledTrees[iset]=FiledTree::Read(fTreeName,fFileNames[iset]); //will be delted at end of function
  
     auto rawtree= fFiledTrees[iset]->Tree().get() ;
     auto vars = fSetup->DataVars();
     cout<<"cerate weights"<<endl;
     if(!fInWeights.get()&&fInWeightName!=TString()){ //if Data object read from root file
       LoadWeights(fInWeightName,fInWeightFile);
     }
     if(fInWeights.get()){//if weights add branches and vars
       rawtree=rawtree->CloneTree();//read tree into memory
       rawtree->SetDirectory(0);
       fInWeights->AddToTree(rawtree);
       cout<<"ADDING WEIGHT "<<fInWeightName<<endl;
       fWeightVar.reset(new RooRealVar(fInWeightName,fInWeightName,0));
       fWeightVar->Print();
       vars.add(*fWeightVar.get());
     }
     cout<<"make data set "<<endl;
     // rawtree->Print();

     //only let datset clone active branches
     TIter iter=vars.createIterator();
     rawtree->SetBranchStatus("*",0);
     while(RooAbsArg* arg=(RooAbsArg*)iter())	
       rawtree->SetBranchStatus(arg->GetName(),1);	

     auto ds=dset_uptr(new  RooDataSet("DataEvents","DataEvents",
				       rawtree,vars,
				       fSetup->Cut(),fInWeightName));
     if(fInWeights.get())
       delete rawtree;
     
     fFiledTrees[iset].reset(); //delete rawtree 
     
     cout<<" return DATA "<<endl;
     ds->Print();
     return std::move(ds); 
    }
   
  }//namespace FIT
}//namespace HS
