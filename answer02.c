#include "answer02.h"
#include "pe02_aux.h"
#include <stdio.h>
// the function performs numerical integration of the function
// double function_to_be_integrated(double) over the 
// range lower_limit to upper_limit using the mid-point rule
//
// The range is divided into n_intervals uniform intervals, where the
// left-most interval has a left boundary of lower_limit and the 
// right-most interval has a right boundary of upper_limit (assuming 
// lower_limit <= upper_limit).  
// If lower_limit >= upper_limit, the right-most interval has a right 
// boundary of lower_limit and the left-most interval has a left boundary
// of upper_limit.
// 
// The mid-point rule is used to perform the integration for each interval.
// In the mid-point rule, the integration is approximated by using the
// area of a rectangle, where the height of the rectange is obtained by
// function_to_be_integrated(mid-point of the interval).  The width of
// the rectangle is (interval boundary closer to upper_limit - interval
// boundary closer to lower_limit).  Note that width could be negative
// if upper_limit < lower_limit
//
// The integral is the sum of the integration over all intervals
//
// The caller function has to make sure that n_intervals >= 1
// Therefore, this function may assume that n_intervals >= 1
//
double mid_point_numerical_integration(double lower_limit, double upper_limit, int n_intervals)
{
  double integral = 0.0;
  double dx = 0; //small increment
  int negative_integral = 1; //this will be converted to -1 if we switch the boundaries
  int step = 0;
  double avg_hight = 0;
  double current_hight = 0;
  //check if the liimits are correct
  if(lower_limit > upper_limit){
    int help = 0;
    help = lower_limit;
    lower_limit = upper_limit;
    upper_limit = help;
    negative_integral = -1; 
  }
  current_hight = lower_limit;
  dx = (upper_limit - lower_limit) / n_intervals; 
    
  printf("%lf d\n", function_to_be_integrated(4));
  for(step = 0; step <= n_intervals; step++){
    avg_hight = function_to_be_integrated(current_hight+dx/2);
    printf("%lf \n", avg_hight);
    integral += dx * avg_hight;
    current_hight += dx;
    step++;
  }

  return ((double)negative_integral*integral);
}

// the function performs numerical integration of the function
// double function_to_be_integrated(double) over the 
// range lower_limit to upper_limit using the trapezoidal rule
//
// The range is divided into n_intervals uniform intervals, where the
// left-most interval has a left boundary of lower_limit and the 
// right-most interval has a right boundary of upper_limit (assuming 
// lower_limit <= upper_limit).  
// If lower_limit >= upper_limit, the right-most interval has a right 
// boundary of lower_limit and the left-most interval has a left boundary
// of upper_limit.
// 
// The trapezoidal rule is used to perform the integration for each interval.
// In the trapezoidal rule, the integration is approximated by the area of 
// a trapezoid, where the heights of the parallel boundaries of the trapezoid
// are obtained by 
// function_to_be_integrated(left boundary of the interval) and 
// function_to_be_integrated(right boundary of the interval).  
// The width of the trapezoid is (interval boundary closer to upper_limit - 
// interval boundary closer to lower_limit).  Note that width could be negative
// if upper_limit < lower_limit
// the area of a trapezoid is the average of the two heights multiplied by
// the width
//
// The integral is the sum of the integration over all intervals
//
// The caller function has to make sure that n_intervals >= 1
// Therefore, this function may assume that n_intervals >= 1
//
double trapezoidal_numerical_integration(double lower_limit, double upper_limit, int n_intervals)
{
  double integral = 0.0;
  double dx = 0; //small increment
  int negative_integral = 1; //this will be converted to -1 if we switch the boundaries
  //check if the liimits are correct
  if(lower_limit > upper_limit){
    int help = 0;
    help = lower_limit;
    lower_limit = upper_limit;
    upper_limit = help;
    negative_integral = -1; 
  }
  
  dx = (upper_limit - lower_limit) / n_intervals; 

  return ((double)negative_integral*integral);
}

int compare_string(char input[])
{
  int match = 0;
  char mid[] = "-m";
  char tra[] = "-t";
  int ch = 0;
  for(ch = 0; mid[ch] != '\0'; ch++){
    if(input[ch]==mid[ch]){
      match = 1;
    }
    else{
      match = 0;
      mid[ch+1] = '\0';
    }
    if(mid[ch+1] == '\0' && input[ch+1] != '\0')
      match = 0;
      
    }
  if(match == 1)
    return match;
  for(ch = 0; tra[ch] != '\0'; ch++){
    if(input[ch]==tra[ch]){
      match = 2;
    }
    else{
      match = 0;
      input[ch+1] = '\0';
    }
    if(mid[ch+1] == '\0' && input[ch+1] != '\0')
       match = 0;
  }
  if(match == 2)
    return match;


  return match;
}

