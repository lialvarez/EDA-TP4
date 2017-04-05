#include <allegro5/allegro.h>
#include "Graphics.h"
#include "Worms2.h"
#include "getKey.h"
#include "dispatch.h"
#include <iostream>

using namespace std;

const float FPS = 50;

int main()
{
	ALLEGRO_EVENT ev;
	ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	keyEvents keyEv;
	Graphics g;
	Worms *worm = new Worms[2];
	bool auxFlag = true;
	

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
		if (keyEv != NO_KEY && auxFlag)
		{
			dispatch(keyEv, worm);
		}
		if (keyEv == NO_KEY)
		{
			auxFlag = true;
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
		}
		
		if (keyEv == KEY_A_DOWN || keyEv == KEY_W_DOWN || keyEv == KEY_D_DOWN || keyEv == KEY_LEFT_DOWN || keyEv == KEY_UP_DOWN || keyEv == KEY_RIGHT_DOWN)
		{
			auxFlag = false;
		}
	} while (keyEv != QUIT);
		
	al_destroy_timer(timer);
	al_destroy_display(g.getDisplay());
	al_destroy_event_queue(eventQueue);

	return 0;
}