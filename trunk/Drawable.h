/**
 * Abstract base class for all drawable objects.
 * 
 * @author Francis BISSON
 */

#ifndef DRAWABLE_H
#define DRAWABLE_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <boost/shared_ptr.hpp>

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Drawable
{
public:
						 Drawable();
	virtual				~Drawable() = 0;

	bool				IsVisible() const	{ return m_IsVisible; }
	void				Show()				{ m_IsVisible = true; }
	void				Hide()				{ m_IsVisible = false; }

protected:
	bool				m_IsVisible;
};

// UTILITY TYPEDEFS ////////////////////////////////////////////////////////////
typedef boost::shared_ptr<Drawable>	DrawablePtr;

#endif // DRAWABLE_H
