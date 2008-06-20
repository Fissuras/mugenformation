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
	
	DEBUG_ASSERT2(errorCode >= 0, SDL_GetError());
}

DisplayContext::~DisplayContext()
{
	SDL_Quit();
}

bool DisplayContext::Init(Size screenWidth, Size screenHeight)
{
	m_Screen = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	DEBUG_ASSERT2(m_Screen, SDL_GetError());
	
	return true;
}

void DisplayContext::Flip()
{
	SDL_Flip(m_Screen);
}

void DisplayContext::SetColor(const Color& color)
{
	DEBUG_ASSERT(m_Screen);
	
	m_Color = SDL_MapRGB(m_Screen->format, color.GetRed(), color.GetGreen(), color.GetBlue());
}

void DisplayContext::ClearScreen()
{
	DEBUG_ASSERT(m_Screen);
	
	SDL_FillRect(m_Screen, NULL, m_Color);
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

void DisplayContext::DrawRectangle(const Point& position, Size width, Size height, bool filled)
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

void DisplayContext::DrawRectangle(const Rectangle& rectangle, bool filled)
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
	DEBUG_ASSERT(m_Screen);
	
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	
	SDL_FillRect(m_Screen, &rect, m_Color);
}

void DisplayContext::DrawImage(const Image& image)
{
	DEBUG_ASSERT(m_Screen);
	
	// Blit whole image to screen
	
	SDL_Rect destination;
	destination.x = image.GetX();
	destination.y = image.GetY();
	
	SDL_BlitSurface(image.m_Surface, NULL, m_Screen, &destination); 
}

void DisplayContext::DrawImage(const Image& image, const Rectangle& clippingMask)
{
	DEBUG_ASSERT(m_Screen);
	
	SDL_Rect destination;
	destination.x = image.GetX();
	destination.y = image.GetY();
	
	SDL_Rect source;
	source.x = clippingMask.GetX();
	source.y = clippingMask.GetY();
	source.w = clippingMask.GetWidth();
	source.h = clippingMask.GetHeight();
	
	SDL_BlitSurface(image.m_Surface, &source, m_Screen, &destination);
}
