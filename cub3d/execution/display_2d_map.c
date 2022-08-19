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

void display_2d_map(s_cub *cub)
{
    int a;
    int b;
    int x;
    int y;

    a= -1;
    y = 30;
    while(cub->map_buffer[++a])
    {
        b = -1;
        x = 30;
        while(cub->map_buffer[a][++b])
        {            
            if(cub->map_buffer[a][b] == '1')
            {
                // printf("a %d b %d x %d y %d\n",a,b,x,y);
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_wall,x,y);
            }
            else if(cub->map_buffer[a][b] == '0')
            {
                // printf("a %d b %d x %d y %d\n",a,b,x,y);
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_floor,x,y);
            }
            else if(cub->map_buffer[a][b] == ' ')
            {
                // printf("a %d b %d x %d y %d\n",a,b,x,y);
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_empty,x,y);
            }
            else if(cub->map_buffer[a][b] == 'N')
            {
                cub->ppx = x+10;
                cub->ppy = y+10;
                cub->px = x/30;
                cub->py = (y/30) - 2;
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_floor,x,y);
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_player,x+10,y+10);
            }
            x += 30;
        }
        y += 30;
    }
}