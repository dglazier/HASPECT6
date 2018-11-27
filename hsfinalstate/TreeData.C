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
    auto mtype=member->GetFullTypeName();
    TString mname=member->GetName();
    if(typelabel.find(mtype)==typelabel.end()){
      std::cout<<" HS::TreeData::Branches(TTree* tree) Type not defined "<<mname<<" "<<mtype<<" branch will be omitted " <<endl;
      continue;
    }
    //make the branch, giving the address of this member
    tree->Branch(mname,(((int*)&(*this))+moffset),mname+typelabel[mtype]);
    
  }
  
}
