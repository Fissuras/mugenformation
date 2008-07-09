/**
 * Implementation of the Player class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <algorithm>

#include "DisplayContext.h"
#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include "Rectangle.h"
#include "Types.h"
#include "Utility.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Player::Player(UID uniqueId, Game* game)
:GameObject(uniqueId, game)
,m_CollisionRect(0, 0, 5, 5)
,m_Velocity(200.0)
,m_X(0.0)
,m_Y(0.0)
{
}

Player::~Player()
{
}

bool Player::Init()
{
	m_X = (640 - m_CollisionRect.GetWidth()) / 2;
	m_Y = 400;
	
	m_CollisionRect.ResizeTo(10, 10);
	m_CollisionRect.MoveTo((Coord)m_X, (Coord)m_Y);
	
	return true;
}

void Player::Update(double deltaTime, double totalTime)
{
	UNUSED(deltaTime);
	UNUSED(totalTime);
	
	if(m_Game->GetKeyboardDevice().IsKeyPressed(LEFT))
	{
		m_X = std::max(m_X - (m_Velocity * deltaTime), 0.0);
	}
	if(m_Game->GetKeyboardDevice().IsKeyPressed(RIGHT))
	{
		m_X = std::min(m_X + (m_Velocity * deltaTime), 640.0 - m_CollisionRect.GetWidth());
	}
	if(m_Game->GetKeyboardDevice().IsKeyPressed(UP))
	{
		m_Y = std::max(m_Y - (m_Velocity * deltaTime), 0.0);
	}
	if(m_Game->GetKeyboardDevice().IsKeyPressed(DOWN))
	{
		m_Y = std::min(m_Y + (m_Velocity * deltaTime), 480.0 - m_CollisionRect.GetHeight());
	}
	
	m_CollisionRect.MoveTo((Coord)m_X, (Coord)m_Y);
}

void Player::Render(DisplayContext* displayContext)
{
	displayContext->SetColor(Color::Blue);
	displayContext->DrawRectangle(m_CollisionRect, false);
}
