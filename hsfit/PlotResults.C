#include "PlotResults.h"
#include <RooPlot.h>
#include <RooMsgService.h>
#include <TCanvas.h>

namespace HS{
  namespace FIT{
    
    PlotResults::PlotResults(const Setup *setup,const RooDataSet* data){

      using namespace RooFit;
      cout<<"PlotResults::PlotResults "<<fCanvases.get()<<" "<<setup<<" "<<endl;
      //  fCanvases->SetOwner();
      fCanvases->SetName(TString("RFPlots")+setup->GetName());

  	
      auto vars=setup->FitVars();
      auto *model=setup->Model();
      cout<<"model "<<model<<endl;
      
      for( auto *var : vars){
	
	auto canName=TString(setup->GetName())+ "_" + var->GetName();
	auto canvas=new TCanvas(canName,canName);
	fCanvases->Add(canvas);	
	canvas->Divide(2,1);
	canvas->cd(1);

	RooPlot* frame = var->frame();
	data->plotOn(frame, DataError(RooAbsData::SumW2) ) ; 

	auto pdfs = setup->PDFs();
	for(Int_t ic=0;ic<pdfs.getSize();ic++)
	  model->plotOn(frame,Components(pdfs[ic]),LineStyle(kDashed),LineColor(ic%8+1),Precision(1E-2)) ;
	
	model->plotOn(frame,LineColor(kRed),Precision(4E-2)) ;

	model->paramOn(frame,
			Layout(0.1, 0.4, 0.9),
			Format("NEU",AutoPrecision(2)),
			ShowConstants()); //show fit parameters
	
	frame->SetTitle(TString("Fit components for ")+var->GetName());

	frame->Draw() ;
	auto level = RooMsgService::instance().globalKillBelow();
	RooMsgService::instance().setGlobalKillBelow(RooFit::ERROR) ;
 
	///////////////////////////////////////////
	//Residual distributions
	auto halfCanvas=canvas->cd(2);
	halfCanvas->Divide(1,2);
	halfCanvas->cd(1);
	
	auto hres=roohist_uptr(frame->residHist());
	hres->Draw();
     	fRooHists.push_back(std::move(hres));//keep it live

	//Pull distributions
	halfCanvas->cd(2);
	
	auto hpull=roohist_uptr(frame->pullHist());
	hpull->Draw();
	fRooHists.push_back(std::move(hpull));//keep it live
	//////////////////////////////////////////////

	
	RooMsgService::instance().setGlobalKillBelow(level);

	canvas->Modified();
	canvas->Update();
	canvas->Draw();
      }
    }

    void PlotResults::Write(){
      fCanvases->Write();
    }
  }//namespace FIT

}//namespace HS
