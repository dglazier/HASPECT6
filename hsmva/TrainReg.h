#ifndef HSMVA_TRAINREG_h
#define HSMVA_TRAINREG_h

#include <TMVA/TMVARegGui.h>
#include <TMVA/deviations.h>

#include "FiledTree.h"
#include "TrainingInterface.h"

namespace HS{
  namespace MVA{
  
    class TrainReg : public TrainingInterface{

    public :
      
      TrainReg()=default;
      TrainReg(TString name,TString opt="!V:!Silent:Color:DrawProgressBar:AnalysisType=Regression");
      virtual ~TrainReg()=default;
      
      void AddRegTree(TTree*  tree,TString wvar="",Double_t weight=1);
      void AddRegTree(ttree_ptr tree,TString wvar="",Double_t weight=1){
	AddRegTree(tree.get(),wvar,weight);
      }
      void SetTarget(TString tar){IgnoreBranches(tar); DataLoader()->AddTarget(tar);}
      void SetTargets(TString tars);
      
      void PrepareTrees() override;
      void Gui() override{ TMVA::TMVARegGui( GetOutDir()+GetOutFileName(),GetName() );};

									     
      void DrawTargetDeviations();
      void DrawVariableDeviations();
      void  DrawDeviationCanvas();
      
    protected:
      
    private :
      
      ClassDefOverride(TrainReg,1);  // HSMVA Signal Identification training
      
    }; //

  } //namespace MVA
}//namespace HS
#endif // HSMVA_TRAINSIGNALID_h
