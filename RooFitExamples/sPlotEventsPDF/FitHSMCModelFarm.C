//root --hsfit  FitHSMCModelFarm.C
{
  //Perform fits on already comfigured binned data files
  TString job=gSystem->Getenv("JOBNAME");
  TString fileDir=gSystem->Getenv("FILEDIR");
  THSsPlot* RF=new THSsPlot(job);

  RF->LoadVariable("Mmiss[0.5,9.5]");//should be same name as variable in tree 
  RF->SetIDBranchName("fgID");
  RooRealVar *var=RF->GetWorkSpace()->var("Mmiss");
  var->setBins(100); 

  RF->SetBinDir(fileDir+"/"+job); 

  
  RF->Factory("RooHSEventsHistPDF::Sig(Mmiss,alpha[0,0,2],off[0,-2,2],scale[1,0.8,1.2])");
  RooHSEventsHistPDF* pdf=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("Sig"));
  RF->LoadSpeciesPDF("Sig",1);

  RF->Factory("RooHSEventsHistPDF::BG(Mmiss,alphaB[0,0,5],offB[0,0,0],scaleB[1,0.9,1.2])");
  RooHSEventsHistPDF* pdfb=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("BG"));
  RF->LoadSpeciesPDF("BG",1);
  
  gBenchmark->Start("Binned");
  RF->AddGausConstraint(pdf->AlphaConstraint());
  RF->AddGausConstraint(pdf->OffConstraint());
  RF->AddGausConstraint(pdf->ScaleConstraint());
  RF->AddGausConstraint(pdfb->AlphaConstraint());
  RF->AddGausConstraint(pdfb->OffConstraint());
  RF->AddGausConstraint(pdfb->ScaleConstraint());
  RF->FitBatchBin(1);
  gBenchmark->Stop("Binned");
  gBenchmark->Print("Binned");
  // RF->DrawTreeVar("Mmiss",100,0,10);
  // RF->DrawTreeVar("M1",100,0,10);
  // RF->DrawTreeVar("M2",100,0,10);


}
