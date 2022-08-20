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
        if((lst.a > -1 && lst.a < 14) && (lst.b > -1 && lst.b<33))
        {
            if(cub->map_buffer[lst.a][lst.b] != '1')
            {
                if(lst.d-- > 0)
                    img_pixel_put(cub,(int)x,(int)y,0x000000);
            }
            else
                break;
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
        if((lst.a > -1 && lst.a < 14) && (lst.b > -1 && lst.b < 33))
            if(cub->map_buffer[lst.a][lst.b] == '1')
               img_pixel_put(cub,(int)x,(int)y,0x331A66);
        // img_pixel_put(cub, lst.begin_x, lst.begin_y, 0x331A66);
        x += lst.deltaX;
        y += lst.deltaY;
        lst.begin_x += lst.deltaX;
        lst.begin_y += lst.deltaY;
    }
    // mlx_pixel_put(cub->ptr,cub->win_cub3d,x,y,0);
}

void draw_line(s_cub *cub)
{
    s_ray lst1;

    lst1_init(cub,&lst1);
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
        lst1.map_min_raduis += 0.00076794487; //for 1 ray evry loop
    }
    mlx_put_image_to_window(cub->ptr,cub->win_cub3d,cub->img_of_screen,0,0);
    mlx_string_put(cub->ptr,cub->win_cub3d,145,25,0xffffff,"N");
}