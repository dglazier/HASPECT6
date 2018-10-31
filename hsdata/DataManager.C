/**
        \class DataManager
	Interface to different data formats
	Can read ROOT, HIPO, LUND,...files and converts into HSData format
	for writing or immediate event processing
	HSData format :

	vector< THSParticle >  + EventInfo + RunInfo

	For CLAS12 data see derived classes THSHipoReader and THSHipoTrigger

	For reading ROOT files for example,

	    DataManager* dm=new DataManager();
	    TChain chain("HSParticles");
	    chain.Add("*.root");
	    dm->InitChain(&chain);
	    vector<THSParticle> *parts=dm->GetParticles();
	    EventInfo* event=dm->GetEventInfo();
	    while(dm->ReadEvent())//loop over events
	      parts->at(0).P4().E()  ... event->TrigBit(30) .... 

	For reading CLAS12 HIPO files you need enviroment variables
	RHIPO, CHIPO and LZ4_h set. For more info see
	https://github.com/dglazier/HASPECT6/wiki/hiporoot
	
	    THSHipoTrigger* dm=new THSHipoTrigger();
	    TChain chain("HSParticles");
	    chain.Add("/home/dglazier/clas12data/out_clas_003432.evio.0.hipo");
	    dm->InitChain(&chain);
	    vector<THSParticle> *parts=dm->GetParticles();
	    EventInfo* event=dm->GetEventInfo();
	    while(dm->ReadEvent())//loop over events
	      parts->at(0).P4().E() ... event->TrigBit(30) .... 

	For reading LUND files
	
	    THSLundReader* dm=new THSLundReader();
	    TChain chain("HSParticles");
	    chain.Add("*.ld");
	    dm->InitChain(&chain);
	    vector<THSParticle> *parts=dm->GetParticles();
	    EventInfo* event=dm->GetEventInfo();
	    while(dm->ReadEvent())//loop over events
	      parts->at(0).P4().E() ... 


	In general it is more likely that this class will be used with 
	THSFinalState:

	    THS2pi* fs=new THS2pi();
	    fs->SetDataManager(dm);
	    TFile* outfile=new TFile("hipofile.root","recreate");
	    TTree* outtree=new TTree("FinalTree","output tree");
	    fs->FinalStateOutTree(outtree); //connect ouput tree to project branches
	    while(dm->ReadEvent()){//loop over events
	    fs->ProcessEvent();
	    }

	In this way the final state analysis can be applied to any input file 
	type that has a THSDataManger interface


*/

#include "DataManager.h"
#include "TTreeCache.h"
#include "TSystem.h"
#include "TObjArray.h"

using namespace HS;

