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

#include "haider.h"

void draw_line(s_cub *cub)
{
    double begin_x;
    double begin_y;
    double deltaX;
    double deltaY;
    int pixels;

    cub->end_ray_x = 60*cos(cub->radien) + cub->ppx;
    cub->end_ray_y = 60*sin(cub->radien) + cub->ppy;
    deltaX = cub->end_ray_x - cub->ppx;
    deltaY = cub->end_ray_y - cub->ppy;
    pixels = sqrt((deltaX*deltaX)+(deltaY*deltaY));
    deltaX /= pixels;
    deltaY /= pixels;
    begin_x =cub->ppx +4;
    begin_y =cub->ppy +4;
    while(pixels--)
    {
        mlx_pixel_put(cub->ptr,cub->win,begin_x,begin_y,16777215);
        begin_x += deltaX;
        begin_y += deltaY;
    }

}

void update_map(s_cub *cub)
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
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_wall,x,y);
            else if(cub->map_buffer[a][b] == '0')
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_floor,x,y);
            else if(cub->map_buffer[a][b] == ' ')
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_empty,x,y);
            else if(cub->map_buffer[a][b] == 'N')
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_floor,x,y);
            x += 30;
        }
        y += 30;
    }
    draw_line(cub);
    mlx_put_image_to_window(cub->ptr,cub->win,cub->img_player,cub->ppx,cub->ppy);
}


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
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_wall,x,y);
            else if(cub->map_buffer[a][b] == '0')
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_floor,x,y);
            else if(cub->map_buffer[a][b] == ' ')
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_empty,x,y);
            else if(cub->map_buffer[a][b] == 'N')
            {
                cub->ppx = x+10;
                cub->ppy = y+10;
                cub->px = x/30;
                cub->py = (y/30) - 2;
                draw_line(cub);
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_floor,x,y);
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_player,x+10,y+10);
            }
            x += 30;
        }
        y += 30;
    }

}