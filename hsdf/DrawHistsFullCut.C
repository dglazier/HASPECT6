#include <TBenchmark.h>
#include "DataFrameApp.h"


void DrawHistsFullCut(){
  using namespace HS::DF;
  // ROOT::EnableImplicitMT(10);
  gBenchmark->Start("DrawHists");
  //HistMaker hm2("ParticleVars","test5.root");
  HistMaker hm2("ParticleVars","/work/dump/test5.root","hists.root");
  hm2.AddAxis("BeamP",3,0,3);
  hm2.AddAxis("MissMass",4,-3,3);
  //hm2.AddCut("test1","BeamTime>0");
  
  hm2.ApplyFullSplits();
  hm2.ApplySingleSplits();
  hm2.Histo1D("BeamTime","Beam Time",100,-5,5);
  hm2.Histo1D("ProtonTime","Proton Time",100,-5,5);
  hm2.Histo1D("KpTime2","K+ Time",100,-5,5);
  hm2.Histo2D("KpTime","KpP","K+ P V Time",50,-5,5,50,0,2);
  hm2.SaveHists();
  
  hm2.PrintHist1DNames();
  //hm2.DrawHist1D("test1:BeamTimeBeamP1.50:");
  gBenchmark->Stop("DrawHists");
  gBenchmark->Print("DrawHists");


  auto hm3=hm2.CloneWithNewFile("/work/dump/test5.root","hists3.root","",{{"Test2","BeamTime>0"}});
  // hm3->SaveHists();
  
 // HistMaker hm4("ParticleVars","/work/dump/test5.root","hists4.root");
 //  hm4.AddAxis("BeamP",3,0,3);
 //  hm4.AddAxis("MissMass",4,-3,3);
 //  hm4.AddCut("test1","BeamTime>0");
 
 //  hm4.ApplyFullSplits();
 //  hm4.ApplySingleSplits();
 //  hm4.ConfigureFileDirs();
 //  hm4.Histo1D("BeamTime","Beam Time",100,-5,5);
 //  hm4.Histo1D("ProtonTime","Proton Time",100,-5,5);
 //  hm4.Histo1D("KpTime2","K+ Time",100,-5,5);
 //  hm4.Histo2D("KpTime","KpP","K+ P V Time",50,-5,5,50,0,2);
 //  hm4.SaveHists();
 // 
  
 //  hm_uptr hm5{new HistMaker("ParticleVars","/work/dump/test5.root","hists5.root")};
 //  hm5->AddAxis("BeamP",3,0,3);
 //  hm5->AddAxis("MissMass",4,-3,3);
 //  hm5->AddCut("test1","BeamTime>0");
 
 //  hm5->ApplyFullSplits();
 //  hm5->ApplySingleSplits();
 //  hm5->ConfigureFileDirs();
 //  hm5->Histo1D("BeamTime","Beam Time",100,-5,5);
 //  hm5->Histo1D("ProtonTime","Proton Time",100,-5,5);
 //  hm5->Histo1D("KpTime2","K+ Time",100,-5,5);
 //  hm5->Histo2D("KpTime","KpP","K+ P V Time",50,-5,5,50,0,2);
 //  hm5->SaveHists();

 
}
