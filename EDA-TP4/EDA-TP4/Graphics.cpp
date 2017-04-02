#include "Graphics.h"


Graphics::Graphics() 
{
	allegroState = initAllegro();

	//Esto no va aca, estoy probando.
	drawBackground();
	al_flip_display();
}

bool Graphics::initAllegro()
{
	if (al_init())
	{
		if (al_init_image_addon())
		{
			std::ostringstream fileNum;
			std::string auxString;

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
				display = al_create_display(al_get_bitmap_width(background), al_get_bitmap_height(background));
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
		std::cerr << "Failed to initialize Allegro!" << std::endl;
		return false;
	}
}

void Graphics::drawBackground()
{
	if (allegroState)
	{
		al_draw_bitmap(background, monitorInfo.x1, monitorInfo.y1, 0);
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
			al_draw_bitmap(wormBitmap, p.getX() - X_OFFSET, p.getY() - Y_OFFSET, ALLEGRO_FLIP_HORIZONTAL);
			return;
		}
		else
		{
			al_draw_bitmap(wormBitmap, p.getX() + X_OFFSET, p.getY() + Y_OFFSET, 0);
			return;
		}
	}
	else
	{
		std::cerr << "Failed to draw worm!" << std::endl;
		return;
	}
}

void Graphics::drawWalkingWorm(Position p, bool inverted, unsigned int frameCount)
{
	Position auxP;
	if (allegroState)
	{
		if (frameCount < 8) //WarmUp
		{
			if (frameCount > 4)
			{
				drawWorm(wormWalk[frameCount - 5], p, inverted);
				return;
			}
			else
			{
				drawWorm(wormWalk[F4], p, inverted);
				return;
			}
		}
		else
		{
			if (frameCount > 22 && frameCount < 36)	//Si la condicion es verdadera esta en el segundo ciclo de la secuencia Walking
			{
				frameCount -= 14;
				if (inverted)
				{
					p.setX(p.getX() + 9);
				}
				else
				{
					p.setX(p.getX() - 9);
				}
			}
			else
			{
				if (frameCount > 35)	//Si la condicion es verdadera esta en el tercer ciclo de la secuencia.
				{
					frameCount -= 28;
					if (inverted)
					{
						p.setX(p.getX() + 18);
					}
					else
					{
						p.setX(p.getX() - 18);
					}
				}
				// Si ninguna de las anteriores es verdad, no se modifica frame count.
			}
			if (frameCount != 21)
			{
				if (frameCount < 16)
				{
					drawWorm(wormWalk[frameCount - 5], p, inverted);
					return;
				}
				else if (frameCount >= 16)
				{
					drawWorm(wormWalk[frameCount - 6], p, inverted);
					return;
				}
			}
			else
			{
				drawWorm(wormWalk[F4], p, inverted);
				return;
			}
			
		}

	}
	else
	{	
		std::cerr << "Failed to draw Walking Warm" << std::endl;
		return;
	}
}

void Graphics::refreshScreen(Position _p, unsigned int _wormstate, bool _facingRight, unsigned int _frameCount)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	switch (_wormstate)
	{
	case Still:

		drawBackground();
		drawWorm(wormWalk[F4], _p, _facingRight);
		break;

	case WalkPending:

		drawBackground();
		drawWalkingWorm(_p, _facingRight, _frameCount);
		break;

	case Walking:

		drawBackground();
		drawWalkingWorm(_p, _facingRight, _frameCount);
		break;

	case Jumping:

		drawBackground();
		drawWorm(wormJump[F5], _p, _facingRight);
		break;

	case JumpEnding:

		drawBackground();
		drawWorm(wormJump[_frameCount + 5], _p, _facingRight);
		break;

	default:
		break;
	}
	al_flip_display();
}