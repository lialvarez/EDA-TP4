#pragma once
#include "Position.h"
#include "graphics.h"
#define PI 3.14159265358979

typedef enum {Still, WalkPending, Walking, Jumping, WalkEnding, JumpEnding} wormstate_e;

typedef enum {Left_UP, Left_DOWN, Right_UP, Right_DOWN, Up_UP, Up_DOWN,
A_UP, A_DOWN, W_UP, W_DOWN, D_UP, D_DOWN, NO_CHAR} key_e;

class Worms
{
public:
	Worms();

	//void walk();
	//void jump();

	void startJump();
	void startWalk();
	void keepMoving();
	void stopJump();
	void stopWalk();

	void updateWormsPosition(unsigned int tecla);

	Position getPosition();
	wormstate_e getWormstate();
	unsigned getFrameCount();
	bool getIsFacingRight();

private:
	Position _Pos;
	bool _isFacingRight;
	wormstate_e _wormIsDoing;
	unsigned _frameCount;
	double _gConstant;
	const int _walkDistance;
	const double _walkSpeed;
	const double _jumpSpeedX;
	 double _jumpSpeedY;

};