/**
 * Implementation of the FramerateModule class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <sstream>
#include <SDL/SDL.h>

#include "Color.h"
#include "Debug.h"
#include "DisplayContext.h"
#include "Font.h"
#include "FramerateModule.h"
#include "Game.h"
#include "GameObject.h"
#include "Point.h"
#include "Text.h"
#include "Utility.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
FramerateModule::FramerateModule(Game* game, unsigned long targetFps)
:GameObject("FramerateModule", game)
,m_FrameCount(0)
,m_Time(0.0)
,m_FrameTime(0.0)
,m_TargetFps(targetFps)
#ifndef NDEBUG
,m_Font( new Font("Fonts/dejavu.bmp", Color::Grey ) )
,m_FPS( m_Font )
#endif
{
	DEBUG_ASSERT(m_TargetFps > 0 && m_TargetFps <= 200);
}

FramerateModule::~FramerateModule()
{
}

bool FramerateModule::Init()
{
	m_FrameCount = 0;
	m_Time = 0.0;
	
#ifndef NDEBUG
	m_FPS.Hide();
#endif
	
	return true;
}

void FramerateModule::Update(double deltaTime, double totalTime)
{
	UNUSED(totalTime);
	
	m_FrameTime = deltaTime;
	
	m_FrameCount++;
	m_Time += deltaTime;
	
	if(m_Time >= 1.0)
	{
#ifndef NDEBUG
		std::stringstream fps;
		fps << "FPS:" << m_FrameCount;
		m_FPS.SetText(fps.str());
		m_FPS.Show();
#endif
		
		m_FrameCount = 0;
		m_Time = 0.0;
	}
}

void FramerateModule::Render(DisplayContext* displayContext)
{
#ifndef NDEBUG
	displayContext->DrawText(m_FPS, Point::Zero);
#else
	UNUSED(displayContext);
#endif
}

void FramerateModule::LimitFramerate()
{
	double targetFrameTime = 1.0 / (double)m_TargetFps;
	
	if(targetFrameTime >= m_FrameTime)
	{
		Uint32 delay = (Uint32)((targetFrameTime - m_FrameTime) * 1000.0);
		SDL_Delay(delay);
	}
}
