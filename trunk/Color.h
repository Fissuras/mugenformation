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
			 Color(Byte r, Byte g, Byte b);
			 Color(int hexCode);
			~Color();

	void	SetRed(Byte r)		{ m_Red = r; }
	void	SetGreen(Byte g)	{ m_Green = g; }
	void	SetBlue(Byte b)		{ m_Blue = b; }

	Byte	GetRed() const		{ return m_Red; }
	Byte	GetGreen() const	{ return m_Green; }
	Byte	GetBlue() const		{ return m_Blue; }
	
	bool	operator== (const Color& color) const;
	bool	operator!= (const Color& color) const;
	
	static const Color	Black;
	static const Color	White;
	static const Color	Red;
	static const Color	Green;
	static const Color	Blue;

private:
	bool	IsEqual(const Color& color) const;
	Byte	m_Red;
	Byte	m_Green;
	Byte	m_Blue;
};

#endif // COLOR_H
