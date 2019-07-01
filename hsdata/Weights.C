/**
	\class Weights
	
	Class to control weight structures in HaSpect.
	Consists of 1 tree with event IDs
	And 1 tree with the weights of the different species
	It relies on being able to read the trees into memory
	to sort the ordering, this may cause issues with order >10^7
	events
	
	
*/

#include "Weights.h"
#include <TTreeIndex.h>
#include <TSystem.h>
#include <TFile.h>
#include <TMath.h>
#include <TCut.h>
#include <TEntryList.h>

using namespace HS;

Weights::Weights(TString name) :TNamed(name,name){
  fWTree=new TTree(name+"_W","Tree weights for each species");
  fWTree->SetDirectory(0);
  fIDTree=new TTree(name+"_ID","event ids for each entry");
  fIDTree->SetDirectory(0);
  fIDTree->Branch("WID",&fID,"WID/L");
  fCurrEntry=0;
  fIsSorted=kFALSE;
  fN=0;
  fSpecies.clear();
  fIDName="UID";
}

Weights::~Weights(){
   if(fFile)Save();			       
  if(fWeightList) delete fWeightList;
  if(fWTree) delete fWTree;
  if(fIDTree) delete fIDTree; 
  if(fFile) {delete fFile;}
  if(fBranchFile) delete fBranchFile;
}

void Weights::SetSpecies(TString name){
  UInt_t NSpecies=fSpecies.size(); 
  fSpecies.insert(pair<TString,Int_t>(name,NSpecies)); //save name in map
  fWVals.ResizeTo(NSpecies+1); //create entry in value array
  //make branch with name and connect to new fWVals entry
  fWVals[NSpecies]=0;
  cout<<"Insert species "<<name <<" "<<NSpecies<<" "<<fWVals[NSpecies]<<endl;
  fWTree->Branch(name,&fWVals[NSpecies],name+TString("/D")); 
}

//////////////////////////////////////////////////////////////
///Move down the tree until you find an event with correct ID.
///This requires the trees are sorted in ID
///and fWTree is a subset of whatever tree requires the weight.
///Fastest if both trees have same events
Bool_t Weights::GetEntryFast(Long64_t id){

  if(!fIDv) BuildIndex();
  if(id!=fIDv[fCurrEntry]){//no weight for this id
    return fGotEntry=kFALSE;}
  fWTree->GetEntry(fCurrEntry++); //get entry now we know it exists 
  return fGotEntry=kTRUE;
}

////////////////////////////////////////////////////////////
///for unsorted tree \n
///Move down the tree until find event with correct ID.
///This is faster if trees are sorted in ID and ReStart not required
///(in which case use GetEntryFast)
///and fWTree is a subset of whatever tree requires the weight.
///Fastest if both trees have same events
Bool_t Weights::GetEntrySlow(Long64_t id){
  if(!fIDv) BuildIndex();
  Bool_t ReStart=0;
  if(id!=fIDv[fCurrEntry++]){//no weight for this id
    //    fIDTree->GetEntry(fCurrEntry++);
    if(fCurrEntry==fWTree->GetEntries()&&ReStart==0){fCurrEntry=0; ReStart=1;}
    else if(fCurrEntry==fWTree->GetEntries()){
      cout<<"Weights::GetEntry entry not found "<<id<<endl; 
      return fGotEntry=kFALSE;}
  }
  fCurrEntry--;
  fWTree->GetEntry(fCurrEntry++); //get entry now we know it exists 
  return fGotEntry=kTRUE;
}

/////////////////////////////////////////////////////////////
///Use a binary search to find the entry for an unsorted tree
Bool_t Weights::GetEntryBinarySearch(Long64_t id){

  if(!fIDv) BuildIndex();
  Long64_t entry=TMath::BinarySearch(fN,fIDv,id);
  if(fIDv[entry]!=id) return fGotEntry=kFALSE;
  fWTree->GetEntry(fIDi[entry]);//entry should be OK if these arrays are be ordered...
  return fGotEntry=kTRUE;
}

