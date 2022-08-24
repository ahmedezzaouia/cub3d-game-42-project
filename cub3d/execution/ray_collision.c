#include "../cub3d.h"
#include "execution.h"

void lst_init(s_cub *cub, s_line *lst, double radien, int len)
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
void rays_collision(s_cub *cub,double radien,int len)
{
    s_line lst;

    lst_init(cub,&lst,radien,len);
    while(lst.pixels--)
    {
        lst.a = round(((lst.begin_y-15)/64)-1);
        lst.b = round(((lst.begin_x-15)/64)-1);
        if((lst.a > -1 && lst.a < cub->a_map_buf))
        {
            if((lst.b > -1 && lst.b < cub->b_map_buf[lst.a]))
            {
                if(cub->map_buffer[lst.a][lst.b] == '1')
                {
                    ray_len(cub, &lst ,radien);
                    break;
                }
            }
        }
        lst.begin_x += lst.deltaX;
        lst.begin_y += lst.deltaY;
    }
}