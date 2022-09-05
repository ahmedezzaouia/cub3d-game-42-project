/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:17:36 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/05 22:31:06 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub	*cub_init_2(void)
{
	int		a;
	t_cub	*cub;

	a = -1;
	cub = malloc(sizeof(t_cub));
	if (!cub)
		ft_error("allocation error for 't_cub *cub'");
	cub->img = malloc(sizeof(t_img *) * 6);
	if (!cub->img)
		ft_error("cant allocat pointer of img struct");
	while (++a < 6)
	{
		cub->img[a] = malloc(sizeof(t_img));
		if (!cub->img[a])
			ft_error("cant allocat img struct");
	}
	return (cub);
}

t_cub	*cub_init(char **argv)
{
	t_cub	*cub;

	(void)argv;
	cub = cub_init_2();
	cub->radien = -M_PI / 2;
	cub->rev_radien = M_PI / 2;
	cub->ceilling_color = NULL;
	cub->east_path = NULL;
	cub->floor_color = NULL;
	cub->map_buffer = NULL;
	cub->north_path = NULL;
	cub->south_path = NULL;
	cub->west_path = NULL;
	cub->buffer = NULL;
	return (cub);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		ft_error("bad number of argumment");
	cub = cub_init(argv);
	validate_map(cub, argv[1]);
	_mlx_init(cub);
	get_len_of_map(cub);
	player_pos(cub);
	mlx_hook(cub->win_cub3d, 2, 0L, key_press, cub);
	mlx_hook(cub->win_cub3d, 6, 0L, mouse_mv, cub);
	mlx_hook(cub->win_cub3d, 17, 0L, ft_close, cub);
	mlx_loop_hook(cub->ptr, update, cub);
	mlx_loop(cub->ptr);
	return (0);
}
