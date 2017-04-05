#include "getKey.h"

bool inhibFlag[] = { true, true, true, true, true, true };
bool inhibPress1 = false;
bool inhibPress2 = false;
bool keyState[] = { false, false, false, false, false, false };
keyEvents keyEvent;

keyEvents getKey(ALLEGRO_EVENT *ev)
{
	if (((*ev)).type == ALLEGRO_EVENT_TIMER) 
	{
		keyEvent = NO_KEY;
		//cout << "NADA" << endl;
	}
	else if (((*ev)).type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (!inhibPress1)
		{
			switch ((*ev).keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				inhibPress1 = true;
				inhibFlag[KEY_UP] = false;
				keyState[KEY_UP] = true;
				keyEvent = KEY_UP_DOWN;
				//cout << "KEY_UP Pressed" << endl;
				break;

			case ALLEGRO_KEY_LEFT:
				inhibPress1 = true;
				inhibFlag[KEY_LEFT] = false;
				keyState[KEY_LEFT] = true;
				keyEvent = KEY_LEFT_DOWN;
				//cout << "KEY_LEFT Pressed" << endl;
				break;

			case ALLEGRO_KEY_RIGHT:
				inhibPress1 = true;
				inhibFlag[KEY_RIGHT] = false;
				keyState[KEY_RIGHT] = true;
				keyEvent = KEY_RIGHT_DOWN;
				//cout << "KEY_RIGHT Pressed" << endl;
				break;

			default:
				break;

			}
		}
		if (!inhibPress2)
		{
			switch ((*ev).keyboard.keycode)
			{

			case ALLEGRO_KEY_W:
				inhibPress2 = true;
				inhibFlag[KEY_W] = false;
				keyState[KEY_W] = true;
				keyEvent = KEY_W_DOWN;
				//cout << "KEY_W Pressed" << endl;
				break;

			case ALLEGRO_KEY_A:
				inhibPress2 = true;
				inhibFlag[KEY_A] = false;
				keyState[KEY_A] = true;
				keyEvent = KEY_A_DOWN;
				//cout << "KEY_A Pressed" << endl;
				break;

			case ALLEGRO_KEY_D:
				inhibPress2 = true;
				inhibFlag[KEY_D] = false;
				keyState[KEY_D] = true;
				keyEvent = KEY_D_DOWN;
				//cout << "KEY_D Pressed" << endl;
				break;

			default:
				break;
			}
		}

	}
	else if ((*ev).type == ALLEGRO_EVENT_KEY_UP)
	{
		switch ((*ev).keyboard.keycode)
		{
		case ALLEGRO_KEY_UP:
			if (!inhibFlag[KEY_UP])
			{
				inhibFlag[KEY_UP] = true;
				keyState[KEY_UP] = false;
				keyEvent = KEY_UP_UP;
				//cout << "KEY_UP Released" << endl;
				inhibPress1 = false;
			}
			break;

		case ALLEGRO_KEY_LEFT:
			if (!inhibFlag[KEY_LEFT])
			{
				inhibFlag[KEY_LEFT] = true;
				keyState[KEY_LEFT] = false;
				keyEvent = KEY_LEFT_UP;
				//cout << "KEY_LEFT Released" << endl;
				inhibPress1 = false;
			}
			break;

		case ALLEGRO_KEY_RIGHT:
			if (!inhibFlag[KEY_RIGHT])
			{
				inhibFlag[KEY_RIGHT] = true;
				keyState[KEY_RIGHT] = false;
				keyEvent = KEY_RIGHT_UP;
				//cout << "KEY_RIGHT Released" << endl;
				inhibPress1 = false;
			}
			break;

		case ALLEGRO_KEY_W:
			if (!inhibFlag[KEY_W])
			{
				inhibFlag[KEY_W] = true;
				keyState[KEY_W] = false;
				keyEvent = KEY_W_UP;
				//cout << "KEY_W Released" << endl;
				inhibPress2 = false;
			}
			break;

		case ALLEGRO_KEY_A:
			if (!inhibFlag[KEY_A])
			{
				inhibFlag[KEY_A] = true;
				keyState[KEY_A] = false;
				keyEvent = KEY_A_UP;
				//cout << "KEY_A Released" << endl;
				inhibPress2 = false;
			}
			break;

		case ALLEGRO_KEY_D:
			if (!inhibFlag[KEY_D])
			{
				inhibFlag[KEY_D] = true;
				keyState[KEY_D] = false;
				keyEvent = KEY_D_UP;
				//cout << "KEY_D Released" << endl;
				inhibPress2 = false;
			}
			break;

		default:
			break;
		}
	}
	else if ((*ev).type == ALLEGRO_EVENT_DISPLAY_CLOSE || (*ev).keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
		return QUIT;
	}
	return keyEvent;

}