DataManager::~DataManager(){
  
  CloseReadTree();
  // if(fReadParticles) delete fReadParticles;
  if(fWeights)delete fWeights;
  if(fEntryList)delete fEntryList;

  if(fBaseEventInfo) delete fBaseEventInfo;
  if(fBaseRunInfo) delete fBaseRunInfo;
  
}
void DataManager::CloseReadTree(){
  if(fReadFile) {
    delete fReadFile;fReadFile=nullptr;
    fReadTree=nullptr;
    fRunTree=nullptr;
  }
  if(fPerfstats) delete fPerfstats;fPerfstats=nullptr;

}
Bool_t DataManager::InitReader(TString filename,TString name){
  //Default read root format
  fReadFile=TFile::Open(filename);
  if(!fReadFile) {Error("DataManager::Init","No file found %s",filename.Data());return kFALSE;}
  fReadTree=dynamic_cast<TTree*>(fReadFile->Get(name));
  if(!fReadTree){Error("DataManager::Init","No tree found %s",name.Data());return kFALSE;}
  //standard particle vector
  fReadParticles=&fParticles;
  fReadTree->SetBranchAddress(fReadBName.Data(),&fReadParticles);
  fBParticles=fReadTree->GetBranch(fReadBName.Data());
  cout<<"DataManager::InitReader set branch "<<fReadParticles<<" "<<&fParticles<<endl;
   //generated particles if simualtions
  fReadGenerated=&fGenerated;
  //if(fInGenerated)fReadTree->SetBranchAddress(fReadGName.Data(),&fReadGenerated);
  if(fReadTree->GetBranch(fReadGName.Data())){
    fReadTree->SetBranchAddress(fReadGName.Data(),&fReadGenerated);
    fInGenerated=kTRUE;
    cout<<"DataManager::InitReader set branch "<<fReadGName<<" "<<fReadGenerated<<" "<<endl;
  }
  else fReadGenerated=nullptr;
  
  //Get Event and Run info if exists
  if(fReadTree->GetBranch("EventInfo"))fReadTree->SetBranchAddress("EventInfo",&fBaseEventInfo);
  fRunTree=dynamic_cast<TTree*>(fReadFile->Get("HSRunInfo"));
  if(fRunTree){
    fBaseRunInfo->LoadTree(filename);
  }
  //if(fFinalState) fFinalState->FileStart();

  fReadTree->SetCacheSize(50E6);//10MB
  fReadTree->StopCacheLearningPhase();
  fPerfstats = new TTreePerfStats("ioperf", fReadTree);
  
  return kTRUE;
}
Bool_t DataManager::Init(TString filename,TString name){
  fTreeName=name;
  fCurFileName=gSystem->BaseName(filename);
  return InitReader(filename,name); //default use tree reader
}
Bool_t DataManager::NextChainFile(){
  if(fChainFileN==fChainFiles->GetEntries()){
    cout<<"DataManager::NextChainFile() Finished all files "<<endl;
    PrintPerfStats();
    CloseReadTree();
    if(fWriteThis)CloseOutput();
    return kFALSE; //no more files
  }
  CloseReadTree();
  if(fWriteThis)CloseOutput();
  cout<<"DataManager::NextChainFile() new file : "<<fChainFiles->At(fChainFileN)->GetTitle()<<" "<<fChainFileN<<" "<<fChainFiles->GetEntries()<<endl;
  //initialise next file
  fEntry=0;
  TString fname=fChainFiles->At(fChainFileN++)->GetTitle();
  Init(fname,fTreeName);
  fCurFileName=gSystem->BaseName(fname);
  if(fOutDir!=TString("")){
    // fCurFileName.Append(fFileAppend);
    InitOutput(fOutDir+"/"+fCurFileName);
  }
  // if(fEntryList) FilterFinalStateEvent();//If filtering via entrlist, redo for this file
  return kTRUE;
}
Bool_t DataManager::ReadEvent(Long64_t entry){
  //Default reader for root files with vector<THSParticle*> branches
  // if(fEntry<fReadTree->GetEntries())fBParticles->GetEntry(fEntry++);
  if(fEntry<fReadTree->GetEntries())fReadTree->GetEntry(fEntry++);
  else if(fChainFiles){
    cout<<fEntry<<" "<<fChainFileN<<" "<<fChainFiles->GetEntries()<<endl;
    if(fChainFileN<=fChainFiles->GetEntries()){//next file
      NextChainFile();  
      //first event in new file

      if(!fReadFile) return kFALSE;
      fReadTree->GetEntry(fEntry++);
    }
  }
  else return kFALSE;
  return kTRUE; 
}

Bool_t DataManager::InitChain(TChain* chain){
  //loop over all files in chain
  fChainFiles=chain->GetListOfFiles();
  Info("DataManager::InitChain"," Will proceess all %d files in chain",fChainFiles->GetEntries());
  //Load first file
  // cout<<fChainFileN<<" "<<endl;
  // cout<<fChainFiles->At(fChainFileN)<<endl;
  // cout<<fChainFiles->At(fChainFileN)<<endl;
  fCurFileName=fChainFiles->At(fChainFileN)->GetTitle();
  fChainFileN++;

  fTreeName=chain->GetName();
  Init(fCurFileName,chain->GetName());
  fCurFileName=gSystem->BaseName(fCurFileName);
  if(fOutDir!=TString("")){
     InitOutput(fOutDir+"/"+fCurFileName);
  }
  return kTRUE;  
}


