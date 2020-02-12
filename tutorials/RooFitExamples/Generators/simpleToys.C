//Run with 
//root --hsfit simpleToys.C
{
  //start with creating 1 data sample
  ToyManager toy(1);

  // TString PWD=gSystem->Getenv("PWD");
  
  //  toy.SetUp().SetOutDir(PWD+"/outSimpleToys/");
  toy.SetUp().SetOutDir("outSimpleToys/");
  ///////////////////////////////Load Variables
  toy.SetUp().LoadVariable("Mmiss[0,10]");//should be same name as variable in tree  
  toy.SetUp().SetIDBranchName("fgID");

  /////////////////////////////Make Model Signal
  toy.SetUp().FactoryPDF("Gaussian::Signal( Mmiss, SIMm[6,4,7], SIMw[0.2,0.0001,3] )");
  toy.SetUp().LoadSpeciesPDF("Signal",100);//Generate will produce 100 Signal events


  ////////////////////////////////Additional background
  toy.SetUp().FactoryPDF("Chebychev::BG(Mmiss,{a0[-0.1,-1,1],a1[0.1,-1,1]})");
  toy.SetUp().LoadSpeciesPDF("BG",50); //Geenrate will produce 50 background events

  ////////////////////////////Make Bins
  toy.Bins().LoadBinVar("Eg",5,3,4);

  //Create a sample of data
  Here::Go(&toy);

  //now create a fitter from the toymanager
  auto fit=toy.Fitter();

  //And fit the sample data
  Here::Go(fit);
  //////////////////////////////////////////////////////////////////
  
  //now create another toymanager from the results of the sample fit
  //and initialise it to create 20 toy datasets
  //Note Minuit2 comes from the default minimiser name
  auto toy2=ToyManager::GetFromFit(100,fit,"ResultsToy0HSMinuit2.root");
  //Give it a new output directory
  toy2->SetUp().SetOutDir("outSimpleToy2");
  //  toy2->SetUp().SetOutDir(PWD+"/outSimpleToy2");
  //create toy data
  Here::Go(toy2);
  //fit toy data
  //Here::Go(toy2->Fitter());
  
  //fit toy data
  Proof::Go(toy2->Fitter(),4);//or use proof with 4 workers
  //summarise, summary results will be saved to outSimpleToy2/ToySummary.root
  //  toy2->Summarise();
  
}
