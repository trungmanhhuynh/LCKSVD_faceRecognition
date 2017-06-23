#include "utilities.h"
#include <fstream>
#include "config.h" 

std::vector<float> csvread(std::string fileName){

   std::string line;
   char* token ;
   char* oneline = new char[10000] ;
	std::vector<float> result ;
   std::ifstream textfile  ;
   textfile.open(fileName.c_str()) ;
   if(textfile.is_open()){
      while(getline(textfile,line)){
         oneline = strcpy(oneline,line.c_str()) ;
         token = strtok(oneline,",") ;
         result.push_back(static_cast<float>(atof(token)));                   // convert string to float and copy to array 
         int i = 1 ;
         while((token=strtok(NULL,",")) != NULL){
            result.push_back(static_cast<float>(atof(token)));                   // convert string to float and copy to array 
            i++ ;
         }
      }
      textfile.close();
   } 
   else{
      std::cout <<"Cant open detection file in file: " << __FILE__ << " line " <<__LINE__ << std::endl ;
      exit(1);
   }

   if(result.empty()){
      std::cout << "Read human detection file [" << BOLDRED << "FAILED" << RESET << "]" << std::endl;
      exit(1) ;
   }

   return result ;
}
