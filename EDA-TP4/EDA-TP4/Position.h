#ifndef POSITION_H
#define POSITION_H

class Position
{
public:

	Position();
	Position(unsigned int _x, unsigned int _y);
	unsigned int getX();
	unsigned int getY();
	void setX(unsigned int _x);
	void setY(unsigned int _y);

private:

	unsigned int x;
	unsigned int y;

};

#endif // !POSITION_H


