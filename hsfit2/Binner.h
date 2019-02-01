////////////////////////////////////////////////////////////////
///
///Class:               Binner
///Description:
///           

#ifndef HS_FIT_BINNER_h
#define HS_FIT_BINNER_h

#include "Bins.h"
#include "Setup.h"

namespace HS{
  namespace FIT{

    using strings_t = std::vector<TString>;

    class Binner  {
      
    public:
      Binner(Setup& setup);
      Binner() =default;
      Binner(const Binner&)=default;
      Binner(Binner&&)=default;
      virtual ~Binner()=default;
      Binner& operator=(const Binner& other)=default;
      Binner& operator=(Binner&& other) = default;

      void ReloadData(TString fname,TString name);
      void SplitData(TTree* tree,TString name="Data");
      void SplitData(TString tname,TString fname,TString name="Data");
      void LoadAuxVar(TString vname);
      void LoadBinVar(TString opt,Int_t nbins,Double_t min,Double_t max);

      void LoadSetup(Setup &setup);

      const TString TreeName(const TString name="Data") const {
	if(fNameToTree.count(name))
	  return fNameToTree.at(name);
	std::cout<<"Binner::TreeName files  named "<<name<<" not found"<<std::endl;
	return TString();

      }
      const strings_t FileNames(const TString name="Data") const {
	if(fNameToFiles.count(name))
	  return fNameToFiles.at(name);
	std::cout<<"Binner::FileNames files  named "<<name<<" not found"<<std::endl;
	return strings_t();
      }

      const TString BinName(UInt_t i) const {
	return fBinNames[i];
      }
      UInt_t GetSize(){return fBinNames.size();}
      
      Bool_t IsSetup(){return fIsSetup;}

  
    protected:
      
    private:
      Bins fBins;

      strings_t fBinNames;
      strings_t fVarNames;
      std::map<TString, strings_t> fNameToFiles;
      std::map<TString, TString> fNameToTree;
  
      TString fOutDir;
      Bool_t fIsSetup=kFALSE;
      
    };
    
  }//namespace FIT
}//namespace HS

#endif
