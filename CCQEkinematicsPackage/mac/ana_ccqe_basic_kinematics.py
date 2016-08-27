'''
    usage:
    ---------
    python mac/ana_ccqe_basic_kinematics.py --Ev=0.2 --option="muon vs. proton" -var=theta
    
    Note: --Ev=0 gives the BNB neutrino flux
'''



import root2matplot as r2m
import ROOT , os , sys , datetime
from root_numpy import root2array, tree2array , hist2array
from ROOT import TPlots
from rootpy.interactive import wait
import seaborn as sns; sns.set(style="white", color_codes=True)
from matplotlib import pyplot as plt
from matplotlib import cm
sys.path.insert(0, '../../mySoftware/MySoftwarePackage/mac')
import GeneralPlot as gp , Initiation as init , input_flags
init.createnewdir()
flags = input_flags.get_args()

var      = flags.variable
RunName  = "Ev%dMeV"%(int(1000*flags.Ev))
Path     = "/Users/erezcohen/Desktop/uBoone/AnaFiles"
FileName = Path + "/CCQE_" + RunName + "_" + datetime.datetime.now().strftime("%Y%B%d")  + ".root"
ana      = TPlots( FileName , "anaTree" )
T        = tree2array(ana.GetTree(),branches=['TMath::RadToDeg()*muon.Theta()','muon.P()','TMath::RadToDeg()*proton.Theta()','proton.P()'])



if flags.option=="muon" or flags.option=="proton":

    particle = flags.option
    plabel   = '\mu' if particle=="muon" else 'p'

    if var=="theta_vs_momentum":

        X , Y , labels = T[particle+'.P()'],T['TMath::RadToDeg()*'+particle+'.Theta()'],[ '$p('+plabel+')$ [GeV/c]' , '$\\theta('+plabel+')$ [deg.]']

    fig = gp.sns2d_with_projections( X , Y , labels )
    plt.savefig(init.dirname() + "/" + RunName + "_" + particle +"_" + var + ".pdf")


if flags.option=="muon vs. proton":


    if var=="theta":

        X , Y , labels = T['TMath::RadToDeg()*muon.Theta()'],T['TMath::RadToDeg()*proton.Theta()'],[ '$\\theta(\mu)$ [deg.]' , '$\\theta(p)$ [deg.]']


    elif var=="momentum":
    
        X , Y , labels = T['muon.P()'],T['proton.P()'],[ '$p(\mu)$ [GeV/c]' , '$p(p)$ [GeV/c]']

    fig = gp.sns2d_with_projections( X , Y , labels , "hex")
    plt.savefig(init.dirname() + "/"+ RunName + "_muon_vs_proton_" + var + ".pdf")



