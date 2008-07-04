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
#include "KeyFrame.hpp"
#include "MainMenu.h"
#include "Palette.h"
#include "Point.h"
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
	KeyFrame<PalettePtr> kf0(3.5, true, kf0Palette);
	
	PalettePtr kf1Palette( new Palette(2) );
	kf1Palette->SetColor(0, Color::Black);
	kf1Palette->SetColor(1, Color::Black);
	KeyFrame<PalettePtr> kf1(3.75, false, kf1Palette);
	
	// Same palette as KeyFrame1
	KeyFrame<PalettePtr> kf2(4.0, false, kf1Palette);
	
	m_FadeOutAnim.AddKeyFrame(kf0);
	m_FadeOutAnim.AddKeyFrame(kf1);
	m_FadeOutAnim.AddKeyFrame(kf2);
	
	m_FadeOutAnim.Start();
	
	return init;
}

void SplashScene::Update(double deltaTime, double totalTime)
{
	Scene::Update(deltaTime, totalTime);
	
	m_FadeOutAnim.Update(deltaTime, totalTime);
	
	if(m_FadeOutAnim.IsFinished())
	{
		m_Game->ChangeScene( ScenePtr( new MainMenu(m_Game) ) );
	}
}

void SplashScene::Render(DisplayContext* displayContext)
{
	Scene::Render(displayContext);
	
	displayContext->DrawImage(*m_Splash, Point::Zero);
}