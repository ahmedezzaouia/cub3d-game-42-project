#include "../cub3d.h"
#include "execution.h"

double ray_collision_len(s_cub *cub, double radian,int len)
{
    s_line lst;

    lst_init1(cub,&lst,radian,len);
    while(lst.pixels--)
    {
        lst.a = round(((lst.begin_y-15)/30)-1);
        lst.b = round(((lst.begin_x-15)/30)-1);
        if((lst.a > -1 && lst.a < 14) && (lst.b > -1 && lst.b<33))
        {
            if(cub->map_buffer[lst.a][lst.b] == '1')
                return(sqrt(pow((cub->ppy-round(lst.begin_y)),2)
                        + pow(cub->ppx-round(lst.begin_x),2)));
        }
        mlx_pixel_put(cub->ptr,cub->win,lst.begin_x,lst.begin_y,0xff0000);
        lst.begin_x += lst.deltaX;
        lst.begin_y += lst.deltaY;
    }
  return(240);
}