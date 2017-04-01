#include "graphics.h"


Graphics::Graphics()
{
	_display = NULL;
	if (al_init())
	{
		_display = al_create_display(STAGE_X, STAGE_Y);
		if (_display != NULL)
		{
			if (al_init_primitives_addon())
			{
				if (al_init_image_addon())
				{
					if (al_init_acodec_addon())
					{
						if (al_install_audio())
						{
							if (al_reserve_samples(1))
							{
								if (al_init_font_addon())
								{
									if (al_init_ttf_addon())
									{
										return;
									}
								}
							}
						}
					}

				}

			}
		}
		al_destroy_display(_display);

	}
}

void Graphics::graficarPelotitas()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_circle(cx1, cy1, r, al_map_rgb(255, 163, 98), 1);
	al_draw_circle(cx1, cy1, r, al_map_rgb(255, 163, 98), 1);
}