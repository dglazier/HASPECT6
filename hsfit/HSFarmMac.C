{
  
  //Get the outpur directory where HSFit.root should reside
  TString outdir=gSystem->Getenv("HS_OUTDIR");
  //  TString outdirstr=TString(outdir->GetTitle());
  if(outdir!=TString(""))
    outdir.Append('/');


  cout<<"GET FITMANAGER "<<endl;
  //Get the fitmanager
  fitFile=TFile::Open(outdir+"HSFit.root");

  TList* compMacros=dynamic_cast<TList*>( fitFile->Get("HS_COMPILEDMACROS"));
  //Load macros to be compiled, may be needed for FitManager Pdfs
  Loader::CompileHere(compMacros);

  fitManager=dynamic_cast<FitManager*>( fitFile->Get("HSFit")->Clone() );

  cout<<"GOT FITMANAGER "<<endl;
  //Get the minimiser
  if(fitManager->GetMinimiserType()!=TString())
    fitManager->SetMinimiser(std::move(dynamic_cast<Minimiser*>( fitFile->Get(fitManager->GetMinimiserType())->Clone() )));
  
  delete fitFile; //close file to stop memory resident issue!



  //configure fit manager data
  fitManager->Data().LoadSetup(&fitManager->SetUp());

  //run fit
  TString fitNumber=gSystem->Getenv("HS_JOBNUMBER");
  fitManager->RunOne(fitNumber.Atoi());


}
