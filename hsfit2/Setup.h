////////////////////////////////////////////////////////////////
///
///Class:               Setup
///Description:
///           

#ifndef HS_FIT_SETUP_h
#define HS_FIT_SETUP_h


#include <RooWorkspace.h>
#include <RooRealVar.h>
#include <RooCategory.h>
#include <RooAddPdf.h>
#include <RooGaussian.h>
#include <RooFormulaVar.h>
#include <TNamed.h>
#include <TString.h>

#include <vector>


namespace HS{
  namespace FIT{

    using realvar_ptr = std::shared_ptr<RooRealVar>;
    using realvars_t    = std::vector<RooRealVar*>;
    using catvar_ptr  = std::shared_ptr<RooCategory>;
    using catvars_t     = std::vector<RooCategory*>;
    using strings_t = std::vector<TString>;
    RooArgSet MakeArgSet(realvars_t vars);
    RooArgSet MakeArgSet(catvars_t cats);
    void SetAllValLimits(RooArgList&,Double_t val,Double_t low=0,Double_t high=0);
      
    class Setup : public TNamed {
      
    public:
      Setup(TString name);
      Setup();
      Setup(const Setup& other);
      Setup(Setup&&)=default;
      virtual ~Setup(){if(fModel) delete fModel;fModel=nullptr;}
      Setup& operator=(const Setup& other);
      Setup& operator=(Setup&& other) = default;


      void FactoryPDF(TString opt){fWS.factory(opt);fPDFString.push_back(opt);}
      void LoadVariable(TString opt);
      void LoadCategory(TString opt);
      void LoadAuxVar(TString opt);
      void LoadSpeciesPDF(TString opt,Float_t Scale0);
      void TotalPDF();
      
      const RooWorkspace& WS(){return fWS;}

      RooArgSet& Vars();
      RooAbsPdf* Model(){return fModel;}
      RooAddPdf ExtendModel() const{return RooAddPdf(*dynamic_cast<RooAddPdf*>(fModel));}


      
      const TString Cut() const {return fCut;}
      void AddCut(TString cut){if(fCut.Sizeof()>1){fCut+="&&";}fCut+=cut;};
      //void SetCut(TString cut){fCut=cut;}
 
      const TString GetIDBranchName() const {return fIDBranchName;}
      void SetIDBranchName(TString name){fIDBranchName=name;}
      const TString GetOutDir() const {return fOutDir;}
      void SetOutDir(TString name){fOutDir=name;}

      realvars_t &FitVars(){return fFitVars;}
      catvars_t &FitCats(){return fFitCats;}
      
      RooArgList& Yields()  {return fYields;}
      RooArgList& Parameters() {return fParameters;}
      RooArgList& PDFs() {return fPDFs;}
      RooArgList& Constraints(){return fConstraints;}


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
	//	AddFitOption(RooFit::SumW2Error(kTRUE));
	AddFitOption(RooFit::NumCPU(1));
	AddFitOption(RooFit::Save(kTRUE));
	AddFitOption(RooFit::Warnings(kFALSE));
	AddFitOption(RooFit::Minos(kFALSE));
	//	AddFitOption(RooFit::Minimizer("Minuit2"));
      }

    protected:
      
    private:
 
      //note fWS owns all of these vector pointers
      realvars_t fFitVars;      
      realvars_t fAuxVars;      
      catvars_t  fFitCats;
      RooArgSet fVars;
      RooArgList fYields;//species yields
      RooArgList fPDFs;//species pdfs
      RooArgList fParameters;//model parameters
      RooArgList fConstraints;//constraints on  parameters
      RooLinkedList fFitOptions;

      RooAbsPdf* fModel=nullptr; //owned by worksapce
 
      RooWorkspace fWS;
      TString fCut;
      TString fIDBranchName="UID";
      TString fOutDir;

      strings_t fVarString;
      strings_t fCatString;
      strings_t fAuxVarString;
      strings_t fPDFString;
      vector<std::pair<TString,Float_t> > fSpecString;
      const TString fYld="Yld_";//yield variable prepend
    };
    
 
  }//namespace FIT
}//namespace HS

#endif
