////////////////////////////////////////////////////////////////
///
///Class:               FiledTree
///Description:
///            A tree connected to its own TFile !
///            An attempt to stop file directory related crashes!
///            Note in interactive root session must create a new
///            object so we can call delete. If you let ROOT delete
///            after .q the file will not be writeable!
 
#ifndef HS_FILEDTREE_h
#define HS_FILEDTREE_h


#include <TTree.h>
#include <TFile.h>
#include <TString.h>
#include <iostream>

namespace HS{
  
  using tfile_ptr=std::shared_ptr<TFile>;
  using ttree_ptr=std::shared_ptr<TTree>;

  class FiledTree  {
    enum class Mode_t{null,recreate,create,read,update,copyempty,copyfull};
    
    using filed_ptr=std::shared_ptr<HS::FiledTree>;
    using filed_uptr=std::unique_ptr<HS::FiledTree>;

  public:
    //////////////////////////////////////////////////////////////////////
    ///Construct a new tree to be branched and filled
    FiledTree(TString tname,TString fname,TString opt="recreate"){
      fFile.reset(TFile::Open(fname,opt));
      fTree.reset(new TTree(tname,"A FiledTree"));
      SetTreeDirectory();
    }
    //////////////////////////////////////////////////////////////////////
    ///Construct a tree based on an existing one
    ///if isfull is true copy all the events, if false just create empty tree
    FiledTree(Bool_t isfull,TTree *tree,TString fname,TString opt="recreate"){
      fFile.reset(TFile::Open(fname,opt));
      if(isfull)fTree.reset(tree->CloneTree(-1,"fast"));
      else fTree.reset(tree->CloneTree(0));
      SetTreeDirectory();
    }
    // FiledTree()=default;
    FiledTree(const FiledTree&)=default;
    FiledTree(FiledTree&&)=default;
    FiledTree& operator=(const FiledTree& other)=default;
    FiledTree& operator=(FiledTree&& other) = default;

    virtual ~FiledTree();
    
    const ttree_ptr Tree() const {return fTree;}
    void Fill(){Tree()->Fill();}

    static filed_uptr Recreate(TString tname,TString fname);
    static filed_uptr Create(TString tname,TString fname);
    static filed_uptr Read(TString tname,TString fname);
    static filed_uptr Update(TString tname,TString fname);
    static filed_uptr CopyEmpty(TTree* tree,TString fname);
    static filed_uptr CopyFull(TTree* tree,TString fname);
    static filed_uptr CopyEmpty(ttree_ptr tree,TString fname);
    static filed_uptr CopyFull(ttree_ptr tree,TString fname);

    void SetMode(Mode_t m){fMode=m;}
    Mode_t Mode(){return fMode;}
    
  protected :

    TFile* File() const {return fFile.get();}
    void SetTreeDirectory(){ Tree()->SetDirectory(File());}
    void CreateFile(TString fname,TString opt){ fFile.reset(TFile::Open(fname,opt));}
    void CreateTree(TString tname){fTree.reset(new TTree(tname,"A FiledTree"));}
    void SetFile(TFile* f){ fFile.reset(f);}
    void SetTree(TTree* t){ fTree.reset(t);}

  private:
    tfile_ptr fFile;//file before tree as is owner
    ttree_ptr fTree;
    Mode_t fMode=Mode_t::null;

    FiledTree()=default;
    
  };

  using filed_ptr=std::shared_ptr<HS::FiledTree>;
  using filed_uptr=std::unique_ptr<HS::FiledTree>;

}//namespace HS
#endif

