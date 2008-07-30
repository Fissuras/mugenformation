/**
 * Implementation of the DisplayContext class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <string>
#include <SDL/SDL.h>

#include "Color.h"
#include "Debug.h"
#include "DisplayContext.h"
#include "Font.h"
#include "Point.hpp"
#include "Rectangle.h"
#include "Text.h"
#include "Types.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
DisplayContext::DisplayContext()
:m_Screen(NULL)
,m_Color(0)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		DEBUG_ASSERT2(false, SDL_GetError());
	}
}

DisplayContext::~DisplayContext()
{
	SDL_Quit();
}

bool DisplayContext::Init(Size screenWidth, Size screenHeight, bool fullscreen)
{
	m_ScreenWidth = screenWidth;
	m_ScreenHeight = screenHeight;
	
	Uint32 flags = SDL_HWSURFACE | SDL_DOUBLEBUF;
	if(fullscreen)
	{
		flags |= SDL_FULLSCREEN;
	}
	
	m_Screen = SDL_SetVideoMode(m_ScreenWidth, m_ScreenHeight, 32, flags);
	
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
	if(!rectangle.IsVisible()) return;
	
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
		FillRectangle(x, y + height - 1, width, 1);
		
		// Left side
		FillRectangle(x, y, 1, height);
		
		// Right side
		FillRectangle(x + width - 1, y, 1, height);
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

void DisplayContext::DrawImage(const Image& image, const Point& position)
{
	DEBUG_ASSERT(m_Screen);
	
	if(!image.IsVisible()) return;
	
	// Blit whole image to screen
	
	SDL_Rect destination;
	destination.x = position.GetX();
	destination.y = position.GetY();
	
	SDL_BlitSurface(image.m_Surface, NULL, m_Screen, &destination); 
}

void DisplayContext::DrawImage(const Image& image, const Point& position, const Rectangle& clippingMask)
{
	DEBUG_ASSERT(m_Screen);
	
	if(!image.IsVisible()) return;
	
	SDL_Rect destination;
	destination.x = position.GetX();
	destination.y = position.GetY();
	
	SDL_Rect source;
	source.x = clippingMask.GetX();
	source.y = clippingMask.GetY();
	source.w = clippingMask.GetWidth();
	source.h = clippingMask.GetHeight();
	
	SDL_BlitSurface(image.m_Surface, &source, m_Screen, &destination);
}

void DisplayContext::DrawText(const Text& text, const Point& position)
{
	DEBUG_ASSERT(m_Screen);
	
	if(!text.IsVisible()) return;
	
	Rectangle mask;
	Point charPosition(position);
	
	Size charWidth = text.m_Font->GetCharacterWidth();
	Size charHeight = text.m_Font->GetCharacterHeight();
	
	for(Uint32 i=0; i<text.m_String.length(); ++i)
	{
		char character = text.m_String[i];
		
		if(character != ' ')
		{
			DEBUG_ASSERT(character >= '!' && character <= '~');
			// TODO Get character range from font's config file
			mask.MoveTo((Coord)((character - '!') * text.m_Font->GetCharacterWidth()), 0);
			mask.ResizeTo(charWidth, charHeight);
			
			DrawImage(text.m_Font->m_FontImage, charPosition, mask);
		}
		
		charPosition.MoveBy(charWidth, 0);
	}
}
