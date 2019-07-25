#include "FitManager.h"
#include "RooHSEventsPDF.h"
#include "RooHSEventsHistPDF.h"
#include "TSystem.h"


namespace HS{
  namespace FIT{

 
    FitManager::FitManager(const FitManager& other):TNamed(other.fName,other.fName){
      fSetup=other.fSetup;
      fBinner=other.fBinner;
      //LoadData(other.GetDataTreeName(),other.GetDataFileNames());
  
    }

    FitManager&  FitManager::operator=(const FitManager& other){
      cout<<"=============FitManager"<<endl;
      fSetup=other.fSetup;
      fBinner=other.fBinner;
      //LoadData(other.fData.ParentTreeName(),other.fData.FileNames());
      return *this;
    }
    
    void FitManager::Run(){
      
      CreateCurrSetup();
     
      //get dataset fFiti
      fCurrDataSet=std::move(Data().Get(fFiti));

      //Look for Special case of RooHSEventsPDFs
      FillEventsPDFs();
   
      //Add fit constraints
      fCurrSetup->AddFitOption(RooFit::ExternalConstraints
			       (fCurrSetup->Constraints()));
      //initialise yields
      if(fCurrSetup->Yields().getSize()==1){//special case only 1 yield)
	Double_t yld=fCurrDataSet->sumEntries();
	SetAllValLimits(fCurrSetup->Yields(),
			yld,0,1.2*yld);
      }
      else
	SetAllValLimits(fCurrSetup->Yields(),
			fCurrDataSet->sumEntries()/2,0,fCurrDataSet->sumEntries()*1.2);
      //create extended max likelihood pdf
      fCurrSetup->Parameters().Print("v");
      fCurrSetup->TotalPDF();
      FitTo();
    }
    void FitManager::CreateCurrSetup(){
      fCurrSetup.reset(new Setup(fSetup)); //Copy setup from template
      fCurrSetup->SetName(GetCurrName());
      fCurrSetup->SetTitle(GetCurrTitle());
      //make sure we take current setup values
      //If not it will use the string from Factory() etc,
      fCurrSetup->ParsAndYields().assignFast(fSetup.ParsAndYields());

      //Look to see if taking previous fit results as initial pars
      if(fUsePrevResult){
	LoadPrevResult(fPrevResultDir,fPrevResultMini);
      }
    }
    /////////////////////////////////////////////////////////////
    void FitManager::RunAll(){

      // PreRun();

      UInt_t Nf=GetN();
      for(UInt_t i=0;i<Nf;i++){
	 RunOne(i);
      }
      
    }

    ////////////////////////////////////////////////////////////
    void FitManager::FitTo(){
      if(!fMinimiser.get()) SetMinimiser(new HS::FIT::Minuit2());
      fMinimiser->Run(*fCurrSetup,*fCurrDataSet);
      
      ///////////////////////////
      //Plot best fit and return
      // PlotDataModel();

    }
    void FitManager::RunOne(Int_t ifit){
      fFiti=ifit;
      
      if(fRedirect) RedirectOutput(fSetup.GetOutDir()+Form("logRooFit%d.txt",fFiti));
      Run();
      if(fRedirect) RedirectOutput();
      SaveResults();
     
      Reset();
    }
    
