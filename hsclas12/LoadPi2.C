{
  gSystem->Setenv("HSFINAL","1");
  gROOT->ProcessLine(".x $HSEXP/LoadCLAS12.C+");
//gROOT->ProcessLine(".x $HSCODE/hsfinalstate/LoadFinalState.C+");
 
/////////////////////////////////////////////////////////////
gROOT->LoadMacro("DeltaTimePCut.C+"); //ADD MY NEW CUT HERE
////////////////////////////////////////////////////////////
gROOT->LoadMacro("TreeDataPi2.C+");
gROOT->LoadMacro("Pi2.C+");
}
