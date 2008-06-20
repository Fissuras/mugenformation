/**
 * Main class that regulates the application's flow.
 * 
 * @author Francis BISSON
 */ 

#ifndef GAME_H
#define GAME_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "DisplayContext.h"
#include "KeyboardDevice.h"
#include "Scene.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Game
{
public:
					 Game();
	virtual			~Game();

	virtual	bool	Init();
	virtual	void	Start();

protected:
	DisplayContext	m_DisplayContext;
	KeyboardDevice	m_KeyboardDevice;
	
	ScenePtr		m_spCurrentScene;
};

#endif // GAME_H
