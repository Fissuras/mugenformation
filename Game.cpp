/**
 * Implementation of the Game class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>

#include "Debug.h"
#include "DisplayContext.h"
#include "Game.h"
#include "KeyboardDevice.h"
#include "Scene.h"
#include "Types.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Game::Game()
:m_DisplayContext()
,m_KeyboardDevice()
,m_spCurrentScene()
{
}

Game::~Game()
{
}

bool Game::Init()
{
	// TODO Load game config
	
	bool bRet = true
		&&	m_DisplayContext.Init(640, 480)
		&&	m_KeyboardDevice.Init();
	
	// Load initial scene
	
	return bRet;
}

void Game::Start()
{
	DEBUG_ASSERT(m_spCurrentScene.get() != NULL);
	
	bool done = false;
	while(!done)
	{
		// MANAGE EVENTS
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				done = true;
				break;
			}
		}
		
		if(!done)
		{
			// MANAGE INPUT DEVICES
			m_KeyboardDevice.Update();
			
			// MANAGE CURRENT SCENE
			m_spCurrentScene->Update();
			
			// RENDER GAME OBJECTS
			m_spCurrentScene->Render(&m_DisplayContext);
			
			// FLIP (SWAP) DISPLAY BUFFERS
			m_DisplayContext.Flip();
		}
	}
}
