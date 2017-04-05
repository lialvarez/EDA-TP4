#include <allegro5/allegro.h>
#include "Graphics.h"
#include "Worms2.h"
#include "getKey.h"
#include "dispatch.h"
#include <iostream>

using namespace std;

const float FPS = 40;

int main()
{
	ALLEGRO_EVENT ev;
	ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	keyEvents keyEv;
	Graphics g;
	Worms *worm = new Worms[2];
	

	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	eventQueue = al_create_event_queue();
	if (!eventQueue) {
		fprintf(stderr, "failed to create eventQueue!\n");
		al_destroy_display(g.getDisplay());
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(eventQueue, al_get_display_event_source(g.getDisplay()));

	al_register_event_source(eventQueue, al_get_timer_event_source(timer));

	al_register_event_source(eventQueue, al_get_keyboard_event_source());

	al_start_timer(timer);

	do
	{
		keyEv = NO_KEY;
		al_wait_for_event(eventQueue, &ev);
		keyEv = getKey(&ev);
		g.auxRefresh();
		for (unsigned int i = 0; i < 2; i++)
		{
			g.refreshScreen(worm[i].getWormPosition(), worm[i].getWormState(), worm[i].getLookingRight(), worm[i].getFrameCounter());
		}
		al_flip_display();
		//Solo para debug.
		if (keyEv != NO_KEY)
		{
			dispatch(keyEv, worm);
			switch (keyEv)
			{
			case KEY_UP_DOWN:
				cout << "KEY_UP Pressed" << endl;
				break;
			case KEY_RIGHT_DOWN:
				cout << "KEY_RIGHT Pressed" << endl;
				break;
			case KEY_LEFT_DOWN:
				cout << "KEY_LEFT Pressed" << endl;
				break;
			case KEY_UP_UP:
				cout << "KEY_UP Released" << endl;
				break;
			case KEY_RIGHT_UP:
				cout << "KEY_RIGHT Released" << endl;
				break;
			case KEY_LEFT_UP:
				cout << "KEY_LEFT Released" << endl;
				break;
			case KEY_W_DOWN:
				cout << "KEY_W Pressed" << endl;
				break;
			case KEY_A_DOWN:
				cout << "KEY_A Pressed" << endl;
				break;
			case KEY_D_DOWN:
				cout << "KEY_D Pressed" << endl;
				break;
			case KEY_W_UP:
				cout << "KEY_W Released" << endl;
				break;
			case KEY_A_UP:
				cout << "KEY_A Released" << endl;
				break;
			case KEY_D_UP:
				cout << "KEY_D Released" << endl;
				break;
			default:
				break;
			}
		}
		if (keyEv == NO_KEY)
		{
			cout << "NADA" << endl;
		}
		for (unsigned int i = 0; i < 2; i++)
		{
			switch (worm[i].getWormState())
			{
			case WalkPending:
				worm[i].continueWalkPending();
				break;

			case Walking:
				worm[i].continueWalking();
				break;

			case WalkEnding:
				worm[i].continueWalkEnding();
				break;

			case JumpStarting:
				worm[i].continueStartJumping();
				break;

			case Jumping:
				worm[i].continueJumping();
				break;

			case JumpEnding:
				worm[i].continueJumpEnding();
			default:
				break;
			}
		}
	} while (keyEv != QUIT);
		
	al_destroy_timer(timer);
	al_destroy_display(g.getDisplay());
	al_destroy_event_queue(eventQueue);

	return 0;
}