#pragma once


#include <allegro5\allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_color.h>
#include<allegro5\allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define STAGE_X	1920 
#define STAGE_Y	696

class Graphics
{
public:
	Graphics();
	void graficarPelotitas();


private:
	ALLEGRO_DISPLAY * _display;

};