'''
    usage:
    ---------
    > python mac/ana_ccqe_basic_kinematics.py --Nbins=50 -cut="" --Ev=0.2 --option="muon vs. proton" -var="theta"
    
    Note: --Ev=0 gives the BNB neutrino flux
'''




import ROOT , os , sys , datetime
from ROOT import TPlots
from rootpy.interactive import wait
sys.path.insert(0, '../../mySoftware/MySoftwarePackage/mac')
import GeneralPlot as gp , Initiation as init , input_flags
init.createnewdir()
flags = input_flags.get_args()

var      = flags.variable
RunName  = "Ev%dMeV"%(int(1000*flags.Ev))
Path     = "/Users/erezcohen/Desktop/uBoone/AnaFiles"
FileName = Path + "/CCQE_" + RunName + "_" + datetime.datetime.now().strftime("%Y%B%d")  + ".root"
ana      = TPlots( FileName , "anaTree" )



if flags.option=="muon" or flags.option=="proton":

    particle = flags.option
    
    c = ana.CreateCanvas( particle + "," + var )
    
    if var=="theta_vs_momentum":
        
        ana.H2( particle+".P()" ,particle+".Theta()*TMath::RadToDeg()" , flags.cut , "colz",
               flags.Nbins ,0,flags.Ev , flags.Nbins ,  -1 , 181 , "" ,
               "p("+particle+") [GeV/c]", gp.ThetaTit(particle) )

    elif var=="momentum":
        
        ana.H2("muon.P()" , "proton.P()" , flags.cut , "colz",
               flags.Nbins , 0 , flags.Ev , flags.Nbins , 0 ,flags.Ev ,"", 'p(#mu) [GeV/c]' , 'p(p) [GeV/c]' )



    c.Update()
    wait()
    c.SaveAs(init.dirname() + "/" + RunName + "_" + particle +"_" + var + ".pdf")


if flags.option=="muon vs. proton":

    c = ana.CreateCanvas(flags.option + "," + var )
    
    if var=="theta":

        ana.H2("TMath::RadToDeg()*muon.Theta()" , "TMath::RadToDeg()*proton.Theta()" , flags.cut , "colz",
               flags.Nbins , -1 , 181 , flags.Nbins ,  -1 , 181 , "" , gp.ThetaTit("#mu") , gp.ThetaTit("p") )

    elif var=="momentum":
    
        ana.H2("muon.P()" , "proton.P()" , flags.cut , "colz",
               flags.Nbins , 0 , flags.Ev , flags.Nbins , 0 , flags.Ev,"", 'p(#mu) [GeV/c]' , 'p(p) [GeV/c]' )



    c.Update()
    wait()
    c.SaveAs(init.dirname() + "/"+ RunName + "_muon_vs_proton_" + var + ".pdf")




