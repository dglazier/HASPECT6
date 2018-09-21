
#include "TrainComparison.h"
#include "GetTutorialFile.h"

using namespace HSMVA;

void RunTrainComparison(){
  gROOT->LoadMacro("GetTutorialFile.C");

  auto input = GetClassificationFile();

  auto *signalTree     = dynamic_cast<TTree*>(input->Get("TreeS"));
  auto *background     = dynamic_cast<TTree*>(input->Get("TreeB"));

  TrainComparison train("Comparison");

  train.SetOutDir("/work/dump/tmva/");
  train.IgnoreBranches("");//Any branches in tree not used must be flagged!
  train.AddTree1(signalTree);
  train.AddTree2(background);
  train.PrepareTrees();

  //Can Book methods either via standard TMVA::Factory interface...
  train.BookMethod(TMVA::Types::kBDT, "BDT","!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20");


  train.DoTraining();
}
