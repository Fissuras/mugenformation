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
,m_Alpha(0xff)
{
}

Color::Color(Byte r, Byte g, Byte b, Byte a)
:m_Red(r)
,m_Green(g)
,m_Blue(b)
,m_Alpha(a)
{
}

Color::Color(int hexCode, Byte alpha)
{
	Byte mask = 0xff;
	
	m_Red	= (Byte)(mask & (hexCode >> 16));
	m_Green	= (Byte)(mask & (hexCode >> 8));
	m_Blue	= (Byte)(mask &  hexCode);
	
	m_Alpha	= alpha;
}

Color::~Color()
{
}

void Color::SetAlpha(double alpha)
{
	DEBUG_ASSERT(alpha >= 0.0 && alpha <= 1.0);
	
	m_Alpha = (Byte)(alpha * 0xff);
}
