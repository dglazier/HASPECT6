{
  //gROOT->ProcessLine(".x $HSCODE/hsfit/LoadHSFit.C+");

  HSsPlot* RF=new HSsPlot("SF");
  RF->SetOutDir("out/");
  ///////////////////////////////Load Variables
  RF->LoadVariable("MesonMass[0.99,1.1]");//should be same name as variable in tree
  RooRealVar * var=RF->GetWorkSpace()->var("MesonMass");
  var->setBins(400); //number of bins used in PDF histogram

  // RF->LoadAuxVars("MissMass2[-2,2]");//Not to be fitted but limits applied to dataset
  //RF->LoadAuxVars("Pol[0.1,0.99]");//Not to be fitted but limits applied to dataset

   RF->LoadAuxVars("Eg[1.7,1.9]");//Not to be fitted but limits applied to dataset
  RF->LoadAuxVars("MLP[0.98,1]");//Not to be fitted but limits applied to dataset
  RF->LoadAuxVars("Topo[0.5,1.5]");//Not to be fitted but limits applied to dataset
  //RF->AddCut("Topo==1&&MLP>0.98");

   RF->Factory("RooHSEventsHistPDF::Phi(MesonMass,alpha[0,0,0.1],off[0,-0.05,0.05],scale[1,0.9,1.1])");
 RooHSEventsHistPDF* pdf=dynamic_cast<RooHSEventsHistPDF*>(RF->GetWorkSpace()->pdf("Phi"));

 TChain *chainmc=new TChain("newtree","mcsignal");
 chainmc->Add("/work/g8dump/hsexamples/converttestmvamlpinc2_sim.root");
 //chainmc->LoadTree(0);
  //chainmc->SetEntries();
  pdf->SetEvTree(chainmc,RF->GetCut());

  RF->LoadSpeciesPDF("Phi",1);

  RF->Factory("Chebychev::BG(MesonMass,{a0[-0.1,-1,1],a1[0.1,-1,1]})");
  RF->LoadSpeciesPDF("BG");

  //auto dfile=new TFile("/work/g8dump/hsexamples/testmvamlpinc2.root");
 auto dfile=new TFile("/work/g8dump/hsexamples/converttestmvamlpinc2.root");
 auto dtree=(TTree*)dfile->Get("newtree");
 //dtree->SetEntries(5E6);
 // dtree->SetMakeClass(1);
 RF->SetIDBranchName("UID");
 RF->LoadDataSet(dtree);


  RF->AddGausConstraint(pdf->AlphaConstraint());
  RF->AddGausConstraint(pdf->OffConstraint());
  RF->AddGausConstraint(pdf->ScaleConstraint());
 RF->TotalPDF();
 RF->PlotDataModel();

 RF->RunAFit(1);
 ///RF->PlotDataModel();

//  TCanvas cc;
// pdf->GetRootHist()->Draw("col1");
// cc.Draw();


 delete dtree;
}
