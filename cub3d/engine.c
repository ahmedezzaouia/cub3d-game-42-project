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


#include "haider.h"


void make_cub3d_win(s_cub *cub)
{
    (void) cub;
    cub->win_cub3d = mlx_new_window(cub->ptr,500,300, "Cub3D");
}

void celing_part(s_cub *cub,int a)
{
    (void) cub;
    cub->wall_px = (64 / cub->ray_len[a]) * 255;
    cub->celing_px = 150 - (cub->wall_px/2);
    while(++cub->ray_pixels < cub->celing_px)
        mlx_pixel_put(cub->ptr,cub->win_cub3d,a,cub->ray_pixels,0x484B47);   
}
void wall_part(s_cub *cub,int a)
{
    int loop;

    loop = -1;
    (void) cub;
    while(++loop < cub->wall_px)
    {
        ++cub->ray_pixels;
        mlx_pixel_put(cub->ptr,cub->win_cub3d,a,cub->ray_pixels,0x3C0EA0);
    }
}
void floor_part(s_cub *cub,int a)
{
    (void) cub;
    while(++cub->ray_pixels < 300)
        mlx_pixel_put(cub->ptr,cub->win_cub3d,a,cub->ray_pixels,0x3A6F7E);
}
void engin(s_cub *cub)
{
    int a;

    (void) cub;
    if(!cub->win_cub3d)
        make_cub3d_win(cub);
    a  =-1;
    mlx_put_image_to_window(cub->ptr,cub->win_cub3d,cub->img_black_screen,0,0);
    while(++a < 500)
    {
        cub->ray_pixels = -1;
        celing_part(cub,a);
        wall_part(cub,a);
        floor_part(cub,a);
    }
}