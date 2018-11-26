///////////////////////////////////////////////////
///run with
/// job submision script (ie script which will run on farm) 
/// e.g. setenv HS_FARMRUN $PWD/pbs_run
/// job submission type  (qsub, jsub,...)
/// e.g. setenv HS_FARMSUB qsub
/// The last argument =1 ->qsub 0 =>run local
/// root 'HSSubmitToys.C(1,1)'
void HSSubmitToys(Int_t Ntoys,Int_t toFarm=1){

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
  gSystem->Setenv("LAUNCH",TString(gSystem->Getenv("PWD")));
   for(Int_t i=0;i<Ntoys;i++){
    TString JobName=Form("Toy_%d",i);
    cout<<"sending JobName "<<JobName<< endl;
    gSystem->Setenv("JOBNAME",JobName);
    if(toFarm)
      gSystem->Exec(farmsub+" "+farmrun);
    else
      gSystem->Exec(farmrun);
    gSystem->Exec("sleep 2");
   
  }
  
}
 
