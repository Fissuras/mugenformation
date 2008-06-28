/**
 * Utility class that represents a 2D coordinate.
 * 
 * @author Francis BISSON
 */

#ifndef POINT_H
#define POINT_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Types.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Point
{
public:
			 Point();
			 Point(Coord x, Coord y);
	virtual	~Point();

	void	MoveTo(Coord x, Coord y);
	void	MoveTo(const Point& position);
	
	void	MoveBy(Size x, Size y);
	
	Coord	GetX() const	{ return m_X; }
	Coord	GetY() const	{ return m_Y; }
	
	static const Point	Zero;

protected:
	Coord	m_X;
	Coord	m_Y;
};

#endif // POINT_H
