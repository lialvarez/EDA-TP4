#pragma once

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
	bool isFacingRight;
	wormstate wormsIsDoing;
	unsigned frameCount;
	double gConstant = 0.24;
	const double speed = (24 / 50);
	const double speedX = (24 / 50) * cos(PI/3);
	const double speedY = (24 / 50) * sin(PI/3);

};