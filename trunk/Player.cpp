/**
 * Implementation of the Player class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <algorithm>

#include "Debug.h"
#include "DisplayContext.h"
#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include "Point.hpp"
#include "Rectangle.h"
#include "Types.h"
#include "Utility.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Player::Player(Game* game)
:GameObject(game)
,m_CollisionRect(0, 0, 5, 5)
,m_Velocity(200.0)
,m_Position(0.0, 0.0)
{
}

Player::~Player()
{
}

bool Player::Init()
{
	Rectangle displayArea = m_Game->GetDisplayArea();
	m_Position.MoveTo((displayArea.GetWidth() - m_CollisionRect.GetWidth()) / 2.0, 0.75 * displayArea.GetHeight());
	
	m_CollisionRect.ResizeTo(10, 10);
	m_CollisionRect.MoveTo(m_Position);
	
	return true;
}

void Player::Update(double deltaTime)
{
	if(m_Game->GetKeyboardDevice().IsKeyPressed(LEFT))
	{
		m_Position.MoveBy(-(m_Velocity * deltaTime), 0.0);
	}
	if(m_Game->GetKeyboardDevice().IsKeyPressed(RIGHT))
	{
		m_Position.MoveBy((m_Velocity * deltaTime), 0.0);
	}
	if(m_Game->GetKeyboardDevice().IsKeyPressed(UP))
	{
		m_Position.MoveBy(0.0, -(m_Velocity * deltaTime));
	}
	if(m_Game->GetKeyboardDevice().IsKeyPressed(DOWN))
	{
		m_Position.MoveBy(0.0, (m_Velocity * deltaTime));
	}
	
	if(m_Game->GetKeyboardDevice().IsKeyPressed(RETURN))
	{
	}
	
	Rectangle displayArea = m_Game->GetDisplayArea();
	double x = std::min( std::max(0.0, m_Position.GetX()) , displayArea.GetWidth()  - (double)m_CollisionRect.GetWidth() );
	double y = std::min( std::max(0.0, m_Position.GetY()) , displayArea.GetHeight() - (double)m_CollisionRect.GetHeight() );
	m_Position.MoveTo(x, y);
	
	m_CollisionRect.MoveTo(m_Position);
}

void Player::Render(DisplayContext* displayContext)
{
	displayContext->SetColor(Color::Blue);
	displayContext->DrawRectangle(m_CollisionRect, false);
}
