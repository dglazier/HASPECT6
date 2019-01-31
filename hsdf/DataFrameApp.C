#include "DataFrameApp.h"
#include <TSystem.h>
#include <ROOT/RSnapshotOptions.hxx>

namespace HS{
  namespace DF{
    ///////////////////////////////////////////////////////////////////////
    ///Splitter
    void Splitter::AddAxis(TString name,Int_t nbins,Double_t min,Double_t max){
      //Add a new axis for a given variable, name should be tree name
      TArrayD bins(nbins+1);
      Double_t binwidth = (max - min) / Double_t(nbins);
      for(Int_t i=0;i<nbins+1;i++)
	bins[i]= min + i * binwidth;
      AddAxis(name,nbins,bins.GetArray());
    
    }
    void Splitter::AddAxis(TString name,Int_t nbins,Double_t* xbins){
      //Add a new axis for a given variable, name should be tree name
      TAxis axis(nbins,xbins);
      axis.SetName(name);
      fSplitAxis.push_back(axis);
      fNaxis++;
    }
    Int_t Splitter::GetAxisi(TString aname) const{
      for(Int_t ia=0;ia<fNaxis;ia++)
	if(fSplitAxis[ia].GetName()==aname)
	  return ia;
      return -1;
    }
    
    void Splitter::Split(){
      if(fNaxis==0) return;
      fDoneSplit=kTRUE; 
      //Make complete names for every lowest level split
      TString splitName;
      fN=0;
      fSplitRangesFull.clear();
      fSplitNamesFull.clear();
      fSingleSplitRanges.clear();
      fSingleSplitNames.clear();
      IterateAxis(0,"",""); 
    }
  
    void Splitter::IterateAxis(Int_t iA,TString splitName,TString splitRange) {
      //iterate through all bins possible with given axis and constuct
      //unique names for them
      if (iA >= fNaxis){ //stop clause
	fSplitNamesFull.push_back(splitName);
	fSplitRangesFull.push_back(splitRange);
	fN++;
	return;
      }
      strings_t part;
      strings_t ranges;
      for (int iB = 1; iB <= fSplitAxis[iA].GetNbins(); iB++) { 
	fSplitAxis[iA].SetBinLabel(iB,Form("%1.2f:",fSplitAxis[iA].GetBinCenter(iB)));
	//get part of split name
	part.push_back(TString(fSplitAxis[iA].GetName())+fSplitAxis[iA].GetBinLabel(iB));
	//get range of this split
	ranges.push_back(Form("%f<%s && %s<=%f",fSplitAxis[iA].GetBinLowEdge(iB),fSplitAxis[iA].GetName(),fSplitAxis[iA].GetName(),fSplitAxis[iA].GetBinUpEdge(iB)));

	if(splitRange==TString(""))
	  IterateAxis(iA+1,splitName+fSplitAxis[iA].GetName()+fSplitAxis[iA].GetBinLabel(iB),ranges.back());
	else
	  IterateAxis(iA+1,splitName+fSplitAxis[iA].GetName()+fSplitAxis[iA].GetBinLabel(iB),splitRange+" && "+ranges.back());
      }
    
      //store ranges
      if(std::find(fSingleSplitRanges.begin(),fSingleSplitRanges.end(),ranges)==fSingleSplitRanges.end()) {
	fSingleSplitRanges.push_back(ranges);
	fSingleSplitNames.push_back(part);
      }
    }

    
    void Splitter::ApplySingleSplits(){
      fAreSingleSplits=kTRUE;
      if(!fDoneSplit) Split();
      if(!fDFSingleSplits.get())fDFSingleSplits.reset(new mfilters_t);
      for(UInt_t i=0;i<fSingleSplitRanges.size();i++)
	for(UInt_t j=0;j<fSingleSplitRanges[i].size();j++){
	  filter_t split=DFrame()->Filter(fSingleSplitRanges[i][j].Data(),fSingleSplitNames[i][j].Data());
	  fDFSingleSplits->insert(std::pair<TString,filter_t>(fSingleSplitNames[i][j], split));
	}
    }

    void Splitter::ApplyFullSplits(){
     fAreFullSplits=kTRUE;
      if(!fDoneSplit) Split();
      if(!fDFSingleSplits.get())fDFSingleSplits.reset(new mfilters_t);
      //filters_t fDFSplits1D;
      for(UInt_t i=0;i<fSplitRangesFull.size();i++){
	filter_t split=DFrame()->Filter(fSplitRangesFull[i].Data(),fSplitNamesFull[i].Data());
	fDFSingleSplits->insert(std::pair<TString,filter_t>(fSplitNamesFull[i], split));    
	
      }
    }
    

