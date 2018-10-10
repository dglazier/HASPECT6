/**
 \class Skeleton
 
 Class to generate skeleton code
 
*/

#include "Skeleton.h"
#include <TSystem.h>
#include <iostream>

using namespace HS;



//////////////////////////////////////////////////////
void Skeleton::AddLineAfter(TString line0,TString line1,Int_t off){
  TList *lines=fCurMacro.GetListOfLines();
  MoveToLine(line0);
  fPlace=fPlace+1+off;
  lines->AddAt(new TObjString(line1),fPlace);
}

void Skeleton::ContinueLineAfter(TString line1,Int_t off){
  TList *lines=fCurMacro.GetListOfLines();
  fPlace=fPlace+1+off;
  lines->AddAt(new TObjString(line1),fPlace);
}

void Skeleton::MoveToLine(TString line0){
  TList *lines=fCurMacro.GetListOfLines();
  TObject* obj=fCurMacro.GetLineWith(line0);
  if(!obj) Error("Skeleton::MoveToLine","Line %s does not exist in %s",line0.Data(),"file");
  fPlace=lines->IndexOf(obj); //get line number
}

TString Skeleton::FindNextLineLike(TString linelike){
  TList *lines=fCurMacro.GetListOfLines();
  TObjString* thisline=0;
  Int_t count=0;
  for(count=fPlace;count<lines->GetEntries();count++){
    thisline=dynamic_cast<TObjString*>(lines->At(count));
    if(thisline->String().Contains(linelike))
      break;
  }
  if(count==lines->GetEntries()) {fPlace=count; return "";} //didn't find line go to end
  else fPlace=count; //get line number
  return thisline->String();
}

void Skeleton::ReplaceInCurrLine(TString text0,TString text1){
  // TString strline=fCurMacro.GetLineWith(text0)->GetString();
  TList *lines=fCurMacro.GetListOfLines();
  TObjString*  thisline=dynamic_cast<TObjString*>(lines->At(fPlace));
  if(!thisline->String().Contains(text0)) cout<<"Warning : ReplaceInCurrLine text not found "<<text0<<" in line "<<thisline->String()<<endl;
  thisline->String().ReplaceAll(text0,text1);
}

void Skeleton::ReplaceMacroText(TString text0,TString text1){
  TString strline=fCurMacro.GetLineWith(text0)->GetString();
  strline.ReplaceAll(text0,text1);
  fCurMacro.GetLineWith(text0)->SetString(strline);
}

void Skeleton::ReplaceAllMacroText(TString text0,TString text1){
  TList *lines=fCurMacro.GetListOfLines();
  TObjString* thisline=0;
  Int_t count=0;
  for(count=fPlace;count<lines->GetEntries();count++){
    thisline=dynamic_cast<TObjString*>(lines->At(count));
    if(thisline->String().Contains(text0))
      thisline->SetString(thisline->String().ReplaceAll(text0,text1));
  }

}
