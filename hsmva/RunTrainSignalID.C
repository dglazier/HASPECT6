#include "GetTutorialFile.h"
#include "TrainSignalID.h"

using namespace HS::MVA;

void RunTrainSignalID(){
 
  auto input = GetClassificationFile();

  auto *signalTree     = dynamic_cast<TTree*>(input->Get("TreeS"));
  auto *background     = dynamic_cast<TTree*>(input->Get("TreeB"));

  TrainSignalID train("TMVAClassificationTut");

  // train.SetOutDir("/work/dump/tmva/");
  train.IgnoreBranches("");//Any branches in tree not used must be flagged!
  train.AddSignalTree(signalTree);
  train.AddBackgroundTree(background);
  train.PrepareTrees();

  //Can Book methods either via standard TMVA::Factory interface...
  train.BookMethod(TMVA::Types::kBDT, "BDT","!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20");

  //..or predefined methods (See HSMVA::MethodConfigure.h)
  train.BookMethod(HS::MVA::Meths.MLP);

  train.DoTraining();
}
