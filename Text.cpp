/**
 * Implementation of the Text class.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <string>

#include "Drawable.h"
#include "Font.h"
#include "Text.h"
#include "Types.h"

// IMPLEMENTATION //////////////////////////////////////////////////////////////
Text::Text()
:Drawable()
{
}

Text::Text(std::string text)
:Drawable()
,m_String(text)
{
}

Text::Text(FontPtr font)
:Drawable()
,m_Font(font)
{
}

Text::Text(std::string text, FontPtr font)
:Drawable()
,m_String(text)
,m_Font(font)
{
}

Text::~Text()
{
}

void Text::SetFont(FontPtr font)
{
	m_Font = font;
}

void Text::SetText(std::string text)
{
	m_String = text;
}

Size Text::GetTextWidth() const
{
	return (Size)(m_String.length() * m_Font->GetCharacterWidth());
}

Size Text::GetTextHeight() const
{
	// TODO Count number of lines in the string
	return m_Font->GetCharacterHeight();
}
