/**
	\class THSRunInfo
	Data Class holding once per file information :
	Run #, Gated charge, mean current, Simulation or real,...
	Will allow run specific configurations
	Used as a datamember of THSFinalState

	Note currently the charge is not divided by the FC attenuation factor
	This is 
	//@(10.7)=9.808%  CLAS-NOTE 2018 - 003
	//@(6.4) =16.283% CLAS-NOTE 2018 - 004

*/
#include <TFile.h>
#include "THSRunInfo.h"

////////////////////////////////////////////////////////////
///Load the run info from file filename
void THSRunInfo::LoadTree(TString filename){
  TFile* file=new TFile(filename);
  TTree* tree=(TTree*) file->Get("HSRunInfo");
  THSRunInfo* info=nullptr;
  tree->SetBranchAddress("Info",&info);
  tree->GetEntry(0); //only a single entry in the tree
  *this=*info;
  delete tree;
  delete file;
  info=nullptr;
}
