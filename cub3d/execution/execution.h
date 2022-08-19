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

}	s_ray;

void draw_line(s_cub *cub,double radien,int len);
void lst_init1(s_cub *cub, s_line *lst,double radien, int len);
double ray_collision_len(s_cub *cub, double radian,int len);
void ray_len(s_cub *cub, s_line *lst, double radien);

#endif