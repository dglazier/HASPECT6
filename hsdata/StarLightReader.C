#include <sstream>
#include <string>
#include "StarLightReader.h"

using namespace HS;

Bool_t StarLightReader::Init(TString filename,TString name){
  if(filename.Length()) fTxtIn.open(filename.Data());
  if(!fTxtIn.is_open()) {Error("InitLundEvent","file not found %s",filename.Data());return kFALSE;}
  //Read (and ignore ) the header info
  string sline;
  getline(fTxtIn,sline); //CONFIG_OPT
  getline(fTxtIn,sline); //BEAM_1
  getline(fTxtIn,sline); //BEAM_2
  getline(fTxtIn,sline); //PHOTON

  //fEventInfo=new THSEventInfo();
  return kTRUE;

}
Bool_t StarLightReader::ReadEvent(Long64_t entry){
  //  if(fAddGenerated) return ReadGenerated(entry); //just fill generated branch
  //return false at end of file
  // LUND format:
// Header (Event Info):
// # of Particles, # of e, particle id, parent, daughter, p_x, p_y, p_z, E, mass, x vertex, y vertex, z vertex
// type is 1 for particles in the detector
  Double_t dummy;
  string sdummy;
  string sline;
  getline(fTxtIn,sline);//EVENT
  //cout<<sline<<endl;
  if(fTxtIn.eof()) return kFALSE;
  stringstream streamline(sline);
  
  streamline>>sdummy>>dummy>>fNin>>dummy; //just need number of particles
  //cout<<sdummy<<" "<<fNin<<endl;
  //fNin+=2; //TARGET AND SOURCE
  
  getline(fTxtIn,sline);//VERTEX ignore for now
  getline(fTxtIn,sline);//GAMMA ignore for now
  getline(fTxtIn,sline);//t ignore for now

  //now read in each particle ans assign to fParticles
  Int_t index,type,pid,parent,daughter;
  Float_t charge,px,py,pz,energy,mass,vx,vy,vz;
  THSParticle particle;
  fParticles.clear();//reset fParticles
  fParticles.reserve(fNin+2);//reset fParticles
  fGenerated.clear();//reset fParticles
  fGenerated.reserve(fNin+2);//reset fParticles
  stringstream streamlinep;
  
  getline(fTxtIn,sline);//TARGET
  streamlinep.str(sline);//set sline as string in stream
  streamlinep>>sdummy>>px>>py>>pz>>energy;
  particle.SetXYZT(px,py,pz,energy);
  fParticles.emplace_back(particle);
  fGenerated.emplace_back(particle);

  cout<<"TARGET "<<sdummy<<" "<<particle.P4().Theta()<<endl;
  getline(fTxtIn,sline);//SOURCE
  streamlinep.clear();
  streamlinep.str(sline);//set sline as string in stream
  streamlinep>>sdummy>>px>>py>>pz>>energy;
  particle.SetXYZT(px,py,pz,energy);
  fParticles.emplace_back(particle);
  fGenerated.emplace_back(particle);
  cout<<"SOURCE "<<sdummy<<" "<<particle.P4().Theta()<<endl;
 
  //cout<<"Read "<<fNin<<endl;
  //TRACKS
  for(UInt_t i=0;i<fNin;i++){
    streamlinep.clear();
    Int_t gpid=0;
  
    Int_t nev=0;
    Int_t ntr=0;
    Int_t stopv=0;
    
    getline(fTxtIn,sline);
    streamlinep.str(sline);//set sline as string in stream
    // cout<<"TRACKS "<<sline<<endl;
    streamlinep>>sdummy>>gpid>>px>>py>>pz>>nev>>ntr>>stopv>>pid;

    //cout<<"PID "<<pid <<" "<<TDatabasePDG::Instance()->GetParticle(pid)<<" "<<sdummy<<" "<<stopv<<" "<<gpid<<" "<<px<<" "<<py<<" "<<pz<<" "<<nev<<endl;
    
    particle.SetXYZM(px,py,pz,TDatabasePDG::Instance()->GetParticle(pid)->Mass());
    //particle.SetVertex(vx,vy,vz);
    particle.SetPDGcode(pid);

    //cout<<"EMPLACE BACK "<<endl;
    fParticles.emplace_back(particle);
    fGenerated.emplace_back(particle);
    
    streamlinep.clear();
  }
  return kTRUE;
  
}
