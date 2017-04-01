#include "Graphics.h"


Graphics::Graphics() 
{
	allegroState = initAllegro();

	//Esto no va aca, estoy probando.
	graphBackground();
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

void Graphics::graphBackground()
{
	if (allegroState)
	{
		al_draw_bitmap(background, monitorInfo.x1, monitorInfo.y1, 0);
		al_flip_display();
	}
}

