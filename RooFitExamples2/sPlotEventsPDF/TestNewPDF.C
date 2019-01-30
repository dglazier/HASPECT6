{


  THSsPlot* RF=new THSsPlot("SF");
  RF->SetOutDir("outBins/");
  //  RF->SetWithConstraints(); //Use Gaussian contraints on alpha,off,scale
  ///////////////////////////////Load Variables
  RF->LoadVariable("Mmiss[0,9.5]");//should be same name as variable in tree 
  RF->LoadAuxVars("Eg[3,3.1]");//should be same name as variable in tree 
  RooRealVar * var=RF->GetWorkSpace()->var("Mmiss");
  var->setBins(100); 

  RF->Factory("RooHSEventsHistPDF::Sig(Mmiss,alpha[0,0,20],off[0,-2,2],scale[1,0.8,1.2])");
  RooHSEventsHistPDF* pdf=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("Sig"));
  TChain *chainmc=new TChain("MyModel","mcsignal");
  chainmc->Add("SigData.root");
  pdf->SetEvTree(chainmc);
  RF->LoadSpeciesPDF("Sig",1);

  RF->Factory("RooHSEventsHistPDF::BG(Mmiss,alphaB[0,0,5],offB[0,0,0],scaleB[1.0,0.8,1.2])");
  RooHSEventsHistPDF* pdfb=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("BG"));
  TChain *chainmcb=new TChain("MyModel","mcbackground");
  chainmcb->Add("BGData.root");
  pdfb->SetEvTree(chainmcb);
  RF->LoadSpeciesPDF("BG",1);

 TChain chain("MyModel");
  chain.AddFile("Data.root");
  RF->SetIDBranchName("fgID");
  //import to RooFit
  RF->LoadDataSet(&chain);
  gBenchmark->Start("Binned");
  // RF->TotalPDF();
  RF->AddGausConstraint(pdf->AlphaConstraint());
  RF->AddGausConstraint(pdf->OffConstraint());
  RF->AddGausConstraint(pdf->ScaleConstraint());
  RF->AddGausConstraint(pdfb->AlphaConstraint());
  RF->AddGausConstraint(pdfb->OffConstraint());
  RF->AddGausConstraint(pdfb->ScaleConstraint());
  //RF->FitMany(1);
  RF->RunWeights(1);
  // gBenchmark->Stop("Binned");
  // gBenchmark->Print("Binned");
  RF->DrawTreeVar("Mmiss",100,0,10);
  RF->DrawTreeVar("M1",100,0,10);
  RF->DrawTreeVar("M2",100,0,10);
 




}
