/**
 * Scene that displays a splash image that fades out.
 * 
 * @author Francis BISSON
 */

#ifndef SPLASHSCENE_H
#define SPLASHSCENE_H

// INCLUDES ////////////////////////////////////////////////////////////////////
#include "Image.h"
#include "Palette.h"
#include "PaletteAnimation.h"
#include "Scene.h"

// CLASS DEFINITION ////////////////////////////////////////////////////////////
class SplashScene : public Scene
{
public:
						 SplashScene(Game* game);
	virtual				~SplashScene();
		
	virtual	bool		Init();
	virtual	void		Update(double deltaTime);
	virtual	void		Render(DisplayContext* displayContext);

protected:
	ImagePtr			m_Splash;
	PaletteAnimation	m_FadeOutAnim;
};

#endif // SPLASHSCENE_H
