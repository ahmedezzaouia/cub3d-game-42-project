/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:29:38 by mabdelou          #+#    #+#             */
/*   Updated: 2022/09/05 22:29:30 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../cub3d.h"

typedef struct t_line
{
	double	begin_x;
	double	begin_y;
	double	deltax;
	double	deltay;
	int		pixels;
	int		a;
	int		b;
	int		d;
}	t_line;

typedef struct t_ray
{
	int		a;
	int		b;
	int		x;
	int		y;
	double	min_raduis;
	double	max_raduis;
	double	map_min_raduis;
	double	map_max_raduis;

}	t_ray;

void	rays_collision(t_cub *cub, double radien, int len);
void	lst1_init(t_cub *cub, t_ray *lst1);
void	lst1_init_(t_cub *cub, t_ray *lst1);
void	lst_init(t_cub *cub, t_line *lst, double radien, int len);
void	lst_init_(t_cub *cub, t_line *lst, double radien, int len);
int		collisiont_ray_len(t_cub *cub, double radian, int len);
void	ray_len(t_cub *cub, t_line *lst, double radien);
void	txt_img_pixel_put1(t_cub *cub, t_img *img,
			int x, int y);
void	txt_img_pixel_put(t_cub *cub, int x, int y);
void	img_pixel_put(t_cub *cub, int x, int y, int color);
#endif
