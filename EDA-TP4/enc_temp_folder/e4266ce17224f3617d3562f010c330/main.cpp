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
	Position p;
	bool faceRight = false;
	p.setX(1212);
	p.setY(616);

	do
	{
		for (unsigned int frame = 0; frame < 50; frame++)
		{
			g.refreshScreen(p, 2, faceRight, frame);
			al_rest(0.02);
		}
		p.setX(p.getX() - 27);
	} while (p.getX() > 701);

	getchar();
	return 0;
}

