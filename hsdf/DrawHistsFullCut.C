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
  hm2.AddCut("test1","BeamTime>0");
  
  hm2.ApplyFullSplits();
  hm2.ApplySingleSplits();
  hm2.ConfigureFileDirs();
  hm2.Histo1D("BeamTime","Beam Time",100,-5,5);
  hm2.Histo1D("ProtonTime","Proton Time",100,-5,5);
  hm2.Histo1D("KpTime","K+ Time",100,-5,5);
  hm2.Histo2D("KpTime","KpP","K+ P V Time",50,-5,5,50,0,2);

  hm2.PrintHist1DNames();
  hm2.DrawHist1D("test1:BeamTimeBeamP1.50:");
  hm2.SaveHists();
  gBenchmark->Stop("DrawHists");
  gBenchmark->Print("DrawHists");
}