void DataManager::WriteParticles(){
  cout<<":WriteParticles() "<<fChainFiles<<" "<<fWriteTree<<endl;
  //Write all input events on 1 go
  if(!fChainFiles){
    if(fOutDir!=TString("")){
      fCurFileName.Append(fFileAppend);
      InitOutput(fOutDir+"/"+fCurFileName);
    }
  }
  while(ReadEvent()){
    if(fWriteTree->GetEntries()==100)
      fWriteTree->OptimizeBaskets();
    if(fWriteThis&&fWriteTree){fWriteTree->Fill();PostWrite();}
    fWriteThis=kTRUE;//assume will write next event unless told otherwise
  }
  if(fWriteTree)CloseOutput();
}
void DataManager::InitOutput(TString filename){
  fWriteThis=kTRUE;
  //Make output directory if not existing
  if(!fWriteFile) gSystem->Exec(Form("mkdir -p %s",fOutDir.Data()));
  if(!filename.Contains(".root")){
      filename.Append(".root");
  }
  fCurFileName=filename;
  fWriteFile=new TFile(filename,"recreate");
  //fWriteFile->SetCompressionSettings(401);//LZ4
  fWriteTree=new TTree("HSParticles","data tree");
  fWriteTree->Branch(fReadBName,&fParticles);
 //Make an unsplit tree for MakeSelector
  TTree* UnSplitTree=new TTree("HSUnSplit","unsplit tree for MakeSelector");
  UnSplitTree->Branch(fReadBName,&fParticles,256000,0);
 
  if(fBaseEventInfo){
    fWriteTree->Branch("EventInfo",&fBaseEventInfo);
    UnSplitTree->Branch("EventInfo",&fBaseEventInfo,64000,0);
  }
  if(fBaseRunInfo){
    fRunTree=new TTree("HSRunInfo","once per run information");
    fRunTree->Branch("Info",&fBaseRunInfo);
  }
  UnSplitTree->Write();
  delete UnSplitTree;

  if(fAddGenerated)fWriteTree->Branch(fWriteGName,&fGenerated);
  Info("DataManager::InitOutput","Saving particles to %s",filename.Data());
}
void DataManager::CloseOutput(){
  if(!fWriteFile) return;
  fWriteFile->cd();
  if(fWriteTree)fWriteTree->Write();
  if(fRunTree){fRunTree->Fill();fRunTree->Write();}
  fWriteFile->Close();
  delete fWriteFile;
  fWriteFile=nullptr;
  fWriteTree=nullptr;
  fRunTree=nullptr;
}
void DataManager::PrintEvent(Long64_t entry){

  Info("DataManager","Printing First event, this should help configure project class");
  if(!ReadEvent(entry)) {Error("PrintEvent","error in event read");return;}  
  cout<<"Initialised with "<<fNin<<" particles"<<endl;
  for(UInt_t i=0;i<fNin;i++){
    fParticles[i].Print("");  
  }
  
}
void DataManager::PrintPerfStats(){
  if(fReadTree)fReadTree->PrintCacheStats();
  if(fPerfstats) fPerfstats->Print();
}
void DataManager::AddUID(TString filename,TString treename){
  //Once all files are available you can give every
  //event a unique ID for use in synchronisating weights etc.
  
  TFile* file=TFile::Open(filename,"update");
  if(!file) {Error("DataManager::AddUID","No file %s found",filename.Data());return;}
  TTree* tree=(TTree*)file->Get(treename);
  if(!tree) {Error("DataManager::AddUID","No tree %s found in %s",treename.Data(),filename.Data());return;}
  if(tree->GetBranch("UID")) return; //aready exists
  TBranch* branch=tree->Branch("UID",&UID,"UID/D");
  if(!branch) return;
  
  Long64_t id=(Long64_t)UID;
  UID=id;
   for(Long64_t i=0;i<tree->GetEntries();i++){
    branch->Fill();
    id++;
    UID=id;   
   }
   Info("DataManager::AddUID","Added UID for file %s ",filename.Data());
   tree->Write(tree->GetName(),TObject::kOverwrite);
   file->Close();
   delete file;
   
}
void DataManager::LoadWeights(TString fname,TString wname){
    Info("LoadWeights"," Opening weights file %s name %s",fname.Data(),wname.Data());
    fWeights=new THSWeights();
    fWeights->LoadSaved(fname,wname);
    fWeights->PrintWeight();
   
}
void DataManager::GetWeightEvent(){
  //if(fWeights)fWeights->GetEntryBinarySearch((Long64_t)fTUID);
}
Double_t DataManager::GetWeight(Int_t species){
  if(fWeights) fWeight=fWeights->GetWeight(species);
  return fWeight;
}
