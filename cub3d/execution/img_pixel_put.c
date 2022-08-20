#include "../cub3d.h"
#include "execution.h"

void txt_img_pixel_put1(s_cub *cub,s_img *img,int x, int y,int txt_x,int txt_y)
{
    int     txt_index;
    int     index;

    (void) txt_x;
    (void) txt_y;
    if((x < 1500 && y < 900) && (txt_x < 64 && txt_y < 64))
    {
        txt_index = (txt_y * img->line_len + txt_x * (img->bpp / 8));
        index = (y * cub->img[0]->line_len + x * (cub->img[0]->bpp / 8));
        cub->img[0]->addr[index] = (int)img->addr[txt_index];
        cub->img[0]->addr[index+1] = (int)img->addr[txt_index+1];
        cub->img[0]->addr[index+2] = (int)img->addr[txt_index+2];
    }
}

void	img_pixel_put(s_cub *cub, int x, int y, int color)
{
	char    *pixel;

    if(x < 1500 && y < 900)
    {
        pixel = cub->img[0]->addr + (y * cub->img[0]->line_len) + (x * (cub->img[0]->bpp / 8));
	    *(int *)pixel = color;
    }
}