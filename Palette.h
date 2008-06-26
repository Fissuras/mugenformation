/**
 * Utility class that represents an image's palette.
 * 
 * @author Francis BISSON
 */

#ifndef PALETTE_H
#define PALETTE_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <SDL/SDL.h>

#include "Color.h"
#include "Types.h"

// FORWARD DECLARATIONS ////////////////////////////////////////////////////////
class Image;

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Palette
{
	friend class	Image;

public:
					 Palette();
					 Palette(Byte nbColors);
					 Palette(Byte nbColors, Color* colors);
	virtual			~Palette();
	
	virtual Color	GetColor(Byte index);
	virtual	void	SetColor(Byte index, const Color& color);

protected:
	Byte			m_NbColors;
	
	// We use SDL_Color instead of Color to avoid an additional overhead when
	// changing an image's palette
	SDL_Color*		m_Colors; 
};

#endif // PALETTE_H
