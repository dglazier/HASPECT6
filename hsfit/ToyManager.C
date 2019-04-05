#include "ToyManager.h"
#include "RooHSEventsPDF.h"
#include "RooHSEventsHistPDF.h"
#include <TH1.h>
#include <TDirectory.h>
#include <RooRandom.h>
#include <RooStats/RooStatsUtils.h>

namespace HS{
  namespace FIT{

    void ToyManager::Run(){
  
      CreateCurrSetup();

      //Look for Special case of RooHSEventsPDFs
      FillEventsPDFs();
     
      //create extended max likelihood pdf
      fCurrSetup->TotalPDF();
      
      Generate();
    }
    
    void  ToyManager::Generate(){

      Long64_t geni=0;

      auto *model=fCurrSetup->Model();

      auto fitvars=fCurrSetup->FitVarsAndCats();
      RooRandom::randomGenerator()->SetSeed(0);//random seed

      // Long64_t nexp=RooRandom::randomGenerator()->Poisson(model->expectedEvents(fitpars));
      Long64_t nexp=RooRandom::randomGenerator()->Poisson(fCurrSetup->SumOfYields());
      
      fGenData=model->generate(fitvars,nexp);
      fGenData->SetName("ToyData");
      fGenData->Print();
      
    }
    void ToyManager::SaveResults(){
      
      TString fileName=Form("%s%s/%s.root",fCurrSetup->GetOutDir().Data(),GetCurrName().Data(),GetCurrTitle().Data());
      
      fToyFileNames.push_back(fileName);
      
      auto outfile=unique_ptr<TFile> {new TFile(fileName,"recreate")};
      //convert dataset to a tree for saving
      TTree* tree=RooStats::GetAsTTree("ToyData","ToyData",*fGenData);

      auto numEntries=fGenData->numEntries();
      auto cats=fCurrSetup->Cats();

      //add categories to tree! not done by GetAsTTree
      TIter iter=cats.createIterator();
      vector<TBranch*> branches(cats.getSize());
      vector<Int_t> branchVal(cats.getSize());
      Int_t ib=0;
      while(RooCategory* arg=dynamic_cast<RooCategory*>(iter())){	
	TString catName=arg->GetName();
	branches[ib]=tree->Branch(catName,&branchVal[ib],catName+"/I");
	ib++;
      }
      //Now loop over dataset
      for(Int_t entry=0;entry<numEntries;entry++){
	auto vars=fGenData->get(entry);
	ib=0;
	for(auto& branch: branches){
	  branchVal[ib++]=vars->getCatIndex(branch->GetName());
	  branch->Fill();
	}
      }
      tree->Write();
      // for(auto& branch: branches){
      // 	delete branch;
      // }
      delete fGenData; fGenData=nullptr;
     }
    ////////////////////////////////////////////////////////////////
    void ToyManager::PreRun(){
      std::unique_ptr<TFile> resFile{TFile::Open(SetUp().GetOutDir()+"ToySummary.root","recreate")};
      auto initpars=SetUp().ParsAndYields();
      initpars.setName(InitialParsName());
      initpars.Write();
      }
    ////////////////////////////////////////////////////////////////
    std::shared_ptr<FitManager> ToyManager::Fitter(){
      std::shared_ptr<FitManager> fit{new FitManager(*this)};      
      fit->LoadData("ToyData",fToyFileNames);
      fit->Data().Toys(fNToys);
      
      return std::move(fit);
    }
  
