/**
 * Utility class that represents a color to draw on the screen.
 * 
 * @author Francis BISSON
 */

#ifndef COLOR_H
#define COLOR_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Types.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Color
{
public:
			 Color();
			 Color(Byte r, Byte g, Byte b, Byte a = 0xff);
			 Color(int hexCode, Byte alpha = 0xff);
			~Color();

	void	SetRed(Byte r)		{ m_Red = r; }
	void	SetGreen(Byte g)	{ m_Green = g; }
	void	SetBlue(Byte b)		{ m_Blue = b; }
	void	SetAlpha(Byte a)	{ m_Alpha = a; }
	void	SetAlpha(double a);

	Byte	GetRed() const		{ return m_Red; }
	Byte	GetGreen() const	{ return m_Green; }
	Byte	GetBlue() const		{ return m_Blue; }
	Byte	GetAlpha() const	{ return m_Alpha; }
	
	static const Color	Black;
	static const Color	White;
	static const Color	Red;
	static const Color	Green;
	static const Color	Blue;

private:
	Byte	m_Red;
	Byte	m_Green;
	Byte	m_Blue;
	Byte	m_Alpha;
};

#endif // COLOR_H
