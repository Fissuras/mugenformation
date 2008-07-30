/**
 * Utility class that represents a 2D coordinate.
 * 
 * @author Francis BISSON
 */

#ifndef POINT_HPP
#define POINT_HPP

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Debug.h"
#include "Types.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
template<class T>
class TPoint
{
public:
			 TPoint();
			 TPoint(T x, T y);
	virtual	~TPoint();

	void	MoveTo(T x, T y);
	void	MoveTo(const TPoint<T>& position);
	
	void	MoveBy(T x, T y);
	
	T	GetX() const	{ return m_X; }
	T	GetY() const	{ return m_Y; }
	
	static const TPoint<T>	Zero;
	
	// Conversion operator
	template<class U>
	operator TPoint<U>() const
	{
		return TPoint<U>((U)m_X, (U)m_Y);
	}

protected:
	T	m_X;
	T	m_Y;
};

// STATIC MEMBERS INITIALIZATION ///////////////////////////////////////////////
template<class T>
const TPoint<T> TPoint<T>::Zero((T)0, (T)0);

// IMPLEMENTATION //////////////////////////////////////////////////////////////
template<class T>
TPoint<T>::TPoint()
:m_X(0)
,m_Y(0)
{
}

template<class T>
TPoint<T>::TPoint(T x, T y)
:m_X(x)
,m_Y(y)
{
}

template<class T>
TPoint<T>::~TPoint()
{
}

template<class T>
void TPoint<T>::MoveTo(T x, T y)
{
	m_X = x;
	m_Y = y;
}

template<class T>
void TPoint<T>::MoveTo(const TPoint<T>& position)
{
	m_X = position.m_X;
	m_Y = position.m_Y;
}

template<class T>
void TPoint<T>::MoveBy(T x, T y)
{
	m_X += x;
	m_Y += y;
}

// UTILITY TYPEDEFS ////////////////////////////////////////////////////////////
typedef TPoint<Coord>	Point;
typedef TPoint<double>	PrecisePoint;

#endif // POINT_HPP
