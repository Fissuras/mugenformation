/**
 * Implementation of the Debug class.
 * Note that this code should not be compiled if not in "Debug" mode.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>

#include "Debug.h"

#ifndef NDEBUG

// IMPLEMENTATION //////////////////////////////////////////////////////////////
void Debug::Assert(bool condition, const char* file, int line)
{
	if(!condition)
	{
		std::cout << "FATAL ERROR (" << file << ", line " << line << ")\n";
		int* p = 0;
		*p = 1;
	}
}

void Debug::Assert2(bool condition, std::string message, const char* file, int line)
{
	if(!condition)
	{
		std::cout << "FATAL ERROR (" << file << ", line " << line << ") : " << message << "\n";
		int* p = 0;
		*p = 1;
	}
}

#endif
