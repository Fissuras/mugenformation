/**
 * Implementation of the ShapeAnimation class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <algorithm>

#include "Animation.hpp"
#include "Rectangle.h"
#include "ShapeAnimation.h"
#include "Types.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
ShapeAnimation::ShapeAnimation(const RectanglePtr& rectangle)
:Animation<Rectangle>()
,m_Rectangle(rectangle)
{
}

ShapeAnimation::~ShapeAnimation()
{
}

void ShapeAnimation::SetValue(const Rectangle& rectangle)
{
	m_Rectangle->MoveTo(rectangle.GetPosition());
	m_Rectangle->ResizeTo(rectangle.GetWidth(), rectangle.GetHeight());
}

Rectangle ShapeAnimation::BlendValues(const Rectangle& current, const Rectangle& next, double percentage)
{
	Coord maxX = std::max(current.GetX(), next.GetX());
	Coord minX = std::min(current.GetX(), next.GetX());
	Coord diffX = (Coord)((maxX - minX) * percentage);
	//(minShade == currentShade ? currentShade + diff : currentShade - diff);
	Coord x = (minX == current.GetX() ? current.GetX() + diffX : current.GetX() - diffX);
	
	Coord maxY = std::max(current.GetY(), next.GetY());
	Coord minY = std::min(current.GetY(), next.GetY());
	Coord diffY = (Coord)((maxY - minY) * percentage);
	Coord y = (minY == current.GetY() ? current.GetY() + diffY : current.GetY() - diffY);
	
	Size w = (Size)((next.GetWidth() - current.GetWidth()) * percentage) + current.GetWidth();
	Size h = (Size)((next.GetHeight() - current.GetHeight()) * percentage) + current.GetHeight();
	
	return Rectangle(x, y, w, h);
}
