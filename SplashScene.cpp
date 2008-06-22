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
#include "Utility.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
SplashScene::SplashScene(Game* game)
:Scene(game)
,m_Splash()
,m_FadeOutStart(3.5)
,m_FadeOutDuration(0.5)
,m_Alpha(1.0)
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
	
	if(sceneTotalTime < m_FadeOutStart)
	{
		m_Alpha = 1.0;
	}
	else
	{
		double fadeOutTime = (sceneTotalTime - m_FadeOutStart);
		if(fadeOutTime >= m_FadeOutDuration)
		{
			m_Alpha = 0.0;
		}
		else
		{
			m_Alpha = 1.0 - (fadeOutTime / m_FadeOutDuration);
		}
	}
}

void SplashScene::Render(DisplayContext* displayContext)
{
	if(m_Alpha > 0.0)
	{
		if(m_Alpha < 1.0)
		{
			m_Splash.SetAlpha(m_Alpha);
		}
		
		displayContext->DrawImage(m_Splash);
	}
	
	Scene::Render(displayContext);
}
