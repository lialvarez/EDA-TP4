#include "Worms.h"
#include "graphics.h"
#include <cmath>
#include <iostream>


#define WORM_OFFSET_RIGHT 28
#define WORM_OFFSET_LEFT  17
Worms::Worms() : 	
	_Pos({960, 616, true}), _gConstant(0.24), _speed(27.0 / 50.0),
	_speedX((4.5) * cos((double)PI / 3.0)), _speedY((4.5) * sin((double)PI / 3.0)){}
 
void Worms::walk()
{
	Graphics g;
	
	for (int c = 0; c < 5; c++)
	{
		for (_frameCount = 1; _frameCount <= 50; _frameCount++)
		{
			if (_Pos.isFacingRight && _Pos.x<1212-WORM_OFFSET_RIGHT)
				_Pos.x = 1101+27*c + _speed*_frameCount;

			if (!_Pos.isFacingRight && _Pos.x>701+WORM_OFFSET_LEFT)
				_Pos.x = 800-27*c - _speed*_frameCount;


			std::cout << "posX:" << _Pos.x << std::endl;
			g.graficarPelotitas(_Pos, _Pos);
		}
	}
	
	return;
}

void Worms::jump()
{
	double dx = 0, dy = 0;
	Graphics g;

	for (int c = 0; c <= 6; c++)
	{
		
		
		_Pos.y = 616;
		for (_frameCount = 1; _frameCount <= 32; _frameCount++)
		{
			
			//dx += _speedX;

			std::cout << dx << std::endl;
			std::cout << "_:" << _speedX << std::endl;

			if (_Pos.isFacingRight && _Pos.x<1212 - WORM_OFFSET_RIGHT)
				_Pos.x = 1000+72*c + _speedX*_frameCount;

			if (!_Pos.isFacingRight && _Pos.x>701 + WORM_OFFSET_LEFT)
				_Pos.x = 900-72*c - _speedX*_frameCount;

		
			std::cout<<"ciclo:" << c << "." << _frameCount << "  POSX:" << _Pos.x << std::endl;
			
				
					std::cout << "y_:" << _speedX << std::endl;
			//dy += (_gConstant  *_frameCount * 0.5  - _speedY);
			std::cout << "   dY:" << dy << std::endl;
			_Pos.y = 616 + (_gConstant  *_frameCount *_frameCount * 0.5 - _speedY*_frameCount);
					std::cout << "     posisisisionY:" << _Pos.y << std::endl;
					std::cout << "     posisisisionX:" << _Pos.x << std::endl;
			g.graficarPelotitas(_Pos, _Pos);



		}
		
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
	return _Pos;
}

wormstate Worms::getWormstate()
{
	return _wormsIsDoing;
}

unsigned Worms::getFrameCount()
{
	return _frameCount;
}

bool Worms::getIsFacingRight()
{
	return _isFacingRight;
}


void main()
{
	Worms uno, dos;

	//for (int c = 0; c < 3; c++)
	{
		//uno.walk();
		dos.jump();

	}
}