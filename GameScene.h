/**
 * Game scene.
 * 
 * @author Francis BISSON
 */

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Font.h"
#include "Player.h"
#include "Scene.h"
#include "Text.h"

// FORWARD DECLARATIONS ////////////////////////////////////////////////////////
class DisplayContext;
class Game;

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class GameScene : public Scene
{
public:
					 GameScene(Game* game);
	virtual			~GameScene();
	
	virtual	bool	Init();
	virtual void	Update(double deltaTime, double totalTime);
	virtual	void	Render(DisplayContext* displayContext);

protected:
	PlayerPtr		m_Player;
	
	FontPtr			m_Font;
	Text			m_FPS;
};
