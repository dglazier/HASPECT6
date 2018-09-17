#ifndef HSMVA_TRAINSIGNALID_h
#define HSMVA_TRAINSIGNALID_h

#include "TMVA/TMVAGui.h"

#include "TrainingInterface.h"

namespace HSMVA{
  
  class TrainSignalID : public TrainingInterface{

  public :
    
    TrainSignalID()=default;
    TrainSignalID(TString name,TString opt="!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification");
    virtual ~TrainSignalID()=default;
  
    void AddSignalTree(TTree*  tree,TString wvar="",Double_t weight=1);
    void AddBackgroundTree(TTree*  tree,TString wvar="",Double_t weight=1);
    void PrepareTrees() override;
    void Gui() override{ TMVA::TMVAGui( GetOutDir()+GetOutFileName(),GetName() );};
 
  protected:
    
  private :
     
    ClassDefOverride(TrainSignalID,1);  // HSMVA Signal Identification training

  }; //

} //namespace HSMVA

#endif // HSMVA_TRAINSIGNALID_h
