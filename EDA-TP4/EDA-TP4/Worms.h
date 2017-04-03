#pragma once
#include "Position.h"
#include "graphics.h"
#define PI 3.14159265358979

typedef enum {Still, WalkPending, Walking, Jumping, WalkEnding, JumpEnding} wormstate;



class Worms
{
public:
	Worms();

	void walk();
	void jump();

	void startJump();
	void startWalk();
	void keepMoving();
	void stopJump();
	void stopWalk();

	Position getPosition();
	wormstate getWormstate();
	unsigned getFrameCount();
	bool getIsFacingRight();

private:
	Position _Pos;
	bool _isFacingRight;
	wormstate _wormsIsDoing;
	unsigned _frameCount;
	double _gConstant;
	const double _speed;
	const double _speedX;
	 double _speedY;

};