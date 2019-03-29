#include "FitManager.h"
#include "RooHSEventsPDF.h"
#include "RooHSEventsHistPDF.h"
#include "TSystem.h"


namespace HS{
  namespace FIT{

 
    FitManager&  FitManager::operator=(const FitManager& other){
      cout<<"=============FitManager"<<endl;
      fSetup=other.fSetup;
      fBinner=other.fBinner;
      LoadData(other.fData.ParentTreeName(),other.fData.FileNames());
      return *this;
    }
    
    void FitManager::Run(UInt_t ifit){
      
      fCurrSetup.reset(new Setup(ConstSetUp())); //Copy setup from template
      fCurrSetup->SetName(fBinner.BinName(Data().GetGroup(ifit)));
      fCurrSetup->SetTitle(Data().GetItemName(ifit));
      cout<<"FitManager::Run "<<Data().GetGroup(ifit)<<" "<<fBinner.BinName(Data().GetGroup(ifit))<<" "<<Data().GetItemName(ifit)<<endl;
      fCurrSetup->Print();

      //get dataset ifit
      fCurrDataSet=std::move(Data().Get(ifit));

      //Look for Special case of RooHSEventsPDFs
      FillEventsPDFs(Data().GetGroup(ifit));
      
      //Add fit constraints
      fCurrSetup->AddFitOption(RooFit::ExternalConstraints
			       (fCurrSetup->Constraints()));
      //initialise yields
      SetAllValLimits(fCurrSetup->Yields(),
		      fCurrDataSet->sumEntries()/2,0,fCurrDataSet->sumEntries()*1.2);
      //create extended max likelihood pdf
      fCurrSetup->TotalPDF();
      FitTo();
    }
    
    /////////////////////////////////////////////////////////////
    void FitManager::RunAll(){

       for(UInt_t i=0;i<fData.GetN();i++){
	RunOne(i);
      }
      
    }

    ////////////////////////////////////////////////////////////
    void FitManager::FitTo(){
      if(!fMinimiser.get()) SetMinimiser(new HS::FIT::Minuit2());
      fMinimiser->Run(*fCurrSetup,*fCurrDataSet);
      
      ///////////////////////////
      //Plot best fit and return
      PlotDataModel();

    }
    void FitManager::RunOne(Int_t ifit){
      cout<<"FitManager::RunOne() "<<ifit<< " "<<fSetup.GetOutDir()<<endl;
      if(fRedirect) RedirectOutput(fSetup.GetOutDir()+Form("logRooFit%d.txt",ifit));
      Run(ifit);
      cout<<"FitManager::RunOne() done "<<fResult<<endl;
      if(fRedirect) RedirectOutput();
      SaveResults();
     
      Reset(ifit);
    }
    
    void FitManager::FillEventsPDFs(UInt_t idata){
      auto pdfs=fCurrSetup->PDFs();

      cout<<" FitManager::FillEventsPDFs "<<pdfs.getSize()<<endl;
      for(Int_t ip=0;ip<pdfs.getSize();ip++){
	auto pdf=dynamic_cast<RooHSEventsPDF*>( &pdfs[ip]);
	cout<<ip<<" "<<pdf<<" "<<endl;
	if(pdf){
	  if(fBinner.FileNames(pdf->GetName()).size()==0)
	    continue;
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
	    pdf->AddProtoData(fCurrDataSet.get());
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
    void FitManager::SaveSetup(){
      auto file=TFile::Open(fSetup.GetOutDir()+"HSSetup.root","recreate");
      fSetup.Write("HSSetup");
      delete file;
    }
    void FitManager::LoadSetup(TString dir){
      auto file=TFile::Open(dir+"/HSSetup.root");
      fSetup=*(dynamic_cast<HS::FIT::Setup*>(file->Get("HSSetup")));
      delete file;
    }
    void FitManager::WriteThis(){
      auto file=TFile::Open(fSetup.GetOutDir()+"HSFit.root","recreate");
      if(!fMinimiser.get()) SetMinimiser(new HS::FIT::Minuit2());
      file->WriteObject(this,"HSFit");
      file->WriteObject(fMinimiser.get(),fMinimiserType);      
      delete file;
    }
    void FitManager::RedirectOutput(TString log){
      if(log==TString(""))
	gSystem->RedirectOutput(0,"w");
      else
	gSystem->RedirectOutput(log.Data(),"w");
      
    }

    void FitManager::SaveResults(){
     
      auto outFile=fMinimiser->SaveInfo();
      if(fPlots.size())fPlots.back()->Write(); //just save the last one

      //outfile is unique_ptr so will be deleted and saved here
    }

  }//namespace FIT
}//namespace HS
