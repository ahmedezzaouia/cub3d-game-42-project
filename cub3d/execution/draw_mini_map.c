#include "../cub3d.h"
#include "execution.h"

void player_view(s_cub *cub,double radien,int len)
{
    s_line lst;
    double x = 150;
    double y =  150;

    lst_init(cub,&lst,radien,len);
    while(lst.pixels--)
    {
        lst.a = round(((lst.begin_y-15)/30)-1);
        lst.b = round(((lst.begin_x-15)/30)-1);
        if((lst.a > -1 && lst.a < cub->a_map_buf))
        {
            if((lst.b > -1 && lst.b < cub->b_map_buf[lst.a]))
            {
            if(cub->map_buffer[lst.a][lst.b] != '1')
            {
                if(lst.d-- > 0)
                    img_pixel_put(cub,(int)x,(int)y,0xFFFFFF);
            }
            else
                break;
            }
        }
        x += lst.deltaX;
        y += lst.deltaY;
        lst.begin_x += lst.deltaX;
        lst.begin_y += lst.deltaY;
    }
}

void maps_ray_collision(s_cub *cub,double radien,int len)
{
    s_line lst;
    double x = 150;
    double y =  150;

    lst_init(cub,&lst,radien,len);
    while(lst.pixels--)
    {
        lst.a = round(((lst.begin_y-15)/30)-1);
        lst.b = round(((lst.begin_x-15)/30)-1);
        if((lst.a > -1 && lst.a < cub->a_map_buf))
            if((lst.b > -1 && lst.b < cub->b_map_buf[lst.a]))
                if(cub->map_buffer[lst.a][lst.b] == '1')
               img_pixel_put(cub,(int)x,(int)y,0x331A66);
        x += lst.deltaX;
        y += lst.deltaY;
        lst.begin_x += lst.deltaX;
        lst.begin_y += lst.deltaY;
    }
}

void txt_img_pixel_put(s_cub *cub,int x, int y)
{
    int     txt_index;
    int     index;

    txt_index = (y * cub->img[5]->line_len + x * (cub->img[5]->bpp / 8));
    index = (y * cub->img[0]->line_len + x * (cub->img[0]->bpp / 8));
    // printf("r %d g %d b %d\n",cub->img[5]->addr[txt_index],cub->img[5]->addr[txt_index+1],cub->img[5]->addr[txt_index+2]);
    if (!*(int *)(cub->img[5]->addr + (y * cub->img[5]->line_len) + (x * (cub->img[5]->bpp / 8))))
    {
        cub->img[0]->addr[index] = (int)cub->img[5]->addr[txt_index];
        cub->img[0]->addr[index+1] = (int)cub->img[5]->addr[txt_index+1];
        cub->img[0]->addr[index+2] = (int)cub->img[5]->addr[txt_index+2];
    }
}

void black_mini_map(s_cub *cub)
{
    int a;
    int b;

    a = -1;
    while(++a < 325)
    {
        b = -1;
        while(++b < 324)
            txt_img_pixel_put(cub,a,b);
    }
}

void draw_line(s_cub *cub)
{
    s_ray lst1;

    lst1_init(cub,&lst1);
    black_mini_map(cub);
    while(cub->map_buffer[++lst1.a])
    {
        lst1.b = -1;
        lst1.x = 30;
        while(cub->map_buffer[lst1.a][++lst1.b])
            lst1.x += 30;
        lst1.y += 30;
    }
    while(lst1.map_min_raduis < lst1.map_max_raduis)
    {
        maps_ray_collision(cub,lst1.map_min_raduis,125);
        if(lst1.map_min_raduis > lst1.min_raduis
            && lst1.map_min_raduis < lst1.max_raduis)
            player_view(cub,lst1.map_min_raduis,125);
        lst1.map_min_raduis += 0.00076794487*10; //for 1 ray evry loop
    }
    mlx_put_image_to_window(cub->ptr,cub->win_cub3d,cub->img_of_screen,0,0);
    mlx_string_put(cub->ptr,cub->win_cub3d,145,25,0xffffff,"N");
}