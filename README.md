# Clustering_Algorithms
## Introduction
This repository consists of the scripts and plots for the estimation of a background in mono-photon final state using the 2017 datasets collected by the Compact Muon Solenoid (CMS) Detector at the Large Hadron Collider (LHC).

This repository describes the **clustering algorithms** to reconstruct the energy of the photon candidate, followed by the photon identification techniques. The reconstructed helical trajectories of charged particles from hits in the silicon inner tracking system are referred to as tracks.

The scripts and corresponding plots are implemented using C++, ROOT, and CMS-Software (CMSSW). These tools enable comprehensive analysis and visualization of the clustering algorithms.

## Contents
**Dataset/:** Contains the datasets used in the analysis 

**scripts/:** Contains the C++ scripts used for data processing and analysis. 

**Plots/:** Includes the generated plots and visualizations.

    Plots_Identification_Variables: Include the generated plots for different identification variables also known as "Shower-shape variables" which  are sensitive to the differences between the signal and the background.

    Plots_Isolation_Variables: Include the generated plots for different isolation variables which isolates the photon candidate from the background. 
  
    Plots_eta_npho: Include the generated plots for signal and QCD background for different transverse energy (Et) values


**README.md:** Provides an overview of the repository and instructions for running the analysis.

## Usage
To reproduce the analysis or modify the scripts, follow these steps:

1. Clone the repository:              git clone https://github.com/SambitSatapathy9/Clustering_Algorithms.git
2. Navigate to the cloned repository: cd Clustering_Algorithms/
3. Execute the analysis script:       ./scripts/photon.C
4. Explore the generated plots in the Plots/.

## Dependencies
To run the analysis, you need the following dependencies installed:

1. C++ compiler
2. ROOT data analysis framework
3. CMS-Software (CMSSW) environment

Make sure to set up these dependencies properly before running the analysis.

## Contributing
Contributions to this repository are welcome. If you encounter any issues or have suggestions for improvements, please create an issue or submit a pull request.

