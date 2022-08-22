#include "../cub3d.h"

int	ft_close(s_cub *cub)
{
    (void) cub;
	write(1, "cub3D exited successful\n", 24);
	exit(0);
	return (0);
}

int	key_press(int keycode, s_cub *cub)
{
	if ((keycode == 13 || keycode == 126) && cub->up_len > 15)
	{
		cub->ppy += roundf(sin(cub->radien) * 5);
		cub->ppx += roundf(cos(cub->radien) * 5);
	}
	if ((keycode == 1 || keycode == 125) && cub->down_len > 15)
	{
		cub->ppy -= roundf(sin(cub->radien) * 5);
		cub->ppx -= roundf(cos(cub->radien) * 5);
	}
	if (keycode == 124)
	{
		cub->radien += 0.075;
		cub->rev_radien += 0.075;
	}
	if (keycode == 123)
	{
		cub->radien -= 0.075;
		cub->rev_radien -= 0.075;
	}
	if (keycode == 2 && cub->right_len > 15)
	{
		cub->ppy += roundf(sin(cub->radien+M_PI/2) * 5);
		cub->ppx += roundf(cos(cub->radien+M_PI/2) * 5);
	}
	if (keycode == 0 && cub->left_len > 15)
	{
		cub->ppy -= roundf(sin(cub->radien+M_PI/2) * 5);
		cub->ppx -= roundf(cos(cub->radien+M_PI/2) * 5);
	}
	if (keycode == 53)
		ft_close(cub);
	return (0);
}

int mouse_mv(int x, int y, s_cub *cub)
{
    static int old_x = -1;
    (void) x;
    (void) y;
    (void) cub;
	if(x > -1 && x < 1500 && y > -1 && y < 900 && old_x != -1)
    {
        if(old_x > x)
        {
            cub->radien -= (old_x-x)/150.0;//150.0 is for sensyvity
            cub->rev_radien -= (old_x-x)/150.0;
        }
        else
        {
            cub->radien += (x-old_x)/150.0;
            cub->rev_radien += (x-old_x)/150.0;
        }
    }
    old_x = x;
    return (0);
}

int update( s_cub *cub)
{
    rays_firing(cub);
	// ft_calc_width_walls(cub, -1, -1);
	engin(cub, -1, 0);
	draw_line(cub);
    return (0);
}