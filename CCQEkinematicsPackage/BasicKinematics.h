/**
 * \file BasicKinematics.h
 *
 * \ingroup CCQEkinematicsPackage
 * 
 * \brief Class def header for a class BasicKinematics
 *
 * @author erezcohen
 */

/** \addtogroup CCQEkinematicsPackage

    @{*/
#ifndef BASICKINEMATICS_H
#define BASICKINEMATICS_H

#include <iostream>
#include "/Users/erezcohen/larlite/UserDev/mySoftware/MySoftwarePackage/myIncludes.h"
#include "/Users/erezcohen/larlite/UserDev/mySoftware/MySoftwarePackage/TCalculations.h"
//#define Mmuon 0.1056

/**
   \class BasicKinematics
   User defined class BasicKinematics ... these comments are used to generate
   doxygen documentation!
 */
class BasicKinematics{

public:

    /// Default constructor
    BasicKinematics(){}
    ~BasicKinematics(){}

    
    
    // initializers
          BasicKinematics (TTree * , Int_t debug = 0);
    void      InitOutTree ();
    

    // Setters
    void       SetOutTree (TTree * tree)    {OutTree = tree;};
    void         SetDebug (int _debug)      {debug = _debug;};

    
    
    
    // running
    void ComputeKinematics ( Double_t fEv );
    void         PrintData ( int );
    
    TRandom3    rand;
    TTree       * OutTree;
    
    
    
    Int_t       debug;
    
    
    Double_t    Ev  , p_muon    , Px    , Py    , Pz    ;
    
    
    TLorentzVector neutrino , neutron , muon , proton;
    
    
    
};

#endif
/** @} */ // end of doxygen group 

