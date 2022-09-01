#include "cub3d.h"

s_cub	*cub_init_2(void)
{
	int a;
	s_cub	*cub;

	a = -1;
	cub = malloc(sizeof(s_cub));
	if (!cub)
		ft_error("allocation error for 's_cub *cub'");
	cub->img = malloc(sizeof(s_img *) * 6);
	if(!cub->img)
			ft_error("cant allocat pointer of img struct");
	while(++a < 6)
	{
		cub->img[a] = malloc(sizeof(s_img));
		if(!cub->img[a])
			ft_error("cant allocat img struct");
	}
	return (cub);
}

s_cub	*cub_init(char **argv)
{
	s_cub	*cub;

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
	player_pos(cub);
	mlx_hook(cub->win_cub3d, 2, 0L, key_press, cub);
	mlx_hook(cub->win_cub3d, 6, 0L, mouse_mv, cub);
	mlx_hook(cub->win_cub3d, 17, 0L, ft_close, cub);
	mlx_loop_hook(cub->ptr,update,cub);
	mlx_loop(cub->ptr);
	return(0);
}