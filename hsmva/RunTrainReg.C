//Recast version of $ROOTSYS/tutorials/tmva/TMVARegression.C
//To run :  root  --TrainingInterface.C --TrainReg1.C RunTrainReg1.C

#include "TrainReg.h"
#include "GetTutorialFile.h"

using namespace HS::MVA;

void RunTrainReg(){
 
  auto input = GetRegressionFile();

  auto regTree = dynamic_cast<TTree*>(input->Get("TreeR"));
 
  TrainReg train("TMVARegressionTut");
  
  train.IgnoreBranches("");//Any branches in tree not used must be flagged!
  train.SetTarget("fvalue"); //function value to "fit"
  train.AddRegTree(regTree);
  train.SetNTrainTest(5000,5000);
  train.PrepareTrees();

  //Can Book methods either via standard TMVA::Factory interface...
  train.BookMethod(TMVA::Types::kBDT, "BDT","!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20");

  //..or predefined methods (See HSMVA::MethodConfigure.h)
  train.BookMethod(HS::MVA::Meths.MLP);

  train.DoTraining();


}
