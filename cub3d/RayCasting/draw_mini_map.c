/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:48:23 by mabdelou          #+#    #+#             */
/*   Updated: 2022/09/05 22:29:30 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	player_view_2(t_cub *cub, t_line *lst, int x, int y)
{
	if (cub->map_buffer[lst->a][lst->b] != '1'
		&& cub->map_buffer[lst->a][lst->b] != ' '
		&& cub->map_buffer[lst->a][lst->b] != '\n'
		&& cub->map_buffer[lst->a][lst->b] != '\0')
	{
		if (lst->d-- > 0)
			img_pixel_put(cub, (int)x, (int)y, 0xFFFFFF);
	}
	else
		return (1);
	return (0);
}

void	player_view(t_cub *cub, double radien, int len)
{
	t_line	lst;
	double	x;
	double	y;

	x = 150;
	y = 150;
	lst_init_(cub, &lst, radien, len);
	while (lst.pixels--)
	{
		lst.a = round(((lst.begin_y - 15) / 32) - 1);
		lst.b = round(((lst.begin_x - 15) / 32) - 1);
		if ((lst.a > -1 && lst.a < cub->a_map_buf))
		{
			if ((lst.b > -1 && lst.b < cub->b_map_buf[lst.a]))
				if (player_view_2(cub, &lst, x, y))
					break ;
		}
		x += lst.deltax;
		y += lst.deltay;
		lst.begin_x += lst.deltax;
		lst.begin_y += lst.deltay;
	}
}

void	mapt_ray_collision(t_cub *cub, double radien, int len)
{
	t_line	lst;
	double	x;
	double	y;

	x = 150;
	y = 150;
	lst_init_(cub, &lst, radien, len);
	while (lst.pixels--)
	{
		lst.a = round(((lst.begin_y - 15) / 32) - 1);
		lst.b = round(((lst.begin_x - 15) / 32) - 1);
		if ((lst.a > -1 && lst.a < cub->a_map_buf))
			if ((lst.b > -1 && lst.b < cub->b_map_buf[lst.a]))
				if (cub->map_buffer[lst.a][lst.b] == '1')
					img_pixel_put(cub, (int)x, (int)y, 0x331A66);
		x += lst.deltax;
		y += lst.deltay;
		lst.begin_x += lst.deltax;
		lst.begin_y += lst.deltay;
	}
}

void	black_mini_map(t_cub *cub)
{
	int	a;
	int	b;

	a = -1;
	while (++a < 325)
	{
		b = -1;
		while (++b < 324)
			txt_img_pixel_put(cub, a, b);
	}
}

void	draw_line(t_cub *cub)
{
	t_ray	lst1;

	lst1_init_(cub, &lst1);
	black_mini_map(cub);
	while (cub->map_buffer[++lst1.a])
	{
		lst1.b = -1;
		lst1.x = 32;
		while (cub->map_buffer[lst1.a][++lst1.b])
			lst1.x += 32;
		lst1.y += 32;
	}
	while (lst1.map_min_raduis < lst1.map_max_raduis)
	{
		mapt_ray_collision(cub, lst1.map_min_raduis, 125);
		if (lst1.map_min_raduis > lst1.min_raduis
			&& lst1.map_min_raduis < lst1.max_raduis)
			player_view(cub, lst1.map_min_raduis, 125);
		lst1.map_min_raduis += 0.0076794487;
	}
	mlx_put_image_to_window(cub->ptr, cub->win_cub3d, cub->img_of_screen, 0, 0);
	mlx_string_put(cub->ptr, cub->win_cub3d, 145, 25, 0xffffff, "N");
}
