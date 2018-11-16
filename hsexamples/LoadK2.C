#include <TROOT.h>

void LoadK2(){
  //HSCODE=gSystem->Getenv("HSCODE");
gROOT->ProcessLine(".x $HSCODE/hsfinalstate/LoadFinalState.C+");
/////////////////////////////////////////////////////////////
gROOT->LoadMacro("DeltaTimePCut.C+"); //ADD MY NEW CUT HERE
////////////////////////////////////////////////////////////
gROOT->LoadMacro("TreeDataK2.C+");
gROOT->LoadMacro("K2.C+");
}