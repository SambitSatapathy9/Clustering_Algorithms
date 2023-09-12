//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Nov  2 08:01:58 2022 by ROOT version 6.12/07
// from TTree eventTree/event tree for analysis
// found on file: Input_SignalPhoton.root
//////////////////////////////////////////////////////////
///afs/hep.wisc.edu/home/ssatapathy/PHOTON/CMSSW_10_2_18/src/Photon_1/MC_QCD_Pt_170to300_58.root
#ifndef try1_h
#define try1_h
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

#include <iostream>
#include <fstream>
#include <TH2.h> // 2d histogram
#include <TH1.h> 
#include "vector"
#include <vector>
#include <TSystemFile.h>
#include <TSystemDirectory.h>
#include <TChain.h>

using namespace std;

//defining a class try1 where variables and branch are declared.

class try1 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
  
  TFile *fileName; //defining a file 
  TTree *tree;    //defining a tree
  
  // adding histograms
  TH1F *Photon_HoverE; // H/E
  TH1F *Photon_phoPFChIso;
  TH1F *Photon_phoPFNeuIso;
  TH1F *Photon_phoPFPhoIso;
  TH1F *Photon_phoEt; //photon transverse energy
  TH1F *Photon_phoEta;
  TH1F *Photon_nPho;   //number of photons
  TH1F *Photon_phohasPixelSeed;
  TH1F *Photon_phoR9;



// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           nPho;
   vector<float>   *phoE;
   vector<float>   *phoPx;
   vector<float>   *phoPy;
   vector<float>   *phoPz;
   vector<float>   *phoEt;
   vector<float>   *phoEta;
   vector<float>   *phoPhi;
   vector<float>   *phoSCE; // supercluster energy
   vector<float>   *phoSCRawE;
   vector<float>   *phoSCEta;
   vector<float>   *phoSCPhi;
   vector<float>   *phoSCEtaWidth;
   vector<float>   *phoSCPhiWidth;
   vector<int>     *phohasPixelSeed;
   vector<int>     *phoEleVeto;//remove e-
   vector<float>   *phoR9;
   vector<float>   *phoR9Full5x5;
   vector<float>   *phoHoverE;
   vector<float>   *phoPFChIso;
   vector<float>   *phoPFChWorstIso;
   vector<float>   *phoPFPhoIso;
   vector<float>   *phoPFNeuIso;

   // List of branches
   TBranch        *b_nPho;   //!
   TBranch        *b_phoE;   //!
   TBranch        *b_phoPx;   //!
   TBranch        *b_phoPy;   //!
   TBranch        *b_phoPz;   //!
   TBranch        *b_phoEt;   //!
   TBranch        *b_phoEta;   //!
   TBranch        *b_phoPhi;   //!
   TBranch        *b_phoSCE;   //! // supercluster energy
   TBranch        *b_phoSCRawE;   //!
   TBranch        *b_phoSCEta;   //!
   TBranch        *b_phoSCPhi;   //!
   TBranch        *b_phoSCEtaWidth;   //!
   TBranch        *b_phoSCPhiWidth;   //!
   TBranch        *b_phohasPixelSeed;   //!
   TBranch        *b_phoEleVeto;   //!
   TBranch        *b_phoR9;   //!
   TBranch        *b_phoR9Full5x5;   //!
   TBranch        *b_phoHoverE;   //!
   TBranch        *b_phoPFChIso;   //!
   TBranch        *b_phoPFChWorstIso;   //!
   TBranch        *b_phoPFPhoIso;   //!
   TBranch        *b_phoPFNeuIso;   //!

  //declaration of a class.
  try1(const char* file1, const char* file2);
  //virtual-> It is a base class function that can be overridden by a derived class.
  virtual ~try1(); // ~ -> destructor
  //virtual data_type function(data_type parameter)
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *tree);
   virtual void     Loop(Long64_t maxEvents,int reportEvery);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void Histograms(const char* file2); // histogram is defined in file2
};

#endif

