#include "Position.h"
#include "Graphics.h"
#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\events.h>
#include <allegro5\keyboard.h>

int main()
{
	// PRUEBAS
	Graphics g;
	Position p(1000, 616);
	for (unsigned int frame = 0; frame < 50; frame++)
	{
		g.refreshScreen(p, 2, true, frame);
		al_rest(0.02);
	}
	getchar();
	return 0;
}

