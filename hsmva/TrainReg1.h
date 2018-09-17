#ifndef HSMVA_TRAINREG1_h
#define HSMVA_TRAINREG1_h

#include <TMVA/TMVARegGui.h>

#include "TrainingInterface.h"

namespace HSMVA{
  
  class TrainReg1 : public TrainingInterface{

  public :
    
    TrainReg1()=default;
    TrainReg1(TString name,TString opt="!V:!Silent:Color:DrawProgressBar:AnalysisType=Regression");
    virtual ~TrainReg1()=default;
  
    void AddRegTree(TTree*  tree,TString wvar="",Double_t weight=1);
    void SetTarget(TString tar){IgnoreBranches(tar); DataLoader()->AddTarget(tar);}
    void PrepareTrees() override;
    void Gui() override{ TMVA::TMVARegGui( GetOutDir()+GetOutFileName(),GetName() );};

protected:
    
  private :
     
    ClassDefOverride(TrainReg1,1);  // HSMVA Signal Identification training

  }; //

} //namespace HSMVA

#endif // HSMVA_TRAINSIGNALID_h
