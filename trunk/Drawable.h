/**
 * Abstract base class for all drawable objects.
 * 
 * @author Francis BISSON
 */

#ifndef DRAWABLE_H
#define DRAWABLE_H

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Drawable
{
public:
						 Drawable();
	virtual				~Drawable() = 0;

	bool				IsVisible() const			{ return m_IsVisible; }
	void				SetVisibility(bool visible)	{ m_IsVisible = visible; }

protected:
	bool				m_IsVisible;
};

#endif // DRAWABLE_H
