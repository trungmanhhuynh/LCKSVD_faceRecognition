#include <iostream>
#include <iomanip>
#include <iterator>
//opecv libs
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

//local libs
#include "dictionarylearningbox/kSVD/kSVD.h"
#include "sparsecodingbox/omp.h"
#include "config.h"
#include "utilities/utilities.h"


int main(int argc, char** argv){

	std::vector<float> trainingFeats = csvread("../data/training_feats.dat"); 
	std::vector<float> testingFeats = csvread("../data/testing_feats.dat"); 
   std::vector<float> labelTrain = csvread("../data/H_train.dat"); 
   std::vector<float> labelTest = csvread("../data/H_test.dat"); 

	
	//std::cout << "training data = " << std::endl ;
   //copy(trainingFeats.begin(), trainingFeats.begin() + 100, std::ostream_iterator<float>(std::cout, " ")); std::cout << std::endl;

	std::cout << "label train = " << std::endl ;
   copy(labelTrain.begin(), labelTrain.begin() + 100, std::ostream_iterator<float>(std::cout, " ")); std::cout << std::endl;


}
