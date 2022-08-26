#ifndef EXECUTION_H
# define EXECUTION_H

typedef struct t_line
{
	double		begin_x;
	double		begin_y;
	double		deltaX;
	double		deltaY;
	int			pixels;
	int			a;
	int			b;
	int			d;
}   s_line;

typedef struct t_ray
{
	int a;
    int b;
    int x;
    int y;
    double min_raduis;
    double max_raduis;
	double map_min_raduis;
	double map_max_raduis;

}	s_ray;

void	rays_collision(s_cub *cub,double radien,int len);
void	lst1_init(s_cub *cub,s_ray *lst1);
void	lst_init(s_cub *cub, s_line *lst, double radien, int len);
void	lst_init_(s_cub *cub, s_line *lst, double radien, int len);
void	lst1_init_(s_cub *cub,s_ray *lst1);
int		collisions_ray_len(s_cub *cub, double radian,int len);
void	ray_len(s_cub *cub, s_line *lst, double radien);
void	txt_img_pixel_put1(s_cub *cub,s_img *img,int x, int y,int txt_x,int txt_y);
void	img_pixel_put(s_cub *cub, int x, int y, int color);
void	lst_init_(s_cub *cub, s_line *lst, double radien, int len);

#endif