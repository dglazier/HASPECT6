#include "sPlot.h"
#include "TDirectory.h"

namespace HS{
  namespace FIT{


  
    void sPlot::Run(UInt_t ifit){
      cout<<"HS::FIT::sPlot::Do prelimanry fits "<<gDirectory->GetName()<<endl;
      FitManager::Run(ifit);
    
       // if(!Data()){
       // 	cout<<"ERROR FitManager::Run no data loaded"<<endl;
       // 	return;
       // }
       //Note sPlot is much (10X) faster with tree store
       //Normal fit is 2X faster with vector...
       RooAbsData::setDefaultStorageType(RooAbsData::Tree);
       RooDataSet* dataset =dynamic_cast<RooDataSet*>( fCurrDataSet->emptyClone());
       dataset->append(*fCurrDataSet.get());
       RooAbsData::setDefaultStorageType(RooAbsData::Vector);
       
      auto *model=fCurrSetup->Model();
      cout<<" splot model y"<<model<<endl;
      ////////////////////////////////////////////////////////
       //sPlot
       cout<<"HS::FIT::sPlot::Run create sWeights "<<endl;
       fCurrSetup->Parameters().setAttribAll("Constant");
       
       fSPlot.reset(new RooStats::SPlot
		    ("splot_fit", "sPlot Fit",
		     *dataset,model,fCurrSetup->Yields()));
       
       fCurrSetup->Parameters().setAttribAll("Constant",kFALSE);

       CreateWeights();
       
       //PlotDataModel();

       delete dataset;
     
   }
    
    void sPlot::CreateWeights(){
      //Check that the fit was succesfull
      Double_t TotalYield=0;
      auto yields=fCurrSetup->Yields();
      for(Int_t iy=0;iy<yields.getSize();iy++)
    	TotalYield+=((RooRealVar*)&yields[iy])->getVal();
      
      if(TotalYield>0){ //got some weights
    	fWeights=std::make_shared<HS::Weights>("HSsWeights");//initialise weights
    	fWeights->SetIDName(fCurrSetup->GetIDBranchName());
    	fWeights->SetTitle(fCurrSetup->GetName());
    	fWeights->SetFile(fCurrSetup->GetOutDir()+TString("Weights")+fCurrSetup->GetName()+fCurrSetup->GetTitle()+".root");
    	ExportWeights();
 	//fWeights->PrintWeight();
	fWeights->SortWeights();

      }
    
      else Warning("sPlot::sPlot()"," total weights 0, fit did not converge. Make sure the non-sweight fit to fix parameters was succesful. No weights will be assigned for these events");
      
    }

    void sPlot::ExportWeights(){
      cout<<"HSsPlot:ExportWeights "<<endl;
      const TString idname=fCurrSetup->GetIDBranchName();
      // cout<<"sPlot::ExportWeights()  "<<idname<<endl;
      const RooArgSet* vars=fCurrDataSet->get(0);
      Bool_t gotID=kFALSE;
      if(vars->find(idname))
	gotID=kTRUE;
      
      auto yields=fCurrSetup->Yields();
      
      Int_t NSpecies=yields.getSize();
      TVectorD eventW(NSpecies); //initialise weights vector
      for(Int_t iw=0;iw<NSpecies;iw++)//set name for each species, 
	fWeights->SetSpecies(TString(yields.at(iw)->GetName()).Remove(0,4));
      
      for(Long64_t ev=0;ev<fCurrDataSet->numEntries();ev++){//loop over events
	for(Int_t iw=0;iw<NSpecies;iw++)//loop over species
	  eventW[iw]=fSPlot->GetSWeight(ev,yields.at(iw)->GetName());//get weight for this species
	if(gotID){//use ID from initial tree
	  const RooArgSet* vars=fCurrDataSet->get(ev);
	  fWeights->FillWeights((Long64_t)vars->getRealValue(idname),eventW);
	} //ID not defined just use entry number in dataset
	else fWeights->FillWeights(ev,eventW);
      }
    }
    
    weights_uptr sPlot::MergeWeights(){
      //in addition combine the weights into 1 and load them
      weights_uptr wts(new HS::Weights("HSsWeights"));
      //Note the output file cannot contain the word Weights (because of Merge), hence Tweights!
      wts->Merge(SetUp().GetOutDir()+"/Weights",
		 SetUp().GetOutDir()+"/"+SetUp().GetName()+"Tweights.root",
		 "HSsWeights");
      //wts->Save();
      return std::move(wts);
    }

    filed_uptr sPlot::WeightedTree(TString wname){
      weights_uptr wts;
      if(Bins().GetSize()>1)
	wts = MergeWeights();
      else{
	wts.reset(new HS::Weights());
	wts->LoadSaved(SetUp().GetOutDir()+TString("Weights")+SetUp().GetName()+".root","HSsWeights");
      }
      return std::move(wts->DFAddToTree(wname,SetUp().GetOutDir()+"Tree"+wname+
					".root",Data().ParentTreeName(),
					Data().ParentName()));
    }

    void sPlot::DrawWeighted(TString var,TString wname){
      if(!fWeightedTree.get())
	fWeightedTree=WeightedTree(wname);

      if(!fWeightedTree.get())
	return;

      fWeightedTree->Tree()->Draw(var,wname);

    }
    void sPlot::WriteThis(){
      auto file=TFile::Open(SetUp().GetOutDir()+"HSFit.root","recreate");
      file->WriteObject(this,"HSFit");
      delete file;
    }
  }//namespace FIT 
}//namespace HS