//////////////////////////////////////////////////
///Function to merge weights from many root files
Long64_t Weights::Merge(TString tempName,TString outName,TString wmName){

  if(outName!=TString("")) {
    //TFile* outFile=new TFile(outName,"recreate");
    SetFile(outName);
  }
  TString dirName=gSystem->DirName(tempName);
  TString prefix=gSystem->BaseName(tempName); //anything after directory in tempname
  if(prefix==TString("")) prefix="Weights";
  void *dir=gSystem->OpenDirectory(dirName);
  if(!dir) cout<<"Weights::Merge No directory found : "<<dirName<<endl;
  else cout<<"Weights::Merge Merging "<<prefix <<"* in directory "<<dirName<<endl;
  TString fileName;
  while( (fileName=(gSystem->GetDirEntry(dir)))){
    if(fileName==TString("")) break;
    if(fileName==TString("."))continue;
    if(fileName==TString(".."))continue;
    if(!fileName.Contains(prefix))continue;
    if(!fileName.Contains(".root"))continue;
    Weights* wm=new Weights();
    wm->LoadSaved(dirName+"/"+fileName,wmName);
    fIDName=wm->GetIDName();
    Add(wm);
    delete wm;
    //wfile->Close();
    //delete wfile;
  }
  gSystem->FreeDirectory(dir);
  
  SortWeights();//needs sorted for binary search to work
  PrintWeight();
  return Size();
  
}

//////////////////////////////////////
///Find the name for a given index
TString Weights::GetSpeciesName(UInt_t isp){
  if(isp>=fSpecies.size()) return TString("");
  //find the name for a given index
  for(StrIntMap_t::iterator it1 = fSpecies.begin(); it1 != fSpecies.end(); ++it1)
    if(it1->second==(Int_t)isp) return it1->first;
  return TString("");
}

/////////////////////////////////////////////////////////////
///Add the tree \n
///Zero weight values in case of missing species in new weights.
///These branches will then just be filled with zero weight for
///the new entries.
void Weights::Add(Weights* Wts){
  StrIntMap_t *sp0=GetSpeciesp();
  StrIntMap_t *sp1=Wts->GetSpeciesp();
  UInt_t Ns0=sp0->size();
  UInt_t Ns1=sp1->size();
  UInt_t NnewSp=0;
  StrIntMap_t New_sp; //map for additional species from Wts with original index
  //Check for new species
  for(StrIntMap_t::iterator it1 = sp1->begin(); it1 != sp1->end(); ++it1){
    if(!(sp0->count(it1->first))){//this species is not in map already
      SetSpecies(it1->first);//add new species branch
      for(Long64_t ie=0;ie<fWTree->GetEntries();ie++)//fill previous entries with 0
	fWTree->GetBranch(it1->first)->Fill();
    }
  }
  //Add the tree
  for(UInt_t isp=0;isp<Ns0;isp++)
    fWVals[isp]=0;
  //if(New_sp==0){//no new species, just merge trees
  TList* tlist=new TList();
  tlist->Add(Wts->GetTree());
  fWTree->Merge(tlist);
  delete tlist;
  TList* wlist=new TList();
  wlist->Add(Wts->GetIDTree());
  fIDTree->Merge(wlist);
  delete wlist;
  //make a list of weights added, this can be used to select contributing entrylists
  if(!fWeightList) {fWeightList=new TList();fWeightList->SetOwner();}
  fWeightList->Add(new TNamed(Wts->GetTitle(),""));//include name of this bin

}

void Weights::PrintWeight(){
  cout<<"Weights "<<GetName()<<" contains "<<Size() <<" events associated file is ";
  if(fFile) cout<<fFile->GetName()<< " "<<fFile->GetTitle()<<endl;
  else cout<<endl;
  cout<<"ID branch name : "<<fIDName<<endl;
  cout<<"Species are : "<<endl;
  for(map<TString,Int_t>::iterator it=fSpecies.begin();it!=fSpecies.end();++it)
    cout<<it->first<<endl;
  Int_t Nit=0;
  cout<<"The first ten entries are :"<<endl;
  Int_t Nw=10;
  if(Size()<10) Nw=Size();
  for(Int_t i=0;i<Nw;i++){
  // for(Int_t i=3900;i<4100;i++){
    GetEntry(i);
    cout<<fID<<" "<<fWVals[0]<<" ";
    for(UInt_t iss=1;iss<fSpecies.size();iss++)
      cout<<fWVals[iss]<< " ";
    cout<<endl;
  }
  if(fWeightList){
    cout<<"These weights are combined from :"<<endl;
    for(Int_t i=0;i<fWeightList->GetEntries();i++)
      cout<<fWeightList->At(i)->GetName()<<endl;
  }
}

