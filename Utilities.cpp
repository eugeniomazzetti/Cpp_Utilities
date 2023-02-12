//This source code file contains utilities function and classes
//Creator: Eugenio Mazzetti

//INCLUSION --------------------------------------------------------------------------------------------------------------
#include <cmath>
#include <algorithm>
#include <iostream>

#include "Utilities.h" //Best practice

// Floating Point Numbers Comparison -------------------------------------------------------------------------------------

// This function compares two floating point numbers. Given their imprecise nature the function use "epsilon" to understand
// if they are “close enough”. If they are then they are considered to be equal.

bool approxEqualAbsRel(double x, double y, double absEpsilon, double relEpsilon)
{
	// (1) Check if floats are close in absolute value: Necessary when comparing numbers near zero
	double diff{ std::abs(x - y) };

	// (2) If they are close enough return true
	if (diff <= absEpsilon)
		return true;

	// (3) Otherwise use Knuth's algo that considers numbers relative magnitude
	return (diff <= (std::max(std::abs(x), std::abs(y)) * relEpsilon));

}

