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
#include "../../mySoftware/MySoftwarePackage/myIncludes.h"

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

    BasicKinematics(TTree * , Int_t debug = 0);
    
    
    
    
    // Setters
    void       SetOutTree (TTree * tree)    {OutTree = tree;};
    void         SetDebug (int _debug)      {debug = _debug;};

    
    
    
    // running
    void ComputeKinematics ();
    void         PrintData ( int);
    
    
    TTree * OutTree;
    
    
    
    Int_t   debug;
    
    
    Float_t     Ev;
    
    
    TLorentzVector neutrino , neutron , muon , proton;
    
    
    
};

#endif
/** @} */ // end of doxygen group 

