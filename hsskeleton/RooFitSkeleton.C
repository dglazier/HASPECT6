
#include "RooFitSkeleton.h"
#include <TSystem.h>
#include <iostream>
#include <RooClassFactory.h>

using namespace HS;

////////////////////////////////////////////////////
void RooFitSkeleton::MakeCode(){
  fPlace=0;

}
void RooFitSkeleton::CreateRooFitEventsPDF(TString pdfName,TString obsNames,TString parNames){
  TObjArray* obss=obsNames.Tokenize(",");
  TObjArray* pars=parNames.Tokenize(",");
  //Check for categories
  vector<Bool_t> is_cat;
  for(Int_t io=0;io<obss->GetEntries();io++)
    if(TString(obss->At(io)->GetName()).Contains("CAT:")){
      TString newstr=obss->At(io)->GetName();
      is_cat.push_back(kTRUE);
      newstr.ReplaceAll("CAT:","");
      dynamic_cast<TObjString*>(obss->At(io))->SetString(newstr); //Get rid of CAT:
      obsNames.ReplaceAll(TString("CAT:")+newstr,newstr);
    }
    else is_cat.push_back(kFALSE);

  TString varNames=obsNames+","+parNames;
  //Make standard RooFit Pdf
  RooClassFactory::makePdf(pdfName,varNames) ;
  //Open code to add RooHSEventsPDF parts
  fCurMacro=TMacro(pdfName+".cxx");
  FindNextLineLike("RooAbsPdf(name,title)");
  ((TObjString*)fCurMacro.GetListOfLines()->At(fPlace))->SetString("   HS::FIT::RooHSEventsPDF(name,title),");
  FindNextLineLike("RooAbsPdf(other,name)");
  ((TObjString*)fCurMacro.GetListOfLines()->At(fPlace))->SetString("   HS::FIT::RooHSEventsPDF(other,name),");
  //Now add observables to ProxSet
  AddLineAfter("{","   MakeSets();");

 
  //Edit text
  for(Int_t io=0;io<obss->GetEntries();io++)
    ContinueLineAfter(TString("   ")+obss->At(io)->GetName()+".SetName(_"+obss->At(io)->GetName()+".GetName());");
  for(Int_t ip=0;ip<pars->GetEntries();ip++)
    ContinueLineAfter(TString("   ")+pars->At(ip)->GetName()+".SetName(_"+pars->At(ip)->GetName()+".GetName());");

  FindNextLineLike("{");
  ContinueLineAfter("   MakeSets();");
  for(Int_t io=0;io<obss->GetEntries();io++)
    ContinueLineAfter(TString("   ")+obss->At(io)->GetName()+".SetName(other."+obss->At(io)->GetName()+".GetName());");
  for(Int_t ip=0;ip<pars->GetEntries();ip++)
    ContinueLineAfter(TString("   ")+pars->At(ip)->GetName()+".SetName(other."+pars->At(ip)->GetName()+".GetName());");
  ContinueLineAfter("   if(fEvTree) SetEvTree(fEvTree,fCut);//Needs fProxSet filled first");
  //Make make sets function need to iterate over obsNames and parNames
  FindNextLineLike("}");
  ContinueLineAfter("void "+pdfName+"::MakeSets(){");
  for(Int_t io=0;io<obss->GetEntries();io++)
    if(!is_cat[io])ContinueLineAfter(TString("   fProxSet.push_back(&")+obss->At(io)->GetName()+");");
    else ContinueLineAfter(TString("   fCatSet.push_back(&")+obss->At(io)->GetName()+");");
  for(Int_t ip=0;ip<pars->GetEntries();ip++)
    ContinueLineAfter(TString("   fParSet.push_back(&")+pars->At(ip)->GetName()+");");
  // ContinueLineAfter("   fVarSet.push_back(RooArgList(\"AllVars\"));");
  ContinueLineAfter("   InitSets();");
  ContinueLineAfter("}");

  //Now evaluateMC template
  MoveToLine("evaluate()");
  FindNextLineLike("}");
  ContinueLineAfter("Double_t "+pdfName+"::evaluateMC(const vector<Float_t> *vars,const  vector<Int_t> *cats) const {",1);
  ContinueLineAfter("// ENTER IDENTICAL EXPRESSION TO evaluate() IN TERMS OF MC VARIABLE ARGUMENTS HERE");
  Int_t nv=0;
  Int_t nc=0;
  for(Int_t io=0;io<obss->GetEntries();io++)
    // if(!is_cat[io]) ContinueLineAfter(TString("  Double_t mc")+obss->At(io)->GetName()+Form("=fMCVar[%d];",nv++));
    //else ContinueLineAfter(TString("  Int_t mc")+obss->At(io)->GetName()+Form("=fMCCat[%d];",nc++));
   if(!is_cat[io]) ContinueLineAfter(TString("  Double_t mc")+obss->At(io)->GetName()+Form("=(*vars)[fTreeEntry*fNvars+%d];",nv++));
    else ContinueLineAfter(TString("  Int_t mc")+obss->At(io)->GetName()+Form("=(*cats)[fTreeEntry*fNcats+%d];",nc++));

  ContinueLineAfter("   return 1.0;");
  ContinueLineAfter("}");
   
  //Done .C file

  //fix categories
  for(Int_t io=0;io<obss->GetEntries();io++)
    if(is_cat[io]){
      fPlace=0;
      FindNextLineLike(obss->At(io)->GetName());
      ReplaceInCurrLine("RooAbsReal","RooAbsCategory");

    }
  fPlace=0;

  fCurMacro.SaveSource(pdfName+".cxx");


  ////////////////////////////////////////////////////////////////////  
  //Now with .h
  fCurMacro=TMacro(pdfName+".h");
  AddLineAfter("RooAbsPdf.h","#include \"RooHSEventsPDF.h\"");

  ReplaceMacroText("public RooAbsPdf","public HS::FIT::RooHSEventsPDF");

    //fix categories
  for(Int_t io=0;io<obss->GetEntries();io++)
    if(is_cat[io]){
      fPlace=0;
      FindNextLineLike(obss->At(io)->GetName());
      ReplaceInCurrLine("RooAbsReal","RooAbsCategory");
      fPlace++;
      FindNextLineLike(obss->At(io)->GetName());
      ReplaceInCurrLine("RooRealProxy","RooCategoryProxy");

    }
  fPlace=0;

  // if(!is_cat[0]) AddLineAfter("protected",TString("  Double_t fMC")+obss->At(0)->GetName()+";");
  // else AddLineAfter("protected",TString("  Int_t fMC")+obss->At(0)->GetName()+";");
  // for(Int_t io=1;io<obss->GetEntries();io++)
  //   if(!is_cat[io]) ContinueLineAfter(TString("  Double_t fMC")+obss->At(io)->GetName()+";");
  //   else  ContinueLineAfter(TString("  Int_t fMC")+obss->At(io)->GetName()+";");
  
  AddLineAfter("Double_t evaluate()","  Double_t evaluateMC(const vector<Float_t> *vars,const  vector<Int_t> *cats) const ;");


  // AddLineAfter("inline virtual ~","  virtual Int_t getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars,const char* rangeName) const;");
  ContinueLineAfter("  void MakeSets();");
  fCurMacro.SaveSource(pdfName+".h");

}
