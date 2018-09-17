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

ClassImp(HSMVA::TrainSignalID);

////////////////////////////////////////////////////////////
///Specific implemntation requires:
HSMVA::TrainSignalID::TrainSignalID(TString name,TString opt):
  TrainingInterface(name,opt)
{
  
}
void HSMVA::TrainSignalID::AddSignalTree(TTree*  tree,TString wvar,Double_t weight){

  LoadTreeVars(tree);
  DataLoader()->AddSignalTree(tree,weight);
  if(wvar!=TString(""))DataLoader()->SetSignalWeightExpression(wvar.Data());

}
void HSMVA::TrainSignalID::AddBackgroundTree(TTree*  tree,TString wvar,Double_t weight){

  if(!AreVarsLoaded()) Warning("HSMVA::TrainSignalID::AddBackgroundTree","Must add signal tree first!");
  DataLoader()->AddBackgroundTree(tree,weight);
  if(wvar!=TString("")) DataLoader()->SetBackgroundWeightExpression(wvar.Data());
}

void HSMVA::TrainSignalID::PrepareTrees(){

  //USe same cut and same number of signal and background events
  DataLoader()->
    PrepareTrainingAndTestTree(GetCut(),
			       NTrain(),NTrain(),NTest(),NTest(),
			       "SplitMode=Random:NormMode=NumEvents:!V" );
}
