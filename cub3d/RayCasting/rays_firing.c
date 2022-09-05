/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_firing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:25:39 by mabdelou          #+#    #+#             */
/*   Updated: 2022/09/05 22:29:30 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	lst1_init(t_cub *cub, t_ray *lst1)
{
	lst1->a = -1;
	lst1->y = 256;
	lst1->min_raduis = cub->radien - 0.57595865315;
	lst1->max_raduis = cub->radien + 0.57595865315;
	lst1->map_min_raduis = cub->radien - M_PI;
	lst1->map_max_raduis = cub->radien + M_PI;
}

void	rays_firing(t_cub *cub)
{
	t_ray	lst1;

	lst1_init(cub, &lst1);
	while (cub->map_buffer[++lst1.a])
	{
		lst1.b = -1;
		lst1.x = 256;
		while (cub->map_buffer[lst1.a][++lst1.b])
			lst1.x += 256;
		lst1.y += 256;
	}
	while (lst1.min_raduis < lst1.max_raduis)
	{
		rays_collision(cub, lst1.min_raduis, 100000);
		lst1.min_raduis += 0.00076794487;
	}
}
