#ifndef HSMVA_RESULTINTERFACE_h
#define HSMVA_RESULTINTERFACE_h

#include "FiledTree.h"

#include <TNamed.h>
#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodBase.h"

namespace HS{
  namespace MVA{

    using vecVars=std::vector<Float_t>;
    
    class ResultInterface : public TNamed{
      
      public :
      
      ResultInterface()=default;
      ResultInterface(TString trainpath,TString methodname);
      
      virtual ~ResultInterface()=default;
      
      void AddToTree();
      
      virtual Float_t Eval();
      virtual vector<Float_t> EvalRegN();
      
      Float_t EvalClass();
      Float_t EvalReg1();
      Float_t Eval(const vector<Float_t> vars){fVars=vars;return Eval();}
      void SetVars(const vector<Float_t> vars){fVars=vars;};
      
      Bool_t NextEntry(){
	if(fEntry<fNEntries){ Tree()->GetEntry(fEntry++);return kTRUE;}
	cout<<"HS::MVA::ResultInterface processed "<<fEntry<<" events "<<endl;
	fEntry=0;
	return kFALSE;
      };
      
      TTree* Tree(){return fTree.get()->Tree();}
      TMVA::Reader *Reader(){return fReader.get();}
      TMVA::MethodBase* Method(){return fMethod;}
      TMVA::DataSetInfo* DataSetInfo(){return fDataSetInfo.get();}
  
    protected:
  
      unique_ptr<HS::FiledTree> *TreePtr(){return &fTree;}
      
      vecVars* Vars(){return &fVars;}
      
      void InitMethod(TString trainpath,TString methodname);
      
      void AddRegressionToTree();
      void AddClassificationToTree();
      
      Long64_t fNEntries=0;
      
    private :
      
      unique_ptr<TMVA::DataSetInfo> fDataSetInfo{nullptr};
      unique_ptr<TMVA::Reader> fReader=unique_ptr<TMVA::Reader>{new TMVA::Reader( "!Color:!Silent" )}; 
      TMVA::MethodBase *fMethod=nullptr;//will be owned by fReader
      unique_ptr<HS::FiledTree> fTree{nullptr};
      
      vecVars fVars;
      Long64_t fEntry=0;
      
      ClassDef(ResultInterface,1);  // Virtual base class for all HSMVA results
      
    }; //


    class ResultByFloatTree :  public ResultInterface{
    public:
      ResultByFloatTree()=default;
      ResultByFloatTree(TString trainpath,TString methodname,TTree *tree);
      virtual ~ResultByFloatTree()=default;
      
    protected:
      void SetBranchAddresses(TTree* tree);
      
    };
    /////////////////////////////////////////////////
    ///Allows branches of differnt types
    class ResultByTree :  public ResultInterface{
    public:
      ResultByTree()=default;
      ResultByTree(TString trainpath,TString methodname,TTree *tree,Bool_t copyTree = kFALSE);
      virtual ~ResultByTree()=default;
      
      Float_t Eval() override;
      vector<Float_t> EvalRegN() override;
      
      
    protected:
      void ReadVars();
      void SetBranchAddresses(TTree* tree);
      
    private:
      vector<Double_t> fTreeVarsD;
      vector<Float_t> fTreeVarsF;
      vector<Long64_t> fTreeVarsL;
      vector<Int_t> fTreeVarsI;
      
      vector<UInt_t> fIsVarD;
      vector<UInt_t> fIsVarF;
      vector<UInt_t> fIsVarL;
      vector<UInt_t> fIsVarI;
      
    };//ResultByTee
    
    //////////////////////////////////////////////
    using mapNameFloat = std::map<TString, Float_t* >;
 
    class ResultByRefLink :  public ResultInterface{
    public:
      ResultByRefLink()=default;
      ResultByRefLink(TString trainpath,TString methodname,mapNameFloat links);
      virtual ~ResultByRefLink()=default;
      
      //void AddToTree() override {}; 
      
    }; //ResultByRefLink
    
  }//namespace MVA
 
} //namespace HS

/////////////////////////////////////////////////
///For ResultInterface
inline Float_t HS::MVA::ResultInterface::Eval(){
  if(Method()->DoRegression()) return EvalReg1();
  else return EvalClass();
}
inline Float_t HS::MVA::ResultInterface::EvalReg1(){
  Float_t result=Method()->GetRegressionValues()[0];
  return result;
}
inline vector<Float_t> HS::MVA::ResultInterface::EvalRegN(){
  return Method()->GetRegressionValues();
}
inline Float_t HS::MVA::ResultInterface::EvalClass(){
  Float_t result=Method()->GetMvaValue();
  return result;
}
////////////////////////////////////////////////////////
///For ResultByTree
inline Float_t HS::MVA::ResultByTree::Eval(){
  ReadVars();
  return ResultInterface::Eval();
}
inline vector<Float_t> HS::MVA::ResultByTree::EvalRegN(){
  ReadVars();
  return Method()->GetRegressionValues();
}

#endif //THSMVAABSRESULT_h
