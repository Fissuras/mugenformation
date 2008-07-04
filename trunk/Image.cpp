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
{
}

Image::Image(std::string filename)
:m_Surface(NULL)
,m_Filename(filename)
{
	Load(m_Filename);
}

Image::Image(const Image& image)
{
	m_Filename = image.m_Filename;
	
	/**
	 * FIXME Use Flyweight pattern to avoid loading the same image more than once
	 * 
	 * Use a reference counter to determine when to SDL_FreeSurface() ?
	 */
	Load(image.m_Filename);
}

Image::~Image()
{
	if(m_Surface)
	{
		SDL_FreeSurface(m_Surface);
	}
}

Image& Image::operator= (const Image& image)
{
	m_Filename = image.m_Filename;
	
	/**
	 * @see copy constructor Image::Image(const Image& image);
	 */
	Load(image.m_Filename);
	
	return *this;
}

bool Image::Load(std::string filename)
{
	DEBUG_ASSERT(!IsLoaded());
	
	m_Filename = filename;
	
	m_Surface = SDL_LoadBMP(m_Filename.c_str());
	
	// Enable RLE to improve performance
	SDL_SetColorKey(m_Surface, SDL_RLEACCEL, 0);
	
	DEBUG_ASSERT2(IsLoaded(), SDL_GetError());
	
	return (bool)(m_Surface != NULL);
}

Size Image::GetWidth() const
{
	DEBUG_ASSERT(IsLoaded());
	
	return (Size)m_Surface->w;
}

Size Image::GetHeight() const
{
	DEBUG_ASSERT(IsLoaded());
	
	return (Size)m_Surface->h;
}

void Image::SetAlpha(Byte alpha)
{
	DEBUG_ASSERT(IsLoaded());
	
	SDL_SetAlpha(m_Surface, SDL_SRCALPHA | SDL_RLEACCEL, alpha);
}

void Image::SetAlpha(double alpha)
{
	DEBUG_ASSERT(IsLoaded());
	DEBUG_ASSERT(alpha >= 0.0 && alpha <= 1.0);
	
	SDL_SetAlpha(m_Surface, SDL_SRCALPHA | SDL_RLEACCEL, (Byte)(alpha * 0xff));
}

void Image::SetPalette(PalettePtr palette)
{
	DEBUG_ASSERT(IsLoaded());
	DEBUG_ASSERT2(m_Surface->format->palette, "This method can only be called on a palettized surface.");
	
	SDL_SetColors(m_Surface, palette->m_Colors, 0, palette->GetNbColors());
}

void Image::SetTransparencyColor(const Color& color)
{
	DEBUG_ASSERT(IsLoaded());
	
	Uint32 sdlColor = SDL_MapRGB(m_Surface->format, color.GetRed(), color.GetGreen(), color.GetBlue());
	SDL_SetColorKey(m_Surface, SDL_SRCCOLORKEY | SDL_RLEACCEL, sdlColor);
}