    void Splitter::PrintRanges(){
      using std::cout;
      using std::endl;
    
      cout<<endl<<"Split::PrintRanges() ::"<<endl;
      for(auto& ar : fSingleSplitRanges){ //loop over axis
	for(auto& r : ar) //loop over axis bins (==splits)
	  std::cout<<r<<"   ";
	cout<<endl;
      }
      std::cout<<std::endl<<std::endl;
    }
    void Splitter::PrintSingleSplitNames(){
      using std::cout;
      using std::endl;
    
      cout<<endl<<"Split::PrintPArtNames() ::"<<endl;
      for(auto& ar : fSingleSplitNames){ //loop over axis
	for(auto& r : ar) //loop over axis bins (==splits)
	  std::cout<<r<<"   ";
	cout<<endl;
      }
      std::cout<<std::endl<<std::endl;
    }
    void Splitter::PrintSplitNames(){
      using std::cout;
      using std::endl;
    
      cout<<endl<<"Split::PrintSplitNames() ::"<<endl;
      for(auto& sn : fSplitNamesFull){ //loop over axis
	std::cout<<sn<<"   ";
      }
      std::cout<<std::endl<<std::endl;
    }
    void Splitter::PrintSplitRangesFull(){
      using std::cout;
      using std::endl;
    
      cout<<endl<<"Split::PrintSplitRangesFull() ::"<<endl;
      for(auto& sn : fSplitRangesFull){ //loop over axis
	std::cout<<sn<<" ;  ";
      }
      std::cout<<std::endl<<std::endl;
    }

    void Splitter::TakeSplitterMembers(const Splitter& s){
      fSplitAxis=s.fSplitAxis;   
      fNaxis=s.fNaxis;
      if(s.fAreSingleSplits)ApplySingleSplits();
      if(s.fAreFullSplits)ApplyFullSplits();
         
    }
    ///////////////////////////////////////////////////////////////////////
    ///TreeSplitter
    void TreeSplitter::SaveTrees(TString basedir){
      ApplySingleSplits();
      gSystem->MakeDirectory(basedir);
      //fDFHistos1D.reset(new mhisto1Ds_t);
      for(auto& split : *fDFSingleSplits){
	TString dirname=basedir+"/"+split.first;
	gSystem->MakeDirectory(dirname);
	ROOT::RDF::RSnapshotOptions opts;
	opts.fLazy = true;
	//remove duplicated columns like a.a
	std::string point = ".";
	auto branch_names=container_filter(split.second.GetColumnNames(), [point](std::string cname){
	    return cname.find(point)==std::string::npos;  });
	
	split.second.Snapshot(TreeName().Data(),(dirname+"/SplitTree.root").Data(),branch_names,opts);
      }
      //  DFrame()->Report()->Print();
    }
   ///////////////////////////////////////////////////////////////////////
    ///HistMaker
    ///////////////////////////////////////////////////////////////////////
    ///reproduces same histograms for another root file (tree)
    ///usage :
    /// CloneWithNewFile("new/in/file.root","new/out/file.root");
    /// CloneWithNewFile("new/in/file.root","new/out/file.root","newtree");v//in case different treename
    /// CloneWithNewFile("new/in/file.root","new/out/file.root","",{{"Test2","BeamTime>0"},{"MassCut","Mass>1"}}); //in case you want to apply different cuts
    hm_uptr HistMaker::CloneWithNewFile(TString infname,TString outfname,TString tname,std::vector<std::pair<TString,TString>> cuts){
      if(tname == TString(""))
	tname=TreeName();
      
      hm_uptr p{new HistMaker(tname,infname,outfname)};

      if(cuts.size()==0){
	for(auto &cut : fCutSpecs){
	  p->AddCut(cut.first,cut.second);
	}
      }
      else{
	for(auto &cut : cuts){
	  p->AddCut(cut.first,cut.second);
	}
      }

      p->TakeSplitterMembers(*this);
      
      p->ConfigureFileDirs();
    
      for(auto &hist : fHistTemplates1D){
      	auto hax=hist.GetXaxis();
       	p->Histo1D(hist.GetName(),hist.GetTitle(),hist.GetNbinsX(),hax->GetXmin(),hax->GetXmax());
      }
 
      for(auto &hist : fHistTemplates2D){
      	auto hax=hist.GetXaxis();
      	auto hay=hist.GetYaxis();
      	p->Histo2D(hax->GetName(),hay->GetName(),hist.GetTitle(),hist.GetNbinsX(),hax->GetXmin(),hax->GetXmax(),hist.GetNbinsY(),hay->GetXmin(),hay->GetXmax());
      }
       p->SaveHists();

      return std::move(p);
    }
   
