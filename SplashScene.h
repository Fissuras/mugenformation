/**
 * Splash scene.
 * 
 * @author Francis BISSON
 */

#ifndef TESTSCENE_H
#define TESTSCENE_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Image.h"
#include "Palette.h"
#include "Scene.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class SplashScene : public Scene
{
public:
					 SplashScene(Game* game);
	virtual			~SplashScene();
		
	virtual	bool	Init();
	virtual	void	Update(double deltaTime, double totalTime);
	virtual	void	Render(DisplayContext* displayContext);

protected:
	Image			m_Splash;
	double			m_StartTime;
	double			m_FadeOutStart;
	double			m_FadeOutDuration;
	Palette			m_FadeOutPalette;
	bool			m_PaletteChanged;
	
	double			m_SceneDisplayDuration;
};

#endif // TESTSCENE_H
