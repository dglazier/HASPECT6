//Datareader class for converting Lund format txt files
//into THSParticles
#ifndef HS_LUNDREADER_h
#define HS_LUNDREADER_h

#include <iostream>
#include <fstream>

#include "THSParticle.h"
#include "DataManager.h"

namespace HS{
  
  class LundReader: public DataManager{
    
  public :
    LundReader(){};
    virtual ~LundReader(){fTxtIn.close();};
    
    virtual Bool_t Init(TString filename,TString name="");
    virtual Bool_t ReadEvent(Long64_t entry=0);
    virtual Bool_t ReadGenerated(Long64_t entry=0);
    
    
  private :
    
    ifstream fTxtIn; //input text file stream
    
  public :
    
    
  };
}
#endif //ifdef LUNDREADER