    void HistMaker::Histo1D(TString vname,TString htitle,
			       Int_t Nbins,Double_t low, Double_t high){
      if(!CheckForColumn(vname)) return;
      if(!fDFHistos1D.get())fDFHistos1D.reset(new mhisto1Ds_t);
      ConfigureFileDirs();

      auto temph=TH1S(vname,htitle,Nbins,low,high);
      temph.SetDirectory(0);
      fHistTemplates1D.push_back(temph);
      
      for(auto& split : *fDFSingleSplits){
	if(fCutSpecs.size()){
	  for(auto& cut : fCutSpecs){
	    TString fullname=vname+":"+cut.first+":"+split.first;
	    auto cutsplit=split.second.Filter(cut.second.Data());
	    histo1D_t hist=cutsplit.Histo1D(ROOT::RDF::TH1DModel{(vname).Data(),htitle.Data(),Nbins,low,high},vname.Data());
	    fDFHistos1D->insert(std::pair<TString,histo1D_t>((fullname),hist));
	  }
	}
	else{
	  TString fullname=vname+":"+split.first;
	  histo1D_t hist=split.second.Histo1D(ROOT::RDF::TH1DModel{fullname.Data(),htitle.Data(),Nbins,low,high},vname.Data());
	  fDFHistos1D->insert(std::pair<TString,histo1D_t>(fullname,hist));
	  
	}
      }
      
      histo1D_t hist=DFrame()->Histo1D(ROOT::RDF::TH1DModel{(vname).Data(),htitle.Data(),Nbins,low,high},vname.Data());
      fDFHistos1D->insert(std::pair<TString,histo1D_t>(vname,hist));

    }
    
    void HistMaker::Histo2D(TString vnameX,TString vnameY,
			    TString htitle,Int_t NbinsX,
			    Double_t lowX, Double_t highX,
			    Int_t NbinsY,
			    Double_t lowY, Double_t highY){
     if(!CheckForColumn(vnameX)) return;
     if(!CheckForColumn(vnameY)) return;

     if(!fDFHistos2D.get())fDFHistos2D.reset(new mhisto2Ds_t);
     ConfigureFileDirs();
     
     TString histname=vnameY+"_V_"+vnameX;
     auto temph=TH2S(histname,htitle,NbinsX,lowX,highX,NbinsY,lowY,highY);
     temph.GetXaxis()->SetName(vnameX);
     temph.GetYaxis()->SetName(vnameY);
     temph.SetDirectory(0);
     fHistTemplates2D.push_back(temph);
     
     for(auto& split : *fDFSingleSplits){
 	if(fCutSpecs.size()){
	  for(auto& cut : fCutSpecs){
	    TString fullname=histname+":"+cut.first+":"+split.first;
	    auto cutsplit=split.second.Filter(cut.second.Data());
	    histo2D_t hist=cutsplit.Histo2D(ROOT::RDF::TH2DModel{histname.Data(),htitle.Data(),NbinsX,lowX,highX,NbinsY,lowY,highY},vnameX.Data(),vnameY.Data());
	    fDFHistos2D->insert(std::pair<TString,histo2D_t>(fullname,hist));
	  }
	}
	else{
	  TString fullname=histname+":"+split.first;
	  histo2D_t hist=split.second.Histo2D(ROOT::RDF::TH2DModel{histname.Data(),htitle.Data(),NbinsX,lowX,highX,NbinsY,lowY,highY},vnameX.Data(),vnameY.Data());
	  fDFHistos2D->insert(std::pair<TString,histo2D_t>(fullname,hist));
	  
	}
      }
     histo2D_t hist=DFrame()->Histo2D(ROOT::RDF::TH2DModel{histname.Data(),htitle.Data(),NbinsX,lowX,highX,NbinsY,lowY,highY},vnameX.Data(),vnameY.Data());
      fDFHistos2D->insert(std::pair<TString,histo2D_t>(histname,hist));

    }
    
  

    void HistMaker::PrintHist1DNames(){
      using std::cout;
      using std::endl;
    
      cout<<endl<<"HistMaker::PrintHistNames() ::"<<endl;
      for(auto& hist : *fDFHistos1D){ //loop over axis
	std::cout<<hist.first<<"   ";
      }
      std::cout<<std::endl<<std::endl;
    }
    void HistMaker::PrintCuts(){
      using std::cout;
      using std::endl;
    
      cout<<endl<<"HistMaker::PrintCuts() ::"<<endl;
      for(auto& cut : fCutSpecs){ //loop over cuts
	std::cout<<"( "<<cut.first<<" =  "<<cut.second<<") ";
      }
      std::cout<<std::endl<<std::endl;
    }