    void FitManager::FillEventsPDFs(){
      UInt_t idata=GetDataBin(fFiti);

      auto pdfs=fCurrSetup->PDFs();

      auto savedir=gDirectory;
      
      cout<<" FitManager::FillEventsPDFs "<<pdfs.getSize()<<endl;
      for(Int_t ip=0;ip<pdfs.getSize();ip++){
	auto pdf=dynamic_cast<RooHSEventsPDF*>( &pdfs[ip]);

	if(pdf){
	  //  pdf->SetConstInt();
	  if(fBinner.FileNames(pdf->GetName()).size()==0)
	    continue;
	  auto filetree=FiledTree::
	    Read(fBinner.TreeName(pdf->GetName()),
		 fBinner.FileNames(pdf->GetName())[idata]);
	  auto tree=filetree->Tree();
	  savedir->cd();
 	  if(!tree.get()){
	    cout<<"WARNING FitManager::FillEventsPDFs :"<<
	      "    No tree data found for EventPDF "<<pdf->GetName()<<endl;
	    continue;
	  }
	  //if too few events remove this PDF
	  if(!tree->GetEntries()||!pdf->IsValid()){
	    fCurrSetup->Yields().remove(fCurrSetup->Yields()[ip]);
	    pdfs.remove(*pdf);
	    ip--;
	  }
	  else{ //use it and give it the simulated tree
	    pdf->SetInWeights(fCurrSetup->GetPDFInWeights(pdf->GetName()));
	    pdf->SetEvTree(tree.get(),fCurrSetup->Cut());

	    //See if data to load for proto data
	    if(!fCurrDataSet.get())
	      fCurrDataSet=std::move(Data().Get(idata));

	    if(fCurrDataSet.get())pdf->AddProtoData(fCurrDataSet.get());
	    RooHSEventsHistPDF* histspdf=0;
	    if((histspdf=dynamic_cast<RooHSEventsHistPDF*>(pdf))){
	      histspdf->CreateHistPdf();
	      fCurrSetup->AddGausConstraint(histspdf->AlphaConstraint());
	      fCurrSetup->AddGausConstraint(histspdf->OffConstraint());
	      fCurrSetup->AddGausConstraint(histspdf->ScaleConstraint());
	    }
	  }
	  //keep the simulated tree alive until Reset()
	  fFiledTrees.push_back(std::move(filetree));	  
	}
      }
      savedir->cd();
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
    //Read in paarameters from previous fit
    void FitManager::InitPrevResult(TString resultDir,TString resultMinimiser){
      fUsePrevResult=kTRUE;
      
      if(resultDir==TString()) fPrevResultDir=fSetup.GetOutDir(); //use current
      else fPrevResultDir=resultDir;

      if(resultMinimiser==TString())fPrevResultMini=fMinimiser->GetName();
      else fPrevResultMini=resultMinimiser;
      
    }
    
    void FitManager::LoadPrevResult(TString resultDir,TString resultMinimiser){
   
      TString resultFile=resultDir+"/"+fCurrSetup->GetName()+"/Results"+fCurrSetup->GetTitle()+resultMinimiser+".root";
	   
      cout<<"LOAD  "<<resultFile<<endl;
      //      TString resultFile=resultDir+Bins().BinName(GetDataBin(GetFiti()))+"/"+resultFileName;
      std::unique_ptr<TFile> fitFile{TFile::Open(resultFile)};
      std::unique_ptr<RooDataSet> result{dynamic_cast<RooDataSet*>( fitFile->Get(Minimiser::FinalParName()))};
      //Set the values of the paramteres to those in the given result
      if(result.get()){
	auto newPars = fCurrSetup->ParsAndYields();
	auto* resAll = result->get(); //get all result info
	auto* resPars=resAll->selectCommon(newPars); //just select pars and yieds
	newPars.assignFast(*resPars); //set values to results
	cout<<"FitManager::LoadResult setting values from fit results "<<resultFile<<" : "<<endl;
	newPars.Print("v");
      }
    }
    void FitManager::WriteThis(){
      auto file=TFile::Open(fSetup.GetOutDir()+"HSFit.root","recreate");
      if(!fMinimiser.get()) SetMinimiser(new HS::FIT::Minuit2());
      file->WriteObject(this,"HSFit");
      file->WriteObject(fMinimiser.get(),fMinimiserType);

      if(fCompiledMacros.size()){
	TList* macList=new TList();
	//	macList->SetName("HS_COMPILEDMACROS");
	macList->SetOwner();
	for(auto& macro : fCompiledMacros)
	  macList->Add(new TObjString(macro));
	file->WriteObject(macList,"HS_COMPILEDMACROS");
      }
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
