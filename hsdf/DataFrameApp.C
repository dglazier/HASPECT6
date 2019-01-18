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
      //  filters_t fDFSplits1D;
      // for(auto& ar : fSingleSplitRanges){ //loop over axis
      //  for(auto& r : ar){ //loop over axis bins (==splits)
      for(UInt_t i=0;i<fSingleSplitRanges.size();i++)
	for(UInt_t j=0;j<fSingleSplitRanges[i].size();j++){
	  cout<<fSingleSplitRanges[i][j]<<" "<<fSingleSplitNames[i][j]<<endl;
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
	cout<<fSplitRangesFull[i]<<" "<<fSplitNamesFull[i]<<endl;
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
    // void HistMaker::Histo1D(TString vname,TString htitle,
    // 			    Int_t Nbins,Double_t low, Double_t high){
    //   if(!fDFHistos1D.get())fDFHistos1D.reset(new mhisto1Ds_t);
    //   for(auto& split : *fDFSingleSplits){
    // 	TString fullname=vname+split.first;
    // 	histo1D_t hist=split.second.Histo1D(ROOT::RDF::TH1DModel{fullname.Data(),htitle.Data(),Nbins,low,high},vname.Data());
    // 	fDFHistos1D->insert(std::pair<TString,histo1D_t>(fullname,hist));
    //   }
    // }
    void HistMaker::Histo1D(TString vname,TString htitle,
			       Int_t Nbins,Double_t low, Double_t high){
      if(!fDFHistos1D.get())fDFHistos1D.reset(new mhisto1Ds_t);
      for(auto& split : *fDFSingleSplits){
	TString fullname=vname+split.first;
	if(fCutSpecs.size()){
	  for(auto& cut : fCutSpecs){
	    auto cutsplit=split.second.Filter(cut.second.Data());
	    histo1D_t hist=cutsplit.Histo1D(ROOT::RDF::TH1DModel{(vname).Data(),htitle.Data(),Nbins,low,high},vname.Data());
	    fDFHistos1D->insert(std::pair<TString,histo1D_t>((cut.first+":"+fullname),hist));
	  }
	}
	else{
	  histo1D_t hist=split.second.Histo1D(ROOT::RDF::TH1DModel{fullname.Data(),htitle.Data(),Nbins,low,high},vname.Data());
	  fDFHistos1D->insert(std::pair<TString,histo1D_t>(fullname,hist));
	  
	}
      }
    }
    
    void HistMaker::Histo2D(TString vnameX,TString vnameY,
			    TString htitle,Int_t NbinsX,
			    Double_t lowX, Double_t highX,
			    Int_t NbinsY,
			    Double_t lowY, Double_t highY){
      if(!fDFHistos2D.get())fDFHistos2D.reset(new mhisto2Ds_t);
      for(auto& split : *fDFSingleSplits){
	TString histname=vnameY+"_V_"+vnameX;
	TString fullname=histname+split.first;
	if(fCutSpecs.size()){
	  for(auto& cut : fCutSpecs){
	    auto cutsplit=split.second.Filter(cut.second.Data());
	    histo2D_t hist=cutsplit.Histo2D(ROOT::RDF::TH2DModel{histname.Data(),htitle.Data(),NbinsX,lowX,highX,NbinsY,lowY,highY},vnameX.Data(),vnameY.Data());
	    fDFHistos2D->insert(std::pair<TString,histo2D_t>((cut.first+":"+fullname),hist));
	  }
	}
	else{
	  histo2D_t hist=split.second.Histo2D(ROOT::RDF::TH2DModel{histname.Data(),htitle.Data(),NbinsX,lowX,highX,NbinsY,lowY,highY},vnameX.Data(),vnameY.Data());
	  fDFHistos2D->insert(std::pair<TString,histo2D_t>(fullname,hist));
	  
	}
      }
    }
    
  
   //  void HistMaker::Histo2D(TString vnameX,TString vnameY,
   // 			    TString htitle,Int_t NbinsX,
   // 			    Double_t lowX, Double_t highX,
   // 			    Int_t NbinsY,
   // 			    Double_t lowY, Double_t highY){
   //    if(!fDFHistos2D.get())fDFHistos2D.reset(new mhisto2Ds_t);
   //    for(auto& split : *fDFSingleSplits){
   // 	TString fullname=vnameY+"_V_"+vnameX+split.first;
   // 	histo2D_t hist=split.second.Histo2D(ROOT::RDF::TH2DModel{fullname.Data(),htitle.Data(),NbinsX,lowX,highX,NbinsY,lowY,highY},vnameX.Data(),vnameY.Data());
   // 	fDFHistos2D->insert(std::pair<TString,histo2D_t>(fullname,hist));
   //    }
   // }

    // void HistMaker::Histo1DForFullSplits(TString vname,TString htitle,
    // 					   Int_t Nbins,Double_t low, Double_t high){
    //   fDFHistos1D.reset(new mhisto1Ds_t);
    //   for(auto& split : *fDFSingleSplits){
    // 	TString fullname=vname+split.first;
    // 	histo1D_t hist=split.second.Histo1D(ROOT::RDF::TH1DModel{fullname.Data(),htitle.Data(),Nbins,low,high},vname.Data());
    // 	fDFHistos1D->insert(std::pair<TString,histo1D_t>(fullname,hist));
    //   }
    // }

    void HistMaker::PrintHist1DNames(){
      using std::cout;
      using std::endl;
    
      cout<<endl<<"HistMaker::PrintHistNames() ::"<<endl;
      for(auto& hist : *fDFHistos1D){ //loop over axis
	std::cout<<hist.first<<"   ";
      }
      std::cout<<std::endl<<std::endl;
    }

    void HistMaker::ConfigureFileDirs(){
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
	cout<<"KKKKKKKKKKKKKKK "<<endl;
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
	  // for(auto& snames:fSingleSplitNames)
	  //   for(auto& sname:snames){
	  //     TString tsname(sname);
	  //     tsname.ReplaceAll(":","");
	  //     gDirectory->mkdir(tsname);
	  //   }
	  
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
	cout<<" HistMaker::FindDirectory"<<i<<" "<<dirnames->At(i)->GetName()<< endl;
	gDirectory->cd(dirnames->At(i)->GetName());
      }
      return gDirectory;		       
    }
    
    void HistMaker::SaveHists(){
      
      if(fOutFile.get()){
	for(auto& hist : *fDFHistos1D){ //loop over axis
	  fOutFile->cd();
	  std::cout<<hist.first<<"   ";
	  TString fullname=hist.first;    
	  fullname.ReplaceAll(hist.second->GetName(),"");
	  hist.second->SetDirectory(FindDirectory(fullname));
	}
	for(auto& hist : *fDFHistos2D){ //loop over axis
	  fOutFile->cd();
	  std::cout<<hist.first<<"   "<<hist.second->GetName()<<endl;
	  TString fullname=hist.first;    
	  fullname.ReplaceAll(hist.second->GetName(),"");
	  hist.second->SetDirectory(FindDirectory(fullname));
	}
	fOutFile->Write();
      }
    }
  }//namespace DF
}//namespace HS
