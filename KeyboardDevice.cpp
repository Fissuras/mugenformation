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
	
	(void)key;

	return false;
}
