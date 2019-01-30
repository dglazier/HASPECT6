#include "FitManager.h"
#include "RooHSEventsPDF.h"
#include "RooHSEventsHistPDF.h"

namespace HS{
  namespace FIT{
    void FitManager::Run(UInt_t ifit){
      
      if(!fData.get()){
	cout<<"ERROR FitManager::Run no data loaded"<<endl;
	return;
      }
      
      fCurrSetup.reset(new Setup(ConstSetUp())); //Copy setup from template
      fCurrSetup->SetName(fBinner.BinName(ifit));
      FillEventsPDFs(ifit);
      fCurrSetup->TotalPDF();

      //standard FitManager
      auto &dataset = *(Data()->Get(ifit));
      auto *model=fCurrSetup->Model();

      fCurrSetup->AddFitOption(RooFit::ExternalConstraints
			       (fCurrSetup->Constraints()));
      
      SetAllValLimits(fCurrSetup->Yields(),
		      dataset.sumEntries()/2,0,dataset.sumEntries()*2);

      cout<<"FitManager::Run start fit "<<endl;
      fCurrSetup->FitOptions().Print("v");
      model->fitTo(dataset,fCurrSetup->FitOptions());

       fPlots.push_back(std::move(plotresult_uptr{new PlotResults(fCurrSetup.get(),dataset)}));

    }
    
    void FitManager::RunAll(){
      
      for(UInt_t i=0;i<fData->GetN();i++){
	Run(i);
	Clear(i);
      }
      
    }
    
    void FitManager::FillEventsPDFs(UInt_t idata){
      auto pdfs=fCurrSetup->PDFs();
      auto data=Data()->Get(idata);
      cout<<" FitManager::FillEventsPDFs "<<pdfs.getSize()<<endl;
      for(Int_t ip=0;ip<pdfs.getSize();ip++){
	auto pdf=dynamic_cast<RooHSEventsPDF*>( &pdfs[ip]);
	cout<<ip<<" "<<pdf<<" "<<endl;
	if(pdf){
	  cout<<"FitManager::FillEventsPDFs"<<pdf->GetName()<<" "<<fBinner.FileNames(pdf->GetName())[idata]<<endl;
	  auto filetree=FiledTree::
	    Read(fBinner.TreeName(pdf->GetName()),
		 fBinner.FileNames(pdf->GetName())[idata]);
	  auto tree=filetree->Tree();
	  if(!tree.get()){
	    cout<<"WARNING FitManager::FillEventsPDFs :"<<
	      "    No tree data found for EventPDF "<<pdf->GetName()<<endl;
	    continue;
	  }
	  if(!tree->GetEntries()||!pdf->IsValid()){
	    fCurrSetup->Yields().remove(fCurrSetup->Yields()[ip]);
	    pdfs.remove(*pdf);
	    ip--;
	  }
	  else{
	    pdf->SetEvTree(tree.get(),fCurrSetup->Cut());
	    pdf->AddProtoData(data);
	    RooHSEventsHistPDF* histspdf=0;
	    if((histspdf=dynamic_cast<RooHSEventsHistPDF*>(pdf))){
	      histspdf->CreateHistPdf();
	      fCurrSetup->AddGausConstraint(histspdf->AlphaConstraint());
	      fCurrSetup->AddGausConstraint(histspdf->OffConstraint());
	      fCurrSetup->AddGausConstraint(histspdf->ScaleConstraint());
	    }
	  }
	  fFiledTrees.push_back(std::move(filetree));
	  
	}
      }
    }

 
  }//namespace FIT
}//namespace HS
