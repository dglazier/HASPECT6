#ifndef HSMVA_TRAINCOMPARISON_h
#define HSMVA_TRAINCOMPARISON_h

#include "TMVA/TMVAGui.h"

#include "TrainingInterface.h"

namespace HS{
  namespace MVA{
  
    class TrainComparison : public TrainingInterface{
      
    public :
      
      TrainComparison()=default;
      TrainComparison(TString name,TString opt="!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification");
      virtual ~TrainComparison()=default;
      
      void AddTree(TTree*  tree,TString v1,TString v2,TString wvar1="",TString wvar2="",Double_t weight1=1,Double_t weight2=1);
      void AddTree1(TTree*  tree,TString wvar="",Double_t weight=1);
      void AddTree2(TTree*  tree,TString wvar="",Double_t weight=1);
      void PrepareTrees() override;
      void Gui() override{ TMVA::TMVAGui( GetOutDir()+GetOutFileName(),GetName() );};
      void ChangeBranchNames(TTree* tree,TString nameold,TString namenew);
      
    protected:
      
    private :
      
      ClassDefOverride(TrainComparison,1);  // HSMVA Signal Identification training
      
    }; //
    
  } //namespace MVA
} //namespace HS
#endif // HSMVA_TRAINCOMPARISON_h
  
