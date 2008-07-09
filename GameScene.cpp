/**
 * Implementation of the GameScene class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <sstream>

#include "Color.h"
#include "DisplayContext.h"
#include "Game.h"
#include "GameScene.h"
#include "Player.h"
#include "Scene.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
GameScene::GameScene(Game* game)
:Scene(game)
,m_Player( new Player("Player1", game) )
{
}

GameScene::~GameScene()
{
}
	
bool GameScene::Init()
{
	m_GameObjects.push_back(m_Player);
	
	return Scene::Init();
}

void GameScene::Update(double deltaTime, double totalTime)
{
	if(m_Game->GetKeyboardDevice().IsKeyTriggered(ESCAPE))
	{
		m_Game->Quit();
		return;
	}
	
	Scene::Update(deltaTime, totalTime);
}

void GameScene::Render(DisplayContext* displayContext)
{
	displayContext->SetColor(Color::White);
	displayContext->ClearScreen();
	
	Scene::Render(displayContext);
}
