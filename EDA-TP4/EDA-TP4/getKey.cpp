#include <allegro5/allegro.h>
#include "Graphics.h"
#include "Worms.h"
#include <iostream>

using namespace std;

const float FPS = 50;

int main(int argc, char **argv) {

//	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	bool redraw = true;
	typedef enum {KEY_UP, KEY_LEFT, KEY_RIGHT, KEY_W, KEY_A, KEY_D};
	bool inhibFlag[] = { true, true, true, true, true, true };
	bool inhibPress1 = false;
	bool inhibPress2 = false;
	bool keyState[] = { false, false, false, false, false, false };
	unsigned int keyEvent;


	Worms worm1;
	Worms worm2;
	Graphics g;

	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(g.getDisplay());
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(g.getDisplay()));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	while (true)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			keyEvent = NO_CHAR;
			cout << "NADA" << endl;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (!inhibPress1)
			{
				switch (ev.keyboard.keycode)
				{
				case ALLEGRO_KEY_UP:
					inhibPress1 = true;
					inhibFlag[KEY_UP] = false;
					keyState[KEY_UP] = true;
					keyEvent = Up_DOWN;
					cout << "KEY_UP Pressed" << endl;
					break;

				case ALLEGRO_KEY_LEFT:
					inhibPress1 = true;
					inhibFlag[KEY_LEFT] = false;
					keyState[KEY_LEFT] = true;
					keyEvent = Left_DOWN;
					cout << "KEY_LEFT Pressed" << endl;
					break;

				case ALLEGRO_KEY_RIGHT:
					inhibPress1 = true;
					inhibFlag[KEY_RIGHT] = false;
					keyState[KEY_RIGHT] = true;
					keyEvent = Right_DOWN;
					cout << "KEY_RIGHT Pressed" << endl;
					break;

				default:
					break;

				}
			}
			if (!inhibPress2)
			{
				switch (ev.keyboard.keycode)
				{

				case ALLEGRO_KEY_W:
					inhibPress2 = true;
					inhibFlag[KEY_W] = false;
					keyState[KEY_W] = true;
					keyEvent = W_DOWN;
					cout << "KEY_W Pressed" << endl;
					break;

				case ALLEGRO_KEY_A:
					inhibPress2 = true;
					inhibFlag[KEY_A] = false;
					keyState[KEY_A] = true;
					keyEvent = A_DOWN;
					cout << "KEY_A Pressed" << endl;
					break;

				case ALLEGRO_KEY_D:
					inhibPress2 = true;
					inhibFlag[KEY_D] = false;
					keyState[KEY_D] = true;
					keyEvent = D_DOWN;
					cout << "KEY_D Pressed" << endl;
					break;

				default:
					break;
				}
			}

		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				if (!inhibFlag[KEY_UP])
				{
					inhibFlag[KEY_UP] = true;
					keyState[KEY_UP] = false;
					keyEvent = Up_UP;
					cout << "KEY_UP Released" << endl;
					inhibPress1 = false;
				}
				break;

			case ALLEGRO_KEY_LEFT:
				if (!inhibFlag[KEY_LEFT])
				{
					inhibFlag[KEY_LEFT] = true;
					keyState[KEY_LEFT] = false;
					keyEvent = Left_UP;
					cout << "KEY_LEFT Released" << endl;
					inhibPress1 = false;
				}
				break;

			case ALLEGRO_KEY_RIGHT:
				if (!inhibFlag[KEY_RIGHT])
				{
					inhibFlag[KEY_RIGHT] = true;
					keyState[KEY_RIGHT] = false;
					keyEvent = Right_UP;
					cout << "KEY_RIGHT Released" << endl;
					inhibPress1 = false;
				}
				break;

			case ALLEGRO_KEY_W:
				if (!inhibFlag[KEY_W])
				{
					inhibFlag[KEY_W] = true;
					keyState[KEY_W] = false;
					keyEvent = W_UP;
					cout << "KEY_W Released" << endl;
					inhibPress2 = false;
				}
				break;

			case ALLEGRO_KEY_A:
				if (!inhibFlag[KEY_A])
				{
					inhibFlag[KEY_A] = true;
					keyState[KEY_A] = false;
					keyEvent = A_UP;
					cout << "KEY_A Released" << endl;
					inhibPress2 = false;
				}
				break;

			case ALLEGRO_KEY_D:
				if (!inhibFlag[KEY_D])
				{
					inhibFlag[KEY_D] = true;
					keyState[KEY_D] = false;
					keyEvent = D_UP;
					cout << "KEY_D Released" << endl;
					inhibPress2 = false;
				}
				break;

			default:
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE || ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
			break;
		}

		g.refreshScreen(worm1.getPosition(), worm1.getWormstate(), worm1.getIsFacingRight(), worm1.get)
		
		if (keyEvent <= 5 && keyEvent != NO_CHAR)
		{
			worm1.updateWormsPosition(keyEvent);
		}
		if (keyEvent > 5 && keyEvent <= 11)
		{
			worm2.updateWormsPosition(keyEvent-6);
		}
		if (keyEvent == NO_CHAR)
		{
			worm1.updateWormsPosition(keyEvent);
			worm2.updateWormsPosition(keyEvent);
		}
	}
	al_destroy_timer(timer);
	al_destroy_display(g.getDisplay());
	al_destroy_event_queue(event_queue);

	return 0;
}