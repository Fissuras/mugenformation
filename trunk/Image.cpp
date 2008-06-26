/**
 * Implementation of the Image class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>
#include <string>

#include "Debug.h"
#include "Image.h"
#include "Palette.h"
#include "Types.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Image::Image()
:m_Surface(NULL)
,m_Position(0, 0)
{
}

Image::Image(std::string filename)
:m_Surface(NULL)
,m_Position(0, 0)
{
	bool loaded = Load(filename);
	
	DEBUG_ASSERT2(loaded, SDL_GetError());
}

Image::~Image()
{
	if(m_Surface)
	{
		SDL_FreeSurface(m_Surface);
	}
}

bool Image::Load(std::string filename)
{
	DEBUG_ASSERT(!m_Surface);
	
	m_Surface = SDL_LoadBMP(filename.c_str());
	
	// Enable RLE to improve performance
	SDL_SetColorKey(m_Surface, SDL_RLEACCEL, 0);
	
	return (bool)(m_Surface != NULL);
}

Size Image::GetWidth() const
{
	DEBUG_ASSERT(m_Surface);
	
	return (Size)m_Surface->w;
}

Size Image::GetHeight() const
{
	DEBUG_ASSERT(m_Surface);
	
	return (Size)m_Surface->h;
}

void Image::SetAlpha(Byte alpha)
{
	DEBUG_ASSERT(m_Surface);
	
	SDL_SetAlpha(m_Surface, SDL_SRCALPHA | SDL_RLEACCEL, alpha);
}

void Image::SetAlpha(double alpha)
{
	DEBUG_ASSERT(m_Surface);
	DEBUG_ASSERT(alpha >= 0.0 && alpha <= 1.0);
	
	SDL_SetAlpha(m_Surface, SDL_SRCALPHA | SDL_RLEACCEL, (Byte)(alpha * 0xff));
}

void Image::SetPalette(const Palette& palette)
{
	DEBUG_ASSERT(m_Surface);
	DEBUG_ASSERT2(m_Surface->format->palette, "This method can only be called on a palettized surface.");
	
	SDL_SetColors(m_Surface, palette.m_Colors, 0, palette.m_NbColors);
}
