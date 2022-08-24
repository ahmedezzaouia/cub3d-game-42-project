#include "../cub3d.h"
#include "execution.h"

void ray_len_2(s_cub *cub, s_line *lst,int c) 
{
    if(((int)(lst->begin_y+18)) % 64 == 0 || (int)(lst->begin_y+17) % 64 == 0)
        cub->ray_hit_pos[c] = ((int)lst->begin_x+17)%64;
    else if(((int)(lst->begin_x+18)) % 64 == 0 || (int)(lst->begin_x+17) % 64 == 0)
        cub->ray_hit_pos[c] = ((int)lst->begin_y+17)%64;
}

void ray_len(s_cub *cub, s_line *lst, double radien)
{
    static int c = -1;

    if(c == 1500)
        c = -1;
    if(radien < -M_PI/2)
        cub->ray_len[++c] = sqrt(pow((cub->ppy-round(lst->begin_y)),2)
            + pow(cub->ppx-round(lst->begin_x),2))*cos(-radien+(cub->radien));
    else
        cub->ray_len[++c] = sqrt(pow((cub->ppy-round(lst->begin_y)),2)
            + pow(cub->ppx-round(lst->begin_x),2))*cos(radien-(cub->radien));
    if(cub->ray_len[c] < 10)
        cub->ray_len[c] = 10;
    if(((int)(lst->begin_y+18)) % 64 == 0 && ((int)(lst->begin_x+17)) % 64 != 0
        && ((int)(lst->begin_x+18)) % 64 != 0 && lst->begin_y < cub->ppy+5)
        cub->color_of_wall[c] = 16777215;
    else if(((int)(lst->begin_y+18)) % 64 == 0 && cub->color_of_wall[c-1] == 16777215)
        cub->color_of_wall[c] = 16777215;
    else if((int)(lst->begin_y+17) % 64 == 0 && ((int)(lst->begin_x+17)) % 64 != 0
        && ((int)(lst->begin_x+18)) % 64 != 0 && lst->begin_y > cub->ppy+5)
        cub->color_of_wall[c] = 11997714;
    else if((int)(lst->begin_y+17) % 64 == 0 && cub->color_of_wall[c-1] == 11997714)
        cub->color_of_wall[c] = 11997714;
    else if (((int)(lst->begin_x+18)) % 64 == 0 && lst->begin_x < cub->ppx+5)
        cub->color_of_wall[c] = 8654765;
    else if ((int)(lst->begin_x+17) % 64 == 0 && lst->begin_x > cub->ppx+5)
        cub->color_of_wall[c] = 1012909;
    ray_len_2(cub,lst,c);
}
