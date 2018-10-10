
#ifndef HS_SKELETON_h
#define HS_SKELETON_h

#include <TString.h>
#include <TObjString.h>
#include <TMacro.h>


namespace HS{
  
  class Skeleton   {
    
    
  public :
    
    Skeleton()=default;
    virtual ~Skeleton()=default;

    virtual void MakeCode()=0;
    
    void AddLineAfter(TString line0,TString line1,Int_t off=0);
    void ContinueLineAfter(TString line1,Int_t off=0);
    void MoveToLine(TString line0);
    TString FindNextLineLike(TString linelike);
    void ReplaceMacroText(TString text0,TString text1);
    void ReplaceAllMacroText(TString text0,TString text1);
    void ReplaceInCurrLine(TString text0,TString text1);


  protected:
    TMacro fCurMacro;
    Int_t fPlace=0;
    TString fOption;
    

  };
}

#endif 
