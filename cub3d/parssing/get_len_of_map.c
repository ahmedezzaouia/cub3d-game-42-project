#include "../cub3d.h"

void get_len_of_map(s_cub * cub)
{
    int a;

    a = -1;
    while(cub->map_buffer[++a])
        ;
    cub->b_map_buf = malloc(sizeof(int) * a);
    if(!cub->b_map_buf)
        ft_error("can't allocated for b_map_buf");
    a = -1;
    while(cub->map_buffer[++a])
        cub->b_map_buf[a] = ft_strlen(cub->map_buffer[a]);
    cub->a_map_buf = a;
}