//Datareader class for converting Lund format txt files
//into THSParticles
#pragma once

#include <iostream>
#include <fstream>

#include "THSParticle.h"
#include "DataManager.h"

namespace HS{
  
  class StarLightReader: public DataManager{
    
  public :
    StarLightReader(){};
    virtual ~StarLightReader(){fTxtIn.close();};
    
    Bool_t Init(TString filename,TString name="") override;
    Bool_t ReadEvent(Long64_t entry=0) override;
      
    
  private :
    
    ifstream fTxtIn; //input text file stream
    
  public :
    
    
  };
}
