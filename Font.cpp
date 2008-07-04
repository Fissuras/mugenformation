/**
 * Implementation of the Font class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <string>

#include "Color.h"
#include "Debug.h"
#include "Font.h"
#include "Image.h"
#include "Palette.h"
#include "Types.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Font::Font()
:m_CharacterWidth(0)
,m_CharacterHeight(0)
,m_Palette( new Palette(2) )
{
}

Font::Font(std::string filename, const Color& color)
:m_CharacterWidth(0)
,m_CharacterHeight(0)
,m_Palette( new Palette(2) )
{
	Load(filename);
	SetColor(color);
}

Font::~Font()
{
}

bool Font::Load(std::string filename)
{
	if(!m_FontImage.Load(filename))
	{
		return false;
	}
	
	// TODO Load font configuration from a file instead
	int nbCharacters = '~' - '!';
	m_CharacterWidth = m_FontImage.GetWidth() / nbCharacters;
	m_CharacterHeight = m_FontImage.GetHeight();
	
	return true;
}

void Font::SetColor(const Color& color)
{
	DEBUG_ASSERT(m_FontImage.IsLoaded());
	
	Color transparency(0xff, 0x00, 0xff);
	
	m_Palette->SetColor(0, color);
	m_Palette->SetColor(1, transparency);
	
	m_FontImage.SetPalette(m_Palette);
	m_FontImage.SetTransparencyColor(transparency);
}

Size Font::GetCharacterWidth() const
{
	DEBUG_ASSERT(m_FontImage.IsLoaded());
	
	return m_CharacterWidth;
}

Size Font::GetCharacterHeight() const
{
	DEBUG_ASSERT(m_FontImage.IsLoaded());
	
	return m_CharacterHeight;
}
