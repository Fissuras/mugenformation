/**
 * Class that defines the behavior for a visibility animation.
 * 
 * @author Francis BISSON
 */

#ifndef VISIBILITYANIMATION_H
#define VISIBILITYANIMATION_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Animation.hpp"
#include "Rectangle.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class VisibilityAnimation : public Animation<bool>
{
public:
					 VisibilityAnimation();
	virtual			~VisibilityAnimation();
	
	virtual	void	SetControlledObject(const DrawablePtr& drawable) { m_Drawable = drawable; }

protected:
	virtual	void	SetValue(const bool& visible);
	virtual	bool	BlendValues(const bool& current, const bool& next, double percentage);
	
	DrawablePtr		m_Drawable;
};

#endif // VISIBILITYANIMATION_H
