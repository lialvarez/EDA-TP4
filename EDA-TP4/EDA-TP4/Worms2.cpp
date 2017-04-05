#include "Worms2.h"

Worms::Worms() :
	wormPos({ 960, 616 }), lookingRight(false), state(Still), frameCounter(0), gConstant(0.24), walkSpeed(27.0 / 50.0),
	jumpSpeedX((4.5) * cos((double)PI / 3.0)), jumpSpeedY((4.5) * sin((double)PI / 3.0)) {}

void Worms::startWalkPending()
{
	state = WalkPending;
	frameCounter = 0;
}

void Worms::continueWalkPending()
{

	if (frameCounter == 4)
	{
		state = Walking;
	}
	frameCounter++;
}

void Worms::stopWalkPending()
{
	state = Still;
}

void Worms::startWalking()
{
	state = Walking;
	frameCounter++;
}

void Worms::continueWalking()
{
	if (frameCounter == 49)
	{
		if (lookingRight && wormPos.getX() < 1212 - WORM_OFFSET_RIGHT)
		{
			wormPos.setX(wormPos.getX() + 27);
		}
		else if (!lookingRight && wormPos.getX() > 701 + WORM_OFFSET_LEFT)
		{
			wormPos.setX(wormPos.getX() - 27);
		}
		state = WalkPending;
		frameCounter = 0;
	}
	else
	{
		frameCounter++;
	}
	
}

void Worms::setWalkEnding()
{
	state = WalkEnding;
	frameCounter++;
}

void Worms::continueWalkEnding()
{
	if (frameCounter == 49)
	{
		if (lookingRight && wormPos.getX() < 1212 - WORM_OFFSET_RIGHT)
		{
			wormPos.setX(wormPos.getX() + 27);
		}
		else if (!lookingRight && wormPos.getX() > 701 + WORM_OFFSET_LEFT)
		{
			wormPos.setX(wormPos.getX() - 27);
		}
		state = Still;
		frameCounter = 0;
	}
	frameCounter++;
}

void Worms::startJumping()
{
	jumpStartX = wormPos.getX();
	frameCounter = 0;
	state = JumpStarting;
}

void Worms::continueStartJumping()
{
	if (frameCounter == 4)
	{
		state = Jumping;
	}
	frameCounter++;
}

void Worms::continueJumping()
{
	if (wormPos.getY()  >= 616 && frameCounter > 5)
	{
		state = JumpEnding;
		frameCounter = 0;
	}
	else
	{
		if (lookingRight && wormPos.getX() < 1212 - WORM_OFFSET_RIGHT)
		{
			wormPos.setX(jumpStartX + jumpSpeedX * (frameCounter - 4));
		}
		if (!lookingRight && wormPos.getX() > 701 + WORM_OFFSET_LEFT)
		{
			wormPos.setX(jumpStartX - jumpSpeedX * (frameCounter - 4));
		}
		wormPos.setY(616 + (gConstant  * (frameCounter - 4) * (frameCounter - 4) * 0.5 - jumpSpeedY * (frameCounter - 4)));
		frameCounter++;
	}
}

void Worms::continueJumpEnding()
{
	if (frameCounter == 4)
	{
		state = Still;
	}
	frameCounter++;
}

void Worms::setLookingRight(bool _lookingRight)
{
	lookingRight = _lookingRight;
}

bool Worms::getLookingRight()
{
	return lookingRight;
}

unsigned int Worms::getFrameCounter()
{
	return frameCounter;
}

Position Worms::getWormPosition()
{
	return wormPos;
}

wormState Worms::getWormState()
{
	return state;
}