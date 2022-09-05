/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisiont_ray_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:04:20 by mabdelou          #+#    #+#             */
/*   Updated: 2022/09/05 17:04:22 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ray_fire(s_cub *cub, t_line *lst)
{
	while (lst->pixels--)
	{
		lst->b = round(((lst->begin_x - 15) / 32) - 1);
		lst->a = round(((lst->begin_y - 15) / 32) - 1);
		if ((lst->a > -1 && lst->a < cub->a_map_buf))
		{
			if ((lst->b > -1 && lst->b < cub->b_map_buf[lst->a]))
			{
				if (cub->map_buffer[lst->a][lst->b] == '1')
					return (1);
			}
		}
		lst->begin_x += lst->deltax;
		lst->begin_y += lst->deltay;
	}
	return (0);
}

int	check_directions(s_cub *cub, double radian)
{
	t_line	lst;

	lst_init_(cub, &lst, radian, 10);
	if (lst.begin_x < (lst.begin_x + lst.deltax))
		return (0);
	else if (lst.begin_y < (lst.begin_y + lst.deltay))
		return (0);
	return (1);
}

int	collisiont_ray_len(s_cub *cub, double radian, int len)
{
	t_line	lst;

	lst_init_(cub, &lst, radian, len);
	if (ray_fire(cub, &lst))
		return (0);
	lst_init_(cub, &lst, (radian - 0.78), len);
	if (ray_fire(cub, &lst))
		return (0);
	lst_init_(cub, &lst, (radian + 0.78), len);
	if (ray_fire(cub, &lst))
		return (0);
	return (1);
}
