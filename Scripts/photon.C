#define try1_cxx
#include "try1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TH1F.h"
#include <vector>
#include "TStopwatch.h"
#include <cstring>
#include <list>
#include <TStyle.h>
using namespace std;
int main (int argc, const char* argv[])
{
  Long64_t maxEvents = atof(argv[3]); //max events is at postion 4
  //atof converts a string of numeric characters to a float value.
  if (maxEvents < -1LL) // LL increases the bits strength
    {
      std::cout<<"Please enter a valid value for maxEvents (parameter 3)."<<std::endl;
      return 1;
    }
  int reportEvery = atof(argv[4]); //after every 1000....
 
 if (reportEvery < 1)
    {
      std::cout<<"Please enter a valid value of reportEvery(parameter 4)."<<std::endl;
      return 1;
    }
  try1 t(argv[1],argv[2]); //[1]->input, [2]->output
  t.Loop(maxEvents, reportEvery);
  return 0;
}
void try1::Loop(Long64_t maxEvents, int reportEvery){
  if (fChain == 0) return;
  int nTotal = 0;
  
  Long64_t nentries = fChain->GetEntry();
  std::cout<<"Total entries: "<< nentries <<std::endl;
  Long64_t nentriesToCheck = nentries;

  if(maxEvents != -1LL && nentries > maxEvents)
    nentriesToCheck = maxEvents;
  nTotal = nentriesToCheck;

  Long64_t nbytes = 0, nb = 0;
  std::cout<<"Running over " <<nTotal<<" events. "<<std::endl;

  TStopwatch sw;
  sw.Start();

  for (Long64_t jentry = 0; jentry<nentries; jentry++)
    {
      Long64_t ientry = LoadTree(jentry);
      if(ientry<0) break;
      nb = fChain->GetEntry(jentry);
      nbytes += nb;
      Photon_nPho->Fill(nPho); // fill number of photons -> first histogram is defined here
      for(int  i= 0;i<nPho; i++)
      {
	if(phoEt->at(i) > 50 && fabs(phoSCEta->at(i)) < 1.4442) // fabs-> absolute value 

	  {
	    Photon_HoverE->Fill(phoHoverE->at(i));
	    Photon_phoPFChIso->Fill(phoPFChIso->at(i));
	    Photon_phoPFNeuIso->Fill(phoPFNeuIso->at(i));
	    Photon_phoPFPhoIso->Fill(phoPFPhoIso->at(i));
	    Photon_phoEt->Fill(phoEt->at(i));
            Photon_phoEta->Fill(phoEta->at(i));
	    Photon_phohasPixelSeed->Fill(phohasPixelSeed->at(i));
            Photon_phoR9->Fill(phoR9->at(i));
		
	  }
// std::cout<<"Running"<<std::endl; // Running wont come if we comment out this
	  }
      }
  if((nentriesToCheck-1)%reportEvery != 0)
    std::cout<<"Finished entry "<<(nentriesToCheck-1)<<" / "<<(nentriesToCheck-1)<<std::endl;
  sw.Stop();
}

void try1::Histograms(const char* file2){
  fileName = new TFile(file2,"RECREATE");
  fileName->cd();
  
  Photon_HoverE = new TH1F("Photon_HoverE","Photon_H/E ",50,0,0.2);
  Photon_phoPFChIso = new TH1F("Photon_phoPFChIso","Photon_Charged_Isolation",30,0,5);
  Photon_phoPFNeuIso = new TH1F("Photon_phoPFNeuIso","Photon_Neutral_Isolation",30,0,5);
  Photon_phoPFPhoIso = new TH1F("Photon_phoPFPhoIso","Photon_Isolation",50,0,5);
  Photon_phoEt = new TH1F("pho_Et","Photon_Et",50,30,1000);
  Photon_phoEta = new TH1F("Photon_phoEta","Photon_Eta",50,-2,2);
  Photon_phohasPixelSeed = new TH1F("Photon_phohasPixelSeed","Pixel_Seed",2,0,2);
  Photon_phoR9 = new TH1F("Photon_phoR9","R9_Ratio",30,0,1);
  Photon_nPho = new TH1F("Photon_nPho","No. of Photons",20,0,20);

}
