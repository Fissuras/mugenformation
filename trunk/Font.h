/**
 * Class that defines a bitmap font used to draw text.
 * 
 * @author Francis BISSON
 */

#ifndef FONT_H
#define FONT_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <string>

#include "Color.h"
#include "Image.h"
#include "Palette.h"
#include "Types.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Font
{
	friend class	DisplayContext;
	
public:
					 Font();
					 Font(std::string filename, const Color& color = Color::Black);
	virtual			~Font();
	
	virtual	bool	Load(std::string filename);
	virtual	void	SetColor(const Color& color);
	
	Size			GetCharacterWidth() const;
	Size			GetCharacterHeight() const;

protected:
	Image			m_FontImage;
	//Color			m_Color;
	Size			m_CharacterWidth;
	Size			m_CharacterHeight;
	Palette			m_Palette;
};

#endif // FONT_H