    ///////////////////////////////////////////////////////////////
    std::shared_ptr<ToyManager> ToyManager::GetFromFit(Int_t N,TString filename,TString resultFile){
       std::unique_ptr<TFile> fitFile{TFile::Open(filename)};
       // auto fit=dynamic_cast<FitManager*>( fitFile->Get("HSFit") );
       std::unique_ptr<FitManager> fit{dynamic_cast<FitManager*>( fitFile->Get("HSFit"))};
       return GetFromFit(N,*fit.get(),resultFile);
       //       return GetFromFit(*fit,result);
     }
    ///////////////////////////////////////////////////////////////
    std::shared_ptr<ToyManager> ToyManager::GetFromFit(Int_t N,std::shared_ptr<FitManager> fit,TString resultFile){
      return GetFromFit(N,*fit.get(),resultFile);
    }
    ////////////////////////////////////////////////////////////////
    std::shared_ptr<ToyManager> ToyManager::GetFromFit(Int_t N,FitManager& fit,TString resultFile){
      
      std::shared_ptr<ToyManager> toy{new ToyManager(N,fit)};
      std::unique_ptr<TFile> fitFile{TFile::Open(resultFile)};
      std::unique_ptr<RooDataSet> result{dynamic_cast<RooDataSet*>( fitFile->Get(Minimiser::FinalParName()))};

      //Set the values of the paramteres to those in the given result
      if(result.get()){
	auto newPars = toy->SetUp().ParsAndYields();
	auto* resAll = result->get(); //get all result info
	auto* resPars=resAll->selectCommon(newPars); //just select pars and yieds
	newPars.assignFast(*resPars); //set values to results
	cout<<"ToyManager::GetFromFit setting values from fit results "<<resultFile<<" : "<<endl;
	newPars.Print("v");
     }
      
      return std::move(toy);
    }
    //////////////////////////////////////////////////////////////////////
    void ToyManager::Summarise(){
      TChain resChain(Minimiser::ResultTreeName());
      resChain.Add(SetUp().GetOutDir()+"Results*.root");
      std::unique_ptr<TFile> resFile{TFile::Open(SetUp().GetOutDir()+"ToySummary.root","update")};
      auto tree=resChain.CloneTree();
       
      //Loop over all parameters
      std::unique_ptr<RooArgSet> pars{dynamic_cast<RooArgSet*>( resFile->Get(InitialParsName()))};
      cout<<" ToyManager::Summarise() Initial Parameters"<<endl;
      pars->Print("v");
      // auto pars = SetUp().ParsAndYields();   
      TIter iter=pars->createIterator();
      while(RooRealVar* arg=(RooRealVar*)iter()){	
	TString parName=arg->GetName();
	Double_t val=arg->getValV();
	
	tree->Draw(parName,"","goff");
	//parameter
	TH1F *hpar = dynamic_cast<TH1F*>((gDirectory->FindObject("htemp"))->Clone(parName));
	Double_t mean=hpar->GetMean();
	Double_t rms=hpar->GetRMS();

	//parameter error
	tree->Draw(parName+"_err","","goff");
	//parameter
	TH1F *hparErr = dynamic_cast<TH1F*>((gDirectory->FindObject("htemp"))->Clone(parName+"_err"));
	Double_t meanErr=hparErr->GetMean();
	Double_t rmsErr=hparErr->GetRMS();

	//pull distribution
	tree->Draw(Form("(%s-%lf)/%s_err",parName.Data(),mean,parName.Data()),"","goff");
	TH1F *hpull = dynamic_cast<TH1F*>((gDirectory->FindObject("htemp"))->Clone(parName+"_pull"));
	Double_t meanPull=hpull->GetMean();
	Double_t rmsPull=hpull->GetRMS();


	//bias
	tree->Draw(Form("(%s-%lf)",parName.Data(),val),"","goff");
	TH1F *hbias = dynamic_cast<TH1F*>((gDirectory->FindObject("htemp"))->Clone(parName+"_bias"));
	Double_t meanBias=hbias->GetMean();
	
	//bias pull
	tree->Draw(Form("(%s-%lf)/%s_err",parName.Data(),val,parName.Data()),"","goff");
	TH1F *hbiasPull = dynamic_cast<TH1F*>((gDirectory->FindObject("htemp"))->Clone(parName+"_biasPull"));
	Double_t meanBPull=hbiasPull->GetMean();
	Double_t rmsBPull=hbiasPull->GetRMS();

	

	hpar->SetNameTitle(parName,parName);
	hpar->Write();
	hparErr->SetNameTitle(parName+"_err",parName+"_err");
	hparErr->Write();
	hpull->SetNameTitle(parName+"_pull",parName+"_pull");
	hpull->Write();
	hbias->SetNameTitle(parName+"_bias",parName+"_bias");
	hpull->Write();
	hbiasPull->SetNameTitle(parName+"_biasPull",parName+"_biasPull");
	hbiasPull->Write();
	
	cout<<endl<<parName <<" "<<mean<<" +- "<<meanErr<<" sigma "<<rms<<" meanPull "<<meanPull<<" sigmaPull "<<rmsPull<<"\n      bias "<< meanBias << " bias Pull "<<meanBPull<< " sigma "<<rmsBPull<<endl<<endl;
	
      }

    }
  }
}
