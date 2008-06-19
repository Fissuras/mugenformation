/**
 * Class used to render any object on the screen.
 * 
 * @author Francis BISSON
 */

#ifndef DISPLAYCONTEXT_H
#define DISPLAYCONTEXT_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>

#include "Color.h"
#include "Point.h"
#include "Rectangle.h"
#include "Types.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class DisplayContext
{
public:
					DisplayContext();
	virtual			~DisplayContext();

	virtual	void	Init(Size screenWidth, Size screenHeight);

	virtual	void	Flip();

	virtual void	SetColor(const Color& color);

	virtual	void	DrawRectangle(Coord x, Coord y, Size width, Size height, bool filled = true);
	virtual	void	DrawRectangle(Point& position, Size width, Size height, bool filled = true);
	virtual	void	DrawRectangle(Rectangle& rectangle, bool filled = true);

//	virtual	void	DrawImage(Image& image, Coord x, Coord y);

private:
	virtual	void	FillRectangle(Coord x, Coord y, Size width, Size height);
	
	SDL_Surface*	m_Screen;
	Uint32			m_Color;
};

#endif // DISPLAYCONTEXT_H