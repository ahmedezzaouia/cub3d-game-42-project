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

double ray_collision_len(s_cub *cub, double radian,int len)
{
    double begin_x;
    double begin_y;
    double deltaX;
    double deltaY;
    int pixels;
    int a;
    int b;

    cub->end_ray_x = len*cos(radian) + cub->ppx;
    cub->end_ray_y = len*sin(radian) + cub->ppy;
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
            if(cub->map_buffer[a][b] == '1')
                return(sqrt(pow((cub->ppy-round(begin_y)),2)
                        + pow(cub->ppx-round(begin_x),2)));
        }
        mlx_pixel_put(cub->ptr,cub->win,begin_x,begin_y,0xff0000);
        begin_x += deltaX;
        begin_y += deltaY;
    }
  return(240);
}
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
    int d;

    d = 75;
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
                if(c == 500)
                     c = -1;
                if(radien < -M_PI/2)
                    cub->ray_len[++c] = sqrt(pow((cub->ppy-round(begin_y)),2)
                        + pow(cub->ppx-round(begin_x),2))*cos(-radien+(cub->radien));
                else
                    cub->ray_len[++c] = sqrt(pow((cub->ppy-round(begin_y)),2)
                        + pow(cub->ppx-round(begin_x),2))*cos(radien-(cub->radien));
                if(cub->ray_len[c] < 10)
                    cub->ray_len[c] = 10;
                if(((int)(begin_y)+1) % 30 == 0 && ((int)(begin_x)) % 30 != 0
                    && ((int)(begin_x)+1) % 30 != 0 && begin_y < cub->ppy+5)
                    cub->color_of_wall[c] = 16777215;//wghite
                else if(((int)(begin_y)+1) % 30 == 0 && cub->color_of_wall[c-1] == 16777215)
                    cub->color_of_wall[c] = 16777215;
                else if((int)(begin_y) % 30 == 0 && ((int)(begin_x)) % 30 != 0
                    && ((int)(begin_x)+1) % 30 != 0 && begin_y > cub->ppy+5)
                    cub->color_of_wall[c] = 11997714;//red
                else if((int)(begin_y) % 30 == 0 && cub->color_of_wall[c-1] == 11997714)
                    cub->color_of_wall[c] = 11997714;
                else if (((int)(begin_x)+1) % 30 == 0 && begin_x < cub->ppx+5)
                    cub->color_of_wall[c] = 8654765;//ghozi
                else if ((int)(begin_x) % 30 == 0 && begin_x > cub->ppx+5)
                    cub->color_of_wall[c] = 1012909;//blue
                break;
            }
        }
        if(d-- > 0)
        {
            // if((int)(begin_y) % 30 == 0 && begin_y < cub->ppy+5)
                mlx_pixel_put(cub->ptr,cub->win,begin_x,begin_y,16777215);
            // else if((int)(begin_y) % 30 == 0 && begin_y > cub->ppy+5)
            //     mlx_pixel_put(cub->ptr,cub->win,begin_x,begin_y,0xb71212);
            // else if ((int)(begin_x) % 30 == 0 && begin_x < cub->ppx+5)
            //     mlx_pixel_put(cub->ptr,cub->win,begin_x,begin_y,0x840fad);
            // else if ((int)(begin_x) % 30 == 0 && begin_x > cub->ppx+5)
            //     mlx_pixel_put(cub->ptr,cub->win,begin_x,begin_y,0x0f74ad);
        }
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
    cub->up_len = ray_collision_len(cub,cub->radien,25);
    if(cub->up_len < 10)
        cub->up_len = 10;
    cub->down_len = ray_collision_len(cub,cub->rev_radien,25);
    if(cub->down_len < 10)
        cub->down_len = 10;
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
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_floor,x,y);
                mlx_put_image_to_window(cub->ptr,cub->win,cub->img_player,x+10,y+10);
            }
            x += 30;
        }
        y += 30;
    }

}