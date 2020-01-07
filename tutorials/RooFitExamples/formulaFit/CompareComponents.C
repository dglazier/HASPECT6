{

  ////////////////////Components
  
  FitManager CompFit;
  CompFit.SetUp().SetOutDir("outComps/");

  CompFit.SetUp().LoadVariable("Phi[0,-10,10]");
  
  CompFit.SetUp().LoadFormula("COS2=cos(2*(@Phi[])/57.29578)");
  CompFit.SetUp().LoadFormula("SIN2=sin(2*(@Phi[])/57.29578)");
  
  CompFit.SetUp().LoadParameter("A[0,-1,1]");
 
  CompFit.SetUp().LoadParameter("B[0,-1,1]");
  CompFit.SetUp().FactoryPDF("RooComponentsPDF::COS2SIN2(1,{Phi},=A;COS2:B;SIN2)");

  CompFit.SetUp().LoadSpeciesPDF("COS2SIN2");
  

  auto pdfComp=dynamic_cast<RooHSEventsPDF*>(&CompFit.SetUp().PDFs()[0]);

  //////////////////////////////////////
  //HSEventsPdf
  Loader::Compile("PhiAsymmetryPDF.cxx");
 
  FitManager PhiAsymFit;
  PhiAsymFit.SetUp().SetOutDir("outObs/");
  ///////////////////////////////Load Variables
  PhiAsymFit.SetUp().LoadVariable("Phi[0,-10,10]");
  PhiAsymFit.SetUp().FactoryPDF("PhiAsymmetryPDF::SigAsym( Phi,A[0,-1,1],B[0,-1,1] )");
 
  PhiAsymFit.SetUp().LoadSpeciesPDF("SigAsym",1);
   
 
  auto pdfPhiAsym=dynamic_cast<RooHSEventsPDF*>(&PhiAsymFit.SetUp().PDFs()[0]);

  Long64_t NINT=100000;
  auto phiAsymSim= FiledTree::Read("ToyData","Toys/Toy0.root");
  pdfPhiAsym->SetNInt(NINT);
  pdfPhiAsym->SetEvTree(phiAsymSim->Tree().get(),PhiAsymFit.SetUp().Cut());
  auto compSim= FiledTree::Read("ToyData","Toys/Toy0.root");
  pdfComp->SetNInt(NINT);
  pdfComp->SetEvTree(compSim->Tree().get(),CompFit.SetUp().Cut());
  
     
  Double_t CompInt0=pdfComp->analyticalIntegral(1,"");
  Double_t PhiAsymInt0=pdfPhiAsym->analyticalIntegral(1,"");
  cout<<"ZERO "<< PhiAsymInt0<<" "<<CompInt0<<endl;
  TH1F* difference0=new TH1F("dif","difference original",1000,-0.1,0.1);
  TH1F* difference1=new TH1F("dif","difference cached",1000,-0.1,0.1);
  TH1F* difference2=new TH1F("dif","difference orig-cached",1000,-0.1,0.1);
  for(Int_t i=0;i<100;i++){
    Double_t A=gRandom->Uniform(-1,1);
    Double_t B=gRandom->Uniform(-1,1);
    PhiAsymFit.SetUp().SetParVal("A",A);
    PhiAsymFit.SetUp().SetParVal("B",B);
    CompFit.SetUp().SetParVal("A",A);
    CompFit.SetUp().SetParVal("B",B);
    // cout<<" A "<<A<<" B "<<B<<endl;
    cout<<"vals "<<pdfPhiAsym->getVal()<<" "<<pdfComp->getVal()<<endl;
    cout<< "ints "<<pdfPhiAsym->analyticalIntegral(1,"") /PhiAsymInt0 <<endl<<" "<<pdfComp->analyticalIntegral(1,"")/CompInt0<<endl;
    difference0->Fill(1-pdfPhiAsym->analyticalIntegral(1,""));
    difference1->Fill(1-pdfComp->analyticalIntegral(1,""));
    difference2->Fill(pdfComp->analyticalIntegral(1,"")-pdfPhiAsym->analyticalIntegral(1,""));
  }
  difference0->Draw();
  new TCanvas;
  difference1->Draw();
  new TCanvas;
  difference2->Draw();
  
}
