/**
	\class TrainComparison
	Derived from TrainingInterface
	Used for comparind 2 data distributions
	For example

	     TrainComparison train("MySigBGSelection");
	     // train.SetOutDir("/a/directory");
	     train.IgnoreBranches("");//Any branches in tree not used must be flagged!
	     train.AddSignalTree(signalTree);
	     train.AddBackgroundTree(background);
	     train.PrepareTrees();
	     train.BookMethod(HSMVA::Meths.MLP); //Predefined MLP mode see ModelConfigs.h
	     train.DoTraining();

	@example RunTrainReg1.C 
**/

#include "TrainComparison.h"

ClassImp(HSMVA::TrainComparison);

using namespace HSMVA;

////////////////////////////////////////////////////////////
///Specific implemntation requires:
TrainComparison::TrainComparison(TString name,TString opt):
  TrainingInterface(name,opt)
{
  
}
////////////////////////////////////////////////////////////////////////
///If you have 1 tree and want to compare different branches use this
void TrainComparison::AddTree(TTree*  tree,TString v1,TString v2,TString wvar1,TString wvar2,Double_t weight1,Double_t weight2){

  //Turn on branches for distribution1
  OnlyTheseBranches(tree,v1);
  
  //Load these variabes to DataLoader
  //Other distribition will need to change branchnames to match these
  AddTree1(tree,wvar1,weight1);

  //Now make a clone of tree and change branch names to match Tree1
  OnlyTheseBranches(tree,v2);
  auto tree2 = tree->CloneTree();
  ChangeBranchNames(tree2,v2,v1);
  tree2->SetName(TString("other")+tree2->GetName());
  tree2->Print();
  //Load the cloned tree to dataloader
  AddTree2(tree2,wvar2,weight2);

}
////////////////////////////////////////////////////////////////////
/// Change names of branches listed in nameold("v1:v2:v3....")
/// with those listed in namenew ("n1:n2:n3:...")
void TrainComparison::ChangeBranchNames(TTree* tree,TString nameold,TString namenew){
  cout<<"TrainComparison::ChangeBranchNames replacing "<<nameold <<" with "<<namenew<<endl; 
  auto bold=nameold.Tokenize(":");
  auto bnew=namenew.Tokenize(":");
  for(Int_t i=0;i<bold->GetEntries();i++){
    TString bname=bold->At(i)->GetName();
    cout<<"old name "<<bname<<endl;
    TBranch* branch=tree->GetBranch(bname);
    cout<<"branch "<<branch<<" "<<bnew->At(i)<<endl;
    branch->SetName(bnew->At(i)->GetName());
    TString title=branch->GetTitle();
    title.ReplaceAll(bname,bnew->At(i)->GetName());
    branch->SetTitle(title);
  }
}
///////////////////////////////////////////////////////////
///If you have 2 trees with same branches you can use these
void TrainComparison::AddTree1(TTree*  tree,TString wvar,Double_t weight){

  LoadTreeVars(tree);
  DataLoader()->AddSignalTree(tree,weight);
  if(wvar!=TString(""))DataLoader()->SetSignalWeightExpression(wvar.Data());

}
///////////////////////////////////////////////////////////
///If you have 2 trees with same branches you can use these
void TrainComparison::AddTree2(TTree*  tree,TString wvar,Double_t weight){

  if(!AreVarsLoaded()) Warning("HSMVA::TrainComparison::AddBackgroundTree","Must add signal tree first!");
  DataLoader()->AddBackgroundTree(tree,weight);
  if(wvar!=TString("")) DataLoader()->SetBackgroundWeightExpression(wvar.Data());
}

void HSMVA::TrainComparison::PrepareTrees(){

  //USe same cut and same number of signal and background events
  DataLoader()->
    PrepareTrainingAndTestTree(GetCut(),
			       NTrain(),NTrain(),NTest(),NTest(),
			       "SplitMode=Random:NormMode=NumEvents:!V" );
}
