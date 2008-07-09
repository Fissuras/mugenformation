/**
 * Implementation of the Point class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Point.h"
#include "Types.h"

// STATIC MEMBERS INITIALIZATION ///////////////////////////////////////////////
const Point Point::Zero(0, 0);

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Point::Point()
:m_X(0)
,m_Y(0)
{
}

Point::Point(Coord x, Coord y)
:m_X(x)
,m_Y(y)
{
}

Point::~Point()
{
}

void Point::MoveTo(Coord x, Coord y)
{
	m_X = x;
	m_Y = y;
}

void Point::MoveTo(const Point& position)
{
	m_X = position.m_X;
	m_Y = position.m_Y;
}

void Point::MoveBy(Coord x, Coord y)
{
	m_X += x;
	m_Y += y;
}
