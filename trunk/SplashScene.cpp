/**
 * Implementation of the SplashScene class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Color.h"
#include "Debug.h"
#include "DisplayContext.h"
#include "Game.h"
#include "Image.h"
#include "MainMenu.h"
#include "Point.h"
#include "Rectangle.h"
#include "Scene.h"
#include "SplashScene.h"
#include "Types.h"
#include "Utility.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
SplashScene::SplashScene(Game* game)
:Scene(game)
,m_Splash()
,m_FadeOutStart(3.5)
,m_FadeOutDuration(0.25)
,m_FadeOutPalette(2)
,m_PaletteChanged(false)
,m_SceneDisplayDuration(4.0)
{
}

SplashScene::~SplashScene()
{
}

bool SplashScene::Init()
{
	bool init = Scene::Init();
	
	init = init && m_Splash.Load("Splash/mugen2clr.bmp");
	
	m_StartTime = -1.0;

	m_FadeOutPalette.SetColor(0, Color::Black);
	m_FadeOutPalette.SetColor(1, Color::White);
	
	return init;
}

void SplashScene::Update(double deltaTime, double totalTime)
{
	Scene::Update(deltaTime, totalTime);
	
	if(m_StartTime == -1.0)
	{
		m_StartTime = totalTime;
	}
	
	double sceneTotalTime = (totalTime - m_StartTime);
	if(sceneTotalTime >= m_SceneDisplayDuration)
	{
		m_Game->ChangeScene( ScenePtr(new MainMenu(m_Game) ));
		m_PaletteChanged = false;
		return;
	}
	
	Color newColor;
	
	if(sceneTotalTime < m_FadeOutStart)
	{
		// Fade out not yet started
		newColor = Color::White;
	}
	else
	{
		double fadeOutTime = (sceneTotalTime - m_FadeOutStart);
		if(fadeOutTime >= m_FadeOutDuration)
		{
			// Fade out finished
			newColor = Color::Black;
		}
		else
		{
			// Fading out
			double alpha = fadeOutTime / m_FadeOutDuration;
			Byte shade = (Byte)(0xFF - (Byte)(0xFF * alpha));
			newColor = Color(shade, shade, shade);
		}
	}
	
	if(newColor != m_FadeOutPalette.GetColor(1))
	{
		m_FadeOutPalette.SetColor(1, newColor);
		m_PaletteChanged = true;
	}
	else
	{
		m_PaletteChanged = false;
	}
}

void SplashScene::Render(DisplayContext* displayContext)
{
	if(m_PaletteChanged)
	{
		m_Splash.SetPalette(m_FadeOutPalette);
	}
	
	displayContext->DrawImage(m_Splash, Point::Zero);
	
	Scene::Render(displayContext);
}
