
#include "../cub3d.h"

void	ft_calc_size_of_img(s_cub *cub)
{
	int a;
	int b;


	a = -1;
	b = -1;
	cub->x_pixel = 0;
	while (cub->map_buffer[++a])
	{
		b = -1;
		while (cub->map_buffer[a][++b])
		{
			cub->y_pixel = ft_strlen(cub->map_buffer[a]);
			if (cub->x_pixel < cub->y_pixel)
				cub->x_pixel = cub->y_pixel;
		}
	}
	cub->x_pixel *=  30;
	cub->y_pixel = (a + 2) * 30;
}