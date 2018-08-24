// Author: Michael Williams 2018 
    
/**********************************************************************************
* Project: THSMVA                                                                *
* Package:                                                                       *
* Class  : THSMVAApp                                                             *
*                                                                                *
* Description:                                                                   *
*                                                                                * 
*     Apply the trained MVA methods on and event by event basis                  *
*                                                                                *
**********************************************************************************/

#include "THSMVAApp.h"

////////////////////////////////////////////////////////////
/// Constructor 
///////////////////////////////////////////////////////////

THSMVAApp::THSMVAApp(){

    TMVA::Tools::Instance();
    // set output for TMVA
    //fOutputName = "THSMVAApp.root";
    //fOutputFile = TFile::Open(fOutputName, "RECREATE");
    //TMVA::PyMethodBase::PyInitialize();
    //ROOT::R::TRInterface &r = ROOT::R::TRInterface::Instance();
    fOutputTree = new TTree("OutputTree", "OutputTree");
}

/**
 * Initialize appliction from save THSMVA class
 *
 */

void THSMVAApp::Init(THSMVA * setup){
    SetSplits(setup->GetSplits());
    SetMethods(setup->GetMethods());
    SetNames();
}

/**
 * Update the pointers for splits for new addresses
 *
 */

void THSMVAApp::UpdateSplit(TString name, Int_t * pointer){
    if (fSplits.empty()){
        std::cout<<"\033[1;35m warning: \033[0m  No splits to update"<<std::endl;
    }
    else{
        for (UInt_t i=0 ; i<fSplits.size(); i++){
            if (fSplits[i].GetSplitName() == name){
                fSplits[i].SetPointer({pointer});
            }
        }
    }
}

/**
 * Update the pointers for splits for new addresses
 *
 */

void THSMVAApp::UpdateSplit(TString name, std::vector<Int_t *> pointers){
    if (fSplits.empty()){
        std::cout<<"\033[1;35m warning: No splits to update \033[0m\n"<<std::endl;
    }
    else{
        for (UInt_t i=0 ; i<fSplits.size(); i++){
            if (fSplits[i].GetSplitName() == name){
                fSplits[i].SetPointer(pointers);
            }
        }
    }
}

/**
 * Set the pointers to the variables for the MVA Application
 *
 */

void THSMVAApp::AddVarsFromParticle(THSParticle* tmpParticle, Int_t tmpPCount) {

    fVariableCount = 0;

    //need original Variables ID (Time, P, Phi, Th...) form THSMVA
    // different methods depending on varaibles were set
    if (!fVarNames.empty()){
        // allows for different number of variables per particle
        for (auto const& v : fVarNames[tmpPCount]) {
            if (v == "Time") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->DeltaTime(); fVariableCount++;};
            if (v == "Edep") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->Edep(); fVariableCount++;};
            if (v == "DeltaE") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->DeltaE(); fVariableCount++;};
            if (v == "PreE") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->PreE(); fVariableCount++;};
            if (v == "P") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->P4p()->P(); fVariableCount++;};
            if (v == "Th") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->P4p()->Theta(); fVariableCount++;};
            if (v == "Phi") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->P4p()->Phi(); fVariableCount++;};
            if (v == "Vz") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->Vertex().Z(); fVariableCount++;};
            if (v == "TrChi2") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->TrChi2(); fVariableCount++;};
            if (v == "Det") {fAppVars[tmpPCount][fVariableCount] = Float_t(tmpParticle->Detector()); fVariableCount++;}
        }
    }
    else{
        // assumes all particles have same variables
        for (auto const& v : fVariableID) {
            if (v == "Time") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->DeltaTime(); fVariableCount++;};
            if (v == "Edep") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->Edep(); fVariableCount++;};
            if (v == "DeltaE") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->DeltaE(); fVariableCount++;};
            if (v == "PreE") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->PreE(); fVariableCount++;};
            if (v == "P") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->P4p()->P(); fVariableCount++;};
            if (v == "Th") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->P4p()->Theta(); fVariableCount++;};
            if (v == "Phi") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->P4p()->Phi(); fVariableCount++;};
            if (v == "Vz") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->Vertex().Z(); fVariableCount++;};
            if (v == "TrChi2") {fAppVars[tmpPCount][fVariableCount] = tmpParticle->TrChi2(); fVariableCount++;};
            if (v == "Det") {fAppVars[tmpPCount][fVariableCount] = Float_t(tmpParticle->Detector()); fVariableCount++;}
        }
    }
}

