/**
 * Main class that regulates the application's flow.
 * 
 * @author Francis BISSON
 */ 

#ifndef GAME_H
#define GAME_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "DisplayContext.h"
#include "FramerateModule.h"
#include "KeyboardDevice.h"
#include "Scene.h"
#include "Rectangle.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Game
{
public:
					 Game();
	virtual			~Game();

	virtual	bool	Init();
	virtual	void	Start();
	
	virtual	void	ChangeScene(ScenePtr scene);
	
	void			Quit()	{ m_Quit = true; }
	
	const KeyboardDevice&	GetKeyboardDevice() const	{ return m_KeyboardDevice; }
	
	virtual	Rectangle	GetDisplayArea() const			{ return m_DisplayArea; }

protected:
	virtual	void	ManageEvents();
	
	DisplayContext	m_DisplayContext;
	KeyboardDevice	m_KeyboardDevice;
	
	ScenePtr		m_CurrentScene;
	
	bool			m_Quit;
	
	FramerateModule	m_Framerate;
	
	Rectangle		m_DisplayArea;
};

#endif // GAME_H