void Weights::BuildIndex(){
  // cout<<"Weights::BuildIndex "<<fIDTree->BuildIndex(TString("(Long64_t)WID"))<<endl;
  fIDTree->BuildIndex(TString("WID"));
  //  fIDTree->BuildIndex(TString("(Long64_t)WID"));
  TTreeIndex *index = (TTreeIndex*)fIDTree->GetTreeIndex();
  fIDi=index->GetIndex();//entry numbers
  fIDv=index->GetIndexValues();//id values
  fN=fWTree->GetEntries();
}

////////////////////////////////////////////////////////////////////////////
///GetEntryFast only works properly on trees where the ID is in order \n
///This is not guaranteed particualrly if weights are merged from different bins,
///reorder here
void Weights::SortWeights(){
  TTree* idtree=fIDTree->CloneTree(0); //create empty tree with branch adresses set //Clone before create index so do not have to save index
  idtree->SetDirectory(fFile); //set file to save memory
  BuildIndex();
   TTree* Mwtree=fWTree->CloneTree(); //create clone tree in memory or very slow!
   Mwtree->SetDirectory(0);
  cout<<"Weights::SortWeights() Clone tree to save "<<endl;
  TTree* wtree=fWTree->CloneTree(0); //create empty tree with branch adresses set
  wtree->SetDirectory(fFile);//set file to save memory
  for( Long64_t i =  0; i < fN ; i++ ) {
    fID=fIDv[i];
    idtree->Fill(); //fill as ordered by the build index
    //wtree is synched with id tree
    Mwtree->GetEntry(fIDi[i]);
    wtree->Fill(); //fill as ordered by the build index
  }
  //swap sorted trees to datamembers
  delete fIDTree;fIDTree=nullptr;
  delete fWTree;fWTree=nullptr;
  delete Mwtree;Mwtree=nullptr;
  fIDTree=idtree;
  fWTree=wtree;
  //resetbranch addresses
  fIDTree->SetBranchAddress("WID",&fID);
  for(UInt_t iss=0;iss<fSpecies.size();iss++)
  for(StrIntMap_t::iterator it1 = fSpecies.begin(); it1 != fSpecies.end(); ++it1)
    fWTree->SetBranchAddress(it1->first,&fWVals[it1->second]);
  
  //  cout<<"Weights::SortWeights Print new ordering"<<endl;
  // PrintWeight();
  //reset index
  fIDv=0;//these have been deleted with orig fIDTree
  fIDi=0;
 
  fIsSorted=kTRUE;
}
/////////////////////////////////////////////////////////////////
///Set file for keeping weights on disk
//Should be done before sort etc to save memory
void Weights::SetFile(TString filename){
  TDirectory *saveDir=gDirectory;
  fFile=new TFile(filename,"recreate");
  if(fIDTree)fIDTree->SetDirectory(fFile);
  if(fWTree)fWTree->SetDirectory(fFile);
  saveDir->cd();
}
////////////////////////////////////////////////////////////////
///Finally save weights to disk
void Weights::Save(){
  // cout<<"void Weights::Save() "<<fFile<<endl;
  //cout<<fIDTree<<" "<<fWTree<<endl;
  if(!fFile) {cout<<"Weights::Save() no file associated with "<<GetName()<<" so not saved"<<endl;return;}
  if(!fFile->IsWritable()) return;
  if(!fIDTree)return ;
  if(!fWTree)return ;
  fFile->cd();
  fWTree->Write();//Note can't just save whole object
  fIDTree->Write(); //As 1GB limit on object buffers in TFile
  Write();//save the rest (not trees) of the weights class
 
  delete fFile;fFile=0;fWTree=0;fIDTree=0;

}
///////////////////////////////////////////////////////////////
///Give file name and name (in .root file) of weights object to load weights
///into and empty weights object
///e.g. Weights* wts=new Weights();
///     wts->LoadSaved("path_to_/Weight_File.root","HSWeight");
void Weights::LoadSaved(TString fname,TString wname){
  TDirectory* savedir=gDirectory;
  TFile* wfile=new TFile(fname);
  if(!wfile) return;
  
  Weights* file_wts=(Weights*)wfile->Get(wname);//read into memory
  if(!file_wts) return;
  fName=file_wts->GetName();
  fTitle=file_wts->GetTitle();

  savedir->cd();
  TTree* tempTree=0;
  tempTree=(TTree*)wfile->Get(wname+"_W");
  fWTree=tempTree->CloneTree();
  delete tempTree;
  fWTree->SetDirectory(0);
  fSpecies=file_wts->GetSpecies();
  fWVals.ResizeTo(fSpecies.size());
  for(UInt_t i=0;i<fSpecies.size();i++)
    fWTree->SetBranchAddress(GetSpeciesName(i),&fWVals[i]); 

  fIDName=file_wts->GetIDName();
  tempTree=(TTree*)wfile->Get(wname+"_ID");
  fIDTree=tempTree->CloneTree();
  // fIDTree=(TTree*)file_wts->GetIDTree()->Clone();
  delete tempTree;
  fIDTree->SetDirectory(0);
  fIDTree->SetBranchAddress("WID",&fID);
 
  fCurrEntry=0;
  fIsSorted=kFALSE;
  fN=fWTree->GetEntries();
  delete file_wts;file_wts=nullptr;  
  wfile->Close();
  delete wfile;wfile=nullptr;
}
void Weights::LoadSavedDisc(TString fname,TString wname){
  TDirectory* savedir=gDirectory;
  TFile* wfile=new TFile(fname);
  if(!wfile) return;
  
  Weights* file_wts=(Weights*)wfile->Get(wname);//read into memory
  if(!file_wts) return;
  fName=file_wts->GetName();
  fTitle=file_wts->GetTitle();

  savedir->cd();
  TTree* tempTree=0;
  tempTree=(TTree*)wfile->Get(wname+"_W");
  fWTree=tempTree;
  //  delete tempTree;
  //fWTree->SetDirectory(0);
  fSpecies=file_wts->GetSpecies();
  fWVals.ResizeTo(fSpecies.size());
  for(UInt_t i=0;i<fSpecies.size();i++)
    fWTree->SetBranchAddress(GetSpeciesName(i),&fWVals[i]); 

  fIDName=file_wts->GetIDName();
  tempTree=(TTree*)wfile->Get(wname+"_ID");
  fIDTree=tempTree;
  // fIDTree=(TTree*)file_wts->GetIDTree()->Clone();
  //delete tempTree;
  //fIDTree->SetDirectory(0);
  fIDTree->SetBranchAddress("WID",&fID);
 
  fCurrEntry=0;
  fIsSorted=kFALSE;
  fN=fWTree->GetEntries();
  // delete file_wts;file_wts=nullptr;  
  //wfile->Close();
  //delete wfile;wfile=nullptr;
}

