#include <stdio.h>
#include <stdlib.h>
// you do not have to include pe02_aux.h here because you are not 
// calling the function function_to_be_integrated here
#include "answer02.h"

// fill in the correct statements to complete the main function
// we expect four arguments:
//
// the first argument is two characters from the sets {"-m", "-t"}
// -m: run mid_point_numerical_integration
// -t: run trapezoidal_numerical_integration
// otherwise: return EXIT_FAILURE
      
// to run any of the two functions, expect the next three arguments
// to be the lower limit of the integration (double), the upper limit
// of the integration (double), and the number of intervals for the
// integration (int)
//
// if the number of intervals is less than 1, set it to 1

// use atof to convert an argument to a double 
// use atoi to convert an argument to an int

// after you have numerically integrated the function, print the 
// return value, and return EXIT_SUCCESS
//
int compare_string(char *);

int main(int argc, char * * argv)
{
  double integral = 0.0; 
  
  //this if makes sure that the user inputs the exact amount of variables needed
  
  if(argc != 5)
   {
     printf("need more / less input\n");
     return EXIT_FAILURE;
   }
  
   
  //converting the input into workable integers
   
  int intervals = atoi(argv[4]);
  int lower_lim = atoi(argv[2]);
  int higher_lim = atoi(argv[3]);
 

  if(intervals<1)
     intervals = 1;

   //custom comapring string
   if(compare_string(argv[1]) == 0){
      return EXIT_FAILURE;
   }
   else if(compare_string(argv[1]) == 1){
     integral = mid_point_numerical_integration(lower_lim,higher_lim,intervals);
   }
   else if(compare_string(argv[1]) == 2){
     integral = trapezoidal_numerical_integration(lower_lim,higher_lim,intervals);
   }

   printf("%.10e\n", integral);
   return EXIT_SUCCESS;
}
