#include "Graphics.h"


Graphics::Graphics() 
{
	allegroState = initAllegro();
	xRes = 1920.0 / (float)dispData.width;
	yRes = 696.0 / (float)dispData.height;
	//Esto no va aca, estoy probando.
	drawBackground();
	al_flip_display();
}

ALLEGRO_DISPLAY *Graphics::getDisplay()
{
	return display;
}

bool Graphics::initAllegro()
{
	if (al_init())
	{
		if (al_init_primitives_addon())
		{
			if (al_init_image_addon())
			{
				std::ostringstream fileNum;
				std::string auxString;
				
				auxiliar = al_load_bitmap("resources/Auxiliar2.png");
				background = al_load_bitmap("resources/Scenario.png");
				if (background != NULL)
				{
					for (unsigned int i = 0; i < WALKPICS; i++)
					{
						auxString = "resources/wwalking/wwalk-F";
						fileNum << i + 1;
						auxString += fileNum.str();
						auxString += ".png";
						char *fileName = new char[auxString.length() + 1];
						strcpy_s(fileName, auxString.length() + 1, auxString.c_str());
						wormWalk[i] = al_load_bitmap(fileName);
						if (wormWalk[i] == NULL)
						{
							delete[] fileName;
							std::cerr << "Failed to load \"" << auxString << "\"!" << std::endl;
							return false;
						}
						delete[] fileName;
						fileNum.str("");
						fileNum.clear();
						auxString.clear();
					}

					for (unsigned int i = 0; i < JUMPPICS; i++)
					{
						auxString = "resources/wjump/wjump-F";
						fileNum << i + 1;
						auxString += fileNum.str();
						auxString += ".png";
						char *fileName = new char[auxString.length() + 1];
						strcpy_s(fileName, auxString.length() + 1, auxString.c_str());
						wormJump[i] = al_load_bitmap(fileName);
						if (wormWalk[i] == NULL)
						{
							delete[] fileName;
							std::cerr << "Failed to load \"" << auxString << "\"!" << std::endl;
							return false;
						}
						delete[] fileName;
						fileNum.str("");
						fileNum.clear();
						auxString.clear();
					}
					al_get_display_mode(al_get_num_display_modes() - 5, &dispData);
					display = al_create_display(dispData.width, dispData.height);
					al_clear_to_color(al_map_rgb(0, 0, 0));
					al_flip_display();
					if (display != NULL)
					{
						return true;
					}
					else
					{
						std::cerr << "Failed to create display!" << std::endl;
						return false;
					}
				}
				else
				{
					std::cerr << "Failed to load \"Scenario.png\"!" << std::endl;
					return false;
				}
			}
			else
			{
				std::cerr << "Failed to load Images Addon!" << std::endl;
				return false;
			}

		}
		else
		{
			std::cerr << "Failed to load Primitives Addon!" << std::endl;
			return false;
		}
	}
	else
	{
		std::cerr << "Failed to initialize Allegro!" << std::endl;
		return false;
	}
}

void Graphics::drawBackground()
{
	if (allegroState)
	{
		al_draw_scaled_bitmap(background, 0, 0, al_get_bitmap_width(background), al_get_bitmap_height(background), 0, 0, dispData.width, dispData.height, 0);
		return;
	}
	else
	{
		std::cerr << "Failed to draw background!" << std::endl;
		return;
	}
}

void Graphics::drawWorm(ALLEGRO_BITMAP *wormBitmap, Position p, bool inverted)
{
	if (allegroState)
	{
		if (inverted)
		{
			al_draw_bitmap(wormBitmap, p.getX() + X_OFFSET / xRes, p.getY() - Y_OFFSET, ALLEGRO_FLIP_HORIZONTAL);
			return;
		}
		else
		{
			al_draw_bitmap(wormBitmap, p.getX() + X_OFFSET, p.getY() - Y_OFFSET, 0);
			return;
		}
	}
	else
	{
		std::cerr << "Failed to draw worm!" << std::endl;
		return;
	}
}

