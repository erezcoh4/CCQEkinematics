'''
    usage:
    ---------
    python mac/calc_ccqe_basic_kinematics.py -v3 -p1 --Ev=0.2 -evf=10
    
    Note: --Ev=0 gives the BNB neutrino flux
'''


import ROOT , os , sys , datetime
import pandas as pd , matplotlib.pyplot as plt
from ROOT import BasicKinematics
sys.path.insert(0, '../../mySoftware/MySoftwarePackage/mac')
import input_flags
flags = input_flags.get_args()


RunName         = "Ev%dMeV"%(int(1000*flags.Ev))
Nevents         = int(flags.evnts_frac*1000)
Path            = "/Users/erezcohen/Desktop/uBoone/AnaFiles"
OutFileName     = Path + "/CCQE_" + RunName + "_" + datetime.datetime.now().strftime("%Y%B%d")  + ".root"

if (flags.verbose>0):
    print "running %d events to \n %s"%(Nevents,OutFileName)

OutFile         = ROOT.TFile(OutFileName,"recreate")
OutTree         = ROOT.TTree("anaTree","CCQE basic kinematics")

calc = BasicKinematics( OutTree , flags.verbose )

EfluxData = pd.read_csv( "dat/Eflux.dat" , sep = ' ', names=['Ev','flux'] )

gFlux = plt.plot( EfluxData['Ev'] , EfluxData['flux'] , 'ro' )

if (flags.verbose > 5):
    
    plt.xlabel(r'$E_{\nu}$ [GeV]')
    plt.ylabel(r'$flux$ [a.u.]')
    plt.show()
    plt.savefig("EvFlux.pdf")

Ev = flags.Ev


for entry in range(Nevents):


    calc.ComputeKinematics( Ev )
    
    if (flags.verbose > 0 and entry%flags.print_mod == 0):
        
        calc.PrintData( entry )
    





print "wrote root file (%d events , %.2f MB):\n"%(OutTree.GetEntries(),float(os.path.getsize(OutFileName)/1048576.0)) + OutFileName + "\n"


OutTree.Write()
OutFile.Close()


