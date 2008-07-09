/**
 * Implementation of the VisibilityAnimation class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <algorithm>

#include "Animation.hpp"
#include "Drawable.h"
#include "Types.h"
#include "Utility.h"
#include "VisibilityAnimation.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
VisibilityAnimation::VisibilityAnimation()
:Animation<bool>()
{
}

VisibilityAnimation::~VisibilityAnimation()
{
}

void VisibilityAnimation::SetValue(const bool& visible)
{
	if(visible)
	{
		m_Drawable->Show();
	}
	else
	{
		m_Drawable->Hide();
	}
}

bool VisibilityAnimation::BlendValues(const bool& current, const bool& next, double percentage)
{
	UNUSED(next);
	UNUSED(percentage);
	
	return current;
}
