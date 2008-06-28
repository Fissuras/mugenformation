/**
 * Class that represents text to be drawn on the screen.
 * 
 * @author Francis BISSON
 */

#ifndef TEXT_H
#define TEXT_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <string>

#include "Types.h"

// FORWARD DECLARATIONS ////////////////////////////////////////////////////////
class Font;

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Text
{
	friend class	DisplayContext;

public:
					 Text();
					 Text(std::string text);
					 Text(Font* font);
					 Text(std::string text, Font* font);
	virtual			~Text();
	
	virtual	void	SetFont(Font* font);
	virtual	void	SetText(std::string text);
	
	Size			GetTextWidth() const;
	Size			GetTextHeight() const;
	
protected:
	std::string		m_String;
	Font*			m_Font;
};

#endif // TEXT_H
