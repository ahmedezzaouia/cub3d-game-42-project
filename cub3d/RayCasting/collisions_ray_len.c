#include "../cub3d.h"
#include "execution.h"


// int check_directions(s_cub *cub, double radian)
// {
//     s_line lst;

//     lst_init_(cub,&lst,radian,10);
//     if(lst.begin_x < (lst.begin_x+lst.deltaX))
//         return (0);
//     else if (lst.begin_y < (lst.begin_y+lst.deltaY))
//         return (0);
//     return (1);
// }

int collisions_ray_len(s_cub *cub, double radian,int len)
{
    s_line lst;

    lst_init_(cub,&lst,radian,len);
    // if(!check_directions(cub,radian))
    //     lst_init_(cub,&lst,radian,len+10);
    while(lst.pixels--)
    {
        lst.b = round(((lst.begin_x-15)/32)-1);
        lst.a = round(((lst.begin_y-15)/32)-1);
        if((lst.a > -1 && lst.a < cub->a_map_buf))
        {
            if((lst.b > -1 && lst.b < cub->b_map_buf[lst.a]))
            {
                if(cub->map_buffer[lst.a][lst.b] == '1')
                    return(0);
            }
        }
        lst.begin_x += lst.deltaX;
        lst.begin_y += lst.deltaY;
    }
    lst_init_(cub,&lst,radian-0.78,len);
    while(lst.pixels--)
    {
        lst.b = round(((lst.begin_x-15)/32)-1);
        lst.a = round(((lst.begin_y-15)/32)-1);
        if((lst.a > -1 && lst.a < cub->a_map_buf))
        {
            if((lst.b > -1 && lst.b < cub->b_map_buf[lst.a]))
            {
                if(cub->map_buffer[lst.a][lst.b] == '1')
                    return(0);
            }
        }
        lst.begin_x += lst.deltaX;
        lst.begin_y += lst.deltaY;
    }
    lst_init_(cub,&lst,radian+0.78,len);
    while(lst.pixels--)
    {
        lst.b = round(((lst.begin_x-15)/32)-1);
        lst.a = round(((lst.begin_y-15)/32)-1);
        if((lst.a > -1 && lst.a < cub->a_map_buf))
        {
            if((lst.b > -1 && lst.b < cub->b_map_buf[lst.a]))
            {
                if(cub->map_buffer[lst.a][lst.b] == '1')
                    return(0);
            }
        }
        lst.begin_x += lst.deltaX;
        lst.begin_y += lst.deltaY;
    }
  return(1);
}