/**
 * Utility class that represents an image's palette.
 * 
 * @author Francis BISSON
 */

#ifndef PALETTE_H
#define PALETTE_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <boost/shared_ptr.hpp>
#include <SDL/SDL.h>

#include "Color.h"
#include "Types.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Palette
{
	friend class	Image;

public:
					 Palette();
					 Palette(Byte nbColors);
					 Palette(Byte nbColors, Color* colors);
					 Palette(const Palette& palette);
	virtual			~Palette();
	
	virtual	Palette& operator= (const Palette& palette);
	
	virtual Color	GetColor(Byte index);
	virtual	void	SetColor(Byte index, const Color& color);
	virtual	Byte	GetNbColors() const	{ return m_NbColors; }

protected:
	Byte			m_NbColors;
	
	// We use SDL_Color instead of Color to avoid an additional overhead when
	// changing an image's palette
	SDL_Color*		m_Colors; 
};

// UTILITY TYPEDEFS ////////////////////////////////////////////////////////////
typedef boost::shared_ptr<Palette>	PalettePtr;

#endif // PALETTE_H
