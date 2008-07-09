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
#include "Rectangle.h"
#include "Types.h"

// FORWARD DECLARATIONS ////////////////////////////////////////////////////////
class DisplayContext;
class Game;

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Player : public GameObject
{
public:
					 Player(UID uniqueId, Game* game);
	virtual			~Player();
	
	virtual	bool	Init();
	virtual void	Update(double deltaTime, double totalTime);
	virtual	void	Render(DisplayContext* displayContext);

protected:
	Rectangle		m_CollisionRect;
	double			m_Velocity;
	
	double			m_X;
	double			m_Y;
};

// UTILITY TYPEDEFS ////////////////////////////////////////////////////////////
typedef boost::shared_ptr<Player>	PlayerPtr;

#endif // PLAYER_H
