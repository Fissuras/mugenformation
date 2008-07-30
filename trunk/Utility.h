/**
 * Utility functions and macros.
 * 
 * @author Francis BISSON
 */

#ifndef UTILITY_H
#define UTILITY_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <cmath>

// CONSTANTS ///////////////////////////////////////////////////////////////////
const double Pi	= 2.0 * acos(0.0);

// MACROS AND FUNCTIONS ////////////////////////////////////////////////////////
#define UNUSED(x) (void)(x)

inline double RadToDeg(double angle)
{
	return angle * (360.0 / (2.0 * Pi));
}

inline double DegToRad(double angle)
{
	return angle * ((2.0 * Pi) / 360.0);
}

#endif // UTILITY_H
