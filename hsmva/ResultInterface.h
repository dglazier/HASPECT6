#ifndef HSMVA_RESULTINTERFACE_h
#define HSMVA_RESULTINTERFACE_h

#include <TNamed.h>
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodBase.h"

namespace HSMVA{
  
  class ResultInterface : public TNamed{

  public :
    
    ResultInterface()=default;
    ResultInterface(TString name,TString varlist,TString methodname,TString weightfile);
    ResultInterface(TString trainpath,TString methodname);
    ResultInterface(TString name):TNamed(name,name){};

    virtual ~ResultInterface();
  
    virtual  Float_t Eval() = 0 ;
  
    void InitMethod(TString methodname,TString weightfile){fMethod=dynamic_cast<TMVA::MethodBase *>(fReader->BookMVA( methodname, weightfile ));};
    void SetBranchAddresses(TTree* tree);
    void SetBranchAllFloats(TTree* tree);

    Float_t Eval(vector<Float_t> vars){fVars=vars;return Eval();}
    Float_t EvalTree();
    
    void SetVars(vector<Float_t> vars){fVars=vars;};
 
  protected:
    TMVA::Reader *Reader(){return fReader;}
    TMVA::MethodBase* Method(){return fMethod;}
    
  private :
    
    TMVA::Reader *fReader=new TMVA::Reader( "!Color:!Silent" );; 
    TMVA::MethodBase* fMethod=nullptr;

    vector<Double_t> fTreeVarsD;
    vector<Float_t> fVars;
    vector<Float_t> fTreeVarsF;
    vector<Long64_t> fTreeVarsL;
    vector<Int_t> fTreeVarsI;

    vector<UInt_t> fIsVarD;
    vector<UInt_t> fIsVarF;
    vector<UInt_t> fIsVarL;
    vector<UInt_t> fIsVarI;
    
    ClassDef(ResultInterface,1);  // Virtual base class for all HSMVA results

  }; //

} //namespace HSMVA

#endif //THSMVAABSRESULT_h
