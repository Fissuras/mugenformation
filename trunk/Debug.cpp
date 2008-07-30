/**
 * Implementation of the Debug class.
 * Note that this code should not be compiled if not in "Debug" mode.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <string>
#include <iostream>

#ifdef _WIN32
#include <sstream>
#include <windows.h>
#endif

#include "Debug.h"

#ifndef NDEBUG

// IMPLEMENTATION //////////////////////////////////////////////////////////////
void Debug::Assert(bool condition, const char* file, int line)
{
	if(!condition)
	{
#ifdef _WIN32
		std::stringstream msg;
		msg << "ASSERTION FAILED\n\n" << file << ", line " << line << "\n";
		
		MessageBoxA(0, msg.str().c_str(), "ASSERTION FAILED", MB_ICONERROR);
#endif
		
		std::cerr << "ASSERTION FAILED (" << file << ", line " << line << ")\n";
		
		int* p = 0;
		*p = 1;
	}
}

void Debug::Assert2(bool condition, std::string message, const char* file, int line)
{
	if(!condition)
	{
#ifdef _WIN32
		std::stringstream msg;
		msg << "ASSERTION FAILED\n\n" << file << ", line " << line << "\n";
				
		MessageBoxA(0, msg.str().c_str(), "ASSERTION FAILED", MB_ICONERROR);
#endif
		
		std::cerr << "ASSERTION FAILED (" << file << ", line " << line << ") : " << message << "\n";
		
		int* p = 0;
		*p = 1;
	}
}

#endif
