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
	
	virtual	void	ChangeScene(ScenePtr scene);
	
	void			Quit() { m_Quit = true; }

protected:
	virtual	void	ManageEvents();
	
	DisplayContext	m_DisplayContext;
	KeyboardDevice	m_KeyboardDevice;
	
	ScenePtr		m_CurrentScene;
	
	bool			m_Quit;
};

#endif // GAME_H
