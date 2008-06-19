/**
 * Abstract base class for all entities in the game world.
 * 
 * @author Francis BISSON
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Types.h"

// FORWARD DECLARATIONS ////////////////////////////////////////////////////////
class DisplayContext;

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class GameObject
{
public:
					GameObject(UID uniqueId) : m_UID(uniqueID)	{ }
	virtual			~GameObject()								{ }
	
	virtual	bool	Initialize() = 0;
	virtual void	Update() = 0;
	virtual	void	Render(DisplayContext* displayContext) = 0;

protected:
	UID				m_UID;
};

#endif // GAMEOBJECT_H
