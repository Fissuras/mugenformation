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
#include "KeyFrame.hpp"
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

PalettePtr PaletteAnimation::BlendValues(const KeyFrameType& current, const KeyFrameType& next, double percentage)
{
	PalettePtr currentFramePalette = current.GetValue();
	PalettePtr nextFramePalette = next.GetValue();
	
	DEBUG_ASSERT(currentFramePalette->GetNbColors() == nextFramePalette->GetNbColors());
	
	Byte nbColors = currentFramePalette->GetNbColors();
	PalettePtr blendedPalette( new Palette(nbColors) );
	for(Byte i=0; i<nbColors; ++i)
	{
		Color currentColor = currentFramePalette->GetColor(i);
		Color nextColor = nextFramePalette->GetColor(i);
		
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
