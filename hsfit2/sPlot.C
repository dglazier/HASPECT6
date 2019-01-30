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
       //standard FitManager
       auto &dataset0 = *(Data()->Get(ifit));
       //Note sPlot is much (10X) faster with tree store
       //Normal fit is 2X faster with vector...
       RooAbsData::setDefaultStorageType(RooAbsData::Tree);
       RooDataSet* dataset =dynamic_cast<RooDataSet*>( dataset0.emptyClone());
       dataset->append(dataset0);
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
       
       Clear(ifit);
       fSPlot.reset(); //delete splot
       delete dataset;
     
   }
    
    
  }//namespace FIT 
}//namespace HS
