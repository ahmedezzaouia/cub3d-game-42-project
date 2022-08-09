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

void draw_line(s_cub *cub,double radien,int len)
{
    double begin_x;
    double begin_y;
    double deltaX;
    double deltaY;
    int pixels;
    int a;
    int b;
    static int c = -1;

    cub->end_ray_x = len*cos(radien) + cub->ppx;
    cub->end_ray_y = len*sin(radien) + cub->ppy;
    deltaX = cub->end_ray_x - cub->ppx;
    deltaY = cub->end_ray_y - cub->ppy;
    pixels = sqrt((deltaX*deltaX)+(deltaY*deltaY));
    deltaX /= pixels;
    deltaY /= pixels;
    begin_x =cub->ppx+5;
    begin_y =cub->ppy+5;
    while(pixels--)
    {
        a = round(((begin_y-15)/30)-1);
        b = round(((begin_x-15)/30)-1);
        if((a > -1 && a < 14) && (b > -1 && b<33))
        {
            if(cub->map_buffer[a][b] == '1') //for stop if hit wall
            {   //for save line_len
                if(radien < -M_PI/2)
                    cub->ray_len[++c] = sqrt(pow((cub->ppy-round(begin_y)),2)
                        + pow(cub->ppx-round(begin_x),2))*cos(-radien+(cub->radien));
                else
                    cub->ray_len[++c] = sqrt(pow((cub->ppy-round(begin_y)),2)
                        + pow(cub->ppx-round(begin_x),2))*cos(radien-(cub->radien));
                // printf("%f\n",cub->ray_len[c]);
                break;
            }
        }
        mlx_pixel_put(cub->ptr,cub->win,begin_x,begin_y,16777215);
        begin_x += deltaX;
        begin_y += deltaY;
    }
    if(c == 500)
        c = -1;
}

void update_map(s_cub *cub)
{
    int a;
    int b;
    int x;
    int y;
    double min_raduis = cub->radien  - 0.57595865315; // == 33 degree for left view
    double max_raduis = cub->radien  + 0.57595865315; // == 33 degree for right view

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
    while(min_raduis < max_raduis)
    {
        draw_line(cub,min_raduis,5000);
        min_raduis += 0.00230383461; //for 1 ray evry loop
    }
    draw_line(cub,cub->radien,60);
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
                draw_line(cub,cub->radien,60);
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_floor,x,y);
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_player,x+10,y+10);
            }
            x += 30;
        }
        y += 30;
    }

}