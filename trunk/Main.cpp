/**
 * Application's entry point.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <cstdlib>

#include "Debug.h"
#include "DisplayContext.h"
#include "Game.h"

// ENTRY POINT /////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;
	
	Game theGame;
	theGame.Init(640, 480);
	theGame.Start();
	
	TRACE("TAMERE");

	return 0;
}
