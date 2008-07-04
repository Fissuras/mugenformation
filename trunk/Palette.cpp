/**
 * Implementation of the Palette class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <cstring>
#include <SDL/SDL.h>

#include "Color.h"
#include "Debug.h"
#include "Palette.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Palette::Palette()
:m_NbColors(0)
,m_Colors(NULL)
{
}

Palette::Palette(Byte nbColors)
:m_NbColors(nbColors)
{
	m_Colors = new SDL_Color[m_NbColors];
	memset(m_Colors, 0, m_NbColors * sizeof(SDL_Color));
}

Palette::Palette(Byte nbColors, Color* colors)
:m_NbColors(nbColors)
{
	m_Colors = new SDL_Color[m_NbColors];
	for(Byte i=0; i<m_NbColors; ++i)
	{
		m_Colors[i].r = colors[i].GetRed();
		m_Colors[i].g = colors[i].GetGreen();
		m_Colors[i].b = colors[i].GetBlue();
		m_Colors[i].unused = 0;
	}
}

Palette::Palette(const Palette& palette)
{
	m_NbColors = palette.m_NbColors;
	m_Colors = new SDL_Color[m_NbColors];
	for(Byte i=0; i<m_NbColors; ++i)
	{
		m_Colors[i] = palette.m_Colors[i];
	}
}

Palette::~Palette()
{
	delete[] m_Colors;
}

Palette& Palette::operator= (const Palette& palette)
{
	m_NbColors = palette.m_NbColors;
	m_Colors = new SDL_Color[m_NbColors];
	for(Byte i=0; i<m_NbColors; ++i)
	{
		m_Colors[i] = palette.m_Colors[i];
	}
	
	return *this;
}

Color Palette::GetColor(Byte index)
{
	DEBUG_ASSERT(m_Colors);
	DEBUG_ASSERT(index < m_NbColors);
	
	return Color(m_Colors[index].r, m_Colors[index].g, m_Colors[index].b);
}

void Palette::SetColor(Byte index, const Color& color)
{
	DEBUG_ASSERT(m_Colors);
	DEBUG_ASSERT(index < m_NbColors);
	
	m_Colors[index].r = color.GetRed();
	m_Colors[index].g = color.GetGreen();
	m_Colors[index].b = color.GetBlue();
	m_Colors[index].unused = 0;
}