////////////////////////////////////////////////////////////
///Given a tree selection weight events that pass with wgt
///and enter the weight into this object
void Weights::WeightBySelection(TTree* tree,TCut cut,Double_t wgt){
  TDirectory *saveDir=gDirectory;
  if(fFile) fFile->cd();
  //Find events which pass cut
  tree->Draw(">>wlist",cut,"entrylist");
  TEntryList *elist =nullptr; 
  elist=dynamic_cast<TEntryList*>(gDirectory->Get("wlist"));
  elist->Print();
  Long64_t listEntries = elist->GetN();
  //Now only want ID branch
  tree->SetBranchStatus("*",0);
  tree->SetBranchStatus(fIDName,1);
  Double_t wID=0;
  tree->SetBranchAddress(fIDName,&wID);
  
  tree->SetEntryList(elist,"");
  //loop over events which passed cut
  for (Long64_t el = 0; el < listEntries; el++) {
    Long64_t entryNumber = tree->GetEntryNumber(el);
    tree->GetEntry(entryNumber);
    FillWeight(wID,wgt);
  }
  delete elist;elist=nullptr;
  tree->SetEntryList(nullptr);
  
  //turn all branches back on
  tree->ResetBranchAddresses();
  tree->SetBranchStatus("*",1);
  cout<<"Weights::WeightBySelection Added "<<listEntries<<" events with a weight of "<<wgt<<" from selection " <<cut<<endl;
  saveDir->cd();
}


