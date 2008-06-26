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
{
}

SplashScene::~SplashScene()
{
}

bool SplashScene::Init()
{
	bool init = Scene::Init();
	
	bool loaded = m_Splash.Load("Splash/mugen2clr.bmp");
	DEBUG_ASSERT(loaded);
	
	m_Splash.MoveTo(0, 0);
	
	m_StartTime = -1.0;

	m_FadeOutPalette.SetColor(0, Color::Black);
	m_FadeOutPalette.SetColor(1, Color::White);
	
	return init;
}

void SplashScene::Update(double deltaTime, double totalTime)
{
	UNUSED(deltaTime);
	
	if(m_StartTime == -1.0)
	{
		m_StartTime = totalTime;
	}
	
	double sceneTotalTime = (totalTime - m_StartTime);
	
	Color newColor;
	
	if(sceneTotalTime < m_FadeOutStart)
	{
		newColor = Color::White;
	}
	else
	{
		double fadeOutTime = (sceneTotalTime - m_FadeOutStart);
		if(fadeOutTime >= m_FadeOutDuration)
		{
			newColor = Color::Black;
		}
		else
		{
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
	
	displayContext->DrawImage(m_Splash);
	
	Scene::Render(displayContext);
}
