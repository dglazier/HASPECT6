////////////////////////////////////////////////////////////////
///
///Class:               Manager
///Description:
///           

#ifndef HS_FIT_MANAGER_h
#define HS_FIT_MANAGER_h

#include "Setup.h"
#include "Data.h"
#include "Binner.h"

namespace HS{
  namespace FIT{
  
    class Manager  {
      
    public:
      Manager()=default;
      Manager(const Manager&)=default;
      Manager(Manager&&)=default;
      virtual ~Manager()=default;
      Manager& operator=(const Manager& other)=default;
      Manager& operator=(Manager&& other) = default;

      const Setup &SetUp() const{return fSetup;};
      const Binner &Bins() const{return fBinner;};

      virtual void Run(UInt_t ifit);
      virtual void RunAll();
      
    protected:
      
    private:
      
      Setup fSetup;
      Binner fBinner;
      DataEvents fData;
      //Minimiser fFitter;
      //Results fResults;
      //
      
    };

    /* class sPlot : public Manager { */
    /* public: */
    /*   sPlot()=default; */
    /*   sPlot(const sPlot&)=default; */
    /*   sPlot(sPlot&&)=default; */
    /*   virtual ~sPlot()=default; */
    /*   sPlot& operator=(const sPlot& other)=default; */
    /*   sPlot& operator=(sPlot&& other) = default; */
      
    /*   Setup &Setup() const{return fSetup;}; */
    /*   Binner &Binner() const{return fBinner;}; */
    /* protected: */
      
    /* private: */
  
    /* }; //class sPlot */
  }//namespace FIT
}//namespace HS

#endif
