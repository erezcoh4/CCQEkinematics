'''
    usage:
    ---------
    > python mac/calc_ccqe_basic_kinematics.py -v3 -evf=0.01 -p1
'''




import ROOT , os , sys , datetime
from ROOT import BasicKinematics
sys.path.insert(0, '../../mySoftware/MySoftwarePackage/mac')
import input_flags
flags = input_flags.get_args()



Nevents         = int(flags.evnts_frac*1000)
Path            = "/Users/erezcohen/Desktop/uBoone/AnaFiles"
OutFileName     = Path + "/CCQEBasicKinematics_" + "_" + datetime.datetime.now().strftime("%Y%B%d")  + ".root"

if (flags.verbose>0):
    print "running %d events -> to \n %s"%(Nevents,OutFileName)

OutFile         = ROOT.TFile(OutFileName,"recreate")
OutTree         = ROOT.TTree("anaTree","CCQE basic kinematics")


calc = BasicKinematics( OutTree , flags.verbose )

for entry in range(Nevents):
    
    calc.ComputeKinematics()
    
    if (flags.verbose > 0 and entry%flags.print_mod == 0):
        
        calc.PrintData( entry )
    
    calc.FillOutTree()





print "wrote root file (%d events , %.2f MB):\n"%(OutTree.GetEntries(),float(os.path.getsize(OutFileName)/1048576.0)) + OutFileName


OutTree.Write()
OutFile.Close()


