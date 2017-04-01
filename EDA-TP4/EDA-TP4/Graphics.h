#ifndef GRAPHICS_H
#define GRAPHICS_H
#define WALKPICS	15
#define JUMPPICS	10

#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <allegro5\allegro.h>
#include <allegro5\display.h>
#include <allegro5\allegro_image.h>


class Graphics
{
public:

	Graphics();
	
private:

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *background = NULL;
	ALLEGRO_BITMAP *wormJump[JUMPPICS];
	ALLEGRO_BITMAP *wormWalk[WALKPICS];
	ALLEGRO_BITMAP *test = NULL;
	ALLEGRO_MONITOR_INFO monitorInfo;

	bool allegroState;

	bool initAllegro();
	void graphBackground();
};


#endif // !GRAPHICS_H
