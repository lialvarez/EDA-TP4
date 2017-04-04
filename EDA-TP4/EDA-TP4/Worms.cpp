#include "Worms.h"
#include "graphics.h"
#include <cmath>
#include <iostream>


#define WORM_OFFSET_RIGHT 28
#define WORM_OFFSET_LEFT  17

Worms::Worms() : 	
	_Pos({960, 616}), _isFacingRight(false), _wormIsDoing(Still), _frameCount(0), _gConstant(0.24), _walkDistance(27), _walkSpeed(27.0 / 50.0),
	_jumpSpeedX((4.5) * cos((double)PI / 3.0)), _jumpSpeedY((4.5) * sin((double)PI / 3.0)){}
 
//void Worms::walk()
//{
//	Graphics g;
//	
//	for (int c = 0; c < 5; c++)
//	{
//		for (_frameCount = 1; _frameCount <= 50; _frameCount++)
//		{
//			if (_isFacingRight && _Pos.x<1212-WORM_OFFSET_RIGHT)
//				_Pos.x = 1101+27*c + _walkSpeed*_frameCount;
//
//			if (!_isFacingRight && _Pos.x>701+WORM_OFFSET_LEFT)
//				_Pos.x = 800-27*c - _walkSpeed*_frameCount;
//
//
//			std::cout << "posX:" << _Pos.x << std::endl;
//			g.graficarPelotitas(_Pos, _Pos);
//		}
//	}
//	
//	return;
//}
//
//void Worms::jump()
//{
//	double dx = 0, dy = 0;
//	Graphics g;
//
//	for (int c = 0; c <= 6; c++)
//	{
//		
//		
//		_Pos.y = 616;
//		for (_frameCount = 1; _frameCount <= 32; _frameCount++)
//		{
//			
//			//dx += _speedX;
//
//			std::cout << dx << std::endl;
////			std::cout << "_:" << _speedX << std::endl;
//
//			if (_isFacingRight && _Pos.x<1212 - WORM_OFFSET_RIGHT)
//				_Pos.x = 1100+72*c + _jumpSpeedX*_frameCount;
//
//			if (!_isFacingRight && _Pos.x>701 + WORM_OFFSET_LEFT)
//				_Pos.x = 900-72*c - _jumpSpeedX*_frameCount;
//
//		
//			std::cout<<"ciclo:" << c << "." << _frameCount << "  POSX:" << _Pos.x << std::endl;
//			
//				
////					std::cout << "y_:" << _speedX << std::endl;
//			//dy += (_gConstant  *_frameCount * 0.5  - _speedY);
//			std::cout << "   dY:" << dy << std::endl;
//			_Pos.y = 616 + (_gConstant  *_frameCount *_frameCount * 0.5 - _jumpSpeedY*_frameCount);
//					std::cout << "     posisisisionY:" << _Pos.y << std::endl;
//					std::cout << "     posisisisionX:" << _Pos.x << std::endl;
//			g.graficarPelotitas(_Pos, _Pos);
//
//
//
//		}
//		
//	}
//	
//}
void Worms::updateWormsPosition(unsigned int tecla)
{
	if (_wormIsDoing == Still)
	{
		_frameCount = 0;		// no me interesa contar los frames donde esta quieto
		switch (tecla)
		{

		case Left_DOWN:
			_isFacingRight = false;
			_wormIsDoing = WalkPending;
			break;

		case Right_DOWN:
			_isFacingRight = true;
			_wormIsDoing = WalkPending;
			break;

		case Up_DOWN:
			_wormIsDoing = Jumping;
			break;

		case NO_CHAR:
			break;
		}
	}

	else if (_wormIsDoing == WalkPending)
	{
		//if(_frameCount>5)
		//	_frameCount = 0;

		//Solo resetea el frme Counter cuando termina de caminar
		switch (tecla)
		{
			case Left_UP:
				_frameCount = 0;
				_wormIsDoing = Still;
				break;

			case Right_UP:
				_frameCount = 0;
				_wormIsDoing = Still;
				break;
			default:
			break;
		}

		if (_frameCount == 5)					//si pase los primeros 100ms 
			_wormIsDoing = Walking;

		_frameCount++;
	}
	
	else if (_wormIsDoing == Walking)
	{
		if (_frameCount == 49)				//ultimo frame de la caminata
		{
			if (_isFacingRight && _Pos.getX()<1212 - WORM_OFFSET_RIGHT)
				_Pos.setX(_Pos.getX()+_walkDistance);

			else if (!_isFacingRight && _Pos.getX()>701 + WORM_OFFSET_LEFT)
				_Pos.setX(_Pos.getX() - _walkDistance);

			if (_isFacingRight && tecla == Right_DOWN)			//si estoy presionando el boton para ir donde estoy moviendome
				_wormIsDoing = WalkPending;

			else if (!_isFacingRight && tecla == Left_DOWN)			// => me sigo moviendo
				_wormIsDoing = WalkPending;

			else
				_wormIsDoing = Still;

		}
		_frameCount++;
	}

	else if (_wormIsDoing == Jumping)
	{
		if (_frameCount > 4 && _frameCount < 37)			//salto de 32 frames. primeros 5 no me muevo.
		{
			if (_isFacingRight && _Pos.getX() < 1212 - WORM_OFFSET_RIGHT)
				_Pos.setX(_Pos.getX() + _jumpSpeedX*_frameCount);

			if (!_isFacingRight && _Pos.getX() > 701 + WORM_OFFSET_LEFT)
				_Pos.setX(_Pos.getX() - _jumpSpeedX*_frameCount);
			_Pos.setY( 616 + (_gConstant  *_frameCount *_frameCount * 0.5 - _jumpSpeedY*_frameCount));
		}

		else if (_frameCount == 37)
			_wormIsDoing = JumpEnding;
		
		_frameCount++;
	}

	else if (_wormIsDoing == JumpEnding)
	{
		if (_frameCount == 42)				//5 antes de saltar+32 saltando+ 5 despues de saltar
		{
			if (tecla == Up_DOWN)
				_wormIsDoing = Jumping;		//si presiono para saltar sigo saltando
			else
				_wormIsDoing = Still;

			_frameCount = 0;				//dejo de caminar, reseteo fc
		}
		else
			_frameCount++;
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

wormstate_e Worms::getWormstate()
{
	return _wormIsDoing;
}

unsigned Worms::getFrameCount()
{
	return _frameCount;
}

bool Worms::getIsFacingRight()
{
	return _isFacingRight;
}


//void main()
//{
//	Worms uno, dos;
//
//	//for (int c = 0; c < 3; c++)
//	{
//		//uno.walk();
//		dos.jump();
//
//	}
//}