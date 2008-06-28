/**
 * Implementation of the Rectangle class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Point.h"
#include "Rectangle.h"
#include "Types.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Rectangle::Rectangle()
:m_Position(0, 0)
,m_Width(0)
,m_Height(0)
{
}

Rectangle::Rectangle(const Point& position, Size width, Size height)
:m_Position(position)
,m_Width(width)
,m_Height(height)
{
}

Rectangle::Rectangle(Coord x, Coord y, Size width, Size height)
:m_Position(x, y)
,m_Width(width)
,m_Height(height)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::ResizeTo(Size width, Size height)
{
	m_Width = width;
	m_Height = height;
}

void Rectangle::ResizeBy(Size width, Size height)
{
	m_Width += width;
	m_Height += height;
}

void Rectangle::ResizeBy(double xFactor, double yFactor)
{
	m_Width  = (Size)(m_Width  * xFactor);
	m_Height = (Size)(m_Height * yFactor);
}
