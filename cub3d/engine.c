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


void txt_img_pixel_put(s_img *walls_txt,s_img *img,int x, int y,int txt_x,int txt_y)
{
    int     txt_index;
    int     index;

    (void) txt_x;
    (void) txt_y;
    txt_index = (txt_y * walls_txt->line_len + txt_x * (walls_txt->bpp / 8));
    index = (y * img->line_len + x * (img->bpp / 8));
    img->addr[index] = 0;
	img->addr[index] = (int)walls_txt->addr[txt_index];
    img->addr[index+1] = (int)walls_txt->addr[txt_index+1];
    img->addr[index+2] = (int)walls_txt->addr[txt_index+2];
}
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
    s_img walls_txt;
    int loop;
    float ppl;
    int txt_x;
    int txt_y;
    int y;
    (void) cub;
    (void) img;
    loop = -1;
    y = -1;
    ppl = cub->wall_px/64.0;
    walls_txt.addr = mlx_get_data_addr(cub->north_wall,&walls_txt.bpp,&walls_txt.line_len,&walls_txt.endien);
    while(++loop < cub->wall_px)
    {
        ++cub->ray_pixels;
        if(cub->color_of_wall[a/3] == 16777215)
        {
            ++y;
            if(ppl >= 1)
            {
                txt_y = y/ppl;
                txt_x = a/ppl;
            }
            else if(ppl < 1)
            {
                txt_y = y*(1/ppl);
                txt_x = a*(1/ppl);
            }
            if(a/3 == 250)
                printf("wall len %d ppl %f y%d\n",cub->wall_px,ppl,txt_y);
            if(txt_y > 63 && txt_x > 64)
                break;
            txt_img_pixel_put(&walls_txt,img,a,cub->ray_pixels,txt_x%64,txt_y);
        }
        else
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