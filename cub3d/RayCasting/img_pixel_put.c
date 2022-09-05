/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:56:47 by mabdelou          #+#    #+#             */
/*   Updated: 2022/09/05 21:11:05 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	txt_img_pixel_put1(s_cub *cub, t_img *img,
		int x, int y)
{
	int	txt_index;
	int	index;

	if ((x < 1500 && y < 900) && (img->txt_x < 256
			&& img->txt_y < 256) && img->txt_y > -1)
	{
		txt_index = (img->txt_y
				* img->line_len + img->txt_x * (img->bpp / 8));
		index = (y * cub->img[0]->line_len + x * (cub->img[0]->bpp / 8));
		cub->img[0]->addr[index] = (int)img->addr[txt_index];
		cub->img[0]->addr[index + 1] = (int)img->addr[txt_index + 1];
		cub->img[0]->addr[index + 2] = (int)img->addr[txt_index + 2];
	}
}

void	img_pixel_put(s_cub *cub, int x, int y, int color)
{
	char	*pixel;

	if (x < 1500 && y < 900)
	{
		pixel = cub->img[0]->addr
			+ (y * cub->img[0]->line_len) + (x * (cub->img[0]->bpp / 8));
		*(int *)pixel = color;
	}
}

void	txt_img_pixel_put(s_cub *cub, int x, int y)
{
	int	txt_index;
	int	index;

	txt_index = (y * cub->img[5]->line_len + x * (cub->img[5]->bpp / 8));
	index = (y * cub->img[0]->line_len + x * (cub->img[0]->bpp / 8));
	if (!*(int *)(cub->img[5]->addr
		+ (y * cub->img[5]->line_len) + (x * (cub->img[5]->bpp / 8))))
	{
		cub->img[0]->addr[index] = (int)cub->img[5]->addr[txt_index];
		cub->img[0]->addr[index + 1] = (int)cub->img[5]->addr[txt_index + 1];
		cub->img[0]->addr[index + 2] = (int)cub->img[5]->addr[txt_index + 2];
	}
}

void	lst1_init_(s_cub *cub, t_ray *lst1)
{
	lst1->a = -1;
	lst1->y = 32;
	lst1->min_raduis = cub->radien - 0.57595865315;
	lst1->max_raduis = cub->radien + 0.57595865315;
	lst1->map_min_raduis = cub->radien - M_PI;
	lst1->map_max_raduis = cub->radien + M_PI;
}

void	lst_init_(s_cub *cub, t_line *lst, double radien, int len)
{
	cub->end_ray_x = len * cos(radien) + (cub->ppx / 8);
	cub->end_ray_y = len * sin(radien) + (cub->ppy / 8);
	lst->deltax = cub->end_ray_x - (cub->ppx / 8);
	lst->deltay = cub->end_ray_y - (cub->ppy / 8);
	lst->pixels = sqrt((lst->deltax
				* lst->deltax) + (lst->deltay * lst->deltay));
	lst->deltax /= lst->pixels;
	lst->deltay /= lst->pixels;
	lst->begin_x = (cub->ppx / 8) + 15;
	lst->begin_y = (cub->ppy / 8) + 15;
	lst->a = -1;
	lst->b = -1;
	lst->d = 75;
}
