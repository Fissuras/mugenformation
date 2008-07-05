/**
 * Implementation of the VisibilityAnimation class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <algorithm>

#include "Animation.hpp"
#include "Rectangle.h"
#include "Types.h"
#include "Utility.h"
#include "VisibilityAnimation.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
VisibilityAnimation::VisibilityAnimation(const RectanglePtr& rectangle)
:Animation<bool>()
,m_Rectangle(rectangle)
{
}

VisibilityAnimation::~VisibilityAnimation()
{
}

void VisibilityAnimation::SetValue(const bool& visible)
{
	m_Rectangle->SetVisibility(visible);
}

bool VisibilityAnimation::BlendValues(const bool& current, const bool& next, double percentage)
{
	UNUSED(next);
	UNUSED(percentage);
	
	return current;
}
