#include "../cub3d.h"
#include "execution.h"

double collisions_ray_len(s_cub *cub, double radian,int len)
{
    s_line lst;

    lst_init(cub,&lst,radian,len);
    while(lst.pixels--)
    {
        lst.a = round(((lst.begin_y-15)/64)-1);
        lst.b = round(((lst.begin_x-15)/64)-1);
        if((lst.a > -1 && lst.a < 14) && (lst.b > -1 && lst.b<33))
        {
            if(cub->map_buffer[lst.a][lst.b] == '1')
                return(sqrt(pow((cub->ppy-round(lst.begin_y)),2)
                        + pow(cub->ppx-round(lst.begin_x),2)));
        }
        lst.begin_x += lst.deltaX;
        lst.begin_y += lst.deltaY;
    }
  return(240);
}