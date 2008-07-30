/**
 * Implementation of the SplashScene class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Color.h"
#include "DisplayContext.h"
#include "Game.h"
#include "Image.h"
#include "MainMenu.h"
#include "Palette.h"
#include "Point.hpp"
#include "Scene.h"
#include "SplashScene.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
SplashScene::SplashScene(Game* game)
:Scene(game)
,m_Splash( new Image("Splash/mugen2clr.bmp") )
,m_FadeOutAnim( m_Splash )
{
}

SplashScene::~SplashScene()
{
}

bool SplashScene::Init()
{
	bool init = Scene::Init();
	
	PalettePtr kf0Palette( new Palette(2) );
	kf0Palette->SetColor(0, Color::Black);
	kf0Palette->SetColor(1, Color::White);
	
	PalettePtr kf1Palette( new Palette(2) );
	kf1Palette->SetColor(0, Color::Black);
	kf1Palette->SetColor(1, Color::Black);
	
	m_FadeOutAnim.AddKeyFrame(3.50, true,  kf0Palette);
	m_FadeOutAnim.AddKeyFrame(3.75, false, kf1Palette);
	m_FadeOutAnim.AddKeyFrame(4.00, false, kf1Palette); // same palette as the previous keyframe
	
	m_FadeOutAnim.Start();
	
	return init;
}

void SplashScene::Update(double deltaTime)
{
	Scene::Update(deltaTime);
	
	m_FadeOutAnim.Update(deltaTime);
	
	if(m_FadeOutAnim.IsFinished())
	{
		m_Game->ChangeScene( ScenePtr( new MainMenu(m_Game) ) );
	}
}

void SplashScene::Render(DisplayContext* displayContext)
{
	displayContext->DrawImage(*m_Splash, Point::Zero);
	
	Scene::Render(displayContext);
}
