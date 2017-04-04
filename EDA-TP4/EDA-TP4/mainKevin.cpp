#include <iostream>
#include "Worms.h"
#include "graphics.h"
#include "Position.h"

#define FPS 50
using namespace std;

void main(void)
{
	Worms worm1, worm2;
	Graphics graph;
	key_e tecla;
	//key_e teclaOffset=Up_DOWN;

	do
	{
		cout << "WORMASTATA: " << worm1.getWormstate() << endl;
		cout << "POSX1: " << worm1.getPosition().getX() << endl;
		cout << "POSX2: " << worm2.getPosition().getX() << endl;
		graph.refreshScreen(worm1.getPosition(), worm1.getWormstate(), worm1.getIsFacingRight(), worm1.getFrameCount());
		graph.refreshScreen(worm2.getPosition(), worm2.getWormstate(), worm2.getIsFacingRight(), worm2.getFrameCount());
		tecla = D_DOWN;

		if (tecla != NO_CHAR)
		{
			if (tecla == A_UP)
				worm1.updateWormsPosition(Left_UP);
			else if(tecla == A_DOWN)
				worm1.updateWormsPosition(Left_DOWN);
			else if(tecla == W_UP)
				worm1.updateWormsPosition(Up_UP);
			else if(tecla == W_DOWN)
				worm1.updateWormsPosition(Up_DOWN); 
			else if(tecla == D_UP)
				worm1.updateWormsPosition(Right_UP); 
			else if(tecla == D_DOWN)
				worm1.updateWormsPosition(Right_DOWN);
			else if (tecla == Left_DOWN || tecla == Left_UP || tecla == Up_DOWN
				|| tecla == Up_UP || tecla == Right_DOWN || tecla == Right_UP)
				worm2.updateWormsPosition(tecla);
		}
		
	} while (tecla != EXIT);

		return;
}