    void HistMaker::ConfigureFileDirs(){
      if(fConfigFileDirsDone) return;
      fConfigFileDirsDone=kTRUE;
      if(!fOutFile.get()) return;
      if(fAreFullSplits){
	fOutFile->cd();
	if(fCutSpecs.size())
	  for(auto& cut: fCutSpecs){
	    fOutFile->cd(cut.first);
	    MakeSplitDirs(GetNAxis(),gDirectory);
	  }
	else
	  MakeSplitDirs(GetNAxis(),gDirectory);
      }
      if(fAreSingleSplits){
	fOutFile->cd();
	if(fCutSpecs.size())
	  for(auto& cut: fCutSpecs){
	    //	    for(auto& snames:fSingleSplitNames)
	    for(UInt_t i=0;i<fSingleSplitNames.size();i++)
	      for(UInt_t j=0;j<fSingleSplitNames[i].size();j++){
		//  for(auto& sname:snames){
		fOutFile->cd(cut.first);
		TString tsname(fSingleSplitNames[i][j]);
		tsname.ReplaceAll(":","");
		gDirectory->mkdir(tsname,fSingleSplitRanges[i][j]);
	      }
	  }
      
	else{

	    for(UInt_t i=0;i<fSingleSplitNames.size();i++)
	      for(UInt_t j=0;j<fSingleSplitNames[i].size();j++){
		TString tsname(fSingleSplitNames[i][j]);
		tsname.ReplaceAll(":","");
		gDirectory->mkdir(tsname,fSingleSplitRanges[i][j]);
	      }
	    
	}
	
      }
    }
    void HistMaker::MakeSplitDirs(Int_t iA,TDirectory* curDir){
      iA--;
      if(iA<0) return;//no more splits
      //      for(Int_t iB=0;iB<fBins->GetAxis(iA).GetNbins();iB++){
      
      //      for(auto& sname:fSingleSplitNames[iA]){
      for(UInt_t i=0;i<fSingleSplitNames[iA].size();i++){
	//cout<<"MakeSplitDirs "<<sname<<" "<<curDir->GetName()<<" "<<iA<<" "<<fSingleSplitNames.size()<<endl;
	//Make directory, move into it and move to next axis
	TString tsname(fSingleSplitNames[iA][i]);
	tsname.ReplaceAll(":","");
	curDir->mkdir(tsname,fSingleSplitRanges[iA][i]);
	curDir->cd(tsname);
	MakeSplitDirs(iA,gDirectory);
      }
    }
    
    TDirectory* HistMaker::FindDirectory(TString name){
      auto dirnames=name.Tokenize(":");
      for(Int_t i=0;i<dirnames->GetEntries();i++){
	gDirectory->cd(dirnames->At(i)->GetName());
      }
      return gDirectory;		       
    }
    
    void HistMaker::SaveHists(){
      cout<<"HistMaker::SaveHists "<<fOutFile->GetName()<<" "<<fDFHistos1D->size()<<endl;
      //Don't save templates
      for(auto& hist : fHistTemplates1D)
	hist.SetDirectory(0);
      for(auto& hist : fHistTemplates2D)
	hist.SetDirectory(0);
   
      if(fOutFile.get()){
	if(fDFHistos1D.get())
	  for(auto& hist : *fDFHistos1D){ //loop over axis
	    fOutFile->cd();
	    TString fullname=hist.first;    
	    fullname.Remove(0,fullname.First(":")+1);
	    auto dir=FindDirectory(fullname);
	    if(dir)hist.second->SetDirectory(dir);
	  }
	if(fDFHistos2D.get()){
	  cout<<"2d "<<fDFHistos2D->size()<<endl;
	  for(auto& hist : *fDFHistos2D){ //loop over axis
	    fOutFile->cd();
	    TString fullname=hist.first;
	    fullname.Remove(0,fullname.First(":")+1);
	    auto dir=FindDirectory(fullname);
	    if(dir)hist.second->SetDirectory(FindDirectory(fullname));
	  }
	}
	fOutFile->Write();
      }
    }
    //////////////////////////////////////////////////////////////
    // MultiFileHists::MultiFileHists(TString tname,strings_t files,TString dir){
    //   for(auto& inname : files){
    // 	auto outname= dir + "/"+gSystem->BaseName(inname);
    // 	fHistMakers.push_back(HistMaker(tname,inname,outname));
    //   }
    // }
    // MultiFileHists::MultiFileHists(TString file,TString dir){

    // }

    
  }//namespace DF
}//namespace HS
