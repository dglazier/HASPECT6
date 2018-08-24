// Author: Michael Williams 2018 
   
/**********************************************************************************
* Project: THSMVA                                                                *
* Package:                                                                       *
* Class  : THSMVA                                                                *
*                                                                                *
* Description:                                                                   *
*     Base class for MVA analysis within THSFinalState                           *
*     Derived classes THSMVAPrep, THSMVATrain and THSMVAApp are responsible      *
*     for preparing training tree and getting the reader response respectively   *
*     This class inherits from TObject so can be saved to root file              *
*     and retrieved later                                                        *
*                                                                                *
**********************************************************************************/

#ifndef THSMVA_h
#define THSMVA_h

#include <iostream>
#include <TNamed.h>
#include <TString.h>
#include <TTree.h>
#include <vector>

#include "TMVA/Types.h"

using namespace std;

class Method {

    protected:

        TMVA::Types::EMVA fMethodType; // method type for factory
        TString fMethodName;           // name for saving dataset
        TString fMethodParameters;     // string of parameters for factory
        // return functions
    public:

        void SetName(TString name) {fMethodName = name;};
        void SetType(TMVA::Types::EMVA type) {fMethodType = type;};
        void SetParameters(TString params) {fMethodParameters = params;};
        

        TMVA::Types::EMVA GetType() const {return fMethodType;};
        TString GetName() const {return fMethodName;};
        TString GetParameters() const {return fMethodParameters;};
};

class Split {

    public:
        Split();

    protected:

        UInt_t fSplitNelements = 0; // Number of variables for split
        TString fSplitName = "";         // Name of split for dataset directory
        TString fTreeSplit = "";         // String for spliting tree
        std::vector<TString> fSplitVariableNames; // Names of variables to split on
        std::vector<Int_t>   fSplitVariables;     // Values of variables (ints for now ) TODO : other types
        std::vector<Int_t *> fSplitPointers; // Pointers for the splits
        std::vector<Int_t> fSplitParticles;  // Particles in this split
        // Following variables make reader setup easier
        std::vector<std::vector<TString>>   fSplitMVAVariables; // Variables to add to tree
        std::vector<std::vector<Float_t>>   fSplitMVATreeVars;  // Variables used to fill tree

    public:
        // initial constructor
        Split(TString inputName, std::vector<TString> inputVariableNames, std::vector<Int_t> values);
        // functions for setting variables
        void AddMVAVariables(std::vector<std::vector<TString>> names, std::vector<std::vector<Float_t>> treeVars);
        void SetPointer(std::vector<Int_t *> p) {fSplitPointers = p;};
        void SetParticles(std::vector<Int_t> p) {fSplitParticles = p;};

        TString CheckPointers() const {return fSplitPointers.empty() ? "False" : "True";};
        TString GetTreeSplit();
        TString GetSplitName() const {return fSplitName;};
        // return fucntions
        std::vector<TString> GetVariableNames() {return fSplitVariableNames;};
        std::vector<Int_t> GetVariables() const {return fSplitVariables;};
        std::vector<Int_t *> GetPointers() const {return fSplitPointers;};
        std::vector<Int_t> GetParticles() const {return fSplitParticles;};
        std::vector<std::vector<TString>> GetMVAVariables() const {return fSplitMVAVariables;};

        UInt_t GetN() const {return fSplitNelements;};
};

// TODO: consider making class for variable, parameter and properties

class THSMVA : public TNamed {

    public :
        THSMVA();
        ~THSMVA()=default;
        THSMVA(TString name) : TNamed(name,name){};
  
    protected :
        // counters
        Int_t fParticleCount = 0;
        Int_t fVariableCount = 0;
        Int_t fCounter = 0;
        UInt_t fParticlesAdded = 0;
        // bools 
        Bool_t fSplitTopologies = false;
        Bool_t fPrintVariables=true;
        // vectors for setting up variables
        std::vector<TString> fVariableID = {"Time", "Edep","DeltaE", "PreE", "P", "Th", "Phi", "Vz", "TrChi2", "Det"};
        std::vector<TString> fTypes = {"F", "F", "F", "F", "F", "F", "F", "F", "F", "I"};
        std::vector<TString> fParticleID = {"El", "P", "Pip", "Pim"};
        // vectors for selecting particles for splits 
        // vectors for default particles for topologies (0-3)
        std::vector<Int_t> fElTopologies = {0, 1, 2, 3};
        std::vector<Int_t> fPTopologies = {0, 1, 2};
        std::vector<Int_t> fPipTopologies = {0, 1, 3};
        std::vector<Int_t> fPimTopologies = {0, 2, 3};
        std::vector<Int_t> fSelectedParticles; // vec that will contain particles to use if spliting
        // vectors for traning and application setup 
        std::vector<Method> fMethods;
        std::vector<Split> fSplits;
        // vectors of variables  
        static std::vector<std::vector<TString>> fNames;        // names for branches for tree
        static std::vector<std::vector<TString>> fVarNames;     // names for branches for tree
        static std::vector<std::vector<TString>> fSelectNames;  // vec of reduced set of names
        static std::vector<std::vector<Float_t>> fTreeVarsF;    // Float_t type variables for tree
        std::vector<std::vector<Int_t>> fTreeVarsI;             // Int_t type variables for tree
        std::vector<std::vector<Int_t>> fParticleTopologies;    // topologies for each each particle

    public:
        ClassDef(THSMVA,1); //class THSParticle
        
        // functions to set variables
        void SetVariables(std::vector<TString> tmpVariables) {fVariableID = tmpVariables;};
        void SetTypes(std::vector<TString> tmpTypes) {fTypes = tmpTypes;};
        void SetParticles(std::vector<TString> tmpParticles) {fParticleID = tmpParticles;};

        void AddParticle(TString name, std::vector<TString> variables, std::vector<TString> types);

        void SetSplits(std::vector<Split> splits) {fSplits = splits;};
        void SetMethods(std::vector<Method> methods) {fMethods = methods;};

        void SetNames();    // set names from variables and particles
        void SetNames(std::vector<std::vector<TString>> names) {fNames = names;};

        void SetTopologies();   // set topologies for each particle given particles
        void SetTopologies(std::vector<std::vector<Int_t>> topologies) {fParticleTopologies = topologies;};
        
        //functions to return variables
        std::vector<Split> GetSplits() const {return fSplits;};
        std::vector<Method> GetMethods() const {return fMethods;};

        void GetNamesTopo(Int_t Topology);
        void GetNames();

        // print functions
        void PrintVar();
        void PrintTopologies();
        void PrintSplits();

};

#endif //
