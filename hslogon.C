/*! \file
	Sets up HaSpect environment when included in .rootrc file.
	
	### Usage
	Use flags when starting root to load needed functions \n
	- \--hsfit : Classes for sWeight fits etc
	- \--hssel : Classes for hselector
	- \--hsdata : Classes for hsdata
	- \--hsfinal=MyFinalState : Classes for hsfinalstate where\n
	MyFinalState is the users own derived class
	
	e.g. 
	\code root -l --hsfit FitHSSimple.C \endcode
	to start FitHSSimple.C macro which uses sWeights to fit data.
	\code root --cleanall \endcode
	to remove all .so .d and .pcm files
	\code root RunSomeScript.C --proof=N \endcode
	to initialise a proof session with N workers
	\code root --MyClass.C \endcode
	to load your own class from current directory, or a class from HSANA or HSUSER
	
*/

#include <TProof.h> //Make sure gProof can be seen here

void HSfit();//Load hsfit classes
void HSselector(); //load hsselector classes
void startproof(Int_t Nw); //intialise proof for hsselector classes
void LoadMacro(TString macro); //Load class via its source code
TString HSin(); //return in files directory
TString HSinFile(); //return in file 
TString HSout(); //return inout files directory
TString HSfinal(); //return project classname
void HSin(TString hsin){gSystem->Setenv("HSIN",hsin);} //set in files directory
void HSout(TString hsout){gSystem->Setenv("HSOUT",hsout);} //set out file
void HSfinal(TString hsfinal){gSystem->Setenv("HSFINAL",hsfinal);} //set out file
void CleanAll();
void hsCleanData();
void hsCleanFinal();
void hsCleanHSMVA();
void hsCleanExperiments();
void HSMacPath(TString opt);
void HSUserPath(TString opt);
TString MACPATH; //additional macro path needed for proof
Bool_t gISFARM=kFALSE;
///////////////////////////////////////////////////////
///Initialises functions demanded by the user
void hslogon(){
  //Execute system .rootlogon.C script 
  if(gSystem->AccessPathName("~/.rootlogon.C")){};

  //Check if user source code directory defined
  TString HSANA=gSystem->Getenv("HSANA");
  TString HSUSER=gSystem->Getenv("HSUSER");
  TString HSCODE=gSystem->Getenv("HSCODE");
 
  if(gSystem->Getenv("HSUSER")){
    gROOT->SetMacroPath(Form("%s:%s",HSUSER.Data(),gROOT->GetMacroPath()));
    gSystem->AddIncludePath(TString("-I")+HSUSER);
  }

  //get command line options first check if makeall
  for(Int_t i=1;i<gApplication->Argc();i++){
    TString opt=gApplication->Argv(i);
    //look for --proof=Nworkers optionif Nworkers not given all cores will be used
    if((opt.Contains("--cleanall"))) CleanAll();
    if((opt.Contains("--cleandata"))) hsCleanData();
    if((opt.Contains("--cleanfinal"))) hsCleanFinal();
    if((opt.Contains("--cleanexp"))) hsCleanExperiments();
    if((opt.Contains("--cleanmva"))) hsCleanHSMVA();
    if((opt.Contains("--fortran")))  gSystem->Load("libgfortran.so");
    
  }
  //check if additional macro dir given
   for(Int_t i=1;i<gApplication->Argc();i++){
    TString opt=gApplication->Argv(i);
    //look for --proof=Nworkers optionif Nworkers not given all cores will be used
    if((opt.Contains("--macrodir"))){
      HSMacPath(TString(opt(11,opt.Sizeof())));
    }
   }

  
   //get command line options first check if proof
  for(Int_t i=1;i<gApplication->Argc();i++){
    TString opt=gApplication->Argv(i);
    //look for --proof=Nworkers optionif Nworkers not given all cores will be used
    if((opt.Contains("--proof"))) startproof(TString(opt(8,opt.Sizeof())).Atoi());
    
  }
  
  //get command line options first check if farm job
  for(Int_t i=1;i<gApplication->Argc();i++){
    TString opt=gApplication->Argv(i);
    //look for --farm and copy all hsroot files to local hsana directory
    if((opt.Contains("--farm"))){
      gISFARM=kTRUE;
      gSystem->Exec(Form("mkdir hscode"));
      gSystem->Exec(Form("cp %s/CleanAll.csh hscode/.",HSCODE.Data()));
      gSystem->Exec(Form("cp -r %s/hsdata hscode/.",HSCODE.Data()));

      //make sure hscode clean
      gSystem->Exec(Form("cd hscode/ ; ./CleanAll.csh ; cd .."));

      gSystem->Setenv("HSCODE","./hscode");
      if(gSystem->Getenv("RHIPO")){
	TString RHIPO=gSystem->Getenv("RHIPO");
	gSystem->Exec(Form("cp %s/THipo.h hscode/.",RHIPO.Data()));
	gSystem->Exec(Form("cp %s/THipo.C hscode/.",RHIPO.Data()));
	gSystem->Exec(Form("cp %s/Hipo2Root.C hscode/.",RHIPO.Data()));
	gSystem->Setenv("RHIPO","./hscode");	
      }
      if(gSystem->Getenv("CHIPO")){
	TString CHIPO=gSystem->Getenv("CHIPO");
	gSystem->Exec(Form("cp %s/*.h hscode/.",CHIPO.Data()));
	gSystem->Exec(Form("cp %s/*.cpp hscode/.",CHIPO.Data()));
	gSystem->Setenv("CHIPO","./hscode");	
      }
      gROOT->SetMacroPath(TString("hscode/:")+gROOT->GetMacroPath());
    }
  }
  
  //get command line options and call assiciated functions
  for(Int_t i=1;i<gApplication->Argc();i++){
    TString opt=gApplication->Argv(i);
    if(opt.Contains("--hsin")) {HSin(TString(opt(7,opt.Sizeof())));} //Set input tree directory
    if(opt.Contains("--hsout")) {HSout(TString(opt(8,opt.Sizeof())));} //Set input tree directory
    if((opt==TString("--hsfit"))) HSfit(); //Load fit classes
    if((opt==TString("--hssel"))) HSselector(); //Load selector classes
    if(opt.Contains("--")&&opt.Contains(".cxx")){opt.Remove(0,2); cout<<"Loading "<<opt<<endl;LoadMacro(opt);} //Load additional THS classes
    if(opt.Contains("--")&&opt.Contains(".cpp")){opt.Remove(0,2); cout<<"Loading "<<opt<<endl;LoadMacro(opt);} //Load additional THS classes
    if(opt.Contains("--")&&opt.Contains(".C")){opt.Remove(0,2); cout<<"Loading "<<opt<<endl;LoadMacro(opt);} //Load additional THS classes
    if(opt.Contains("--")&&opt.Contains(".cc")){opt.Remove(0,2); cout<<"Loading "<<opt<<endl;LoadMacro(opt);} //Load additional THS classes
    
  }	
  
}


