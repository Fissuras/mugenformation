/**
 * Implementation of the Game class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Debug.h"
#include "DisplayContext.h"
#include "Game.h"
#include "Types.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Game::Game()
:m_DisplayContext()
{
}

Game::~Game()
{
}

bool Game::Init(Size screenWidth, Size screenHeight)
{
	m_DisplayContext.Init(screenWidth, screenHeight);
	
	return true;
}

void Game::Start()
{
	bool done = false;
	while(!done)
	{
		// MANAGE EVENTS
		
		// MANAGE GAME OBJECTS
		
		// TODO GameObject base class
		// TODO list<boost::shared_ptr<GameObject> >
		// TODO install boost
		
		// RENDER GAME OBJECTS
		
		// Flip (swap) display buffers
		m_DisplayContext.Flip();
	}
}
