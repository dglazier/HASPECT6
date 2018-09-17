#ifndef HSMVA_METHCON_h
#define HSMVA_METHCON_h

#include <TMVA/Types.h>
#include <TMVA/Tools.h>
 
namespace HSMVA {
  
  class MethConf {
    
   public:
    
    MethConf(TMVA::Types::EMVA type,TString name,TString params):
    fName(name),fType(type),fParams(params){}
    
    virtual ~MethConf()=default;
    
    void SetName(TString name) {fName = name;};
    void SetType(TMVA::Types::EMVA type) {fType = type;};
    void SetParameters(TString params) {fParams = params;};
    
    
  /*   TMVA::Types::EMVA Type() const {return fMethodType;}; */
  /*   TString Name() const {return fMethodName;}; */
  /*   TString Params() const {return fMethodParameters;}; */

  /* private: */
    
    TMVA::Types::EMVA fType; // method type for factory
    TString fName;           // name for saving dataset
    TString fParams;     // string of parameters for factory

  }; //class MethConf

  //Method Configurations taken from TMVAClassification.C
  //I am sure there is a beter way than this to provide
  //these defaults. Note if Meths is not const it crashes
  //om exiting ROOT
  struct MethodList{

    MethConf BDTA={TMVA::Types::kBDT,"defBDTA","!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20"};
    
    MethConf BDTG={TMVA::Types::kBDT, "defBDTG", "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=2"};
    
    MethConf BDTD={TMVA::Types::kBDT,"defBDTD","!H:!V:NTrees=400:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:SeparationType=GiniIndex:nCuts=20:VarTransform=Decorrelate"};
    
    MethConf RuleFit={TMVA::Types::kRuleFit, "defRuleFit","H:!V:RuleFitModule=RFTMVA:Model=ModRuleLinear:MinImp=0.001:RuleMinDist=0.001:NTrees=20:fEventsMin=0.01:fEventsMax=0.5:GDTau=-1.0:GDTauPrec=0.01:GDStep=0.01:GDNSteps=10000:GDErrScale=1.02"};
    
    MethConf MLP={TMVA::Types::kMLP, "defMLP", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:!UseRegulator"};
    
    MethConf Cuts={TMVA::Types::kCuts, "defCuts", "!H:!V:FitMethod=MC:EffSel:SampleSize=200000:VarProp=FSmart"};
    
    /* MethConf BDTG(TMVA::Types::kBDT, "BDTG", "!H:!V:NTrees=1000:MinNodeSize=2.5%:BoostType=Grad:Shrinkage=0.10:UseBaggedBoost:BaggedSampleFraction=0.5:nCuts=20:MaxDepth=2"); */
    /* MethConf BDTD(TMVA::Types::kBDT,"BDTD","!H:!V:NTrees=400:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:SeparationType=GiniIndex:nCuts=20:VarTransform=Decorrelate"); */
    /* MethConf RuleFit( TMVA::Types::kRuleFit, "RuleFit","H:!V:RuleFitModule=RFTMVA:Model=ModRuleLinear:MinImp=0.001:RuleMinDist=0.001:NTrees=20:fEventsMin=0.01:fEventsMax=0.5:GDTau=-1.0:GDTauPrec=0.01:GDStep=0.01:GDNSteps=10000:GDErrScale=1.02"); */
    /* MethConf MLP(TMVA::Types::kMLP, "MLP", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:!UseRegulator"); */
    //} //namespace ClassMethConfs
  }; //struct Meths

  static const MethodList Meths;
}
#endif // HSMVA_METHODCONFIGURE
