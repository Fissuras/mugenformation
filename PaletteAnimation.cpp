/**
 * Implementation of the PaletteAnimation class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <algorithm>

#include "Animation.hpp"
#include "Debug.h"
#include "Image.h"
#include "Palette.h"
#include "PaletteAnimation.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
PaletteAnimation::PaletteAnimation(const ImagePtr& image)
:Animation<PalettePtr>()
,m_Image(image)
{
}

PaletteAnimation::~PaletteAnimation()
{
}

void PaletteAnimation::SetValue(const PalettePtr& palette)
{
	m_Image->SetPalette( palette );
}

PalettePtr PaletteAnimation::BlendValues(const PalettePtr& current, const PalettePtr& next, double percentage)
{
	DEBUG_ASSERT(current->GetNbColors() == next->GetNbColors());
	
	Byte nbColors = current->GetNbColors();
	PalettePtr blendedPalette( new Palette(nbColors) );
	for(Byte i=0; i<nbColors; ++i)
	{
		Color currentColor = current->GetColor(i);
		Color nextColor = next->GetColor(i);
		
		Byte red = BlendShade(currentColor.GetRed(), nextColor.GetRed(), percentage);
		Byte green = BlendShade(currentColor.GetGreen(), nextColor.GetGreen(), percentage);
		Byte blue = BlendShade(currentColor.GetBlue(), nextColor.GetBlue(), percentage);
		
		blendedPalette->SetColor(i, Color(red, green, blue));
	}
	
	return blendedPalette;
}

Byte PaletteAnimation::BlendShade(Byte currentShade, Byte nextShade, double percentage) const
{
	Byte maxShade = std::max(currentShade, nextShade);
	Byte minShade = std::min(currentShade, nextShade);
	
	Byte diff = (Byte)((maxShade - minShade) * percentage);
	
	return (minShade == currentShade ? currentShade + diff : currentShade - diff);
}
