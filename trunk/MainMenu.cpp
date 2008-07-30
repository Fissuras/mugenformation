/**
 * Implementation of the MainMenu class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Color.h"
#include "Debug.h"
#include "DisplayContext.h"
#include "Font.h"
#include "Game.h"
#include "GameScene.h"
#include "Keys.h"
#include "MainMenu.h"
#include "Point.hpp"
#include "Rectangle.h"
#include "Scene.h"
#include "ShapeAnimation.h"
#include "Text.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
MainMenu::MainMenu(Game* game)
:Scene(game)
,m_Font( new Font("Fonts/dejavu.bmp", Color::White) )
,m_FocusText("+", m_Font)
,m_FocusIndex(0)
,m_VerticalRect( new Rectangle(316, 0, 120, 480) )
,m_HorizontalRect( new Rectangle(0, 155, 640, 60) )
,m_VerticalRectAnim( m_VerticalRect )
,m_HorizontalRectAnim( m_HorizontalRect )
,m_BlinkAnim( )
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
		m_MenuElements[i].reset( new Text(strings[i], m_Font) );
	}
	m_Positions[ITEM_PLAY_GAME	].MoveTo( 70, 245);
	m_Positions[ITEM_OPTIONS	].MoveTo( 31, 325);
	m_Positions[ITEM_QUIT		].MoveTo(138, 405);
	
	// Vertical rectangle anim setup
	Rectangle kf0VerticalRect(316, 0, 120, 480);
	Rectangle kf1VerticalRect(316 ,0, 273, 480);
	Rectangle kf2VerticalRect(316, 0, 324, 480);
	Rectangle kf3VerticalRect(80,  0, 560, 480);
	Rectangle kf4VerticalRect(0,   0, 640, 480);
	
	m_VerticalRectAnim.AddKeyFrame(0.000, true,  kf0VerticalRect);
	m_VerticalRectAnim.AddKeyFrame(0.025, true,  kf1VerticalRect);
	m_VerticalRectAnim.AddKeyFrame(0.100, false, kf2VerticalRect);
	m_VerticalRectAnim.AddKeyFrame(0.200, true,  kf2VerticalRect); // same rectangle as the previous keyframe
	m_VerticalRectAnim.AddKeyFrame(0.225, true,  kf3VerticalRect);
	m_VerticalRectAnim.AddKeyFrame(0.300, false, kf4VerticalRect);
	m_VerticalRectAnim.AddKeyFrame(0.600, false, kf4VerticalRect); // same rectangle as the previous keyframe
	
	// Horizontal rectangle anim setup
	Rectangle kf0HorizontalRect(0, 155, 640,  60);
	Rectangle kf1HorizontalRect(0, 115, 640, 100);
	Rectangle kf2HorizontalRect(0,   0, 640, 215);
	
	m_HorizontalRectAnim.AddKeyFrame(0.100, true,  kf0HorizontalRect);
	m_HorizontalRectAnim.AddKeyFrame(0.125, true,  kf1HorizontalRect);
	m_HorizontalRectAnim.AddKeyFrame(0.200, false, kf2HorizontalRect);
	
	// Blinking anim setup
	bool visible = true;
	for(int i=0; i<7; ++i)
	{
		m_BlinkAnim.AddKeyFrame(i * 0.1, false, visible);
		visible = !visible;
	}
	
	return init;
}

void MainMenu::Update(double deltaTime)
{
	Scene::Update(deltaTime);
	
	m_VerticalRectAnim.Update(deltaTime);
	m_HorizontalRectAnim.Update(deltaTime);
	m_BlinkAnim.Update(deltaTime);
	
	if(m_BlinkAnim.IsFinished() && !m_VerticalRectAnim.IsStarted())
	{
		m_VerticalRectAnim.Start();
		m_HorizontalRectAnim.Start();
	}
	
	if(m_VerticalRectAnim.IsFinished())
	{
		ScenePtr nextScene;
		
		switch(m_FocusIndex)
		{
		case ITEM_PLAY_GAME:
			nextScene.reset( new GameScene(m_Game) );
			break;
		case ITEM_OPTIONS:
//			nextScene.reset( new OptionsMenu(m_Game) );
//			break;
		case ITEM_QUIT:
			m_Game->Quit();
			break;
		default:
			DEBUG_ASSERT(false);
		}
		
		if(nextScene)
		{
			m_Game->ChangeScene(nextScene);
		}
		return;
	}
	
	if(!m_VerticalRectAnim.IsStarted() && !m_HorizontalRectAnim.IsStarted() && !m_BlinkAnim.IsStarted())
	{
		// Only check input if the anims have not started yet 
		
		if(m_Game->GetKeyboardDevice().IsKeyTriggered(UP))
		{
			m_FocusIndex = (m_FocusIndex == 0 ? ITEM_QTY : m_FocusIndex) - 1;
		}
		if(m_Game->GetKeyboardDevice().IsKeyTriggered(DOWN))
		{
			m_FocusIndex = (m_FocusIndex + 1) == ITEM_QTY ? 0 : (m_FocusIndex + 1);
		}
		
		if(m_Game->GetKeyboardDevice().IsKeyTriggered(RETURN))
		{
			m_BlinkAnim.SetControlledObject( DrawablePtr(m_MenuElements[m_FocusIndex]) );
			
			m_BlinkAnim.Start();
		}
	}
}

void MainMenu::Render(DisplayContext* displayContext)
{
	for(int i=0; i<ITEM_QTY; ++i)
	{
		displayContext->DrawText(*m_MenuElements[i], m_Positions[i]);
	}
	
	Point arrowPosition( m_Positions[m_FocusIndex] );
	arrowPosition.MoveBy(-m_FocusText.GetTextWidth(), 0);
	displayContext->DrawText(m_FocusText, arrowPosition);
	
	displayContext->SetColor(Color::White);
	displayContext->DrawRectangle(*m_VerticalRect);
	displayContext->DrawRectangle(*m_HorizontalRect);
	
	Scene::Render(displayContext);
}
