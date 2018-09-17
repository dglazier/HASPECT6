{
  TString HSCODE=gSystem->Getenv("HSCODE");
  TString mvapath="/hsmva";
  
  gInterpreter->AddIncludePath(HSCODE+mvapath);
  gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(HSCODE+mvapath).Data()));
 
  gROOT->LoadMacro("TrainingInterface.C+");
  gROOT->LoadMacro("TrainSignalID.C+");
  gROOT->LoadMacro("TrainReg1.C+");
  gROOT->LoadMacro("ResultInterface.C+");
  gROOT->LoadMacro("ResultSignalID.C+");
  gROOT->LoadMacro("ResultReg1.C+");


}
