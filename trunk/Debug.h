/**
 * Utility debugging functions.
 * 
 * @author Francis BISSON
 */

#ifndef DEBUG_H
#define DEBUG_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Utility.h"

// MACRO DEFINITIONS ///////////////////////////////////////////////////////////

#ifdef NDEBUG
#	define DEBUG_ASSERT(cond) UNUSED((cond))
#	define DEBUG_ASSERT2(cond, msg) UNUSED((cond))
#	define TRACE(msg)
#else
#	include <iostream>
#	define DEBUG_ASSERT(cond) Debug::Assert2(cond, #cond, __FILE__, __LINE__)
#	define DEBUG_ASSERT2(cond, msg) Debug::Assert2(cond, msg, __FILE__, __LINE__)
#	define TRACE(msg) (std::cout << msg << std::endl)

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Debug
{
private:
	Debug();
	~Debug();

public:
	static void	Assert(bool condition, const char* file, int line);
	static void Assert2(bool condition, std::string message, const char* file, int line);
};
#endif

#endif // DEBUG_H
