// Header Guard ----------------------------------------------------------------------------------------------------------
#ifndef UTILITIES_H
#define UTILITIES_H

// Namespace -------------------------------------------------------------------------------------------------------------

namespace personal_utilities
{
	// Forward Declarations ----------------------------------------------------------------------------------------------

	// Floating Point Numbers Comparison 
	bool approxEqualAbsRel(double x, double y, double absEpsilon = 1e-12, double relEpsilon = 1e-8);

	// Two to the Power Bitwise Operation
	std::uint64_t power_two_bitwise(std::uint64_t exponent);

	// Standard Normal CDF
	double normalCdf(double x);
}

#endif // !UTILITIES_H
