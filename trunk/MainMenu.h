/**
 * Main menu.
 * 
 * @author Francis BISSON
 */

#ifndef MAINMENU_H
#define MAINMENU_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Font.h"
#include "Point.h"
#include "Rectangle.h"
#include "Scene.h"
#include "Text.h"

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
	virtual void	Update(double deltaTime, double totalTime);
	virtual	void	Render(DisplayContext* displayContext);

protected:
	enum Items
	{
		ITEM_PLAY_GAME = 0,
		ITEM_OPTIONS,
		ITEM_QUIT,
		
		ITEM_QTY
	};
	
	Font			m_Font;
	Text			m_MenuElements[ITEM_QTY];
	Point			m_Positions[ITEM_QTY];
	Text			m_FocusText;
	int				m_FocusIndex;
	
	Rectangle		m_VerticalRect;
	Rectangle		m_HorizontalRect;
};

#endif // FONT_H
