#include "sPlot.h"
#include "TDirectory.h"

namespace HS{
  namespace FIT{


  
    void sPlot::Run(UInt_t ifit){
      cout<<"HS::FIT::sPlot::Do prelimanry fits "<<gDirectory->GetName()<<endl;
      FitManager::Run(ifit);
    
       if(!Data()){
	cout<<"ERROR FitManager::Run no data loaded"<<endl;
	return;
       }
       //Note sPlot is much (10X) faster with tree store
       //Normal fit is 2X faster with vector...
       RooAbsData::setDefaultStorageType(RooAbsData::Tree);
       RooDataSet* dataset =dynamic_cast<RooDataSet*>( fCurrDataSet->emptyClone());
       dataset->append(*fCurrDataSet.get());
       RooAbsData::setDefaultStorageType(RooAbsData::Vector);
       

       auto *model=fCurrSetup->Model();
       ////////////////////////////////////////////////////////
       //sPlot
       cout<<"HS::FIT::sPlot::Run create sWeights "<<endl;
       fCurrSetup->Parameters().setAttribAll("Constant");
       
       fSPlot.reset(new RooStats::SPlot
		    ("splot_fit", "sPlot Fit",
		     *dataset,model,fCurrSetup->Yields()));
       
       fCurrSetup->Parameters().setAttribAll("Constant",kFALSE);

       //CreateWeights();
       
       fSPlot.reset(); //delete splot
       delete dataset;
     
   }
    // void CreateWeights(){
    //   //Check that the fit was succesfull
    //   Double_t TotalYield=0;
    //   auto yields=fCurrSetup->Yields();
    //   for(Int_t iy=0;iy<yields.getSize();iy++)
    // 	TotalYield+=((RooRealVar*)&yields[iy])->getVal();
      
    //   if(TotalYield>0){ //got some weights
    // 	fWeights=new HS::Weights("HSsWeights");//initialise weights
    // 	fWeights->SetIDName(fIDBranchName);
    // 	fWeights->SetTitle(GetName());
    // 	fWeights->SetFile(fOutDir+TString("Weights")+GetName()+".root");
    // 	ExportWeights();

    //   }
    
    //   else Warning("sPlot::sPlot()"," total weights 0, fit did not converge. Make sure the non-sweight fit to fix parameters was succesful. No weights will be assigned for these events");
      
    // }
    
  }//namespace FIT 
}//namespace HS
