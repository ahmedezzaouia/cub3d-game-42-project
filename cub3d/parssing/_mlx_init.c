/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:58:21 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/18 13:58:51 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_close(s_cub *cub)
{
	write(1, "programe exited sucsfull\n", 25);
	mlx_destroy_window(cub->ptr, cub->win);
	exit(0);
	return (0);
}

int	update(int keycode, s_cub *cub)
{
	if ((keycode == 13 || keycode == 126) && cub->up_len > 15)
	{
		cub->ppy += roundf(sin(cub->radien) * 5);
		cub->ppx += roundf(cos(cub->radien) * 5);
	}
	if ((keycode == 1 || keycode == 125) && cub->down_len > 15)
	{
		cub->ppy -= roundf(sin(cub->radien) * 5);
		cub->ppx -= roundf(cos(cub->radien) * 5);
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
	if (keycode == 53)
		ft_error("cub3D exited successful");
	rays_firing(cub);
	ft_calc_width_walls(cub, -1, -1);
	engin(cub, -1, 0);
	draw_line(cub);
	return (0);
}

void	_mlx_init_2(s_cub *cub)
{
	int	a;
	int	b;
	cub->img_black_screen = mlx_xpm_file_to_image(cub->ptr,
			"texture/big_black_screen.xpm", &a, &b);
	if (!cub->img_black_screen)
		ft_error("can't get img_black_screen data");
	cub->north_wall = mlx_xpm_file_to_image(cub->ptr,
			"texture/mabdelou-30px.xpm", &a, &b);
	if (!cub->north_wall)
		ft_error("can't get img_north_wall data");
	cub->south_wall = mlx_xpm_file_to_image(cub->ptr,
			"texture/small_ael-hayy_1.xpm", &a, &b);
	if (!cub->south_wall)
		ft_error("can't get img_south_wall data");
	cub->west_wall = mlx_xpm_file_to_image(cub->ptr,
			"texture/small_mamellal_1.xpm", &a, &b);
	if (!cub->west_wall)
		ft_error("can't get img_west_wall data");
	cub->east_wall = mlx_xpm_file_to_image(cub->ptr,
			"texture/small_oouazize_1.xpm", &a, &b);
	if (!cub->east_wall)
		ft_error("can't get img_east_wall data");
	cub->img[0]->addr = mlx_get_data_addr(cub->img_of_screen, &cub->img[0]->bpp, &cub->img[0]->line_len, &cub->img[0]->endien);
	cub->img[1]->addr = mlx_get_data_addr(cub->east_wall,&cub->img[1]->bpp,&cub->img[1]->line_len,&cub->img[1]->endien);
	cub->img[2]->addr = mlx_get_data_addr(cub->west_wall,&cub->img[2]->bpp,&cub->img[2]->line_len,&cub->img[2]->endien);
	cub->img[3]->addr = mlx_get_data_addr(cub->south_wall,&cub->img[3]->bpp,&cub->img[3]->line_len,&cub->img[3]->endien);
	cub->img[4]->addr = mlx_get_data_addr(cub->north_wall,&cub->img[4]->bpp,&cub->img[4]->line_len,&cub->img[4]->endien);
}

void	_mlx_init_1(s_cub *cub)
{
	int	a;
	int	b;

	cub->ptr = mlx_init();
    cub->win_cub3d = mlx_new_window(cub->ptr,1500,900, "Cub3D");
	if(!cub->win_cub3d)
		ft_error("cant make cub3d_win");
	cub->img_of_screen = mlx_new_image(cub->ptr,1500,900);
    if(!cub->img_of_screen)
        ft_error("can't make img_of_screen");
	// cub->win = mlx_new_window(cub->ptr, cub->x_pixel, cub->y_pixel, "2D_map");
	cub->img_wall = mlx_xpm_file_to_image(cub->ptr, "texture/wall.xpm", &a, &b);
	if (!cub->img_wall)
		ft_error("can't get img_wall data");
	cub->img_floor = mlx_xpm_file_to_image(cub->ptr,
			"texture/floor.xpm", &a, &b);
	if (!cub->img_floor)
		ft_error("can't get img_floor data");
	cub->img_empty = mlx_xpm_file_to_image(cub->ptr,
			"texture/black.xpm", &a, &b);
	if (!cub->img_empty)
		ft_error("can't get img_empty data");
	cub->img_player = mlx_xpm_file_to_image(cub->ptr,
			"texture/player.xpm", &a, &b);
	if (!cub->img_player)
		ft_error("can't get img_player data");
}

void	_mlx_init(s_cub *cub)
{
	ft_calc_size_of_img(cub);
	_mlx_init_1(cub);
	_mlx_init_2(cub);
}
