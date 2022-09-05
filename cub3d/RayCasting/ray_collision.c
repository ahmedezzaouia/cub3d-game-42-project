/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:08:43 by mabdelou          #+#    #+#             */
/*   Updated: 2022/09/05 22:29:30 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	lst_init(t_cub *cub, t_line *lst, double radien, int len)
{
	cub->end_ray_x = len * cos(radien) + cub->ppx;
	cub->end_ray_y = len * sin(radien) + cub->ppy;
	lst->deltax = cub->end_ray_x - cub->ppx;
	lst->deltay = cub->end_ray_y - cub->ppy;
	lst->pixels = sqrt((lst->deltax
				* lst->deltax) + (lst->deltay * lst->deltay));
	lst->deltax /= lst->pixels;
	lst->deltay /= lst->pixels;
	lst->begin_x = cub->ppx + 5;
	lst->begin_y = cub->ppy + 5;
	lst->a = -1;
	lst->b = -1;
	lst->d = 75;
}

void	rays_collision(t_cub *cub, double radien, int len)
{
	t_line	lst;

	lst_init(cub, &lst, radien, len);
	while (lst.pixels--)
	{
		lst.a = round(((lst.begin_y - 15) / 256) - 1);
		lst.b = round(((lst.begin_x - 15) / 256) - 1);
		if ((lst.a > -1 && lst.a < cub->a_map_buf))
		{
			if ((lst.b > -1 && lst.b < cub->b_map_buf[lst.a]))
			{
				if (cub->map_buffer[lst.a][lst.b] == '1'
					|| cub->map_buffer[lst.a][lst.b] == ' '
					|| cub->map_buffer[lst.a][lst.b] == '\n'
					|| cub->map_buffer[lst.a][lst.b] == '\0')
				{
					ray_len(cub, &lst, radien);
					break ;
				}
			}
		}
		lst.begin_x += lst.deltax;
		lst.begin_y += lst.deltay;
	}
}
