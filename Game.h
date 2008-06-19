/**
 * Main class that regulates the application's flow.
 * 
 * @author Francis BISSON
 */ 

#ifndef GAME_H
#define GAME_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>

#include "DisplayContext.h"
#include "Types.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Game
{
public:
					 Game();
	virtual			~Game();

	virtual	bool	Init(Size screenWidth, Size screenHeight);
	virtual	void	Start();

protected:
	DisplayContext	m_DisplayContext;
};

#endif // GAME_H
