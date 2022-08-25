#include "../cub3d.h"
#include "execution.h"
double collisions_ray_len(s_cub *cub, double radian)
{
    s_line lst;

    lst_init_(cub,&lst,radian,5);
    while(lst.pixels--)
    {
        lst.b = round(((lst.begin_x-15)/32)-1);
        lst.a = round(((lst.begin_y-15)/32)-1);
        if((lst.a > -1 && lst.a < 14) && (lst.b > -1 && lst.b<33))
        {
            if(cub->map_buffer[lst.a][lst.b] == '1')
                return(0);
        }
        lst.begin_x += lst.deltaX;
        lst.begin_y += lst.deltaY;
    }
  return(1);
}