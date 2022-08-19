/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:59:27 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/18 11:59:35 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"
# include "./parssing/parssing.h"

typedef struct t_list
{
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*floor_color;
	char	*ceilling_color;
	char	**map_buffer;
	char	*buffer;
	int		*f_rgb;
	int		*c_rgb;

	void	*win;
	void	*ptr;
	void	*img_wall;
	void	*img_floor;
	void	*img_empty;
	void	*img_player;
	int		x_pixel;
	int		y_pixel;
	int		px;
	int		py;
	int		ppx;
	int		ppy;
	void	*win_cub3d;
	void	*img_black_screen;
	void	*img_of_screen;
	void	*north_wall;
	void	*south_wall;
	void	*west_wall;
	void	*east_wall;
	int		end_ray_x;
	int		end_ray_y;
	double	radien;
	double	rev_radien;
	int		ray_pixels;
	int		celing_px;
	int		wall_px;
	int		floor_px;
	double	ray_len[500];
	int		color_of_wall[500];
	int		wall_width[100];
	double	up_len;
	double	down_len;
}	s_cub;

typedef struct t_img
{
	char	*addr;
	int		line_len;
	int		bpp;
	int		endien;
}	s_img;

// utilitis functions
int		ft_strlen(char *str);
int		ft_strncmp2(char *S1, char *S2, int num);
int		ft_strcmp(char *S1, char *S2);
char	*ft_strjoin(char *s1, char *s2);
double	ft_to_radien(int degree);
void	ft_error(char *error);
char	*get_next_line(int fd);

// parssing part
void	_mlx_init(s_cub *cub);
void	check_path_of_map_file(char *path);
void	get_buff_of_map(s_cub *cub, char *path);
char	*get_texture_path(char *ptr);
void	check_north_texture_path(s_cub *cub);
void	check_south_texture_path(s_cub *cub);
void	check_west_texture_path(s_cub *cub);
void	check_east_texture_path(s_cub *cub);
int		*get_rgb_color(char *str);
void	check_map_if_valid(s_cub *cub);
void	ft_calc_size_of_img(s_cub *cub);

//execution part
void	display_2d_map(s_cub *cub);
void	update_map(s_cub *cub);
void	ft_calc_width_walls(s_cub *cub, int a, int b);
void	engin(s_cub *cub);

#endif
