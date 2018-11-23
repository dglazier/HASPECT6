 {

   gROOT->ProcessLine(".x $HSEXP/LoadExperiment.C+");

   if(TString(gSystem->Getenv("ROOTBEER"))==TString("")){cout<<"No ROOTBEER defined exiting..."<<endl; exit(0);}
  TString ROOTBEER=gSystem->Getenv("ROOTBEER");
  gSystem->Load(TString(gSystem->Getenv("ROOTBEER_SLIB"))+"/libRootBeer");
  gInterpreter->AddIncludePath(ROOTBEER+"/include");
  gInterpreter->AddIncludePath(ROOTBEER+"/Experiments/");
  gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),(ROOTBEER+"/Experiments/").Data()));
  gSystem->Load(TString(gSystem->Getenv("ROOTBEER_SLIB"))+"/libeloss.so");
 
  //  gROOT->LoadMacro("$HSCODE/hsdata/LoadDataManager.C+");
   TString G8=gSystem->Getenv("G8");
   //gSystem->AddIncludePath(TString("-I")+gSystem->Getenv("ROOTBEER")+"/include");
  LoadMacro("THSRootBeer.C");
  LoadMacro("THSCLASg8.C");
 }		
