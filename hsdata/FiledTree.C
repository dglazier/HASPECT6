#include "FiledTree.h"
#include <TDirectory.h>

using namespace HS;

FiledTree::~FiledTree(){
  std::cout<<"FiledTree::~FiledTree()  tree name "<<fTree->GetName()<<" "<<fTree->GetEntries()<<" "<<fFile->GetName()<<endl;
  if(fMode==Mode_t::recreate||fMode==Mode_t::create||
     fMode==Mode_t::update||fMode==Mode_t::copyfull||
     fMode==Mode_t::copyempty){
    if(fFile){ 
      fFile->cd();
      if(fFile->IsWritable())
	Tree()->Write();
      else{
	std::cout<<"Warning deleting FiledTree but can't write to file!"<<endl;
	std::cout<<"        this may mean you are letting ROOT cleanup "<<endl;
	std::cout<<"        this object (i.e. after .q) rather than calling"<<endl;
	std::cout<<"        its destructor somewhere in your code..."<<endl;
	std::cout<<"       tree name "<<fTree->GetName()<<" "<<fFile->GetName()<<endl;
      }
    }
  }
  fTree.reset();
}
filed_uptr FiledTree::Recreate(TString tname,TString fname){
  auto saveDir=gDirectory;
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"recreate");
  f->CreateTree(tname);
  f->SetMode(Mode_t::recreate);
  f->SetTreeDirectory();
  saveDir->cd();
  return f;
}
filed_uptr FiledTree::Read(TString tname,TString fname){
  auto saveDir=gDirectory;
  filed_uptr f{new FiledTree()};
  auto file=TFile::Open(fname,"read");
  auto tree=dynamic_cast<TTree*>(file->Get(tname));
  f->SetFile(std::move(file));
  f->SetTree(std::move(tree));
  f->SetMode(Mode_t::read);
  f->SetTreeDirectory();
  saveDir->cd();
  return f;
}
filed_uptr FiledTree::Update(TString tname,TString fname){
  auto saveDir=gDirectory;
  filed_uptr f{new FiledTree()};
  auto file=TFile::Open(fname,"update");
  auto tree=dynamic_cast<TTree*>(file->Get(tname));
  f->SetFile(std::move(file));
  f->SetTree(std::move(tree));
  f->SetMode(Mode_t::update);
  f->SetTreeDirectory();
  saveDir->cd();
  return f;
}
filed_uptr FiledTree::Create(TString tname,TString fname){
  auto saveDir=gDirectory;
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"create");
  f->CreateTree(tname);
  f->SetMode(Mode_t::create);
  f->SetTreeDirectory();
  saveDir->cd();
  return f;
}
filed_uptr FiledTree::CloneEmpty(TTree* tree,TString fname){
  auto saveDir=gDirectory;
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"create");
  f->SetTree(tree->CloneTree(0));
  f->SetMode(Mode_t::copyempty);
  f->SetTreeDirectory();
  saveDir->cd();
  return f;
}
filed_uptr FiledTree::CloneFull(TTree* tree,TString fname){
  auto saveDir=gDirectory;
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"create");
  f->SetTree(tree->CloneTree(-1,"fast"));
  f->SetMode(Mode_t::copyfull);
  f->SetTreeDirectory();
  saveDir->cd();
  return f;
}
filed_uptr FiledTree::CloneEmpty(ttree_ptr tree,TString fname){
  auto saveDir=gDirectory;
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"create");
  f->SetTree(tree->CloneTree(0));
  f->SetMode(Mode_t::copyempty);
  f->SetTreeDirectory();
  saveDir->cd();
  return f;
}
filed_uptr FiledTree::CloneFull(ttree_ptr tree,TString fname){
  auto saveDir=gDirectory;
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"create");
  f->SetTree(tree->CloneTree(-1,"fast"));
  f->SetMode(Mode_t::copyfull);
  f->SetTreeDirectory();
  saveDir->cd();
  return f;
}
filed_uptr FiledTree::RecreateCopyFull(ttree_ptr tree,TString fname){
  //using copy tree allows use of tentrylists to filter
  auto saveDir=gDirectory;
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"recreate");
  f->SetTree(tree->CopyTree(""));
  f->SetMode(Mode_t::copyfull);
  f->SetTreeDirectory();
  saveDir->cd();
  return f;
}
filed_uptr FiledTree::RecreateCopyFull(TTree* tree,TString fname){
  auto saveDir=gDirectory;
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"recreate");
  f->SetTree(tree->CopyTree(""));
  f->SetMode(Mode_t::copyfull);
  f->SetTreeDirectory();
  saveDir->cd();
  return f;
}