/**
 * Add readers 
 *
 */

void THSMVAApp::AddReaders(){

    std::cout<<"Adding readers..."<<std::endl;
    
    if (!fSplits.empty()) fReaders.resize(fSplits.size());
    else fReaders.resize(1);

    for (UInt_t i=0; i<fReaders.size(); i++){
        fReader = new TMVA::Reader( "!Color:!Silent" );
        fReaders[i] = (fReader);
    }
}

/**
 * Set variables for a given reader
 *
 */

void THSMVAApp::SetReaderVariables(TMVA::Reader* tmpReader){

    fParticleCount = 0;
    fVariableCount = 0;

    if (fAppVars.empty()) {std::cout<<"ERROR : tree vars"<<std::endl;exit(1);};

    std::cout<<"    Setting reader variables..."<<std::endl;
    for (UInt_t iPar=0; iPar<fAppVars.size(); iPar++) {
        for (UInt_t iVar=0; iVar<fAppVars[iPar].size(); iVar++) {
            tmpReader->AddVariable( fAppVariableNames[iPar][iVar], &fAppVars[iPar][iVar]);
            //std::cout<<fAppVariableNames[iPar][iVar]<<std::endl;
            //std::cout<<&(fAppVars[iPar][iVar])<<std::endl;
        }
    }
}

/**
 * Set variables for a given reader and split
 *
 */

void THSMVAApp::SetReaderVariables(TMVA::Reader* tmpReader, Split tmpSplit){

    fParticleCount = 0;
    fVariableCount = 0;

    std::cout<<"    Setting reader variables..."<<std::endl;
    for (auto const& p : tmpSplit.GetMVAVariables()){
        fIdx = tmpSplit.GetParticles()[fParticleCount];
        std::cout<<"    particle: "<<fIdx<<std::endl;
        for (auto const& v : p){
            tmpReader->AddVariable( v,&(fAppVars[fIdx][fVariableCount]) );
            std::cout<<"        "<<v<<std::endl;
            fVariableCount++;
        }
        fParticleCount++;
    }
}

/**
 * Set all readers
 *
 */

void THSMVAApp::SetReaders(){
    std::cout<<"Setting variables and methods for readers..."<<std::endl;
    fSplitCount = 0;

    if (fAppVariableNames.empty()) {fAppVariableNames = fSelectNames;};
    if (fAppVars.empty()){
        fAppVars.resize(fAppVariableNames.size());
        for (UInt_t i=0; i<fAppVars.size(); i++){
            fAppVars[i].resize(fAppVariableNames[i].size());
        }
    }

    if (!fSplits.empty()){
        for (auto const& r : fReaders){
        std::cout<<"    ...Reader "<<fSplitCount<<std::endl;
            SetReaderVariables(r, fSplits[fSplitCount]);
            SetReaderMethods(r, fSplits[fSplitCount]);
            fSplitCount++;
        }
    }
    else{
        for (auto const& r : fReaders){
            SetReaderVariables(r);
            SetReaderMethods(r);
        }
    }
}

/**
 * Book MVA methods
 *
 */

void THSMVAApp::SetReaderMethods(TMVA::Reader* tmpReader){

    if (fMethods.empty()){
        std::cout<<"    Using default MVA method..."<<std::endl;
        tmpReader->BookMVA( "BDT method", "dataset/weights/THSMVAClassification_BDT.weights.xml");
    }   
    else {
        std::cout<<"    Using given methods..."<<std::endl;
        for (auto const& m : fMethods) {
            fMethodName = m.GetName() + " method";
            fWeightFile = "dataset/weights/THSMVAClassification_" + m.GetName()  + ".weights.xml";
            tmpReader->BookMVA( fMethodName, fWeightFile );
        }
    }
}

/**
 * Book MVA methods
 *
 */

