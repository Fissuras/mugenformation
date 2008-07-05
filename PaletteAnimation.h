/**
 * Class that defines the behavior for a palette animation.
 * 
 * @author Francis BISSON
 */

#ifndef PALETTEANIMATION_H
#define PALETTEANIMATION_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Animation.hpp"
#include "Image.h"
#include "Palette.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class PaletteAnimation : public Animation<PalettePtr>
{
public:
						 PaletteAnimation(const ImagePtr& image);
	virtual				~PaletteAnimation();

protected:
	virtual	void		SetValue(const PalettePtr& palette);
	virtual	PalettePtr	BlendValues(const PalettePtr& current, const PalettePtr& next, double percentage);
	Byte				BlendShade(Byte currentShade, Byte nextShade, double percentage) const;
	
	ImagePtr			m_Image;
};

#endif // PALETTEANIMATION_H
