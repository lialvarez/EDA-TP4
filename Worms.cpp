#include "Worms.h"
#include "Position.h"
#include "graphics.h"
#include <cmath>

Worms::Worms()
{
	_Pos.x = 701;
	_Pos.y = 616;


}

void Worms::walk()
{
	for (frameCount = 0; frameCount <= 50; frameCount++)
		_Pos.x += speed;
}

void Worms::jump()
{
	for (frameCount = 0; frameCount <= 50; frameCount++)
	{
		_Pos.x += speedX;
		_Pos.y += (speedY - gConstant*(pow(frameCount, 2))); 
	}
}

void Worms::startJump()
{

}

void Worms::startWalk()
{

}

void Worms::keepMoving()
{

}

void Worms::stopJump()
{

}

void Worms::stopWalk()
{

}

Position Worms::getPosition()
{
	return P;
}

wormstate Worms::getWormstate()
{
	return wormsIsDoing;
}

unsigned Worms::getFrameCount()
{
	return frameCount;
}

bool Worms::getIsFacingRight()
{
	return isFacingRight;
}


void main()
{

}