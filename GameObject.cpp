/**
 * Implementation of the GameObject abstract base class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Game.h"
#include "GameObject.h"
#include "Types.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
GameObject::GameObject(Game* game)
:m_Game(game)
{
}

GameObject::~GameObject()
{
}
