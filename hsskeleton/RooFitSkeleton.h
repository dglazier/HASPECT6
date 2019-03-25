#ifndef HS_ROOFITSKELETON_h
#define HS_ROOFITSKELETON_h

#include "Skeleton.h"
#include <TObjArray.h>

namespace HS{
  
  class RooFitSkeleton : public Skeleton  {
    
    
  public :
    
    RooFitSkeleton()=default;
    virtual ~RooFitSkeleton()=default;
    
  public :
    
    void MakeCode() override;

    void CreateRooFitEventsPDF(TString pdfName,TString obsNames,TString parNames);

  protected:

 
 };
}//namespace HS

#endif 
