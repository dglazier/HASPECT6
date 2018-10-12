{
gROOT->ProcessLine(".x /scratch/dglazier/tesths/HASPECT6/hsfinalstate/LoadFinalState.C+");
/////////////////////////////////////////////////////////////
gROOT->LoadMacro("DeltaTimePCut.C+"); //ADD MY NEW CUT HERE
////////////////////////////////////////////////////////////
gROOT->LoadMacro("TreeDataPi2.C+");
gROOT->LoadMacro("Pi2.C+");
}