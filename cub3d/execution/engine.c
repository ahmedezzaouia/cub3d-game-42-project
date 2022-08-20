/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:17:19 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/08 12:17:20 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"
#include "execution.h"

void celing_part(s_cub *cub,int a)
{
    (void) cub;
    cub->wall_px = (64 / cub->ray_len[a]) * 255;
    cub->wall_px *=2;
    cub->celing_px = 450 - (cub->wall_px/2);
    while(++cub->ray_pixels < cub->celing_px)
        img_pixel_put(cub,a,cub->ray_pixels,0x484B47);
}
void wall_part_2(s_cub *cub, int txt_x, int txt_y, int a)
{
    if(cub->color_of_wall[a] == 16777215)
        txt_img_pixel_put1(cub,cub->img[4],a,cub->ray_pixels,txt_x,txt_y);
    else if(cub->color_of_wall[a] == 11997714)
        txt_img_pixel_put1(cub,cub->img[3],a,cub->ray_pixels,txt_x,txt_y);
    else if(cub->color_of_wall[a] == 8654765)
        txt_img_pixel_put1(cub,cub->img[2],a,cub->ray_pixels,txt_x,txt_y);
    else if (cub->color_of_wall[a] == 1012909)
        txt_img_pixel_put1(cub,cub->img[1],a,cub->ray_pixels,txt_x,txt_y);
    else if(cub->color_of_wall[a] == 0)
        img_pixel_put(cub,a,cub->ray_pixels,0);
}
void wall_part(s_cub *cub,int a,int b,float w_ppl)
{
    int loop;
    float ppl;
    int txt_x;
    int txt_y;

    int y;
    (void) cub;
    loop = -1;
    y = -1;
    ppl = cub->wall_px/64.0;
    while(++loop < cub->wall_px)
    {
        ++cub->ray_pixels;
        ++y;
        if(ppl >= 1)
            txt_y = y/ppl;
        else if(ppl < 1)
            txt_y = y*(1/ppl);
        if(w_ppl >= 1)
            txt_x = b/w_ppl;
        else if(w_ppl < 1)
            txt_x = b*(1/w_ppl);
        if(txt_y > 63 || txt_x > 63)
            break;
        wall_part_2(cub, txt_x, txt_y, a);
    }
}
void floor_part(s_cub *cub,int a)
{
    (void) cub;
    while(++cub->ray_pixels < 900)
        img_pixel_put(cub,a,cub->ray_pixels,0x3A6F7E);
}
void engin(s_cub *cub, int a, int b)
{
    int x;
    int txt_x;
    float w_ppl;

    mlx_put_image_to_window(cub->ptr, cub->win_cub3d, cub->img_wall, 0, 0);
    x = 0;
    txt_x = cub->wall_width[0]*1.1;
    w_ppl = txt_x/64.0;
    while(++a < 1500)
    {
        if(--txt_x == 0)
        {
            txt_x = cub->wall_width[++x]*1.1;
            w_ppl = txt_x/64.0;
            b = 0;
        }
        ++b;
        cub->ray_pixels = -1;
        celing_part(cub,a);
        wall_part(cub,a,b,w_ppl);
        floor_part(cub,a);
    }
}