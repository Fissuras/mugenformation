/**
 * Keyboard as an input device.
 * 
 * @author Francis BISSON
 */

#ifndef KEYBOARDDEVICE_H
#define KEYBOARDDEVICE_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "InputDevice.h"
#include "Keys.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class KeyboardDevice : public InputDevice
{
public:
					 KeyboardDevice();
	virtual			~KeyboardDevice();
	
	virtual	bool	Init();
	virtual	void	Update();
	
	virtual bool	IsKeyPressed(Keys key);
};

#endif // KEYBOARDDEVICE_H
