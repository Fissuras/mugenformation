/**
 * Utility class that represents a rectangle in 2D space.
 * 
 * @author Francis BISSON
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Point.h"
#include "Types.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Rectangle
{
public:
				 Rectangle();
				 Rectangle(const Point& position, Size width, Size height);
				 Rectangle(Coord x, Coord y, Size width, Size height);
	virtual		~Rectangle();
	
	void		MoveTo(Coord x, Coord y)		{ m_Position.MoveTo(x, y); }
	void		MoveTo(const Point& position)	{ m_Position.MoveTo(position); }
	
	void		MoveBy(Size x, Size y)			{ m_Position.MoveBy(x, y); }
	
	Coord		GetX() const					{ return m_Position.GetX(); }
	Coord		GetY() const					{ return m_Position.GetY(); }
	
	void		ResizeTo(Size width, Size height);
	
	void		ResizeBy(Size width, Size height);
	void		ResizeBy(double xFactor, double yFactor);
	
	Size		GetWidth() const				{ return m_Width; }
	Size		GetHeight() const				{ return m_Height; }
	
	Point		GetPosition() const				{ return m_Position; }

protected:
	Point		m_Position;
	Size		m_Width;
	Size		m_Height;
};

#endif // RECTANGLE_H
