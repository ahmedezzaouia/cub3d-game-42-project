#include "cub3d.h"

s_cub	*cub_init(char **argv)
{
	s_cub	*cub;

	cub = malloc(sizeof(s_cub));
	if (!cub)
		ft_error("allocation error for 's_cub *cub'");
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
	get_buff_of_map(cub, argv[1]);
	check_north_texture_path(cub);
	check_south_texture_path(cub);
	check_west_texture_path(cub);
	check_east_texture_path(cub);
	cub->f_rgb = get_rgb_color(cub->floor_color);
	cub->c_rgb = get_rgb_color(cub->ceilling_color);
	return (cub);
}

int main (int argc,char **argv)
{
	s_cub	*cub;

	if (argc != 2)
		ft_error("bad number of argumment");
	check_path_of_map_file(argv[1]);
	cub = cub_init(argv);
	check_map_if_valid(cub);
	_mlx_init(cub);
	display_2d_map(cub);
	mlx_loop(cub->ptr);
	return(0);
}