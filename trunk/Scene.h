/**
 * Base abstract class for the game scenes (menus, game levels, etc.)
 * 
 * @author Francis BISSON
 */

#ifndef SCENE_H
#define SCENE_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <boost/shared_ptr.hpp>

#include "GameObject.h"

// FORWARD DECLARATIONS ////////////////////////////////////////////////////////
class DisplayContext;
class Game;
class Scene;

// UTILITY TYPEDEFS ////////////////////////////////////////////////////////////
typedef boost::shared_ptr<Scene>	ScenePtr;

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Scene
{
public:
					 Scene(Game* game);
	virtual			~Scene() = 0;
	
//	virtual	bool	Load();
	
	virtual	bool	Init();
	virtual void	Update();
	virtual	void	Render(DisplayContext* displayContext);
	
protected:
	Game*			m_pGame;
	Scene*			m_pPreviousScene;
	GameObjectList	m_GameObjects;
};

#endif // SCENE_H
