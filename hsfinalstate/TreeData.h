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
#include <TList.h>

namespace HS{
  
  class TreeData  : public TObject{

  public:
    TreeData(TString name){fName=name;}
    TreeData(){fName=ClassName();}
    virtual ~TreeData()=default;
    
    void Branches(TTree* tree,TList* dmList);
    virtual void Branches(TTree* tree)=0;

     
  private:
    TString fName="TreeData";//!

    ClassDef(TreeData,1);

  };//class TreeData

  /* void   BranchTreeData(TTree* tree,TreeData* data){ */
  /*   //First make a tree with the branches we need */
  /*   TTree fakeTree("fakeTree","fakeTree"); */
  /*   fakeTree.Branch(data->GetName(),data); */

  /*   std::map<TString , TString > mapTypeTitle; */
  /*   mapTypeTitle["Double_t","/D"];mapTypeTitle["double","/D"]; */
  /*   mapTypeTitle["Float_t","/F"];mapTypeTitle["float","/F"]; */
  /*   mapTypeTitle["Int_t","/I"];mapTypeTitle["int","/I"]; */
  /*   mapTypeTitle["Long64_t","/L"];mapTypeTitle["long64","/L"]; */
  /*   mapTypeTitle["Short_t","/S"]; mapTypeTitle["short","/S"]; */

 
  /*   auto leaves=tree->GetListOfLeaves(); */
  /*   fakeTree.SetMakeClass(1); //allows setbranchaddress to link to TreeData			  */
  /*   for(Int_t il=3;il<leaves.GetEntries();il++){ */
  /*     TString typename=((TLeaf*)leaves->At(il))->GetTypeName(); */
  /*     TString branchname=((TLeaf*)leaves->At(il))->GetName(); */
  /*     if(typename==TString("Double_t")){ */
  /* 	Double_t varD=0;  */
  /* 	fakeTree.SetBranchAddress(branchname,mapTypeTitle[]); */
  /*     tree->Branch(); */
  /*   } */

      
  /* } */
}//namespace HS

#endif
