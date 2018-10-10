////////////////////////////////////////////////////////////////
///
///Class:               TreeData
///Description:
///            A base class to be used as a tree branch !
///            Inherit from this and add data members to the derived class
///            Then call dervived.Branches(tree,&derived);
///            to attach to tree

#ifndef HS_TREEDATA_h
#define HS_TREEDATA_h


#include <TTree.h>
#include <TString.h>
#include <TObject.h>

namespace HS{
  
  class TreeData  : public TObject{

  public:
    TreeData(TString name){fName=name;}
    TreeData(){fName=ClassName();}
    virtual ~TreeData()=default;
    
    void Branches(TTree* tree,TreeData* data){
      tree->Branch(data->GetName(),data);
    }

    //TString GetName() override {return fName;}
    
  private:
    TString fName="TreeData";//!

    ClassDef(TreeData,1);

  };//class TreeData
}//namespace HS

#endif
