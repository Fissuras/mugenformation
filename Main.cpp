/**
 * Application's entry point.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Debug.h"
#include "DisplayContext.h"
#include "Game.h"
#include "Utility.h"

// ENTRY POINT /////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	UNUSED(argc);
	UNUSED(argv);
	
	Game theGame;
	theGame.Init();
	theGame.Start();

	return 0;
}
