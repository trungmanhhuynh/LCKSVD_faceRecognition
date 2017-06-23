//system libs 
#include <iomanip>
#include <iostream>
#include <vector>             //std::vector 

//opencv libs
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#ifndef CONFIG_H 
#define CONFIG_H

#define GREEN   "\033[32m"      /* Green */
#define RED     "\033[31m"      /* Red */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */

#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */

//Changes these paramaters to make effect on results 
const int sparsityThres = 30 ; 
const float sqrtAlpha = 4; 
const float sqrtBeta = 2; 
const int dictSize = 570;
const int featureSize = 504 ;
const int trainSize = 1216; 
const int nClass = 38  ; 
const int iterations = 50 ;
const int iterations4init = 20; 


#endif

