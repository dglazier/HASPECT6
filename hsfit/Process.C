#include "Process.h"
#include <TString.h>
#include <TSystem.h>

namespace HS{
  namespace FIT{
    namespace PROCESS{
      

      ////////////////////////////////////////////////////////
      ///Send jobs to Farm needs env variables
      /// e.g. setenv HS_FARMRUN $PWD/pbs_run
      /// e.g. setenv HS_FARMSUB qsub
      /// e.g. setenv HS_RUNMAC FitMac.C  
      void Farm::Go(FitManager* fm,Bool_t toFarm){

	if(!fm) return;
	fm->SetCompiledMacros(gCompilesList);
	fm->WriteThis();
	auto Njobs=fm->GetN();

	//Look for env variable RUNMAC for job macro 
	TString farmmac;
	if(gSystem->Getenv("HS_RUNMAC"))
	  std::cout<<"Going to run macro "<<gSystem->Getenv("HS_RUNMAC")<<endl;
	else{
	  gSystem->Setenv("HS_RUNMAC",Form("%s/hsfit/HSFarmMac.C",gSystem->Getenv("HSCODE")));
	  std::cout<<"Going to run macro "<<gSystem->Getenv("HS_RUNMAC")<<endl;
	}

	//Look for env variable FARMRUN for job submission script 
	TString farmrun;
	if(gSystem->Getenv("HS_FARMRUN"))
	  farmrun=gSystem->Getenv("HS_FARMRUN");
	else
	  farmrun="./pbs_run";

	//Look for variable FARMSUBMIT
	TString farmsub;
	if(gSystem->Getenv("HS_FARMSUBMIT"))
	  farmsub=gSystem->Getenv("HS_FARMSUBMIT");
	else
	  farmsub="qsub";

	//create a farm job for each toy requested    
	gSystem->Setenv("HS_LAUNCH",TString(gSystem->Getenv("PWD")));
	gSystem->Setenv("HS_OUTDIR",fm->SetUp().GetOutDir());
	gSystem->Setenv("HS_JOBNAME",fm->GetName());
	
	for(Int_t i=0;i<Njobs;i++){
	  TString JobNumber=Form("%d",i);
	  cout<<"sending JobNumber "<<JobNumber<< endl;
	  gSystem->Setenv("HS_JOBNUMBER",JobNumber);
	  if(toFarm)
	    gSystem->Exec(farmsub+" "+farmrun);
	  else
	    gSystem->Exec(farmrun);

	  
 	}
      }//Go
      
    }//PROCESS
  }//FIT
}//HS