void THSMVAApp::SetReaderMethods(TMVA::Reader* tmpReader, Split tmpSplit){

    if (fMethods.empty()){
        std::cout<<"    Using default MVA method..."<<std::endl;
        fWeightFile = "dataset" + tmpSplit.GetSplitName() + "/weights/THSMVAClassification_BDT.weights.xml";
        std::cout<<"    weights file: "<<fWeightFile<<std::endl;
        tmpReader->BookMVA( "BDT method", fWeightFile);
    }   
    else {
        for (auto const& m : fMethods) {
            fMethodName = m.GetName() + " method";
            fWeightFile = "dataset" + tmpSplit.GetSplitName() + "/weights/THSMVAClassification_" + m.GetName()  + ".weights.xml";
            std::cout<<"    weights file: "<<fWeightFile<<std::endl;
            tmpReader->BookMVA( fMethodName, fWeightFile );
        }
    }
}
/**
 * Set up output tree
 *
 */

void THSMVAApp::SetOutput(){
    
    fParticleCount = 0;
    fVariableCount = 0;
        
    // set branch addresses
    if (fCheckVariables){
        for (auto const& p : fAppVariableNames){
            for (auto const& v : p){
                fOutputTree->Branch( v, &(fAppVars[fParticleCount][fVariableCount]), v+"/F" );
                fVariableCount++;
            }
            fParticleCount++;
            fVariableCount=0;
        }
    }

    if (!fMethods.empty()){
        fMethodResults.resize(fMethods.size());
        for (UInt_t i=0; i<fMethods.size(); i++){
            fOutputTree->Branch(fMethods[i].GetName(), &fMethodResults[i], fMethods[i].GetName() + "/F");
        }
    }
    else{
        fMethodResults.resize(1);
        fOutputTree->Branch("DefaultBDT", &fMethodResults[0], "DefaultBDT/F");
    }

    if (!fSplits.empty()){
        fOutputTree->Branch("ReaderIdx", &fReaderIdx, "ReaderIdx/I");
    }

}

/**
 * Get index of reader to use for a particular event
 *
 */

Int_t THSMVAApp::CheckSplits(){

    // if splits have been defined
    // check which reader should be used
    // based on the variables the splits
    // point to
    if (!fSplits.empty()){
        // check each split
        for (UInt_t i=0; i<fSplits.size(); i++){
            fSplitCount = 0;
            // check all pointers in splits
            for (UInt_t j=0; j<fSplits[i].GetN(); j++){
                //std::cout<<"Checking criteria"<<std::endl;
                //std::cout<<fSplits[i].GetVariables()[j]<<std::endl;
                //std::cout<<*fSplits[i].GetPointers()[j]<<std::endl;
                
                if (*fSplits[i].GetPointers()[j]==fSplits[i].GetVariables()[j]){
                    fSplitCount++;
                    //std::cout<<"Checked criteria"<<std::endl;
                }
                else break; // next splits if one of the criteria fail
            }
            // if all criteria met, set reader to this split
            if (fSplitCount == fSplits[i].GetN()) fReaderIdx = i;
        }
    }
    // if there a no splits only one reader will be defined
    else fReaderIdx = 0;

    return fReaderIdx;
}

/**
 * Process the current event
 *
 */

void THSMVAApp::ProcessEvent(){

    // will have as many outputs as results
    if (fMethodResults.empty()){
        std::cout<<"ERROR : output vector not set"<<std::endl;
        exit(1);
    }

    if (fEventCount%1000==0) {std::cout<<"  processing event: "<<fEventCount<<std::endl;};
    // remove NaNs from event
    for (UInt_t iPar=0; iPar<fAppVars.size(); iPar++) {
        for (UInt_t iVar=0; iVar<fAppVars[iPar].size(); iVar++) {
            if (!std::isfinite(fAppVars[iPar][iVar])){
                fAppVars[iPar][iVar] = 0;
            }
        }
    } 
    //  get index of reader to use
    fReaderIdx = CheckSplits();
    // return MVA outputs
    if (!fMethods.empty()) {
       for (UInt_t i = 0; i<fMethods.size(); i++) {
          fMethodName = fMethods[i].GetName() + " method"; // get method name
          fMethodResults[i] = fReaders[fReaderIdx]->EvaluateMVA( (fMethodName) );
       }
    }
    else{
        fMethodResults[0] = fReaders[fReaderIdx]->EvaluateMVA( ("BDT method"));
    }
    fEventCount++; 
}

////////////////////////////////////////
///Destructor
////////////////////////////////////////
THSMVAApp::~THSMVAApp(){

    delete fAppTree;
    delete fOutputFile;
    delete fOutputTree;
    delete fReader;

}
