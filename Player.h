/**
 * Class that implements the behavior required for the player.
 * 
 * @author Francis BISSON
 */

#ifndef PLAYER_H
#define PLAYER_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <boost/shared_ptr.hpp>

#include "GameObject.h"
#include "Point.hpp"
#include "Rectangle.h"

// FORWARD DECLARATIONS ////////////////////////////////////////////////////////
class DisplayContext;
class Game;

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Player : public GameObject
{
public:
					 Player(Game* game);
	virtual			~Player();
	
	virtual	bool	Init();
	virtual void	Update(double deltaTime);
	virtual	void	Render(DisplayContext* displayContext);

protected:
	Rectangle		m_CollisionRect;
	double			m_Velocity;
	
	PrecisePoint	m_Position;
};

// UTILITY TYPEDEFS ////////////////////////////////////////////////////////////
typedef boost::shared_ptr<Player>	PlayerPtr;

#endif // PLAYER_H
