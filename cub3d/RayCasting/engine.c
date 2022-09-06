/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:17:19 by mabdelou          #+#    #+#             */
/*   Updated: 2022/09/06 16:08:55 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	celing_part(t_cub *cub, int a)
{
	(void) cub;
	cub->wall_px = (512 / cub->ray_len[a]) * 255;
	cub->wall_px *= 2;
	cub->celing_px = 450 - (cub->wall_px / 2);
	while (++cub->ray_pixels < cub->celing_px)
		img_pixel_put(cub, a, cub->ray_pixels, \
		(cub->c_rgb[0] * 256 * 256) + (cub->c_rgb[1] * 256) + cub->c_rgb[2]);
}

void	wall_part_2(t_cub *cub, int txt_x, int txt_y, int a)
{
	if (cub->color_of_wall[a] == 16777215)
	{
		cub->img[4]->txt_x = txt_x;
		cub->img[4]->txt_y = txt_y;
		txt_img_pixel_put1(cub, cub->img[4], a, cub->ray_pixels);
	}
	else if (cub->color_of_wall[a] == 11997714)
	{
		cub->img[3]->txt_x = txt_x;
		cub->img[3]->txt_y = txt_y;
		txt_img_pixel_put1(cub, cub->img[3], a, cub->ray_pixels);
	}
	else if (cub->color_of_wall[a] == 8654765)
	{
		cub->img[2]->txt_x = txt_x;
		cub->img[2]->txt_y = txt_y;
		txt_img_pixel_put1(cub, cub->img[2], a, cub->ray_pixels);
	}
	else if (cub->color_of_wall[a] == 1012909)
	{
		cub->img[1]->txt_x = txt_x;
		cub->img[1]->txt_y = txt_y;
		txt_img_pixel_put1(cub, cub->img[1], a, cub->ray_pixels);
	}
}

void	wall_part(t_cub *cub, int a)
{
	int		loop;
	int		txt_y;
	float	ppl;
	int		y;

	loop = -1;
	ppl = cub->wall_px / 256.0;
	y = -1;
	if (cub->wall_px > 900)
		y = (cub->wall_px - 900) / 2;
	while (++loop < cub->wall_px)
	{
		++cub->ray_pixels;
		++y;
		if (ppl >= 1)
			txt_y = y / ppl;
		else if (ppl < 1)
			txt_y = y * (1 / ppl);
		if (txt_y > 255 && txt_y < -1)
			break ;
		wall_part_2(cub, cub->ray_hit_pos[a], txt_y, a);
	}
}

void	floor_part(t_cub *cub, int a)
{
	(void) cub;
	while (++cub->ray_pixels < 900)
		img_pixel_put(cub, a, cub->ray_pixels, \
		(cub->f_rgb[0] * 256 * 256) + (cub->f_rgb[1] * 256) + cub->f_rgb[2]);
}

void	engin(t_cub *cub, int a, int b)
{
	(void) b;
	mlx_put_image_to_window(cub->ptr, cub->win_cub3d,
		cub->img_black_screen, 0, 0);
	while (++a < 1500)
	{
		cub->ray_pixels = -1;
		celing_part(cub, a);
		wall_part(cub, a);
		floor_part(cub, a);
	}
}
