/**
 * Class that defines the behavior for a shape-changing animation.
 * 
 * @author Francis BISSON
 */

#ifndef SHAPEANIMATION_H
#define SHAPEANIMATION_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Animation.hpp"
#include "Rectangle.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class ShapeAnimation : public Animation<Rectangle>
{
public:
						 ShapeAnimation(const RectanglePtr& rectangle);
	virtual				~ShapeAnimation();

protected:
	virtual	void		SetValue(const Rectangle& rectangle);
	virtual	Rectangle	BlendValues(const Rectangle& current, const Rectangle& next, double percentage);
	
	RectanglePtr		m_Rectangle;
};

#endif // SHAPEANIMATION_H
