#include "Position.h"

Position::Position() {}

Position::Position(unsigned int _x, unsigned int _y)
{
	x = _x;
	y = _y;
}

unsigned int Position::getX()
{
	return x;
}

unsigned int Position::getY()
{
	return y;
}

void Position::setX(unsigned int _x)
{
	x = _x;
}

void Position::setY(unsigned int _y)
{
	y = _y;
}