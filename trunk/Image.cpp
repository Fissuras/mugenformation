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
	bool ret = Load(filename);
	(void)ret;
	
	DEBUG_ASSERT(ret);
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
