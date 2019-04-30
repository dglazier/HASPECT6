#include "MVASignalID.h"
#include <TDataMember.h>


void HS::MVASignalID::CreateResult(TString methname,TString dirname){
  SetVarLinks();
  //Create mva result giving directory, method and links
  fResult.reset(new HS::MVA::ResultByRefLink(dirname,methname,fParticleLinks));
 }
//////////////////////////////////////////////////////////////
///Loop over particle data and connect the reference to each
///data member to its name in fParticleLinks
void HS::MVASignalID::SetVarLinks() {
  std::map<TString,TString> typelabel;
  typelabel["Double_t"]="/D";typelabel["double"]="/D";
  typelabel["Float_t"]="/F";typelabel["float"]="/F";
  typelabel["Int_t"]="/I";typelabel["int"]="/I";
  typelabel["Long64_t"]="/L";typelabel["long64"]="/L";
  typelabel["Short_t"]="/S"; typelabel["short"]="/S";

  auto sizeOfShort=2;
  Int_t n=0;

  for(auto& pdata : fPData){ //loop over particle data
    auto dmList= pdata.Class()->GetListOfDataMembers();
    auto pname=pdata.GetName();
    for(Int_t i=0;i<dmList->GetEntries();i++){ //loop over data members
        auto member=dynamic_cast<TDataMember*> (dmList->At(i));
	auto mtype=TString(member->GetFullTypeName());
	if(typelabel.find(mtype)==typelabel.end())
	  continue; //only include basic types
	auto moffset = member->GetOffset()/sizeOfShort;
  	TString mname=member->GetName();
	auto pvname=pname+mname;
	//add to map connect var name and reference
	fParticleLinks[pvname]=(Float_t*)(((Short_t*)&(pdata))+moffset);
    }
  }
}
