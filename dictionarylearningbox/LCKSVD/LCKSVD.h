#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "config.h" 

#ifndef LCKSVD_H 
#define LCKSVD_H 



struct LCKSVDParameters{
   int iterations ;
	int nAtoms ;               //number of atoms of dictionary 
   int featureSize ;          //number of rows of dictionary
	int trainSize ;  
   int debug ;
	int sparsityThres;
	float sqrtAlpha; 
	float sqrtBeta ;
	int nClass ; 
};

//*********************************************************
// Initialize matrixes for LCKSVD 
// *****************************************************
void LCKSVD_initialize(
	std::vector<float> &DInit, 		// Output, initialized dictionary 
	std::vector<float> &TInit, 		// Output, initialized linear transform matrix
	std::vector<float> &WInit, 		// Output, initialized classfifier parameters 
	std::vector<float> &Q,				// Output, optimal code matrix for training features
	std::vector<float> trainingFeats, // Input, training features 
	std::vector<float> labelTrain, 	// Input, label of training features 
    LCKSVDParameters param
	
); 


#endif 
