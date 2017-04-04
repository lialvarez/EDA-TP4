#include <stdio.h>
#include <allegro5/allegro.h>
void dispatch(ALLEGRO_EVENT &ev);
const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
bool key[4] = { false, false, false, false };
bool redraw = true;
bool doexit = false;

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;


	
	

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}




	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");

		return -1;
	}




	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");

		al_destroy_display(display);

		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	
		ALLEGRO_EVENT ev;


	do

	{

		bool evento = al_get_next_event(event_queue, &ev);



		if (!evento)

		{

			dispatch(ev);

		}

	}

	while (!doexit);
	
	
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;

}
	
	void dispatch(ALLEGRO_EVENT &ev)
	{

		


		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				printf("KEY UP PRESSED\n");
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;

				printf("KEY LEFT PRESSED\n");
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				printf("KEY RIGHT PRESSED\n");
				break;

				/*case ALLEGRO_KEY_RIGHT:
					key[KEY_RIGHT] = true;
					printf("KEY RIGHT PRESSED\n");
					break;
				case ALLEGRO_KEY_RIGHT:
					key[KEY_RIGHT] = true;
					printf("KEY RIGHT PRESSED\n");
					break;
				case ALLEGRO_KEY_A:
					key[KEY_RIGHT] = true;
					printf("KEY RIGHT PRESSED\n");
					break;
				}

				*/
			}
		}


		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				printf("KEY UP UP\n");
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				printf("KEY LEFT UP\n");
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				printf("KEY RIGHT UP\n");
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}
	}

	

		

			
	


	