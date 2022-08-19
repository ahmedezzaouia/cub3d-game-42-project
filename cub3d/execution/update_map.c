#include "../cub3d.h"
#include "execution.h"

void lst1_init(s_cub *cub,s_ray *lst1)
{
    lst1->a= -1;
    lst1->y = 30;
    lst1->min_raduis = cub->radien  - 0.57595865315;
    lst1->max_raduis = cub->radien  + 0.57595865315;
}

void update_map_2(s_cub *cub,s_ray *lst1)
{
    (void) cub;
    // if(cub->map_buffer[lst1->a][lst1->b] == '1')
    //     mlx_put_image_to_window(cub->ptr,cub->win,cub->img_wall,lst1->x,lst1->y);
    // else if(cub->map_buffer[lst1->a][lst1->b] == '0')
    //     mlx_put_image_to_window(cub->ptr,cub->win,cub->img_floor,lst1->x,lst1->y);
    // else if(cub->map_buffer[lst1->a][lst1->b] == ' ')
    //     mlx_put_image_to_window(cub->ptr,cub->win,cub->img_empty,lst1->x,lst1->y);
    // else if(cub->map_buffer[lst1->a][lst1->b] == 'N')
    //     mlx_put_image_to_window(cub->ptr,cub->win,cub->img_floor,lst1->x,lst1->y);
    lst1->x += 30;
}

void update_map(s_cub *cub)
{
    s_ray lst1;

    lst1_init(cub,&lst1);
    while(cub->map_buffer[++lst1.a])
    {
        lst1.b = -1;
        lst1.x = 30;
        while(cub->map_buffer[lst1.a][++lst1.b])
            update_map_2(cub,&lst1);
        lst1.y += 30;
    }
    while(lst1.min_raduis < lst1.max_raduis)
    {
        draw_line(cub,lst1.min_raduis,5000);
        lst1.min_raduis += 0.00230383461; //for 1 ray evry loop
    }
    cub->up_len = ray_collision_len(cub,cub->radien,25);
    if(cub->up_len < 10)
        cub->up_len = 10;
    cub->down_len = ray_collision_len(cub,cub->rev_radien,25);
    if(cub->down_len < 10)
        cub->down_len = 10;
    // mlx_put_image_to_window(cub->ptr,cub->win,cub->img_player,cub->ppx,cub->ppy);
}