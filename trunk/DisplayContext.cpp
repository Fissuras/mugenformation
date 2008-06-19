/**
 * Implementation of the DisplayContext class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>

#include "Color.h"
#include "Debug.h"
#include "DisplayContext.h"
#include "Point.h"
#include "Rectangle.h"
#include "Types.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
DisplayContext::DisplayContext()
:m_Screen(NULL)
,m_Color(0)
{
	int errorCode = SDL_Init(SDL_INIT_VIDEO);
	(void)errorCode;
	
	DEBUG_ASSERT(errorCode >= 0 && SDL_GetError());
}

DisplayContext::~DisplayContext()
{
	SDL_Quit();
}

void DisplayContext::Init(Size screenWidth, Size screenHeight)
{
	m_Screen = SDL_SetVideoMode(screenWidth * 10000, screenHeight, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	DEBUG_ASSERT(m_Screen != NULL);
}

void DisplayContext::Flip()
{
	SDL_Flip(m_Screen);
}

void DisplayContext::SetColor(const Color& color)
{
	DEBUG_ASSERT(m_Screen != NULL);
	
	m_Color = SDL_MapRGB(m_Screen->format, color.GetRed(), color.GetGreen(), color.GetBlue());
}

void DisplayContext::DrawRectangle(Coord x, Coord y, Size width, Size height, bool filled)
{
	if(filled)
	{
		FillRectangle(x, y, width, height);
	}
	else
	{
		// Top side
		FillRectangle(x, y, width, 1);
		
		// Bottom side
		FillRectangle(x, y + height, width, 1);
		
		// Left side
		FillRectangle(x, y, 1, height);
		
		// Right side
		FillRectangle(x + width, y, 1, height);
	}
}

void DisplayContext::DrawRectangle(Point& position, Size width, Size height, bool filled)
{
	Coord x = position.GetX();
	Coord y = position.GetY();
	
	if(filled)
	{
		FillRectangle(x, y, width, height);
	}
	else
	{
		// Top side
		FillRectangle(x, y, width, 1);
		
		// Bottom side
		FillRectangle(x, y + height, width, 1);
		
		// Left side
		FillRectangle(x, y, 1, height);
		
		// Right side
		FillRectangle(x + width, y, 1, height);
	}
}

void DisplayContext::DrawRectangle(Rectangle& rectangle, bool filled)
{
	Coord x = rectangle.GetX();
	Coord y = rectangle.GetY();
	Size width = rectangle.GetWidth();
	Size height = rectangle.GetHeight();
	
	if(filled)
	{
		FillRectangle(x, y, width, height);
	}
	else
	{
		// Top side
		FillRectangle(x, y, width, 1);
		
		// Bottom side
		FillRectangle(x, y + height, width, 1);
		
		// Left side
		FillRectangle(x, y, 1, height);
		
		// Right side
		FillRectangle(x + width, y, 1, height);
	}
}

void DisplayContext::FillRectangle(Coord x, Coord y, Size width, Size height)
{
	DEBUG_ASSERT(m_Screen != NULL);
	
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	
	SDL_FillRect(m_Screen, &rect, m_Color);
}

//void DisplayContext::DrawImage(Image& image, Coord x, Coord y)
//{
//}
