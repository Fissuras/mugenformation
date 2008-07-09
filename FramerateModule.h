/**
 * Module that limits the framerate to a target rate.
 * 
 * @author Francis BISSON
 */

#ifndef FRAMERATEMODULE_H
#define FRAMERATEMODULE_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Font.h"
#include "GameObject.h"
#include "Text.h"

// FORWARD DECLARATIONS ////////////////////////////////////////////////////////
class DisplayContext;
class Game;

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class FramerateModule : public GameObject
{
public:
					 FramerateModule(Game* game, unsigned long targetFps);
	virtual			~FramerateModule();
	
	virtual	bool	Init();
	virtual	void	Update(double deltaTime, double totalTime);
	virtual	void	Render(DisplayContext* displayContext);
	
	void			LimitFramerate();

protected:
	unsigned long	m_FrameCount;
	double			m_Time;
	double			m_FrameTime;
	unsigned long	m_TargetFps;
	
#ifndef NDEBUG
	FontPtr			m_Font;
	Text			m_FPS;
#endif
};

#endif // FRAMERATEMODULE_H
