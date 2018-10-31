{
  if(!gSystem->Load("liblz4")){
    //Found liblz4 in LD_LIBRARY_PATH 
    gROOT->ProcessLine("#define __LZ4__");
    gSystem->AddIncludePath("-D__LZ4__");
    gSystem->AddIncludePath(TString("-I")+gSystem->Getenv("LZ4_h"));
  }
  else{
    printf("\n   >>>>> LZ4 compression is not supported.");
    printf("\n   >>>>> check if libz4 is installed on your system.");  
    printf("\n   >>>>> and included in LD_LIBRARY_PATH");  
  }

  if(gSystem->Getenv("CHIPO")){
    TString chipo=gSystem->Getenv("CHIPO");
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),chipo.Data()));
    gSystem->AddIncludePath(TString("-I")+chipo);
  }
  if(gSystem->Getenv("RHIPO")){
    TString rhipo=gSystem->Getenv("RHIPO");
    gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),rhipo.Data()));
    gSystem->AddIncludePath(TString("-I")+rhipo);
  }

  gROOT->LoadMacro("utils.cpp+");
  gROOT->LoadMacro("dictionary.cpp+");
  gROOT->LoadMacro("node.cpp+");
  gROOT->LoadMacro("event.cpp+");
  gROOT->LoadMacro("record.cpp+");
  gROOT->LoadMacro("reader.cpp+");
  gROOT->LoadMacro("THipo.C+");
}
