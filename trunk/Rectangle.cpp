/**
 * Implementation of the Rectangle class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Point.hpp"
#include "Rectangle.h"
#include "Types.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Rectangle::Rectangle()
:Drawable()
,m_Position(0, 0)
,m_Width(0)
,m_Height(0)
{
}

Rectangle::Rectangle(const Point& position, Size width, Size height)
:Drawable()
,m_Position(position)
,m_Width(width)
,m_Height(height)
{
}

Rectangle::Rectangle(Coord x, Coord y, Size width, Size height)
:Drawable()
,m_Position(x, y)
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

bool Rectangle::Contains(const Point& point) const
{
	if((point.GetX() >= GetX()) && (point.GetX() <= (GetX() + GetWidth())))
	{
		if((point.GetY() >= GetY()) && (point.GetY() <= (GetY() + GetHeight())))
		{
			return true;
		}
	}
	
	return false;
}

bool Rectangle::Contains(const Rectangle& rect) const
{
	if(((rect.GetX() + rect.GetWidth()) >= GetX()) && (rect.GetX() <= (GetX() + GetWidth())))
	{
		if(((rect.GetY() + rect.GetHeight()) >= GetY()) && (rect.GetY() <= (GetY() + GetHeight())))
		{
			return true;
		}
	}
	
	return false;
}

bool Rectangle::ContainsCompletely(const Rectangle& rect) const
{
	if((rect.GetX() >= GetX()) && ((rect.GetX() + rect.GetWidth()) <= (GetX() + GetWidth())))
	{
		if((rect.GetY() >= GetY()) && ((rect.GetY() + rect.GetHeight()) <= (GetY() + GetHeight())))
		{
			return true;
		}
	}
	
	return false;
}
