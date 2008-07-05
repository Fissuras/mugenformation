/**
 * Base class for image resources.
 * 
 * @author Francis BISSON
 */

#ifndef IMAGE_H
#define IMAGE_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <boost/shared_ptr.hpp>
#include <string>
#include <SDL/SDL.h>

#include "Drawable.h"
#include "Palette.h"
#include "Types.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Image : public Drawable
{
	friend class	DisplayContext;

public:
					 Image();
					 Image(std::string filename);
					 Image(const Image& image);
	virtual			~Image();
	
	Image&			operator= (const Image& image);
	
	virtual	bool	Load(std::string filename);
	virtual	bool	IsLoaded() const				{ return m_Surface != NULL; }
	
	Size			GetWidth()	const;
	Size			GetHeight()	const;
	
	virtual	void	SetAlpha(Byte alpha);
	virtual	void	SetAlpha(double alpha);
	
	virtual	void	SetPalette(PalettePtr palette);
	virtual	void	SetTransparencyColor(const Color& color);

protected:
	SDL_Surface*	m_Surface;
	std::string		m_Filename;
};

// UTILITY TYPEDEFS ////////////////////////////////////////////////////////////
typedef boost::shared_ptr<Image>	ImagePtr;

#endif // IMAGE_H
