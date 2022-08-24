/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2d_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:00:19 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/06 15:00:31 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void player_pos(s_cub *cub)
{
    int a;
    int b;
    int x;
    int y;

    a= -1;
    y = 64;
    while(cub->map_buffer[++a])
    {
        b = -1;
        x = 64;
        while(cub->map_buffer[a][++b])
        {
            if(cub->map_buffer[a][b] == 'N')
            {
                cub->ppx = x+5;
                cub->ppy = y+5;
                cub->px = x/64;
                cub->py = y/64;
            }
            x += 64;
        }
        y += 64;
    }
}