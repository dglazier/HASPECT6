/**
	\class TrainSignalID
	Derived from TrainingInterface
	Used for classifying signal and background events
	For example

	     TrainSignalID train("MySigBGSelection");
	     // train.SetOutDir("/a/directory");
	     train.IgnoreBranches("");//Any branches in tree not used must be flagged!
	     train.AddSignalTree(signalTree);
	     train.AddBackgroundTree(background);
	     train.PrepareTrees();
	     train.BookMethod(HSMVA::Meths.MLP); //Predefined MLP mode see ModelConfigs.h
	     train.DoTraining();

	@example RunTrainReg1.C 
**/

#include "TrainSignalID.h"

using namespace HS::MVA;

////////////////////////////////////////////////////////////
///Specific implemntation requires:
TrainSignalID::TrainSignalID(TString name,TString opt):
  TrainingInterface(name,opt)
{
  
}
void TrainSignalID::AddSignalTree(TTree*  tree,TString wvar,Double_t weight){

  LoadTreeVars(tree);
  DataLoader()->AddSignalTree(tree,weight);
  if(wvar!=TString(""))DataLoader()->SetSignalWeightExpression(wvar.Data());
  //Only add events with non-zero weight. 0 weights would not contribute
  if(wvar!=TString(""))DataLoader()->AddCut(wvar+"!=0","Signal");

}
void TrainSignalID::AddBackgroundTree(TTree*  tree,TString wvar,Double_t weight){

  if(!AreVarsLoaded()) Warning("TrainSignalID::AddBackgroundTree","Must add signal tree first!");
  DataLoader()->AddBackgroundTree(tree,weight);
  if(wvar!=TString("")) DataLoader()->SetBackgroundWeightExpression(wvar.Data());
  //Only add events with non-zero weight. 0 weights would not contribute
  if(wvar!=TString(""))DataLoader()->AddCut(wvar+"!=0","Background");
}

void TrainSignalID::PrepareTrees(){

  //USe same cut and same number of signal and background events
  DataLoader()->
    PrepareTrainingAndTestTree(GetCut(),
			       NTrain(),NTrain(),NTest(),NTest(),
			       "SplitMode=Random:NormMode=NumEvents:!V" );
}
void  TrainSignalID::DrawResponses(){
  TMVA::mvas(GetName(),GetOutDir()+GetOutFileName(),TMVA::kCompareType);
  auto clist = gROOT->GetListOfCanvases();
  std::cout << "Created  " << clist->GetSize() << " canvases with names:  " << std::endl;
  for (auto *c : *clist) { 
    if (c->IsA() == TCanvas::Class()) {
      std::cout << "--- canvas name :   " << c->GetName() << std::endl;
      c->Draw();
    }
  }
}
