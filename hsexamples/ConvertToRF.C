#include <TTree.h>
#include <TFile.h>
#include "TreeDataK2.h"

void ConvertToRF(TTree* tree,TString outname){
  //Take a tree with branches and convert
  //to just leafs (i.e. split objects directly)
  auto outfile=new TFile(outname,"recreate");

  TTree *newtree=new TTree("newtree","newtree");

  Double_t MissMass=0;
  newtree->Branch("MissMass",&MissMass,"MissMass/D");
  Double_t MissMass2=0;
  newtree->Branch("MissMass2",&MissMass2,"MissMass2/D");
  
  Double_t MesonMass=0;
  newtree->Branch("MesonMass",&MesonMass,"MesonMass/D");
  Double_t HyperonMass=0;
  newtree->Branch("HyperonMass",&HyperonMass,"HyperonMass/D");
  
  Double_t MesonCosTh=0;
  newtree->Branch("MesonCosTh",&MesonCosTh,"MesonCosTh/D");
   Double_t MesonPhi=0;
   newtree->Branch("MesonPhi",&MesonPhi,"MesonPhi/D");
   Double_t HyperonCosTh=0;
   newtree->Branch("HyperonCosTh",&HyperonCosTh,"HyperonCosTh/D");
   Double_t HyperonPhi=0;
   newtree->Branch("HyperonPhi",&HyperonPhi,"HyperonPhi/D");
   Double_t Eg=0;
   newtree->Branch("Eg",&Eg,"Eg/D");
   Double_t t=0;
   newtree->Branch("t",&t,"t/D");
   
  Double_t HelCosTh=0;
  newtree->Branch("HelCosTh",&HelCosTh,"HelCosTh/D");
  Double_t HelPhi=0;;
  newtree->Branch("HelPhi",&HelPhi,"HelPhi/D");
   
  
   Double_t Pol=0;
   newtree->Branch("Pol",&Pol,"Pol/D");
   Int_t PolState=0;
   newtree->Branch("PolState",&PolState,"PolState/I");

     

   Int_t TopoID=0;
   newtree->Branch("Topo",&TopoID,"Topo/I");
   Int_t Correct=0;
   newtree->Branch("Correct",&Correct,"Correct/I");
   Int_t NPerm=0;
   newtree->Branch("NPerm",&NPerm,"NPerm/I");
   Int_t NDet=0;
   newtree->Branch("NDet",&NDet,"NDet/I");
   Double_t MLP=0;
   newtree->Branch("MLP",&MLP,"MLP/D");
   Double_t UID=0;
   newtree->Branch("UID",&UID,"UID/D");


  
   Double_t MissMass0=0;
   Double_t MissMass20=0;
  
   Double_t MesonMass0=0;
   Double_t HyperonMass0=0;
   
   Double_t MesonCosTh0=0;
   Double_t MesonPhi0=0;
   Double_t HyperonCosTh0=0;
   Double_t HyperonPhi0=0;
   Double_t Eg0=0;
   Double_t t0=0;
   Double_t Pol0=0;
   Int_t PolState0=0;

   Double_t HelCosTh0=0;
   Double_t HelPhi0=0;
   Int_t TopoID0=0;
   Int_t Correct0=0;
   Int_t NPerm0=0;
   Int_t NDet0=0;
   Float_t MLP0=0;
   Double_t UID0=0;
 
   //   tree->SetBranchAddress("MissMass",&MissMass0);
   // tree->SetBranchAddress("",&MissMass20);
   // tree->SetBranchAddress("",&MesonMass0);
   // tree->SetBranchAddress("",&MesonCosTh0);
   // tree->SetBranchAddress("",&MesonPhi0);
   // tree->SetBranchAddress("",&HyperonCosTh0);
   // tree->SetBranchAddress("",&HyperonPhi0);
   // tree->SetBranchAddress("",&Eg0);
   // tree->SetBranchAddress("",&t0);
   // tree->SetBranchAddress("",&Pol0);
   // tree->SetBranchAddress("",&PolState0);
   // tree->SetBranchAddress("",&HelCosTh0);
   // tree->SetBranchAddress("",&HelPhi0);
   TreeDataK2* td=0;
   tree->SetBranchAddress("TreeDataK2",&td);
 
   tree->SetBranchAddress("Topo",&TopoID0);
   tree->SetBranchAddress("Correct",&Correct0);
   tree->SetBranchAddress("NPerm",&NPerm0);
   tree->SetBranchAddress("NDet",&NDet0);
   tree->SetBranchAddress("MLP",&MLP0);
   tree->SetBranchAddress("UID",&UID0);
  
   auto leaves=tree->GetListOfLeaves();
   for(Long64_t entry=0;entry<tree->GetEntries();entry++){
   // for(Long64_t entry=0;entry<1E4;entry++){
     tree->GetEntry(entry);

     MissMass=td->MissMass;
     MissMass2=td->MissMass2;
     MesonMass=td->MesonMass;
     HyperonMass=td->HyperonMass;
     MesonCosTh=td->MesonCosTh;
     MesonPhi=td->MesonPhi;

     HyperonCosTh=td->HyperonCosTh;
     Eg=td->Eg;
     t=td->t;
     HelCosTh=td->HelCosTh;

     HelPhi=td->HelPhi;
     Pol= td->Pol;
     PolState=td->PolState;
     UID=UID0;
     
     TopoID=TopoID0;
     Correct=Correct0;
     NPerm=NPerm0;
     NDet=NDet0;
     MLP=MLP0;
     newtree->Fill();
   }
   newtree->Write();
   delete outfile;
}
