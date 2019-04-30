#ifndef HSMVA_TRAINSIGNALID_h
#define HSMVA_TRAINSIGNALID_h

#include <TMVA/TMVAGui.h>
#include <TCanvas.h>

#include "FiledTree.h"
#include "TrainingInterface.h"

namespace HS{
  namespace MVA{
  
    class TrainSignalID : public TrainingInterface{

    public :
      
      TrainSignalID()=default;
      TrainSignalID(TString name,TString opt="!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification");
      virtual ~TrainSignalID()=default;
      
      void AddSignalTree(TTree*  tree,TString wvar="",Double_t weight=1);
      void AddBackgroundTree(TTree*  tree,TString wvar="",Double_t weight=1);
      void AddSignalTree(ttree_ptr  tree,TString wvar="",Double_t weight=1){
	AddSignalTree(tree.get(),wvar,weight);
      }
      void AddBackgroundTree(ttree_ptr  tree,TString wvar="",Double_t weight=1){
	AddBackgroundTree(tree.get(),wvar,weight);
      }
      void PrepareTrees() override;
      void Gui() override{ TMVA::TMVAGui( GetOutDir()+GetOutFileName(),GetName() );};
      
      TCanvas* DrawROCCurve(){
	DrawResponses();
	TCanvas* can= Factory()->GetROCCurve(DataLoader());
	can->SetName("ROCCan");
	can->Draw();
	return std::move(can);
      }
      void DrawResponses();
      
      std::vector<TCanvas*> GetCanvases(){return fCanvases;}
    protected:
      
    private :

      std::vector<TCanvas*> fCanvases;
      
      ClassDefOverride(TrainSignalID,1);  // HSMVA Signal Identification training
      
    }; //
    
  } //namespace MVA
} //namespace HS
#endif // HSMVA_TRAINSIGNALID_h
