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
:Point()
,m_Width(0)
,m_Height(0)
{
}

Rectangle::Rectangle(Point& position, Size width, Size height)
:Point(position)
,m_Width(width)
,m_Height(height)
{
}

Rectangle::Rectangle(Coord x, Coord y, Size width, Size height)
:Point(x, y)
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

Point Rectangle::GetPosition() const
{
	Point position(m_X, m_Y);
	return position;
}
