#ifndef WORMS_H
#define WORMS_H

#include <math.h>
#include "Position.h"

#define PI 3.141592
#define WORM_OFFSET_RIGHT 28
#define WORM_OFFSET_LEFT  17

typedef enum { Still, WalkPending, Walking, WalkEnding, JumpStarting, Jumping, JumpEnding } wormState;

class Worms
{
public:

	Worms();

	wormState getWormState();
	Position getWormPosition();
	unsigned int getFrameCounter();
	bool getLookingRight();

	void startWalkPending();	
	void continueWalkPending();	
	void stopWalkPending();		
	void startWalking();		
	void continueWalking();
	void setWalkEnding();
	void continueWalkEnding();

	void startJumping();
	void continueStartJumping();
	void continueJumping();
	void continueJumpEnding();
	
	void setLookingRight(bool _lookingRight);

private:

	double gConstant;
	const double walkSpeed;
	const double jumpSpeedX;
	double jumpSpeedY;
	double jumpStartX;

	bool lookingRight;
	unsigned int frameCounter;
	wormState state;
	Position wormPos;

};


#endif // !WORMS_H
