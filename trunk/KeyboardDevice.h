/**
 * Keyboard as an input device.
 * 
 * @author Francis BISSON
 */

#ifndef KEYBOARDDEVICE_H
#define KEYBOARDDEVICE_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>

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
	
	virtual bool	IsKeyPressed(Keys key) const;
	virtual	bool	IsKeyTriggered(Keys key) const;

protected:
	virtual	bool	IsKeyPressedImpl(Keys key, bool triggered) const;
	
	Uint8*			m_KeyStates;
	Uint8*			m_PreviousKeyStates;
};

#endif // KEYBOARDDEVICE_H
