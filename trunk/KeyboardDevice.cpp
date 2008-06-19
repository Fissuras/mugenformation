/**
 * Implementation of the KeyboardDevice class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "InputDevice.h"
#include "KeyboardDevice.h"
#include "Keys.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
KeyboardDevice::KeyboardDevice()
:InputDevice()
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
	
	
}

bool KeyboardDevice::IsKeyPressed(Keys key)
{
	return false;
}
