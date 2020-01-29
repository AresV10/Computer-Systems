#include "challenge.h"

//
// Returns degrees C for given degrees F
//   param F: temperature in degrees Fahrenheit
//   return: temperature in degrees Celsius
//
//  TODO:
//   1. Return the conversion from degrees Fahrenheit to Celsius
//
float convert(float F)
{
float C = 0;
  C = (F-32)*5/9;
  return C;
}