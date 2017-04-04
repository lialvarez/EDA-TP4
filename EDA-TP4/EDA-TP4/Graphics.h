#ifndef GRAPHICS_H
#define GRAPHICS_H


#include "Position.h"
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <allegro5\allegro.h>
#include <allegro5\display.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\color.h>

#define WALKPICS	15
#define JUMPPICS	10
#define X_OFFSET	-42
#define	Y_OFFSET	38

class Graphics
{
public:

	ALLEGRO_DISPLAY *getDisplay();
	void refreshScreen(Position _p, unsigned int _wormstate, bool _facingRight, unsigned int _frameCount);
	void auxRefresh();
	Graphics();
	
private:

	typedef enum { F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15 } imageIndex;
	typedef enum { Still, WalkPending, Walking, Jumping, WalkEnding, JumpEnding } wormstate;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_DISPLAY_MODE dispData;
	ALLEGRO_BITMAP *background = NULL;
	ALLEGRO_BITMAP *scaledBackground = NULL;
	ALLEGRO_BITMAP *wormJump[JUMPPICS];
	ALLEGRO_BITMAP *wormWalk[WALKPICS];
	ALLEGRO_BITMAP *test = NULL;
	ALLEGRO_BITMAP *auxiliar = NULL;
	ALLEGRO_MONITOR_INFO monitorInfo;

	float xRes;
	float yRes;

	bool allegroState;

	bool initAllegro();
	void drawBackground();
	void drawWorm(ALLEGRO_BITMAP *wormBitmap, Position p, bool inverted);
	void setDrawingPoint(Position& p, unsigned int frameCount, bool inverted);
};
#endif // !GRAPHICS_H
