#include "TreeData.h"
#include "TDataMember.h"
#include <iostream>
#include <map>

////////////////////////////////////////////////////////
/// Make branches in a tree for each datamember
/// we do this rather than just creating an object branch
/// as only this way works in RooFit!

void HS::TreeData::Branches(TTree* tree,TList* dmList){

  std::map<TString,TString> typelabel;
  typelabel["Double_t"]="/D";typelabel["double"]="/D";
  typelabel["Float_t"]="/F";typelabel["float"]="/F";
  typelabel["Int_t"]="/I";typelabel["int"]="/I";
  typelabel["Long64_t"]="/L";typelabel["long64"]="/L";
  typelabel["Short_t"]="/S"; typelabel["short"]="/S";

  auto sizeOfInt=4;
  for(Int_t i=0;i<dmList->GetEntries();i++){
    auto member=dynamic_cast<TDataMember*> (dmList->At(i));
    auto moffset = member->GetOffset()/sizeOfInt;
    auto mtype=TString(member->GetFullTypeName());
    TString mname=fName+member->GetName();
    if(typelabel.find(mtype)==typelabel.end()){
      continue;
    }
    
    if(fForBranch.size()) //if list of allowed branches 
      if(std::find(fForBranch.begin(),fForBranch.end(),mname)==fForBranch.end())
	continue;  //if not in list don't make branch
    //make the branch, giving the address of this member
    tree->Branch(mname,(((int*)&(*this))+moffset),mname+typelabel[mtype]);
    
  }
  
}
