//This source code file contains utilities functions and classes
//Creator: Eugenio Mazzetti

//INCLUSION --------------------------------------------------------------------------------------------------------------
#include <cmath>
#include <algorithm>
#include <iostream>
#include <limits>

//HEADER INCLUSION -------------------------------------------------------------------------------------------------------
#include "Utilities.h" //Best practice

//UTILITIES NAMESPACE ----------------------------------------------------------------------------------------------------

namespace personal_utilities
{

	// -------------------------------------------------------------------------------------------------------------------
	// Floating Point Numbers Comparison ---------------------------------------------------------------------------------
	// -------------------------------------------------------------------------------------------------------------------

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

	// -------------------------------------------------------------------------------------------------------------------
	// Two to the Power of Integer Exponent ------------------------------------------------------------------------------
	// -------------------------------------------------------------------------------------------------------------------

	// This function computes 2^n where n is an unsigned long long int (64bytes) using bitwise opearation: The best way to
	//  get 2^n results.

	std::uint64_t power_two_bitwise(std::uint64_t exponent)
	{
		return static_cast<std::uint64_t>(1) << exponent;

	}

	// -------------------------------------------------------------------------------------------------------------------
	// Standard Normal CFD -----------------------------------------------------------------------------------------------
	// -------------------------------------------------------------------------------------------------------------------

    double normalCdf(double x)
    {
        const double rt2pi = std::sqrt(2.0 * M_PI);

        // Handle special values of x
        if (std::isnan(x)) {
            return x;
        }
        if (std::isinf(x)) {
            return x > 0 ? 1.0 : 0.0;
        }
        if (x == 0.0) {
            return 0.5;
        }

        double z = std::abs(x);
        double y;

        // Use Chebyshev approximation for very small values of x
        if (z < 1.0) {
            double t = z * z;
            y = 0.5 + z * (0.3989422804014327 + t * (-0.050442066853686944 + t * (0.003924060675811331 + t * (-0.00017046355892079225 + t * 4.789743475538174e-6))));
        }
        // Use hybrid algorithm for moderate values of x
        else if (z < 6.0) {
            double t = 1.0 / (1.0 + 0.2316419 * z);
            y = 1.0 - 0.5 * std::exp(-0.5 * z * z) / rt2pi * t * (0.319381530 + t * (-0.356563782 + t * (1.781477937 + t * (-1.821255978 + t * 1.330274429))));
        }
        // Use Hill 1970 algorithm for large values of x
        else {
            double t = 1.0 / z;
            y = std::exp(-0.5 * z * z) / (rt2pi * z) * (0.5 * t - 0.125 * std::pow(t, 3) + 0.02734375 * std::pow(t, 5) - 0.006640625 * std::pow(t, 7) + 0.00166015625 * std::pow(t, 9) - 0.00041015625 * std::pow(t, 11) + 0.0001025390625 * std::pow(t, 13));
        }

        return std::copysign(y, x);
    }


}