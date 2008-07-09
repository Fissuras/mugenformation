/**
 * Class that represents text to be drawn on the screen.
 * 
 * @author Francis BISSON
 */

#ifndef TEXT_H
#define TEXT_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include <boost/shared_ptr.hpp>
#include <string>

#include "Drawable.h"
#include "Font.h"
#include "Types.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class Text : public Drawable
{
	friend class	DisplayContext;

public:
					 Text();
					 Text(std::string text);
					 Text(FontPtr font);
					 Text(std::string text, FontPtr font);
	virtual			~Text();
	
	virtual	void	SetFont(FontPtr font);
	virtual	void	SetText(std::string text);
	
	Size			GetTextWidth() const;
	Size			GetTextHeight() const;
	
protected:
	std::string		m_String;
	FontPtr			m_Font;
};

// UTILITY TYPEDEFS ////////////////////////////////////////////////////////////
typedef boost::shared_ptr<Text>	TextPtr;

#endif // TEXT_H
