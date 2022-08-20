#include "../cub3d.h"
#include "execution.h"

void lst1_init(s_cub *cub,s_ray *lst1)
{
    lst1->a= -1;
    lst1->y = 30;
    lst1->min_raduis = cub->radien  - M_PI/2;
    lst1->max_raduis = cub->radien  + M_PI/2;
}

void lst_init1(s_cub *cub, s_line *lst, double radien, int len)
{
    cub->end_ray_x = len*cos(radien) + cub->ppx;
    cub->end_ray_y = len*sin(radien) + cub->ppy;
    lst->deltaX = cub->end_ray_x - cub->ppx;
    lst->deltaY = cub->end_ray_y - cub->ppy;
    lst->pixels = sqrt((lst->deltaX*lst->deltaX)+(lst->deltaY*lst->deltaY));
    lst->deltaX /= lst->pixels;
    lst->deltaY /= lst->pixels;
    lst->begin_x =cub->ppx+5;
    lst->begin_y =cub->ppy+5;
    lst->a = -1;
    lst->b = -1;
    lst->d = 75;
}

void maps_ray_collision(s_cub *cub,double radien,int len)
{
    s_line lst;

    lst_init1(cub,&lst,radien,len);
    while(lst.pixels--)
    {
        lst.a = round(((lst.begin_y-15)/30)-1);
        lst.b = round(((lst.begin_x-15)/30)-1);
        if(lst.d-- > 0)
            img_pixel_put(cub, lst.begin_x, lst.begin_y,16777215);
        img_pixel_put(cub, lst.begin_x, lst.begin_y, 0x331A66);
        lst.begin_x += lst.deltaX;
        lst.begin_y += lst.deltaY;
    }
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
    while(lst1.min_raduis < lst1.max_raduis)
    {
        maps_ray_collision(cub,lst1.min_raduis,250);
        lst1.min_raduis += 0.00076794487; //for 1 ray evry loop
    }
}