void hsCleanExperiments(){gROOT->ProcessLine(".x $HSCODE/hsexperiments/CleanExperiments.C+");}
void hsCleanData(){ gROOT->ProcessLine(".x $HSCODE/hsdata/CleanData.C+");}
void hsCleanFinal(){ gROOT->ProcessLine(".x $HSCODE/hsfinalstate/CleanFinalState.C+");}
void hsCleanHSMVA(){ gROOT->ProcessLine(".x $HSCODE/hsmva/CleanHSMVA.C+");}

void CleanAll(){
  hsCleanExperiments();
  hsCleanData();
}

/** Function is called with \--hsfit \n
 * It loads necessary functions to perform RooFit/RooStats fits:\n
 * THSBins.C
 * THSWeights.C
 * RooHSEventsPDF.C
 * RooHSEventsHistPDF.C
 * THSRooFit.C
 * THSsPlot.C
 * RooHS1StepStudy.C
 * RooHSsPlotAndFitStudy.C
 * RooHSStudyManager.C
 */
void HSfit(){
  cout<<"Loading HSFit classes"<<endl;
  //set prompt
  if(!gProof)((TRint*)gROOT->GetApplication())->SetPrompt("hsroot [%d] ");
  //Load extra classes for roofit
  LoadMacro("THSBins.C"); 
  LoadMacro("THSWeights.C");
  LoadMacro("RooHSEventsPDF.C");
  LoadMacro("RooHSEventsHistPDF.C");
  LoadMacro("HSMCMC.C");
  LoadMacro("THSRooFit.C");
  LoadMacro("THSsPlot.C");
  LoadMacro("RooHS1StepStudy.C");
  LoadMacro("RooHSsPlotAndFitStudy.C");
  LoadMacro("RooHSStudyManager.C");
}

