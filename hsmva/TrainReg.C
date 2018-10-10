/**
	\class TrainReg
	Derived from TrainingInterface
	Used for regression tasks with 1 output (but N input variables/dimensions)
	For example
	     TrainReg train("MyMultiDimensionFunction");
	     train.IgnoreBranches("");//Any branches in tree not used must be flagged!
	     train.SetTarget("fvalue"); //function value to "fit"
            //OR train.SetTargets("tar1:tar2:tar3:..."); in case of multi-dim outputs
	     train.AddRegTree(regTree);
	     train.SetNTrainTest(5000,5000);
	     train.PrepareTrees();
	     train.BookMethod(HSMVA::Meths.MLP);
	     train.DoTraining();

	@example RunTrainReg.C 
*/

#include "TrainReg.h"

using namespace HS::MVA;

////////////////////////////////////////////////////////////
///Specific implemntation requires:
TrainReg::TrainReg(TString name,TString opt):
  TrainingInterface(name,opt)
{
  
}
void TrainReg::AddRegTree(TTree*  tree,TString wvar,Double_t weight){

  LoadTreeVars(tree);
  DataLoader()->AddRegressionTree(tree,weight);
  if(wvar!=TString(""))DataLoader()->SetWeightExpression(wvar.Data(),"Regression");

}

void TrainReg::PrepareTrees(){

  //USe same cut and same number of signal and background events
  DataLoader()->
    PrepareTrainingAndTestTree(GetCut(),Form("nTrain_Regression=%d:nTest_Regression=%d:SplitMode=Random:NormMode=NumEvents:!V",NTrain(),NTest()));
}
///////////////////////////////////////////////////////////////
///Add multiple targets via string "tar1:tar2:tar3:..."
void  TrainReg::SetTargets(TString targets){
  
  //Split the string with the variables list (v1:v2:v3:...) 
  auto bvars=targets.Tokenize(":");
  
  //Add variables from constructor list to the reader
  //And link to this fVars
  for (auto const& tar : *bvars) {
    SetTarget(tar->GetName());
  }

}
void  TrainReg::DrawTargetDeviations(){
  //train targets
  TMVA::deviations(GetName(),GetOutDir()+GetOutFileName(),TMVA::kMVAType,kTRUE);
  DrawDeviationCanvas();
}
void  TrainReg::DrawVariableDeviations(){
  //test variables
  TMVA::deviations(GetName(),GetOutDir()+GetOutFileName(),TMVA::kCompareType,kFALSE);
  DrawDeviationCanvas();

}

void  TrainReg::DrawDeviationCanvas(){
  auto clist = gROOT->GetListOfCanvases();
  std::cout << "Created  " << clist->GetSize() << " canvases with names:  " << std::endl;
  for (auto *c : *clist) { 
    if (c->IsA() == TCanvas::Class()) {
      std::cout << "--- canvas name :   " << c->GetName() << std::endl;
      c->Draw();
    }
  }

}
