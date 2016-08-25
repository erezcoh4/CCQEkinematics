#ifndef BASICKINEMATICS_CXX
#define BASICKINEMATICS_CXX

#include "BasicKinematics.h"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
BasicKinematics::BasicKinematics( TTree * fOutTree , Int_t fdebug ){
    
    SetOutTree(fOutTree);
    SetDebug(fdebug);
    
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void BasicKinematics::ComputeKinematics(){
    
    neutrino= TLorentzVector ( 0 , 0 , Ev, Ev );
    neutron = TLorentzVector ( 0 , 0 , 0 , 0  );
    
    muon    = TLorentzVector ( 0 , 0 , 0 , 0  );
    proton  = neutrino + neutron - muon;
    
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void BasicKinematics::PrintData( int entry ){
    
    PrintLine();
    SHOW(entry);
    SHOWTLorentzVector(neutrino);
    SHOWTLorentzVector(neutron);
    SHOWTLorentzVector(muon);
    SHOWTLorentzVector(proton);
    
    EndEventBlock();

}





#endif
