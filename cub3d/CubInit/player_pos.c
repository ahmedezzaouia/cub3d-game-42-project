/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:00:19 by mabdelou          #+#    #+#             */
/*   Updated: 2022/09/05 22:29:30 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_pos(t_cub *cub)
{
	int	a;
	int	b;
	int	x;
	int	y;

	a = -1;
	y = 256;
	while (cub->map_buffer[++a])
	{
		b = -1;
		x = 256;
		while (cub->map_buffer[a][++b])
		{
			if (cub->map_buffer[a][b] == 'N' || cub->map_buffer[a][b] == 'S' \
				|| cub->map_buffer[a][b] == 'W' || cub->map_buffer[a][b] == 'E')
			{
				cub->ppx = x + 5;
				cub->ppy = y + 5;
				cub->px = x / 256;
				cub->py = y / 256;
			}
			x += 256;
		}
		y += 256;
	}
}
