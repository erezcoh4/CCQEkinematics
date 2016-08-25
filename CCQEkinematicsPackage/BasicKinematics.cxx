#ifndef BASICKINEMATICS_CXX
#define BASICKINEMATICS_CXX

#include "BasicKinematics.h"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
BasicKinematics::BasicKinematics( TTree * fOutTree , Int_t fdebug ){
    
    SetOutTree(fOutTree);
    SetDebug(fdebug);

    rand = TRandom3((int)(1000*gRandom->Uniform()));
    InitOutTree();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void BasicKinematics::InitOutTree(){
    
    
    OutTree -> Branch("neutrino"        ,"TLorentzVector"       ,&neutrino);
    OutTree -> Branch("neutron"         ,"TLorentzVector"       ,&neutron);
    OutTree -> Branch("muon"            ,"TLorentzVector"       ,&muon);
    OutTree -> Branch("proton"          ,"TLorentzVector"       ,&proton);

    if (debug>1) cout << "initialized BasicKinematics output tree " << OutTree->GetTitle() << endl;
    
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void BasicKinematics::ComputeKinematics( Double_t fEv ){
    
    Ev = fEv;
    
    neutrino= TLorentzVector ( 0 , 0 , Ev, Ev );
    neutron = TLorentzVector ( 0 , 0 , 0 , 0  );
    
    
    p_muon = rand.Uniform( 0 , neutrino.P() );
    rand.Sphere( Px , Py , Pz , p_muon );
    muon = TLorentzVector( Px , Py , Pz , sqrt( p_muon*p_muon + Mmu*Mmu ) );

    proton  = neutrino + neutron - muon;
    
    OutTree->Fill();
    
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void BasicKinematics::PrintData( int entry ){
    
    SHOW(entry);
    SHOWTLorentzVector(neutrino);
    SHOWTLorentzVector(neutron);
    SHOWTLorentzVector(muon);
    
    SHOWTLorentzVector(proton);
    
    EndEventBlock();

}





#endif
