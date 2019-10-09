#include "ToyManager.h"
#include "RooHSEventsPDF.h"
#include "RooHSEventsHistPDF.h"
#include "RooComponentsPDF.h"
#include <TH1.h>
#include <TDirectory.h>
#include <RooRandom.h>
#include <RooStats/RooStatsUtils.h>

namespace HS{
  namespace FIT{

    void ToyManager::Run(){


      LoadResult();
      
      if(GetCurrToy()==0){
	InitSummary(); 
      }
      
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

 
      //fitvars.Print("v");
      auto iter=fitvars.iterator();
      const RooAbsArg *tmp=0;
      while ((tmp = (RooAbsArg*)iter.Next())){
	auto arg=fitvars.find(tmp->GetName());
	cout<<"ToyManager::Generate() "<<tmp->GetName()<<" "<<model->isDirectGenSafe(*arg)<<endl;
      }

      while(fToyi<fNToys){
	fGenData=model->generate(fitvars,nexp);
	fGenData->SetName("ToyData");
	SaveResults();
	fToyi++;
      }
      fToyi=0;
      
    }
    void ToyManager::SaveResults(){
      if(!fGenData) return;

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
      delete tree;
      delete fGenData; fGenData=nullptr;
     }
    ///////////////////////////////////////////////////////////////
    void ToyManager::InitSummary(){
      std::unique_ptr<TFile> resFile{TFile::Open(SetUp().GetOutDir()+GetCurrName()+"/ToySummary.root","recreate")};
      auto initpars=*((RooArgSet*)(SetUp().ParsAndYields().selectByAttrib("Constant",kFALSE)));
      cout<<"ToyManager::InitSummary()"<<endl;
      initpars.Print("v");
      initpars.setName(InitialParsName());
      //initpars.Write();//commented out for amplitudes test as crashing?!>
      //resFile->WriteObject(&initpars,InitialParsName());//crahss when RooFormulaVar is used....
      //cant save pars to file directly if got formulavar connected 
      //dont know why
      RooDataSet d(InitialParsName(),InitialParsName(),initpars);
      d.fill();
      d.Print("v");
      d.Write();

    }
    ////////////////////////////////////////////////////////////////
    void ToyManager::PreRun(){
  
      //if using bins make sure directories are made
      Bins().GetBins().SetOutDir(SetUp().GetOutDir());
      Bins().GetBins().MakeDirectories();
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
      
      std::shared_ptr<ToyManager> toy{new ToyManager(N,fit,fit.SetUp().GetOutDir(),resultFile)};

      return std::move(toy);
    }

    void ToyManager::LoadResult(){
      if(fResultFileName==TString())
	return;
      // cout<<"LOAD  "<<fResultFileName<<endl;
      TString resultFile=fResultOutDir+Bins().BinName(GetDataBin(GetFiti()))+"/"+fResultFileName;
      std::unique_ptr<TFile> fitFile{TFile::Open(resultFile)};
      std::unique_ptr<RooDataSet> result{dynamic_cast<RooDataSet*>( fitFile->Get(Minimiser::FinalParName()))};
      //Set the values of the paramteres to those in the given result
      if(result.get()){
	auto newPars = SetUp().ParsAndYields();
	auto* resAll = result->get(); //get all result info
	auto* resPars=resAll->selectCommon(newPars); //just select pars and yieds
	newPars.assignFast(*resPars); //set values to results
       	cout<<"ToyManager::LoadResult setting values from fit results "<<resultFile<<" : "<<endl;
	newPars.Print("v");
      }
    }
    //////////////////////////////////////////////////////////////////////
    void ToyManager::Summarise(){
      if(!Bins().GetSize())
	Summarise(0);
  
      for(UInt_t i=0;i<Bins().GetSize();i++)
	Summarise(i);
      
    }
    //////////////////////////////////////////////////////////////////////
    void ToyManager::Summarise(Int_t ibin){
      cout<<"Summarise "<<Minimiser::ResultTreeName() <<" "<<SetUp().GetOutDir()+Bins().BinName(ibin)<<endl;
      TChain resChain(Minimiser::ResultTreeName());
      resChain.Add(SetUp().GetOutDir()+Bins().BinName(ibin)+"/Results*.root");
      std::unique_ptr<TFile> resFile{TFile::Open(SetUp().GetOutDir()+Bins().BinName(ibin)+"/ToySummary.root","update")};
      auto tree=resChain.CloneTree();
       
      //Loop over all parameters
      std::unique_ptr<RooDataSet> parsData{dynamic_cast<RooDataSet*>( resFile->Get(InitialParsName()))};
      cout<<" ToyManager::Summarise() Initial Parameters"<<endl;
      if(!parsData.get()) return;
      auto pars=parsData->get();
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