/** Function is called with \--hssel \n
 * It loads the following functions:\n
 * THSBins.C
 * THSWeights.C
 * THSHisto.C
 * THSOutput.C
 * THSSkeleton.C
 * THSKinematics.C
 * THSParticle.C (unless explicitly replaced)
 */
void HSselector(){
  cout<<"Loading HSSel classes"<<endl;
 //set prompt
  if(!gProof)((TRint*)gROOT->GetApplication())->SetPrompt("hsroot [%d] ");
   //Load classess for selector analysis
  //particle container class
  LoadMacro("THSBins.C");
  LoadMacro("THSWeights.C");
  LoadMacro("THSHisto.C");
  LoadMacro("THSOutput.C");
  LoadMacro("THSSkeleton.C");
  LoadMacro("THSKinematics.C");
}

//////////////////////////////////
/// Start proof with Nw workers
void startproof(Int_t Nw){
  cout<<"Loading Proof setup"<<endl;
  //set prompt
  ((TRint*)gROOT->GetApplication())->SetPrompt("hsproof [%d] ");
  TProof::Open("://lite");
  if(Nw) gProof->SetParallel(Nw); //set number of workers if specified on command line
}


void LoadMacro(TString macro){
  //Different methods depending on whether proof or not
  TString PWD=gSystem->Getenv("PWD");
  TString HSANA=gSystem->Getenv("HSANA");
  TString HSUSER=gSystem->Getenv("HSUSER");
  //if(gHSMacroList->FindObject(macro)) return; //already loaded
  //  gHSMacroList->Add(new TNamed(macro,macro));
  cout<<"Loading hsmacro "<<macro<<endl;
  if(gProof) {
    if(gSystem->Which("./",macro)){
      macro=PWD+"/"+macro+"+"; //needs to compile to prevent warnings
    }	
    else if(gSystem->Which(HSUSER,macro)){
      macro=HSUSER+"/"+macro;
    }
    else  if(gSystem->Which(MACPATH,macro)){
      macro=MACPATH+"/"+macro;
    }
    else  if(gSystem->Which(HSANA,macro)){
      macro=HSANA+"/"+macro;
    }
    else {cout<<"Can't find macro "<<macro<<endl; return;}
    gProof->Load(macro+"+");
  }
  else gROOT->LoadMacro(macro+"+");//don't use HSANA in case want to overwrite with macro in current directory

 }

//////////////////////////////////////////
/// Checks for and returns HSPROJ variable
TString HSfinal(){
  if(!gSystem->Getenv("HSFINAL")) cout<<"Warning no HSFINAL env variable defined but hsfinal() called..."<<endl;
  return TString(gSystem->Getenv("HSFINAL"));
}

//////////////////////////////////////////
/// Checks for and returns HSIN variable
TString HSin(){
  if(!gSystem->Getenv("HSIN")) cout<<"Warning no HSIN env variable defined but hsin() called..."<<endl;
  return TString(gSystem->Getenv("HSIN"))+"/";
}
//////////////////////////////////////////
/// Checks for and returns HSIN variable don't add /
TString HSinFile(){
  if(!gSystem->Getenv("HSIN")) cout<<"Warning no HSIN env variable defined but hsin() called..."<<endl;
  return TString(gSystem->Getenv("HSIN"));
}

//////////////////////////////////////////
/// Checks for and returns HSOUT variable
TString HSout(){
  if(!gSystem->Getenv("HSOUT")) cout<<"Warning no HSOUT env variable defined but hsout() called..."<<endl;
  if(gProof) cout<<"Warning : Using proof so need full path to output"<<endl;
  return gSystem->Getenv("HSOUT");
}

/////////////////////////////////////////
/// Adds opt to MACPATH (macro path)
void HSMacPath(TString opt){
  cout<<"Adding Macro Path "<<opt<<endl;
  MACPATH=opt;
  gROOT->SetMacroPath(Form("%s:%s",gROOT->GetMacroPath(),MACPATH.Data()));
  gSystem->AddIncludePath(TString("-I")+MACPATH);
}
