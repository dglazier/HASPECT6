//root --hsfit  FitHSMCModelSavedBins.C
{
  //Perform fits on already comfigured binned data files

  THSsPlot* RF=new THSsPlot("SF");
  RF->SetOutDir("outBins2/Fits");
  // RF->SetSPlotRange(2,8);
  RF->LoadVariable("Mmiss[0.5,9.5]");//should be same name as variable in tree 
  RF->SetIDBranchName("fgID");
  RooRealVar *var=RF->GetWorkSpace()->var("Mmiss");
  var->setBins(100); 

  RF->ConfigureSavedBins("outBins2/"); 

  
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
  RF->FitSavedBins(1);
  gBenchmark->Stop("Binned");
  gBenchmark->Print("Binned");
 
   //chain deleted so recreate for extra plots  
  TChain chain2("MyModel");
  chain2.Add("Data.root");
  RF->LoadDataSet(&chain2);
 
  RF->DrawTreeVar("M1",100,0,10);
  RF->DrawTreeVar("M2",100,0,10);

  //Save merged weights
  RF->GetWeights()->Save();
}
