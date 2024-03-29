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
#include "Image.h"
#include "Point.hpp"
#include "Rectangle.h"
#include "Text.h"
#include "Types.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class DisplayContext
{
public:
					DisplayContext();
	virtual			~DisplayContext();

	virtual	bool	Init(Size screenWidth, Size screenHeight, bool fullscreen = false);

	virtual	void	Flip();

	virtual void	SetColor(const Color& color);
	
	virtual	void	ClearScreen();

	virtual	void	DrawRectangle(Coord x, Coord y, Size width, Size height, bool filled = true);
	virtual	void	DrawRectangle(const Point& position, Size width, Size height, bool filled = true);
	virtual	void	DrawRectangle(const Rectangle& rectangle, bool filled = true);

	virtual	void	DrawImage(const Image& image, const Point& position);
	virtual	void	DrawImage(const Image& image, const Point& position, const Rectangle& clippingMask);
	
	virtual	void	DrawText(const Text& text, const Point& position);
	
	Size			GetWidth() const	{ return m_ScreenWidth; }
	Size			GetHeight() const	{ return m_ScreenHeight; }

private:
	virtual	void	FillRectangle(Coord x, Coord y, Size width, Size height);
	
	SDL_Surface*	m_Screen;
	Uint32			m_Color;
	
	Size			m_ScreenWidth;
	Size			m_ScreenHeight;
};

#endif // DISPLAYCONTEXT_H
