/**
 * Implementation of the Game class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <cstdlib>
#include <ctime>
#include <SDL/SDL.h>

#include "Color.h"
#include "Debug.h"
#include "DisplayContext.h"
#include "Game.h"
#include "KeyboardDevice.h"
#include "Scene.h"
#include "SplashScene.h"
#include "Types.h"

// MACROS //////////////////////////////////////////////////////////////////////
#define USE_FRAMERATE_LIMITER

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Game::Game()
:m_DisplayContext()
,m_KeyboardDevice()
,m_CurrentScene()
,m_Quit(false)
,m_Framerate(this, 60)
,m_DisplayArea(0, 0, 640, 480)
{
}

Game::~Game()
{
}

bool Game::Init()
{
	// TODO Load game config
	
	bool init = true;
	init = init && m_DisplayContext.Init(m_DisplayArea.GetWidth(), m_DisplayArea.GetHeight());
	init = init && m_KeyboardDevice.Init();
	
	SDL_WM_SetCaption("Mugen Formation", NULL);
	
	// Load initial scene
	m_CurrentScene.reset( new SplashScene(this) );
	init = init && m_CurrentScene->Init();
	
	// Initialize random number generator
	srand( time(NULL) );
	
	return init;
}

void Game::Start()
{
	DEBUG_ASSERT(m_CurrentScene.get() != NULL);
	
	Uint32 lastTime	= SDL_GetTicks();
	m_Quit = false;
	
	while(!m_Quit)
	{
		// CLEAR SCREEN
		m_DisplayContext.SetColor(Color::Black);
		m_DisplayContext.ClearScreen();

		// MANAGE INPUT DEVICES
		m_KeyboardDevice.Update();
		
		// MANAGE EVENTS
		ManageEvents();
		
		Uint32 currentTime = SDL_GetTicks();
		double deltaTime = (double)(currentTime - lastTime) / 1000.0;
		
		lastTime = currentTime;
		
		// MANAGE CURRENT SCENE
		m_CurrentScene->Update(deltaTime);
		m_Framerate.Update(deltaTime);
		
		// RENDER GAME OBJECTS
		m_CurrentScene->Render(&m_DisplayContext);
		m_Framerate.Render(&m_DisplayContext);
		
		// FLIP (SWAP) DISPLAY BUFFERS
		m_DisplayContext.Flip();
		
#ifdef USE_FRAMERATE_LIMITER
		m_Framerate.LimitFramerate();
#endif
	}
}

void Game::ManageEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			m_Quit = true;
			break;
		}
	}
}

void Game::ChangeScene(ScenePtr scene)
{
	if(m_CurrentScene)
	{
		/**
		 * TODO Implement scenes stack
		 * i.e. Game scene -> Pause Menu -> Options Menu -> Back to Pause Menu -> Back to Game
		 */
		
		m_CurrentScene = scene;
		m_CurrentScene->Init();
	}
}
