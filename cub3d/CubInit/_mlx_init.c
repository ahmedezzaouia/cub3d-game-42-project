/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:58:21 by mabdelou          #+#    #+#             */
/*   Updated: 2022/09/05 22:27:15 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_images(int a, int b, s_cub *cub)
{
	cub->img_black_screen = mlx_xpm_file_to_image(cub->ptr,
			"./texture/big_black_screen.xpm", &a, &b);
	if (!cub->img_black_screen)
		ft_error("can't get img_black_screen data");
	cub->north_wall = mlx_xpm_file_to_image(cub->ptr,
			cub->north_path, &a, &b);
	if (!cub->north_wall)
		ft_error("can't get img_north_wall data");
	cub->south_wall = mlx_xpm_file_to_image(cub->ptr,
			cub->south_path, &a, &b);
	if (!cub->south_wall)
		ft_error("can't get img_south_wall data");
	cub->west_wall = mlx_xpm_file_to_image(cub->ptr,
			cub->west_path, &a, &b);
	if (!cub->west_wall)
		ft_error("can't get img_west_wall data");
	cub->east_wall = mlx_xpm_file_to_image(cub->ptr,
			cub->east_path, &a, &b);
	if (!cub->east_wall)
		ft_error("can't get img_east_wall data");
	cub->minimap = mlx_xpm_file_to_image(cub->ptr,
			"./Texture/minimap.xpm", &a, &b);
}

void	_mlx_init_2(s_cub *cub)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	set_images(a, b, cub);
	if (!cub->minimap)
		ft_error("can't get img_minimap data");
	cub->img[0]->addr = mlx_get_data_addr(cub->img_of_screen, \
			&cub->img[0]->bpp, \
			&cub->img[0]->line_len, &cub->img[0]->endien);
	cub->img[1]->addr = mlx_get_data_addr(cub->east_wall, \
			&cub->img[1]->bpp, &cub->img[1]->line_len, \
			&cub->img[1]->endien);
	cub->img[2]->addr = mlx_get_data_addr(cub->west_wall, \
			&cub->img[2]->bpp, &cub->img[2]->line_len, \
			&cub->img[2]->endien);
	cub->img[3]->addr = mlx_get_data_addr(cub->south_wall, \
			&cub->img[3]->bpp, &cub->img[3]->line_len, \
			&cub->img[3]->endien);
	cub->img[4]->addr = mlx_get_data_addr(cub->north_wall, \
			&cub->img[4]->bpp, &cub->img[4]->line_len, \
			&cub->img[4]->endien);
	cub->img[5]->addr = mlx_get_data_addr(cub->minimap, \
			&cub->img[5]->bpp, &cub->img[5]->line_len, &cub->img[5]->endien);
}

void	_mlx_init_1_norm(s_cub *cub, int a, int b)
{
	if (!cub->img_empty)
		ft_error("can't get img_empty data");
	cub->img_player = mlx_xpm_file_to_image(cub->ptr,
			"./Texture/player.xpm", &a, &b);
	if (!cub->img_player)
		ft_error("can't get img_player data");
}

void	_mlx_init_1(s_cub *cub)
{
	int	a;
	int	b;

	cub->ptr = mlx_init();
	cub->win_cub3d = mlx_new_window(cub->ptr, 1500, 900, "Cub3D");
	if (!cub->win_cub3d)
		ft_error("cant make cub3d_win");
	cub->img_of_screen = mlx_new_image(cub->ptr, 1500, 900);
	if (!cub->img_of_screen)
		ft_error("can't make img_of_screen");
	cub->img_wall = mlx_xpm_file_to_image(cub->ptr, \
		"./Texture/wall.xpm", &a, &b);
	if (!cub->img_wall)
		ft_error("can't get img_wall data");
	cub->img_floor = mlx_xpm_file_to_image(cub->ptr,
			"./Texture/floor.xpm", &a, &b);
	if (!cub->img_floor)
		ft_error("can't get img_floor data");
	cub->img_empty = mlx_xpm_file_to_image(cub->ptr,
			"./Texture/black.xpm", &a, &b);
	_mlx_init_1_norm(cub, a, b);
}

void	_mlx_init(s_cub *cub)
{
	get_len_of_map(cub);
	_mlx_init_1(cub);
	_mlx_init_2(cub);
}
