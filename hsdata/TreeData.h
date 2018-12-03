////////////////////////////////////////////////////////////////
///
///Class:               TreeData
///Description:
///            A base class to be used as a tree branch !
///            Inherit from this and add data members to the derived class
///            Then call dervived.Branches(tree);
///            To select data members to tree branch use
///            TreeData::SetBranches({"ThisOne","ThisTwo"});
///            to attach to tree

#ifndef HS_TREEDATA_h
#define HS_TREEDATA_h


#include <TTree.h>
#include <TString.h>
#include <TObject.h>
#include <TList.h>

namespace HS{
  
  class TreeData  {

  public:
    TreeData(TString name){fName=name;}
    TreeData()=default;
    TreeData(const TreeData&)=default;
    TreeData(TreeData&&)=default;
    virtual ~TreeData()=default;
    
    void Branches(TTree* tree,TList* dmList);
    virtual void Branches(TTree* tree)=0;

    TString GetName(){return fName;}
    void SetBranches(vector<TString > brs){fForBranch=brs;}

  private:
    TString fName="";//!
    vector<TString > fForBranch;//!
  
    ClassDef(TreeData,1);

  };//class TreeData


}//namespace HS

#endif
