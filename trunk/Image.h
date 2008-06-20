/**
 * Base class for image resources.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>
#include <string>

#include "Point.h"
#include "Types.h"

// FORWARD DECLARATIONS ////////////////////////////////////////////////////////
class DisplayContext;

// CLASS DEFINITION/////////////////////////////////////////////////////////////
class Image
{
	friend class	DisplayContext;

public:
					 Image();
					 Image(std::string filename);
	virtual			~Image();
	
	virtual	bool	Load(std::string filename);
	
	void			MoveTo(Coord x, Coord y)		{ m_Position.MoveTo(x, y); }
	void			MoveTo(const Point& position)	{ m_Position.MoveTo(position); }
		
	void			MoveBy(Coord x, Coord y)		{ m_Position.MoveBy(x, y); }
	void			MoveBy(const Point& position)	{ m_Position.MoveBy(position); }
	
	Size			GetWidth()	const;
	Size			GetHeight()	const;
	
	Coord			GetX() const					{ return m_Position.GetX(); }
	Coord			GetY() const					{ return m_Position.GetY(); }
	Point			GetPosition() const				{ return m_Position; }

protected:
	SDL_Surface*	m_Surface;
	Point			m_Position;
};
