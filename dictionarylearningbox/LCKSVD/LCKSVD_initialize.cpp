#include <numeric>      // std::inner_product
#include <algorithm> // for std::transform
#include <functional> 
#include <ctime>
#include <iterator>

#include "LCKSVD.h"
#include "dictionarylearningbox/kSVD/kSVD.h"
#include "config.h" 
#include "utilities/utilities.h" 
#include "sparsecodingbox/omp.h" 

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

//*********************************************************
// Initialize matrixes for LCKSVD 
// *****************************************************
void LCKSVD_initialize(
		std::vector<float> &DInit,       // Output, initialized dictionary 
		std::vector<float> &TInit,       // Output, initialized linear transform matrix
		std::vector<float> &WInit,       // Output, initialized classfifier parameters 
		std::vector<float> &Q,            // Output, optimal code matrix for training features
		std::vector<float> trainingFeats, // Input, training features 
		std::vector<float> labelTrain,    // Input, label of training features i
		LCKSVDParameters param ){

	//Train seperate dictionary for each class 
	int nAtomsEachClass = 15 ;		//total 32 samples each class
	for(int classId = 0 ; classId < 	param.nClass ; classId++){

		std::cout <<"class id = " << classId <<"/" << param.nClass << std::endl ;
		//get each class data
		std::vector<float> data; 
		for(int dataId = 0 ; dataId < param.trainSize ; dataId++){
			if(labelTrain[dataId*param.nClass + classId] ==1)
				data.insert(data.end(),trainingFeats.begin() + dataId*param.featureSize,
						trainingFeats.begin() + (dataId + 1)*param.featureSize);
		}
		//get dictionary for each class 
		std::vector<float> Dpart(data.begin(),data.begin() + nAtomsEachClass*param.featureSize); 
		
		//normalize dictionary 
		Dpart = normalize_matrix_norml2(Dpart,param.featureSize,nAtomsEachClass); 
		//Set KSVD parameters
		kSVDParameters kSVDParam; 
		kSVDParam.iterations = param.iterations; 
		kSVDParam.nAtoms = nAtomsEachClass; 
		kSVDParam.featureSize = param.featureSize ; 
		kSVDParam.sparsityThres = 5 ;

		//run kSVD 
		std::vector<float> sparseCode; 
		kSVD(sparseCode,Dpart,data,kSVDParam);

	}


	//


}


