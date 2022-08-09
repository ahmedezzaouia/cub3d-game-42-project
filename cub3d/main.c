/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:54:23 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/04 11:54:33 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "haider.h"

s_cub *cub_init(char **argv)
{
    s_cub *cub;

    cub = malloc(sizeof(s_cub));

    cub->radien = -M_PI/2;
    cub->rev_radien = M_PI/2;
    cub->ceilling_color = NULL;
    cub->east_path = NULL;
    cub->floor_color = NULL;
    cub->map_buffer = NULL;
    cub->north_path = NULL;
    cub->south_path = NULL;
    cub->west_path = NULL;
    cub->buffer = NULL;
    cub->win_cub3d = NULL;
    get_buff_of_map(cub, argv[1]);
    check_north_texture_path(cub);
    check_south_texture_path(cub);
    check_west_texture_path(cub);
    check_east_texture_path(cub);
    cub->F_RGB = get_rgb_color(cub->floor_color);
    cub->C_RGB =  get_rgb_color(cub->ceilling_color);
    check_map_if_valid(cub);
    return (cub);
}
int	ft_close(s_cub *cub)
{
	write(1, "programe exited sucsfull\n", 25);
    mlx_destroy_window(cub->ptr,cub->win);
	exit(0);
	return (0);
}
int update(int keycode, s_cub *cub)
{
    if((keycode == 13 || keycode == 126) && cub->up_len > 10)
    {
        cub->ppy += roundf(sin(cub->radien)*5);
        cub->ppx += roundf(cos(cub->radien)*5);
    }
    if((keycode == 1 || keycode == 125) && cub->down_len > 15)
    {
        cub->ppy -= roundf(sin(cub->radien)*5);
        cub->ppx -= roundf(cos(cub->radien)*5);
    }
    if (keycode == 2 || keycode == 124)
    {
        cub->radien += 0.075;
        cub->rev_radien += 0.075;
    }
    if (keycode == 0 || keycode == 123)
    {
        cub->radien -= 0.075;
        cub->rev_radien -= 0.075;
    }
    if(keycode == 53)
		exit(0);
    update_map(cub);
    engin(cub);
    return (0);
}
void _mlx_init(s_cub *cub)
{
    int a;
    int b;
    
    cub->a_buf = -1;
    cub->x_pixel = 0;
    while(cub->map_buffer[++cub->a_buf])
    {
        cub->b_buf = -1;
        while(cub->map_buffer[cub->a_buf][++cub->b_buf])
        {
            cub->y_pixel = ft_strlen(cub->map_buffer[cub->a_buf]);
            if(cub->x_pixel < cub->y_pixel)
                cub->x_pixel = cub->y_pixel;
        }
    }
    cub->x_pixel *=  30;
    cub->y_pixel = (cub->a_buf + 2) * 30;
    cub->ptr = mlx_init();
    cub->win = mlx_new_window(cub->ptr,cub->x_pixel,cub->y_pixel, "2D_map");
    cub->img_wall = mlx_xpm_file_to_image(cub->ptr,"texture/wall.xpm",&a,&b);
    if(!cub->img_wall)
        printf("here\n");
    cub->img_floor = mlx_xpm_file_to_image(cub->ptr,"texture/floor.xpm",&a,&b);
    if(!cub->img_floor)
        printf("here 1\n");
    cub->img_empty = mlx_xpm_file_to_image(cub->ptr,"texture/black.xpm",&a,&b);
    if(!cub->img_empty)
        printf("here 2\n");
    cub->img_player = mlx_xpm_file_to_image(cub->ptr,"texture/player.xpm",&a,&b);
    if(!cub->img_player)
        printf("here 3\n");
    cub->img_black_screen = mlx_xpm_file_to_image(cub->ptr,"texture/big_black_screen.xpm",&a,&b);
    if(!cub->img_black_screen)
        printf("here 4\n");
    mlx_hook(cub->win, 2, 0L, update, cub);
    mlx_hook(cub->win, 17, 0L, ft_close, cub);
}
int main (int argc,char **argv)
{
    s_cub *cub;
    if(argc != 2)
    {   
        write(2,"Erorr bad number of argumment\n",30);
        return (1);
    }
    check_path_of_map_file(argv[1]);
    cub = cub_init(argv);
    _mlx_init(cub);
    display_2d_map(cub);
    mlx_loop(cub->ptr);
    // system("leaks cub3D");
    return(0);
}
