/**
 * Implementation of the Color class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Color.h"
#include "Debug.h"
#include "Types.h"

// STATIC MEMBERS INITIALIZATION ///////////////////////////////////////////////
const Color Color::White( 0xff, 0xff, 0xff );
const Color Color::Black( 0x00, 0x00, 0x00 );
const Color Color::Red(   0xff, 0x00, 0x00 );
const Color Color::Green( 0x00, 0xff, 0x00 );
const Color Color::Blue ( 0x00, 0x00, 0xff );

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Color::Color()
:m_Red(0)
,m_Green(0)
,m_Blue(0)
{
}

Color::Color(Byte r, Byte g, Byte b)
:m_Red(r)
,m_Green(g)
,m_Blue(b)
{
}

Color::Color(int hexCode)
{
	Byte mask = 0xff;
	
	m_Red	= (Byte)(mask & (hexCode >> 16));
	m_Green	= (Byte)(mask & (hexCode >> 8));
	m_Blue	= (Byte)(mask &  hexCode);
}

Color::~Color()
{
}

bool Color::operator== (const Color& color) const
{
	return IsEqual(color);
}

bool Color::operator!= (const Color& color) const
{
	return !IsEqual(color);
}

bool Color::IsEqual(const Color& color) const
{
	return (color.m_Red == m_Red && color.m_Green == m_Green && color.m_Blue == m_Blue);
}
