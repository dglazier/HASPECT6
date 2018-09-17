/**
	\class TrainReg1
	Derived from TrainingInterface
	Used for regression tasks with 1 output (but N input variables/dimensions)
	For example
	     TrainReg1 train("MyMultiDimensionFunction");
	     train.IgnoreBranches("");//Any branches in tree not used must be flagged!
	     train.SetTarget("fvalue"); //function value to "fit"
	     train.AddRegTree(regTree);
	     train.SetNTrainTest(5000,5000);
	     train.PrepareTrees();
	     train.BookMethod(HSMVA::Meths.MLP);
	     train.DoTraining();

	@example RunTrainReg1.C 
*/

#include "TrainReg1.h"

ClassImp(HSMVA::TrainReg1);

////////////////////////////////////////////////////////////
///Specific implemntation requires:
HSMVA::TrainReg1::TrainReg1(TString name,TString opt):
  TrainingInterface(name,opt)
{
  
}
void HSMVA::TrainReg1::AddRegTree(TTree*  tree,TString wvar,Double_t weight){

  LoadTreeVars(tree);
  DataLoader()->AddRegressionTree(tree,weight);
  if(wvar!=TString(""))DataLoader()->SetWeightExpression(wvar.Data(),"Regression");

}

void HSMVA::TrainReg1::PrepareTrees(){

  //USe same cut and same number of signal and background events
  DataLoader()->
    PrepareTrainingAndTestTree(GetCut(),Form("nTrain_Regression=%d:nTest_Regression=%d:SplitMode=Random:NormMode=NumEvents:!V",NTrain(),NTest()));
}
