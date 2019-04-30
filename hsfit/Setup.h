////////////////////////////////////////////////////////////////
///
///Class:               Setup
///Description:
///           

#ifndef HS_FIT_SETUP_h
#define HS_FIT_SETUP_h


#include <RooStats/ModelConfig.h>
#include <RooWorkspace.h>
#include <RooRealVar.h>
#include <RooCategory.h>
#include <RooAddPdf.h>
#include <RooStats/ModelConfig.h>
#include <RooGaussian.h>
#include <RooFormulaVar.h>
#include <TNamed.h>
#include <TString.h>
#include <TSystem.h>

#include <vector>

#pragma link C++ class vector<std::pair<TString,Float_t> >+;

namespace HS{
  namespace FIT{

    using realvar_ptr = std::shared_ptr<RooRealVar>;
    using realvars_t    = std::vector<RooRealVar*>;
    using catvar_ptr  = std::shared_ptr<RooCategory>;
    using catvars_t     = std::vector<RooCategory*>;
    using strings_t = std::vector<TString>;

    //Helper functions
    RooArgSet MakeArgSet(realvars_t vars);
    RooArgSet MakeArgSet(catvars_t cats);
    void SetAllValLimits(RooArgList&,Double_t val,Double_t low=0,Double_t high=0);
    void ReadFormula(TString forma, strings_t& svars,strings_t& sranges);
    
      
    class Setup : public TNamed {
      
    public:
      Setup(TString name);
      Setup();
      Setup(const Setup& other);
      Setup(Setup&&)=default;
      virtual ~Setup(){if(fModel) delete fModel;fModel=nullptr;}
      Setup& operator=(const Setup& other);
      Setup& operator=(Setup&& other) = default;


      void FactoryPDF(TString opt);
       void LoadVariable(TString opt);
      void LoadCategory(TString opt);
      void LoadAuxVar(TString opt);
      void LoadFormula(TString formu);
      void LoadParameter(TString opt);
      void LoadSpeciesPDF(TString opt,Float_t Scale0=1);
      void TotalPDF();
      
      const RooWorkspace& WS(){return fWS;}

      RooArgSet& DataVars();
      RooArgSet& Cats();
      RooArgSet& FitVarsAndCats();
      RooArgSet& ParsAndYields();
      
      RooAbsPdf* Model()  const {return fModel;}
      RooAddPdf ExtendModel() const{return RooAddPdf(*dynamic_cast<RooAddPdf*>(fModel));}


      
      const TString Cut() const {return fCut;}
      void AddCut(TString cut){if(fCut.Sizeof()>1){fCut+="&&";}fCut+=cut;};
      //void SetCut(TString cut){fCut=cut;}
 
      const TString GetIDBranchName() const {return fIDBranchName;}
      void SetIDBranchName(TString name){fIDBranchName=name;}
      const TString GetOutDir() const {
	if(fOutDir==TString())
	  return "./";
	return fOutDir+"/";
      }
      void SetOutDir(TString name){
	if(!name.BeginsWith("/"))
	  name = TString(gSystem->Getenv("PWD"))+"/"+name;
	fOutDir=name;
	gSystem->Exec(Form("mkdir -p %s",fOutDir.Data()));
      }

      const realvars_t &FitVars() const {return fFitVars;}
      const catvars_t &FitCats()const {return fFitCats;}
      
      RooArgList& Yields()  {return fYields;}
      RooArgList& Parameters() {return fParameters;}
      RooArgList& Formulas() {return fFormulas;}
      const RooArgList& PDFs() const  {return fPDFs;}
      RooArgList& Constraints(){return fConstraints;}

      Double_t SumOfYields();
      
      void AddGausConstraint(RooGaussian *pdf){
	if(!pdf) return;
	fConstraints.add(*(pdf));
      }
      void AddFormulaConstraint(RooFormulaVar *formu){
	if(!formu) return;
	fConstraints.add(*(dynamic_cast<RooAbsArg*>(formu)));
      }
      
      void AddFitOption(RooCmdArg cmd){fFitOptions.Add((RooCmdArg*)cmd.Clone());}
      RooLinkedList FitOptions(){return fFitOptions;}
      
      void DefaultFitOptions(){
	AddFitOption(RooFit::SumW2Error(kTRUE));
	AddFitOption(RooFit::NumCPU(1));
	AddFitOption(RooFit::Save(kTRUE));
	AddFitOption(RooFit::Warnings(kFALSE));
	//AddFitOption(RooFit::Minos(kFALSE));
	//AddFitOption(RooFit::Minimizer("Minuit2"));
      }
      void RandomisePars();

      void SaveSnapShot(TString name){fWS.saveSnapshot(name,RooArgSet(fYields,fParameters),kTRUE);};
      void LoadSnapShot(TString name){fWS.loadSnapshot(name);}

      RooStats::ModelConfig*  GetModelConfig();
      TString GetPDFInWeights(TString name) {return fPDFInWeights[name];}
    protected:
      
    private:
 
      //note fWS owns all of these vector pointers
      realvars_t fFitVars;      
      realvars_t fAuxVars;      
      catvars_t  fFitCats;
      RooArgSet fVars;
      RooArgSet fCats; //only categories
      RooArgSet fPars;//!
      RooArgList fFormulas;//! CANT WRITE formulas ArgSet!
      RooArgSet fVarsAndCats;
      RooArgSet fParsAndYields;
      RooArgList fYields;//species yields
      RooArgList fPDFs;//species pdfs
      RooArgList fParameters;//model parameters
      RooArgList fConstraints;//constraints on  parameters
      RooLinkedList fFitOptions;//

      RooAbsPdf* fModel=nullptr; //!owned by workspace
 
      RooWorkspace fWS;
      TString fCut;
      TString fIDBranchName="UID";
      TString fOutDir;

      strings_t fVarString;
      strings_t fCatString;
      strings_t fParString;
      strings_t fFormString;
      strings_t fAuxVarString;
      strings_t fPDFString;
      std::vector<std::pair<TString,Float_t> > fSpecString;
      std::map<TString,TString> fPDFInWeights;
      TString fYld="Yld_";//yield variable prepend

      ClassDef(HS::FIT::Setup,1);
    };
    
 
  }//namespace FIT
}//namespace HS

#endif
