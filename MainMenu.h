/**
 * Main menu.
 * 
 * @author Francis BISSON
 */

#ifndef MAINMENU_H
#define MAINMENU_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Font.h"
#include "Point.hpp"
#include "Rectangle.h"
#include "Scene.h"
#include "ShapeAnimation.h"
#include "Text.h"
#include "VisibilityAnimation.h"

// FORWARD DECLARATIONS ////////////////////////////////////////////////////////
class DisplayContext;
class Game;

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class MainMenu : public Scene
{
public:
					 MainMenu(Game* game);
	virtual			~MainMenu();
	
	virtual	bool	Init();
	virtual void	Update(double deltaTime);
	virtual	void	Render(DisplayContext* displayContext);

protected:
	enum Items
	{
		ITEM_PLAY_GAME = 0,
		ITEM_OPTIONS,
		ITEM_QUIT,
		
		ITEM_QTY
	};
	
	FontPtr			m_Font;
	TextPtr			m_MenuElements[ITEM_QTY];
	Point			m_Positions[ITEM_QTY];
	Text			m_FocusText;
	int				m_FocusIndex;
	
	RectanglePtr	m_VerticalRect;
	RectanglePtr	m_HorizontalRect;
	
	ShapeAnimation	m_VerticalRectAnim;
	ShapeAnimation	m_HorizontalRectAnim;
	VisibilityAnimation	m_BlinkAnim;
};

#endif // FONT_H
