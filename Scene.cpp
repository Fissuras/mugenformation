/**
 * Implementation of the Scene class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "DisplayContext.h"
#include "Game.h"
#include "GameObject.h"
#include "Scene.h"
#include "Utility.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Scene::Scene(Game* game)
:m_Game(game)
{
}

Scene::~Scene()
{
}

bool Scene::Init()
{
	for(GameObjectIterator i = m_GameObjects.begin(); i != m_GameObjects.end(); ++i)
	{
		GameObjectPtr gameObject(*i);
		if(!gameObject->Init())
		{
			return false;
		}
	}
	
	return true;
}

void Scene::Update(double deltaTime, double totalTime)
{
	UNUSED(deltaTime);
	UNUSED(totalTime);
	
//	for(GameObjectIterator i = m_GameObjects.begin(); i != m_GameObjects.end(); ++i)
//	{
//		GameObjectPtr gameObject(*i);
//		gameObject->Update(deltaTime, totalTime);
//	}
}

void Scene::Render(DisplayContext* displayContext)
{
	UNUSED(displayContext);
	
//	for(GameObjectIterator i = m_GameObjects.begin(); i != m_GameObjects.end(); ++i)
//	{
//		GameObjectPtr gameObject(*i);
//		gameObject->Render(displayContext);
//	}
}
