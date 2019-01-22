#include "Canvaser.h"
#include <iostream>
#include <TDirectoryFile.h>
#include <TKey.h>
#include <TLatex.h>

namespace HS{

  Canvaser::Canvaser(TString fname):
    fFile(new TFile(fname)){
  }
    
  
  void Canvaser::DrawHist(hist_uptr hist,TPad* pad,TString opt){
    pad->cd();

    hist->Draw(opt);
    fDrawnHists.push_back(std::move(hist));
  }
   void Canvaser::DrawHist(TString hname,TString opt){
   fCanvases.push_back(can_uptr());
    hist_uptr hist(dynamic_cast<TH1*>(fFile->Get(hname)));
    if(hist.get()){
      hist->Draw(opt);
      fDrawnHists.push_back(std::move(hist));
    }
  }

  //void DrawCutHist(){}
  //void DrawSplitHist(){}
    
  void Canvaser::DrawDirectory(TString dname,Int_t nx, Int_t ny){
    fNX=nx;
    fNY=ny;
    using std::cout;
    using std::endl;
    auto dir=dynamic_cast<TDirectoryFile*>(fFile->GetDirectory(dname));
    if(!dir) {cout<<"Canvaser::DrawDirectory no such directory"<<dname<<endl;return;}
    dir->cd();
    auto contents=dir->GetListOfKeys();
    hists_t dirHists;
    //Get all hists from directory
    for(Int_t ic=0;ic<contents->GetEntries();ic++){
      hist_uptr hist(dynamic_cast<TH1*>(dir->Get(contents->At(ic)->GetName())));
      if(hist.get())
	dirHists.push_back(std::move(hist));
    }
    //make approporiate sized canvas
    auto Nhists=dirHists.size();
    if(!Nhists) return;
    
    auto NperCanvas = fNX*fNY;
    Int_t NCanvases = Nhists/NperCanvas;
    auto Nextra = Nhists%NperCanvas;
    Int_t extraNy=1;
    if(Nextra){ //for dimensions of extra canvas take fNX
      NCanvases++;
      extraNy=Nextra/fNX; //now determine Ny
      if(Nextra%fNX)
	extraNy++;
    }

    UInt_t ihist=0;
    for(Int_t ica=0;ica<NCanvases;ica++){
      //Setup up title display
      //For jsroot on Jupyter
      can_uptr titleCan(new TCanvas(TString("CT")+dname,dname,500,100));
      auto tt = new TLatex(0.01,0.01,GetFullDirTitle(dir));
      titleCan->Draw();
      tt->SetTextSize(1./tt->GetXsize()*tt->GetTextSize()*0.8);
      tt->Draw();
      fCanvases.push_back(std::move(titleCan)); //keep it alive!
 
   //fCanvases.push_back(can_uptr());
      can_uptr canvas(new TCanvas(dname,dname));
      Int_t NX=fNX;
      Int_t NY=1;
      //change NY for the last canvas
      if(ica!=NCanvases-1||Nextra==0) NY=fNY;
      else NY=extraNy;
      canvas->Divide(NX,NY);
      auto pads=canvas->GetListOfPrimitives();
      for(Int_t ipad=0;ipad<pads->GetEntries();ipad++){
	if(ihist==Nhists)
	  break;
	DrawHist(std::move(dirHists[ihist++]),dynamic_cast<TPad*>(canvas->GetPad(ipad+1)),"col1z");
      }
      
      canvas->Draw();
      fCanvases.push_back(std::move(canvas)); //keep it alive!
    }
  }
  void  Canvaser::DrawAllDirectories(Int_t nx, Int_t ny){
    fNX=nx;
    fNY=ny;
    DrawNextDir(fFile.get());
  }
  void   Canvaser::DrawNextDir(TDirectory* dir,TString fullname){
    TIter nextkey(dir->GetListOfKeys() );
    TKey *key=nullptr;
     while ((key = dynamic_cast<TKey*>(nextkey()))) {
      TDirectory* next_dir=nullptr;
      if(!(next_dir=dynamic_cast<TDirectory*>(key->ReadObj())))
	continue;
       DrawNextDir(next_dir,fullname+TString(next_dir->GetName())+"/");
    }
     DrawDirectory(fullname,fNX,fNY);
 }

  TString Canvaser::GetFullDirTitle(TDirectory* dir){
    TDirectory* Savedir=dir;
    TString name=dir->GetTitle() ;
    while((dir=dir->GetMotherDir())){
      name.Prepend(TString(dir->GetTitle())+" ");
    }
    dir=Savedir;
    return name;
  }
}//namespace HS
  
