////////////////////////////////////////////////////////////////
///
///Class:               ComponentsPdfParser
///Description:   Construct ComponentsPdf string
///

#pragma once
#include "PdfParser.h"

namespace HS{
  namespace PARSER{

   class ComponentsPdfParser : public PdfParser {
      
      
    public:
    ComponentsPdfParser(string name):PdfParser(name){};
      
   
      //Deal with HS::FIT
      string ConstructPDF(string str) override;
      string NextComponentsTerm(string str, size_t& pos, size_t& tpos);
       
    private :

       
      
    };//class ComponentsPdfParser

  
  }
}