////////////////////////////////////////////////////////////
///Given a tree selection weight events that pass with wgt
///and enter the weight into this object. wgt is a branch in the tree
void Weights::WeightBySelection(TTree* tree,TCut cut,TString wgt){
  TDirectory *saveDir=gDirectory;
  if(fFile) fFile->cd();
  //Find events which pass cut
  tree->Draw(">>wlist",cut,"entrylist");
  TEntryList *elist =nullptr; 
  elist=dynamic_cast<TEntryList*>(gDirectory->Get("wlist"));
  elist->Print();
  Long64_t listEntries = elist->GetN();
  //Now only want ID branch
  tree->SetBranchStatus("*",0);
  tree->SetBranchStatus(fIDName,1);
  tree->SetBranchStatus(wgt,1);
  Double_t wID=0;
  Double_t eventWeight;
  tree->SetBranchAddress(fIDName,&wID);
  tree->SetBranchAddress(wgt,&eventWeight);
  
  tree->SetEntryList(elist,"");
  //loop over events which passed cut
  for (Long64_t el = 0; el < listEntries; el++) {
    Long64_t entryNumber = tree->GetEntryNumber(el);
    tree->GetEntry(entryNumber);
    FillWeight(wID,eventWeight);
  }
  delete elist;elist=nullptr;
  tree->SetEntryList(nullptr);
  
  //turn all branches back on
  tree->ResetBranchAddresses();
  tree->SetBranchStatus("*",1);
  cout<<"Weights::WeightBySelection Added "<<listEntries<<" events with a weight taken from branch " << wgt << " from tree " << tree->GetName() << " according to selection " <<cut<<endl;
  saveDir->cd();
}

////////////////////////////////////////////
///This creates a new file with a copy of the original tree + wname
filed_uptr  Weights::DFAddToTree(TString wname,TString outfname,TString tname,TString infname){
  //  ROOT::RDataFrame df(tname.Data(),fname.Data(),{GetIDName().Data()});
  Int_t isp=GetSpeciesID(wname);
  auto applyWeights = [this,&isp](double id ) {
    GetEntryBinarySearch((Long64_t)id);
    return (double)(GetWeight(isp));
  };
  ROOT::RDataFrame df(tname.Data(),infname.Data(),{GetIDName().Data()});
  // df.Define(wname,applyWeights);
  //  return DFdef_uptr(new DFdef_t(df.Define(wname.Data(),applyWeights)));
  df.Define(wname.Data(),applyWeights).Snapshot(tname.Data(),outfname.Data());

  return std::move(FiledTree::Read(tname.Data(),outfname.Data()));
 }
/////////////////////////////////////////////
// void Weights::AddToTree(TString outfname,TString tname,TString infname){

// }
void Weights::AddToTree(TTree* tree){
  vector<TBranch*> branches;
  tree->SetBranchStatus("*",0);
  tree->SetBranchStatus(fIDName,1);

  const UInt_t Nsp=fSpecies.size();
  for(UInt_t i=0;i<Nsp;i++)
    branches.push_back(tree->Branch(GetSpeciesName(i),&fWVals[i]));
 

  auto id_leaf=tree->GetLeaf(fIDName);
  if(!id_leaf) {
    cout<<" ERROR Weights::AddToTree weights idname not found in tree : " <<fIDName<<endl;
    tree->Print();
  }
  
  auto Nentries=tree->GetEntries();
  for(Long64_t ient=0;ient<Nentries;ient++){
    tree->GetEntry(ient);
 
    GetEntryBinarySearch((Long64_t)id_leaf->GetValue());
 
    if(!GotEntry())
      for(UInt_t ivec=0;ivec<Nsp;ivec++)
	fWVals[ivec]=0;
 
    for(auto* br: branches)
      br->Fill();
  }
 
  tree->ResetBranchAddresses();

}
void Weights::AddToTreeDisc(TTree* tree,TString fileName){
  TDirectory* saveDir=gDirectory;
  fBranchFile=TFile::Open(fileName,"recreate");

  vector<TBranch*> branches;
  tree->SetBranchStatus("*",0);
  tree->SetBranchStatus(fIDName,1);

  const UInt_t Nsp=fSpecies.size();
  for(UInt_t i=0;i<Nsp;i++){
    TBranch* branch=tree->Branch(GetSpeciesName(i),&fWVals[i]);
    branch->SetFile(fBranchFile);
    branches.push_back(branch);
  }

  auto id_leaf=tree->GetLeaf(fIDName);
  if(!id_leaf) {
    cout<<" ERROR Weights::AddToTree weights idname not found in tree : " <<fIDName<<endl;
    tree->Print();
  }
  
  auto Nentries=tree->GetEntries();
  for(Long64_t ient=0;ient<Nentries;ient++){
    tree->GetEntry(ient);
 
    GetEntryBinarySearch((Long64_t)id_leaf->GetValue());
 
    if(!GotEntry())
      for(UInt_t ivec=0;ivec<Nsp;ivec++)
	fWVals[ivec]=0;
 
    for(auto* br: branches)
      br->Fill();
  }
 
  tree->ResetBranchAddresses();
  saveDir->cd();
}

