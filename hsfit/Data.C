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
    void  DataEvents::LoadWeights(TString wname,TString fname,TString wobj){
      auto wcon=WeightsConfig{wname,fname,wobj};
      fInWeights.reset(new HS::Weights());
      //fInWeights->LoadSaved(wcon.File(),wcon.ObjName());
      fInWeights->LoadSavedDisc(wcon.File(),wcon.ObjName());
      // fInWeights->PrintWeight();
      fInWeightName=wcon.Species().Data();
      fInWeightFile=wcon.File().Data();
      fInWeightObjName=wcon.ObjName().Data();
      cout<<"  DataEvents::LoadWeights using "<<fInWeightName<<" weights "<<endl;
    }
 
    dset_uptr DataEvents::Get(const UInt_t iset) {
  
      cout<<" RooAbsData& DataEvents::Get "<<" "<<fFileNames[iset]<<" tree "<<fTreeName<<" weights "<<fInWeights.get()<<" "<<fInWeightName<<endl;
      
      fFiledTrees[iset]=FiledTree::Read(fTreeName,fFileNames[iset]); //will be delted at end of function
  
     auto rawtree= fFiledTrees[iset]->Tree().get() ;
     auto vars = fSetup->DataVars();
     
     if(!fInWeights.get()&&fInWeightName!=TString()){ //if Data object read from root file
       LoadWeights(fInWeightName,fInWeightFile);
     }
     if(fInWeights.get()){//if weights add branches and vars
       //create a copy in a new file to append the weights to
       //Keep it in file as large trees can use too much memory
       auto weightedFileTree=FiledTree::CloneFull(rawtree,fSetup->GetOutDir()+Form("/DataInWeightedTree%d.root",iset));
       //auto weightedFileTree=FiledTree::RecreateCopyFull(rawtree,fSetup->GetOutDir()+"DataInWeightedTree.root");
       fFiledTrees[iset].reset();
       fFiledTrees[iset]=std::move(weightedFileTree);

       rawtree= fFiledTrees[iset]->Tree().get() ;	
       //Add weights to tree
       cout<<"           About to add weights to tree "<<endl;
       fInWeights->AddToTree(rawtree);	
      //fInWeights->AddToTreeDisc(rawtree,fSetup->GetOutDir()+"DataInWeights.root");	
       fWeightVar.reset(new RooRealVar(fInWeightName,fInWeightName,0));
       fWeightVar->Print();
       vars.add(*fWeightVar.get());
     }
     cout<< "                now get the data "<<endl;
     //only let datset clone active branches
     TIter iter=vars.createIterator();
     rawtree->SetBranchStatus("*",0);
     while(RooAbsArg* arg=(RooAbsArg*)iter())	
       rawtree->SetBranchStatus(arg->GetName(),1);	

     auto ds=dset_uptr(new  RooDataSet("DataEvents","DataEvents",
				       rawtree,vars,
				       fSetup->DataCut(),fInWeightName));

     fFiledTrees[iset].reset(); //delete rawtree 
     if(fInWeights.get()){
       fInWeights.reset();
     }		
     
     
     ds->Print();
     return std::move(ds); 
    }
   
  }//namespace FIT
}//namespace HS
