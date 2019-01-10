#include "FiledTree.h"

using namespace HS;

FiledTree::~FiledTree(){
  std::cout<<"       tree name "<<fTree->GetName()<<" "<<fTree->GetEntries()<<" "<<fFile->GetName()<<endl;
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
}
filed_uptr FiledTree::Recreate(TString tname,TString fname){
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"recreate");
  f->CreateTree(tname);
  f->SetMode(Mode_t::recreate);
  f->SetTreeDirectory();
  return f;
}
filed_uptr FiledTree::Read(TString tname,TString fname){
  filed_uptr f{new FiledTree()};
  auto file=TFile::Open(fname,"read");
  auto tree=dynamic_cast<TTree*>(file->Get(tname));
  f->SetFile(std::move(file));
  f->SetTree(std::move(tree));
  f->SetMode(Mode_t::read);
  f->SetTreeDirectory();
  return f;
}
filed_uptr FiledTree::Update(TString tname,TString fname){
  filed_uptr f{new FiledTree()};
  auto file=TFile::Open(fname,"update");
  auto tree=dynamic_cast<TTree*>(file->Get(tname));
  f->SetFile(std::move(file));
  f->SetTree(std::move(tree));
  f->SetMode(Mode_t::update);
  f->SetTreeDirectory();
  return f;
}
filed_uptr FiledTree::Create(TString tname,TString fname){
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"create");
  f->CreateTree(tname);
  f->SetMode(Mode_t::create);
  f->SetTreeDirectory();
  return f;
}
filed_uptr FiledTree::CopyEmpty(TTree* tree,TString fname){
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"create");
  f->SetTree(tree->CloneTree(0));
  f->SetMode(Mode_t::copyempty);
  f->SetTreeDirectory();
  return f;
}
filed_uptr FiledTree::CopyFull(TTree* tree,TString fname){
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"create");
  f->SetTree(tree->CloneTree(-1,"fast"));
  f->SetMode(Mode_t::copyfull);
  f->SetTreeDirectory();
  return f;
}
filed_uptr FiledTree::CopyEmpty(ttree_ptr tree,TString fname){
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"create");
  f->SetTree(tree->CloneTree(0));
  f->SetMode(Mode_t::copyempty);
  f->SetTreeDirectory();
 return f;
}
filed_uptr FiledTree::CopyFull(ttree_ptr tree,TString fname){
  filed_uptr f{new FiledTree()};
  f->CreateFile(fname,"create");
  f->SetTree(tree->CloneTree(-1,"fast"));
  f->SetMode(Mode_t::copyfull);
  f->SetTreeDirectory();
  return f;
}