#ifdef try1_cxx
//:: -> function call
try1::try1(const char* file1, const char* file2){
  TChain *chain = new TChain("phoJetNTupilizer/eventTree"); 
  TString path = file1; // path declared
  TSystemDirectory sourceDir("hi",path); //path name is hi
  TList* fileList = sourceDir.GetListOfFiles();
  TIter next(fileList); //iterate through all the files
  TSystemFile* fileName;
  int fileNumber = 0;
  int maxFiles = -1; // -1 (-> all)
  std::cout<<"path: " <<path<<std::endl;
  chain->Add("file:MC_QCD_Pt_170to300_88.root");
  
  //chain => if file is in that folder we dont need to add the path else we have to add the path of the file that's need to be chained.
  //chain->Add(/afs/hep.wisc.edu/home/ssatapathy/PHOTON/CMSSW_10_2_18/src/Photon_1/Output_Ntuple_Signal_70000_1.root"

  /* The Init() function is called when the selector needs to initialize a new tree or chain. Typically here the branch addresses and branch pointers of the tree will be set.
     It is normally not necessary to make changes to the generated code, but the routine can be extended by the user if needed.
    Init() will be called many times when running on PROOF(once per file to be processed).*/
  Init(chain);
  Histograms(file2); //histograms are defined in file2 here for the first time
}

  try1::~try1() //~ destructor defined 
  {
   if (!fChain) return;
   delete fChain->GetCurrentFile();
   fileName->cd(); //-> open the file
   fileName->Write();//->edit he file 
   fileName->Close(); //->close the file
}
  Int_t try1::GetEntry(Long64_t entry){
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t try1::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void try1::Init(TChain *tree){
  
   // Set object pointer
   phoE = 0;
   phoPx = 0;
   phoPy = 0;
   phoPz = 0;
   phoEt = 0;
   phoEta = 0;
   phoPhi = 0;
   phoSCE = 0;
   phoSCRawE = 0;
   phoSCEta = 0;
   phoSCPhi = 0;
   phoSCEtaWidth = 0;
   phoSCPhiWidth = 0;
   phohasPixelSeed = 0;
   phoEleVeto = 0;
   phoR9 = 0;
   phoR9Full5x5 = 0;
   phoHoverE = 0;
   phoPFChIso = 0;
   phoPFChWorstIso = 0;
   phoPFPhoIso = 0;
   phoPFNeuIso = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1); //makeclass defined 

	         //("name",leaf address,branch name)
   fChain->SetBranchAddress("nPho", &nPho, &b_nPho);
   fChain->SetBranchAddress("phoE", &phoE, &b_phoE);
   fChain->SetBranchAddress("phoPx", &phoPx, &b_phoPx);
   fChain->SetBranchAddress("phoPy", &phoPy, &b_phoPy);
   fChain->SetBranchAddress("phoPz", &phoPz, &b_phoPz);
   fChain->SetBranchAddress("phoEt", &phoEt, &b_phoEt);
   fChain->SetBranchAddress("phoEta", &phoEta, &b_phoEta);
   fChain->SetBranchAddress("phoPhi", &phoPhi, &b_phoPhi);
   fChain->SetBranchAddress("phoSCE", &phoSCE, &b_phoSCE);
   fChain->SetBranchAddress("phoSCRawE", &phoSCRawE, &b_phoSCRawE);
   fChain->SetBranchAddress("phoSCEta", &phoSCEta, &b_phoSCEta);
   fChain->SetBranchAddress("phoSCPhi", &phoSCPhi, &b_phoSCPhi);
   fChain->SetBranchAddress("phoSCEtaWidth", &phoSCEtaWidth, &b_phoSCEtaWidth);
   fChain->SetBranchAddress("phoSCPhiWidth", &phoSCPhiWidth, &b_phoSCPhiWidth);
   fChain->SetBranchAddress("phohasPixelSeed", &phohasPixelSeed, &b_phohasPixelSeed);
   fChain->SetBranchAddress("phoEleVeto", &phoEleVeto, &b_phoEleVeto);
   fChain->SetBranchAddress("phoR9", &phoR9, &b_phoR9);
   fChain->SetBranchAddress("phoR9Full5x5", &phoR9Full5x5, &b_phoR9Full5x5);
   fChain->SetBranchAddress("phoHoverE", &phoHoverE, &b_phoHoverE);
   fChain->SetBranchAddress("phoPFChIso", &phoPFChIso, &b_phoPFChIso);
   fChain->SetBranchAddress("phoPFChWorstIso", &phoPFChWorstIso, &b_phoPFChWorstIso);
   fChain->SetBranchAddress("phoPFPhoIso", &phoPFPhoIso, &b_phoPFPhoIso);
   fChain->SetBranchAddress("phoPFNeuIso", &phoPFNeuIso, &b_phoPFNeuIso);
   Notify();
}

Bool_t try1::Notify()
{
  // The Notify() function is called when a new file is opened.          This can be either for a new TTree in a TChain or when when a new TTree is started when using PROOF.

   return kTRUE;
}

void try1::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t try1::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef try1_cxx
