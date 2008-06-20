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

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Scene::Scene(Game* game)
:m_pGame(game)
,m_pPreviousScene(NULL)
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

void Scene::Update()
{
	for(GameObjectIterator i = m_GameObjects.begin(); i != m_GameObjects.end(); ++i)
	{
		GameObjectPtr gameObject(*i);
		gameObject->Update();
	}
}

void Scene::Render(DisplayContext* displayContext)
{
	for(GameObjectIterator i = m_GameObjects.begin(); i != m_GameObjects.end(); ++i)
	{
		GameObjectPtr gameObject(*i);
		gameObject->Render(displayContext);
	}
}
