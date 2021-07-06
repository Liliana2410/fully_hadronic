#include "SampleAnalyzer/User/Analyzer/Analysis.h"
#include "SampleAnalyzer/Interfaces/root/RootMainHeaders.h"
#include <TFile.h>
#include <TCanvas.h>
#include <vector>
using namespace MA5;
using namespace std;

// -----------------------------------------------------------------------------
// Initialize
// function called one time at the beginning of the analysis
// -----------------------------------------------------------------------------
bool Analysis::Initialize(const MA5::Configuration& cfg, const std::map<std::string,std::string>& parameters)
{
  cout << "BEGIN Initialization" << endl;
  // initialize variables, histos
  
  PHYSICS->mcConfig().Reset();

  // definition of the multiparticle "hadronic" 
  PHYSICS->mcConfig().AddHadronicId(1); // down
  PHYSICS->mcConfig().AddHadronicId(2); // up
  PHYSICS->mcConfig().AddHadronicId(3); // strange
  PHYSICS->mcConfig().AddHadronicId(4); // charm
  PHYSICS->mcConfig().AddHadronicId(5); // bottom
  PHYSICS->mcConfig().AddHadronicId(6); // top
  PHYSICS->mcConfig().AddHadronicId(-1);
  PHYSICS->mcConfig().AddHadronicId(-2);
  PHYSICS->mcConfig().AddHadronicId(-3);
  PHYSICS->mcConfig().AddHadronicId(-4); 
  PHYSICS->mcConfig().AddHadronicId(-5);
  PHYSICS->mcConfig().AddHadronicId(21); // gluon(s)

  // definition of the multiparticle "invisible"
  PHYSICS->mcConfig().AddInvisibleId(12); // neutrino_e
  PHYSICS->mcConfig().AddInvisibleId(14); // neutrino_mu
  PHYSICS->mcConfig().AddInvisibleId(16); //neutrino_tau
  PHYSICS->mcConfig().AddInvisibleId(-12);
  PHYSICS->mcConfig().AddInvisibleId(-14);
  PHYSICS->mcConfig().AddInvisibleId(-16);
  
  
  Manager()->AddRegionSelection("myregion");

  // Definition of histograms
  
  //**************************************************************************************************************************************************************************************************
  //**************************************************************************************************************************************************************************************************
  //PLOTS OF THE FIRST PAIR OF DIJET AND B_DIJET******************************************************************************************************************************************************
  //general plots
  
  Manager()->AddHisto("FoundPair", 2, 0.0, 3.0); /*Name, bins, x_initial, x_final*/ //dR(b,jj)
  plot_FoundPair = new TH1F("FoundPair", "FoundPair", 2, 0.0, 3.0);

  Manager()->AddHisto("N_Merged1", 3, 0.0, 4.0); /*Name, bins, x_initial, x_final*/ //dR(b,jj)
  plot_N_Merged1 = new TH1F("N_Merged1", "N_Merged1", 3, 0.0, 4.0);
  
  //general plots dijet1
  
  Manager()->AddHisto("PT_dijet1", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet1 = new TH1F("PT_dijet1", "PT_dijet1", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet1", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet1 = new TH1F("ETA_dijet1", "ETA_dijet1", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet1", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet1 = new TH1F("M_dijet1", "M_dijet1", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet1", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet1 = new TH1F("PHI_dijet1", "PHI_dijet1", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet1", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet1 = new TH1F("DR_dijet1", "DR_dijet1", 100, 0.0, 10.0);
  
  //general plots b_dijet1
  
  Manager()->AddHisto("PT_b_dijet1", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet1 = new TH1F("PT_b_dijet1", "PT_b_dijet1", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet1", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet1 = new TH1F("ETA_b_dijet1", "ETA_b_dijet1", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet1", 100, 100.0, 300.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet1 = new TH1F("M_b_dijet1", "M_b_dijet1", 100, 100.0, 300.0);

  Manager()->AddHisto("PHI_b_dijet1", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet1 = new TH1F("PHI_b_dijet1", "PHI_b_dijet1", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet1", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet1 = new TH1F("DR_b_dijet1", "DR_b_dijet1", 100, 0.0, 10.0);
  
  //DIJET1 *******************************************************************************************************************************************************************************************
  //plots of the dijet1 pairs that are not merged.

  Manager()->AddHisto("PT_dijet1_not", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet1_not = new TH1F("PT_dijet1_not", "PT_dijet1_not", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet1_not", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet1_not = new TH1F("ETA_dijet1_not", "ETA_dijet1_not", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet1_not", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet1_not = new TH1F("M_dijet1_not", "M_dijet1_not", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet1_not", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet1_not = new TH1F("PHI_dijet1_not", "PHI_dijet1_not", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet1_not", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet1_not = new TH1F("DR_dijet1_not", "DR_dijet1_not", 100, 0.0, 10.0);
  
  //plots of the dijet1 pairs that are partially merged.

  Manager()->AddHisto("PT_dijet1_partially", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet1_partially = new TH1F("PT_dijet1_partially", "PT_dijet1_partially", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet1_partially", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet1_partially = new TH1F("ETA_dijet1_partially", "ETA_dijet1_partially", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet1_partially", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet1_partially = new TH1F("M_dijet1_partially", "M_dijet1_partially", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet1_partially", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet1_partially = new TH1F("PHI_dijet1_partially", "PHI_dijet1_partially", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet1_partially", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet1_partially = new TH1F("DR_dijet1_partially", "DR_dijet1_partially", 100, 0.0, 10.0);
  
  //plots of the dijet1 pairs that are fully merged.

  Manager()->AddHisto("PT_dijet1_fully", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet1_fully = new TH1F("PT_dijet1_fully", "PT_dijet1_fully", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet1_fully", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet1_fully = new TH1F("ETA_dijet1_fully", "ETA_dijet1_fully", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet1_fully", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet1_fully = new TH1F("M_dijet1_fully", "M_dijet1_fully", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet1_fully", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet1_fully = new TH1F("PHI_dijet1_fully", "PHI_dijet1_fully", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet1_fully", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet1_fully = new TH1F("DR_dijet1_fully", "DR_dijet1_fully", 100, 0.0, 10.0);
  
  //B-DIJET1 *****************************************************************************************************************************************************************************************
  //plots of the b_dijet1 pairs that are partially merged.

  Manager()->AddHisto("PT_b_dijet1_partially", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet1_partially = new TH1F("PT_b_dijet1_partially", "PT_b_dijet1_partially", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet1_partially", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet1_partially = new TH1F("ETA_b_dijet1_partially", "ETA_b_dijet1_partially", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet1_partially", 100, 100.0, 300.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet1_partially = new TH1F("M_b_dijet1_partially", "M_b_dijet1_partially", 100, 100.0, 300.0);

  Manager()->AddHisto("PHI_b_dijet1_partially", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet1_partially = new TH1F("PHI_b_dijet1_partially", "PHI_b_dijet1_partially", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet1_partially", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet1_partially = new TH1F("DR_b_dijet1_partially", "DR_b_dijet1_partially", 100, 0.0, 10.0);
  
  //plots of the b_dijet1 pairs that are fully merged.

  Manager()->AddHisto("PT_b_dijet1_fully", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet1_fully = new TH1F("PT_b_dijet1_fully", "PT_b_dijet1_fully", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet1_fully", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet1_fully = new TH1F("ETA_b_dijet1_fully", "ETA_b_dijet1_fully", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet1_fully", 100, 100.0, 300.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet1_fully = new TH1F("M_b_dijet1_fully", "M_b_dijet1_fully", 100, 100.0, 300.0);

  Manager()->AddHisto("PHI_b_dijet1_fully", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet1_fully = new TH1F("PHI_b_dijet1_fully", "PHI_b_dijet1_fully", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet1_fully", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet1_fully = new TH1F("DR_b_dijet1_fully", "DR_b_dijet1_fully", 100, 0.0, 10.0);
  
  //PLOTS OF THE THE TWO B****************************************************************************************************************************************************************************
  //plots of b1.
  
  Manager()->AddHisto("PT_b1", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b1 = new TH1F("PT_b1", "PT_b1", 100, 0.0, 1000.0);
  
  Manager()->AddHisto("ETA_b1", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b1 = new TH1F("ETA_b1", "ETA_b1", 100, -8.0, 8.0);
  
  Manager()->AddHisto("PHI_b1", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b1 = new TH1F("PHI_b1", "PHI_b1", 100, -3.0, 3.0);
  
  //plots of b2.
  
  Manager()->AddHisto("PT_b2", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b2 = new TH1F("PT_b2", "PT_b2", 100, 0.0, 1000.0);
  
  Manager()->AddHisto("ETA_b2", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b2 = new TH1F("ETA_b2", "ETA_b2", 100, -8.0, 8.0);
  
  Manager()->AddHisto("PHI_b2", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b2 = new TH1F("PHI_b2", "PHI_b2", 100, -3.0, 3.0);
  
  
  
  
  
  //PLOTS OF THE SECOND PAIR OF DIJET AND B_DIJET ****************************************************************************************************************************************************
  //ONLY USED IN THE FULLY HADRONIC CHANNEL **********************************************************************************************************************************************************
  //general plots dijet2
  
  Manager()->AddHisto("N_Merged2", 3, 0.0, 4.0); /*Name, bins, x_initial, x_final*/ //dR(b,jj)
  plot_N_Merged2 = new TH1F("N_Merged2", "N_Merged2", 3, 0.0, 4.0);

  Manager()->AddHisto("Smallest_DR_dijet", 2, 0.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_Smallest_DR_dijet = new TH1F("Smallest_DR_dijet", "Smallest_DR_dijet", 2, 0.0, 3.0);
  
  Manager()->AddHisto("Smallest_DR_b_dijet", 2, 0.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_Smallest_DR_b_dijet = new TH1F("Smallest_DR_b_dijet", "Smallest_DR_b_dijet", 2, 0.0, 3.0);
  
  Manager()->AddHisto("Pairs", 3, 0.0, 4.0); /*Name, bins, x_initial, x_final*/
  plot_Pairs = new TH1F("Pairs", "Pairs", 3, 0.0, 4.0);
  
  Manager()->AddHisto("Pairs_b", 6, 0.0, 7.0); /*Name, bins, x_initial, x_final*/
  plot_Pairs_b = new TH1F("Pairs_b", "Pairs_b", 6, 0.0, 7.0);
  
  Manager()->AddHisto("Mother_Particles_dijets", 2, 0.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_Mother_Particles_dijets = new TH1F("Mother_Particles_dijets", "Mother_Particles_dijets", 2, 0.0, 3.0);
  
  //general plots dijet2
  
  Manager()->AddHisto("PT_dijet2", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet2 = new TH1F("PT_dijet2", "PT_dijet2", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet2", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet2 = new TH1F("ETA_dijet2", "ETA_dijet2", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet2", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet2 = new TH1F("M_dijet2", "M_dijet2", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet2", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet2 = new TH1F("PHI_dijet2", "PHI_dijet2", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet2", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet2 = new TH1F("DR_dijet2", "DR_dijet2", 100, 0.0, 10.0);
  
  //dETA, dPHI, dDR plots for the first dijet.
  
  Manager()->AddHisto("dETA_dijet1", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_dETA_dijet1 = new TH1F("dETA_dijet1", "dETA_dijet1", 100, -8.0, 8.0);
  
  Manager()->AddHisto("dPHI_dijet1", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_dPHI_dijet1 = new TH1F("dPHI_dijet1", "dPHI_dijet1", 100, -3.0, 3.0);
  
  Manager()->AddHisto("dDR_dijet1", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_dDR_dijet1 = new TH1F("dDR_dijet1", "dDR_dijet1", 100, 0.0, 10.0);
  
  //dETA, dPHI, dDR plots for the second dijet.
  
  Manager()->AddHisto("dETA_dijet2", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_dETA_dijet2 = new TH1F("dETA_dijet2", "dETA_dijet2", 100, -8.0, 8.0);
  
  Manager()->AddHisto("dPHI_dijet2", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_dPHI_dijet2 = new TH1F("dPHI_dijet2", "dPHI_dijet2", 100, -3.0, 3.0);
  
  Manager()->AddHisto("dDR_dijet2", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_dDR_dijet2 = new TH1F("dDR_dijet2", "dDR_dijet2", 100, 0.0, 10.0);
  
  //dETA, dPHI, dDR plots for the first pair not used: (1,2).
  
  Manager()->AddHisto("dETA_pair12", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_dETA_pair12 = new TH1F("dETA_pair12", "dETA_pair12", 100, -8.0, 8.0);
  
  Manager()->AddHisto("dPHI_pair12", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_dPHI_pair12 = new TH1F("dPHI_pair12", "dPHI_pair12", 100, -3.0, 3.0);
  
  Manager()->AddHisto("dDR_pair12", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_dDR_pair12 = new TH1F("dDR_pair12", "dDR_pair12", 100, 0.0, 10.0);
  
  //dETA, dPHI, dDR plots for the first pair not used: (1,3).
  
  Manager()->AddHisto("dETA_pair13", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_dETA_pair13 = new TH1F("dETA_pair13", "dETA_pair13", 100, -8.0, 8.0);
  
  Manager()->AddHisto("dPHI_pair13", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_dPHI_pair13 = new TH1F("dPHI_pair13", "dPHI_pair13", 100, -3.0, 3.0);
  
  Manager()->AddHisto("dDR_pair13", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_dDR_pair13 = new TH1F("dDR_pair13", "dDR_pair13", 100, 0.0, 10.0);
  
  //dETA, dPHI, dDR plots for the first pair not used: (1,4).
  
  Manager()->AddHisto("dETA_pair14", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_dETA_pair14 = new TH1F("dETA_pair14", "dETA_pair14", 100, -8.0, 8.0);
  
  Manager()->AddHisto("dPHI_pair14", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_dPHI_pair14 = new TH1F("dPHI_pair14", "dPHI_pair14", 100, -3.0, 3.0);
  
  Manager()->AddHisto("dDR_pair14", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_dDR_pair14 = new TH1F("dDR_pair14", "dDR_pair14", 100, 0.0, 10.0);
  
  //dETA, dPHI, dDR plots for the first pair not used: (2,3).
  
  Manager()->AddHisto("dETA_pair23", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_dETA_pair23 = new TH1F("dETA_pair23", "dETA_pair23", 100, -8.0, 8.0);
  
  Manager()->AddHisto("dPHI_pair23", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_dPHI_pair23 = new TH1F("dPHI_pair23", "dPHI_pair23", 100, -3.0, 3.0);
  
  Manager()->AddHisto("dDR_pair23", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_dDR_pair23 = new TH1F("dDR_pair23", "dDR_pair23", 100, 0.0, 10.0);
  
  //dETA, dPHI, dDR plots for the first pair not used: (2,4).
  
  Manager()->AddHisto("dETA_pair24", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_dETA_pair24 = new TH1F("dETA_pair24", "dETA_pair24", 100, -8.0, 8.0);
  
  Manager()->AddHisto("dPHI_pair24", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_dPHI_pair24 = new TH1F("dPHI_pair24", "dPHI_pair24", 100, -3.0, 3.0);
  
  Manager()->AddHisto("dDR_pair24", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_dDR_pair24 = new TH1F("dDR_pair24", "dDR_pair24", 100, 0.0, 10.0);
  
  //dETA, dPHI, dDR plots for the first pair not used: (3,4).
  
  Manager()->AddHisto("dETA_pair34", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_dETA_pair34 = new TH1F("dETA_pair34", "dETA_pair34", 100, -8.0, 8.0);
  
  Manager()->AddHisto("dPHI_pair34", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_dPHI_pair34 = new TH1F("dPHI_pair34", "dPHI_pair34", 100, -3.0, 3.0);
  
  Manager()->AddHisto("dDR_pair34", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_dDR_pair34 = new TH1F("dDR_pair34", "dDR_pair34", 100, 0.0, 10.0);
  
  //general plots b_dijet2
  
  Manager()->AddHisto("PT_b_dijet2", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet2 = new TH1F("PT_b_dijet2", "PT_b_dijet2", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet2", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet2 = new TH1F("ETA_b_dijet2", "ETA_b_dijet2", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet2", 100, 100.0, 300.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet2 = new TH1F("M_b_dijet2", "M_b_dijet2", 100, 100.0, 300.0);

  Manager()->AddHisto("PHI_b_dijet2", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet2 = new TH1F("PHI_b_dijet2", "PHI_b_dijet2", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet2", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet2 = new TH1F("DR_b_dijet2", "DR_b_dijet2", 100, 0.0, 10.0);
  
  //DIJETS *******************************************************************************************************************************************************************************************
  //plots of the dijet2 pairs that are not merged.

  Manager()->AddHisto("PT_dijet2_not", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet2_not = new TH1F("PT_dijet2_not", "PT_dijet2_not", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet2_not", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet2_not = new TH1F("ETA_dijet2_not", "ETA_dijet2_not", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet2_not", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet2_not = new TH1F("M_dijet2_not", "M_dijet2_not", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet2_not", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet2_not = new TH1F("PHI_dijet2_not", "PHI_dijet2_not", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet2_not", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet2_not = new TH1F("DR_dijet2_not", "DR_dijet2_not", 100, 0.0, 10.0);
  
  //plots of the dijet2 pairs that are partially merged.

  Manager()->AddHisto("PT_dijet2_partially", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet2_partially = new TH1F("PT_dijet2_partially", "PT_dijet2_partially", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet2_partially", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet2_partially = new TH1F("ETA_dijet2_partially", "ETA_dijet2_partially", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet2_partially", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet2_partially = new TH1F("M_dijet2_partially", "M_dijet2_partially", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet2_partially", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet2_partially = new TH1F("PHI_dijet2_partially", "PHI_dijet2_partially", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet2_partially", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet2_partially = new TH1F("DR_dijet2_partially", "DR_dijet2_partially", 100, 0.0, 10.0);
  
  //plots of the dijet2 pairs that are fully merged.

  Manager()->AddHisto("PT_dijet2_fully", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_dijet2_fully = new TH1F("PT_dijet2_fully", "PT_dijet2_fully", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_dijet2_fully", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_dijet2_fully = new TH1F("ETA_dijet2_fully", "ETA_dijet2_fully", 100, -8.0, 8.0);

  Manager()->AddHisto("M_dijet2_fully", 100, 0.0, 100.0); /*Name, bins, x_initial, x_final*/
  plot_M_dijet2_fully = new TH1F("M_dijet2_fully", "M_dijet2_fully", 100, 0.0, 100.0);

  Manager()->AddHisto("PHI_dijet2_fully", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_dijet2_fully = new TH1F("PHI_dijet2_fully", "PHI_dijet2_fully", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_dijet2_fully", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_dijet2_fully = new TH1F("DR_dijet2_fully", "DR_dijet2_fully", 100, 0.0, 10.0);
  
  //B-DIJET2 *****************************************************************************************************************************************************************************************
  //plots of the b_dijet2 pairs that are partially merged.

  Manager()->AddHisto("PT_b_dijet2_partially", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet2_partially = new TH1F("PT_b_dijet2_partially", "PT_b_dijet2_partially", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet2_partially", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet2_partially = new TH1F("ETA_b_dijet2_partially", "ETA_b_dijet2_partially", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet2_partially", 100, 100.0, 300.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet2_partially = new TH1F("M_b_dijet2_partially", "M_b_dijet2_partially", 100, 100.0, 300.0);

  Manager()->AddHisto("PHI_b_dijet2_partially", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet2_partially = new TH1F("PHI_b_dijet2_partially", "PHI_b_dijet2_partially", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet2_partially", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet2_partially = new TH1F("DR_b_dijet2_partially", "DR_b_dijet2_partially", 100, 0.0, 10.0);
  
  //plots of the b_dijet2 pairs that are fully merged.

  Manager()->AddHisto("PT_b_dijet2_fully", 100, 0.0, 1000.0); /*Name, bins, x_initial, x_final*/
  plot_PT_b_dijet2_fully = new TH1F("PT_b_dijet2_fully", "PT_b_dijet2_fully", 100, 0.0, 1000.0);

  Manager()->AddHisto("ETA_b_dijet2_fully", 100, -8.0, 8.0); /*Name, bins, x_initial, x_final*/
  plot_ETA_b_dijet2_fully = new TH1F("ETA_b_dijet2_fully", "ETA_b_dijet2_fully", 100, -8.0, 8.0);

  Manager()->AddHisto("M_b_dijet2_fully", 100, 100.0, 300.0); /*Name, bins, x_initial, x_final*/
  plot_M_b_dijet2_fully = new TH1F("M_b_dijet2_fully", "M_b_dijet2_fully", 100, 100.0, 300.0);

  Manager()->AddHisto("PHI_b_dijet2_fully", 100, -3.0, 3.0); /*Name, bins, x_initial, x_final*/
  plot_PHI_b_dijet2_fully = new TH1F("PHI_b_dijet2_fully", "PHI_b_dijet2_fully", 100, -3.0, 3.0);

  Manager()->AddHisto("DR_b_dijet2_fully", 100, 0.0, 10.0); /*Name, bins, x_initial, x_final*/
  plot_DR_b_dijet2_fully = new TH1F("DR_b_dijet2_fully", "DR_b_dijet2_fully", 100, 0.0, 10.0);
  
  
  
  
  
  
  
  cout << "END   Initialization" << endl;
  return true;
}

// -----------------------------------------------------------------------------
// Finalize
// function called one time at the end of the analysis
// -----------------------------------------------------------------------------
void Analysis::Finalize(const SampleFormat& summary, const std::vector<SampleFormat>& files)
{
  cout << "BEGIN Finalization" << endl;
  // saving histos
  
  TFile* Output = new TFile("resultados.root", "RECREATE");
  
  //1 -> solid
  //2 -> dashed
  //3 -> doted
  //4 -> dashed-doted
  
  //**************************************************************************************************************************************************************************************************
  //**************************************************************************************************************************************************************************************************
  //PLOTS OF THE FIRST PAIR OF DIJET AND B_DIJET******************************************************************************************************************************************************
  //general plots
  plot_FoundPair->SetLineStyle(1);
  plot_N_Merged1->SetLineStyle(1);
  
  //general plots dijet1
  plot_PT_dijet1->SetLineStyle(1);
  plot_ETA_dijet1->SetLineStyle(1);
  plot_M_dijet1->SetLineStyle(1);
  plot_PHI_dijet1->SetLineStyle(1);
  plot_DR_dijet1->SetLineStyle(1);
  
  //general plots b_dijet1
  plot_PT_b_dijet1->SetLineStyle(1);
  plot_ETA_b_dijet1->SetLineStyle(1);
  plot_M_b_dijet1->SetLineStyle(1);
  plot_PHI_b_dijet1->SetLineStyle(1);
  plot_DR_b_dijet1->SetLineStyle(1);
  
  //DIJET1 *******************************************************************************************************************************************************************************************
  //plots of the dijet1 pairs that are not merged.
  plot_PT_dijet1_not->SetLineStyle(1);
  plot_ETA_dijet1_not->SetLineStyle(1);
  plot_M_dijet1_not->SetLineStyle(1);
  plot_PHI_dijet1_not->SetLineStyle(1);
  plot_DR_dijet1_not->SetLineStyle(1);
  
  //plots of the dijet1 pairs that are partially merged.
  plot_PT_dijet1_partially->SetLineStyle(1);
  plot_ETA_dijet1_partially->SetLineStyle(1);
  plot_M_dijet1_partially->SetLineStyle(1);
  plot_PHI_dijet1_partially->SetLineStyle(1);
  plot_DR_dijet1_partially->SetLineStyle(1);
  
  //plots of the dijet1 pairs that are fully merged.
  plot_PT_dijet1_fully->SetLineStyle(1);
  plot_ETA_dijet1_fully->SetLineStyle(1);
  plot_M_dijet1_fully->SetLineStyle(1);
  plot_PHI_dijet1_fully->SetLineStyle(1);
  plot_DR_dijet1_fully->SetLineStyle(1);
  
  //B_DIJET1 *****************************************************************************************************************************************************************************************
  //plots of the b_dijet1 pairs that are partially merged.
  plot_PT_b_dijet1_partially->SetLineStyle(1);
  plot_ETA_b_dijet1_partially->SetLineStyle(1);
  plot_M_b_dijet1_partially->SetLineStyle(1);
  plot_PHI_b_dijet1_partially->SetLineStyle(1);
  plot_DR_b_dijet1_partially->SetLineStyle(1);
  
  //plots of the b_dijet1 pairs that are fully merged.
  plot_PT_b_dijet1_fully->SetLineStyle(1);
  plot_ETA_b_dijet1_fully->SetLineStyle(1);
  plot_M_b_dijet1_fully->SetLineStyle(1);
  plot_PHI_b_dijet1_fully->SetLineStyle(1);
  plot_DR_b_dijet1_fully->SetLineStyle(1);
  
  //PLOTS OF THE THE TWO B****************************************************************************************************************************************************************************
  //plots of b1.
  plot_PT_b1->SetLineStyle(1);
  plot_ETA_b1->SetLineStyle(1);
  plot_PHI_b1->SetLineStyle(1);
  
  //plots of b2.
  plot_PT_b2->SetLineStyle(1);
  plot_ETA_b2->SetLineStyle(1);
  plot_PHI_b2->SetLineStyle(1);
  
  
  
  
  
  //PLOTS OF THE SECOND PAIR OF DIJET AND B_DIJET ****************************************************************************************************************************************************
  //ONLY USED IN THE FULLY HADRONIC CHANNEL **********************************************************************************************************************************************************
  //general plots dijet2
  plot_N_Merged2->SetLineStyle(1);
  plot_Smallest_DR_dijet->SetLineStyle(1);
  plot_Smallest_DR_b_dijet->SetLineStyle(1);
  plot_Pairs->SetLineStyle(1);
  plot_Pairs_b->SetLineStyle(1);
  plot_Mother_Particles_dijets->SetLineStyle(1);
  
  //general plots dijet2
  plot_PT_dijet2->SetLineStyle(1);
  plot_ETA_dijet2->SetLineStyle(1);
  plot_M_dijet2->SetLineStyle(1);
  plot_PHI_dijet2->SetLineStyle(1);
  plot_DR_dijet2->SetLineStyle(1);
  
  //dETA, dPHI, dDR plots for the first dijet.
  plot_dETA_dijet1->SetLineStyle(1);
  plot_dPHI_dijet1->SetLineStyle(1);
  plot_dDR_dijet1->SetLineStyle(1);
  //dETA, dPHI, dDR plots for the second dijet.
  plot_dETA_dijet2->SetLineStyle(1);
  plot_dPHI_dijet2->SetLineStyle(1);
  plot_dDR_dijet2->SetLineStyle(1);
  //dETA, dPHI, dDR plots for the first pair not used: (1,2).
  plot_dETA_pair12->SetLineStyle(1);
  plot_dPHI_pair12->SetLineStyle(1);
  plot_dDR_pair12->SetLineStyle(1);
  //dETA, dPHI, dDR plots for the second pair not used: (1,3).
  plot_dETA_pair13->SetLineStyle(1);
  plot_dPHI_pair13->SetLineStyle(1);
  plot_dDR_pair13->SetLineStyle(1);
  //dETA, dPHI, dDR plots for the third pair not used: (1,4).
  plot_dETA_pair14->SetLineStyle(1);
  plot_dPHI_pair14->SetLineStyle(1);
  plot_dDR_pair14->SetLineStyle(1);
  //dETA, dPHI, dDR plots for the fourth pair not used: (2,3).
  plot_dETA_pair23->SetLineStyle(1);
  plot_dPHI_pair23->SetLineStyle(1);
  plot_dDR_pair23->SetLineStyle(1);
  //dETA, dPHI, dDR plots for the fifth pair not used: (2,4).
  plot_dETA_pair24->SetLineStyle(1);
  plot_dPHI_pair24->SetLineStyle(1);
  plot_dDR_pair24->SetLineStyle(1);
  //dETA, dPHI, dDR plots for the sixth pair not used: (3,4).
  plot_dETA_pair34->SetLineStyle(1);
  plot_dPHI_pair34->SetLineStyle(1);
  plot_dDR_pair34->SetLineStyle(1);
  
  //general plots b_dijet2
  plot_PT_b_dijet2->SetLineStyle(1);
  plot_ETA_b_dijet2->SetLineStyle(1);
  plot_M_b_dijet2->SetLineStyle(1);
  plot_PHI_b_dijet2->SetLineStyle(1);
  plot_DR_b_dijet2->SetLineStyle(1);
  
  //DIJET2 *******************************************************************************************************************************************************************************************
  //plots of the dijet2 pairs that are not merged.
  plot_PT_dijet2_not->SetLineStyle(1);
  plot_ETA_dijet2_not->SetLineStyle(1);
  plot_M_dijet2_not->SetLineStyle(1);
  plot_PHI_dijet2_not->SetLineStyle(1);
  plot_DR_dijet2_not->SetLineStyle(1);
  
  //plots of the dijet2 pairs that are partially merged.
  plot_PT_dijet2_partially->SetLineStyle(1);
  plot_ETA_dijet2_partially->SetLineStyle(1);
  plot_M_dijet2_partially->SetLineStyle(1);
  plot_PHI_dijet2_partially->SetLineStyle(1);
  plot_DR_dijet2_partially->SetLineStyle(1);
  
  //plots of the dijet2 pairs that are fully merged.
  plot_PT_dijet2_fully->SetLineStyle(1);
  plot_ETA_dijet2_fully->SetLineStyle(1);
  plot_M_dijet2_fully->SetLineStyle(1);
  plot_PHI_dijet2_fully->SetLineStyle(1);
  plot_DR_dijet2_fully->SetLineStyle(1);
  
  //B_DIJET2 *****************************************************************************************************************************************************************************************
  //plots of the b_dijet2 pairs that are partially merged.
  plot_PT_b_dijet2_partially->SetLineStyle(1);
  plot_ETA_b_dijet2_partially->SetLineStyle(1);
  plot_M_b_dijet2_partially->SetLineStyle(1);
  plot_PHI_b_dijet2_partially->SetLineStyle(1);
  plot_DR_b_dijet2_partially->SetLineStyle(1);
  
  //plots of the b_dijet2 pairs that are fully merged.
  plot_PT_b_dijet2_fully->SetLineStyle(1);
  plot_ETA_b_dijet2_fully->SetLineStyle(1);
  plot_M_b_dijet2_fully->SetLineStyle(1);
  plot_PHI_b_dijet2_fully->SetLineStyle(1);
  plot_DR_b_dijet2_fully->SetLineStyle(1);
  
  
  
  
  
  //**************************************************************************************************************************************************************************************************
  //**************************************************************************************************************************************************************************************************
  //PLOTS OF THE FIRST PAIR OF DIJET AND B_DIJET******************************************************************************************************************************************************
  //general plots
  TAxis* a = plot_FoundPair->GetXaxis();
  a->SetBit(TAxis::kLabelsHori);
  a->SetBinLabel(1,"Found");
  a->SetBinLabel(2,"Not found");
  plot_FoundPair->Draw("HIST");
  
  TAxis* b = plot_N_Merged1->GetXaxis();
  b->SetBit(TAxis::kLabelsHori); 
  b->SetBinLabel(1,"Not Merged"); 
  b->SetBinLabel(2,"Partially Merged"); 
  b->SetBinLabel(3,"Fully Merged");
  plot_N_Merged1->Draw("HIST");
  
  //general plots dijet1
  plot_PT_dijet1->Draw("HIST");
  plot_ETA_dijet1->Draw("HIST");
  plot_M_dijet1->Draw("HIST");
  plot_PHI_dijet1->Draw("HIST");
  plot_DR_dijet1->Draw("HIST");
  
  //general plots b_dijet1
  plot_PT_b_dijet1->Draw("HIST");
  plot_ETA_b_dijet1->Draw("HIST");
  plot_M_b_dijet1->Draw("HIST");
  plot_PHI_b_dijet1->Draw("HIST");
  plot_DR_b_dijet1->Draw("HIST");
  
  //DIJET1 *******************************************************************************************************************************************************************************************
  //plots of the dijet1 pairs that are not merged.
  plot_PT_dijet1_not->Draw("HIST");
  plot_ETA_dijet1_not->Draw("HIST");
  plot_M_dijet1_not->Draw("HIST");
  plot_PHI_dijet1_not->Draw("HIST");
  plot_DR_dijet1_not->Draw("HIST");
  
  //plots of the dijet1 pairs that are partially merged.
  plot_PT_dijet1_partially->Draw("HIST");
  plot_ETA_dijet1_partially->Draw("HIST");
  plot_M_dijet1_partially->Draw("HIST");
  plot_PHI_dijet1_partially->Draw("HIST");
  plot_DR_dijet1_partially->Draw("HIST");
  
  //plots of the dijet1 pairs that are fully merged.
  plot_PT_dijet1_fully->Draw("HIST");
  plot_ETA_dijet1_fully->Draw("HIST");
  plot_M_dijet1_fully->Draw("HIST");
  plot_PHI_dijet1_fully->Draw("HIST");
  plot_DR_dijet1_fully->Draw("HIST");
  
  //B_DIJET1 *****************************************************************************************************************************************************************************************
  //plots of the b_dijet1 pairs that are partially merged.
  plot_PT_b_dijet1_partially->Draw("HIST");
  plot_ETA_b_dijet1_partially->Draw("HIST");
  plot_M_b_dijet1_partially->Draw("HIST");
  plot_PHI_b_dijet1_partially->Draw("HIST");
  plot_DR_b_dijet1_partially->Draw("HIST");
  
  //plots of the b_dijet1 pairs that are fully merged.
  plot_PT_b_dijet1_fully->Draw("HIST");
  plot_ETA_b_dijet1_fully->Draw("HIST");
  plot_M_b_dijet1_fully->Draw("HIST");
  plot_PHI_b_dijet1_fully->Draw("HIST");
  plot_DR_b_dijet1_fully->Draw("HIST");
  
  //PLOTS OF THE THE TWO B****************************************************************************************************************************************************************************
  //plots of b1.
  plot_PT_b1->Draw("HIST");
  plot_ETA_b1->Draw("HIST");
  plot_PHI_b1->Draw("HIST");
  
  //plots of b2.
  plot_PT_b2->Draw("HIST");
  plot_ETA_b2->Draw("HIST");
  plot_PHI_b2->Draw("HIST");
  
  
  
  
  
  //PLOTS OF THE SECOND PAIR OF DIJET AND B_DIJET ****************************************************************************************************************************************************
  //ONLY USED IN THE FULLY HADRONIC CHANNEL **********************************************************************************************************************************************************
  //general plots
  TAxis* c = plot_N_Merged2->GetXaxis();
  c->SetBit(TAxis::kLabelsHori); 
  c->SetBinLabel(1,"Not Merged"); 
  c->SetBinLabel(2,"Partially Merged"); 
  c->SetBinLabel(3,"Fully Merged");
  plot_N_Merged2->Draw("HIST");
  
  TAxis* d = plot_Smallest_DR_dijet->GetXaxis();
  d->SetBit(TAxis::kLabelsHori); 
  d->SetBinLabel(1,"Smallest DR"); 
  d->SetBinLabel(2,"Not Smallest DR"); 
  plot_Smallest_DR_dijet->Draw("HIST");
  
  TAxis* e = plot_Smallest_DR_b_dijet->GetXaxis();
  e->SetBit(TAxis::kLabelsHori); 
  e->SetBinLabel(1,"Smallest DR"); 
  e->SetBinLabel(2,"Not Smallest DR"); 
  plot_Smallest_DR_b_dijet->Draw("HIST");
  
  TAxis* f = plot_Pairs->GetXaxis();
  f->SetBit(TAxis::kLabelsHori); 
  f->SetBinLabel(1,"(j_{1},j_{2}),(j_{3},j_{4})"); 
  f->SetBinLabel(2,"(j_{1},j_{3}),(j_{2},j_{4})");
  f->SetBinLabel(3,"(j_{1},j_{4}),(j_{2},j_{3})");
  plot_Pairs->Draw("HIST");
  
  TAxis* g = plot_Pairs_b->GetXaxis();
  g->SetBit(TAxis::kLabelsHori); 
  g->SetBinLabel(1,"(j_{1},j_{2},b_{1}),(j_{3},j_{4},b_{2})"); 
  g->SetBinLabel(2,"(j_{1},j_{2},b_{2}),(j_{3},j_{4},b_{1})");
  g->SetBinLabel(3,"(j_{1},j_{3},b_{1}),(j_{2},j_{4},b_{2})");
  g->SetBinLabel(4,"(j_{1},j_{3},b_{2}),(j_{2},j_{4},b_{1})");
  g->SetBinLabel(5,"(j_{1},j_{4},b_{1}),(j_{2},j_{3},b_{2})");
  g->SetBinLabel(6,"(j_{1},j_{4},b_{2}),(j_{2},j_{3},b_{1})");
  plot_Pairs_b->Draw("HIST");
  
  TAxis* h = plot_Mother_Particles_dijets->GetXaxis();
  h->SetBit(TAxis::kLabelsHori); 
  h->SetBinLabel(1,"Same mother particles"); 
  h->SetBinLabel(2,"Not same mother particles");
  plot_Mother_Particles_dijets->Draw("HIST");
  
  //general plots dijet2
  plot_PT_dijet2->Draw("HIST");
  plot_ETA_dijet2->Draw("HIST");
  plot_M_dijet2->Draw("HIST");
  plot_PHI_dijet2->Draw("HIST");
  plot_DR_dijet2->Draw("HIST");
  
  //dETA, dPHI, dDR plots for the first dijet.
  plot_dETA_dijet1->Draw("HIST");
  plot_dPHI_dijet1->Draw("HIST");
  plot_dDR_dijet1->Draw("HIST");
  //dETA, dPHI, dDR plots for the second dijet.
  plot_dETA_dijet2->Draw("HIST");
  plot_dPHI_dijet2->Draw("HIST");
  plot_dDR_dijet2->Draw("HIST");
  //dETA, dPHI, dDR plots for the first pair not used: (1,2).
  plot_dETA_pair12->Draw("HIST");
  plot_dPHI_pair12->Draw("HIST");
  plot_dDR_pair12->Draw("HIST");
  //dETA, dPHI, dDR plots for the second pair not used: (1,3).
  plot_dETA_pair13->Draw("HIST");
  plot_dPHI_pair13->Draw("HIST");
  plot_dDR_pair13->Draw("HIST");
  //dETA, dPHI, dDR plots for the third pair not used: (1,4).
  plot_dETA_pair14->Draw("HIST");
  plot_dPHI_pair14->Draw("HIST");
  plot_dDR_pair14->Draw("HIST");
  //dETA, dPHI, dDR plots for the fourth pair not used: (2,3).
  plot_dETA_pair23->Draw("HIST");
  plot_dPHI_pair23->Draw("HIST");
  plot_dDR_pair23->Draw("HIST");
  //dETA, dPHI, dDR plots for the fifth pair not used: (2,4).
  plot_dETA_pair24->Draw("HIST");
  plot_dPHI_pair24->Draw("HIST");
  plot_dDR_pair24->Draw("HIST");
  //dETA, dPHI, dDR plots for the sixth pair not used: (3,4).
  plot_dETA_pair34->Draw("HIST");
  plot_dPHI_pair34->Draw("HIST");
  plot_dDR_pair34->Draw("HIST");
  
  //general plots b_dijet2
  plot_PT_b_dijet2->Draw("HIST");
  plot_ETA_b_dijet2->Draw("HIST");
  plot_M_b_dijet2->Draw("HIST");
  plot_PHI_b_dijet2->Draw("HIST");
  plot_DR_b_dijet2->Draw("HIST");
  
  //DIJET2 *******************************************************************************************************************************************************************************************
  //plots of the dijet2 pairs that are not merged.
  plot_PT_dijet2_not->Draw("HIST");
  plot_ETA_dijet2_not->Draw("HIST");
  plot_M_dijet2_not->Draw("HIST");
  plot_PHI_dijet2_not->Draw("HIST");
  plot_DR_dijet2_not->Draw("HIST");
  
  //plots of the dijet2 pairs that are partially merged.
  plot_PT_dijet2_partially->Draw("HIST");
  plot_ETA_dijet2_partially->Draw("HIST");
  plot_M_dijet2_partially->Draw("HIST");
  plot_PHI_dijet2_partially->Draw("HIST");
  plot_DR_dijet2_partially->Draw("HIST");
  
  //plots of the dijet2 pairs that are fully merged.
  plot_PT_dijet2_fully->Draw("HIST");
  plot_ETA_dijet2_fully->Draw("HIST");
  plot_M_dijet2_fully->Draw("HIST");
  plot_PHI_dijet2_fully->Draw("HIST");
  plot_DR_dijet2_fully->Draw("HIST");
  
  //B_DIJET2 *****************************************************************************************************************************************************************************************
  //plots of the b_dijet2 pairs that are partially merged.
  plot_PT_b_dijet2_partially->Draw("HIST");
  plot_ETA_b_dijet2_partially->Draw("HIST");
  plot_M_b_dijet2_partially->Draw("HIST");
  plot_PHI_b_dijet2_partially->Draw("HIST");
  plot_DR_b_dijet2_partially->Draw("HIST");
  
  //plots of the b_dijet2 pairs that are fully merged.
  plot_PT_b_dijet2_fully->Draw("HIST");
  plot_ETA_b_dijet2_fully->Draw("HIST");
  plot_M_b_dijet2_fully->Draw("HIST");
  plot_PHI_b_dijet2_fully->Draw("HIST");
  plot_DR_b_dijet2_fully->Draw("HIST");
  
  
  
  
  
  //**************************************************************************************************************************************************************************************************
  //**************************************************************************************************************************************************************************************************
  //PLOTS OF THE FIRST PAIR OF DIJET AND B_DIJET******************************************************************************************************************************************************
  //general plots
  plot_FoundPair->Write();
  plot_N_Merged1->Write();
  
  //general plots dijet1
  plot_PT_dijet1->Write();
  plot_ETA_dijet1->Write();
  plot_M_dijet1->Write();
  plot_PHI_dijet1->Write();
  plot_DR_dijet1->Write();
  
  //general plots b_dijet1
  plot_PT_b_dijet1->Write();
  plot_ETA_b_dijet1->Write();
  plot_M_b_dijet1->Write();
  plot_PHI_b_dijet1->Write();
  plot_DR_b_dijet1->Write();
  
  //DIJET1 *******************************************************************************************************************************************************************************************
  //plots of the dijet1 pairs that are not merged.
  plot_PT_dijet1_not->Write();
  plot_ETA_dijet1_not->Write();
  plot_M_dijet1_not->Write();
  plot_PHI_dijet1_not->Write();
  plot_DR_dijet1_not->Write();
  
  //plots of the dijet1 pairs that are partially merged.
  plot_PT_dijet1_partially->Write();
  plot_ETA_dijet1_partially->Write();
  plot_M_dijet1_partially->Write();
  plot_PHI_dijet1_partially->Write();
  plot_DR_dijet1_partially->Write();
  
  //plots of the dijet1 pairs that are fully merged.
  plot_PT_dijet1_fully->Write();
  plot_ETA_dijet1_fully->Write();
  plot_M_dijet1_fully->Write();
  plot_PHI_dijet1_fully->Write();
  plot_DR_dijet1_fully->Write();
  
  //B_DIJET1 *****************************************************************************************************************************************************************************************
  //plots of the b_dijet1 pairs that are partially merged.
  plot_PT_b_dijet1_partially->Write();
  plot_ETA_b_dijet1_partially->Write();
  plot_M_b_dijet1_partially->Write();
  plot_PHI_b_dijet1_partially->Write();
  plot_DR_b_dijet1_partially->Write();
  
  //plots of the b_dijet1 pairs that are fully merged.
  plot_PT_b_dijet1_fully->Write();
  plot_ETA_b_dijet1_fully->Write();
  plot_M_b_dijet1_fully->Write();
  plot_PHI_b_dijet1_fully->Write();
  plot_DR_b_dijet1_fully->Write();
  
  //PLOTS OF THE THE TWO B****************************************************************************************************************************************************************************
  //plots of b1.
  plot_PT_b1->Write();
  plot_ETA_b1->Write();
  plot_PHI_b1->Write();
  
  //plots of b2.
  plot_PT_b2->Write();
  plot_ETA_b2->Write();
  plot_PHI_b2->Write();
  
  
  
  
  
  //PLOTS OF THE SECOND PAIR OF DIJET AND B_DIJET ****************************************************************************************************************************************************
  //ONLY USED IN THE FULLY HADRONIC CHANNEL **********************************************************************************************************************************************************
  //general plots
  plot_N_Merged2->Write();
  plot_Smallest_DR_dijet->Write();
  plot_Smallest_DR_b_dijet->Write();
  plot_Pairs->Write();
  plot_Pairs_b->Write();
  plot_Mother_Particles_dijets->Write();
  
  //general plots dijet2
  plot_PT_dijet2->Write();
  plot_ETA_dijet2->Write();
  plot_M_dijet2->Write();
  plot_PHI_dijet2->Write();
  plot_DR_dijet2->Write();
  
  //dETA, dPHI, dDR plots for the first dijet.
  plot_dETA_dijet1->Write();
  plot_dPHI_dijet1->Write();
  plot_dDR_dijet1->Write();
  //dETA, dPHI, dDR plots for the second dijet.
  plot_dETA_dijet2->Write();
  plot_dPHI_dijet2->Write();
  plot_dDR_dijet2->Write();
  //dETA, dPHI, dDR plots for the first pair not used: (1,2).
  plot_dETA_pair12->Write();
  plot_dPHI_pair12->Write();
  plot_dDR_pair12->Write();
  //dETA, dPHI, dDR plots for the second pair not used: (1,3).
  plot_dETA_pair13->Write();
  plot_dPHI_pair13->Write();
  plot_dDR_pair13->Write();
  //dETA, dPHI, dDR plots for the third pair not used: (1,4).
  plot_dETA_pair14->Write();
  plot_dPHI_pair14->Write();
  plot_dDR_pair14->Write();
  //dETA, dPHI, dDR plots for the fourth pair not used: (2,3).
  plot_dETA_pair23->Write();
  plot_dPHI_pair23->Write();
  plot_dDR_pair23->Write();
  //dETA, dPHI, dDR plots for the fifth pair not used: (2,4).
  plot_dETA_pair24->Write();
  plot_dPHI_pair24->Write();
  plot_dDR_pair24->Write();
  //dETA, dPHI, dDR plots for the sixth pair not used: (3,4).
  plot_dETA_pair34->Write();
  plot_dPHI_pair34->Write();
  plot_dDR_pair34->Write();
  
  //general plots b_dijet2
  plot_PT_b_dijet2->Write();
  plot_ETA_b_dijet2->Write();
  plot_M_b_dijet2->Write();
  plot_PHI_b_dijet2->Write();
  plot_DR_b_dijet2->Write();
  
  //DIJET2 *******************************************************************************************************************************************************************************************
  //plots of the dijet2 pairs that are not merged.
  plot_PT_dijet2_not->Write();
  plot_ETA_dijet2_not->Write();
  plot_M_dijet2_not->Write();
  plot_PHI_dijet2_not->Write();
  plot_DR_dijet2_not->Write();
  
  //plots of the dijet2 pairs that are partially merged.
  plot_PT_dijet2_partially->Write();
  plot_ETA_dijet2_partially->Write();
  plot_M_dijet2_partially->Write();
  plot_PHI_dijet2_partially->Write();
  plot_DR_dijet2_partially->Write();
  
  //plots of the dijet2 pairs that are fully merged.
  plot_PT_dijet2_fully->Write();
  plot_ETA_dijet2_fully->Write();
  plot_M_dijet2_fully->Write();
  plot_PHI_dijet2_fully->Write();
  plot_DR_dijet2_fully->Write();
  
  //B_DIJET2 *****************************************************************************************************************************************************************************************
  //plots of the b_dijet2 pairs that are partially merged.
  plot_PT_b_dijet2_partially->Write();
  plot_ETA_b_dijet2_partially->Write();
  plot_M_b_dijet2_partially->Write();
  plot_PHI_b_dijet2_partially->Write();
  plot_DR_b_dijet2_partially->Write();
  
  //plots of the b_dijet2 pairs that are fully merged.
  plot_PT_b_dijet2_fully->Write();
  plot_ETA_b_dijet2_fully->Write();
  plot_M_b_dijet2_fully->Write();
  plot_PHI_b_dijet2_fully->Write();
  plot_DR_b_dijet2_fully->Write();
  
  Output->Close();
   
  cout << "END   Finalization" << endl;
}

// -----------------------------------------------------------------------------
// Execute
// function called each time one event is read
// -----------------------------------------------------------------------------
bool Analysis::Execute(SampleFormat& sample, const EventFormat& event)
{

	//Clear all vectors.
	FinalStateLeptons.clear();
	FinalStateNeutrinos.clear();
	FinalStateJs.clear();
	FinalStateBs.clear();
	notMerged.clear();
	partiallyMerged.clear();
	fullyMerged.clear();
	smallestdr.clear();
	
	//Fill the vectors that contain final state particles.
	for (MAuint32 i = 0 ; i < event.mc()->particles().size(); i++){
    		ClassifyParticles(&(event.mc()->particles()[i]), FinalStateLeptons, FinalStateNeutrinos, FinalStateJs, FinalStateBs);
    	}
      	
      	//Organize the final state particles by their PT.
      	OrganizeByPT(FinalStateLeptons);
      	OrganizeByPT(FinalStateNeutrinos);
      	OrganizeByPT(FinalStateJs);
	OrganizeByPT(FinalStateBs);
      	
	//Reconstruct the events depending on wether the fully-hadronic or semi-leptonic channel is being studied.
	if (FinalStateJs.size() == 4){
		MergedFullyHadronic(FinalStateJs, FinalStateBs, dijet1, dijet2, b_dijet1, b_dijet2);
	}
	if (FinalStateJs.size() == 2){
		MergedSemiLeptonic(FinalStateJs, FinalStateBs, dijet1, b_dijet1);
	}
	
	
	
	
	
	if (index_j2 != 0){
	//********************************************************************************************************************************************************************************************
	//********************************************************************************************************************************************************************************************
	//PLOTS OF THE FIRST PAIR OF DIJET AND B_DIJET************************************************************************************************************************************************
	//general plots
	
	//fills FoundPair.
	Manager()->FillHisto("FoundPair",1);
	plot_FoundPair->Fill(1);
	
	//fills N_merged1.
	if (notMerged[0]){
		Manager()->FillHisto("N_Merged1", 1);
		plot_N_Merged1->Fill(1);
	}
	
	if (partiallyMerged[0]){
		Manager()->FillHisto("N_Merged1", 2);
		plot_N_Merged1->Fill(2);
	}
	
	if (fullyMerged[0]){
		Manager()->FillHisto("N_Merged1", 3);
		plot_N_Merged1->Fill(3);
	}
  
	//general plots dijet1
	
	//fils PT_dijet1.
	Manager()->FillHisto("PT_dijet1", dijet1.Pt());
        plot_PT_dijet1->Fill(dijet1.Pt());

	//fils ETA_dijet1.
	Manager()->FillHisto("ETA_dijet1", dijet1.Eta());
        plot_ETA_dijet1->Fill(dijet1.Eta());

	//fils M_dijet1.
	Manager()->FillHisto("M_dijet1", dijet1.M());
        plot_M_dijet1->Fill(dijet1.M());
        
	//fils PHI_dijet1.
	Manager()->FillHisto("PHI_dijet1", dijet1.Phi());
        plot_PHI_dijet1->Fill(dijet1.Phi());
        
	//fils DR_dijet1.
	Manager()->FillHisto("DR_dijet1", (FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
        plot_DR_dijet1->Fill((FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
	
	//general plots b_dijet1
	
	//fils PT_b_dijet1.
	Manager()->FillHisto("PT_b_dijet1", b_dijet1.Pt());
        plot_PT_b_dijet1->Fill(b_dijet1.Pt());

	//fils ETA_b_dijet1.
	Manager()->FillHisto("ETA_b_dijet1", b_dijet1.Eta());
      	plot_ETA_b_dijet1->Fill(b_dijet1.Eta());

	//fils M_b_dijet1.
	Manager()->FillHisto("M_b_dijet1", b_dijet1.M());
      	plot_M_b_dijet1->Fill(b_dijet1.M());
        
	//fils PHI_b_dijet1.
	Manager()->FillHisto("PHI_b_dijet1", b_dijet1.Phi());
      	plot_PHI_b_dijet1->Fill(b_dijet1.Phi());
        
	//fils DR_b_dijet1.
	Manager()->FillHisto("DR_b_dijet1", ((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum())));
      	plot_DR_b_dijet1->Fill((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum()));
	
	//DIJET1 *************************************************************************************************************************************************************************************
  	//plots of the dijet1 pairs that are not merged.
  	if(notMerged[0]){
  		//fils PT_dijet1_not.
		Manager()->FillHisto("PT_dijet1_not", dijet1.Pt());
        	plot_PT_dijet1_not->Fill(dijet1.Pt());
        	
        	//fils ETA_dijet1_not.
		Manager()->FillHisto("ETA_dijet1_not", dijet1.Eta());
        	plot_ETA_dijet1_not->Fill(dijet1.Eta());
        	
        	//fils M_dijet1_not.
		Manager()->FillHisto("M_dijet1_not", dijet1.M());
        	plot_M_dijet1_not->Fill(dijet1.M());
        	
        	//fils PHI_dijet1_not.
		Manager()->FillHisto("PHI_dijet1_not", dijet1.Phi());
        	plot_PHI_dijet1_not->Fill(dijet1.Phi());
        	
        	//fils DR_dijet1_not.
		Manager()->FillHisto("DR_dijet1_not", (FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
        	plot_DR_dijet1_not->Fill((FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
  	}
 
	//plots of the dijet1 pairs that are partially merged.
  	if(partiallyMerged[0]){
  		//fils PT_dijet1_partially.
		Manager()->FillHisto("PT_dijet1_partially", dijet1.Pt());
        	plot_PT_dijet1_partially->Fill(dijet1.Pt());
        	
        	//fils ETA_dijet1_partially.
		Manager()->FillHisto("ETA_dijet1_partially", dijet1.Eta());
        	plot_ETA_dijet1_partially->Fill(dijet1.Eta());
        	
        	//fils M_dijet1_partially.
		Manager()->FillHisto("M_dijet1_partially", dijet1.M());
        	plot_M_dijet1_partially->Fill(dijet1.M());
        	
        	//fils PHI_dijet1_partially.
		Manager()->FillHisto("PHI_dijet1_partially", dijet1.Phi());
        	plot_PHI_dijet1_partially->Fill(dijet1.Phi());
        	
        	//fils DR_dijet1_partially.
		Manager()->FillHisto("DR_dijet1_partially", (FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
        	plot_DR_dijet1_partially->Fill((FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
  	}
  
	//plots of the dijet1 pairs that are fully merged.
  	if(fullyMerged[0]){
  		//fils PT_dijet1_fully.
		Manager()->FillHisto("PT_dijet1_fully", dijet1.Pt());
        	plot_PT_dijet1_fully->Fill(dijet1.Pt());
        	
        	//fils ETA_dijet1_fully.
		Manager()->FillHisto("ETA_dijet1_fully", dijet1.Eta());
        	plot_ETA_dijet1_fully->Fill(dijet1.Eta());
        	
        	//fils M_dijet1_fully.
		Manager()->FillHisto("M_dijet1_fully", dijet1.M());
        	plot_M_dijet1_fully->Fill(dijet1.M());
        	
        	//fils PHI_dijet1_fully.
		Manager()->FillHisto("PHI_dijet1_fully", dijet1.Phi());
        	plot_PHI_dijet1_fully->Fill(dijet1.Phi());
        	
        	//fils DR_dijet1_fully.
		Manager()->FillHisto("DR_dijet1_fully", (FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
        	plot_DR_dijet1_fully->Fill((FinalStateJs[index_j1]->momentum()).DeltaR(FinalStateJs[index_j2]->momentum()));
  	}

  	//B_DIJET1 ***********************************************************************************************************************************************************************************
	//plots of the b_dijet1 pairs that are partially merged.
  	if(partiallyMerged[0]){
  		//fils PT_b_dijet1_partially.
		Manager()->FillHisto("PT_b_dijet1_partially", b_dijet1.Pt());
        	plot_PT_b_dijet1_partially->Fill(b_dijet1.Pt());
        	
        	//fils ETA_b_dijet1_partially.
		Manager()->FillHisto("ETA_b_dijet1_partially", b_dijet1.Eta());
        	plot_ETA_b_dijet1_partially->Fill(b_dijet1.Eta());
        	
        	//fils M_b_dijet1_partially.
		Manager()->FillHisto("M_b_dijet1_partially", b_dijet1.M());
        	plot_M_b_dijet1_partially->Fill(b_dijet1.M());
        	
        	//fils PHI_b_dijet1_partially.
		Manager()->FillHisto("PHI_b_dijet1_partially", b_dijet1.Phi());
        	plot_PHI_b_dijet1_partially->Fill(b_dijet1.Phi());
        	
        	//fils DR_b_dijet1_partially.
		Manager()->FillHisto("DR_b_dijet1_partially", ((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum())));
        	plot_DR_b_dijet1_partially->Fill((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum()));
  	}
  
	//plots of the b_dijet1 pairs that are fully merged.
  	if(fullyMerged[0]){
  		//fils PT_b_dijet1_fully.
		Manager()->FillHisto("PT_b_dijet1_fully", b_dijet1.Pt());
        	plot_PT_b_dijet1_fully->Fill(b_dijet1.Pt());
        	
        	//fils ETA_b_dijet1_fully.
		Manager()->FillHisto("ETA_b_dijet1_fully", b_dijet1.Eta());
        	plot_ETA_b_dijet1_fully->Fill(b_dijet1.Eta());
        	
        	//fils M_b_dijet1_fully.
		Manager()->FillHisto("M_b_dijet1_fully", b_dijet1.M());
        	plot_M_b_dijet1_fully->Fill(b_dijet1.M());
        	
        	//fils PHI_b_dijet1_fully.
		Manager()->FillHisto("PHI_b_dijet1_fully", b_dijet1.Phi());
        	plot_PHI_b_dijet1_fully->Fill(b_dijet1.Phi());
        	
        	//fils DR_b_dijet1_fully.
		Manager()->FillHisto("DR_b_dijet1_fully", ((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum())));
        	plot_DR_b_dijet1_fully->Fill((FinalStateJs[index_j1]->momentum() + FinalStateJs[index_j2]->momentum()).DeltaR(FinalStateBs[index_b1]->momentum()));
  	}
  	
  	//PLOTS OF THE THE TWO B**********************************************************************************************************************************************************************
 	//plots of b1.
 	
	//fills PT_b1.
	Manager()->FillHisto("PT_b1", (FinalStateBs[index_b1]->momentum()).Pt());
	plot_PT_b1->Fill((FinalStateBs[index_b1]->momentum()).Pt());
        
	//fills ETA_b1.
	Manager()->FillHisto("ETA_b1", (FinalStateBs[index_b1]->momentum()).Eta());
	plot_ETA_b1->Fill((FinalStateBs[index_b1]->momentum()).Eta());
        
        //fills PHI_b1.
	Manager()->FillHisto("PHI_b1", (FinalStateBs[index_b1]->momentum()).Phi());
	plot_PHI_b1->Fill((FinalStateBs[index_b1]->momentum()).Phi());
        
 	//plots of b2.
 	
 	//fills PT_b2.
	Manager()->FillHisto("PT_b2", (FinalStateBs[index_b2]->momentum()).Pt());
	plot_PT_b2->Fill((FinalStateBs[index_b2]->momentum()).Pt());
        
        //fills ETA_b2.
	Manager()->FillHisto("ETA_b2", (FinalStateBs[index_b2]->momentum()).Eta());
	plot_ETA_b2->Fill((FinalStateBs[index_b2]->momentum()).Eta());
        
        //fills PHI_b2.
	Manager()->FillHisto("PHI_b2", (FinalStateBs[index_b2]->momentum()).Phi());
	plot_PHI_b2->Fill((FinalStateBs[index_b2]->momentum()).Phi());
	  	
	  	
	
	
	
	//PLOTS OF THE SECOND PAIR OF DIJET AND B_DIJET **********************************************************************************************************************************************
	//ONLY USED IN THE FULLY HADRONIC CHANNEL ****************************************************************************************************************************************************
  	if (FinalStateJs.size() == 4){
  	
	  	//general plots
	  	
		//fills N_merged2.
		if(notMerged[1])
		{
			Manager()->FillHisto("N_Merged2", 1);
			plot_N_Merged2->Fill(1);
		}
	
		if(partiallyMerged[1])
		{
			Manager()->FillHisto("N_Merged2", 2);
			plot_N_Merged2->Fill(2);
		}
	
		if(fullyMerged[1])
		{
			Manager()->FillHisto("N_Merged2", 3);
			plot_N_Merged2->Fill(3);
		}
		
		//fills Smallest_DR_dijet.
		if (smallestdr[0] == true){
			Manager()->FillHisto("Smallest_DR_dijet", 1);
			plot_Smallest_DR_dijet->Fill(1);
		}
		if (smallestdr[0] == false){
			Manager()->FillHisto("Smallest_DR_dijet", 2);
			plot_Smallest_DR_dijet->Fill(2);
		}
	
		//fills Smallest_DR_b_dijet.
		if (smallestdr[1] == true){
			Manager()->FillHisto("Smallest_DR_b_dijet", 1);
			plot_Smallest_DR_b_dijet->Fill(1);
		}
		if (smallestdr[1] == false){
			Manager()->FillHisto("Smallest_DR_b_dijet", 2);
			plot_Smallest_DR_b_dijet->Fill(2);
		}
		
		//fils Pairs.
		if (index_j2 == 1){
			Manager()->FillHisto("Pairs", 1);
			plot_Pairs->Fill(1);
		}
		
		if (index_j2 == 2){
			Manager()->FillHisto("Pairs", 2);
			plot_Pairs->Fill(2);
		}
		
		if (index_j2 == 3){
			Manager()->FillHisto("Pairs", 3);
			plot_Pairs->Fill(3);
		}
		
		//fills Pairs_b.
        	if (index_j2 == 1){
        		if (index_b1 == 0){
				Manager()->FillHisto("Pairs_b", 1);
				plot_Pairs_b->Fill(1);
			}
			if (index_b1 == 1){
				Manager()->FillHisto("Pairs_b", 2);
				plot_Pairs_b->Fill(2);
			}
		}
			
		if (index_j2 == 2){
        		if (index_b1 == 0){
				Manager()->FillHisto("Pairs_b", 3);
				plot_Pairs_b->Fill(3);
			}
			if (index_b1 == 1){
				Manager()->FillHisto("Pairs_b", 4);
				plot_Pairs_b->Fill(4);
			}
		}
		
		if (index_j2 == 3){
			if (index_b1 == 0){
				Manager()->FillHisto("Pairs_b", 5);
				plot_Pairs_b->Fill(5);
			}
			if (index_b1 == 1){
				Manager()->FillHisto("Pairs_b", 6);
				plot_Pairs_b->Fill(6);
			}
		}
		
		//fills Mother_Particles_dijets
		if (((FinalStateJs[index_j1]->mothers()) == (FinalStateJs[index_j2]->mothers())) && ((FinalStateJs[index_j3]->mothers()) == (FinalStateJs[index_j4]->mothers()))){
		
			Manager()->FillHisto("Mother_Particles_dijets",1);
			plot_Mother_Particles_dijets->Fill(1);
		}
		
		if (((FinalStateJs[index_j1]->mothers()) != (FinalStateJs[index_j2]->mothers())) || ((FinalStateJs[index_j3]->mothers()) != (FinalStateJs[index_j4]->mothers()))){
		
			Manager()->FillHisto("Mother_Particles_dijets",2);
			plot_Mother_Particles_dijets->Fill(2);
		}
		
		/*
		if (((FinalStateJs[index_j1]->mothers()) == (FinalStateJs[index_j3]->mothers())) || ((FinalStateJs[index_j1]->mothers()) == (FinalStateJs[index_j4]->mothers())) || ((FinalStateJs[index_j2]->mothers()) == (FinalStateJs[index_j3]->mothers())) || ((FinalStateJs[index_j2]->mothers()) == (FinalStateJs[index_j4]->mothers()))){
			std::cout << "PARES MAL" << std::endl;
		}
		
		if (Charge(FinalStateJs[index_j1]) + Charge(FinalStateJs[index_j2]) == Charge(FinalStateJs[index_j3]) + Charge(FinalStateJs[index_j4])){
			std::cout << "CARGAS MAL" << std::endl;
		}
		*/
  	
		//general plots dijet2
		
		//fils PT_dijet2.
		Manager()->FillHisto("PT_dijet2", dijet2.Pt());
        	plot_PT_dijet2->Fill(dijet2.Pt());
	
		//fils ETA_dijet2.
		Manager()->FillHisto("ETA_dijet2", dijet2.Eta());
        	plot_ETA_dijet2->Fill(dijet2.Eta());
	
		//fils M_dijet2.
		Manager()->FillHisto("M_dijet2", dijet2.M());
        	plot_M_dijet2->Fill(dijet2.M());
        	
		//fils PHI_dijet2.
		Manager()->FillHisto("PHI_dijet2", dijet2.Phi());
        	plot_PHI_dijet2->Fill(dijet2.Phi());
        	
		//fils DR_dijet2.
		Manager()->FillHisto("DR_dijet2", (FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
        	plot_DR_dijet2->Fill((FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
        	
        	//PLOTS DE LOS DELTA ETA, PHI Y PT PARA LOS PARES DE DIJET ESCOGIDOS Y LOS QUE NO.
		for (MAuint32 i = 0; i < FinalStateJs.size(); i++){
  			for (MAuint32 j = i + 1; j < FinalStateJs.size(); j++){
  	
  				if (((i == index_j1) || (i == index_j2)) && ((j == index_j1) || (j == index_j2))){
  				
  					Manager()->FillHisto("dETA_dijet1", (FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
        				plot_dETA_dijet1->Fill((FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
  					
  					Manager()->FillHisto("dPHI_dijet1", (FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        				plot_dPHI_dijet1->Fill((FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        				
        				Manager()->FillHisto("dDR_dijet1", ((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum())));
        				plot_dDR_dijet1->Fill((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum()));
  				}
  				
  				if (((i == index_j3) || (i == index_j4)) && ((j == index_j3) || (j == index_j4))){
  				
  					Manager()->FillHisto("dETA_dijet2", (FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
        				plot_dETA_dijet2->Fill((FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
  					
  					Manager()->FillHisto("dPHI_dijet2", (FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        				plot_dPHI_dijet2->Fill((FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        				
        				Manager()->FillHisto("dDR_dijet2", ((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum())));
        				plot_dDR_dijet2->Fill((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum()));
  				}
  				
  				if ((!(((i == index_j1) || (i == index_j2)) && ((j == index_j1) || (j == index_j2)))) && (!(((i == index_j3) || (i == index_j4)) && ((j == index_j3) || (j == index_j4))))){
  				
  					if ((i == 0) && (j == 1)){
  						
  						Manager()->FillHisto("dETA_pair12", (FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
        					plot_dETA_pair12->Fill((FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
  						
  						Manager()->FillHisto("dPHI_pair12", (FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        					plot_dPHI_pair12->Fill((FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        					
        					Manager()->FillHisto("dDR_pair12", ((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum())));
        					plot_dDR_pair12->Fill((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum()));
  					}
  				
  					if ((i == 0) && (j == 2)){
  				
  						Manager()->FillHisto("dETA_pair13", (FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
        					plot_dETA_pair13->Fill((FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
  						
  						Manager()->FillHisto("dPHI_pair13", (FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        					plot_dPHI_pair13->Fill((FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        					
        					Manager()->FillHisto("dDR_pair13", ((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum())));
        					plot_dDR_pair13->Fill((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum()));
  					}
  				
  					if ((i == 0) && (j == 3)){
  					
  						Manager()->FillHisto("dETA_pair14", (FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
        					plot_dETA_pair14->Fill((FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
  						
  						Manager()->FillHisto("dPHI_pair14", (FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        					plot_dPHI_pair14->Fill((FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        					
        					Manager()->FillHisto("dDR_pair14", ((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum())));
        					plot_dDR_pair14->Fill((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum()));
  					}
  				
  					if ((i == 1) && (j == 2)){
  					
  						Manager()->FillHisto("dETA_pair23", (FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
        					plot_dETA_pair23->Fill((FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
  						
  						Manager()->FillHisto("dPHI_pair23", (FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        					plot_dPHI_pair23->Fill((FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        					
        					Manager()->FillHisto("dDR_pair23", ((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum())));
        					plot_dDR_pair23->Fill((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum()));
  					}
  				
  					if ((i == 1) && (j == 3)){
  					
  						Manager()->FillHisto("dETA_pair24", (FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
        					plot_dETA_pair24->Fill((FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
  						
  						Manager()->FillHisto("dPHI_pair24", (FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        					plot_dPHI_pair24->Fill((FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        					
        					Manager()->FillHisto("dDR_pair24", ((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum())));
        					plot_dDR_pair24->Fill((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum()));
  					}
  				
  					if ((i == 2) && (j == 3)){
  					
  						Manager()->FillHisto("dETA_pair34", (FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
        					plot_dETA_pair34->Fill((FinalStateJs[i]->momentum().Eta()) - (FinalStateJs[j]->momentum().Eta()));
  						
  						Manager()->FillHisto("dPHI_pair34", (FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        					plot_dPHI_pair34->Fill((FinalStateJs[i]->momentum().Phi()) - (FinalStateJs[j]->momentum().Phi()));
        					
        					Manager()->FillHisto("dDR_pair34", ((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum())));
        					plot_dDR_pair34->Fill((FinalStateJs[i]->momentum()).DeltaR(FinalStateJs[j]->momentum()));
  					}
  				}
  			}
  		}
		
		//general plots b_dijet2
		
		//fils PT_b_dijet2.
		Manager()->FillHisto("PT_b_dijet2", b_dijet2.Pt());
        	plot_PT_b_dijet2->Fill(b_dijet2.Pt());
			
		//fils ETA_b_dijet2.
		Manager()->FillHisto("ETA_b_dijet2", b_dijet2.Eta());
        	plot_ETA_b_dijet2->Fill(b_dijet2.Eta());
		
		//fils M_b_dijet2.
		Manager()->FillHisto("M_b_dijet2", b_dijet2.M());
        	plot_M_b_dijet2->Fill(b_dijet2.M());
        	
		//fils PHI_b_dijet2.
		Manager()->FillHisto("PHI_b_dijet2", b_dijet2.Phi());
        	plot_PHI_b_dijet2->Fill(b_dijet2.Phi());
        	
		//fils DR_b_dijet2.
		Manager()->FillHisto("DR_b_dijet2", ((FinalStateJs[index_j3]->momentum() + FinalStateJs[index_j4]->momentum()).DeltaR(FinalStateBs[index_b2]->momentum())));
        	plot_DR_b_dijet2->Fill((FinalStateJs[index_j3]->momentum() + FinalStateJs[index_j4]->momentum()).DeltaR(FinalStateBs[index_b2]->momentum()));
		
		//DIJET2 ******************************************************************************************************************************************************************************
  		//plots of the dijet2 pairs that are not merged.
  		if(notMerged[1]){
  			//fils PT_dijet2_not.
			Manager()->FillHisto("PT_dijet2_not", dijet2.Pt());
        		plot_PT_dijet2_not->Fill(dijet2.Pt());
        		
        		//fils ETA_dijet2_not.
			Manager()->FillHisto("ETA_dijet2_not", dijet2.Eta());
        		plot_ETA_dijet2_not->Fill(dijet2.Eta());
        		
        		//fils M_dijet2_not.
			Manager()->FillHisto("M_dijet2_not", dijet2.M());
        		plot_M_dijet2_not->Fill(dijet2.M());
        		
        		//fils PHI_dijet2_not.
			Manager()->FillHisto("PHI_dijet2_not", dijet2.Phi());
        		plot_PHI_dijet2_not->Fill(dijet2.Phi());
        		
        		//fils DR_dijet2_not.
			Manager()->FillHisto("DR_dijet2_not", (FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
        		plot_DR_dijet2_not->Fill((FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
  		}
 	
		//plots of the dijet2 pairs that are partially merged.
	  	if(partiallyMerged[1]){
	  		//fils PT_dijet2_partially.
			Manager()->FillHisto("PT_dijet2_partially", dijet2.Pt());
        		plot_PT_dijet2_partially->Fill(dijet2.Pt());
        		
        		//fils ETA_dijet2_partially.
			Manager()->FillHisto("ETA_dijet2_partially", dijet2.Eta());
        		plot_ETA_dijet2_partially->Fill(dijet2.Eta());
        		
        		//fils M_dijet2_partially.
			Manager()->FillHisto("M_dijet2_partially", dijet2.M());
        		plot_M_dijet2_partially->Fill(dijet2.M());
        		
        		//fils PHI_dijet2_partially.
			Manager()->FillHisto("PHI_dijet2_partially", dijet2.Phi());
        		plot_PHI_dijet2_partially->Fill(dijet2.Phi());
        		
        		//fils DR_dijet2_partially.
			Manager()->FillHisto("DR_dijet2_partially", (FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
        		plot_DR_dijet2_partially->Fill((FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
  		}
  	
		//plots of the dijet2 pairs that are fully merged.
  		if(fullyMerged[1]){
  			//fils PT_dijet2_fully.
			Manager()->FillHisto("PT_dijet2_fully", dijet2.Pt());
        		plot_PT_dijet2_fully->Fill(dijet2.Pt());
        		
        		//fils ETA_dijet2_fully.
			Manager()->FillHisto("ETA_dijet2_fully", dijet2.Eta());
        		plot_ETA_dijet2_fully->Fill(dijet2.Eta());
        		
        		//fils M_dijet2_fully.
			Manager()->FillHisto("M_dijet2_fully", dijet2.M());
        		plot_M_dijet2_fully->Fill(dijet2.M());
        		
        		//fils PHI_dijet2_fully.
			Manager()->FillHisto("PHI_dijet2_fully", dijet2.Phi());
        		plot_PHI_dijet2_fully->Fill(dijet2.Phi());
        		
        		//fils DR_dijet2_fully.
			Manager()->FillHisto("DR_dijet2_fully", (FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
        		plot_DR_dijet2_fully->Fill((FinalStateJs[index_j3]->momentum()).DeltaR(FinalStateJs[index_j4]->momentum()));
  		}
	
	  	//B_DIJET2 ****************************************************************************************************************************************************************************
		//plots of the b_dijet2 pairs that are partially merged.
	  	if(partiallyMerged[1]){
  			//fils PT_b_dijet2_partially.
			Manager()->FillHisto("PT_b_dijet2_partially", b_dijet2.Pt());
        		plot_PT_b_dijet2_partially->Fill(b_dijet2.Pt());
        		
        		//fils ETA_b_dijet2_partially.
			Manager()->FillHisto("ETA_b_dijet2_partially", b_dijet2.Eta());
        		plot_ETA_b_dijet2_partially->Fill(b_dijet2.Eta());
        		
        		//fils M_b_dijet2_partially.
			Manager()->FillHisto("M_b_dijet2_partially", b_dijet2.M());
        		plot_M_b_dijet2_partially->Fill(b_dijet2.M());
        		
        		//fils PHI_b_dijet2_partially.
			Manager()->FillHisto("PHI_b_dijet2_partially", b_dijet2.Phi());
        		plot_PHI_b_dijet2_partially->Fill(b_dijet2.Phi());
        		
        		//fils DR_b_dijet2_partially.
			Manager()->FillHisto("DR_b_dijet2_partially", ((FinalStateJs[index_j3]->momentum() + FinalStateJs[index_j4]->momentum()).DeltaR(FinalStateBs[index_b2]->momentum())));
        		plot_DR_b_dijet2_partially->Fill((FinalStateJs[index_j3]->momentum() + FinalStateJs[index_j4]->momentum()).DeltaR(FinalStateBs[index_b2]->momentum()));
  		}
  	
		//plots of the b_dijet2 pairs that are fully merged.
	  	if(fullyMerged[1]){
  			//fils PT_b_dijet2_fully.
			Manager()->FillHisto("PT_b_dijet2_fully", b_dijet2.Pt());
        		plot_PT_b_dijet2_fully->Fill(b_dijet2.Pt());
        		
        		//fils ETA_b_dijet2_fully.
			Manager()->FillHisto("ETA_b_dijet2_fully", b_dijet2.Eta());
        		plot_ETA_b_dijet2_fully->Fill(b_dijet2.Eta());
        		
        		//fils M_b_dijet2_fully.
			Manager()->FillHisto("M_b_dijet2_fully", b_dijet2.M());
        		plot_M_b_dijet2_fully->Fill(b_dijet2.M());
        		
        		//fils PHI_b_dijet2_fully.
			Manager()->FillHisto("PHI_b_dijet2_fully", b_dijet2.Phi());
        		plot_PHI_b_dijet2_fully->Fill(b_dijet2.Phi());
        		
        		//fils DR_b_dijet2_fully.
			Manager()->FillHisto("DR_b_dijet2_fully", ((FinalStateJs[index_j3]->momentum() + FinalStateJs[index_j4]->momentum()).DeltaR(FinalStateBs[index_b2]->momentum())));
        		plot_DR_b_dijet2_fully->Fill((FinalStateJs[index_j3]->momentum() + FinalStateJs[index_j4]->momentum()).DeltaR(FinalStateBs[index_b2]->momentum()));
  		}
  	}
  	
  	}
  	
  	if (index_j2 == 0){
  	
  		//fills FoundPair.
  		Manager()->FillHisto("FoundPair",2);
		plot_FoundPair->Fill(2);
  	}



  return true;
}

