#include "../cub3d.h"
#include "execution.h"

void lst1_init(s_cub *cub,s_ray *lst1)
{
    lst1->a= -1;
    lst1->y = 30;
    lst1->min_raduis = cub->radien  - 0.57595865315;
    lst1->max_raduis = cub->radien  + 0.57595865315;
    lst1->map_min_raduis = cub->radien  - M_PI;
    lst1->map_max_raduis = cub->radien  + M_PI;
}

void rays_firing(s_cub *cub)
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
        rays_collision(cub,lst1.min_raduis,5000);
        lst1.min_raduis += 0.00076794487; //for 1 ray evry loop
    }
    cub->up_len = collisions_ray_len(cub,cub->radien,25);
    if(cub->up_len < 10)
        cub->up_len = 10;
    cub->down_len = collisions_ray_len(cub,cub->rev_radien,25);
    if(cub->down_len < 10)
        cub->down_len = 10;
    cub->right_len = collisions_ray_len(cub,cub->radien+M_PI/2.0,25);
    if(cub->right_len < 10)
        cub->right_len = 10;
    cub->left_len = collisions_ray_len(cub,cub->rev_radien+M_PI/2.0,25);
    if(cub->left_len < 10)
        cub->left_len = 10;
}