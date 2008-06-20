/**
 * Implementation of the KeyboardDevice class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>

#include "InputDevice.h"
#include "KeyboardDevice.h"
#include "Keys.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
KeyboardDevice::KeyboardDevice()
:InputDevice()
,m_KeyStates(NULL)
{
}

KeyboardDevice::~KeyboardDevice()
{
}

bool KeyboardDevice::Init()
{
	bool bRet = InputDevice::Init();
	
	return bRet;
}

void KeyboardDevice::Update()
{
	InputDevice::Update();
	
	SDL_PumpEvents();
}

bool KeyboardDevice::IsKeyPressed(Keys key)
{
	m_KeyStates = SDL_GetKeyState(NULL);
	
	switch(key)
	{
	case UP:
		return (bool)m_KeyStates[SDLK_UP];
	case DOWN:
		return (bool)m_KeyStates[SDLK_DOWN];
	case LEFT:
		return (bool)m_KeyStates[SDLK_LEFT];
	case RIGHT:
		return (bool)m_KeyStates[SDLK_RIGHT];
	}
	
	return false;
}
