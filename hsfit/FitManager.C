#include "FitManager.h"
#include "RooHSEventsPDF.h"
#include "RooHSEventsHistPDF.h"
#include "RooStats/RooStatsUtils.h"
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
		      fCurrDataSet->sumEntries()/2,0,fCurrDataSet->sumEntries()*2);
      //create extended max likelihood pdf
      fCurrSetup->TotalPDF();
      auto *model=fCurrSetup->Model();

      // fResult=model->fitTo(*fCurrDataSet,fCurrSetup->FitOptions());
      //      PlotDataModel();
      FitTo();
      
      fResult->Print();
    }
    
    void FitManager::RunAll(){

       for(UInt_t i=0;i<fData.GetN();i++){
	RunOne(i);
      }
      
    }
    void FitManager::FitTo(){
      //original fit using intial parameters
      auto *model=fCurrSetup->Model();    
      fResult=model->fitTo(*fCurrDataSet,fCurrSetup->FitOptions());
      
      //Perform many fits with differnt initial parameters
      if(fNRefits){
	UInt_t nrefit = 0;
	fCurrSetup->SaveSnapShot(Form("Refit_%d",nrefit)); //original
	vector<Double_t> likelies;

	using result_uptr=std::unique_ptr<RooFitResult>;
	
	vector<result_uptr> results;

	//save original likelihood and results
	StoreLikelihood(likelies);
	results.push_back(result_uptr{dynamic_cast<RooFitResult*>(fResult->clone())});

	//loop over refits
	while(nrefit++<fNRefits){
	  fCurrSetup->RandomisePars();
	  fResult=model->fitTo(*fCurrDataSet,fCurrSetup->FitOptions());
	  fCurrSetup->SaveSnapShot(Form("Refit_%d",nrefit));
	  StoreLikelihood(likelies);
	  results.push_back(result_uptr{dynamic_cast<RooFitResult*>(fResult->clone())});
	}
	//Find the best fit result and save it
	Int_t best=std::distance(likelies.begin(), std::min_element(likelies.begin(), likelies.end()));
	cout<<"FitManager::FitTo() best fit likelihood "<<likelies[best]<<" from fit "<<best<<" all likelihoods "<<endl;
	for(auto& lh:likelies)
	  cout<<lh<<" ";
	cout<<endl;
	fCurrSetup->LoadSnapShot(Form("Refit_%d",best));
	fResult=dynamic_cast<RooFitResult*>(results[best]->clone());
      }
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
      // fResult->Print();
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
      file->WriteObject(this,"HSFit");
      delete file;
    }
    void FitManager::RedirectOutput(TString log){
      if(log==TString(""))
	gSystem->RedirectOutput(0,"w");
      else
	gSystem->RedirectOutput(log.Data(),"w");
      
    }

    void FitManager::SaveResults(){
      TString fileName=fCurrSetup->GetOutDir()+fCurrSetup->GetName()+"/Results"+fCurrSetup->GetTitle()+".root";
      std::unique_ptr<TFile> file(TFile::Open(fileName,"recreate"));
      if(fPlots.size())fPlots.back()->Write();
      if(fResult) fResult->Write("HSFitResult");
      
      //save paramters and chi2s in  dataset (for easy merging)
      RooArgSet saveArgs(fCurrSetup->Parameters());
      saveArgs.add(fCurrSetup->Yields());
      RooRealVar Nllval("NLL","NLL",fResult->minNll());
      saveArgs.add(Nllval);
      RooDataSet saveDS("HSResults","HSResults",saveArgs);
      saveDS.add(saveArgs);
      saveDS.Write();
      TTree* treeDS=RooStats::GetAsTTree("ResultsTree","ResultsTree",saveDS);
      treeDS->Write();
      
    }
    void FitManager::StoreLikelihood(vector<Double_t> &likelies){
      Bool_t nan=TMath::IsNaN(fResult->minNll());
      //check covariance OK or externally provide (SumW2Error) =-1
      Bool_t edm=(fResult->covQual()>1)||(fResult->covQual()==-1);
      Bool_t fail=(fResult->minNll()!=-1e+30);
      if((!nan)&&edm&&fail)likelies.push_back(fResult->minNll());
      else likelies.push_back(1E300);
    }

  }//namespace FIT
}//namespace HS
