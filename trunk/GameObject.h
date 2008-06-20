/**
 * Abstract base class for all entities in the game world.
 * 
 * @author Francis BISSON
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <boost/shared_ptr.hpp>
#include <list>

#include "Types.h"

// FORWARD DECLARATIONS ////////////////////////////////////////////////////////
class DisplayContext;
class Game;

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class GameObject
{
public:
					GameObject(UID uniqueId, Game* game);
	virtual			~GameObject();
	
	virtual	bool	Init() = 0;
	virtual void	Update() = 0;
	virtual	void	Render(DisplayContext* displayContext) = 0;

protected:
	UID				m_UID;
	Game*			m_Game;
};

// UTILITY TYPEDEFS ////////////////////////////////////////////////////////////
typedef boost::shared_ptr<GameObject>	GameObjectPtr;
typedef std::list<GameObjectPtr>		GameObjectList;
typedef	GameObjectList::iterator		GameObjectIterator;

#endif // GAMEOBJECT_H
