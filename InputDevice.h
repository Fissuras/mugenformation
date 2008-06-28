/**
 * Manager for input devices.
 * 
 * @author Francis BISSON
 */

#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Keys.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class InputDevice
{
public:
					 InputDevice();
	virtual			~InputDevice();
	
	virtual	bool	Init();
	virtual	void	Update();
	
	virtual	bool	IsKeyPressed(Keys key) const = 0;
	virtual	bool	IsKeyTriggered(Keys key) const = 0;
};

#endif // INPUTDEVICE_H
