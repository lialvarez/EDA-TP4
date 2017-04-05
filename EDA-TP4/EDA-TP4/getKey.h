#ifndef GETKEY_H
#define GETKEY_H
#include <allegro5\allegro.h>
#include <iostream>

using namespace std;

typedef enum { KEY_UP, KEY_LEFT, KEY_RIGHT, KEY_W, KEY_A, KEY_D }keyList;
typedef enum { KEY_UP_DOWN, KEY_UP_UP, KEY_LEFT_DOWN, KEY_LEFT_UP, KEY_RIGHT_DOWN, KEY_RIGHT_UP, KEY_W_DOWN, KEY_W_UP, KEY_A_DOWN, KEY_A_UP, KEY_D_DOWN, KEY_D_UP, NO_KEY, QUIT }keyEvents;

keyEvents getKey(ALLEGRO_EVENT *ev);

#endif // !GETKEY_H
