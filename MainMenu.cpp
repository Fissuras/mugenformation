/**
 * Implementation of the MainMenu class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Color.h"
#include "DisplayContext.h"
#include "Font.h"
#include "Game.h"
#include "Keys.h"
#include "MainMenu.h"
#include "Point.h"
#include "Rectangle.h"
#include "Scene.h"
#include "Text.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
MainMenu::MainMenu(Game* game)
:Scene(game)
,m_Font( new Font("Fonts/dejavu.bmp", Color::White) )
,m_FocusText("+", m_Font)
,m_FocusIndex(0)
,m_VerticalRect(316, 0, 120, 480)
,m_HorizontalRect(0, 155, 640, 60)
{
}

MainMenu::~MainMenu()
{
}

bool MainMenu::Init()
{
	bool init = Scene::Init();
	
	std::string strings[ITEM_QTY] =
	{
		"Play game",
		"Options",
		"Quit"
	};
	
	for(int i=0; i<ITEM_QTY; ++i)
	{
		m_MenuElements[i].SetFont(m_Font);
		m_MenuElements[i].SetText(strings[i]);
	}
	m_Positions[ITEM_PLAY_GAME	].MoveTo( 70, 245);
	m_Positions[ITEM_OPTIONS	].MoveTo( 31, 325);
	m_Positions[ITEM_QUIT		].MoveTo(138, 405);
	
	return init;
}

void MainMenu::Update(double deltaTime, double totalTime)
{
	Scene::Update(deltaTime, totalTime);
	
	if(m_Game->GetKeyboardDevice().IsKeyTriggered(UP))
	{
		m_FocusIndex = (m_FocusIndex == 0 ? ITEM_QTY : m_FocusIndex) - 1;
	}
	if(m_Game->GetKeyboardDevice().IsKeyTriggered(DOWN))
	{
		m_FocusIndex = (m_FocusIndex + 1) == ITEM_QTY ? 0 : (m_FocusIndex + 1);
	}
	
	if(m_FocusIndex == ITEM_QUIT && m_Game->GetKeyboardDevice().IsKeyTriggered(RETURN))
	{
		m_Game->Quit();
	}
}

void MainMenu::Render(DisplayContext* displayContext)
{
	for(int i=0; i<ITEM_QTY; ++i)
	{
		displayContext->DrawText(m_MenuElements[i], m_Positions[i]);
	}
	
	Point arrowPosition( m_Positions[m_FocusIndex] );
	arrowPosition.MoveBy(-m_FocusText.GetTextWidth(), 0);
	displayContext->DrawText(m_FocusText, arrowPosition);
	
	displayContext->SetColor(Color::White);
	displayContext->DrawRectangle(m_VerticalRect);
	displayContext->DrawRectangle(m_HorizontalRect);
	
	Scene::Render(displayContext);
}
