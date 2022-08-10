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


// void img_pixel_put(s_img *img,int x, int y, int color)
// {
//     int  index;

//     // printf("here\n");
//     index = (y * img->line_len + x * (img->bpp / 8));
//     // printf("%d\n",index);
// 	img->addr[index] = color;
// }
void	img_pixel_put(s_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len) + (x * (img->bpp / 8));
	*(int *)pixel = color;
}

void celing_part(s_cub *cub,s_img *img,int a)
{
    (void) cub;
    (void) img;
    cub->wall_px = (64 / cub->ray_len[a/3]) * 255;
    cub->celing_px = 450 - (cub->wall_px/2);
    while(++cub->ray_pixels < cub->celing_px)
        img_pixel_put(img,a,cub->ray_pixels,0x484B47);
}
void wall_part(s_cub *cub,s_img *img,int a)
{
    int loop;

    loop = -1;
    (void) cub;
    (void) img;
    while(++loop < cub->wall_px)
    {
        ++cub->ray_pixels;
        img_pixel_put(img,a,cub->ray_pixels,cub->color_of_wall[a/3]);
    }
}
void floor_part(s_cub *cub,s_img *img,int a)
{
    (void) cub;
    (void) img;
    while(++cub->ray_pixels < 900)
        img_pixel_put(img,a,cub->ray_pixels,0x3A6F7E); 
}
void engin(s_cub *cub)
{
    s_img img;
    int a;

    (void) cub;
    if(!cub->win_cub3d)
    {
        cub->win_cub3d = mlx_new_window(cub->ptr,1500,900, "Cub3D");
        cub->img_of_screen = mlx_new_image(cub->ptr,1500,900);
    }
    img.addr = mlx_get_data_addr(cub->img_of_screen,&img.bpp,&img.line_len,&img.endien);
    mlx_put_image_to_window(cub->ptr,cub->win_cub3d,cub->img_black_screen,0,0);
    a  =-1;
    // printf("here1\n");
    while(++a < 1500)
    {
        cub->ray_pixels = -1;
        celing_part(cub,&img,a);
        wall_part(cub,&img,a);
        floor_part(cub,&img,a);
    }
    // printf("here2\n");
    mlx_put_image_to_window(cub->ptr,cub->win_cub3d,cub->img_of_screen,0,0);
}