void Graphics::setDrawingPoint(Position& p, unsigned int frameCount, bool inverted)
{
	
	if (frameCount > 20 && frameCount < 35)
	{
		if (inverted)
		{
			p.setX(p.getX() + 9 / xRes);
		}
		else
		{
			p.setX(p.getX() - 9 / xRes);
		}
		return;
	}
	if (frameCount > 34 && frameCount < 49)
	{
		if (inverted)
		{
			p.setX(p.getX() + 18 / xRes);
		}
		else
		{
			p.setX(p.getX() - 18 / xRes);
		}
		return;
	}
	if (frameCount == 49)
	{
		if (inverted)
		{
			p.setX(p.getX() + 27 / xRes);
		}
		else
		{
			p.setX(p.getX() - 27 / xRes);
		}
		return;
	}
}

void Graphics::refreshScreen(Position _p, unsigned int _wormstate, bool _facingRight, unsigned int _frameCount)
{
	
	_p.setX(_p.getX() / xRes);
	_p.setY(_p.getY() / yRes);

	if (_wormstate == WalkEnding)
	{
		_wormstate = Walking;
	}

	switch (_wormstate)
	{
	case Still:

		drawWorm(wormWalk[F4], _p, _facingRight);
		break;

	case WalkPending:


		drawWorm(wormWalk[F4], _p, _facingRight);
		break;

	case Walking:

		setDrawingPoint(_p, _frameCount, _facingRight);
		if (_frameCount < 8)
		{
			if (_frameCount < 5)
			{
				drawWorm(wormWalk[F4], _p, _facingRight);
			}
			else
			{
				drawWorm(wormWalk[_frameCount - 5], _p, _facingRight);
			}
			break;
		}
		if (_frameCount > 7 && _frameCount < 21)
		{
			if (_frameCount < 16)
			{
				drawWorm(wormWalk[_frameCount - 5], _p, _facingRight);
			}
			else
			{
				drawWorm(wormWalk[_frameCount - 6], _p, _facingRight);
			}
			break;
		}
		if (_frameCount > 21 && _frameCount < 35)
		{
			if (_frameCount < 30)
			{
				drawWorm(wormWalk[_frameCount - 5 - 14], _p, _facingRight);
			}
			else
			{
				drawWorm(wormWalk[_frameCount - 6 - 14], _p, _facingRight);
			}
			break;
		}
		if (_frameCount > 35 && _frameCount < 49)
		{
			if (_frameCount < 44)
			{
				drawWorm(wormWalk[_frameCount - 5 - 28], _p, _facingRight);
			}
			else
			{
				drawWorm(wormWalk[_frameCount - 6 - 28], _p, _facingRight);
			}
			break;
		}
		if (_frameCount == 21 || _frameCount == 35 || _frameCount == 49)
		{
			drawWorm(wormWalk[F4], _p, _facingRight);
		}
		break;

	case Jumping:

		if (_frameCount < 5)
		{
			drawWorm(wormJump[_frameCount], _p, _facingRight);
			break;
		}
		drawWorm(wormJump[F5], _p, _facingRight);
		break;

	case JumpEnding:

		drawWorm(wormJump[_frameCount + 5], _p, _facingRight);
		break;

	default:
		break;
	}
}

void Graphics::auxRefresh()
{
	al_draw_scaled_bitmap(auxiliar, 0, 0, al_get_bitmap_width(auxiliar), al_get_bitmap_height(auxiliar), 666 / xRes, 562 / yRes, al_get_bitmap_width(auxiliar) / xRes, al_get_bitmap_height(auxiliar) / yRes, 0);
	al_draw_filled_rectangle(701 / xRes, 400 / yRes, 1212 / xRes, 616 / yRes, al_map_rgb(0, 0, 0));
}

