/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:00:30 by mabdelou          #+#    #+#             */
/*   Updated: 2022/09/05 18:00:31 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ft_close(s_cub *cub)
{
	(void) cub;
	write(1, "cub3D exited successful\n", 24);
	exit(0);
	return (0);
}

void	key_press_2(int keycode, s_cub *cub)
{
	if ((keycode == 13 || keycode == 126)
		&& collisiont_ray_len(cub, cub->radien, 10))
	{
		cub->ppy += roundf(sin(cub->radien) * 40);
		cub->ppx += roundf(cos(cub->radien) * 40);
	}
	if ((keycode == 1 || keycode == 125)
		&& collisiont_ray_len(cub, cub->rev_radien, 10))
	{
		cub->ppy -= roundf(sin(cub->radien) * 40);
		cub->ppx -= roundf(cos(cub->radien) * 40);
	}
	if (keycode == 2 && collisiont_ray_len(cub, (cub->radien + M_PI) / 2.0, 10))
	{
		cub->ppy += roundf(sin(cub->radien + M_PI / 2) * 40);
		cub->ppx += roundf(cos(cub->radien + M_PI / 2) * 40);
	}
	if (keycode == 0
		&& collisiont_ray_len(cub, (cub->rev_radien + M_PI) / 2.0, 10))
	{
		cub->ppy -= roundf(sin(cub->radien + M_PI / 2) * 40);
		cub->ppx -= roundf(cos(cub->radien + M_PI / 2) * 40);
	}
}

int	key_press(int keycode, s_cub *cub)
{
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
	if (keycode == 53)
		ft_close(cub);
	key_press_2(keycode, cub);
	return (0);
}

int	mouse_mv(int x, int y, s_cub *cub)
{
	static int	old_x = -1;

	(void) x;
	(void) y;
	(void) cub;
	if (x > -1 && x < 1500 && y > -1 && y < 900 && old_x != -1)
	{
		if (old_x > x)
		{
			cub->radien -= (old_x - x) / 150.0;
			cub->rev_radien -= (old_x - x) / 150.0;
		}
		else
		{
			cub->radien += (x - old_x) / 150.0;
			cub->rev_radien += (x - old_x) / 150.0;
		}
	}
	old_x = x;
	return (0);
}

int	update( s_cub *cub)
{
	static int	a = -1;

	while (++a % 20 == 0)
	{
		rays_firing(cub);
		engin(cub, -1, 0);
		draw_line(cub);
		if (a == 1000)
			a = -1;
	}
	return (0);
}
