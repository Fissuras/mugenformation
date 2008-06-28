/**
 * Implementation of the KeyboardDevice class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <cstring>
#include <SDL/SDL.h>

#include "Debug.h"
#include "InputDevice.h"
#include "KeyboardDevice.h"
#include "Keys.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
KeyboardDevice::KeyboardDevice()
:InputDevice()
,m_KeyStates(NULL)
{
	m_PreviousKeyStates = new Uint8[SDLK_LAST];
}

KeyboardDevice::~KeyboardDevice()
{
	delete[] m_PreviousKeyStates;
}

bool KeyboardDevice::Init()
{
	bool init = InputDevice::Init();
	
	return init;
}

void KeyboardDevice::Update()
{
	InputDevice::Update();
	
	if(m_KeyStates != NULL)
	{
		memcpy(m_PreviousKeyStates, m_KeyStates, SDLK_LAST * sizeof(Uint8));
	}
	
	SDL_PumpEvents();
	
	m_KeyStates = SDL_GetKeyState(NULL);
}

bool KeyboardDevice::IsKeyPressed(Keys key) const
{
	return IsKeyPressedImpl(key, false);
}

bool KeyboardDevice::IsKeyTriggered(Keys key) const
{
	return IsKeyPressedImpl(key, true);
}

bool KeyboardDevice::IsKeyPressedImpl(Keys key, bool triggered) const
{
	int index = -1;
	switch(key)
	{
	case UP:
		index = SDLK_UP;
		break;
	case DOWN:
		index = SDLK_DOWN;
		break;
	case LEFT:
		index = SDLK_LEFT;
		break;
	case RIGHT:
		index = SDLK_RIGHT;
		break;
	case RETURN:
		index = SDLK_RETURN;
		break;
	default:
		return false;
	}
	
	bool isPressed = (bool)m_KeyStates[index];
	if(triggered && isPressed)
	{
		isPressed = isPressed && !m_PreviousKeyStates[index];
	}
	
	return isPressed;
}
