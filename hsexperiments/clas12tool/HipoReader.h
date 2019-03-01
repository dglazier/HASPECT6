
#ifndef HS_HIPOREADER_h
#define HS_HIPOREADER_h

#include <iostream>
#include <fstream>

#include "THSParticle.h"
#include "DataManager.h"
#include "EventInfo.h"
#include "RunInfo.h"
#include "THipo.h"

namespace HS{
  namespace CLAS12{

    class HipoReader: public DataManager{
      
    public :
      HipoReader();
      virtual ~HipoReader(){if(fHipo) delete fHipo;};
      
      Bool_t Init(TString filename,TString name="") override;
      Bool_t ReadEvent(Long64_t entry=0) override;
      void CloseReadTree() override;
      void InitOutput(TString filename) override;
      void CloseOutput() override;
      
      Int_t GetRunNumber(TString filen);
      void SetCombineFiles(Bool_t setf=kTRUE){fCombineFiles=kTRUE;};
      
    protected :
      
      THipo *fHipo=nullptr;
      
      THipoBank *fPBank=nullptr;
      THipoBank *fSBank=nullptr;
      THipoBank *fCalBank=nullptr;
      THipoBank *fChBank=nullptr;
      THipoBank *fMCBank=nullptr;
      THipoBank *fFTBank=nullptr;
      THipoBank *fEvBank=nullptr;
      THipoBank *fTrBank=nullptr;
      THipoBank *fTBTrBank=nullptr;
      THipoBank *fCVTrBank=nullptr;
      //  THipoBank *fCVTBank=nullptr;
      THipoBank *fFTCALClustBank=nullptr;
      //fHipo->GetBank("FTCAL::clusters");
      
      THipoItemI* fPid=nullptr;
      THipoItemF* fPx=nullptr;
      THipoItemF* fPy=nullptr;
      THipoItemF* fPz=nullptr;
      THipoItemF* fVx=nullptr;
      THipoItemF* fVy=nullptr;
      THipoItemF* fVz=nullptr;
      THipoItemF* fBeta=nullptr;
      THipoItemB* fCharge=nullptr;
      THipoItemS* fStatus=nullptr;
      
      THipoItemS* fSPindex=nullptr;
      THipoItemF* fSTime=nullptr;
      THipoItemB* fSSector=nullptr;
      THipoItemF* fSEnergy=nullptr;
      THipoItemB* fSDet=nullptr;
      THipoItemB* fSLayer=nullptr;
      THipoItemF* fSPath=nullptr;
      
      THipoItemS* fCalPindex=nullptr;
      THipoItemF* fCalEnergy=nullptr;
      THipoItemF* fCalTime=nullptr;
      THipoItemF* fCalPath=nullptr;
      THipoItemB* fCalLayer=nullptr;
      
      THipoItemS* fChPindex=nullptr;
      THipoItemF* fChEnergy=nullptr;
      THipoItemB* fChDetector=nullptr;
      
      THipoItemS* fTrPindex=nullptr;
      THipoItemS* fTrIndex=nullptr;
      THipoItemS* fTrNDF=nullptr;
      THipoItemB* fTrDet=nullptr;
      THipoItemB* fTrq=nullptr;
      THipoItemF* fTrChi2=nullptr;
      
      THipoItemS* fTBTrNDF=nullptr;
      THipoItemF* fTBTrChi2=nullptr;
      THipoItemS* fCVTrNDF=nullptr;
      THipoItemF* fCVTrChi2=nullptr;
      
      THipoItemS* fFTPindex=nullptr;
      THipoItemF* fFTTime=nullptr;
      THipoItemF* fFTEnergy=nullptr;
      THipoItemB* fFTDet=nullptr;
      THipoItemF* fFTPath=nullptr;
      THipoItemF* fFTX=nullptr;
      THipoItemF* fFTY=nullptr;
      THipoItemF* fFTZ=nullptr;
      
      THipoItemF* fRecEvSTTime=nullptr;
      
      THipoItemI* fMCPid=nullptr;
      THipoItemF* fMCPx=nullptr;
      THipoItemF* fMCPy=nullptr;
      THipoItemF* fMCPz=nullptr;
      THipoItemF* fMCVx=nullptr;
      THipoItemF* fMCVy=nullptr;
      THipoItemF* fMCVz=nullptr;
      
      THipoItemF* fFTCALClust_t=nullptr;
      
      Bool_t fCombineFiles=kFALSE;
      Int_t fRunNumber=0;
      
      CLAS12::EventInfo *fEventInfo=nullptr;
      CLAS12::RunInfo *fRunInfo=nullptr;
    
    
    };//	class HipoReader
  }//namespace CLAS12
}//namespace HS
#endif //
